#ifndef SmartPtrH 
#define SmartPtrH 
#include"Base.h"

class SmartPtr : public Base
{
public:
    static std::unique_ptr<SmartPtr> create();
};

#endif // !SmartPtrH 
