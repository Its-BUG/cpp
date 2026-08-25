#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Error: No input provided. Please provide positive integers as arguments.");
        
        PmergeMe pmergeMe;
        pmergeMe.parseInput(argc, argv);
        pmergeMe.print_vector(); 
        std::cout << "After sorting: \n";
        pmergeMe.mergeInsertSort(pmergeMe.vec);
        pmergeMe.print_vector();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}