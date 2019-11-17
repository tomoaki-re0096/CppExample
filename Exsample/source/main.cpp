
#include "Cpp11.h"
#include "Cpp17.h"
#include "SmartPtr.h"
#include "Lambda.h"

int main()
{
    auto cpp11 = Cpp11::create();
    cpp11->main();
    auto cpp17 = Cpp17::create();
    cpp17->main();

    auto smart_ptr = SmartPtr::create();
    smart_ptr->main();
    auto lambda = Lambda::create();
    lambda->main();
    return 0;
}
