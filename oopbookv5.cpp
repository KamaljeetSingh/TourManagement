#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

#include "date.h"
#include "bank.h"
#include "Hotel.h"
#include "Ticket.h"
#include "User.h"
#include "Place.h"
#include "transport.h"
#include "Tour.h"


template<class T>
void quicksort(T obj[],int first,int last){
    int pivot,j,i;
    T temp;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(obj[i].getfare()<=obj[pivot].getfare()&&i<last)
                 i++;
             while(obj[j].getfare()>obj[pivot].getfare())
                 j--;
             if(i<j){
                 temp=obj[i];
                  obj[i]=obj[j];
                  obj[j]=temp;
             }
         }

         temp=obj[pivot];
         obj[pivot]=obj[j];
         obj[j]=temp;
         quicksort(obj,first,j-1);
         quicksort(obj,j+1,last);

    }
}





void interface::viewflight_bus(int choice)
{
    cout<<"\n"<<"From:";
    cin>>fromy;
    cout<<endl;
    cout<<"To:";
    cin>>toy;
    cout<<endl;
    cout<<"No of persons:";
    cin>>pply;
    Y:
    try
        {
     cout<<"\n";
    cout<<"Enter Date in the format(dd-mm-yyy):";
    cin>>d;
        if(!d.checkdate())
        throw "Wrong date Entered. Please Enter Again.\n";
        }catch (const char* excp){
        cerr<<excp;
        goto Y;
        }

    if(choice==1)
    {
        typey='F';
        cout<<"\n";
        cout<<"Enter Seat Class(E/B):";
        cin>>planeclassy;
    }
    else
        typey='B';
    cout<<endl;


}



void interface::hotel()
{
cout<<"\n"<<"Place:";
cin>>toy;
cout<<"\n"<<"No of persons:";
cin>>pply2;
Y:
try
{

cout<<"\n"<<"sir your check in date:";
cin>>d1;

if(!d1.checkdate())
throw "Wrong date Entered. Please Enter Again.\n";

}catch (const char* excp){
cerr<<excp;
goto Y;
}
X:
try
{

cout<<"\n"<<"sir your check out date:";
cin>>d2;

if(!d2.checkdate()||(d2.getdateno()<d1.getdateno()&&d2.getmonth()==d1.getmonth()))
throw "Wrong date Entered. Please Enter Again. \n";

}catch (const char* excp){
cerr<<excp;
goto X;
}
}


void interface::tour_flight_hotel(int c)
{
cout<<"\n"<<"From:";
cin>>fromy;
cout<<"\n"<<"To:";
cin>>toy;
if(c==1)
{
cout<<"\n"<<"No.of persons to board flight:";
cin>>pply;
pply2=pply;
typey='F';
cout<<"\n"<<"Seat Class(E/B)";
cin>>planeclassy;
}
else
{
cout<<"\n"<<"No.of persons to board bus:";
cin>>pply;
pply2=pply;
typey='B';
}
Y:
    try
        {
    cout<<"\n"<<"Enter Date in the format(dd-mm-yyy):";
    cin>>d;
        if(!d.checkdate())
        throw "Wrong date Entered. Please Enter Again.\n";
        }catch (const char* excp){
        cerr<<excp;
        goto Y;
        }
d1=d;
X:
try
{

cout<<"\n"<<"Check out date for Hotel:";
cin>>d2;

if(!d2.checkdate()||(d2.getdateno()<d1.getdateno()&&d2.getmonth()==d1.getmonth()))
throw "Wrong date Entered. Please Enter Again. \n";

}catch (const char* excp){
cerr<<excp;
goto X;
}

}



Happy_user call_me(interface ini,Happy_user h_user[])
{
    char c;
    int ss;
    string enter_id;


                Again:
                cout<<"1.Registered User\n2.New User\n";
                cin>>ss;
                if(ss==1)
                {
                    cout<<"Enter Your Id-- ";
                   cin>>enter_id;
                    for(int i=0;i<ini.get_users();i++)
                    {

                    if(enter_id==h_user[i].get_id())
                    {
                        cout<<"Ok!You Can Proceed  ";
                        return h_user[i];
                    }
                    }
                    cout<<"You Are Misbehaving";
                    goto Again;
                }
                else if(ss==2)
                {
                    string name,email,mob,add;
                    int age;
                    cout<<"Name  Email  Mobile  Address  Age- \n";
                    cin>>name;
                    getchar();
                    cin>>email;
                    getchar();
                    cin>>mob;
                    getchar();
                    cin>>add;
                    getchar();
                    cin>>age;

                    Happy_user H(name,age,email,mob,add);
                    ini.increment_count();
                    return H;
                }





}




