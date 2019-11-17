#ifndef LAMBDA_H 
#define LAMBDA_H 

#include "Base.h"

class Lambda : public Base
{
public:
    static std::unique_ptr<Lambda> create();
};

#endif // !LAMBDA_H 

