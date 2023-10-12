#include <iostream>
#include <iomanip>
#include <cmath>
// π/4 = Σ((-1)^(n+1) / (2n-1))
// π over 4 = sum from {n=1} to ∞ {(-1)^(n+1)/(2n-1)}
// That is the formula we are using

#define PI 3.14159

double calculated = 0;

int main(int argc, char *argv[])
{
    std::cout << "doing ∞ iterations" << std::endl;

    unsigned int i = 0;
    for (;;)
    {
        ++i;
        calculated += pow(-1, i + 1) / ((2 * i) - 1);
        if (i % 100 == 0)
        {

            std::cout << "Current iteration: " << i << " Current Approximation: " << std::setprecision(ceil(i / 1000000) + 15) << calculated * 4 << "\r";
        }
    }

    std::cout << std::endl
              << "Our approximation: " << calculated * 4 << std::endl
              << "Actual pi: " << PI << std::endl;
    return 0;
}