#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

int main(int argc, char** argv)
{
    std::string line;
    bool isHeader = true;

    while (std::getline(std::cin, line))
    {
        if (isHeader)
        {
            isHeader = false;
            continue;
        }

        std::vector<std::string> fields = CsvParser::parseLine(line);
        if (fields.size() > 9)
        {
            try
            {
                double price = std::stod(fields[9]);
                std::cout << "1" << "\t" << price << std::endl;
            }
            catch (...)
            {
             
            }
        }
    }

    return 0;
}