#include "Cpp11.h"

#include <iostream>
#include <vector>
#include <tuple>

//! @brief ユーザー定義リテラル
namespace UserDefinedLiteral
{
    //! operator"" が基本の記法。C++14以降からは、""の後に半角スペースが不必要になった。
    unsigned long long  operator""_msec(unsigned long long msec)
    {
        return msec;
    }
    unsigned long long  operator""_sec(unsigned long long sec)
    {
        return sec * 1000;
    }
    static void main()
    {
        std::cout << 5_sec << "msec" << std::endl;
        std::cout << 5000_msec << "msec" << std::endl;
    }
    
}

class Cpp11Impl :
    public Cpp11
{
public:
    Cpp11Impl()
    {

    }
    ~Cpp11Impl() override
    {

    }

    class Decltype
    {
    public:
        static void main()
        {
            Decltype test{};
        }
        //! @brief decltype
        //! https://cpprefjp.github.io/lang/cpp11/decltype.html
        Decltype()
        {
            //! 通常の宣言
            {
                int i = 10;
                decltype(i) ret = 1;

                std::cout << typeid(ret).name() << std::endl;
            }
            //! templateの場合でも可能
            {
                //関数から受け取る変数をautoにしておけば、実装が変わろうが呼び出し側のコードを変える手間がなくなる
                auto ret_f = decltypeTemplate(1.0f, 0.5f);
                auto ret_d = decltypeTemplate(1.0, 0.5);

                std::cout << typeid(ret_f).name() << std::endl;
                std::cout << typeid(ret_d).name() << std::endl;

            }
        }
        //! @brief decltype を使用したtemplateの確認用
        template<class T, class U>
        auto decltypeTemplate(T lhs, U rhs) ->decltype(lhs + rhs)
        {
            //! lhs + rhs の演算結果により式が確定
            return lhs + rhs;
        }
        
    private:

    };

    //! @brief 範囲For文確認用
    class RangeForStatement
    {
    public:
        static void main()
        {
            RangeForStatement array{};
            for (auto i : array)
            {
                std::cout << i << std::endl;
            }
        }
        RangeForStatement()
        {
            //! コメントを解除すると、デフォルトメンバ初期化子の方が先に呼ばれていることがわかる。
            /*int i = 4;
            for (auto r = begin(); r!=end();r++ )
            {
                *r = i;
                i--;
            }*/
        }
        int* begin()
        {
            return m_array;
        }
        int* end()
        {
            return &m_array[size()];
        }
        std::size_t const size() const
        {
            return arraySize(m_array);
        }

    private:
        template<class T, std::size_t N>
        //! @brief これをlambdaにしてsize内に入れようとしたがNの宣言ができないので難しそう？
        std::size_t arraySize(const T(&)[N]) const
        {
            return N;
        }
        //! [非静的メンバ変数の初期化](https://cpprefjp.github.io/lang/cpp11/non_static_data_member_initializers.html)
        //! 宣言時に初期値を代入できるので、初期化忘れなどを避けられる。
        static int const c_size = 5;
        int m_array[c_size]{0,1,2,3,4};
    };


    class MoveSemantics
    {
    public:
        //! ムーブコンストラクタ・ムーブ演算子は以下の条件を満たすクラス内では自動生成されている。
        //! クラスがコピー演算を宣言していない
        //! クラスがムーブ演算を宣言していない
        //! クラスがデストラクタを宣言していない
        static void main()
        {
            MoveSemantics   lvalue1{};
            MoveSemantics   lvalue2{};
            MoveSemantics   r_operator{};
            MoveSemantics   r_constructor1(std::move(lvalue1));//ムーブコンストラクタ
            r_operator = std::move(lvalue2);//ムーブ演算子
        }
        MoveSemantics()
        {
            m_ptr = new auto(10);
        }
        //! @brief ムーブコンストラクタ
        MoveSemantics(MoveSemantics&& rvalue)
        {
            m_ptr = rvalue.m_ptr;
            rvalue.m_ptr = nullptr;
        }
        //! @brief ムーブ演算子
        MoveSemantics& operator=(MoveSemantics&& rvalue)
        {
            m_ptr = rvalue.m_ptr;
            rvalue.m_ptr = nullptr;
            return *this;
        }

        ~MoveSemantics()
        {
            delete m_ptr;
        }

    private:
        int*    m_ptr{nullptr};
    };

    //! @brief エイリアステンプレート
    class AliasTemplate
    {
    public:
        template<class T>
        using Vec = std::vector<T>; //! @brief templateを使用した型の別名定義

        static void main()
        {
            AliasTemplate test{};
        }
        AliasTemplate()
        {
            for (auto i : m_my_vec)
            {
                std::cout << i << std::endl;
            }
        }
       
    private:
        Vec<int>    m_my_vec{0,1,2,3,4};
    };

    //! @brief 可変引数テンプレート。やっては見たが、いまいち効果的な方法が思いつかない
    template<class... Args1>
    class VariableArgumentTemplate
    {
    public:
        static void main()
        {
            std::string str{ "test" };
            VariableArgumentTemplate m_test(1, 1.5, str);
        }
        VariableArgumentTemplate(Args1... args)
        {
            f(args ...);
        }
        void f(int i, float f, std::string str)
        {

        }
    private:

    };

    /*
        ### [明示的な型変換演算子のオーバーロード](https://cpprefjp.github.io/lang/cpp11/explicit_conversion_operator.html)
        どんな機能？<br>
        　operatorなどで、明示的に型変換した時のみに呼ばれる事を指定できる
        何に使える？<br>
        　使えると思ったが、下記のようにoperatorに特殊な対応をするだけでも対応できるし、
        　下手に型変換を明示的にした時のみ別関数が通るという時点で、可読性やらが悪くなりそう
    */
    class ExplicitOperatorOverload
    {
    public:
        ExplicitOperatorOverload() = default;
        ~ExplicitOperatorOverload() = default;
        //! if文、明示的キャストなどの時のみ呼ばれる。
        explicit operator bool() 
        {
            auto is_even=[this]()
            {
                return (count++ % 2) == 0 ? true : false;
            };
            return is_even();
        }

        static void main()
        {
            ExplicitOperatorOverload even_check{};
            for (int i = 0; i < 5; i++)
            {
                if (even_check) { std::cout << "even:" << i << std::endl; }
            }
        }
    private:
        int count = 0;
    };


    void main() override
    {
        Decltype::main();
        RangeForStatement::main();
        MoveSemantics::main();
        UserDefinedLiteral::main();
        AliasTemplate::main();
        VariableArgumentTemplate<int, float, std::string>::main();
        //ExplicitOperatorOverload::main();
    }

private:

};

std::unique_ptr<Cpp11> Cpp11::create()
{
    return std::make_unique<Cpp11Impl>();
}
