## Thread-count: a concurrency experiment

<pre>
Author: chatgpt and bjr
Date: 21 september 2025
At: csc421 at the Univeristy of Miami
</pre>

----

This repository contains a C program demonstrating 

- threads,
- concurrency,
- and race conditions

using POSIX threads (`pthread`). The program defines a function `counter_thread`, and starts some `N` threads to run the function. 
A common integer `counter` is incremented `K` times by each threads. The increment is separated into three steps:

- read from the counter to a temporary
- increment the temporary
- write to the counter from the temporary

The program is run in two update regimes:
  - **atomic**: the read-increment-write statements of each thread are most likely run without other threads intervening.
  - **interleaved**: a sleep is put between the read and write statements, so the threads very likely interleave their access to the counter.

The two runs are shown, with colors used so each thread’s output is visually distinct. This makes it easier to see 
the interleaving of thread actions. 

A **race condition** is a situation in concurrency when the result of a calculation can vary depending on the order of events,
and that ordering is not explicitly controlled. The output is therefore uncertain. I show here two different results, depending
on even ordering. 

- **Question:** Are there others? What different end values are possible?



