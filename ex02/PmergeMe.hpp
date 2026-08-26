#pragma once
#include <iostream> 
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <deque>

class PmergeMe
{
    public:
        std::vector<int> vec;

    public:

        size_t get_size();
        void print_vector();
        void parseInput(int argc, char **argv);
        void make_pairs(std::vector<std::pair<int, int> >& pairs ,std::vector<int>& vec ,bool& has_odd , int& odd_num);
        void make_pairs_deque(std::deque<std::pair<int, int> >& pairs ,std::deque<int>& deq ,bool& has_odd , int& odd_num);
        std::vector<int> jacobInsertOrder(size_t n);
        std::vector<int> mergeInsertSort(std::vector<int> vec);
    };