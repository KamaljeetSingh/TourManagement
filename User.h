#include <bits/stdc++.h>
using namespace std;

#ifndef USER_H
#define USER_H

string iid[]={"125","456","789","741"};

class User
{
      string name;
      int age;
      string email;
      string mob_no;
      string add;
      debit_card *D;
      net_bank *N;
      public:
          User()
          {

          }
             User(string a,int b,string e,string m,string ad)
             {
                         name=a;
                         age=b;
                            email=e;
                         mob_no=m;
                         add=ad;
        D=(new debit_card(cardno[rand()%5],mon_card[rand()%11],year_card[rand()%8],pin_card[rand()%5],bank[rand()%5],amount_c[rand()%9]));
        N=(new net_bank(cardno[rand()%5],pin_card[rand()%5],bank[rand()%5],amount_c[rand()%9]));
               }
               string get_name() const
               {
                      return(name);
                }


	string get_email() const
       {
         return(email);
       }
       string get_add() const
       {
              return(add);
        }

	int get_age() const
         {
             return(age);
         }
       string get_mob_no() const
       {
           return(mob_no);
        }
        virtual void show_user_det()
        {
             cout<<"name:"<<name<<endl<<"age:"<<age<<endl<<"e-mail:"<<email<<endl<<"mobile no:"<<mob_no<<endl<<"addresss:"<<add;
        }

        void show_bank()
        {
            cout<<"\n";
            cout<<"Debit-Card Details-";D->show();
            cout<<"\n";
            cout<<"Net-Bank Details-";N->show();
        }

        bool check_card(string name,long int card,int mon,int year,int pin,float tot)
{

    return D->Check(card,mon,year,pin,name,tot);
}

bool check_nbank(string name,int id,int p,float tot)
{
    return N->Check(id,p,name,tot);
}

        };


 class Happy_user:public User
   {
  string uid;
vector<Ticket*> t1;
int tour_ind[5][2];
//vector<tour*>  to;
float tot;
vector<h_voucher*> h_vo;
  public:
      Happy_user()
      {

      }
    Happy_user(string a,int b,string e,string m,string ad): User(a,b,e,m,ad)
{tot=0.0;
 uid=iid[rand()%4];
}
    void set_ticket_air(Ticket*t)
    {
         t1.push_back(t);

     }

    string get_id()
    {
        return uid;
    }




 void set_voucher(h_voucher*v1)
     {
          h_vo.push_back(v1);
      }


float get_tot_fare(int choice)
{

    if(choice==1||choice==2)
        {tot=tot+t1[t1.size()-1]->get_fare();
            return t1[t1.size()-1]->get_fare();
        }
    if(choice==3)
      {  tot=tot+h_vo[h_vo.size()-1]->get_tot();
        return h_vo[h_vo.size()-1]->get_tot();
      }
    if(choice==4)
    return (h_vo[h_vo.size()-1]->get_tot()+t1[t1.size()-1]->get_fare()+(0.15*h_vo[h_vo.size()-1]->get_tot()+t1[t1.size()-1]->get_fare()));
}

void set_tour()
{
    static int c=0;
    int i=h_vo.size()-1;
    int j=t1.size()-1;
    tour_ind[c][0]=i;
    tour_ind[c][1]=j;
    c++;
}

void show_user_det()
{
cout<<"\n"<<"id:"<<uid<<endl;
User::show_user_det();
for(int i=0;i<t1.size();i++)
t1[i]->show_details();
for(int i=0;i<h_vo.size();i++)
h_vo[i]->display();


}

void show_user_bank()
{
    User::show_bank();
}

float getuser_tot()
{
    return tot;
}

int get_count()
{
    return (t1.size()+h_vo.size());
}



};

#endif
