## nag.c — Thread Synchronization Demo

<pre>
Author: chatGPT &amp; bjr
Date: 21 september 2025
At: csc421 at the Univeristy of Miami
</pre>

This repository contains a simple **C program** (`nag.c`) that demonstrates 
how to use **mutexes** and **condition variables** with POSIX threads (`pthread`). 
It shows how a worker thread can wait either for a **timeout** or for a **signal** from another thread.

---

### Program Overview

The program creates **two threads**:

1. **Main thread**
   - Reads characters from the keyboard. `fgets` returns with the message,
   - If the message is not the quit message:
     - Locks a shared **mutex**.
     - Copies the message into a shared buffer.
     - Increments a shared `cur_count`.
     - Wakes up the `nag` thread via a **condition variable**.
     - Unlocks the mutex.
    - If the message is the quit message:
      - Locks the shared **mutex**.
      - Sets `req_exit`
      - Wakes up the `nag` thread via a **condition variable**.
      - Unlocks the mutex.
      - Calls `pthread_exit` to wait for the nag thread to exit, then exits.

   - Loops back up to "Reads characters ... "

2. **Nag thread**
   - In a loop:
      - Acquires the **mutex** and then performs a **timed wait** on the condition variable.
      - If `cur_count` is larger than `old_count` then there is a new message to print.
         - Prints the message and updates `old_count` to equal `cur_count`.
      - If this was **timeout**, and it prints a nagging message (e.g., `"Well ... ?"`).
      - Releases the **Mutex**
      - If `req_exit` is set, exits thread.

This pattern demonstrates how to coordinate 
threads with **time-based waiting** and **event-based signaling**.
There are two events: 
   - a new message (`cur_count` is larger than `old_count`)
   - and to exit (`req_exit` set).

---

### Algorithm notes

When the nag thread wakes up (i.e. returns from `pthread_cond_timedwait`), it gets ownership 
of the mutex and must assess the situation. The use of `old_count` and `new_count` is to 
indicate the situation that there is new information in the buffer. 

The setting of `req_exit` gives an orderly exit in which the main thread requests the nag thread
to exit, the nag thread responds to the request by exiting, and the main thread responds to the 
thread exit by exiting the program.

---

### Key Concepts

- **Mutex (`pthread_mutex_t`)**  
  Protects access to the shared buffer and counter. In particular, the copying to and from
  the shared buffer has many steps, and each thread has to complete all the steps without
  interrupting each other.

- **Condition variable (`pthread_cond_t`)**  
  Allows the `nag` thread to wait for either:
  - A **timeout**, or  
  - A **signal** from the main thread.

- **Timed wait (`pthread_cond_timedwait`)**  
  Lets the `nag` thread periodically wake up and take action even if no input has arrived.

---
