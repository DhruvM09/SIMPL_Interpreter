#include "token.h"
#include <vector>


class expr{

    expr(){

    }

};

class Parser{
    private:
    Token token;
    TokenType baseType;// type of declaration
    int exprType; // if / while / etc..
    
    public:
    int current;
    Parser(std::vector<Token> & tokens);
    Parser();
    void Parse();
    std::vector<Token> tokens;

    private:
    void program();
    void globals();
    void variables();
    void statement();
    void match(TokenType tt);
    float expression();
    float factor();
    float term();
    float rem_expression(float lvalue);
    float rem_term( float lvalue);
    void next();

};



