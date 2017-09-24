#include <bits/stdc++.h>
using namespace std;

#ifndef INTERFACE_H
#define INTERFACE_H

#include "date.h"

class interface
{
string fromy;
string toy;
Date d;
Date d1;
Date d2;
int pply;
int pply2;
char typey;
char planeclassy;

public:
void viewflight_bus(int);
void hotel();
void tour_flight_hotel(int);
void view_tour();
void feedback();
static int count_user;

string from()
{
    return fromy;

}
string to()
{
    return toy;

}
Date getd()
{
    return d;
}
Date getd1()
{
return d1;
}
Date getd2()
{
return d2;
}
int ppl()
{
    return pply;
}

int ppl_hot()
{
    return pply2;
}
char type()
{
    return typey;
}

char planeclass()
{
    return planeclassy;
}

Date get_chkin()
{
    return d1;
}
Date get_chkout()
{
    return d2;
}
int get_users() const
{
    return count_user;
}

void increment_count()
{
    count_user++;
}


};

int interface::count_user=0;
#endif
