#include "token.h"
#include <iostream>

Token::Token(TokenType type ,int lineNum){
    this->type = type;
    this->lineNum = lineNum;
}
Token::Token(TokenType type , std::string value , int lineNum){

    this->type = type;
    this->lineNum = lineNum;
    this->StringValue = value;
}
Token::Token(TokenType type , float value , int lineNum){

    this->type = type;
    this->lineNum = lineNum;
    this->NumValue = value;
}


void Token::print(){
    std::cout << lineNum << ' ' << TokenTypeMap[type] << ' ';
    if(type == NUM){
        std::cout << NumValue ;
    }
    if(type == STRING){
        std::cout << StringValue;
    }
    if(type == IDENTIFIER){
        std::cout << StringValue;
    }
    std::cout << '\n';
}

Token::Token(){

}