
#include "Cpp11.h"
#include "Cpp17.h"
int main()
{
    auto cpp11 = Cpp11::create();
    cpp11->main();
    auto cpp17 = Cpp17::create();
    cpp17->main();
    return 0;
}
