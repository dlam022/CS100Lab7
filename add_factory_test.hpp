#ifndef __ADD_FACTORY_TEST_HPP__
#define __ADD_FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "factory.hpp"
#include <cstring>

TEST(ClassAdditionTest, AddEvaluateZero) {
	Factory* test = new Factory();
	char** input = new char*[4];

	char main[7] ="./main"; 
	input[0] = new char[strlen(main) + 1];
	input[0] = main;

	char first[2] ="1"; 
	input[1] = new char[strlen(first) + 1];
	input[1] = first;

	char op[2] ="+"; 
	input[2] = new char[strlen(op) + 1];
	input[2] = op;

	char second[2] ="0"; 
	input[3] = new char[strlen(second) + 1];
	input[3] = second;

	Base* op1 = new Op(1);
	Base* op2 = new Op(0);

	Base* add = new Add(op1, op2);

	EXPECT_EQ(test->parse(input, 4)->evaluate(), add->evaluate());
	delete add;
	delete input;
	delete test;
}

#endif
