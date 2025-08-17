/* ---------------- Linker Map ---------------- */
#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include <cstdint>
#include <type_traits>
#include "core\logging.h"

/* ---------------- Defines ---------------- */
using namespace logging;

/* ---------------- Function Prototype Signatures ---------------- */


/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */

/*
* @brief Node class for List class. Should i eventually make this private and maybe contained private within List class?
*
* @param value Private main value or content of node.
* @param prev Pointer to previous node.
* @param next Pointer to the following node.
*
* @note `Functions`
* @note Get()
* @note Set(_value)
* @note Node(_value, end) - Constructor
* @note Node(_value) - Constructor
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


}; // template<typename t> class Node


/*
* @brief List Class for Doubly Linked List Structure, attributes and methods
*
* @param start Pointer to the head of list.
* @param end Pointer to the tail of list.
* @param size The total count of items stored in list.
*
* @note `Functions`
* @note InsertFirst(value)
* @note InsertLast(value)
* @note InsertAt(index, value)
* @note InsertMany(args...)
* @note DeleteFirst()
* @note DeleteLast()
* @note DeleteAt(index)
* @note DeleteValue(value)
* @note PrintAll()
* @note Contains(value)
* @note IsEmpty()
* @note GetSize()
* @note Find(value)
* @note GetAt(index)
* @note Clear()
* @note ~List() - Destructor
*/
template<typename t>
class List {
    private:
        Node<t> * start = nullptr;
        Node<t> * end = nullptr;
        size_t size = 0;


    public:
        
        
        /*
        * @brief Adds value to list at the head of list.
        *
        * @param value Value that will be appended to list.
        * @return void
        */
       void InsertFirst(const t& value) {
           if (start == nullptr && end == nullptr) {
               start = end = new Node<t>(value);
            } else {
                Node<t> * NewNode = new Node<t>(value);
                start->prev = NewNode;
                NewNode->next = start;
                start = NewNode;
            }
            size++;
        }
        

        /*
        * @brief Adds value to list at the tail of list.
        *
        * @param value Value that will be appended to list
        * @return void
        */
        void InsertLast(const t& value) {
            if (start == nullptr && end == nullptr) {
                start = end = new Node<t>(value);
            } else {
                Node<t> * NewNode = new Node<t>(value, end);
                end->next = NewNode;
                end = NewNode;
            }
            size++;
        } // void Append(const t& value)
        

