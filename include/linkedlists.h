/* ---------------- Linker Map ---------------- */
#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include "logging.h"

/* ---------------- Defines ---------------- */


/* ---------------- Function Prototype Signatures ---------------- */


/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */
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