#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"

class Sub : public Base {
	public:
		Sub(Base* left, Base* right) {
			this->l = left;
			this->r = right;
		}

		virtual double evaluate() {
			return l->evaluate() - r->evaluate();
		}
	
		virtual string stringify() {
			return "(" + l->stringify() + " - " + r->stringify() + ")";
		}

	private:
		Base* l;
		Base* r;

};

#endif