        /*
        * @brief Adds value to list at the index position "index" of list.
        *
        * @param value Value that will be appended to list.
        * @param index Position where the value will be appended to in the list.
        * @return void
        * @note Index will always begin counting from 0.
        */
       void InsertAt(const size_t& index, const t& value) {
            if (size < index) {
                error("Error: Cannot insert into list at index : '", index, "' as it is bigger than the list's size.");
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
            Node<t> * current = start;
            for (size_t i = 0; i < index; i++) {
                current = current->next;
            }
            Node<t> * NewNode = new Node(value);
            NewNode->prev = current->prev;
            NewNode->next = current;
            current->prev->next = NewNode;
            current->prev = NewNode;
            

            size++;
        } // void InsertAt(size_t& index, const t& value)


        /*
        * @brief Inserts user defined length of items to list.
        *
        * @note `static assertion` on all variadic types to ensure they match with the lists template type.
        *
        * @param args Variadic template, allows the user to enter as many arguments as they want into the function parameter.
        * @return void
        */
        template<typename... arguments>
        void InsertMany(const arguments&... args) {
            static_assert((std::is_same_v<t, arguments> && ...), "Source file function 'List::InsertMany()' only supports one template type, ensure all function parameter types match the list's template type.");
            (InsertLast(args), ...);
        } // template<typename... arguments> void InsertMany(const arguments&... args)


        /*
        * @brief Deletes the first item or "head", from list.
        *
        * @param none
        * @return void
        */
       void DeleteFirst() {
            if (start == nullptr && end == nullptr) {
                println("No items stored");
                return;
            }
            if (start == end) {
                delete start;
                start = end = nullptr;
                size--;
                return;
            } else {
                Node<t> * del = start;
                start->next->prev = nullptr;
                start = del->next;
                delete del;
                size--;
            }
        } // void DeleteFirst()
        

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
        * @brief Deletes the value at specified index in list.
        *
        * @param index The position for the deletion in list.
        * @param value Value that will be deleted from list.
        * @return void
        */
        void DeleteAt(const size_t& index) {
            if (start == nullptr && end == nullptr) {
                println("Empty list");
                return;
            }
            if (size <= index) {
                error("Error: Cannot delete item from index : '", index, "' as it is bigger than the list's size.");
                return;
            }
            if (index == 0) {
                DeleteFirst();
                return;
            }
            if (index == size - 1) {
                DeleteLast();
                return;
            }
            Node<t> * del = start;
            for (size_t i = 0; i < index; ++i) {
                del = del->next;
            }
            del->prev->next = del->next;
            del->next->prev = del->prev;
            delete del;
            size--;
        } // void DeleteAt(const size_t& index)
        

        /*
        * @brief Deletes the first instance of a value in list.
        *
        * @param value Value that will be deleted from list.
        * @return void
        * 
        * @note Will only remove The First Instance
        */
        void DeleteValue(const t& value) {
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
        * 
        * @note Strings are logged within double quotes `""`, char's and const char *'s are logged within single quotes `''` and all other types have no wrapping within characters.
        */
        void PrintAll() const {
            Node<t> * current = start;
            constexpr bool is_char_or_p = std::is_same_v<t, char> || std::is_same_v<t, const char *>;
            constexpr bool is_str = std::is_same_v<t, std::string>;
            if (start == nullptr) {
                println("Empty list");
                return;
            }
            print("[");
            while (current != nullptr) {
                if (current->next == nullptr) {
                    if (is_str) {
                        print("\"", current->Get(), "\"");
                    } else if (is_char_or_p) {
                        print("\'", current->Get(), "\'");
                    } else {
                        print(current->Get());
                    }
                } else {
                    if (is_str) {
                        print("\"", current->Get(), "\", ");
                    } else if (is_char_or_p) {
                        print("\'", current->Get(), "\', ");
                    } else {
                        print(current->Get(), ", ");
                    }
                }
                current = current->next;
            }
            println("]");
            return;
        } // void PrintAll() const


        /*
        * @brief Return a bool on whether a value is present in list.
        *
        * @param value Value that will be searched for in the list.
        * @return boolean on whether an item of such exists in list.
        * 
        * @note Checks edge cases first.
        */
        bool Contains(const t& value) {
            if (start == nullptr && end == nullptr) {
                return false;
            }
            if (start->Get() == value || end->Get() == value) {
                return true;
            }
            Node<t> * current = start->next;
            while (current != nullptr) {
                if (current->Get() == value) {
                    return true;
                } else {
                    current = current->next;
                }
            }
            return false;
        } // bool Contains(const t& value)


        /*
        * @brief Returns whether or not the list is empty.
        *
        * @param none
        * @return boolean true or false on whether start and end are nullptr's
        * @note Does not check size, rather the bool expression of 'start == nullptr && end == nullptr'
        */
        bool IsEmpty() const {
            if (start == nullptr && end == nullptr) {
                return true;
            } else {
                return false;
            }
        } // bool IsEmpty()


        /*
        * @brief Returns the total number of nodes in list.
        *
        * @param none
        * @return size_t unsigned long long integer
        */
        size_t GetSize() const {
            return size;
        } // size_t GetSize() const


        /*
        * @brief Returns either the first instance node pointer to the found item or a nullptr if the item was not found in list.
        *
        * @param value Value that will be searched for in the list.
        * @return Node pointer to found item or nullptr.
        * 
        * @note Does not check tail edgecase, rather traverses from the head of the list.
        */
        Node<t> * Find(const t& value) {
            Node<t> * current = start;
            while (current != nullptr) {
                if (current->Get() == value) {
                    return current;
                } else {
                    current = current->next;
                }
            }
            return nullptr;
        } // template<typename t> Node<t> * Find(const t& value)
        

        /*
        * @brief Returns the value stored at index specified in list.
        *
        * @param index The positional node of the value that will be retrieved
        * @return user specified type or NULL if the index is not valid
        * 
        * @note Does not check tail edgecase, rather traverses from the head of the list.
        */
        t GetAt(size_t index) const {
            if (start == nullptr && end == nullptr) {
                error("Error: Index '", index, "' is out of bounds.");
                return t();
            }
            if (index >= size) {
                error("Error: Index '", index, "' is out of bounds.");
                return t();
            }
            Node<t> * current = start;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->Get();
        } // t GetAt(size_t index) const


        /*
        * @brief Empties the list, deleting all contained values and setting size to 0.
        *
        * @param none
        * @return void
        */
        void Clear() {
            if (start == nullptr && end == nullptr) {
                return;
            }
            Node<t> * current = start;
            while (current != nullptr) {
                Node<t> * next = current->next;
                delete current;
                current = next;
            }
            start = nullptr;
            end = nullptr;
            size = 0;
        } // void Clear()


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


}; // template<typename t> class List


#endif