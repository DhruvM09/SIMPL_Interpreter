#pragma once
#include "token.h"
#include <vector>
#include <string>
#include <map>

class Scanner{
    private:
    std::string currentLine;
    int current;

    public:
        int lineNumber = 0;


    char peek();
    char Advance();
    bool check(char c);
    std::vector<Token> scanlines(std::vector<std::string>& lines);
    std::vector<Token> scanline();
    
    

};