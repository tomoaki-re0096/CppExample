#pragma once
#include "Base.h"
class Cpp11 :
	public Base
{
public:
	static std::unique_ptr<Cpp11> create();
};

