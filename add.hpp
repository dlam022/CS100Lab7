#ifndef __ADD_HPP_
#define __ADD_HPP_

#include "op.hpp"

using namespace std;

class Add : public Base {
//	private:
	//	double leftVal;
	//	double rightVal;
	//	string leftStr;
	//	string rightStr;
	//	Op* l;
	//	Op* r;
	public:
		Add(Base* left, Base* right){
		//	this-> l = left;
		//	this-> r = right;
			leftVal = left->evaluate();
			rightVal = right->evaluate();
			leftStr = left->stringify();
			rightStr = right->stringify();
		}
		virtual double evaluate() {
		//	return l->evaluate() + r->evaluate();
			return (leftVal + rightVal);
		}
		virtual string stringify() {
		//	return "(" + l->stringify() + " + " + r->stringify() + ")";
			return ("(" + leftStr + " + " + rightStr + ")" );
		}
	private:
		double leftVal;
		double rightVal;
		string leftStr;
		string rightStr;
	//	Op* l;
	//	Op* r;
};

#endif



