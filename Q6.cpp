/* Create a class by name date with the member data day, month and year. Perform the following:
• Overload all relational operators <, <=, >, >=, ==, !=
• Overload ++ operator to increment a date by one day
• Overload + to add given number of days to find the next date
• Provide the necessary function to use the statement like days=dt; where days is an int 
variable and dt is an object of date class. The statement is intended to assign the number of days 
elapsed in the current year of the date to the variable days. Note that this is a case of conversion 
from derived type to basic type.*\
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
public:
    // Constructor
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    // Overload relational operators
    bool operator<(const Date &other) const
    {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    bool operator<=(const Date &other) const
    {
        return (*this < other) || (*this == other);
    }

    bool operator>(const Date &other) const
    {
        return !(*this <= other);
    }

    bool operator>=(const Date &other) const
    {
        return !(*this < other);
    }

    bool operator==(const Date &other) const
    {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date &other) const
    {
        return !(*this == other);
    }

// Overload ++ operator to increment the date by one day
    Date &operator++()
    {
        day++;
        if (day > daysInMonth(month, year))
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return *this;
    }

// Overload + operator to add a given number of days
    Date operator+(int days) const
    {
        Date newDate = *this;
        while (days > 0)
        {
            newDate.day++;
            if (newDate.day > newDate.daysInMonth(newDate.month, newDate.year))
            {
                newDate.day = 1;
                newDate.month++;
                if (newDate.month > 12)
                {
                    newDate.month = 1;
                    newDate.year++;
                }
            }
            days--;
        }
        return newDate;
    }

    // Conversion to int to get the number of days elapsed in the current year
    operator int() const
    {
        int daysElapsed = day;
        for (int i = 1; i < month; ++i)
        {
            daysElapsed += daysInMonth(i, year);
        }
        return daysElapsed;
    }

    // Display function
    void display() const
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main()
{
    Date dt(25, 8, 2024);
    Date dt2(1, 1, 2025);

    cout << "Date 1: ";
    dt.display();
    cout << "Date 2: ";
    dt2.display();

    // Relational operator testing
    cout << "dt < dt2: " << (dt < dt2) << endl;
    cout << "dt > dt2: " << (dt > dt2) << endl;
    cout << "dt == dt2: " << (dt == dt2) << endl;

    // Increment the date by one day
    ++dt;
    cout << "Date after increment: ";
    dt.display();

    // Add 10 days to the date
    Date dt3 = dt + 10;
    cout << "Date after adding 10 days: ";
    dt3.display();

    // Convert date to int to get the days elapsed in the year
    int days = dt;
    cout << "Days elapsed in the year: " << days << endl;

    return 0;
}
//main function
