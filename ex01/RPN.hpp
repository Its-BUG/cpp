#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
    private :
    std::stack<int> s ;

    public:
    RPN() ;
    RPN(RPN& o) ;
    RPN& operator=(RPN& o) ;
    ~RPN() ;
     
    void check_token(std::string& line);
    void print_stack();
};
