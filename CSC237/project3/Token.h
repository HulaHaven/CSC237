/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     October 16, 2023                          */
/*   Due Date:          October 18, 2023                          */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #3                                        */
/*   Filename:          Token.h                                   */
/*   Purpose:           Added a helper function to determine the  */
/*                      precedence level of operators             */
/******************************************************************/
/**
 * @file Token.h
 * @author Dr. Schwesinger
 */
#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

/**
 * Tag represents a categories of token types
 */
enum Tag { OPERATOR, OPERAND, LPAREN, RPAREN };

/**
 * @brief Operator represents types of binary operations
 */
enum Operator { ADD, SUBTRACT, MULTIPLY, DIVIDE };

/**
 * @brief A data structure to represent a token parsed from a string.
 */
struct Token {
    /** a numeric value -- only valid if the tag is OPERAND */
    double d;
    /** an operator type -- only valid if the tag is OPERATOR */
    Operator o;
    /** the category of the token */
    Tag tag;
};

/**
 * @brief convert an Operator to a std::string
 * @param o the operator
 * @return a string representation of the operator
 */
std::string opToString(Operator o);

/**
 * @brief An overloaded stream insertion operator for the Token type.
 * @param os the output stream object
 * @param t the Token to be inserted into the stream
 * @return the same ostream that was passed in
 */
std::ostream& operator<<(std::ostream& os, const Token& t);

/**
 * @brief parse a string representing a simple arithmetic expression
 * into sequence of tokens.
 * @param s the string to parse
 * @return the result of parsing the string into tokens
 */
std::vector<Token> tokenize(std::string s);
int PrecedenceLevel(Operator operations);
#endif
