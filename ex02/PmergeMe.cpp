#include "PmergeMe.hpp"

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        try
        {
            std::stringstream iss(arg);
            int num;
            iss >> num;
            if(iss.fail() || !iss.eof())
                throw std::invalid_argument("Invalid number");
            if (num < 0)
                throw std::invalid_argument("Negative number");
            if(std::find(vec.begin(), vec.end(), num) != vec.end())
                throw std::invalid_argument("Duplicate number");
            vec.push_back(num);
        }
        catch (const std::invalid_argument&)
        {
            throw std::runtime_error("Error: Invalid input. Please provide positive integers only.");
        }
    }
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

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> vec)
{
    std::cout << vec.size() << std::endl;
    if (vec.size() <= 1)
        return vec;

    std::vector<std::pair<int, int> > pairs;
    bool has_odd = false;
    int odd_num = 0;

    make_pairs(pairs, vec, has_odd, odd_num);

    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        //larger.push_back(pairs[i].first);
        larger.push_back(pairs[i].second);
    }

    std::vector<int> sorted_larger = mergeInsertSort(larger);
 
    return sorted_larger;
}