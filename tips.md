# General Tips

- Understand the problem
- Understand your solution

## [LC #146: LRU Cache](https://leetcode.com/problems/lru-cache/)

1. Know what each data structure is used for

- LRU cache uses a hashmap and doubly linked list. I was confused with the
  role of each and erroneously did not implement several things:
  1. Delete nodes from the hashmap itself after removing them from the linked
     linked list.
  2. Be able to delete such nodes from the map by storing the key in the node.

2. Draw it out
3. Create logical interfaces

- LRU cache requires addition and deletion of nodes. To maintain a clean
  interface, `add()` and `remove()` methods should only accept a node.

## [LC #125: Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)

1. With two pointers, perform one operation per iteration

- Attempting to adjust both left and right pointers in the same iteration
  introduced complexity. Discrete, clear-intended loops are better.
