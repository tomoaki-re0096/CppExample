#ifndef BaseH
#define BaseH

#include <memory>

//! @brief 基底クラス 
class Base
{
public:
    Base();
    virtual ~Base() = default;

    virtual void main() = 0;
};
#endif // !BaseH
