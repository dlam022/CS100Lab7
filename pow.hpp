#ifndef __POW_HPP__
#define __POW_HPP__

#include <math.h>

#include "op.hpp"

using namespace std;

class Pow : public Base {
	public:
		Pow(Op* left, Op* right) {
			this->l = left;
			this->r = right;
		}

		virtual double evaluate() {
			return (pow(l->evaluate(), r->evaluate()));
		}

		virtual string stringify() {
			return ("(" + l->stringify() + " ** " + r->stringify() + ")");
		

	private:
		Op* l;
		Op* r; 
};

#endif
