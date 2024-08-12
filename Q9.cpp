#include <iostream>

using namespace std;

int LargestNumber(int a, int b, int c)
{
    int max = a;
    if (max < b && max > c)
    {
        max = b;
    }
else if (max < c)
    {
        max = c;
    }
return max;
}

int main()
{
    int x, y, z;


