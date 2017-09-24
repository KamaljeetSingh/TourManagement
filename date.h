#include<bits/stdc++.h>
using namespace std;

#ifndef DATE_H
#define DATE_H

const char alphanum[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
const int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
    int dateno,month,year;
public:
    friend istream &operator>>(istream &,Date &);
    friend ostream &operator<<(ostream&,Date &);
    Date(){}
    Date(int m,int y)
    {
        month=m;
        year=y;
    }

    int getdateno()
    {
        return dateno;
    }
    int getmonth()
    {
        return month;
    }
    int getyear()
    {
        return year;
    }


    bool checkdate()
    {
        time_t t = time(0);   // get time now
    struct tm * now = localtime(&t);
    int day=now->tm_mday;
    int m=now->tm_mon+1;
    if(dateno<day && month==m)
    {
        return false;
    }
  if(dateno>arr[month-1])
   {
       return false;
   }

   if(month>12|| month<m)
   {
       return false;
   }

   if(year!=2015)
   {
       return false;
   }
   return true;
    }


int dayofweek()
{
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
year -= month < 3;
return ( year + year/4 - year/100 + year/400 + t[month-1] + dateno) % 7;
}

};

istream &operator>>(istream &i,Date &d)
{

   i>>setw(2)>>d.dateno;
   i.ignore(1);
   i>>setw(2)>>d.month;

   i.ignore(1);
   i>>setw(4)>>d.year;
   return i;
}

ostream &operator<<(ostream &o,Date &d)
{
    o<<d.dateno<<"-"<<d.month<<"-"<<d.year;
}
#endif
