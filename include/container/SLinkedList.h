

// SLinkedList struct
// - public

//      - InsertMany
//      - DeleteFirst
//      - DeleteLast
//      - DeleteAt
//      - DeleteValue
//      - Clear
//      - Contains
//      - PrintAll
//      - IsEmpty
//      - GetSize
//      - Find
//      - GetAt
//      - constr, destruct

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
    * @brief Node Class For SinglyLinkedList class .
    * 
    * @param value Private main data or content of node.
    * @param next Pointer to the following node.
    * 
    * @note `Functions`
    * @note Get()
    * @note Set(_value)
    * @note SNode(_value) - Constructor
    */
    template<typename t>
    class SNode {

        private:
            t value;

        public:
            SNode<t> * next = nullptr;


            /*
            * @brief Returns private value of node.
            * 
            * @param none 
            * @return template value corresponding users type specifier.
            */
            t Get() const {
                return value;
            } // t Get() const


            /*
            * @brief Sets the private value of node.
            *
            * @param _value The value that the node will now be set to.
            * @return void
            */
            void Set(const t& _value) {
                value = _value;
            } // void Set(const t& _value)


            /*
            * @brief SNode Class Constructor.
            *
            * @param _value The new nodes value.
            * @param end Pointer to the end of the list.
            * @return 
            */
            SNode(const t& _value) {
                value = _value;
                next = nullptr;
            } // SNode(const t& _value)


    }; // template<typename t> class SNode

    /*
    * @brief SinglyLinkedList Class for Singly Linked List Structure, attributes and methods.
    *
    * @param head Pointer to the head of the list.
    * @param size The total count of items stored in the list.
    * 
    * @note `Functions`
    * @note 
    */
    template<typename t>
    class SinglyLinkedList {

        private:
            SNode<t> * head = nullptr;
            SNode<t> * tail = nullptr;
            size_t size = 0;
            
        public:


            /*
            * @brief Adds a value to list at the head of the list.
            *
            * @param value Value that will be appended to the list.
            * @return void
            */
            void InsertFirst(const t& value) {
                if (head == nullptr) {
                    head = tail = new SNode<t>(value);
                } else {
                    SNode<t> * NewNode = new SNode<t>(value);
                    NewNode->next = head;
                    head = NewNode;
                }
                size++;
            } // void InsertFirst(const t& value)


            /*
            * @brief Adds a value to list at the tail of the list.
            *
            * @param value Value that will be appended to the list.
            * @return void
            */
            void InsertLast(const t& value) {
                if (head == nullptr) {
                    head = tail = new SNode<t>(value);
                } else {
                    SNode<t> * NewNode = new SNode<t>(value);
                    tail->next = NewNode;
                    tail = NewNode;
                }
                size++;
            } // void InsertLast(const t& value)


            /*
            * @brief Adds value to list at the index position "index" of the list.
            *
            * @param value Value that will be appended to the list.
            * @param index Position where the value will be appended to in the list.
            * @return void
            * @note Index will always begin counting from 0.
            */
            InsertAt(const size_t& index, const t& value) {
                if (size < index) {
                    logging::error("Error: Cannot insert into list at index : '", index, "' as it is bigger than the list's size.");
                    return;
                }
                if (size == 0 || index == 0) {
                    InsertFirst(value);
                    return;
                }
                if (size == index) {
                    InsertLast(value);
                    return;
                }
                SNode<t> * current = head;
                for (size_t i = 0; i < index - 1; ++i) {
                    current = current->next;
                }
                SNode<t> * NewNode = new SNode(value);
                NewNode->next = current->next;
                current->next = NewNode;
                if (NewNode->next == nullptr) {
                    tail = NewNode;
                }
                size++;
            } // InsertAt(const size_t& index, const t& value)


    };

} // namespace container


#endif // #ifndef SLINKEDLIST_H