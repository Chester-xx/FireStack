// SNode struct
//  - t value
//  - SNode<t> * next
//  - Constr
// SLinkedList struct
// - private
// - Node<t> * head = nullptr
// - size_t size = 0
// - public
// - constr, destruct
// - InsertFirst
// - InsertLast
// - InsertAt
// - InsertMany
// - DeleteFirst
// - DeleteLast
// - DeleteAt
// - DeleteValue
// - Clear
// - Contains
// - PrintAll
// - IsEmpty
// - GetSize
// - Find
// - GetAt

/* ---------------- Linker Map ---------------- */
#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include <cstdint>
#include <type_traits>
#include "core/logging.h"

/* ---------------- Defines ---------------- */


/* ---------------- Function Prototype Signatures ---------------- */


/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */


namespace container {

    /*
    * @brief 
    * 
    * @param
    * @return
    */
    template<typename t>
    class SNode {
        private:
            t value;
            SNode<t> * next = nullptr;
        public:

    };

} // namespace container


#endif // #ifndef SLINKEDLIST_H