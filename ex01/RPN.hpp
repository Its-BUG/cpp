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
    
    void check_token(std::string& line);
    void print_stack()
    {
        std::stack<int> temp = s;
        while (!temp.empty())
        {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};
