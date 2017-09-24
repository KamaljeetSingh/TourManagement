#include<bits/stdc++.h>
using namespace std;

#ifndef HOTEL_H
#define HOTEL_H

#include "date.h"


class h_voucher
{
char num[6];
int rooms_booked;
int persons;
float total_fare;
int check_in_day;
int check_in_month;
int days_of_stay;
int check_out_day;
int check_out_month;
public:
h_voucher(int rooms,float total,int checkday,int checkmonth,int chkout,int chkoutm,int p):rooms_booked(rooms),total_fare(total),check_in_day(checkday),check_in_month(checkmonth),persons(p)
    {
        for(int i=0;i<5;i++)
            num[i]=alphanum[rand() % (sizeof(alphanum) - 1)];
            num[5]='\0';
            check_out_day=chkout;
            check_out_month=chkoutm;
            if(check_out_month>check_in_month)
            days_of_stay=(arr[check_in_month-1]-check_in_day)+check_out_day;
            else
                days_of_stay=check_out_day-check_in_day;
                total_fare=total*(days_of_stay)*persons;

    }


    int get_checkout_day()
    {
        return check_out_day;
    }



    int get_noofrooms()
    {
        return rooms_booked;
    }

    int get_checkin_day()
    {
        return check_in_day;
    }

    int get_noofdays()
    {
        return days_of_stay;

    }
    int get_checkin_month()
    {
        return check_in_month;
    }

    int get_checkout_month()
    {
        return check_out_month;
    }

    float get_tot()
    {
        return total_fare;
    }
    void display();

};

void h_voucher::display()
{
    cout<<"\n\n";
    cout<<" voucher id: "<<num<<" "<<" rooms booked: "<<rooms_booked<<" "<<" total fare is: "<<total_fare<<" "<<" check in day: "<<check_in_day<<"-"<<check_in_month<<" "<<" check out day: "<<check_out_day<<"-"<<check_out_month<<" "<<" days of stay: "<<days_of_stay<<" "<<" persons: "<<persons;
}


class hotel
{
int id;
string h_name;
string h_place;
string h_state;
string specs;
int vac_room[32];
float fare_per_day;
vector<h_voucher*> v;

public:
    hotel()
    {

    }
hotel(int idea,string name,string place,string state,int fare,int room):id(idea),h_name(name),h_place(place),h_state(state),fare_per_day(fare)
{
    for(int i=0;i<32;i++)
        vac_room[i]=room;
}

void add_specs(string specifications)
{
   specs=specifications;
}

void add_voucher(h_voucher *v1)
{
int i,j;

if(v1->get_checkin_month()<v1->get_checkout_month())
{
for(i=v1->get_checkin_day();i<=arr[v1->get_checkin_month()];i++)
vac_room[i]=vac_room[i]-(v1->get_noofrooms());
for(i=1;i<=v1->get_checkout_day();i++)
vac_room[i]=vac_room[i]-(v1->get_noofrooms());
}

else
{
for(i=v1->get_checkin_day();i<=v1->get_checkout_day();i++)
{
 vac_room[i]=vac_room[i]-(v1->get_noofrooms());
}
}

v.push_back(v1);
}

void update_rooms()
{
    int j;
   time_t t = time(0);   // get time now
    struct tm * now = localtime(&t);
    int day=now->tm_mday;

    for(int i=0;i<v.size();i++)
    {
            if(v[i]->get_checkout_day()<=day&&v[i]->get_checkin_month()==v[i]->get_checkout_month())
        {j=v[i]->get_checkin_day();
        for(;j<=v[i]->get_checkout_day();j++)
        vac_room[j]=vac_room[j]+v[i]->get_noofrooms();
    }

    else
        if(v[i]->get_checkout_day()<day&&v[i]->get_checkin_month()!=v[i]->get_checkout_month())
    {j=v[i]->get_checkin_day();
    for(;j<=arr[v[i]->get_checkout_month()];j++)
        vac_room[j]=vac_room[j]+v[i]->get_noofrooms();
    j=v[i]->get_checkout_day();
    for(int f=1;f<=j;f++)
         vac_room[f]=vac_room[f]+v[i]->get_noofrooms();
    }
}
}

float getfare()
{
    return fare_per_day;
}

int getvoucher()
{
    return (v.size());
}

bool check_room(int chk_day,int chk_out,int m1,int m2,int room)
{
    if(m1==m2)
    {for(;chk_day<=chk_out;chk_day++)
        if(vac_room[chk_day]<room)

        {
            return false;
    }
    }
    else
    {for(;chk_day<=arr[m1];chk_day++)
    if(vac_room[chk_day]<room)
        {
            return false;
    }
    for(int i=1;i<=chk_out;i++)
        if(vac_room[chk_day]<room)
        {
            return false;
    }
    }
        return true;
}

void display(Date d1,Date d2)
{

    cout<<"hotel id:"<<id<<" "<<"hotel name:"<<h_name<<" "<<"place:"<<h_place<<" "<<"fare(per day):"<<fare_per_day<<" Vacant-rooms from "<<d1<<" to "<<d2<<"\t";
    if(d1.getmonth()!=d2.getmonth())
    {
    for(int i=d1.getdateno();i<=arr[d1.getmonth()-1];i++)
        cout<<vac_room[i]<<" ";

    for(int i=1;i<d2.getdateno();i++)
        cout<<vac_room[i]<<" ";
    }
    else
        for(int i=d1.getdateno();i<d2.getdateno();i++)
        cout<<vac_room[i]<<" ";
        cout<<endl;
}

void vouchers_info()
{
    for(int i=0;i<v.size();i++)
       v[i]->display();
}
string get_h_place() const
{
       return h_place;
}

void display_only()
{
     cout<<"id:"<<id<<" "<<"hotel name:"<<h_name<<" "<<" place:"<<h_place<<" "<<"fare(per day):"<<fare_per_day<<" ";
}
int get_id()
{
    return id;
}


};

#endif
