#ifndef __ADD_HPP_
#define __ADD_HPP_

#include "op.hpp"
#include "base.hpp"


using namespace std;

class Add : public Base
	public:
		Add(Base* left, Base* right) {
			leftVal = right->evaluate();
			rightVal = right->evaluate();
			leftStr = left->stringify();
			rightStr = right->stringify();
		}

		virtual double evaluate() {
			return (leftVal + rightVal);
		}

		virtual string stringify() {
			return ("(" + leftStr + " + " + rightStr + ")");
		}

	private:
		double leftVal;
		double rightVal;
		string leftStr;
		string rightStr;
};

#endif
