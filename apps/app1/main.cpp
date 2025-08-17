// --- Tests ---

#include "linkedlists.h"
#include <string>
#include "logging.h"

using namespace logging;

int main() {
    List<int> l;

    l.InsertMany(1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 100, 9000);
    l.PrintAll();
    println("End");

    return EXIT_SUCCESS;
} // int main()