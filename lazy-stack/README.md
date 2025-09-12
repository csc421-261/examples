### Stack variables

Stack variables are not initialized. To prove this, I present a program that opens and closes a stack frame, hoping nothing has
changed between the open and the close. This explains how a variable seems to be self-initialized to increasing values between calls.

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
