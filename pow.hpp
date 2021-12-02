#ifndef _POW_HPP
#define _POW_HPP

#include <math.h>

#include "op.hpp"

using namespace std;

class Pow : public Base {
	public: 
		Pow(Base* left, Base* right) {
			this->l = left;
			this->r = right;
		}

		virtual double evaluate() {
			return (pow(l->evaluate(), r->evaluate()));
		}

		virtual string stringify() {
			return ("(" + l->stringify() + " ** " + r->stringify() + ")" );
		}

	private:
		Base* l;
		Base* r;

};

#endif

