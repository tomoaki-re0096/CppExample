#include "SmartPtr.h"


class SmartPtrImpl : public SmartPtr
{
private:
    void main() override
    {

    }

    class SharedPtr
    {
        static void main()
        {

        }
    };

    class UniquePtr
    {
        static void main()
        {

        }
    };
};

std::unique_ptr<SmartPtr> SmartPtr::create()
{
    return std::unique_ptr<SmartPtrImpl>();
}
