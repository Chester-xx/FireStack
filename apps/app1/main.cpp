// --- Tests ---

#include "linkedlists.h"

int main() {
    List<int> lst;

    // Test InsertFirst and InsertLast
    lst.InsertFirst(10);          // List: [10]
    lst.InsertLast(20);           // List: [10, 20]
    lst.InsertFirst(5);           // List: [5, 10, 20]
    lst.InsertAt(1, 7);           // List: [5, 7, 10, 20]

    lst.PrintAll();               // Expected: [5, 7, 10, 20]

    // Test GetAt and Contains
    std::cout << lst.GetAt(2) << "\n";     // Expected: 10
    std::cout << std::boolalpha << lst.Contains(7) << "\n";   // Expected: true
    std::cout << std::boolalpha << lst.Contains(100) << "\n"; // Expected: false

    // Test DeleteFirst and DeleteLast
    lst.DeleteFirst();           // Removes 5; List: [7, 10, 20]
    lst.DeleteLast();            // Removes 20; List: [7, 10]
    lst.PrintAll();              // Expected: [7, 10]

    // Test DeleteAt
    lst.DeleteAt(0);             // Removes 7; List: [10]
    lst.PrintAll();              // Expected: [10]

    // Test DeleteValue
    lst.InsertLast(15);          // List: [10, 15]
    lst.InsertLast(10);          // List: [10, 15, 10]
    lst.DeleteValue(10);         // Deletes first 10; List: [15, 10]
    lst.PrintAll();              // Expected: [15, 10]

    // Test Clear
    lst.Clear();                 // List cleared
    lst.PrintAll();              // Expected: Empty list

    // Test IsEmpty and GetSize
    std::cout << std::boolalpha << lst.IsEmpty() << "\n"; // Expected: true
    std::cout << lst.GetSize() << "\n";                   // Expected: 0

    return EXIT_SUCCESS;
}
