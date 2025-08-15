/* ---------------- File Inclusions ---------------- */
#include "linkedlists.h"

/* ---------------- Defines ---------------- */
using namespace logging;

/* ---------------- Constructor ---------------- */


/* ---------------- Destructor ---------------- */


/*
* @brief Destructor that frees memory allocated by a lists construction and use when list goes out of scope.
*
* @param none
* @return 
*/
List::~List() {
    Node * current = start;
    if (current == nullptr) {
        return;
    }
    while (current != nullptr) {
        Node * next = current->next;
        delete current;
        current = next;
    };
} // List::~List()


/* ---------------- Functions ---------------- */


// --- Class Node ---


/*
* @brief Returns private value of node.
*
* @param none
* @return int
*/
int Node::Get() const {
    return value;
} // int Node::Get() const


/*
* @brief Sets the private value of node.
*
* @param _value The value that the node will now be set to.
* @return void
*/
void Node::Set(const int _value) {
    value = _value;
}


/*
* @brief Node Class Constructor.
*
* @param _value The new nodes value.
* @param end Pointer to the end of the list.
* @return 
*/
Node::Node(const int _value, Node * end) {
    value = _value;
    prev = end;
    next = nullptr;
}


/*
* @brief Node Class Constructor.
*
* @param _value The new nodes value.
* @return 
*/
Node::Node(const int _value) {
    value = _value;
    prev = nullptr;
    next = nullptr;
}


// --- End Class Node --- 


// --- Class List ---


/*
* @brief Adds value to list at the tail of list.
*
* @param value Value that will be appended to list
* @return void
*/
void List::Append(const int value) {
    if (start == nullptr && end == nullptr) {
        start = end = new Node(value);
    } 
    else {
        Node * NewNode = new Node(value, end);
        end->next = NewNode;
        end = NewNode;
    }
    size++;
} // void List::Append(const int value)


/*
* @brief Deletes the last item or "tail", from list.
*
* @param none
* @return void
*/
void List::DeleteLast() {
    if (start == nullptr && end == nullptr) {
        println("No items stored");
        return;
    }
    if (start == end) {
        delete start;
        start = end = nullptr;
        return;
    } else {
        Node * del = end;
        end->prev->next = nullptr;
        end = del->prev;
        delete del;
    }
    size--;
} // void List::DeleteLast()


/*
* @brief Deletes the first instance of a value in list.
*
* @param value Value that will be deleted from list.
* @return void
*/
void List::Delete(const int& value) {
    if (start == nullptr && end == nullptr) {
        println("Empty list");
        return;
    }
    Node * current = start;
    Node * target = nullptr;
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
    Node* _prev = target->prev;
    Node* _next = target->next;
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
} // void List::Delete(const int value)


/*
* @brief Print all items contained in list to console.
*
* @param none
* @return void
*/
void List::PrintAll() const {
    Node * current = start;
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
} // void List::PrintAll() const


/*
* @brief Returns the total amount of items stored in list.
*
* @param none
* @return int
*/
int List::GetSize() const {
    return size;
} // int List::GetSize() const


// --- End Class List ---