#include <iostream>
using namespace std;

class date{
private:
    int day, month, year;

public:
    date(){
        this->day = this->month = 1;
        this->year = 1970;
    }

    date(int D, int M, int Y){
        this->day = D;
        this->month = M;
        this->year = Y;
    }

    void printDate(){
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }

    // Overloaded Operators
    //  diff = d2 - d3;
    int operator-(const date& Date){
        return ((this->year) - (Date.year));
    }

    //  d1 = d2
    void operator=(const date& Date){
        this->day = Date.day;
        this->month = Date.month;
        this->year = Date.year;
    }

    //  d1 = d2 + 10;
    date operator+(int days){
        date Result;
        Result.month = this->month;
        Result.year = this->year;
        if((this->day + days) > 30){
            Result.day =  days - (30 - (this->day));
            Result.month++;
        }else{
            Result.day = this->day + days;
        }
        if(month > 12){
            this->year++;
            this->day = 1;
            this->month = 1;
        }
        return Result;
    }

    date operator++(){
        (this->day)++;
        if((this->day) > 30){
            this->month++;
            this->day = 1;
        }
        if((this->month) > 12){
            this->year++;
            this->month = this->day = 1;
        }
        return *this;
    }

        date operator++(int){
        date Result = *this;
        (this->day)++;
        if((this->day) > 30){
            this->month++;
            this->day = 1;
        }
        if((this->month) > 12){
            this->year++;
            this->month = this->day = 1;
        }
        return Result;
    }

    bool operator==(const date& Date){
        return ((this->day == Date.day) && (this->month == Date.month) && (this->year == Date.year));
    }

    operator int(){
        return this->day;
    }

    int operator[] (char ch){
        switch(ch){
        case 'd':
            return this->day;
            break;

        case 'm':
            return this->month;
            break;

        case 'y':
            return this->year;
            break;

        default:
            return -1;
        }
    }
};

int main()
{
   date d1(2, 10, 2010), d2(26, 9, 2002);
   // ********** diff = d2 - d3 ***************
   int diff = (d1 - d2);
   cout << "Difference in Years = " << diff << endl;

    // ********** d1 = d2 + 10 ***************
    d1 = d2 + 10;
    d1.printDate();

    // ********** d1 = ++d2 ***************
    d1 = ++d2;
    d1.printDate();

    // ********** d1 = d2++ ***************
    d1 = d2++;
    d1.printDate();
    d2.printDate();

//     ********** d1 = d2 ***************
    d1 = d2;
    d1.printDate();

//     ********** d1 == d2 ***************
    (d1 == d2)? cout << "True" : cout << "False";

//     ********** Casting Operator ***************
    int x = (int)d1;
    cout << x;

//     ********** Operator [] ***************
    int day=d1['d'];
    int month=d1['m'];
    int year=d1['y'];
    cout << day << "/"<< month << "/" << year << endl;
    return 0;
}
