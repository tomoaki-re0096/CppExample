#include "SmartPtr.h"
#include <iostream>

class SmartPtrImpl : public SmartPtr
{
private:
    class TestClass
    {
    public:
        TestClass(const char* msg)
        {
            std::cout << "constructor:" << msg << std::endl;
        }
        ~TestClass()
        {
            std::cout << "destructor" << std::endl;
        }
    };

    //! shared_ptr
    void sharedTest()
    {
        auto null_check = [](auto& ptr)
        {
            if (!ptr) { std::cout << "null" << std::endl; }
        };
        auto ptr = std::make_shared<TestClass>("shared");
        {
            auto copy = ptr;
            null_check(ptr);//sharedはコピーが出来るのでptrは有効
        }
        std::cout << "end" << std::endl;
    }
    //! unique_ptr
    void uniqueTest()
    {
        auto null_check = [](auto& ptr) 
        {
            if (!ptr) { std::cout << "null" << std::endl; }
        };

        auto ptr = std::make_unique<TestClass>("unique");
        {
            // コピーは出来ない。移行のみで、その時はstd::move
            auto move = std::move(ptr);
            null_check(ptr);
        }

        auto create_unique = []() {return std::make_unique<TestClass>("right"); };
        //! この時はmoveは必要なし
        auto right_num = create_unique();

        std::cout << "end" << std::endl;

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
