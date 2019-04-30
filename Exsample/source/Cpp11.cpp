#include "Cpp11.h"

#include <iostream>



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


	//! @brief decltype を使用したtemplateの確認用
	template<class T, class U>
	auto decltypeTemplateTest(T lhs, U rhs) ->decltype(lhs + rhs)
	{
		return lhs + rhs;
	}
	//! @brief decltype
	//! https://cpprefjp.github.io/lang/cpp11/decltype.html
	void Decltype()
	{
		{
			int i = 10;
			decltype(i) ret = 1;

			std::cout << typeid(ret).name() << std::endl;
		}
		{
			auto ret_f = decltypeTemplateTest(1.0f, 0.5f);	
			auto ret_d = decltypeTemplateTest(1.0, 0.5);
			
			std::cout << typeid(ret_f).name() << std::endl;
			std::cout << typeid(ret_d).name() << std::endl;

		}
	}

	void main() override
	{
		Decltype();
	}

private:

};

std::unique_ptr<Cpp11> Cpp11::create()
{
	return std::make_unique<Cpp11Impl>();
}
