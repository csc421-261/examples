## nag.c — Thread Synchronization Demo

<pre>
Author: chatGPT &amp; bjr
Date: 21 september 2025
At: csc421 at the Univeristy of Miami
</pre>

`nag.c` is a simple C program demonstrating how to use POSIX threads, 
mutexes, and condition variables. 

It creates a "nagging" worker 
thread that periodically complains if no input is received, 
but responds differently when the main thread signals 
it after keyboard input. 

This illustrates how to combine timed 
waits with event signaling in concurrent programming.
The main thread can also request the nag thread to exit, 
for a coordinated stop of the two threads.

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
      - Loops back up to "Reads characters ... "
    - If the message is the quit message:
      - Locks the shared **mutex**.
      - Sets `req_exit`
      - Wakes up the `nag` thread via a **condition variable**.
      - Unlocks the mutex.
      - Calls `pthread_exit` to wait for the nag thread to exit, then exits.


2. **Nag thread**
   - In a loop:
      - Acquires the **mutex** and then performs a **timed wait** on the condition variable.
      - Will return from the wait either from a timeout or because the thread was signaled.
        - The **mutex** is reacquired by the wake up
      - If `cur_count` is larger than `old_count` then there is a new message to print.
         - Prints the message and updates `old_count` to equal `cur_count`.
      - If this was **timeout**, and it prints a nagging message (e.g., `"Well ... ?"`).
      - Releases the **mutex**
      - If `req_exit` is set, exits thread.

This pattern demonstrates how to coordinate 
threads with **time-based waiting** and **event-based signaling**.

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

### Sample run

<pre>
% make run
./nag
Speak to me! ("quit" to quit)
hello
Is "hello" all you have to say for yourself?
Well ... ?
Well ... ?
nag me some more
Is "nag me some more" all you have to say for yourself?
Well ... ?
ok i am out of here
Is "ok i am out of here" all you have to say for yourself?
Well ... ?
quit
</pre>

