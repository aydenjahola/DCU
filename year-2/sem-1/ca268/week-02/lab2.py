#!/usr/bin/env python3

# Q1

# the time complexity of this script is O(n) which is Linear Search and this script in finding an element "x" in list "Y" of length "n". in this specific example,
# we have 6 elements in this list so our time complexity is going to be O(6) which is essentially the same as O(1) due to a constant factor but in general it
# just remains as O(n) for the larger lists

# Q2

# The time complexity of this script is O(log n) which is Binary Search and this script is used to find an item in a sorted list, the time complexity of binary
# search is O(log n) in the worst case as its very effiecient and reduces the number of elements in the search by half in each iteration. in this specific example
# the binary search finds the element "60" effiecenitly out of the 8 sorted elements given

# Q3

# The time complexity of this script is O(n) where "n" is the value in the scirpt, regardless of the value of "n", the time it takes for this script to run scaled
# linearly with "n". we notice that the first "for" loop iterated from "i = 0" to "i = n + 1" and in each iteration it performs constant-time operation where
# "test = test + 1", the loop runs n times therefore the complexity of it is O(n).
# but in the second "for" loop, we notice that its similar to the first one but instead it iterates from "j = 0" to "j = n - 1" and in each iteration it
# perfroms constact-time operatoin where "test = test - 1" and it also runs "n" times so each itertaion has constact time complexity, so this is also O(n).
# since both loops run sequentally, one after the other, we just add their time complexity together.
# so thats gonna be "O(n) + O(n) = 2*O(n)"

# Q4

# the time complexity of this script is "O(log n)" where "n" is the value of "n" in the script because the loop iterates "log2(n)" times and each iteration involve
# constant-time operations.
# the "while" loop start with the initial value of "n" and continues as "i" gets greater than "O".
# in each iteration the script performs 2 constant-time operations, the first one being "k = 2 + 2" which is just simple addition and the second one is
# "i = i // 2" which is an integer division. the loop stops when i becomes O and the number of iteration required for "i" to become O is determined by
# the number of times "i" can be haled before reaching 0

# Q5

#the time complexity of this script is "O(m * n) where "m" is the number of rows and "n" is the number of the coloumns in the matrix "mat". the time
# complexity is proportional to the number of elements in the matrix. the outer "for" loop iterates through the rows of the matrix and the number of iterations
# is determined by the number of the rows which is "len(mat). then the inner "for" loop iterates through the coloumns of the matrix "mat[0]" and the number
# of iterations is determined by the number of coloumns in "mat[0]" which is "len(mat[0]).
# inside the innermost loop, a constant-time operation "add += mat[i][j]" is performed, where "mat[i][j]" represens the accessing of an element in the matrix.

# Q6

# the time exomplexity of this script is "O(2^n) which is exponential, the recursive algorithm in this script makes for each value of "n" two recursive calls
# leading to an exponential number of function calls. the execution time increases rapidly with increasing values of "n" making in inefficnet for larger inputs
