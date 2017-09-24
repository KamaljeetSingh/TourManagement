#include <bits/stdc++.h>
using namespace std;

#ifndef PLACE_H
#define PLACE_H

#include "transport.h"
#include "date.h"


class place
{
    string from;
    string to;
    flight *f,*f1;
    Bus *b,*b1;
    hotel *h[10];

public:
    place(string fr,string t,flight *f,flight *f1,Bus *b,Bus *b1)
        {
            from=fr;
            to=t;
            this->f=f;
           this->f1=f1;
           this->b=b;
           this->b1=b1;
        }
    bool checkplace(interface in)
    {
        if(in.from()==from && in.to()==to)
        {
           return true;
        }
        else
            return false;
    }


    string get_to() const
    {
           return to;
}
    void getdetails(interface in)
    {
        transport *t;
        int i;


            for (i=0;i<2;i++)
        {
            if(in.type()=='F'&&i==0)
                t=f;
                else if(in.type()=='F'&&i==1)
                    t=f1;
            else if(i==0)
                t=b;
                else
                    t=b1;

            if(t->checkdayavail(in.getd().dayofweek()) && t->checkseatavail(in))
                {t->showdetails();
                 cout<<"\n";
                 cout<<"\n";
                }
        }
        }
        float get_ff(int ch,interface in)
        {
            int i;
        flight* k[2]={f,f1};
        Bus* h[2]={b,b1};
        if(in.type()=='F')
        for(i=0;i<2;i++)
        {
            if(k[i]->getid()==ch)
          return(k[i]->getfare());

        }
        else if(in.type()=='B')
        for(i=0;i<2;i++)
        {
            if(h[i]->getid()==ch)
                return(h[i]->getfare());
        }
        }




        Ticket* book(interface ini)
        {
            Ticket *ti;
            float farem;
            int opt;
            flight *k[2]={f,f1};
             Bus *h[2]={b,b1};


                cout<<"enter your option sir"<<endl;
                cin>>opt;
            if(ini.type()=='F')
            {

                if(ini.planeclass()=='E')
                {
                    farem=k[opt-1]->getfare()*ini.ppl();
                    k[opt-1]->decseat(ini.getd().getdateno(),ini.ppl());
                }

                else if(ini.planeclass()=='B')
                {
                    farem=k[opt-1]->getothfare()*ini.ppl();
                    k[opt-1]->decseat(ini.getd().getdateno(),ini.ppl());
                }

        ti=new Air_ticket(ini.planeclass(),from,to,k[opt-1]->getid(),k[opt-1]->getorg(),k[opt-1]->gettime(),ini.getd().getdateno(),ini.getd().getmonth(),ini.getd().getyear(),farem,ini.ppl());
        k[opt-1]->addticket(ti);

            }
            else
            {


                farem=h[opt-1]->getfare()*ini.ppl();
                h[opt-1]->decseat(ini.getd().getdateno(),ini.ppl());
                ti=new Bus_ticket(from,to,h[opt-1]->getid(),h[opt-1]->getorg(),h[opt-1]->gettime(),ini.getd().getdateno(),ini.getd().getmonth(),ini.getd().getyear(),farem,ini.ppl());
                h[opt-1]->addticket(ti);

            }



            //ti->show_details();
            return ti;



        }
Ticket*Book_tour(interface ini,int opt)
{
    int i,m=0;
     Ticket *ti;
            float farem;

            flight *k[2]={f,f1};
             Bus *h[2]={b,b1};
             if(ini.type()=='F')
             {


            for(i=0;i<2;i++)
            {
                if(k[i]->getid()==opt)
                {


                 m++;
                 break;
                }
                else
                m++;
            }

                if(ini.planeclass()=='E')
                {
                    farem=k[m-1]->getfare()*ini.ppl();
                    k[m-1]->decseat(ini.getd().getdateno(),ini.ppl());
                }

                else if(ini.planeclass()=='B')
                {
                    farem=k[m-1]->getothfare()*ini.ppl();
                    k[m-1]->decseat(ini.getd().getdateno(),ini.ppl());
                }

        ti=new Air_ticket(ini.planeclass(),from,to,k[m-1]->getid(),k[m-1]->getorg(),k[m-1]->gettime(),ini.getd().getdateno(),ini.getd().getmonth(),ini.getd().getyear(),farem,ini.ppl());
        k[m-1]->addticket(ti);

             }
            else if(ini.type()=='B')
            {


            for(i=0;i<2;i++)
            {
                if(h[i]->getid()==opt)
                {


                 m++;
                 break;
                }
                else
                m++;
            }
            farem=h[m-1]->getfare()*ini.ppl();
                h[m-1]->decseat(ini.getd().getdateno(),ini.ppl());
                ti=new Bus_ticket(from,to,h[m-1]->getid(),h[m-1]->getorg(),h[m-1]->gettime(),ini.getd().getdateno(),ini.getd().getmonth(),ini.getd().getyear(),farem,ini.ppl());
                h[m-1]->addticket(ti);

            }


            ti->show_details();
            return ti;





}


};
#endif
