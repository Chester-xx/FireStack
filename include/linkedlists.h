/* ---------------- Linker Map ---------------- */
#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include "logging.h"

/* ---------------- Defines ---------------- */


/* ---------------- Function Prototype Signatures ---------------- */


/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */

/*
* @brief Node class for List class.
*
* @param value Private main value or content of node.
* @param prev Pointer to previous node.
* @param next Pointer to the following node.
*
* @note Functions: Get() | Set(_value) | Node(_value, end) | Node(_value).
*/
class Node {
    private:
        int value;

    public:
        Node * prev;
        Node * next;

        int Get() const;
        void Set(const int _value);

        Node(const int _value, Node * end);
        Node(const int _value);

};


/*
* @brief List Class for Doubly Linked List Structure, attributes and methods
*
* @param start Pointer to the head of list.
* @param end Pointer to the tail of list.
* @param size The total count of items stored in list.
*
* @note Functions: Append(value) | DeleteLast() | Delete(value) | PrintAll() | GetSize().
*/
class List {
    private:
        Node * start = nullptr;
        Node * end = nullptr;
        int size = 0;

    public:
        void Append(const int value);
        void DeleteLast();
        void Delete(const int& value);
        
        void PrintAll() const;
        int GetSize() const;

        ~List();
};


#endif