#!/usr/bin/env python3

# Q1

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return TreeNode(key)

    if key < root.val:
        root.left = insert(root.left, key)
    elif key > root.val:
        root.right = insert(root.right, key)

    return root

# Usage
root = TreeNode(10)
root = insert(root, 5)
root = insert(root, 15)


# Q2

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def is_valid_bst(root):
    def is_valid_bst_helper(node, lower=float('-inf'), upper=float('inf')):
        if node is None:
            return True

        val = node.val
        if val <= lower or val >= upper:
            return False

        return (is_valid_bst_helper(node.left, lower, val) and
                is_valid_bst_helper(node.right, val, upper))

    return is_valid_bst_helper(root)

# Usage
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)
print(is_valid_bst(root))  # Should return True


# Q3

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def find_kth_smallest(root, k):
    def in_order_traversal(node):
        if node is None:
            return []

        return in_order_traversal(node.left) + [node.val] + in_order_traversal(node.right)

    sorted_elements = in_order_traversal(root)

    if 1 <= k <= len(sorted_elements):
        return sorted_elements[k - 1]
    else:
        return None

# Usage
# Example tree
#         3
#        / \
#       1   4
#        \
#         2
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)

k = 2
print(find_kth_smallest(root, k))  # Should return 2


# Q4

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def is_balanced(root):
    def check_height(node):
        if node is None:
            return 0

        left_height = check_height(node.left)
        right_height = check_height(node.right)

        # If any subtree is not balanced, propagate the unbalance signal (-1)
        if left_height == -1 or right_height == -1 or abs(left_height - right_height) > 1:
            return -1

        return 1 + max(left_height, right_height)

    return check_height(root) != -1

# Usage
# Example tree
#         1
#        / \
#       2   2
#      / \
#     3   3
#    /
#   4
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(2)
root.left.left = TreeNode(3)
root.left.right = TreeNode(3)
root.left.left.left = TreeNode(4)

print(is_balanced(root))  # Should return True


# Q5

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def iterative_in_order_traversal(root):
    result = []
    stack = []
    current = root

    while current or stack:
        # Traverse to the leftmost node
        while current:
            stack.append(current)
            current = current.left

        # Visit the current node
        current = stack.pop()
        result.append(current.val)

        # Move to the right subtree
        current = current.right

    return result

# Usage
# Example tree
#         1
#          \
#           2
#          /
#         3
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)

print(iterative_in_order_traversal(root))  # Should print [1, 3, 2]


# Q6

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def binary_tree_paths(root):
    def construct_path(node, current_path, result):
        if not node:
            return

        current_path += str(node.val)

        if not node.left and not node.right:
            result.append(current_path)
            return

        current_path += "->"

        construct_path(node.left, current_path, result)
        construct_path(node.right, current_path, result)

    result_paths = []
    construct_path(root, "", result_paths)
    return result_paths

# Example usage:
# Example tree
#         1
#        / \
#       2   3
#        \
#         5
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)

print(binary_tree_paths(root))  # Output: ["1->2->5", "1->3"]