int main()
{
    interface ini;
int i,ch;
char ans;
int cho;
int cho1;
//DATABASE
    int freqf1[7]={1,0,1,1,1,0,1};
    int freqf2[7]={0,1,0,1,1,1,0};
    int freqb1[7]={1,0,1,1,1,0,1};
    int freqb2[7]={0,1,0,1,1,1,0};
    int availseatf1[31]={120};
    int availseatf2[31]={120};
    int availseatb1[31]={56};
    int availseatb2[31]={60};
    int freqp2f1[7]={1,0,1,1,1,0,1};
    int freqp2f2[7]={0,1,0,1,1,1,0};
    int freqp2b1[7]={1,0,1,1,1,0,1};
    int freqp2b2[7]={0,1,0,1,1,1,0};
    int availseatp2f1[31]={235};
    int availseatp2f2[31]={235};
    int availseatp2b1[31]={45};
    int availseatp2b2[31]={50};
    flight f(451,"Air india",120,availseatf1,3946,5000,2.35,freqf1,"23:10");
    flight f1(720,"Jet Airways",120,availseatf2,3600,4500,2.15,freqf2,"12:50");
    flight f2(678,"Spice Jet",235,availseatp2f1,1965,2500,1.3,freqp2f1,"20:40");
    flight f3(459,"Kingfisher",235,availseatp2f2,1670,2300,1.2,freqp2f2,"12:50");
    Bus b(12,"GSRTC",56,availseatb1,2000,12,freqb1,"04:30");
    Bus b1(15,"Pappu travels",60,availseatb2,1500,13,freqb2,"15:30");
    Bus b2(17,"PSRTC",45,availseatp2b1,450,6,freqp2b1,"09:20");
    Bus b3(18,"punjab roadways",50,availseatp2b2,500,6.5,freqp2b2,"08:40");
    place p[2]={place("delhi","goa",&f,&f1,&b,&b1),
                place("delhi","Chandigarh",&f2,&f3,&b2,&b3)};
    Tour_package t[2]={Tour_package("goa","Marina-Beach--Temple visit--Forts&Historic monuments",15000),Tour_package("Chandigarh","rock garden--zoo--mughal gardens",7000)};

hotel h[3]={hotel(121,"Ashoka","goa","goa",900,10),hotel(131,"Taj","Chandigarh","Punjab",1200,7),hotel(141,"Shangri La","goa","goa",850,8)};
vector<string> feed;
bool flag;
string feed_back;
Happy_user h_user[10]={Happy_user("ABC",15,"XYZ@hotmail.com","9555137225","lajpat nagar "),Happy_user("DEF",25,"ABC@gmail.com","9010667859","lal quarter ")};
int book,c,ss,choice,rooms;
string enter_id;
Happy_user Hi;
Ticket *Ti;

ini.increment_count();
ini.increment_count();

flight f_goa[2]={f,f1};
flight f_Chandigarh[2]={f2,f3};
Bus b_goa[2]={b,b1};
Bus b_Chandigarh[2]={b2,b3};
hotel h_goa[2]={h[0],h[2]};

cout<<f_goa[0].getfare()<<" "<<f_goa[1].getfare()<<endl;

quicksort(f_goa,0,1);
for(i=0;i<2;i++)
    cout<<f_goa[i].getfare()<<" ";
cout<<endl;
quicksort(h_goa,0,2);
quicksort(b_Chandigarh,0,2);




/*
cout<<ini.get_users();
for(i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{
if(h[j].get_h_place()==t[i].get_place())
t[i].set_hotel(&h[j]);
}
}

for(i=0;i<2;i++)
{
    h_user[i].show_user_det();
}*/
repeat:
flag=0;
   system("cls");
   cout<<"***** welcome to LEISURE TOURS & TRAVELS....your true travel companion *****"<<endl<<endl;
cout<<"Hey User,What Do You Want ??\n1.Book Flight\n2.Book Bus\n3.Book Hotel\n4.Book Tour\n5.Give Suggestions & Feedback \n6.Quit App\n 7.Query";
cin>>choice;
switch(choice)
{
case 1:ini.viewflight_bus(1);
    for(i=0;i<2;i++)
        {
            if(p[i].checkplace(ini))
            {
               p[i].getdetails(ini);
               cout<<"\n";
            cout<<"would you like to book an air ticket sir??"<<endl;
            cin>>ans;
            if(ans=='y')
            {Hi=call_me(ini,h_user);
                Ti=p[i].book(ini);
                Hi.set_ticket_air(Ti);
                }
                break;
            }


        }
        break;

case 2:ini.viewflight_bus(2);
    for(i=0;i<2;i++)
        {
            if(p[i].checkplace(ini))
            {
               p[i].getdetails(ini);
               cout<<"\n"<<"would you like to book a bus ticket sir??"<<endl;
            cin>>ans;
            if(ans=='y')
            {Hi=call_me(ini,h_user);
                Ti=p[i].book(ini);
                Hi.set_ticket_air(Ti);
                }
                break;
            }
        }
        break;

case 3:ini.hotel();
        for(i=0;i<3;i++)
        {
            h[i].update_rooms();
           if(h[i].get_h_place()==ini.to())
           {
               cout<<"\n";
              h[i].display(ini.get_chkin(),ini.get_chkout());

           }
        }
        cout<<"\n"<<"Would you Like to book A hotel sir?? ";
        cin>>ans;
        if(ans=='y')
        {
            Hi=call_me(ini,h_user);
            int opt;
            cout<<"Enter Hotel Id- ";
            cin>>opt;
            int rooms=ini.ppl_hot()/2;
            if(ini.ppl_hot()%2==1)
                rooms++;
            for(i=0;i<3;i++)
            {
                if(opt==h[i].get_id())
                {opt=i;
                break;
                }

            }
            cout<<"option--"<<opt;
            if(h[opt].check_room(ini.getd1().getdateno(),ini.getd2().getdateno(),ini.getd1().getmonth(),ini.getd2().getmonth(),rooms))
            {
            h_voucher *vouch=new h_voucher(rooms,h[opt].getfare(),ini.get_chkin().getdateno(),ini.get_chkin().getmonth(),ini.get_chkout().getdateno(),ini.get_chkout().getmonth(),ini.ppl_hot());
            cout<<endl;
            cout<<"Voucher Info-";
            //vouch->display();
            h[opt].add_voucher(vouch);
            Hi.set_voucher(vouch);
            }
            else
                {cout<<"Sorry Not Enough Rooms";
                getch();
                goto repeat;
                }

        }

            break;

    case 4:

            cout<<"Want to travel by 1.flight 2.Bus";
            cin>>cho;
            if(cho==1)
     ini.tour_flight_hotel(1);
    else
        ini.tour_flight_hotel(2);
    for(i=0;i<2;i++)
    {
            if(p[i].checkplace(ini))
            {
                cout<<"\n";
              p[i].getdetails(ini);
              cho=i;
              }
}
            rooms=ini.ppl_hot()/2;
            if(ini.ppl_hot()%2==1)
                rooms++;

for(i=0;i<3;i++)
{           h[i].update_rooms();
            if(h[i].check_room(ini.getd1().getdateno(),ini.getd2().getdateno(),ini.getd1().getmonth(),ini.getd2().getmonth(),rooms)&&h[i].get_h_place()==ini.to())
                {
                    h[i].display(ini.getd1(),ini.getd2());
                    cout<<"\n";
                }
}

    int fn;
    int fn1;
    int nod;

    float f_fare;
    cout<<"\n"<<"Enter transport id u want to select:";
    cin>>fn;
    f_fare=p[cho].get_ff(fn,ini)*ini.ppl();
    cout<<"\n"<<"Enter hotel id u want to select:";
    cin>>fn1;
    if(ini.getd1().getmonth()<ini.getd2().getmonth())
   {nod=(arr[ini.getd1().getmonth()]-ini.getd1().getdateno()+1)+ini.getd2().getdateno();

    }
    else
    {
        nod=ini.getd2().getdateno()-ini.getd1().getdateno();

    }
    for(i=0;i<3;i++)
    {
        if(h[i].get_id()==fn1)
            cho1=i;
    }
    f_fare=f_fare+(h[cho1].getfare()*ini.ppl()*nod);
    //cout<<(h[cho1].getfare()*ini.ppl()*nod);
     cout<<"Total Fare:"<<f_fare;
     cout<<"\n"<<"sir would u like to book your tour??";
     cin>>ans;
     if(ans=='y')
     {
         Hi=call_me(ini,h_user);
         Ti=p[cho].Book_tour(ini,fn);
         Hi.set_ticket_air(Ti);
         int rooms=ini.ppl_hot()/2;
            if(ini.ppl_hot()%2==1)
                rooms++;
            h_voucher *vouch=new h_voucher(rooms,h[cho1].getfare(),ini.get_chkin().getdateno(),ini.get_chkin().getmonth(),ini.get_chkout().getdateno(),ini.get_chkout().getmonth(),ini.ppl_hot());
            cout<<endl;
            cout<<"Voucher Info- ";
            h[cho1].add_voucher(vouch);
            cout<<"No--"<<h[cho1].getvoucher();
            Hi.set_voucher(vouch);


     }
     Hi.set_tour();
     break;

     case 5:cout<<"Give Your Feedback About Your Tour/Flight/Bus/Hotel Sir-\n";
            cin.ignore();
            getline(cin,feed_back);
            feed.push_back(feed_back);
            //cout<<feed[0];
            break;

     case 6:exit(0);
     break;

     case 7:float maxim=-1.00;
            int j;
            for(i=0;i<2;i++)
{
    if(h_user[i].getuser_tot()>maxim)
        {maxim=h_user[i].getuser_tot();
        j=i;
        }
}
cout<<"Max Fare Booked-- "<<h_user[j].getuser_tot();
h_user[j].show_user_det();
cout<<"No of Transactions-- "<<h_user[j].get_count();
exit(0);
         //query_tot(h_user);


}


//---------------------------------------------PAYMENT PROCESS-----------------------------------------------------
    if(ans=='y')
    {
        system("cls");
    cout<<"User INFO ALL--\n";
    {
        Hi.show_user_det();
        cout<<endl;
        Hi.show_user_bank();
    }

   cout<<"\n"<<"Your Total fare Comes out to be--"<<Hi.get_tot_fare(choice)<<endl;
    string name;
    long int card;
    int mon,year,pin;

    cout<<"\n"<<"Enter The Mode Of Payment--\n1.Debit Card\n2.Net Banking";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"Enter details--"<<endl;
                cout<<"name:";
                cin>>name;
                cout<<endl;
                cout<<"card no:";
                cin>>card;
                cout<<endl;
                cout<<"expiry month:";
                cin>>mon;
                cout<<endl;
                cout<<"expiry year:";
                cin>>year;
                cout<<endl;
                cout<<"pin:";
                cin>>pin;
                cout<<endl;
                if(Hi.check_card(name,card,mon,year,pin,Hi.get_tot_fare(choice)))
                {cout<<"Processing Payment Of....."<<Hi.get_tot_fare(choice);
                getch();
                cout<<"Payment Successful!!";
                }
                else
                {
            cout<<"Details Entered Are Wrong Or The Account Has Not Enough Money To Proceed";
                }
                break;

        case 2:cout<<"Enter Net_bank Details"<<endl;
                cout<<"name:";
                cin>>name;
                cout<<endl;
                cout<<"no:";
                cin>>card;
                cout<<endl;
                cout<<"pin:";
                cin>>pin;
                cout<<endl;
                if(Hi.check_nbank(name,card,pin,Hi.get_tot_fare(choice)))
                {cout<<"Processing Payment Of...."<<Hi.get_tot_fare(choice);
                getch();
                cout<<"Payment Successful!!";
                }
                else
                {
            cout<<"Details Entered Are Wrong Or The Account Has Not Enough Money To Proceed";
                }
                break;

    }
    flag=1;
    }

    if(flag==1)
    {
    cout<<"\n"<<"\nCurrent bank--"; Hi.show_user_bank();
    for(i=0;i<ini.get_users();i++)
    {
        if(Hi.get_id()==h_user[i].get_id())
        {
            break;
        }
    }
    h_user[i]=Hi;
    }
    getch();
    goto repeat;
    return 0;
}



