#include "utils.h"


Token CreateTokenSymbol(TokenType type , int lineNum){
    return Token(type , lineNum);
}
Token CreateTokenString(TokenType type , std::string value , int lineNum){
    return Token(type , value ,lineNum);
}
Token CreateTokenNum(TokenType type , float value , int lineNum){
    return Token(type , value , lineNum);
}