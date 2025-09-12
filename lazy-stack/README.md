### Stack variables

Stack variables are not initialized. 

To prove this, I present a program that opens and closes a stack frame, hoping nothing has
changed between the open and the close. This explains how a variable seems to be self-initialized to increasing values between calls.

Because memory is initialized one time, on delivery to the virtual space of the process, the result here (if it works at all) will be consistent.

This sort of may-or-maynot work code, typical of hackers, I call **pirate programming**. As in, why doesn't the count start at 0? I don't know. 
It's pirate programming. Maybe you can tell me.

```
% make run
cc -o lazy-stack lazy-stack.c
./lazy-stack > lazy-stack.out
cat lazy-stack.out
1
2
3
4
5
6
7
8
9
10
```
