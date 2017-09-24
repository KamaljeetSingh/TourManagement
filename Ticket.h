#include <bits/stdc++.h>
using namespace std;

#ifndef TICKET_H
#define TICKET_H

string ticketidalphanum[]={"1253","4568","7819","1741"};
class Ticket
{
    protected:
   string tid;
   string source_name;
   string dest_name;
   int fbid;//flight or bus id
   string fborg;//flight or bus organisation
   string tim;
   float fare;
   int ddday;
   int mmon;
   int year;
   int ppl;

    public:
      Ticket(string sn,string dn,int fbidd,string fbor,string timet, int dd,int mm,int yy,float faret, int pply)
      {
         tid=ticketidalphanum[rand()%3];

          source_name=sn;
          dest_name=dn;
          fbid=fbidd;
          fborg=fbor;
          tim=timet;
          fare=faret;
          ddday=dd;
          mmon=mm;
          year=yy;
          ppl=pply;
       }
       string get_tid() const
       {
           return tid;
       }

string get_tim() const
{
    return tim;
}

string get_source_name() const
{
       return source_name;
  }
  int get_day() const
  {
      return ddday;
}
int get_month() const
{
    return mmon;
}
int get_year() const
{
    return year;
}
virtual void show_details()
{

}
float get_fare()

{
    return fare;
}


};
class Air_ticket:public Ticket
{
      char class_type;
      public:
        Air_ticket(char type,string sn, string dn,int fbid,string org,string timet, int dd,int mm,int yy,float faret,int pply):Ticket(sn, dn, fbid,org,timet, dd, mm, yy,faret,pply)
        {
                          class_type=type;
        }
        char get_type() const
        {
               return class_type;
        }
        virtual void show_details()
        {
            cout<<"\n\n";
             cout<<" id "<<tid<<" has been generated of flight "<<fbid<<" "<<fborg<<" from "<<source_name<<" to "<<dest_name<<" on "<<ddday<<"-"<<mmon<<"-"<<year<<"-"<<tim<<" for fare "<<fare<<" class "<<class_type<<endl;
         }
};


class Bus_ticket:public Ticket
{
      public:
       Bus_ticket(string sn, string dn,int fbid,string org,string timet, int dd,int mm,int yy,float faret,int pply):Ticket(sn, dn, fbid,org,timet, dd, mm, yy,faret,pply)
  {
     }
    virtual void show_details()
     {
         cout<<"\n\n";
          cout<<" id "<<tid<<" has been generated of bus "<<fbid<<"\t"<<fborg<<" from "<<source_name<<" to "<<dest_name<<" on "<<ddday<<"-"<<mmon<<"-"<<year<<"\t"<<tim<<"for fare"<<fare<<endl;
       }
};
#endif
