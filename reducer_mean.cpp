#include <iostream>
#include <string>

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

int main(int argc, char** argv)
{
    MeanReducer reducer;
    reducer.run();
    return 0;
}