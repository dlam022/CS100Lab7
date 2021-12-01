#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"

using namespace std;

class Mult : public Base {
	private:
		Base* l;
		Base* r;

	public:
		Mult(Base* left, Base* right) {
			this->l = left;
			this->r = right;
		}

		virtual double evaluate() {
			return l->evaluate() * r->evaluate();
		}

		virtual string stringify() {
			return "(" + l->stringify() + " * " + r->stringify() + ")";
		}

#endif
