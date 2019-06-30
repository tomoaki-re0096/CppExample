#ifndef Cpp17H
#define Cpp17H
#include "Base.h"

class Cpp17 : public Base
{
public:
    static std::unique_ptr<Cpp17> create();
};

#endif // !Cpp17H
