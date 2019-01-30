#include<iostream>
#include"conio.h"
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<windows.h>

using namespace std;
void bye_bye();
void initiate();
void welcome_screen();
void aid();
void call(char[]);
class music
{
private:
    char track_id[10];
    char track_name[20];
    char category[20];
    char marketing_brand[20];
    char year_of_release[15];
    int stock_record;
    float record_price;
public:
    void add_records();
    void enter_data();
    void enter_datas();
    void show_data();
    void search();
    void edit();
    void create();
    void view_data();
    void delete_record();
    void test();
    int check(char[]);
    char choice(char*);


}global;
void aid()
{


    cout<<""<<endl;
    cout<<"welcome to k2AT club"<<endl;
    cout<<"music planet"<<endl;
    cout<<""<<endl;
    cout<<"#####$$*****"<<endl;
    cout<<"------------"<<endl;
    cout<<"choose your option"<<endl;
    cout<<"------------"<<endl;
    cout<<"1-> add tracks "<<endl;
    cout<<"2-> view data from file "<<endl;
    cout<<"3-> search record(s) "<<endl;
    cout<<"4-> edit data "<<endl;
    cout<<"5-> delete records from file "<<endl;
    cout<<"6-> exit to program windows"<<endl;
    cout<<"------------------------------"<<endl;


}
int music::check(char rec[])
{
    ifstream mem5("MUworld",ios::binary);
    if(!mem5)
    {
        cout<<"not enough space";
        exit(0);
    }
    music checks;
    int k=0;
    mem5.seekg(0);
    while(mem5.read((char*)&checks,sizeof(checks)))
    {
        if(strcmp(checks.track_id,rec)==0)
        {
            k++;
            return k;

        }

    }
    mem5.close();
    return k;
}
void music::test()
{
    ifstream memo;
    memo.open("MUWORLD");
    memo.seekg(0,ios::end);
    int n;
    n=memo.tellg()/sizeof(global);
    cout<<"\n\t\t number of records present in the file are="<<n<<endl;
    cout<<"---------------------"<<endl;

}
void music::enter_data()
{
    cout<<"WELCOME TO MUSIC MILLENIUM"<<endl<<endl;
    chk:
        cout<<"ENTER TRACK's IDENTITY"<<endl;
        gets(track_id);
        if(check(track_id)>=1)
        {
            cout<<"The id entered already exists,please enter a new id"<<endl;
            goto chk;
        }
        cout<<"~Enter track's name"<<endl;
        gets(track_name);
        cout<<"~Enter track's category:AUDIO/VIDEO/MP3...."<<endl;
        gets(category);
        cout<<"~enter track's marketing board"<<endl;
        gets(marketing_brand);
        cout<<"~Enter track's year of release:22 july 2016 etc..."<<endl;
        gets(year_of_release);
        cout<<"~Enter track's stock"<<endl;
        cin>>stock_record;
        cout<<"~enter track's price"<<endl;
        cin>>record_price;
}
char music::choice(char*s)
{
    cout<<"\n MOFDIFY \t"<<s<<"\t"<<"Y/N";
    char ch;
    ch=getch();
    if((ch=='y')||(ch=='Y'))
        return 'Y';
    else
         return 'n';

}
void music::enter_datas()
{

    global.show_data();
    cout<<endl;
    if(choice("track's name")=='Y')
    {
        cout<<"\n ENTER TRACK's NAME"<<endl;
        gets(track_name);

    }
    cout<<endl;
    if(choice("CATEGORY")=='Y')
    {
        cout<<"\n ENTER NEW CATEGORY"<<endl;
        gets(category);
    }
    cout<<endl;
    {
        if(choice("MARKETING BRAND")=='Y')
        {
            cout<<"'\n ENTER NEW BRAND"<<endl;
            gets(marketing_brand);

        }
        cout<<endl;
        if(choice("TRACKS STOCK")=='Y')
        {
            cout<<"\n \tENTER NEW STOCK"<<endl;
            cin>>stock_record;

        }
        cout<<endl;
        if(choice("PRICE OF RECORD")=='Y')
        {
            cout<<"\n ENTER NEW PRICE"<<endl;
            cin>>record_price;

        }
        cout<<endl;
    }


    void music::show_data()
    {
        cout<<"***###***"<<endl<<endl;
        cout<<"~TRACK's identification"<<track_id<<endl;
        cout<<"~Track's name is"<<track_name<<endl;
        cout<<"~Track's category is"<<category<<endl;
        cout<<"~ track's marketing brand"<<marketing_brand<<endl;
        cout<<"~ track's year of release"<<year_of_release<<endl;
        cout<<"~Track's stock"<<stock_record<<endl;
        cout<<"~Track's price"<<record_price<<endl;

    }
    void music::create()
    {
        ifstream mem0;
        mem0.open("MUWORLD",ios::binary);
        mem0.close();

    }
    void music::search()
    {
        ifstream mem1;
        mem1.open("MUWORLD",ios::binary);
        if(!mem1)
        {
            cout<<"No space NO space";
            getch();
            exit(0);


        }
        int z=0;
        char searchh[10];
        char ch='y';
        while(ch=='y'||ch=='Y')
        {
            z=0;
            global.test();
            cout<<"enter tracks id to search:"<<endl;
            gets(searchh);
            mem1.close();
            mem1.open("MUWORLD");
            while(mem1.read((char*)&global,sizeof(global)))
                {
                    if(strcmp(global.track_id,searchh)==0)
                    {
                        cout<<"TRACK PRESENT IN THE FILE MEMORY"<<endl<<endl;
                        z++;

                    }

                }
                mem1.seekg(0);
                mem1.close();
                if(z==0)
                {
                    cout<<"No such track present,please enter id properly"<<endl;

                }
                cout<<"want to continue";
                cin>>ch;
                aid();

                  }
    }
    void music::view_data()
    {
        ifstream mem3;
        mem3.open("MUWORLD",ios::binary);
        if(!mem3)
        {
            cout<<"no space present";
            getch();
            exit(0);

        }
        global.test();
        char chy='y';
        int x=0;y=0;
        char choice1;
        char id[10];
        while(chy=='y'||chy=='Y')
        {
            mem3.seekg(0);
            aid(;
            cout<<"->Enter your choice"<<endl;
            cout<<"U->see record of choice"<<endl;
            cout<<"V-> all records"<<endl;
            cout<<"W->exit"<<endl;
            global.test();
            cout<<endl;
            cin>>choice1;
            switch(choice1)
            {
                case 'U';
                case 'u';
                x=0;
                mem3.close();
                mem3.open("MUWORLD");
                cout<<"Enter tracks id"<<endl;
                gets(id);
                while(mem3.read((char*)&global,sizeof(global)))
                {
                    if(strcmp(global.track_id,id)==0)
                    {
                        global.show_data();
                        x++;

                    }
                }
                mem3.seekg(0);
                mem3.close();
                if(x==0)
                    cout<<"no such id present,enter proper id";
                break;
                case 'V';
                case 'v';
                y=0;
                mem3.close();
                mem3.open("MUWORLD");
                while(mem3.read((char*)&global,sizeof(global)))
                {
                    global.show_data();
                    y++;

                }
                mem3.seekg(0);
                mem.close();
                if(y==0)
                    cout<<"NO DATA PRESENT"<<endl<<endl;
                braek;
                case 'W';
                case 'w';
                return;
                default:
                    cout<<"enter proper choice U or V";







            }
            mem3.close();
            cout<<endl;
            cout<<"want to continue";
            cin>>chy;

        }
        cout<<"press any key to continue";
        aid();
        getch();
    }


}

