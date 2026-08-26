#include "PmergeMe.hpp"

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
            std::stringstream iss(arg);
            int num;
            iss >> num;
            if(iss.fail() || !iss.eof())
                throw std::invalid_argument("Error: Invalid input. Invalid number.");
            if (num < 0)
                throw std::invalid_argument("Error: Invalid input. Negative number.");
            if(std::find(vec.begin(), vec.end(), num) != vec.end())
                throw std::invalid_argument("Error: Invalid input. Duplicate number.");
            vec.push_back(num);
    
    }
}

void print_vector1(std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_vector()
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::make_pairs(std::vector<std::pair<int, int> >& pairs, std::vector<int>& vec, bool& has_odd, int& odd_num)
{
    size_t i = 0;
    for (; i < vec.size() - 1; i += 2)
    {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
    if (vec.size() % 2 != 0)
    {
        has_odd = true;
        odd_num = vec.back();
    }
    else
    {
        has_odd = false;
    }
}

std::vector<int> PmergeMe::jacobInsertOrder(size_t n)
{
    std::vector<int> order;
    if (n < 2)
        return order; // only b1 exists, nothing else to insert

    // Build Jacobsthal sequence until it reaches/exceeds n
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);
    while (J.back() < n)
        J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
    // J = [0, 1, 1, 3, 5, 11, 21, ...]

    size_t prevBoundary = 1; // index 1 (b1) already handled
    for (size_t i = 2; i < J.size(); ++i)
    {
        size_t boundary = J[i];
        if (boundary > n)
            boundary = n; // cap at however many pend elements we actually have

        for (size_t k = boundary; k > prevBoundary; --k)
            order.push_back(k);

        prevBoundary = boundary;
        if (boundary >= n)
            break;
    }
    return order;
}

bool compairpairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.second < b.second;
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> vec)
{
    if (vec.size() <= 1)
        return vec;

    std::vector<std::pair<int, int> > pairs;
    bool has_odd = false;
    int odd_num = 0;

    make_pairs(pairs, vec, has_odd, odd_num);

    std::sort(pairs.begin(), pairs.end(), compairpairs);

    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);
    
    std::vector<int> main_chain = mergeInsertSort(larger);
    main_chain.insert(main_chain.begin(), pairs[0].first);

    std::vector<int> order = jacobInsertOrder(pairs.size());

    for(size_t i = 0; i < order.size(); ++i)
    {
        size_t index = order[i] ;
            int element_to_insert = pairs[index - 1].first;
            int element_paired = pairs[index - 1].second;

        std::vector<int>::iterator itp = std::find(main_chain.begin(), main_chain.end(), element_paired);
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), itp , element_to_insert);
        main_chain.insert(it, element_to_insert);
    }
    if (has_odd)
    {
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), odd_num);
        main_chain.insert(it, odd_num);
    }
    this->vec = main_chain;
    return main_chain;
}

size_t PmergeMe::get_size()
{
    return vec.size();  
}