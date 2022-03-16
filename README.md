# Phonebook-Management-system-using-data-structures

A project done with collaboration with my team members (*currently in progress*)

**Problem Statement**
In this project, we're trying to operate a Phonebook management system, with optimal time complexities for the operation given below.

**Operations implemented **(*currently in progress*)
1. Insertion
2. Display
3. Searching(*currently in progress)
4. Deletion(*currently in progress)
5. Sorting(*currently in progress)

# Data Structures used

**1. Doubly Linked List** 

Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence. Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer).

In a singly linked list, we could traverse only in one direction, because each node contains address of the next node and it doesn't have any record of its previous nodes. However, doubly linked list overcome this limitation of singly linked list. Due to the fact that, each node of the list contains the address of its previous node, we can find all the details about the previous node as well by using the previous address stored inside the previous part of each node.

**3. Array**
In this project, we're using array of pointers.

Array and pointers are closely related to each other. In C++, the name of an array is considered às a pointer, i.e., the name of an array contains the address of an element. C++ considers the array name as the address of the first element.

**5. Hash Table**

Hash Table is a data structure which stores data in an associative manner. In a hash table, data is stored in an array format, where each data value has its own unique index value. Access of data becomes very fast if we know the index of the desired data.

Thus, it becomes a data structure in which insertion and search operations are very fast irrespective of the size of the data. Hash Table uses an array as a storage medium and uses hash technique to generate an index where an element is to be inserted or is to be located from.

Hashing is a technique to convert a range of key values into a range of indexes of an array. We're going to use modulo operator to get a range of key values

**Programming Language used**
1. C++
