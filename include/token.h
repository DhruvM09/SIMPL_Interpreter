#include <string>
#include <map>
#pragma once

enum TokenType{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LEFT_PARA,
    RIGHT_PARA,
    LEFT_BRACE,
    RIGHT_BRACE,
    EQUAL,
    EQUAL_EQUAL,
    LESS,
    GREATER,
    LESS_EQUAL,
    GREATER_EQUAL,
    NOT_EQUAL,
    IDENTIFIER,
    NUM,
    STRING,
    VAR,
    PRINT,
    SET,
    LOOP,
    ENDOFFILE
};
static std::map<TokenType , std::string> TokenTypeMap = {
    {PLUS , "plus"},
    {MINUS , "minus"},
    {MULTIPLY , "multiply"},
    {DIVIDE , "divide"},
    {LEFT_PARA , "left_para"},
    {RIGHT_PARA , "right_para"},
    {LEFT_BRACE , "left_brace"},
    {RIGHT_BRACE , "right_brace"},
    {EQUAL , "equal"},
    {EQUAL_EQUAL , "equal_equal"},
    {LESS , "less"},
    {GREATER , "greater"},
    {LESS_EQUAL , "less_equal"},
    {GREATER_EQUAL , "greater_equal"},
    {NOT_EQUAL ,"not_equal"},
    {IDENTIFIER ,"identifier"},
    {NUM, "num"},
    {STRING, "string"},
    {VAR, "var"},
    {PRINT, "print"},
};
class Token{
    private:
    int lineNum;
    TokenType type;
    float NumValue;
    std::string StringValue;
    public:
    Token(TokenType type, int lineNum);
    Token(TokenType type , float NumValue , int lineNum);
    Token(TokenType type , std::string StringValue , int lineNum);

    void print();
};

