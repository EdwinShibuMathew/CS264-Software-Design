#include <iostream>
#include "Module.h"
#include "Programme.h"

using namespace std;

int main() {
    Module cs264("CS264", 181, 5);
    Module cs357("CS357", 155, 5);

    Programme csse("CSSE", 3, 5);  // capacity = 5 modules

    csse.addModule(cs264);
    csse.addModule(cs357);

    cout << csse.toStr();

    return 0;
}
