# Phonebook-Management-system-using-data-structures

A project done with collaboration with my team members (*currently in progress*)

**Problem Statement**
In this project, we're trying to operate a Phonebook management system, with optimal time complexities for the operation given below.

**Programming Language used**
1. C++

**Operations implemented(*currently in progress*)**
1. Insertion
2. Display
3. Search and modify
4. Deletion

# Data Structures used

**1. Ternary Search Tree**

In the trie (standard) data structure,

--The left pointer points to the node whose value is lower than the current node's value.

--The equal pointer leads to a node whose value is the same as the current node's value.

--The right pointer leads to the node whose value exceeds the current node's value.

One of the advantage of using ternary search trees over tries is that ternary search trees are a more space efficient. Tries are suitable when there is a proper distribution of words over the alphabets so that spaces are utilized most efficiently. Otherwise ternary search trees are better. Ternary search trees are efficient to use (in terms of space) when the strings to be stored share a common prefix.

**3. Array**

In this project, we're implementing arrays as pointers.

An array of 26 elements is implemented, in which each array element is equivalent to an alphabet in a sequential order.
Each element in array can be considered as a pointer which points to a unique Ternary Search Tree(TST).
Array and pointers are closely related to each other. In C++, the name of an array is considered às a pointer, i.e., the name of an array contains the address of an element. C++ considers the array name as the address of the first element.

**5. Hash Table**

Hash Table is a data structure which stores data in an associative manner. In a hash table, data is stored in an array format, where each data value has its own unique index value. Access of data becomes very fast if we know the index of the desired data.

Thus, it becomes a data structure in which insertion and search operations are very fast irrespective of the size of the data. Hash Table uses an array as a storage medium and uses hash technique to generate an index where an element is to be inserted or is to be located from.

Hashing is a technique to convert a range of key values into a range of indexes of an array. We're going to use modulo operator to get a range of key values
Hashing reduces the time complexity of our project.
