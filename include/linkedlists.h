/* ---------------- Linker Map ---------------- */
#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include "logging.h"
#include <cstdint>

/* ---------------- Defines ---------------- */
using namespace logging;

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
template<typename t>
class Node {
    private:
        t value;

    public:
        Node<t> * prev;
        Node<t> * next;

        /*
        * @brief Returns private value of node.
        *
        * @param none
        * @return template value corresponding users type specifier
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
        * @brief Node Class Constructor.
        *
        * @param _value The new nodes value.
        * @param end Pointer to the end of the list.
        * @return 
        */
        Node(const t& _value, Node<t> * end) {
            value = _value;
            prev = end;
            next = nullptr;
        } // Node(const t& _value, Node<t> * end)


        /*
        * @brief Node Class Constructor.
        *
        * @param _value The new nodes value.
        * @return 
        */
        Node(const t& _value) {
            value = _value;
            prev = nullptr;
            next = nullptr;
        } // Node(const t& _value)


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
template<typename t>
class List {
    private:
        Node<t> * start = nullptr;
        Node<t> * end = nullptr;
        uint32_t size = 0;

    public:


        /*
        * @brief Adds value to list at the tail of list.
        *
        * @param value Value that will be appended to list
        * @return void
        */
        void Append(const t& value) {
            if (start == nullptr && end == nullptr) {
                start = end = new Node<t>(value);
            }
            else {
                Node<t> * NewNode = new Node<t>(value, end);
                end->next = NewNode;
                end = NewNode;
            }
            size++;
        } // void Append(const t& value)


        /*
        * @brief Deletes the last item or "tail", from list.
        *
        * @param none
        * @return void
        */
        void DeleteLast() {
            if (start == nullptr && end == nullptr) {
                println("No items stored");
                return;
            }
            if (start == end) {
                delete start;
                start = end = nullptr;
                return;
            } else {
                Node<t> * del = end;
                end->prev->next = nullptr;
                end = del->prev;
                delete del;
            }
            size--;
        } // void DeleteLast()


        /*
        * @brief Deletes the first instance of a value in list.
        *
        * @param value Value that will be deleted from list.
        * @return void
        */
        void Delete(const t& value) {
            if (start == nullptr && end == nullptr) {
                println("Empty list");
                return;
            }
            Node<t> * current = start;
            Node<t> * target = nullptr;
            while (current != nullptr) {
                if (current->Get() == value) {
                    target = current;
                    break;
                }
                current = current->next;
            }
            if (target == nullptr) {
                println("Item not found");
                return;
            }
            Node<t> * _prev = target->prev;
            Node<t> * _next = target->next;
            if (target == end) {
                DeleteLast();
                return;
            }
            else if (target == start) {
                start = _next;
                if (start != nullptr) {
                    start->prev = nullptr;
                }
            }
            else {
                _prev->next = _next;
                if (_next != nullptr) {
                    _next->prev = _prev;
                }
            }
            delete target;
            size--;
        } // void Delete(const t& value)
        

        /*
        * @brief Print all items contained in list to console.
        *
        * @param none
        * @return void
        */
        void PrintAll() const {
            Node<t> * current = start;
            if (start == nullptr) {
                println("Empty list");
                return;
            }
            print("[");
            while (current != nullptr) {
                if (current->next == nullptr) {
                    print(current->Get());
                } else {
                    print(current->Get(), ", ");
                }
                current = current->next;
            }
            print("]\n");
            return;
        } // void PrintAll() const


        /*
        * @brief Returns the total amount of items stored in list.
        *
        * @param none
        * @return uint32_t unsigned 32 bit integer
        */
        uint32_t GetSize() const {
            return size;
        } // uint32_t GetSize() const


        /*
        * @brief Destructor that frees memory allocated by a lists construction and use when list goes out of scope.
        *
        * @param none
        * @return 
        */
        ~List() {
            Node<t> * current = start;
            if (current == nullptr) {
                return;
            }
            while (current != nullptr) {
                Node<t> * next = current->next;
                delete current;
                current = next;
            }
        } // ~List()
};


#endif