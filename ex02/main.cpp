#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Error: No input provided. Please provide positive integers as arguments.");
        
        PmergeMe pmergeMe;
        pmergeMe.parseInput(argc, argv);
        pmergeMe.mergeInsertSort(pmergeMe.vec);
        //pmergeMe.print_vector();
        //pmergeMe.mergeInsertSort(pmergeMe.vec, 0, pmergeMe.vec.size() - 1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}