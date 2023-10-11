#include <iostream>
#include <cmath>
// π/4 = Σ((-1)^(n+1) / (2n-1))
// π over 4 = sum from {n=1} to ∞ {(-1)^(n+1)/(2n-1)}
// That is the formula we are using

#define PI 3.14159

float calculated = pow(-1, 1 + 1) / (2 * 1 - 1);

int main(int argc, char *argv[])
{
    std::cout << calculated << std::endl;
    return 0;
}