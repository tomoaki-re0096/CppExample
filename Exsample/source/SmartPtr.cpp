#include "SmartPtr.h"


class SmartPtrImpl : public SmartPtr
{
private:
    class TestClass
    {
    public:
        TestClass()
        {

        }
        ~TestClass()
        {

        }
    };
    //! shared_ptr
    void sharedTest()
    {
    
    }
    //! unique_ptr
    void uniqueTest()
    {

    }
    void main() override
    {
        sharedTest();
        uniqueTest();
    }
};

std::unique_ptr<SmartPtr> SmartPtr::create()
{
    return std::make_unique<SmartPtrImpl>();
}
