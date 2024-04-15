/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     October 16, 2023                          */
/*   Due Date:          October 18, 2023                          */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #3                                        */
/*   Filename:          expression.cpp                            */
/*   Purpose:           This file implements 2 functions. One to  */
/*                      evaluate a postfix experssion and one to  */
/*                      convert infix to postfix                  */
/******************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include "Token.h"

using namespace std;

double evaluatePostfix(vector<Token> tokens);
vector<Token> infixToPostfix(vector<Token> tokens);


double evaluatePostfix(vector<Token> tokens) {
  
  stack<double> Tstack;

  for (int i = 0; i < tokens.size(); i++) //loop for as longs as the tokens vector has items
    {
      if(tokens[i].tag == OPERAND) //if value is an operand, push to stack
	Tstack.push(tokens[i].d);
      else
	{
	  double OP2 = Tstack.top(); //variable to store item from stack
	  Tstack.pop(); //pop it out
	  double OP1 = Tstack.top(); //variable to store item from stack 
	  Tstack.pop(); //pop it out 

	  switch(tokens[i].o) //switch for the different options, then push the final product back into the stack
	    {
	    case ADD:
	      Tstack.push(OP1 + OP2);
	      break;
	    case SUBTRACT:
	      Tstack.push(OP1 - OP2);
	      break;
	    case MULTIPLY:
	      Tstack.push(OP1 * OP2);
	      break;
	    case DIVIDE:
	      if(OP2 == 0) //make sure no divide by 0
		return 0;
	      Tstack.push(OP1 / OP2);
	      break;
	    }
	}
	}
  return Tstack.top(); //return whats left in the stack
}
vector<Token> infixToPostfix(vector<Token> tokens) {
  vector<Token> result;
  
  stack<Token> Tstack;
  
  for (int i = 0; i < tokens.size(); i++) //loop for as longs as the tokens vector has items
    {
      if (tokens[i].tag == OPERAND) //if value is an operand, push to stack 
	result.push_back(tokens[i]);
      else if (tokens[i].tag == OPERATOR)
	{
	  while (!Tstack.empty() && Tstack.top().tag == OPERATOR && PrecedenceLevel(Tstack.top().o) >= PrecedenceLevel(tokens[i].o)) //if the stack isn't empty and the value is an operator and the precedence of the top operator is
	    {                                                                                                                        //greater then the one below, put the top into the result vector	    
	      result.push_back(Tstack.top());
	      Tstack.pop(); 
	    }
	  Tstack.push(tokens[i]);
	}
      else if (tokens[i].tag == LPAREN)
	Tstack.push(tokens[i]); //push left parenthesis into stack
      else if (tokens[i].tag == RPAREN)
	{
	  while (!Tstack.empty() && Tstack.top().tag != LPAREN)
	    {
	      result.push_back(Tstack.top()); //empty the stack into the result vector until it reaches a left parenthesis
	      Tstack.pop();
	    }
	  Tstack.pop(); //pop the left parenthesis
	}
    }
  
  while (!Tstack.empty()) //empty the rest of the stack
    {
      result.push_back(Tstack.top());
      Tstack.pop();
    }
  
  return result; 
}

int PrecedenceLevel(Operator operations) {  //helper funtion to determine the precedence level of the operators
  if(operations == ADD || operations == SUBTRACT)
    return 0;
  if(operations == MULTIPLY || operations == DIVIDE)
    return 1;
  return -1;
}
