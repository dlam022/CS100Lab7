#include <iostream>
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "factory.hpp"
#include "base.hpp"
#include <string>

using namespace std;


int main(int argc, char**argv) {
    Factory* expressionTree = new Factory();
    
    for(unsigned i = 0; i < argc; i++) {
      cout << argv[i] << endl;
    }

    Base* result = expressionTree->parse(argv, argc);

    if(!result) {
      cout << "invalid expression Tree" << endl;
    } else {
      cout << result->stringify() << " = " << result->evaluate() << endl;
    }

    return 0;
}
