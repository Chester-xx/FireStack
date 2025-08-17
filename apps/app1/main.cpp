// --- Tests ---

#include "container.h"
#include <string>

int main() {

    container::List<int> l;

    l.InsertMany(1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 100, 9000);
    l.PrintAll();

    return EXIT_SUCCESS;

} // int main()