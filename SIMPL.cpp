#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "token.h"
#include "scanner.h"
#include "rdparser.h"

void runfile(std::string filename){
    std::ifstream inputFile(filename);
    if(!inputFile.is_open()){
        std::cerr<< "unable to open file" << std::endl;
        return;
    }
    // read line by line
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(inputFile , line)){
        lines.push_back(line);
        std::vector<std::string> curline;
        curline.push_back(line);
        // scan tokens
        Scanner scanner;
        std::vector<Token> tokens = scanner.scanlines(curline); 
        //print
        // for(auto t : tokens){
        //     t.print();
        // }
        
    //parser
    Parser parser(tokens);
    parser.Parse();
    }
    
    
    

}

int main(int argc , char ** argv){
    
    if(argc < 2){
        std::cerr << "no file given"<< std::endl;
        return -1;
    }
    std::string filename = argv[1];
    runfile(filename);

    
}