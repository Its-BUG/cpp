#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
    try
    {
        if(ac < 2)
            throw std::runtime_error("check your args");
        
        BitcoinExchange a ;
        std::string file ;
        file = av[1];
        a.loaddatabase("data.csv");
        a.processInput(file);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}