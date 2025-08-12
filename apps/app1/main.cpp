// launch.json config to app1.exe | when working on other projects remember to change the exe name
#include "linkedlists.h"

int main() {

    List l;
    l.Append(1);
    l.Append(2);
    l.Append(3);
    l.Delete(3);
    l.PrintAll();
    std::cout << "Size: " << l.GetSize() << std::endl;

    return 0;
}