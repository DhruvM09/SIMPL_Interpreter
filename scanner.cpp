#include "scanner.h"
#include "utils.h"
#include "token.h"


std::vector<Token> Scanner::scanlines(std::vector<std::string> & lines){
    
    std::vector<Token> tokens;
    
    for(std::string line : lines){
        lineNumber++;
        currentLine = line;
        std::vector<Token> temp = Scanner::scanline();
        for(Token t : temp)tokens.push_back(t);
    }

    return tokens;

}

char Scanner::peek(){
    return currentLine[current];
}
char Scanner::Advance(){
    char c= currentLine[current];
    current++;
    return c;
}
std::vector<Token> Scanner::scanline(){

    std::vector<Token> tokens;
    current = 0;
    while(current < currentLine.size()){
        char c = Advance();
        switch (c)
        {
        case '+':
            tokens.push_back(CreateTokenSymbol(PLUS ,lineNumber));
        break;
        case '-':
            tokens.push_back(CreateTokenSymbol(MINUS,lineNumber));
        break;
        case '<':
            tokens.push_back(CreateTokenSymbol(LESS,lineNumber));
        break;
        case '>':
            tokens.push_back(CreateTokenSymbol(GREATER,lineNumber));
        break;
        case '=':
            if(current != currentLine.size() && peek() == '='){
                tokens.push_back(CreateTokenSymbol(EQUAL_EQUAL,lineNumber));
                current++;
            }else{
                tokens.push_back(CreateTokenSymbol(EQUAL,lineNumber));
            }
        break;
        case '/':
            if(current != currentLine.size() && peek() == '/'){
                //this is a comment  so ignore the rest of the line 
                current = currentLine.size();
            }else{
                tokens.push_back(CreateTokenSymbol(DIVIDE,lineNumber));

            }
        break;
        case '*':
            tokens.push_back(CreateTokenSymbol(MULTIPLY,lineNumber));
        break;

        case '"':
        {
            std::string val;
            while(peek() != '"'){
                val.push_back(peek());
                current++;
            }
            //to skip the ending "
            current++;
            tokens.push_back(CreateTokenString(STRING , val , lineNumber));
        }
        break;
        case '(':
            tokens.push_back(CreateTokenSymbol(LEFT_PARA,lineNumber));
        break;
        case ')':
            tokens.push_back(CreateTokenSymbol(RIGHT_PARA,lineNumber));
        break;
        case '{':
            tokens.push_back(CreateTokenSymbol(LEFT_BRACE,lineNumber));
        break;
        case '}':
            tokens.push_back(CreateTokenSymbol(RIGHT_PARA,lineNumber));
        break;



        case '\0':
        case '\n':
        case ' ':
        default:
            if(std::isalnum(c)){
                std::string value;
                value.push_back(c);
                while(isalnum(peek())){
                    value.push_back(peek());
                    current++;
                }
                if(std::isalpha(c)){
                    // if first was letter then its a string identifier or keyword 
                    tokens.push_back(CreateTokenString(IDENTIFIER , value,lineNumber));
                }else{
                    //else it is a number
                    float val = std::stof(value);
                    tokens.push_back(CreateTokenNum(NUM , val , lineNumber));
                }
            }
            break;
        }

    }
    return tokens;
}