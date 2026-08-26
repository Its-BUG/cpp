#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Error: No input provided. Please provide positive integers as arguments.");
        
        PmergeMe pmergeMe;
        pmergeMe.parseInput(argc, argv);
        std::cout << "Before: ";
        pmergeMe.print_vector();
        std::cout << "After: ";
        clock_t start = clock();
        pmergeMe.mergeInsertSort(pmergeMe.vec);
        clock_t end = clock();
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        double elapsed_time_microseconds = elapsed_time * 1000000.0;
        pmergeMe.print_vector();
        std::cout << "Time to process a range of " << pmergeMe.get_size() << " elements with std::vector : " << elapsed_time_microseconds << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}