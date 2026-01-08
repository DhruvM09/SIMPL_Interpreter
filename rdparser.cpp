#include "rdparser.h"
#include <iostream>
#include "utils.h"

std::map<std::string ,SymbolTableStorage> symbolTable;
Parser::Parser(std::vector<Token>& tokenPass){
    this->current = 0;
    this->tokens = tokenPass;
    this->token = tokens[0];
}
Parser::Parser(){
    this->current = 0;
    

}

void Parser::next(){
    if(current < tokens.size()){
        token = tokens[current];
        current++;
    }
}
void Parser::match(TokenType tt){
    if(token.type!=tt ){
        std::cerr << " Line Number : " << token.lineNum << " expected " << TokenTypeMap[tt] << " got " << TokenTypeMap[token.type]; 
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
    bool isNeg = 0;
    if(token.type == MINUS){
        match(MINUS);
        isNeg= 1;
    }
    if(token.type == LEFT_PARA){
        match(LEFT_PARA);
        value = expression();
        match(RIGHT_PARA);
    }
    else if(token.type == IDENTIFIER){
        if(symbolTable.count(token.StringValue)){
            if(symbolTable[token.StringValue].TokenClass == STRING){
                std::cerr  << "line " << token.lineNum<< " invalid variable , variable is not a NUM" << '\n';
                exit(-1);
            }
            value =  symbolTable[token.StringValue].NumValue;
            match(IDENTIFIER);
            
        }else{
            std::cerr << "line " << token.lineNum << " variable not found\n";
            exit (-1);
        }
        
    }
   else{
        value = token.NumValue;
        match(NUM);
    }

    if(isNeg)value = value * -1;
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

void Parser::program(){
    next();
    while(current < tokens.size()){
        statement();
    }
}
void Parser::globals(){
}
void Parser::statement(){
    //for printing
    if(token.type == PRINT){
        match(PRINT);
        if(token.type == IDENTIFIER){
            if(symbolTable.count(token.StringValue) == 0){
                std::cerr <<  "line " << token.lineNum<< "variable not found" << '\n';
                exit(-1);
            }
            if(symbolTable[token.StringValue].TokenClass == NUM){
                std::cout << symbolTable[token.StringValue].NumValue;
            }else{
                std::cout << symbolTable[token.StringValue].StringValue;
            }
            std::cout << '\n';
            match(IDENTIFIER);
        }else if(token.type == STRING){
            std::cout << token.StringValue << '\n';
            match(STRING);
        }
    }
    //variable declaration
    else if(token.type == VAR){
        match(VAR);
        Token temp = token;
        match(IDENTIFIER);
        SymbolTableStorage store;
        store.name = temp.StringValue;
        store.type = VAR;
        match(EQUAL);

        if(token.type != NUM && token.type != MINUS){

            store.TokenClass = STRING;
            store.StringValue = token.StringValue;
            match(STRING);
 
        }else{
            store.TokenClass = NUM;
            store.NumValue = expression();
       }
        symbolTable[store.name] = store;
    }
    //functions 
    else if(token.type == FUNC){

    }
    //if
    else if(token.type == IF){
        match(IF);
        match(LEFT_PARA);
        int assign = (int)expression();
        match(RIGHT_PARA);
        match(LEFT_BRACE);
        if(assign > 0){
        while(token.type != RIGHT_BRACE){
            statement();
        }
        match(RIGHT_BRACE);
        }else{
            while(token.type != RIGHT_BRACE)next();
            match(RIGHT_BRACE);
        }
    }else {
        next();
    }
    
}

void Parser::Parse(){
    program();

}
