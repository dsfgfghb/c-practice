#include <iostream>
#include "math.cpp"
using namespace std;
class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)          
    {
        if (numerator == 0)denominator = 1;
        else {
            int d = gac(abs(numerator), abs(denominator));          //分子分母同时除以他们的最大公约数即最简的分数
            numerator /= d;
            denominator /= d;
        };
    };
};

int main()
{
    return 0;
}