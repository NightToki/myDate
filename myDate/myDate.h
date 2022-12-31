#include <string>
#ifndef H_date
#define H_date 
using namespace std;

class myDate
{
private:
    int year, month, day;
    char character;
    string months[12]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    string days[7]{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
public:
    myDate();
    myDate(int M, int D, int Y); 
    void display() const; 
    void increaseDate(int N);
    void decreaseDate(int N); 
    int daysBetween(myDate D) const; 
    int getMonth() const; 
    int getDay() const; 
    int getYear() const; 
    int dayOfYear() const; 
    string dayName() const; 
    string monthName() const; 
    char getchar() const;
};

#endif