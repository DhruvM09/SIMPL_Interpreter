
#include "token.h"


Token CreateTokenSymbol(TokenType type , int lineNumber);

Token CreateTokenNum(TokenType type , float value ,int lineNumber);
Token CreateTokenString(TokenType type , std::string value , int lineNumber);