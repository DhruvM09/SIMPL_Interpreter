#include "rdparser.h"
#include <iostream>
Parser::Parser(std::vector<Token>& token){
    this->current = 1;
    this->tokens = token;
    this->token = tokens[0];
}

void Parser::next(){
    if(current < tokens.size()){
        token = tokens[current];
        current++;
    }
}
void Parser::match(TokenType tt){
    if(token.type!=tt ){
        std::cerr << " Line Number : " << token.lineNum << "expected " << TokenTypeMap[tt] << " got " << TokenTypeMap[token.type]; 
        exit(-1);
    }
    next();
}
float Parser::expression(){
    float lvalue = term(); 
    return rem_expression(lvalue);
};

float Parser::factor(){
    float value = 0.0;
    if(token.type == LEFT_PARA){
        match(LEFT_PARA);
        value = expression();
        match(RIGHT_PARA);
    }
    else{
        value = token.NumValue;
        match(NUM);
    }

    return value;
}
float Parser::rem_term(float lvalue){
    if(token.type == MULTIPLY){
        match(MULTIPLY);
        float value = lvalue * factor();
        return rem_term(value);
    }else if(token.type == DIVIDE){
        match(DIVIDE);
        float value = lvalue / factor();
        return rem_term(value);
    }else{
        return lvalue;
    }
}
float Parser::term(){
    float lvalue = factor();
    return rem_term(lvalue);
}
float Parser::rem_expression(float lvalue){
    if(token.type == PLUS){
        match(PLUS);
        float value = lvalue + term();
        return rem_expression(value);
    }else if(token.type == MINUS){
        match(MINUS);
        float value = lvalue - term();
        return rem_expression(value);
    }else{
        return lvalue;
    }
}


void Parser::Parse(){
    std::cout << expression() << '\n';
}
