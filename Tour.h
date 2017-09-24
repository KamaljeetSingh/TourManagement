#include<bits/stdc++.h>
using namespace std;

#ifndef TOUR_H
#define TOUR_H

#include "date.h"
#include "Place.h"
#include "Interface.h"




class Tour_package
{
      string t_place;
      string desc;
      float tot_fare;
      vector<place*> pp;
      vector<hotel*> hh;
      public:
Tour_package(string a,string d,int  tf)
{

t_place=a;
desc=d;
tot_fare=tf;
}
string get_place() const
{
     return t_place;
}
string get_desc() const
{
return desc;
}
float get_fare() const
{
     return tot_fare;
}
void set_place(place*pp1)
{
     pp.push_back(pp1);
}
void set_hotel(hotel*hh1)
{
     hh.push_back(hh1);
}
void show_tour_det(interface inn)
{
     cout<<t_place<<" "<<desc<<" "<<tot_fare<<endl;
     for(int j=0;j<pp.size();j++)
     pp[j]->getdetails(inn);
     for(int j=0;j<hh.size();j++)
     hh[j]->display_only();

}

};

#endif
