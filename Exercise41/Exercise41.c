/*
Exercise 41 — Dynamically Allocated Strings
Objective: Learn to allocate memory for strings based on their actual length.

Write a program that:
1. Asks the user to enter a string.
2. Determines the length of the string.
3. Allocates exactly enough memory to store the string, including its terminating '\0'.
4. Copies the original string into the allocated memory.
5. Displays the dynamically allocated string.
6. Frees the allocation.
Constraints:
- Don't allocate a fixed-size array for the final string.
- Use malloc().
- Handle allocation failure.
The input mechanism can use a temporary buffer.
*/