#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<unistd.h>
#include<windows.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
class meni;


class wallet                                                                    //class wallet
{
protected:
    long long int h,mint,d,m,year,my_day;
    unsigned int credits;
    double bal,amount;
    char w_name[100];


public:
    char coups[100];
    void walletfile(string noho)
    {
        int y;
        int s=noho.length();
        for(y=0;y<s;++y)
        {
            w_name[y]=noho[y];
        }
        w_name[y]='\0';
        ifstream nick;
        nick.open(w_name,ios::in);
        if(nick.fail())
        {
            ofstream molt;
            molt.open(w_name,ios::out);
            molt<<0;
            molt.close();
            nick.close();
        }
        else
        {
            nick.close();
        }

    }
    void time(int hr,int minit, int day,int mn,int yr,int my_d)
    {
        h=hr;
        mint=minit;
        d=day;
        m=mn;
        year=yr;
        my_day=my_d;
    }
    void coupons()
    {
        ifstream liza;
        liza.open("Noftime.txt",ios::in);
        liza>>credits;
        liza.close();
        unsigned int DLimit;
        if(credits<=200)
        {

            cout<<"\nYou are not eligible for coupons!\nYour account should have above 200 credits to become eligible for coupons!\n";
            Sleep(2000);
        }
        else
        {
            ifstream todd;
            todd.open("coupons.txt",ios::in);
            memset(coups,'\0',100);
            cout<<"\nYou current Credits are "<<credits;
            if(credits>200&&credits<=250)
            {
                todd.getline(coups,100);
                DLimit=200;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            else if(credits>250&&credits<=300)
            {
                for(int i=0;i<2;++i)
                {
                    todd.getline(coups,100);
                }
                DLimit=250;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            else if(credits>300&&credits<=350)
            {
                for(int i=0;i<3;++i)
                {
                    todd.getline(coups,100);
                }
                DLimit=300;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            else if(credits>350&&credits<=400)
            {
                for(int i=0;i<4;++i)
                {
                    todd.getline(coups,100);
                }
                DLimit=350;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            else if(credits>400&&credits<=450)
            {
                for(int i=0;i<5;++i)
                {
                    todd.getline(coups,100);
                }
                DLimit=400;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            else if(credits>450&&credits<=500)
            {
                for(int i=0;i<6;++i)
                {
                    todd.getline(coups,100);
                }
                DLimit=450;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            else
            {
                for(int i=0;i<7;++i)
                {
                todd.getline(coups,100);
                }
                DLimit=500;
                cout<<"\nYour DLimit is set to "<<DLimit;
            }
            char mone[100]="",deduc[100]="";
            cout<<"\nA new Coupon is available and can be added to your Active Coupon List!\nClaim Coupon \"";
            int y;
            for(y=0;coups[y]!=':';++y)
            {
                mone[y]=coups[y];
                cout<<coups[y];
            }
            cout<<"\" to get ";
            int k=0;
            for(int u=y+1;coups[u]!=':';++u)
            {
                deduc[k]=coups[u];
                cout<<coups[u];
                ++k;
            }
            cout<<"% off on your next transaction!\n";
            todd.close();
            cout<<"\n\nSelect:-\n1. Claim Coupon (Note that your Credits will be deducted with the DLimit specified above!)\n2. Cancel\nSelection: ";
            int getit;
            cin>>getit;
            if(getit==1)
            {
                credits-=DLimit;
                ofstream sit;
                sit.open("Noftime.txt",ios::out);
                sit<<credits;
                sit.close();
                Sleep(1000);
                cout<<"A new Coupon has been added to your Coupon List!\nUse code \""<<mone<<"\" to get "<<deduc<<" % on your purchase!";
                cout<<"\nNote: Coupons Can be  used only once!\n";
                ofstream haile;
                haile.open("activecoupons.txt",ios::out|ios::app);
                haile<<mone<<":"<<deduc<<":"<<endl;
                haile.close();
            }
            else
            {
                cout<<"\nYour current Credits are "<<credits;
            }
            Sleep(2500);
        }
    }

    void display()
{   int cch1;
cout<<"\nSelect"<<endl<<"1. Add Money"<<"\n2. View Balance"<<endl;
cout<<"Choice: ";
cin>>cch1;

switch(cch1)
{
case 1:
{
if(h>9 && h<22)
{
credit_debit();
}
else
{
cout<<"\nTry again between 9 A.M to 10 P.M"<<endl;
}

   break;

}
case 2:
{
display_amount();
break;
}
default:
cout<<"\nWRONG INPUT!"<<endl;
Sleep(1000);
}
}
protected:
    void credit_debit()
    {
        //cout<<"Your current wallet balance is: "<<bal<<endl;
        re_cd:
        cout<<"\nEnter the amount you wish to add into your wallet: ";
        cin>>amount;
    retry:
        cout<<"\nSelect a payment method:"<<endl;
        cout<<"1. Credit Card\n2. Debit Card\n3.Other Wallets"<<endl;
        int choice;
        cout<<"\nSelection: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                long long int card_num,temp_card_num;
                int card_cvv,temp_card_cvv,r,y,cch3,card_month,card_year;
                string card_name;

                //float balance0=5000.0;
                cpoint:
                cout<<"\nEnter Card details:"<<endl;
                cout<<"Enter Card Holder Name: ";
                getline(cin,card_name);
                getline(cin,card_name);
                c_no:
                cout<<"Enter Card Number: ";
                cin>>card_num;
                temp_card_num=card_num;
                r=0;
                while(temp_card_num>0)
                {
                    temp_card_num=temp_card_num/10;
                    r++;
                }
                //cout<<r;
                if(r<16||r>16)
                {
                    cout<<"\nInvalid Card Number!\nTry again!\n";
                    goto c_no;
                }
                c_cvv:
                cout<<"Enter Card CVV: ";
                cin>>card_cvv;
                temp_card_cvv=card_cvv;
                y=0;
                while(temp_card_cvv>0)
                {
                    temp_card_cvv=temp_card_cvv/10;
                    ++y;
                }
                if(y<3||y>3)
                {
                    cout<<"\nInvalid Card CVV!\nPlease check the 3 digits at the back of your card.\nTry again!\n";
                    goto c_cvv;
                }
                retry2:
                cout<<"\nEnter expiry date: "<<endl;
                cout<<"Month(MM): ";
                cin>>card_month;
                cout<<"Year(YYYY): ";
                cin>>card_year;
                cout<<"YEAR: "<<y<<endl<<"MONTH: "<<m<<endl;
                if(card_year<year || card_month>12)
                {
                    cout<<"Invalid or expired Card details!\nTry again!";
                    goto retry2;
                }
                cout<<endl<<endl;
                cout<<"CHECK YOUR DETAILS: "<<endl;
                cout<<"CARD HOLDER NAME: ";
                cout<<card_name;
                cout<<"\nCARD NUMBER: ";
                cout<<card_num;
                cout<<"\nCVV: ";
                cout<<card_cvv<<endl;
                sel_re:
                cout<<"\nPress:"<<endl<<"1. Save & Continue"<<endl<<"2. Edit card information"<<endl;
                cout<<"Selection: ";
                cin>>cch3;

            if(cch3==1)
            {cpoint2:
                if(amount>=100.0 && amount<=3000.0)
                {
/*char num;
ifstream in_stream("Noftime.txt");
in_stream.get(num);
in_stream.close();
*/

ifstream in_stream("Noftime.txt");
                    in_stream>>credits;

double temp;
ifstream objj;
objj.open(w_name,ios::in);
objj>>temp;
objj.close();

amount+=temp;

ofstream o_stream;
o_stream.open(w_name,ios::out);
o_stream<<amount;
                    o_stream.close();

/*num++;
ofstream out_stream("Noftime.txt");
out_stream<<num;
out_stream.close();
*/
                    credits+=5;
                    ofstream out_stream("Noftime.txt");
                    out_stream<<credits;
                    out_stream.close();
                    in_stream.close();

                    cout<<"\nLoading...\n";
                    Sleep(5000);
                    cout<<"Transaction successful!\n";
cout<<"Rs. "<<amount-temp<<" succesfully added!"<<endl;
cout<<"\nCurrent balance: "<<amount;
Sleep(2000);
}
else
{
if(amount<100)
{
cout<<"\nMinimum transactions can be of Rs. 100.0/-"<<endl;
goto re_cd;
}
else
{
cout<<"\nMaximum transactions can be upto Rs. 3000.0/-"<<endl;
goto re_cd;
}
}
            }
            else if(cch3==2)
{
goto cpoint;
}
else
{
cout<<"WRONG INPUT!"<<endl;
//Sleep(1000);
goto sel_re;
}
         break;
        }
        case 2:
            {
                long long int card_num,temp_card_num;
                int card_cvv,temp_card_cvv,r,y,cch3,card_month,card_year;
                string card_name;

                //float balance0=5000.0;
                chpoint:
                cout<<"\nEnter Card details:"<<endl;
                cout<<"Enter Card Holder Name: ";
                getline(cin,card_name);
                getline(cin,card_name);
                ch_no:
                cout<<"Enter Card Number: ";
                cin>>card_num;
                temp_card_num=card_num;
                r=0;
                while(temp_card_num>0)
                {
                    temp_card_num=temp_card_num/10;
                    r++;
                }
                //cout<<r;
                if(r<16||r>16)
                {
                    cout<<"\nInvalid Card Number!\nTry again!\n";
                    goto ch_no;
                }
                ch_cvv:
                cout<<"Enter Card CVV: ";
                cin>>card_cvv;
                temp_card_cvv=card_cvv;
                y=0;
                while(temp_card_cvv>0)
                {
                    temp_card_cvv=temp_card_cvv/10;
                    ++y;
                }
                if(y<3||y>3)
                {
                    cout<<"\nInvalid Card CVV!\nPlease check the 3 digits at the back of your card.\nTry again!\n";
                    goto ch_cvv;
                }
                rere2:
                cout<<"\nEnter expiry date: "<<endl;
                cout<<"Month(MM): ";
                cin>>card_month;
                cout<<"Year(YYYY): ";
                cin>>card_year;
                //cout<<y<<endl<<m<<endl;
                if(card_year<year || card_month>12)
                {
                    cout<<"Invalid or expired Card details!\nTry again!";
                    goto rere2;
                }
                cout<<endl<<endl;
                cout<<"CHECK YOUR DETAILS: "<<endl;
                cout<<"CARD HOLDER NAME: ";
                cout<<card_name;
                cout<<"\nCARD NUMBER: ";
                cout<<card_num;
                cout<<"\nCVV: ";
                cout<<card_cvv<<endl;
                sel_re2:
                cout<<"\nPress:"<<endl<<"1. Save & Continue"<<endl<<"2. Edit card information"<<endl;
                cout<<"Selection: ";
                cin>>cch3;

            if(cch3==1)
            {   chpoint2:
                if(amount>=100.0 && amount<=3000.0)
                {
/*char num;
ifstream in_stream("Noftime.txt");
in_stream.get(num);
in_stream.close();
*/

ifstream in_stream("Noftime.txt");
                    in_stream>>credits;

double temp;
ifstream objj;
objj.open(w_name,ios::in);
objj>>temp;
objj.close();

amount+=temp;

ofstream o_stream;
o_stream.open(w_name,ios::out);
o_stream<<amount;
                    o_stream.close();

/*num++;
ofstream out_stream("Noftime.txt");
out_stream<<num;
out_stream.close();
*/
                    credits+=5;
                    ofstream out_stream("Noftime.txt");
                    out_stream<<credits;
                    out_stream.close();
                    in_stream.close();

                    cout<<"\nLoading...\n";
                    Sleep(5000);
                    cout<<"Transaction successful!\n";
cout<<"Rs. "<<amount-temp<<" succesfully added!"<<endl;
cout<<"\nCurrent balance: "<<amount;
Sleep(2000);
}
else
{
if(amount<100)
{
cout<<"\nMinimum transactions can be of Rs. 100.0/-"<<endl;
goto re_cd;
}
else
{
cout<<"\nMaximum transactions can be upto Rs. 3000.0/-"<<endl;
goto re_cd;
}
}
            }
            else if(cch3==2)
{
goto chpoint;
}
else
{
cout<<"WRONG INPUT!"<<endl;
goto sel_re2;
}
         break;
        }
        case 3:
            {   int choice2;
                cout<<"\nSelect amongst the following online wallets:\n";
                cout<<"1. Paytm\n2. PhonePe\n";
                cout<<"Selection (1 or 2): ";
                cin>>choice2;
                switch(choice2)
                {
                case 1:
                    {   retry21:
                        string mobile;
                        cout<<"\nEnter your registered Paytm Mobile Number: ";
                        cin>>mobile;
                        if((mobile.size())!=10)
                        {
                            cout<<"\nInvalid mobile number!\nMake sure your mobile number is 10 digit long.\nTry again!\n\n";
                            goto retry21;
                        }
                        double balance;
                        ifstream nick;
                        nick.open("otherwallet.txt",ios::in);
                        nick>>balance;
                        nick.close();
                        cout<<"\nYour current PayTM Balance is: "<<balance<<endl;
                        balance=balance-amount;
                        if(amount>balance)
                        {
                            cout<<"\nTransaction failed!\n";
                            cout<<"Err! Insufficient funds! Try again!\nTry another payment mode!\n\n";
                            goto retry;
                        }
                        else
                        {
                        chpoint31:
                        if(amount>=100.0 && amount<=3000.0)
                        {

                            ifstream in_stream("Noftime.txt");
                            in_stream>>credits;

                            double temp;
                            ifstream objj;
                            objj.open(w_name,ios::in);
                            objj>>temp;
                            objj.close();

                            amount+=temp;

                            ofstream o_stream;
                            o_stream.open(w_name,ios::out);
                            o_stream<<amount;
                            o_stream.close();

                            credits+=5;
                            ofstream out_stream("Noftime.txt");
                            out_stream<<credits;
                            out_stream.close();
                            in_stream.close();

                            cout<<"\nLoading...";
                            Sleep(5000);
                            cout<<"\n\n\nTransaction successful!\n";
                            cout<<"\nRs. "<<amount-temp<<" successfully added!\n";
                            cout<<"\nYour current Paytm balance is: "<<balance<<endl;
                            ofstream juli;
                            juli.open("otherwallet.txt",ios::out);
                            juli<<balance;
                            juli.close();
                            Sleep(2000);
                        }
                        else
                        {
                            cout<<"\nTransactions with minimum amount Rs. 100/- and maximum acount as Rs. 3000/-\nPlease try again!";
                            goto re_cd;
                        }
                        break;

                       }
                    }
                case 2:
                    {
                        retry22:
                        string mobile;
                        cout<<"\nEnter your registered PhonePe Mobile Number: ";
                        cin>>mobile;
                        if((mobile.size())!=10)
                        {
                            cout<<"\nInvalid mobile number!\nMake sure your mobile number is 10 digit long.Try again!";
                            goto retry22;
                        }
                        double balance;
                        ifstream howard;
                        howard.open("otherwallet.txt",ios::in);
                        howard>>balance;
                        howard.close();
                        cout<<"Your current Balance is: "<<balance;
                        balance=balance-amount;
                        if(amount>balance)
                        {
                            cout<<"\nTransaction failed!\n";
                            cout<<"Err! Insufficient funds! Try again!\nTry another payment mode!\n\n";
                            goto retry;
                        }
                        else
                        {
                            chpoint32:
                        if(amount>=100.0 && amount<=3000.0)
                        {
                            ifstream in_stream("Noftime.txt");
                            in_stream>>credits;

                            double temp;
                            ifstream objj;
                            objj.open(w_name,ios::in);
                            objj>>temp;
                            objj.close();

                            amount+=temp;

                            ofstream o_stream;
                            o_stream.open(w_name,ios::out);
                            o_stream<<amount;
                            o_stream.close();

                            credits+=5;
                            ofstream out_stream("Noftime.txt");
                            out_stream<<credits;
                            out_stream.close();
                            in_stream.close();

                            cout<<"\nLoading...";
                            Sleep(5000);
                            cout<<"\n\n\nTransaction successful!\n\n";
                            cout<<"\nRs. "<<amount-temp<<" successfully added!\n";
                            cout<<"\nYour current Paytm balance is: "<<balance<<endl;
                            ofstream nati;
                            nati.open("otherwallet.txt",ios::out);
                            nati<<balance;
                            nati.close();
                            Sleep(2000);
                        }
                        else
                        {
                            cout<<"\nTransactions with minimum amount Rs. 100/- and maximum acount as Rs. 3000/-\nPlease try again!";
                            goto re_cd;
                        }
                        break;

                        }
                    }
                default:cout<<"\nInvalid input";break;
                }
                break;
            }
            default:
                {
                    rede:
                    int dollarin;
                    cout<<"\nInvalid input!\n\nSelect:-\n1. Try again\n2. Cancel Transaction\nSelection: ";
                    cin>>dollarin;
                    if(dollarin==1)
                        goto retry;
                    else if(dollarin==2)
                    {
                        cout<<"Cancelling Transaction...";
                        Sleep(1000);
                        break;
                    }
                    else
                    {
                        cout<<"\nInvalid input!\nTry again!\n";
                        goto rede;
                    }
                    break;
                }
        }                                                            //switch ends here

    }                                               //func ends here

    void display_amount()
    {
        double temp_amount;
        ifstream i_stream;
        //cout<<w_name;
        if(i_stream.fail())
        {
            ofstream ofl;
            ofl.open(w_name,ios::out);
            ofl<<0;
            ofl.close();
            i_stream.open(w_name,ios::in);
            i_stream>>temp_amount;
            i_stream.close();
        }
        else
        {
            i_stream.open(w_name,ios::in);
            i_stream>>temp_amount;
            i_stream.close();
        }
        cout<<"\nBALANCE: "<<temp_amount;
        Sleep(1200);
    }

};

class login:public wallet                                                                             //class login
{

protected:
    string username;
    int ch,impoo;
    string password;
    float balance;
public:
    string operator++()
    {
        string ty;
        ty=username+"_wallet.txt";
        return ty;
    }
   login()
   {
       balance=0000.0;
       impoo=0;
   }
void account()
{

    cout<<"Hello User!"<<endl;
    choice:
    impoo=0;
    cout<<"1. Create new account?\n2. Existing user?\n";
    cout<<"Selection: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            new_account();
        }
    case 2:
        {
            if(impoo==3||impoo==0)
            {
                existing_account();
                break;
            }
            else
                break;

        }
    default:
        {
            cout<<"\n\nErr! Invalid input!\nTry again!"<<endl;
            goto choice;
        }
    }                                                                       //switch ends here fam

}
protected:
void existing_account()
{

                re_signin:
                cout<<"\nEnter details to log in to your account:-";
                char usr[100],temp_pass[100]="";
                char temp_usr[100]="";
                int i,j,k;
                cout<<"\nEnter your SAP ID: ";
                cin>>username;
                try
                {
                for(int d=0;username[d]!='\0';++d)
                {
                    if((username[d]>='a' && username[d]<='z')||(username[d]>='A' && username[d]<='Z')||username[d]==' ')
                    throw username[d];
                }
                }
                catch(char c)
                {
                cout<<"Your SAP ID can only contain digits!\nTry again!";
                goto re_signin;
                }
                if(username.size()!=11)
                {
                   cout<<"\nErr!Your SAP ID has to be 11 digits strong\nTry again!"<<endl;
                   goto re_signin;
                }
                ifstream input_stream;
                input_stream.open("p_account.txt",ios::in);
                while(!input_stream.eof())
                    {   input_stream.getline(usr,100);
                        //cout<<usr;
                        for(i=0;usr[i]!=':';++i)
                        {
                                temp_usr[i]=usr[i];
                        }
                        //cout<<temp_usr<<endl;
                        if(temp_usr==username)
                        {
                            goto passchk;
                        }
                        memset(temp_usr,'\0',100);
                    }
                    goto breaking2;
                    passchk:
                    cout<<"Account Found!"<<endl;
                    re_signpass:
                    cout<<"\nEnter your password: ";
                    cin>>password;

                    k=0;
                    for(j=i+1;usr[j]!=':';++j)
                    {
                        temp_pass[k]=usr[j];
                        k++;
                    }
                    if(temp_pass==password)
                    {
                        cout<<"Welcome "<<temp_usr<<"!\nNice to have you back!\nWhat would you like to do?"<<endl;
                        Sleep(2300);
                    }
                    else
                    {
                        cout<<"\nWrong Password!\nTry again!"<<endl;
                        goto re_signpass;
                    }
                    memset(temp_pass,'\0',100);
                    goto breaking1;
                breaking2:
                cout<<"\n\nAccount not found!\nTry again!\n";
                goto re_signin;
                breaking1:
                input_stream.close();
                //Sleep(3000);
}
int new_account()
{
        re_signup:
            cout<<"\nEnter your details to create your account:- \n";
            cout<<"\nEnter your SAP ID: ";
            cin>>username;
            try
            {
                for(int d=0;username[d]!='\0';++d)
                {
                    if((username[d]>='a' && username[d]<='z')||(username[d]>='A' && username[d]<='Z')||username[d]==' ')
                        throw username[d];
                }
            }
            catch(char a)
            {
                cout<<"Your SAP ID can only contain digits!\nTry again!";
                goto re_signup;
            }
            if(username.size()!=11||username=="0")
               {
                   cout<<"\nErr!Your SAP ID has to be 11 digits strong\nTry again!"<<endl;
                   goto re_signup;
               }
            ifstream jeff;
            jeff.open("p_account.txt",ios::in);
            char j_line[100]="0",j_usr[100]="0";
            int j1;
            while(!jeff.eof())
            {
                jeff.getline(j_line,100);
                for(j1=0;j_line[j1]!=':';++j1)
                {
                    j_usr[j1]=j_line[j1];
                }
                if(j_usr==username)
                {
                    cout<<"\nYour Account already exists!\nContact Management to change your password or simply log into your account!\n";
                    yikes:
                    int yipee;
                    cout<<"\nSelect:-\n1. Get Management details\n2. Log into your account\nSelection: ";
                    cin>>yipee;
                    if(yipee==1)
                    {
                         cout<<"\nContact Details are displayed in the next window!\n";
                         Sleep(1200);
                         return 0;
                    }
                    else if(yipee==2)
                    {
                        impoo=3;
                        jeff.close();
                        Sleep(1500);
                        return 0;
                    }
                    else
                    {
                        cout<<"\nInvalid Input!\nTry again!";
                        goto yikes;
                    }
                }
            }
            jeff.close();
            cout<<"\nAccount Created!"<<endl;
            password="admin";
            cout<<"Your default password is 'admin'.\n(Note that once you log into your account you have to change your password!)"<<endl;
            ofstream output_stream;
            output_stream.open("account.txt",ios::out|ios::app);
            output_stream<<username<<":"<<password<<":"<<balance<<":"<<endl;
            output_stream.close();
            ting:
            char re_username[100]="";
            cout<<"\nRe-enter your SAP ID: ";
            cin>>re_username;
            if(re_username!=username)
            {
                cout<<"\nSAP ID's don't match!\nTry again!";
                goto ting;
            }
            ifstream i_stream;
            i_stream.open("account.txt",ios::in);
            int i,j,k=0;
            char un[100]="",ps[100]="",t_usr[100]="",t_pass[100]="";
            while(!i_stream.eof())
                    {   i_stream.getline(un,100);
                        //cout<<usr;
                        for(i=0;(un[i]!='\0')&&(un[i]!=':');++i)
                        {
                                t_usr[i]=un[i];
                        }
                        //cout<<temp_usr<<endl;
                        if(t_usr==username)
                        {
                            goto passck;
                        }
                        memset(t_usr,'\0',100);
                    }
            cout<<"\nIncorrect Username!";
            goto ting;
                    passck:
                    cout<<"\nAccount Found!"<<endl;
                    cout<<"Welcome "<<t_usr<<endl;
                    re_signinpass:
                    cout<<"\n\nEnter your default password: ";
                    cin>>password;
                    k=0;
                    for(j=i+1;un[j]!=':';++j)
                    {
                        t_pass[k]=un[j];
                        k++;
                    }
                    if(t_pass==password)
                    {
                        reap:
                        char t_password[100]="";
                        cout<<"\nEnter your desired password: ";
                        cin>>password;
                        cout<<"Re-enter your desired password: ";
                        cin>>t_password;
                        if(t_password!=password)
                        {
                            cout<<"\nPasswords don't match!\nTry again!\n\n";
                            goto reap;
                        }
                        ofstream o_stream;
                        o_stream.open("p_account.txt",ios::out|ios::app);
                        o_stream<<username<<":"<<password<<":"<<endl;
                        cout<<"\nPassword saved!"<<endl;
                        o_stream.close();
                        Sleep(2000);
                    }
                    else
                    {
                        cout<<"\nWrong Password!\nTry again!"<<endl;
                        goto re_signinpass;
                    }

                i_stream.close();
                impoo=5;

}                                                                           //function ends here fam

friend string history(login A);
friend void acc_det(login X,meni Y,string test);

};

class meni:public wallet                                                                                 //class meni
{
    string flname;
    char fn[100];

protected:
    char f_name[100],ft_name[100];
public:
void filenamee(string xo)
{
int v;
int g=xo.length();
//f_name[g+1];
for(v=0;v<g;++v)
{
    ft_name[v]=xo[v];
}
ft_name[v]='\0';
//cout<<ft_name<<endl;
}
int order(string c)                                                                                     //order func
{
char line[100]="",tline[100]="",price[100]="",item_name[100]="";
int i,j,a,b;
int sel_item;
flname=c;
retry:
cout<<"\n\nSelect amongst the following:-\n1. Order Food\n2. Search Item\n3. Return to the main menu\nSelection: ";
cin>>a;
            if(a==1)
            {
                /*int my_local_time=(h*100)+mint;
                if( my_local_time<600 || my_local_time>2000 || my_day==7)
                {

                    if(my_day==7)
                    {
                        cout<<"Sorry!\nWe are closed on Sundays!"<<endl;
                    }
                    else
                    {
                        cout<<"\nOops!\nTry again between 6 A.M. and 8 P.M.\n";
                    }
                    Sleep(2300);
                    return 0;
                }
                else
                {

                }*/
                re_cuisine:
                cout<<"\nSelect a cuisine:\n";
                ifstream obj;
                obj.open("menua.txt",ios::in);
while(!obj.eof())
{
obj.getline(line,100);
cout<<endl<<line;
}
cout<<"6. Return to the main menu";
cout<<"\nSelection: ";
int cate;
cin>>cate;
switch(cate)
{
case 1:
{
int qt=0,qtpie=0;
rete:
ifstream obj1;
obj1.open("southindian.txt",ios::in);
int n=1;
while(!obj1.eof())
{
obj1.getline(line,100);

cout<<n<<". ";
++n;
for(j=0;line[j]!=':';++j)
{
cout<<line[j];
}
cout<<"\t";
for(int k=j+1;line[k]!=':';++k)
{
cout<<line[k];
}
cout<<endl;
}
obj1.close();
retry1:
                        qt=0;
cout<<"Select an item: ";
cin>>sel_item;
if(sel_item!=1&&sel_item!=2&&sel_item!=3&&sel_item!=4)
                            goto retry1;
ifstream ojj;
ojj.open("southindian.txt",ios::in);
                        for(int r=0;r<sel_item;++r)
                        {
                            ojj.getline(tline,100);
                        }
                        ojj.close();
                        cout<<"\nYou've selected ";
                        for(i=0;tline[i]!=':';++i)
                        {
                            item_name[i]=tline[i];
                        }
                        cout<<item_name<<endl;
                        int u,x=0;
                        for(u=i+1;tline[u]!=':';++u)
                        {
                            price[x]=tline[u];
                            ++x;
                        }
                        int order_choice;
                        cout<<"\nSelect:-"<<endl<<"1. Immediate Order"<<endl<<"2. Schedule Order"<<endl<<"Selection: ";
                        cin>>order_choice;

                        if(order_choice==1)
                        {
                            if(mint+15>=60)
                            {
                                ++h;
                                mint=(mint+15)-60;
                                cout<<"Your meal would be prepared by "<<setw(2)<<setfill(' ')<<h<<":"<<mint<<endl;
                            }
                            else
                            {
                                cout<<"Your meal would be prepared by "<<setw(2)<<setfill(' ')<<h<<":"<<mint+15<<endl;
                            }
                        }
                        else
                        {
                            retry_order:
                            int c1,m_time,m_min;
                            int h1,m1;
                            cout<<"Enter time(H:M):-"<<endl;
                            cout<<"HOURS: ";
                            cin>>h1;
                            cout<<"MINUTES: ";
                            cin>>m1;
                            if(h1<h)
                            {
                                cout<<"\nInvalid Input!\nTry again!\n\n"<<endl;
                                goto retry_order;
                            }
                            else if(h1>h)
                            {
                                m_time=h1-h;
                                if(m_time<3)
                                {
                                    cout<<"Think we can pull it off!\nYour meal would be ready by then!"<<endl;
                                }
                                else
                                {
                                    cout<<"\nInvalid Input!\nTry again!\n\n"<<endl;
                                    goto retry_order;
                                }
                            }
                            else if(h1=h)
                            {

                                if(m1<mint)
                                {
                                    cout<<"\nInvalid Input!\nTry again!\n\n"<<endl;
                                    goto retry_order;
                                }
                                else if(m1>=mint+15)
                                {
                                    cout<<"Think we can pull it off!\nYour meal would be ready by then!"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"\nInvalid input!\nTry again!\n\n";
                                goto retry_order;
                            }
                        }
                        qt=0,qtpie=0;
                        menuuu:
                        int trr;

                        cout<<"\n\nProceed to:\n1. The Cart?\n2. To add more?\n3. Edit Order?\nSelection: ";
                        cin>>trr;
                        char itname[100]="",toi[100]="",pprice[100]="",fin[10]={48,48};
                        int s=0;
                        switch(trr)
                        {
                        case 1:
                            {   double amot;
                                if(qtpie==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    //ojj.close();
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                else
                                {
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                sel:
                                int coi;
                                ifstream nite;
                                nite.open(w_name,ios::in);
                                nite>>bal;
                                cout<<"\n\nYour current wallet balance is Rs. "<<bal<<"/-\n";
                                cout<<"\nSelect amongst the following:-\n1. Proceed to Checkout\n2. Return to the menu\n";
                                cout<<"3. Cancel Order(Note this will discard all the items from the cart!)\nSelection:  ";
                                cin>>coi;
                                if(coi==1)
                                    checkout_amount(amot,flname);
                                else if(coi==2)
                                {
                                   qtpie=3;
                                   qt=2;
                                   goto menuuu;
                                }
                                else if(coi==3)
                                {
                                    cout<<"Discarding items from the cart...";
                                    Sleep(1000);
                                    ofstream dell;
                                    dell.open("cart.txt",ios::trunc);
                                    dell.close();
                                }
                                else
                                {
                                    cout<<"\nInvalid input!"<<endl<<"Try again!\n";
                                    goto sel;
                                }
                                break;
                            }
                        case 2:
                            {
                                if(qt==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    memset(item_name,'\0',100);
                                    re_ask:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask;
                                    }
                                    break;
                                }
                                else
                                {
                                    memset(item_name,'\0',100);
                                    re_ask0:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask0;
                                    }
                                    break;
                                }
                                break;
                            }
                        case 3:
                            {   memset(item_name,'\0',100);
                                memset(tline,'\0',100);
                                goto rete;
                                break;
                            }
                        default:
                            {
                                cout<<"\nInvalid Input!"<<endl;
                                goto rete;
                            }
                        }
                        break;
}
                                                                                            //case 1 ends here
            case 2:                                                                                //case 2starts here
                {
                int qt=0,qtpie=0;
                rete1:
ifstream obj1;
obj1.open("mumbiamasala.txt",ios::in);
int n=1;
while(!obj1.eof())
{
obj1.getline(line,100);

cout<<n<<". ";
++n;
for(j=0;line[j]!=':';++j)
{
cout<<line[j];
}
cout<<"\t";
for(int k=j+1;line[k]!=':';++k)
{
cout<<line[k];
}
cout<<endl;
}
obj1.close();
retry11:
                        qt=0;
cout<<"Select an item: ";
cin>>sel_item;
if(sel_item!=1&&sel_item!=2&&sel_item!=3&&sel_item!=4)
                            goto retry11;
ifstream ojj;
ojj.open("mumbiamasala.txt",ios::in);
                        for(int r=0;r<sel_item;++r)
                        {
                            ojj.getline(tline,100);
                        }
                        ojj.close();
                        cout<<"\nYou've selected ";
                        for(i=0;tline[i]!=':';++i)
                        {
                            item_name[i]=tline[i];
                        }
                        cout<<item_name<<endl;
                        int u,x=0;
                        for(u=i+1;tline[u]!=':';++u)
                        {
                            price[x]=tline[u];
                            ++x;
                        }
                        int order_choice;
                        cout<<"\nPress:"<<endl<<"1. Immediate Order"<<endl<<"2. Schedule Order"<<endl<<"Selection: ";
                        cin>>order_choice;

                        if(order_choice==1)
                        {
                            if(mint+15>=60)
                            {
                                h++;
                                mint=(mint+15)-60;
                                cout<<"Your meal would be prepared by "<<setw(2)<<setfill(' ')<<h<<":"<<mint<<endl;
                            }
                            else
                            {
                                cout<<"Your meal would be prepared by "<<setw(2)<<setfill(' ')<<h<<":"<<mint+15<<endl;
                            }

                        }
                        else
                        {
                            retry_order3:
                            int c1,m_time,m_min;
                            int h1,m1;
                            cout<<"Enter time(H:M):"<<endl;
                            cout<<"HOURS: ";
                            cin>>h1;
                            cout<<"MINUTES: ";
                            cin>>m1;
                            if(h1<h)
                            {
                                cout<<"\nInvalid input!\n\n"<<endl;
                                goto retry_order3;
                            }
                            else if(h1>h)
                            {
                                m_time=h1-h;
                                if(m_time<3)
                                {
                                    cout<<"\nThink we can pull it off!\nYour meal would be ready by then!"<<endl;
                                }
                                else
                                {
                                    cout<<"\nInvalid input!\n\n"<<endl;
                                    goto retry_order3;
                                }
                            }
                            else if(h1=h)
                            {

                                if(m1<mint)
                                {
                                    cout<<"\nInvalid input!\n\n"<<endl;
                                    goto retry_order3;
                                }
                                else if(m1>=mint+15)
                                {
                                    cout<<"\nThink we can pull it off!\nYour meal would be ready by then!"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"\nInvalid input!\n";
                                goto retry_order3;
                            }
                        }
                        /*ofstream point;
                        point.open("cart.txt",ios::out|ios::app);
                        point<<item_name<<':'<<price<<':'<<endl;
                        point.close();
                        ojj.close();
                        */
                        qt=0,qtpie=0;
                        menuuu1:
                        int trr;
                        cout<<"\nProceed to:\n1. The Cart?\n2. To add more?\n3. Edit Order?\nSelection: ";
                        cin>>trr;
                        char itname[100]="",toi[100]="",pprice[100]="",fin[10]={48,48};
                        int s=0;
                        switch(trr)
                        {
                        case 1:
                            {   double amot;
                                if(qtpie==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    //ojj.close();
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                else
                                {
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                sel1:
                                int coi;
                                ifstream nite;
                                nite.open(w_name,ios::in);
                                nite>>bal;
                                cout<<"\n\nYour current wallet balance is Rs. "<<bal<<"/-\n";
                                cout<<"\nSelect amongst the following:-\n1. Proceed to Checkout\n2. Return to the menu\n";
                                cout<<"3. Cancel Order(Note this will discard all the items from the cart!)\nSelection:  ";                                cin>>coi;
                                if(coi==1)
                                    checkout_amount(amot,flname);
                                else if(coi==2)
                                {
                                   qtpie=3;
                                   qt=2;
                                   goto menuuu1;
                                }
                                else if(coi==3)
                                {
                                    cout<<"Discarding items from the cart...";
                                    Sleep(1000);
                                    ofstream bill;
                                    bill.open("cart.txt",ios::trunc);
                                    bill.close();
                                }
                                else
                                {
                                    cout<<"\nInvalid input!"<<endl<<"Try again!\n";
                                    goto sel1;
                                }
                                break;
                            }
                        case 2:
                            {
                                if(qt==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    memset(item_name,'\0',100);
                                    re_ask11:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete1;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask11;
                                    }
                                    break;
                                }
                                else
                                {
                                    memset(item_name,'\0',100);
                                    re_ask111:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete1;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask111;
                                    }
                                    break;
                                }
                                break;
                            }
                        case 3:
                            {   memset(item_name,'\0',100);
                                memset(tline,'\0',100);
                                goto rete1;
                                break;
                            }
                        default:
                            {
                                cout<<"\nInvalid Input!"<<endl;
                                goto rete1;
                            }
                        }

                    break;
                }
            case 3:                                                                                               //CASE 3 STARTS HERE
                {

                        int qt=0,qtpie=0;
                        rete2:
ifstream obj1;
obj1.open("mpstmespecial.txt",ios::in);
int n=1;
while(!obj1.eof())
{
obj1.getline(line,100);

cout<<n<<". ";
++n;
for(j=0;line[j]!=':';++j)
{
cout<<line[j];
}
cout<<"\t";
for(int k=j+1;line[k]!=':';++k)
{
cout<<line[k];
}
cout<<endl;
}
obj1.close();
retry12:
                        qt=0;
cout<<"Select an item: ";
cin>>sel_item;
if(sel_item!=1&&sel_item!=2)
                            goto retry12;
ifstream ojj;
ojj.open("mpstmespecial.txt",ios::in);
                        for(int r=0;r<sel_item;++r)
                        {
                            ojj.getline(tline,100);
                        }
                        ojj.close();
                        //cout<<endl<<tline<<"++:";
                        cout<<"\nYou've selected ";
                        for(i=0;tline[i]!=':';++i)
                        {
                            item_name[i]=tline[i];
                        }
                        cout<<item_name<<endl;
                        int u,x=0;
                        for(u=i+1;tline[u]!=':';++u)
                        {
                            price[x]=tline[u];
                            ++x;
                        }
int order_choice;
                        cout<<"\nPress:"<<endl<<"1. Immediate Order"<<endl<<"2. Schedule Order"<<endl<<"Selection: ";
                        cin>>order_choice;

                        if(order_choice==1)
                        {
                            if(mint+15>=60)
                            {
                                h++;
                                mint=(mint+15)-60;
                                cout<<"Your meal would be prepared by "<<setw(2)<<setfill(' ')<<h<<":"<<mint<<endl;
                            }
                            else
                            {
                                cout<<"Your meal would be prepared by "<<setw(2)<<setfill(' ')<<h<<":"<<mint+15<<endl;
                            }
                        }
                        else
                        {
                            retry_order1:
                            int c1,m_time,m_min;
                            int h1,m1;
                            cout<<"Enter time(H:M):"<<endl;
                            cout<<"HOURS: ";
                            cin>>h1;
                            cout<<"MINUTES: ";
                            cin>>m1;
                            if(h1<h)
                            {
                                cout<<"\nInvalid input!\n\n";
                                goto retry_order1;
                            }
                            else if(h1>h)
                            {
                                m_time=h1-h;
                                if(m_time<3)
                                {
                                    cout<<"\nThink we can pull it off!\nYour meal would be ready by then!"<<endl;
                                }
                                else
                                {
                                    cout<<"\nInvalid input!\n\n";
                                    goto retry_order1;
                                }
                            }
                            else if(h1=h)
                            {

                                if(m1<mint)
                                {
                                    cout<<"\nInvalid input!\n\n";
                                    goto retry_order1;
                                }
                                else if(m1>=mint+15)
                                {
                                    cout<<"\nThink we can pull it off!\nYour meal would be ready by then!"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"\nInvalid input!\n\n";
                                goto retry_order1;
                            }
                        }
                        /*ofstream point;
                        point.open("cart.txt",ios::out|ios::app);
                        point<<item_name<<':'<<price<<':'<<endl;
                        point.close();
                        ojj.close();
                        */
                        qt=0,qtpie=0;
                        menuuu2:
                        int trr;
                        cout<<"\nProceed to:\n1. The Cart?\n2. To add more?\n3. Edit Order?\nSelection: ";
                        cin>>trr;
                        char itname[100]="",toi[100]="",pprice[100]="",fin[10]={48,48};
                        int s=0;
                        switch(trr)
                        {
                        case 1:
                            {   double amot;
                                if(qtpie==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    //ojj.close();
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                else
                                {
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                sel2:
                                int coi;
                                ifstream nite;
                                nite.open(w_name,ios::in);
                                nite>>bal;
                                cout<<"\n\nYour current wallet balance is Rs. "<<bal<<"/-\n";
                                cout<<"\nSelect amongst the following:-\n1. Proceed to Checkout\n2. Return to the menu\n";
                                cout<<"3. Cancel Order(Note this will discard all the items from the cart!)\nSelection:  ";
                                cin>>coi;
                                if(coi==1)
                                    checkout_amount(amot,flname);
                                else if(coi==2)
                                {
                                   qtpie=3;
                                   qt=2;
                                   goto menuuu2;
                                }
                                else if(coi==3)
                                {
                                    cout<<"Discarding items from the cart...";
                                    Sleep(1000);
                                    ofstream nah;
                                    nah.open("cart.txt",ios::trunc);
                                    nah.close();
                                }
                                else
                                {
                                    cout<<"\nInvalid input!"<<endl<<"Try again!\n";
                                    goto sel2;
                                }
                                break;
                            }
                        case 2:
                            {
                                if(qt==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    memset(item_name,'\0',100);
                                    re_ask2:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete2;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask2;
                                    }
                                    break;
                                }
                                else
                                {
                                    memset(item_name,'\0',100);
                                    re_ask21:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete2;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask21;
                                    }
                                    break;
                                }
                                break;
                            }
                        case 3:
                            {   memset(item_name,'\0',100);
                                memset(tline,'\0',100);
                                goto rete2;
                                break;
                            }
                        default:
                            {
                                cout<<"\nInvalid Input!"<<endl;
                                goto rete2;
                            }
                        }


                    break;
                }
            case 4:                                                                 //case 4 starts here
                {

                        int qt=0,qtpie=0;
                        rete3:
ifstream obj1;
obj1.open("beverages.txt",ios::in);
int n=1;
while(!obj1.eof())
{
obj1.getline(line,100);

cout<<n<<". ";
++n;
for(j=0;line[j]!=':';++j)
{
cout<<line[j];
}
cout<<"\t";
for(int k=j+1;line[k]!=':';++k)
{
cout<<line[k];
}
cout<<endl;
}
obj1.close();
retry13:
                        qt=0;
cout<<"Select an item: ";
cin>>sel_item;
if(sel_item!=1&&sel_item!=2&&sel_item!=3&&sel_item!=4)
                            goto retry13;
ifstream ojj;
ojj.open("beverages.txt",ios::in);
                        for(int r=0;r<sel_item;++r)
                        {
                            ojj.getline(tline,100);
                        }
                        ojj.close();
                        cout<<"\nYou've selected ";
                        for(i=0;tline[i]!=':';++i)
                        {
                            item_name[i]=tline[i];
                        }
                        cout<<item_name<<endl;
                        int u,x=0;
                        for(u=i+1;tline[u]!=':';++u)
                        {
                            price[x]=tline[u];
                            ++x;
                        }
                        /*ofstream point;
                        point.open("cart.txt",ios::out|ios::app);
                        point<<item_name<<':'<<price<<':'<<endl;
                        point.close();
                        ojj.close();
                        */
                        qt=0,qtpie=0;
                        menuuu3:
                        int trr;
                        cout<<"\nProceed to:\n1. The Cart?\n2. To add more?\n3. Edit Order?\nSelection: ";
                        cin>>trr;
                        char itname[100]="",toi[100]="",pprice[100]="",fin[10]={48,48};
                        int s=0;
                        switch(trr)
                        {
                        case 1:
                            {   double amot;
                                if(qtpie==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    //ojj.close();
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                else
                                {
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                sel3:
                                int coi;
                                ifstream nite;
                                nite.open(w_name,ios::in);
                                nite>>bal;
                                cout<<"\n\nYour current wallet balance is Rs. "<<bal<<"/-\n";
                                cout<<"\nSelect amongst the following:-\n1. Proceed to Checkout\n2. Return to the menu\n";
                                cout<<"3. Cancel Order(Note this will discard all the items from the cart!)\nSelection:  ";
                                cin>>coi;
                                if(coi==1)
                                    checkout_amount(amot,flname);
                                else if(coi==2)
                                {
                                   qtpie=3;
                                   qt=2;
                                   goto menuuu3;
                                }
                                else if(coi==3)
                                {
                                    cout<<"Discarding items from the cart...";
                                    Sleep(1000);
                                    ofstream el;
                                    el.open("cart.txt",ios::trunc);
                                    el.close();
                                }
                                else
                                {
                                    cout<<"\nInvalid input!"<<endl<<"Try again!\n";
                                    goto sel3;
                                }
                                break;
                            }
                        case 2:
                            {
                                if(qt==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    memset(item_name,'\0',100);
                                    re_ask3:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete3;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask3;
                                    }
                                    break;
                                }
                                else
                                {
                                    memset(item_name,'\0',100);
                                    re_ask31:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete3;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask31;
                                    }
                                    break;
                                }
                                break;
                            }
                        case 3:
                            {   memset(item_name,'\0',100);
                                memset(tline,'\0',100);
                                goto rete3;
                                break;
                            }
                        default:
                            {
                                cout<<"\nInvalid Input!"<<endl;
                                goto rete3;
                            }
                        }

                    break;
                }
            case 5:                                                                         //case 5 starts here
                {

                        int qt=0,qtpie=0;
                        rete4:
ifstream obj1;
obj1.open("chocolates.txt",ios::in);
int n=1;
while(!obj1.eof())
{
obj1.getline(line,100);

cout<<n<<". ";
++n;
for(j=0;line[j]!=':';++j)
{
cout<<line[j];
}
cout<<"\t";
for(int k=j+1;line[k]!=':';++k)
{
cout<<line[k];
}
cout<<endl;
}
obj1.close();
retry14:
                        qt=0;
cout<<"Select an item: ";
cin>>sel_item;
if(sel_item!=1&&sel_item!=2)
                            goto retry14;
ifstream ojj;
ojj.open("chocolates.txt",ios::in);
                        for(int r=0;r<sel_item;++r)
                        {
                            ojj.getline(tline,100);
                        }
                        ojj.close();
                        cout<<"\nYou've selected ";
                        for(i=0;tline[i]!=':';++i)
                        {
                            item_name[i]=tline[i];
                        }
                        cout<<item_name<<endl;
                        int u,x=0;
                        for(u=i+1;tline[u]!=':';++u)
                        {
                            price[x]=tline[u];
                            ++x;
                        }
                        /*ofstream point;
                        point.open("cart.txt",ios::out|ios::app);
                        point<<item_name<<':'<<price<<':'<<endl;
                        point.close();
                        ojj.close();
                        */
                        qt=0,qtpie=0;
                        menuuu4:
                        int trr;
                        cout<<"\nProceed to:\n1. The Cart?\n2. To add more?\n3. Edit Order?\nSelection: ";
                        cin>>trr;
                        char itname[100]="",toi[100]="",pprice[100]="",fin[10]={48,48};
                        int s=0;
                        switch(trr)
                        {
                        case 1:
                            {   double amot;
                                if(qtpie==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    //ojj.close();
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                else
                                {
                                    int y=0,z,v,b;
                                    ifstream ppoint;
                                    ppoint.open("cart.txt",ios::in);
                                    int f,q;
                                    cout<<"\nItems currently in your cart are: "<<endl;
                                    while(!ppoint.eof())
                                    {
                                        ppoint.getline(toi,100);
                                        q;
                                        for(q=0;toi[q]!=':';++q)
                                        {
                                            itname[q]=toi[q];
                                        }
                                        cout<<itname;
                                        memset(itname,'\0',100);
                                        //cout<<"\t";
                                        f=0,u;
                                        for(u=q+1;toi[u]!=':';++u)
                                        {
                                            pprice[f]=toi[u];
                                            ++f;
                                        }
                                        b=(pprice[0]-'0');
                                        v=pprice[1]-'0';
                                        z=(b*10)+v;
                                        s=s+z;
                                        cout<<endl;
                                        ++y;
                                    }
                                    ppoint.close();
                                    //memset(item_name,'\0',100);
                                    amot=s-z;
                                    y--;
                                    cout<<"\nSubtotal(for "<<y<<" items): Rs. "<<amot<<" /-";
                                }
                                sel4:
                                int coi;
                                ifstream nite;
                                nite.open(w_name,ios::in);
                                nite>>bal;
                                cout<<"\n\nYour current wallet balance is Rs. "<<bal<<"/-\n";
                                cout<<"\nSelect amongst the following:-\n1. Proceed to Checkout\n2. Return to the menu\n";
                                cout<<"3. Cancel Order(Note this will discard all the items from the cart!)\nSelection:  ";
                                cin>>coi;
                                if(coi==1)
                                    checkout_amount(amot,flname);
                                else if(coi==2)
                                {
                                   qtpie=3;
                                   qt=2;
                                   goto menuuu4;
                                }
                                else if(coi==3)
                                {
                                    cout<<"Discarding items from the cart...";
                                    Sleep(1000);
                                    ofstream mary;
                                    mary.open("cart.txt",ios::trunc);
                                    mary.close();
                                }
                                else
                                {
                                    cout<<"\nInvalid input!"<<endl<<"Try again!\n";
                                    goto sel4;
                                }
                                break;
                            }
                        case 2:
                            {
                                if(qt==0)
                                {
                                    ofstream point;
                                    point.open("cart.txt",ios::out|ios::app);
                                    point<<item_name<<':'<<price<<':'<<endl;
                                    point.close();
                                    memset(item_name,'\0',100);
                                    re_ask4:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete4;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask4;
                                    }
                                    break;
                                }
                                else
                                {
                                    memset(item_name,'\0',100);
                                    re_ask41:
                                    int ad_mr;
                                    cout<<"\nAdd more from:\n1. The same category\n2. Different category\nSelection: ";
                                    cin>>ad_mr;
                                    if(ad_mr==1)
                                        goto rete4;
                                    else if(ad_mr==2)
                                        goto re_cuisine;
                                    else
                                    {
                                        cout<<"\nInvalid input!\nTry again!\n";
                                        goto re_ask41;
                                    }
                                    break;
                                }
                                break;
                            }
                        case 3:
                            {   memset(item_name,'\0',100);
                                memset(tline,'\0',100);
                                goto rete4;
                                break;
                            }
                        default:
                            {
                                cout<<"\nInvalid Input!"<<endl;
                                goto rete4;
                            }
                        }

                    break;
                }
        case 6:
            {
               cout<<"Redirecting...";
               Sleep(1000);
               break;
            }
            default:
                {
                    cout<<"\nInvalid input!\nTry again!"<<endl;
                    goto retry;
                    break;
                }
            }
            Sleep(2000);                                                                              //switch ends here
            }                                                                                   //if ends here
            else if(a==2)
            {
                char mline[100]="",mitem[100]="";
                string msearch;
                int m;
                ifstream loe;
                loe.open("allmenu.txt",ios::in);
                cout<<"\nEnter the item's name you want to search for: ";
                getline(cin,msearch);
                getline(cin,msearch);
                while(!loe.eof())
                {
                    loe.getline(mline,100);
                    for(m=0;mline[m]!=':';++m)
                    {
                        mitem[m]=mline[m];
                    }
                    if(mitem==msearch)
                    {
                        cout<<endl<<mitem<<" is available in ";
                        for(int y=m+1;mline[y]!=':';++y)
                        {
                            cout<<mline[y];
                        }
                        goto doi;
                    }
                    memset(mitem,'\0',100);
                    memset(mline,'\0',100);
                }
                cout<<"\nItem not found or it isn't in stock!";
                doi:
                    loe.close();
                    Sleep(1500);

            }
            else if(a==3)
            {
                cout<<"\nLet's pretend that never happened!\nRedirecting...";
                Sleep(1500);
                cout<<endl;
            }
            else

            {
                cout<<"\nInvalid Input\nTry again!\n\n";
                goto retry;
            }
            //Sleep(4000);
}                                                                                   //func ends here
protected:
void checkout_amount(double aout,string sr)
{
    int huck,m;
    double SP;
    int a,b;
    double c;
    char huck_line[100]="",huck_code[8]="",huck_disc[3]="";
    cout<<"\nSelect:-\n1. Apply Coupon\n2. Continue to Payment Gateway?\nSelection: ";
    cin>>huck;
    if(huck==1)
    {
        ifstream done;
        done.open("activecoupons.txt",ios::in);
        if(done.fail())
        {
            ofstream pls;
            pls.open("activecoupons.txt",ios::out);
            //pls<<0;
            pls.close();
            cout<<"\nYou've no active coupons!"<<endl;
            goto access_w;
        }
        char ett[100];
        int l=0;
        while(!done.eof())
        {
            memset(ett,'\0',100);
            done.getline(ett,100);
            if(ett[0]==' '||ett[0]=='\n'||ett[0]=='\0')
            {

            }
            else
            {
                ++l;
            }
        }
        done.close();
        if(l==0)
        {
            cout<<"\nYou have no Active coupons!\n";
            goto access_w;
        }
        else
        {
        }
        ifstream donee;
        donee.open("activecoupons.txt",ios::in);
        while(!donee.eof())
        {
            donee.getline(huck_line,100);
            for(m=0;huck_line[m]!=':';++m)
            {
                huck_code[m]=huck_line[m];
            }
            int z=0;
            for(int f=m+1;huck_line[f]!=':';++f)
            {
                huck_disc[z]=huck_line[f];
                ++z;
            }
            //cout<<huck_disc<<endl;
        }
        donee.close();
        a=huck_disc[0]-'0';
        b=huck_disc[1]-'0';
        c=(a*10)+b;
        //cout<<c<<endl;
        //cout<<aout<<endl;
        SP=aout*(c/100);
        //cout<<SP;
        cout<<"\nYou will receive Rs. "<<SP<<"/- of discount!\nEnjoy!\n";
        aout=aout-SP;
        ofstream cler;
        cler.open("activecoupons.txt",ios::trunc);
        cler.close();
    }
    else
    {
    }
    access_w:
    cout<<"\nAccessing wallet..."<<endl;
    Sleep(2000);
    double bala;
    batata:
    ifstream amt;
    amt.open(w_name,ios::in);
    amt>>bala;
    double t_bala;
    t_bala=bala-aout;
    if(t_bala<0.0)
    {
        cout<<"\nInsufficient funds in your wallet!\nPlease add money and try again\n\n";
        re_fund:
        cout<<"\nSelect amongst the following:-\n1. Add money\n2. Cancel payment (Note:Items in your cart will be discarded)\nSelection: ";
        int cpr;
        cin>>cpr;
        if(cpr==1)
        {
            credit_debit();

            goto batata;
        }
        else if(cpr==2)
        {
            cout<<"\nTransaction failed!\nDiscarding items in your cart...";
            Sleep(2000);
            ofstream bill;
            bill.open("cart.txt",ios::trunc);
            bill.close();
        }
        else
        {
            cout<<"\nInvalid input!\n";
            goto re_fund;
        }

    }
    else
    {
        ofstream tma;
        tma.open(w_name,ios::out);
        tma<<t_bala;
        cout<<"\nTransaction Successful!\nYour order is confirmed!\nHappy ordering!\n\n";
        cout<<"\nYour current balance is Rs. "<<t_bala<<"/-\n";
        tma.close();
        ifstream shiz;
        shiz.open("Noftime.txt",ios::in);
        shiz>>credits;
        shiz.close();
        credits=credits+5;
        ofstream nshiz;
        nshiz.open("Noftime.txt",ios::out);
        nshiz<<credits;
        nshiz.close();
        //cout<<f_name;
        ifstream vlog;
        vlog.open("cart.txt",ios::in);
        string blah;
        blah=sr;
        int v;
        int g=blah.length();
        //f_name[g+1];
        for(v=0;v<g;++v)
        {
            f_name[v]=blah[v];
        }
        f_name[v]='\0';
        ofstream david;
        david.open(f_name,ios::out|ios::app);
        char pastorders[100]="";
        while(!vlog.eof())
        {
            vlog.getline(pastorders,100);
            david<<pastorders<<endl;
        }
        david.close();
        vlog.close();

        ofstream dell;
        dell.open("cart.txt",ios::trunc);
        dell.close();
        Sleep(1700);
    }

    amt.close();
    Sleep(5000);
}

friend void acc_det(login X,meni Y,string test);
};

void acc_det(login X,meni Y,string test)
{
    int p_len;
    cout<<"\nAccount Details:-"<<endl;
    cout<<"\nSAP ID or username: "<<X.username;
    p_len=X.password.length();
    cout<<"\nPassword: ";
    for(int z=0;z<p_len;++z)
    {
        cout<<"*";
    }
    cout<<endl;
    int sw;
    //cout<<test;
    cout<<"\nSelect:-\n1. View Past orders\n2. View Wallet Balance\n3. Get Rewards\n4. View Credits\n5. View Active Coupons";
    cout<<"\n6. Return to menu";
    cout<<"\nSelections: ";
    cin>>sw;
    switch(sw)
    {
    case 1:
        {
            cout<<"\nPast orders:-\n";
            Y.filenamee(test);
            //cout<<Y.ft_name<<endl;
            char sx[100]="",past[100]="";
            int n=1;
            ifstream dom;
            dom.open(Y.ft_name,ios::in);
            if(dom.fail())
            {
                cout<<"\nYou have no past orders!\nOrder something and come back here!\n";
                Sleep(1200);
                break;
            }
            while(!dom.eof())
            {
                dom.getline(sx,100);

                for(int r=0;sx[r]!=':';++r)
                {
                    past[r]=sx[r];
                }
                if(past[0]==' '||past[0]=='\n'||past[0]=='\0')
                {}
                else
                {
                    cout<<n<<". ";
                    cout<<past;
                    cout<<endl;
                    ++n;
                    memset(past,'\0',100);
                }

            }
            Sleep(1500);
            break;
        }
    case 2:
        {
            Y.display_amount();
            break;
        }
    case 3:
        {
            X.coupons();
            break;
        }
    case 4:
        {
            unsigned int s;
            cout<<"\nCredits are your points!\nWith the help of Credits you can get exciting rewards!\n\n";
            ifstream nott;
            nott.open("Noftime.txt",ios::in);
            nott>>s;
            nott.close();
            cout<<"\nYou currently have "<<s<<" credits in your account!\n";
            cout<<"You can increase those credits by ordering food or by adding money to your wallet!\n";
            Sleep(2500);
            break;
        }
    case 5:
        {
            cout<<"\nActive Coupons:-\n";
            char ohno[100];
            int x,n=0;
            ifstream kit;
            kit.open("activecoupons.txt",ios::in);
            while(!kit.eof())
            {
                kit.getline(ohno,100);
                if(ohno[0]==' '||ohno[0]=='\n'||ohno[0]=='\0')
                {

                }
                else
                    ++n;
            }
            kit.close();
            ifstream kity;
            kity.open("activecoupons.txt",ios::in);
            if(n==0)
            {
                cout<<"\nNo Active Coupons!\nIncrease your Credits to get exciting rewards!\n";
                Sleep(1200);
                break;
            }
            else
            {
                while(!kity.eof())
                {
                kity.getline(ohno,100);
                if(ohno[0]==' '||ohno[0]=='\n'||ohno[0]=='\0')
                {
                }
                else
                {
                    cout<<"\nUse code \"";
                for(x=0;ohno[x]!=':';++x)
                {
                    cout<<ohno[x];
                }
                cout<<"\" to get ";
                for(n=x+1;ohno[n]!=':';++n)
                {
                    cout<<ohno[n];
                }
                cout<<"% off on your next purchase!\n";
                ++n;
                }
                }
                Sleep(2000);
            }
            break;
        }
    case 6:
        {
            break;
        }
    default:cout<<"\nInvalid input!\n Redirecting to the main menu...\n";Sleep(1500);
    }
    //Sleep(8000);
}

string history(login A)
{
    string filenm;
    filenm=A.username+"_allorders.txt";
    return filenm;
}

class check
{
int choice,i,j,l,k,z;
string sap_id;
char Name[100],ID[100],temp_id[100],email_id[100];
public:
int input()
{
while(true)
{
    memset(Name,'\0',100);
    memset(ID,'\0',100);
    memset(temp_id,'\0',100);
    memset(email_id,'\0',100);
    k=0;
    z=0;
checkpoint_1:

cout<<endl<<setw(120)<<setfill('-')<<'-';

cout<<endl;
cout<<"Press:"<<endl<<"1. Order Food"<<endl<<"2. Exit"<<endl<<"Selection: ";
cin>>choice;

cout<<endl<<setw(120)<<setfill('-')<<'-';

switch(choice)
{

case 1:
    {
        cus_re:
        char elite[100];
        cout<<"\nSelect a cuisine:\n";
        ifstream oJ;
        oJ.open("menua.txt",ios::in);
        while(!oJ.eof())
        {
        oJ.getline(elite,100);
        cout<<endl<<elite;
        //memset(elite,'\0',100);
        }
        cout<<"6. Return to the main menu";
        cout<<"\nSelection: ";
        int cod;
        cin>>cod;
        char tem_nm[100],tem_prc[100];
        memset(tem_nm,'\0',100);
        memset(tem_prc,'\0',100);
        if(cod==1)
        {
            int vc,po=1;
            cout<<endl;
            ifstream sike;
            sike.open("southindian.txt",ios::in);
            while(!sike.eof())
            {
                sike.getline(tem_nm,100);
                cout<<po<<". ";
                ++po;
                for(vc=0;tem_nm[vc]!=':';++vc)
                {
                    cout<<tem_nm[vc];
                }
                cout<<"\t";
                for(int q=vc+1;tem_nm[q]!=':';++q)
                {
                    cout<<tem_nm[q];
                }
                cout<<endl;
            }
            int brv;
            cout<<"\nSelection: ";
            cin>>brv;
            sike.close();
        }
        else if(cod==2)
        {
           int vc,po=1;
            cout<<endl;
            ifstream sike;
            sike.open("mumbiamasala.txt",ios::in);
            while(!sike.eof())
            {
                sike.getline(tem_nm,100);
                cout<<po<<". ";
                ++po;
                for(vc=0;tem_nm[vc]!=':';++vc)
                {
                    cout<<tem_nm[vc];
                }
                cout<<"\t";
                for(int q=vc+1;tem_nm[q]!=':';++q)
                {
                    cout<<tem_nm[q];
                }
                cout<<endl;
            }
            int brv;
            cout<<"\nSelection: ";
            cin>>brv;
            sike.close();
        }
        else if(cod==3)
        {
            int vc,po=1;
            cout<<endl;
            ifstream sike;
            sike.open("mpstmespecial.txt",ios::in);
            while(!sike.eof())
            {
                sike.getline(tem_nm,100);
                cout<<po<<". ";
                ++po;
                for(vc=0;tem_nm[vc]!=':';++vc)
                {
                    cout<<tem_nm[vc];
                }
                cout<<"\t";
                for(int q=vc+1;tem_nm[q]!=':';++q)
                {
                    cout<<tem_nm[q];
                }
                cout<<endl;
            }
            int brv;
            cout<<"\nSelection: ";
            cin>>brv;
            sike.close();

        }
        else if(cod==4)
        {
            int vc,po=1;
            cout<<endl;
            ifstream sike;
            sike.open("beverages.txt",ios::in);
            while(!sike.eof())
            {
                sike.getline(tem_nm,100);
                cout<<po<<". ";
                ++po;
                for(vc=0;tem_nm[vc]!=':';++vc)
                {
                    cout<<tem_nm[vc];
                }
                cout<<"\t";
                for(int q=vc+1;tem_nm[q]!=':';++q)
                {
                    cout<<tem_nm[q];
                }
                cout<<endl;
            }
            int brv;
            cout<<"\nSelection: ";
            cin>>brv;
            sike.close();
        }
        else if(cod==5)
        {
            int vc,po=1;
            cout<<endl;
            ifstream sike;
            sike.open("chocolates.txt",ios::in);
            while(!sike.eof())
            {
                sike.getline(tem_nm,100);
                cout<<po<<". ";
                ++po;
                for(vc=0;tem_nm[vc]!=':';++vc)
                {
                    cout<<tem_nm[vc];
                }
                cout<<"\t";
                for(int q=vc+1;tem_nm[q]!=':';++q)
                {
                    cout<<tem_nm[q];
                }
                cout<<endl;
            }
            int brv;
            cout<<"\nSelection: ";
            cin>>brv;
            sike.close();
        }
        else if(cod==6)
        {
            cout<<"\nRedirecting back to main menu...";
            Sleep(1500);
            goto cus_re;
        }
        else
        {
            cout<<"\nInvalid input!\nTry again!\n";
            goto cus_re;
        }
        int yu;
        cout<<"\nSelect:-\n1. Proceed to Checkout\n2. Cancel Order\nSelection: ";
        cin>>yu;
        if(yu==1)
        {
            cout<<endl;
cout<<"Enter student SAP-ID: ";
cin>>sap_id;
cout<<endl;

cout<<"SAP-ID -----> "<<sap_id<<endl;

cout<<endl<<setw(120)<<setfill('-')<<'-';

sap_id_check();
break;
        }
        else
        {
            cout<<"\nCancelling Order...";
            Sleep(1200);
            break;
        }
    }

case 2:
    {
        return 0;
        break;
    }

default:
    {
        cout<<"Wrong input"<<endl;
        goto checkpoint_1;
    }

}
}
}
int sap_id_check()
{
ifstream input_stream("Name.txt",ios::in);
if(input_stream.fail())
{
cout<<"File not found"<<endl;
//return 0;
}
checkpoint_2:
while(!input_stream.eof())
{
input_stream.getline(ID,100);
for(i=0;(ID[i]!='\0')&&(ID[i]!=';');++i)
                   {
                       temp_id[i]=ID[i];
                   }
                if(sap_id==temp_id)
                {
display();
}
memset(temp_id,'\0',100);
}
}
void display()
{
for(j=i+1;ID[j]!=';';++j)
            {
                Name[k]=ID[j];
                k++;
            }
            cout<<endl;
        cout<<"NAME -----> "<<Name<<endl;
        for(l=j+1;ID[l]!=';';++l)
            {
                email_id[z]=ID[l];
                z++;
            }
        cout<<"E-MAIL ID -----> "<<email_id<<endl;
        cout<<endl<<setw(120)<<setfill('-')<<'-'<<endl;
        mail();
}
mail()
{
    here:
int c;
cout<<"PRESS:"<<endl<<"1.SEND MAIL"<<endl<<"2.EXIT"<<endl<<"\nSelection: ";
cin>>c;
switch(c)
{
case 1:
    {cout<<endl<<setw(120)<<setfill('*')<<'*';
cout<<setw(50)<<setfill(' ')<<' '<<"* MAIL SENT *";
cout<<endl<<setw(120)<<setfill('*')<<'*'<<endl;
break;
    }
case 2:
    {
        cout<<"Cancelling Order...";
        Sleep(1000);
        cout<<"\nExitting...";
        Sleep(800);
        return 0;
        break;
    }

default:
cout<<"\nInvalid Input\nTry again!\n";goto here;
}
}
};
int main()
{
    int gd = DETECT;
    int gm;

    initgraph(&gd, &gm, "");

    for(int i=9;i>4;i--)
    {

        if(i==5)
        {
            settextstyle(6, HORIZ_DIR,5);
            outtextxy(90,25,"MPSTME");
        }
        if(i==6)
        {
            settextstyle(5, HORIZ_DIR,5);
            outtextxy(90,25,"           Canteen");
        }
        if(i==7)
        {
            settextstyle(4, HORIZ_DIR,2);
            outtextxy(10,400,"Contact us: 1800 1025 138");
        }
        if(i==8)
        {

            settextstyle(4, HORIZ_DIR,2);
            outtextxy(170,420,"enquiry.mpstme@nmims.edu");
        }
    }
    re_heat:
    int heat;
    cout<<"\nSelect:-\n1. Administration login\n2. User login\nSelection: ";
    cin>>heat;
    if(heat==1)
    {
        renamer:
        string admin_usr="",admin_pass="";
        cout<<"\nEnter your username: ";
        cin>>admin_usr;
        if(admin_usr=="00000000000")
        {
            cout<<"\nAccount Found!";
            repeak:
            cout<<"\nEnter your password: ";
            cin>>admin_pass;
            if(admin_pass=="admin")
            {
                cout<<"\n\nWelcome Admin!";
                Sleep(1000);
                system("CLS");
                check obj;
                obj.input();
            }
            else
            {
                cout<<"\nInvalid Password!\nTry again!\n";
                goto repeak;
            }
        }
        else
        {
            cout<<"\nInvalid Username!\nTry again!";
            goto renamer;
        }


    }
    else if(heat==2)
    {
        cout<<endl<<endl;
        login log;
    log.account();
    int hour,mini,d,m,y,day;
            time_t my_time = time(NULL);
            struct tm nowLocal=*localtime(&my_time);

            hour=nowLocal.tm_hour;
            mini=nowLocal.tm_min;
            d=nowLocal.tm_mday;
            m=nowLocal.tm_mon+1;
            y=nowLocal.tm_year+1900;
            day=nowLocal.tm_wday;
            string hollywood;
hollywood=++log;
while(true)
{
system("CLS");
cout<<"Services provided\n1. New Order\n2. View Account details\n3. Access Wallet\n4. Logout\nSelection: ";
int sel;
cin>>sel;
string s1,tempo;
switch(sel)
{
    case 1:
        {
            meni obj_meni;
            obj_meni.walletfile(hollywood);
            s1=history(log);
            obj_meni.time(hour,mini,d,m,y,day);
            obj_meni.order(s1);
            //Sleep(10000);
            break;
        }
    case 2:
        {
            meni temp;
            temp.walletfile(hollywood);
            tempo=history(log);
            acc_det(log,temp,tempo);
            //Sleep(8000);
            break;
        }
    case 3:
        {

            //meni sake;
            log.walletfile(hollywood);
            log.time(hour,mini,d,m,y,day);
            log.display();
            //Sleep(10000);
            break;
        }
    case 4:
        {
            cout<<"\nLogging out...";
            Sleep(1500);
            cout<<"\nSuccessfully logged out!";

            //initwindow(1023,590);
            /*for(int i=0;i<1000;i++)
            {
                settextstyle(4, HORIZ_DIR,5);
                outtextxy(150,150,"THANK YOU");
                settextstyle(4, HORIZ_DIR,2);
                outtextxy(-170+i,420,"Made by: Maanaav, Dhyey & Aajinkya");
                delay(5);
                cleardevice();

            }*/



            return 0;
        }
    default:
        {
            cout<<"\nChecking...";
            Sleep(800);
            cout<<endl<<"Wrong Input!"<<endl;
            Sleep(1500);
        }
}

}
    }
    else
    {
        cout<<"\nInvalid Input!\nTry again!\n";
        goto re_heat;
    }




    return 0;
}
