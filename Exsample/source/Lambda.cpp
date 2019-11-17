#include "Lambda.h"
#include <functional>
#include <iostream>


class LambdaImpl : public Lambda
{
private:
    void main() override
    {
        //!ラムダ式を宣言した時点で、関数オブジェクトのクラスが定義され、
        //!一時オブジェクトが生成される。これをクロージャオブジェクトという
        auto lambda_func = []()
        {
            std::cout << "lambda" << std::endl;
        };
        lambda_func();

        //! キャプチャ
        int copy_num = 0;
        int ref_num = 0;
        [lambda_func, copy_num,&ref_num, this]() mutable // コピーキャプチャした変数は基本変更できない。mutableを指定すると変更が可能
        {
            copy_num++; ref_num++; m_num++;
            std::cout << "キャプチャ" << std::endl;
            std::cout << "copy_num"<< copy_num << std::endl;
            std::cout << "ref_num" << ref_num << std::endl;
            std::cout << "m_num" << m_num << std::endl;
            lambda_func();
        }();//変数化せずに即ラムダの関数を呼び出す時はこれでよい
        std::cout << "copy_num" << copy_num << std::endl;
        std::cout << "ref_num" << ref_num << std::endl;
        
        //ジェネリックラムダ
        struct AInt
        {
            int num;
        };
        struct BInt
        {
            int num;
        };
        struct AFloat
        {
            float num;
        };
        struct BFloat
        {
            float num;
        };
        auto generic_lambda = [](auto a, auto b)
        {
            std::cout << "generic_lambda" << a.num + b.num << std::endl;
        };
        AInt a_i{ 2 }; BInt b_i{ 4 };
        generic_lambda(a_i, b_i);
        AFloat a_f{ 3.f }; BFloat b_f{ 5.5f };
        generic_lambda(a_f, b_f);

        //ラムダ式の初期化キャプチャ
        [num = copy_num+ref_num]()
        {
            std::cout << "initialize_lambda" << num << std::endl;
        }();

    }
    int m_num{};
    std::function<void()> m_func;
};


std::unique_ptr<Lambda> Lambda::create()
{
    return std::make_unique<LambdaImpl>();
}
