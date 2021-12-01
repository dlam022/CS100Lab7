#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

using namespace std;

class Rand : public Base {
	private:
		double num = rand() % 100;
	public:
		Rand() {}
		virtual double evaluate() { return num;}
		virtual string stringify() {to_string(num);}
};

#endif
