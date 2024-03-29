#ifndef Cpp11H
#define Cpp11H

#include "Base.h"

//! @brief C++11 機能確認用
class Cpp11 : public Base
{
public:
    static std::unique_ptr<Cpp11> create();
};
#endif // !Cpp11H
