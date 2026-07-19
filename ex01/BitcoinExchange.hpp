#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
    std::map<std::string, double> db ;

    public:
    /*BitcoinExchange();
    BitcoinExchange(std::map<std::string, double>& db);
    BitcoinExchange(BitcoinExchange& o);
    BitcoinExchange& operator=(BitcoinExchange& o);
    */
   
    std::map<std::string, double>& loaddatabase(std::string filename);
    void processInput(const std::string& filename);
    private:
    bool isvalidformat(std::string& line);
    double Todouble(std::string& value);
    double getRateForDate(std::string& date);
    double parseValue(std::string& value);
};

#endif