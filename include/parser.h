#include "token.h"
#include <vector>


class Parser{
    private:
    std::vector<Token> tokens;
    public:
    Parser(std::vector<Token> & tokens);

};