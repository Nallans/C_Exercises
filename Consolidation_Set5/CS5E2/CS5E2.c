/*
Exercise 2 — Resizing an Allocation
Objective: Understand what realloc() actually changes.

Start with an array of 5 integers.
1. Allocate space for 5 integers.
2. Fill the array with five values.
3. Ask the user for a new size greater than 5.
4. Resize the allocation using realloc().
5. Fill only the newly added elements.
6. Display the entire array.
7. Free the allocation.
Pay attention to which values must be preserved after resizing.

Improvement challenge: Make the new size user-defined, allowing either growth or shrinkage, while preserving all elements that still fit in the resized array.
*/