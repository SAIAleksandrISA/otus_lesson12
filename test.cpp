#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <iomanip>

class CsvParser
{
public:
    static std::vector<std::string> parseLine(const std::string& line)
    {
        std::vector<std::string> result;
        std::string current;
        bool inQuotes = false;
        for (char ch : line)
        {
            if (ch == '\"')
            {
                inQuotes = !inQuotes;
            }
            else if (ch == ',' && !inQuotes)
            {
                result.push_back(current);
                current.clear();
            }
            else
            {
                current += ch;
            }
        }
        result.push_back(current);
        return result;
    }
};

class MeanReducer
{
public:
    void run()
    {
        std::string key;
        double price;
        while (std::cin >> key >> price)
        {
            m_sum += price;
            m_count += 1;
        }
        if (m_count > 0)
        {
            std::cout << "Average: " << (m_sum / m_count) << std::endl;
        }
    }
private:
    double m_sum = 0.0;
    size_t m_count = 0;
};

void testCsvParser()
{
    std::string line = "a,b,c";
    std::vector<std::string> res = CsvParser::parseLine(line);
    assert(res.size() == 3);
    assert(res[0] == "a");
}

void testMeanReducer()
{
    std::stringstream input("1 10.0\n1 20.0");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    std::stringstream output;
    std::streambuf* orig_out = std::cout.rdbuf(output.rdbuf());
    MeanReducer r;
    r.run();
    std::cin.rdbuf(orig);
    std::cout.rdbuf(orig_out);
    assert(output.str() == "Average: 15\n");
}

int main()
{
    testCsvParser();
    testMeanReducer();
    std::cout << "All tests passed" << std::endl;
    return 0;
}