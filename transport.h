#include <bits/stdc++.h>
using namespace std;

#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Ticket.h"
#include "interface.h"

class interface;

class transport
{

protected:
    int id;
    string org;
    int totalseat;
    int availseat[31];
    float fare;
    float duration;
    int freq[7];
    string tim;
    int tickcount;
    Ticket *ti[20];

public:
    transport()
    {
    }
    transport(int idt,string orgt, int totalseatt,int availseatt[31],float faret, float durationt,int freqt[7],string timet)
    {
        int i;
        id=idt;
        org=orgt;
        tim=timet;
        totalseat=totalseatt;
        fare=faret;
        duration=durationt;

        tickcount=0;
        for(i=0;i<7;i++)
        {
            freq[i]=freqt[i];
        }
        for(i=0;i<31;i++)
        {
            availseat[i]=availseatt[i];
        }
        for(i=0;i<20;i++)
        {
            ti[i]=NULL;
        }




    }
    void addticket(Ticket *t)
    {
        tickcount++;
        ti[tickcount]=t;
        //ti[tickcount]->show_details();
    }
    void decseat(int dateno,int ppl)
    {
        availseat[dateno]=availseat[dateno]-ppl;
    }
    virtual void showdetails()
    {
        cout<<"\n";
        cout<<"id: "<<id<<endl<<"name: "<<org<<endl<<"travel duration: "<<duration<<" hours "<<endl<<"General fare:  "<<fare<<endl<<"at: "<<tim<<endl;
    }
    float getfare()
    {
        return fare;
    }
    float getduration()
    {
        return duration;
    }
    int getid()
    {
        return id;
    }
    string getorg()
    {
        return org;
    }
    string gettime()
    {
        return tim;
    }

    virtual bool checkdayavail(int k)//(sun,mo,tue,wed...)
    {
        if (freq[k])
            return true;
        else
            return false;
    }
    virtual bool checkseatavail(interface in)
    {
        if (availseat[(in.getd().getdateno())-1]>=in.ppl())
            return true;
        else
            return true;
    }


};
class flight :public transport
{
protected:
    float othfare;

public:
    flight():transport()
    {
    }

    flight(int idf1,string orgf1, int totalseatf1,int availseatf1[31],float faref1, float othfaref1, float durationf1,int freqf1[7],string timef1)
    :transport(idf1,orgf1,totalseatf1,availseatf1,faref1,durationf1,freqf1,timef1)
    {
        othfare=othfaref1;
    }
    float getothfare()
    {
        return othfare;
    }
    void showdetails()
    {

    transport::showdetails();
    cout<<"buiseness fare:"<<othfare;
    }
    float get_t_fare()
    {
        return(transport::getfare());
    }
};

class Bus: public transport
{
public:
    Bus():transport()
    {
    }

    Bus(int idb1,string orgb1, int totalseatb1,int availseatb1[31],float fareb1, float durationb1,int freqb1[7],string timeb1)
    :transport(idb1,orgb1,totalseatb1,availseatb1,fareb1,durationb1,freqb1,timeb1)
    {

    }

};
#endif
