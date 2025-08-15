// launch.json config to app1.exe | when working on other projects remember to change the exe name
#include "linkedlists.h"
#include "logging.h"

using namespace logging;

int main() {

    List<int> l;
    l.Append(1);
    l.Append(2);
    l.Append(3);
    // l.Delete(3);
    l.PrintAll();
    println("Size: ", l.GetSize());

    return EXIT_SUCCESS;
}