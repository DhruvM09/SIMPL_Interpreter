#include "token.h"
#include <vector>

class expr{

    expr(){

    }

};

class Parser{
    private:
    std::vector<Token> tokens;
    Token token;
    int current;

    public:
    Parser(std::vector<Token> & tokens);
    void Parse();

    private:
    void match(TokenType tt);
    float expression();
    float factor();
    float term();
    float rem_expression(float lvalue);
    float rem_term( float lvalue);
    void next();

};



