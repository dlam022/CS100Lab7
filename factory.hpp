#ifndef FACTORY_H
#define FACTORY_H
#include "base.hpp"
#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Factory
{
    private:
        Base* createExpression(Base* prevOperand, char currentOperator, Base* currentOperand){
            switch(currentOperator) {
                case '+': {
                    return new Add(prevOperand, currentOperand);
                    break;
		            }
                case '-' : {
                    return new Sub(prevOperand, currentOperand);
                    break;
			          }
		case '*' : {
		    return new Mult(prevOperand, currentOperand);
		    break;
		}
                case '/': {
                    if(currentOperand->evaluate() == 0) {
                         cout << "Cannot divide by zero" << endl;
                    }

                    if (currentOperand->evaluate() == 0) {
                         return nullptr;
                    }
                    else {
                         return new Div(prevOperand, currentOperand);
                    }

                    break;
                }

                case '^': {
                    return new Pow(prevOperand, currentOperand);
                    break;
                }
                default: {
                    return nullptr;
                }
            }
        }

	 bool validateOperator(char* input){
            int length = strlen(input);
            if(length == 1){  
               if(input[0] != '+' && input[0] != '-' && input[0] != '/' && input[0] != '*'){
                    return false;
                }
            }


            if(length == 2 && input[0] != '*' && input[1] != '*')  { 
	    	return false;
	    }

            return true;
        }

    public:
        Factory() {}
        
        Base* parse(char** input, int length){
            Base* prevOperand = nullptr;
            Base* currentOperand = nullptr;
            char currentOperator;
            bool endsWithOperator = false;
            for(unsigned i = 1; i < length; i++){
                char * endptr;
                int charToInt = (int) strtol(input[i], &endptr, 10);
                if(endptr != input[i]){
			if((*endptr) && (*endptr <= '0' || *endptr >= '9')){
                        return nullptr;
                    }
                    if(!prevOperand){
                        
                        
                        if(currentOperator) {
                            return nullptr;
                        }

                        prevOperand = new Op(charToInt);
                        endsWithOperator = false;
                    } else {
                        currentOperand = new Op(charToInt);
                        prevOperand = createExpression(prevOperand, currentOperator, currentOperand);
      
                        //delete currentOperand;
                                                                                        
                        currentOperator = '\0'; //reset
                        endsWithOperator = false;
                    }    
                } 
		else if(!validateOperator(input[i])) {
                    return nullptr;
                }
		else {
			if (strlen(input[i]) == 2) {
				currentOperator = '^';
			}
			else {
				currentOperator = input[i][0];
			}
                    endsWithOperator = true;
            	}
	    }
	    if (endsWithOperator) { return nullptr; }
	    else { return prevOperand; }
        };
};
#endif
