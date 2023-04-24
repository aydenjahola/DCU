#!/usr/bin/env python3

# Here we have to explore all combinations of numbers from 1 to n of length k.
# Indeed, we could solve the problem with the paradigm of backtracking.

# Problem - combinations
# Decision space- numbers from 1 to n without repetation
# Output- all combinatins of numbers from 1 to n of size k



def combine(self, n, k):
		sol=[]
        def backtrack(remain,comb,nex):
			# solution found
            if remain==0:
                sol.append(comb.copy())
            else:
				# iterate through all possible candidates
                for i in range(nex,n+1):
					# add candidate
                    comb.append(i)
					#backtrack
                    backtrack(remain-1,comb,i+1)
					# remove candidate
                    comb.pop()

        backtrack(k,[],1)
        return sol


# - Given an empty array, the task is to add numbers between 1 to n to the array upto size of k.
#   We could model the each step to add a number as a recursion function (i.e. backtrack() function).

# - At each step, technically we have 9 candidates at hand to add to the array.
#   Yet, we want to consider solutions that lead to a valid case (i.e. is_valid(candidate)).
#   Here the validity is determined by whether the number is repeated or not.
#   Since in the loop, we iterate from nex to n+1, the numbers before nex are already visited and cannot be added to the array.
#   Hence, we dont arrive at an invalid case.

# - Then, among all the suitable candidates, we add different numbers using comb.append(i) i.e. place(next_candidate).
#   Later we can revert our decision with comb.pop() i.e. remove(next_candidate), so that we could try out the other candidates.

# - The backtracking would be triggered at the points where the decision space is complete i.e. nex is 9 or when the size of thecombarray becomes k.
#   At the end of the backtracking, we would enumerate all the possible combinations.
