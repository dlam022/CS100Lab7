#include "gtest/gtest.h"
#include "factory.hpp"
#include <cstdio>
#include <iostream>
#include <vector>

TEST(FactoryTest, NullptrTest) {
	Factory* test = new Factory();
	int length = 2;
	const char** input = new const char*[length];
	input[0] = "./calculator";
	input[1] = "2";

	Base* equation = test->parse(const_cast <char**> (input), 1);

	EXPECT_EQ(equation, nullptr);
}
