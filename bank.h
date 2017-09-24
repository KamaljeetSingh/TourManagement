#include <bits/stdc++.h>
using namespace std;

#ifndef BANK_H
#define BANK_H

#include "date.h"


long int cardno[]={123456789,201111459,753951246,897231564,358961474,123477896,444555478};
int mon_card[]={1,2,3,4,5,6,7,8,9};
int year_card[]={2018,2020,2021,2022,2023,2025,2027,2030,2029};
int pin_card[]={2522,6366,1489,5698,7456,1159};
string bank[]={"HDFC","ICICI","PNB","YesBank","OBC","BankBaroda"};
float amount_c[]={25000.39,200000.15,654568.33,92000.25,680000.15,455668.47,78944.55,19000.66,10000.47,36988.12};

class payment_mode
{
    protected:
    string bank_name;
    float amount;

public:
    payment_mode(){}
    payment_mode(string name,float a)
    {
        bank_name=name;
        amount=a;
    }




};

class debit_card:public payment_mode
{

    long int cardno;
    int mon_exp;
    int year_exp;
    int pin;
public:
    debit_card(){}
    debit_card(long int card,int mon,int year,int p,string n,float a):payment_mode(n,a)
    {
        cardno=card;
        mon_exp=mon;
        year_exp=year;
        pin=p;
    }

    bool Check(long int card,int mon,int year,int p,string n,float tot)
    {
        if(card==cardno&&mon_exp==mon&&year_exp==year&&n==bank_name&&tot<=amount)
          {
              amount=amount-tot;
              return true;
          }
        else
            return false;

    }

    void show()
    {
        cout<<"bank name:"<<bank_name<<" "<<" "<<"amount:"<<amount<<" "<<"card no:"<<cardno<<" "<<"expiry month:"<<mon_exp<<" "<<"expiry year:"<<year_exp<<" "<<"pin:"<<pin<<endl;
    }

};


class net_bank:public payment_mode
{
    int userid,pass;
public:
    net_bank(){}
    net_bank(int id,int pass,string s,float a):payment_mode(s,a)
    {
        userid=id;
        this->pass=pass;
    }


    bool Check(int id,int p,string s,float tot)
    {
        if(userid==id&&pass==p&&s==bank_name&&tot<=amount)
            {
              amount=amount-tot;
              return true;
          }
        else
            return false;

    }
    void show()
    {

        cout<<"bank name:"<<bank_name<<" "<<"amonut:"<<amount<<" "<<" "<<"id:"<<userid<<" "<<"pasword:"<<pass<<endl;
    }


};

#endif // BANK_H
