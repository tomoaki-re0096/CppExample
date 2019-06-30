#include "Cpp17.h"

#include <iostream>
#include <map>

class Cpp17Impl : public Cpp17
{
    //! if文とswitch文の条件式と初期化を分離
    class IfSwitchInitialize
    {
    public:
        static void main()
        {
            IfSwitchInitialize test{};
        }
        IfSwitchInitialize()
        {
            constexpr int s_const_value = 10;
            enum class eTest
            {
                A,
                B,
                C,
                Num
            };
            if (auto value = s_const_value; value == s_const_value)
            {
                switch (auto test = eTest::C)
                {
                case eTest::A:
                    break;
                case eTest::B:
                    break;
                case eTest::C:
                    std::cout << "select C" << std::endl;
                    break;
                case eTest::Num:
                    break;
                default:
                    break;
                }
            }
        }
    };

    //! 構造化束縛
    class StructuredBinding
    {
    public:
        //! 確認用のデータクラス。
        //! 想定例：何かしらのリソースバッファを、インデックスと、文字列で紐づけをしようとしている的な？
        class Test
        {
        public:
            Test() : key(s_key++){}
            //! メンバの一部変数をまとめて取り出すことができる。
            std::pair<int, std::string&> get()
            {
                return { key, value };
            }
        private:
            static int s_key;
            int key;
            std::string value{""};
            void* p_data = nullptr;
        };

        static void main()
        {
            StructuredBinding test{};
        }
        StructuredBinding()
        {
            constexpr int s_num = 5;
            Test test_array[s_num]{};
            constexpr char const *s_value_array[s_num] =
            {
                "A",
                "B",
                "C",
                "D",
                "E"
            };
            for (auto& _test : test_array)
            {
                //! _valueが string& _value 表記になっているが、get関数が参照を返さないと参照にはなっていない模様。
                auto[_key, _value] = _test.get();
                //! メンバを各々取り出すことができる。
                _value = s_value_array[_key];
            }

            std::map<std::string, int> m = {
                {"Alice", 3},
                {"Bob", 1},
                {"Carol", 4}
            };
            // mapの各要素をキーと値に分解する。
            // const auto&ではなくauto&にした場合は、
            // const std::string&型のkey変数と、
            // int&型のvalue変数に分解される。
            for (const auto&[_key, _value] : m) 
            {
                std::cout << _key.c_str() << " : " << _value << std::endl;
            }
        }
    };

    void main() override
    {
        IfSwitchInitialize::main();
        StructuredBinding::main();
    }
};
int Cpp17Impl::StructuredBinding::Test::s_key = 0;


std::unique_ptr<Cpp17> Cpp17::create()
{
    return std::make_unique<Cpp17Impl>();
}
