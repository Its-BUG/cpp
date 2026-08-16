#include "RPN.hpp"

bool is_num(std::string& token)
{
    if (token.size() != 1)
        throw std::runtime_error("Error");
    return std::isdigit(token[0]);
}

int toInt(std::string& token)
{
    std::stringstream ss(token) ;
    int num ;
    ss >> num;
    if(ss.fail() || !ss.eof())
    {
        throw std::runtime_error("Error: check your num!\n");
    }
    else if(num > 9)
        throw std::runtime_error("Error: check your num!\n");
    return num ;
}

bool is_operator(std::string& token)
{
    return (token == "*" || token == "+" || token == "/" || token == "-");
}

int apply(int a , int b, std::string& op)
{
    int res ;
    if(op == "+") res = a + b ; 
    if(op == "*") res = a * b ;
    if(op == "/") res = a / b ;
    if(op == "-") res = a - b ;
    return res ;

}

void RPN::check_token(std::string& line)
{
    std::stringstream ss(line);
    std::string token ;
    while(ss >> token)
    {
        if(is_num(token))
        {
            int n ;
            n = toInt(token);    
            s.push(n);
        }
        else if(is_operator(token))
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(apply(b,a,token));
        }
    }
}