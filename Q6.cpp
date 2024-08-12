#include <iostream>

using namespace std;

class Date
{
private:
    int day, month, year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Helper function to get the number of days in a month
    int daysInMonth(int m, int y) const
    {
        switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 0;
        }
    }
