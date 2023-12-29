
#if 0

Internal Implementation of Set Data Structure:
=================================================
A set is a data structure that stores a collection of unique elements, with no duplicates allowed. Sets can be implemented using a variety of data structures, including arrays, linked lists, binary search trees, and hash tables.

Basically, a Set is language dependent Data Structure. Every language uses a different data structure to implement a set data structure internally like C++ uses Self-Balancing BST. Java, Python, C#, and JavaScript use Hash tables.

Sets in C++ use Self-Balancing Binary Tree(BST). 
-----------------------------------------------
In this approach, the elements are stored in nodes of a binary tree, with the property that the left subtree of any node contains only elements smaller than the node’s value, and the right subtree contains only elements larger than the node’s value. This property ensures that the elements in the tree are always sorted in ascending order.

To add an element to the set implemented with a BST, you start at the root of the tree and compare the element to the node’s value.
If the element is less than the node’s value, you traverse to the left subtree and repeat the process.
If the element is greater than the node’s value, you traverse to the right subtree and repeat the process.
If you reach a node with the same value as the element, you do not add the element to the tree since duplicates are not allowed.
To remove an element from the set implemented with a BST, you first search for the node containing the element, following the same process as adding an element.
If the element is not found in the tree, there is nothing to remove.
If the element is found, there are three cases to consider:
The node has no children: In this case, you simply remove the node from the tree.
The node has one child: In this case, you replace the node with its child.
The node has two children: In this case, you find the minimum element in the right subtree of the node (i.e., the leftmost node in the right subtree) and replace the node’s value with that element. Then, you remove the duplicate element from the right subtree


Sets in python use Hash table. 
-----------------------------------------------
In the case of implementation of Set using Hash table (as happens in Python) the implementation happens in the following way:

To add an element to the set:
Generate a hash value (say entry) for the key to be inserted.
Go to the entry in the hash table and check if there are already other entries or not.
If the slot is empty add the new element there.
Otherwise, if there are other entries, traverse to the end of that entry list and add the new element there.
To remove an element from the set:
First, generate the hash value for the element.
If the hash value is invalid or there are no entries then return an error message.
Otherwise, go to that slot and find the element from the list present in that slot.
Then remove that element from the hash table.



Set also maintains count of unique elemnts. SO hash map should contain one occurance of the element along with its count.



#endif
