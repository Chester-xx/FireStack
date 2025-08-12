/* ---------------- Linker Map ---------------- */
#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>

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
        void Set(const int val);

        Node(const int val, Node * end);
        Node(const int val);

};

class List {
    private:
        Node * start = nullptr;
        Node * end = nullptr;
        int size = 0;

    public:
        void Append(const int val);
        void DeleteLast();
        void Delete(const int val);
        
        void PrintAll() const;
        int GetSize() const;

        ~List();
};

#endif