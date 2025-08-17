// --- Tests ---

#include "linkedlists.h"
#include <string>
#include "logging.h"

using namespace logging;

int main() {
    List<std::string> l;

    l.InsertLast("str1");
    l.InsertLast("string 2, test");
    l.InsertLast("1");
    l.PrintAll();
    println("End");

    return EXIT_SUCCESS;
} // int main()