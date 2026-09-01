/*
Exercise 29 — Manual string comparison

You already did a version of this in CS1E5, so this time we're making it more interesting.

Write:

int compare_words(char* word1, char* word2);

Return:

-1 if word1 comes before word2
0 if they are identical
1 if word1 comes after word2

And this time, do not use strcmp().

Examples:

apple / banana → -1
banana / apple → 1
hello / hello → 0

Remember our previous discussion: "before" and "after" here mean lexicographical order, character by character—not length.
*/