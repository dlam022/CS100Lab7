#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

using namespace std;

class Op : public Base {
	private:
		double num = 0;
	public:
		Op(double value : Base() {
			this->num = value;
		}

		double evaluate() {return num; };
		string stringify() {return to_string(num); }
};

#endif
