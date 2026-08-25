#pragma once
#include <iostream> 
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
    public:
        std::vector<int> vec;

    public:

        void print_vector();
        void parseInput(int argc, char **argv);
        void make_pairs(std::vector<std::pair<int, int> >& pairs ,std::vector<int>& vec ,bool& has_odd , int& odd_num);
        std::vector<int> jacobInsertOrder(size_t n);
        std::vector<int> mergeInsertSort(std::vector<int> vec1);
        //void mergeInsertSort(std::vector<int> &vec, int left, int right);
};