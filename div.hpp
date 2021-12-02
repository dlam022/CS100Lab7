#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"
#include "op.hpp"

using namespace std;


struct DivideByZero : public std::exception {
        const char* what() const throw() {
                return "Divide By Zero Exception";
        }
};

class Div : public Base {
	private:
		Base* l;
		Base* r;
	public:
		Div(Base* left, Base* right) {
			this->l = left;
			this->r = right;
		}
		virtual double evaluate() {
			if (r->evaluate() == 0) {
				throw DivideByZero();
			}
			return l->evaluate() / r->evaluate();
		}

		virtual string stringify() {
			return "(" + l->stringify() + " / " + r->stringify() + ")";
		}
};


#endif
