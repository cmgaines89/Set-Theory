# Set-Theory
A program that supports the operations of unions, difference, and cardinality between two arrays.

https://en.wikipedia.org/wiki/Union_(set_theory)

The program prompts the user to get the sizes of the two arrays which are SetA and SetB, the sizes of the arrays can be from 0-15 characters. The user then unputs their chosen elements into SetA and SetB. Each set is then printed out and the calculations of set comparisons are automatically ran.

The arrays are first sorted using a recursive binary search algorithm required for use in the sort function, the union (AUB) is found by concatenating the arrays and removing the duplicate elements, the remaining elements are counted and displayed as the cardinality output. The (A-B) difference is found by sorting the arrays and searching through every element of the second array and printed if it is not found the remaining elements are then counted for the cardinality output. The (B-A) difference is found by doing the opposite of the original difference function.
