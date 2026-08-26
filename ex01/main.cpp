#include "RPN.hpp"

int main(int argc , char **argv)
{   
    try 
    {
        (void)argc ;
        if(argc != 2)
            throw std::runtime_error("Error check your argument");
        RPN a ;
        std::string line ;
        line = argv[1];
        a.check_token(line);
        a.print_stack();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl ;
    }
    return 0;
}