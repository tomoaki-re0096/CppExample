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

	//! @brief 範囲For文確認用
	class RangeForTest
	{
	public:
		RangeForTest()
		{
			int i = 4;
			for (auto r = begin(); r!=end();r++ )
			{
				*r = i;
				i--;
			}
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
		//! @brief これをlambdaにしてsize内に入れようとしたがNの宣言ができないので難しそう？
		template<class T, std::size_t N>
		std::size_t arraySize(const T(&)[N]) const
		{
			return N;
		}
		//! [デフォルトメンバ初期化子](https://cpprefjp.github.io/lang/cpp11/non_static_data_member_initializers.html)
		static int const c_size = 5;
		int m_array[c_size]{0,1,2,3,4};
	};

	void RangeForStatement()
	{
		RangeForTest array;
		for (auto i : array)
		{
			std::cout << i << std::endl;
		}
	}

	void main() override
	{
		Decltype();
		RangeForStatement();

	}

private:

};

std::unique_ptr<Cpp11> Cpp11::create()
{
	return std::make_unique<Cpp11Impl>();
}
