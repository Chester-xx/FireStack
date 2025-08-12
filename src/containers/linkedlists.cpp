/* ---------------- File Inclusions ---------------- */
#include "linkedlists.h"

/* ---------------- Defines ---------------- */


/* ---------------- Constructor ---------------- */


/* ---------------- Destructor ---------------- */

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
}

/* ---------------- Functions ---------------- */

// --- Class Node ---

int Node::Get() const {
    return value;
}

void Node::Set(const int val) {
    value = val;
}

Node::Node(const int val, Node * end) {
            value = val;
            prev = end;
            next = nullptr;
        }

Node::Node(const int val) {
    value = val;
    prev = nullptr;
    next = nullptr;
}

// --- End Class Node --- 

// --- Class List ---

void List::Append(const int val) {
    if (start == nullptr && end == nullptr) {
        start = end = new Node(val);
    } 
    else {
        Node * NewNode = new Node(val, end);
        end->next = NewNode;
        end = NewNode;
    }
    size++;
}

void List::DeleteLast() {
    if (start == nullptr && end == nullptr) {
        std::cout << "No items stored\n";
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
}

void List::Delete(const int val) {
    if (start == nullptr && end == nullptr) {
        std::cout << "Empty list\n";
        return;
    }
    Node * current = start;
    Node * target = nullptr;
    while (current != nullptr) {
        if (current->Get() == val) {
            target = current;
            break;
        }
        current = current->next;
    }
    if (target == nullptr) {
        std::cout << "Item not found\n";
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
}

void List::PrintAll() const {
            Node * current = start;
            if (start == nullptr) {
                std::cout << "Empty list\n";
                return;
            }
            while (current != nullptr) {
                // i know it prints addresses its just to show that values are not constrained inline like an array 0x1 and 0x2
                std::cout << current << ": " << current->Get() << "\n";
                current = current->next;
            }
            return;
        }

int List::GetSize() const {
    return size;
}

// --- End Class List ---

