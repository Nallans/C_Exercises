/*
CS4E5 — Welcome to malloc()

Now we'll solve CS4E4 properly.

Write the same basic program, but this time use dynamic memory allocation.

The program should:

Ask how many integers the user wants.
Allocate enough memory for them.
Let the user enter the values.
Display them.
Calculate the sum and average.
Display the highest and lowest values.
Release the memory before the program ends.

You will need to investigate and understand:

malloc()
sizeof
free()
Rules

Don't blindly copy a malloc() pattern.

I want you to understand why something conceptually like:

number of elements × size of one element

is necessary.

And I especially want you to understand what the pointer contains after the allocation.

This is your first proper encounter with:

memory that your program requested while it was running.
*/