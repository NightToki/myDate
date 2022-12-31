#include "myDate.h"
#include <iostream>


/*TO DO LIST
* Gold gave us a main so match up the functions from here to the main 
* 
*/





int Greg2Julian(int month, int day, int year) // calculations @.@
{
    int jul = day - 32075 + 1461 *
        (year + 4800 + (month - 14) / 12) / 4 + 367 *
        (month - 2 - (month - 14) / 12 * 12) /
        12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
    return jul;
}

void Julian2Greg(int JD, int& month, int& day, int& year)// calculations @.@
{
    int L, N, I, J, K;
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;

    year = I;
    month = J;
    day = K;
}
bool isLeapYear(int year) // figured this out in the lab
{
    if (Greg2Julian(year, 3, 1) - Greg2Julian(year, 2, 28) == 2)
    {
        return true;
    }
    return false;
}
myDate::myDate() // the default that gold told us to do 
{
    year = 1959;
    month = 5;
    day = 11;

}

myDate::myDate(int M, int D, int Y)  // separate the months that have 31 days from 30 days
//find out if a day in febuary is a leap year or not
// put default if given invalid dates
{
    switch (M)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (D > 31 || D < 1)
        {
            month = 5; day = 11; year = 1959;
        }
        else
        {
            month = M; day = D; year = Y;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (D > 30 || D < 1)
        {
            month = 5; day = 11; year = 1959;
        }
        else
        {
            month = M; day = D; year = Y;
        }
        break;
    case 2:
        if (isLeapYear(Y))
        {
            if (D > 29 || D < 1)
            {
                month = 5; day = 11; year = 1959;
            }
            else
            {
                month = M; day = D; year = Y;
            }
            break;
        }
        else if (D > 28 || D < 1)
        {
            month = 5; day = 11; year = 1959;
        }
        else
        {
            month = M; day = D; year = Y;
        }
        break;
    default: month = 5; day = 11; year = 1959;
    }

}

void myDate::display() const// create a display 
{
    cout << day << " " << getMonth() << ", " << year;
}

void myDate::increaseDate(int N)  //pass the number of days to julian and then convert it back
{
    int add = Greg2Julian(this->month, this->day, this->year);
    add += N;
    Julian2Greg(add, this->month, this->day, this->year);
}

void myDate::decreaseDate(int N)//pass the number of days to julian and then convert it back
{
    int sub = Greg2Julian(this->month, this->day, this->year);
    sub -= N;
    Julian2Greg(sub, this->month, this->day, this->year);
}

int myDate::daysBetween(myDate D) const//subtract the julian days 
{
    return Greg2Julian(D.month, D.day, D.year) - Greg2Julian(this->month, this->day, this->year); 
}

int myDate::getMonth() const
{
	return month;
}

int myDate::getDay() const
{
	return day;
}

int myDate::getYear() const
{
	return year;
}

int myDate::dayOfYear() const // we only need to find out which day it is 
{
    int dayOfYear = Greg2Julian(1, 1, this->year);
    int thisDate = Greg2Julian(this->month, this->day, this->year);
    return thisDate - dayOfYear + 1;
}

string myDate::dayName() const
{
    int jul = Greg2Julian(this->month, this->day, this->year);
    string dayOfWeek = days[jul % 7];
    return dayOfWeek;
}

string myDate::monthName() const
{
    return months[month - 1];
}

char myDate::getchar() const
{
    return character;
}


