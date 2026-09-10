#include <iostream>
#include <string>

class VarianceReducer
{
public:
    void run()
    {
        std::string key;
        double price;

        while (std::cin >> key >> price)
        {
            m_sum += price;
            m_sumSq += (price * price);
            m_count += 1;
        }

        if (m_count > 0)
        {
            double mean = m_sum / m_count;
            double meanSq = m_sumSq / m_count;
            double variance = meanSq - (mean * mean);

            std::cout << "Variance: " << variance << std::endl;
        }
    }

private:
    double m_sum = 0.0;
    double m_sumSq = 0.0;
    size_t m_count = 0;
};

int main(int argc, char** argv)
{
    VarianceReducer reducer;
    reducer.run();
    return 0;
}