#include "BitcoinExchange.hpp"

double BitcoinExchange::Todouble(std::string& value)
{
    std::stringstream ss(value);
    double vvalue ;

    ss >> vvalue ;
    if(ss.fail())
        throw std::runtime_error("Error : fail stream!");
    return vvalue;
}

std::map<std::string, double>& BitcoinExchange::loaddatabase(std::string filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        throw std::runtime_error("error open file");
    }

    std::string line ;
    std::getline(file,line);
    while(std::getline(file,line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        if(!std::getline(ss, date, ','))
            continue;
        if(!std::getline(ss, value))
            continue;

        double vvalue = Todouble(value);
        db[date] = vvalue ;
    }
    return db;
}

void trim(std::string &s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end   = s.find_last_not_of(" \t");

    if (start == std::string::npos)
        s.clear();
    else
        s = s.substr(start, end - start + 1);
}

double BitcoinExchange::parseValue(std::string& value)
{
       std::stringstream ss(value);
    double vvalue ;

    ss >> vvalue ;
    if(ss.fail() || !ss.eof())
        throw std::runtime_error("Error: bad input => " + value);
    if(vvalue < 0)
        throw std::runtime_error("Error: not a positive number.");
    if(vvalue > 1000)
        throw std::runtime_error("Error: too large a number.");        
    return vvalue;
}

double BitcoinExchange::getRateForDate(std::string& date)
{
    std::map<std::string, double>::iterator it ;

    it = db.lower_bound(date);

    if(it != db.end() && it->first == date)
        return it->second ;
    if(it == db.begin())
        throw std::runtime_error("Error date not found");
    --it;
    return it->second ;
}

bool BitcoinExchange::isvalidformat(std::string& line)
{
    if(line.length() != 10)
        return false ;
    if(line[4] != '-' || line[7] != '-')
        return false;
    static const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = atoi(line.substr(0, 4).c_str());
    int month = atoi(line.substr(5, 2).c_str());
    int day = atoi(line.substr(8, 2).c_str());
    int maxday ;
    maxday = days_in_month[month -1];
    bool is_Leep = (((year % 4) == 0 && (year % 100) != 0) || year % 400 == 0) ;
    if(month == 2 && is_Leep)
        maxday = 29 ;
    if(month < 1 || month > 12)
        return false;
    if(day < 1 || day > maxday)
        return false;
    return true ;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        throw std::runtime_error("error open file!\n");
    }
    std::string line ;
    std::string date ;
    std::string value ;
    std::getline(file,line);
    while (std::getline(file,line))
    {
        std::stringstream ss(line);

        std::getline(ss,date,'|');
        std::getline(ss,value);
        
        trim(date);
        trim(value);
        try
        {
            if(!isvalidformat(date))
                throw std::runtime_error("Error: bad input => " + date);
            double v = parseValue(value);
            double rate = getRateForDate(date);

            std::cout << date << " => " << v << " = " << v * rate << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}









