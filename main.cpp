#include<iostream>
#include<conio.h>
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
class Music
{
private:
    char Track_Id[10];
    char Track_Name[20];
    char Category[20];
    char Marketing_Brand[20];
    char Year_of_release[15];
    int Stock_record;
    float Record_Price;
public:
    void add_records();
    void enter_data();
    void enter_datas();
    void show_data()

    {
        cout<<"***###***"<<endl<<endl;
        cout<<"~TRACK's identification"<<Track_Id<<endl;
        cout<<"~Track's name is"<<Track_Name<<endl;
        cout<<"~Track's category is"<<Category<<endl;
        cout<<"~ track's marketing brand"<<Marketing_Brand<<endl;
        cout<<"~ track's year of release"<<Year_of_release<<endl;
        cout<<"~Track's stock"<<Stock_record<<endl;
        cout<<"~Track's price"<<Record_Price<<endl;

    }
    void search();
    void edit();
    void create()
    {
        ifstream mem0;
        mem0.open("MUWORLD",ios::binary);
        mem0.close();

    };
    void view_data();
    void delete_record();
    void test();
    int check(char[]);
    char Choice(char*);


}global;
void aid()
{

//clrscr();
    cout<<"--------------------"<<endl;
    cout<<"welcome to k2AT club"<<endl;
    cout<<"Music planet"<<endl;
    cout<<"---------------"<<endl;
    cout<<"#####$$*****"<<endl;
    cout<<"------------"<<endl;
    cout<<"Choose your option"<<endl;
    cout<<"------------"<<endl;
    cout<<"1-> Add Tracks "<<endl;
    cout<<"2-> View data from file "<<endl;
    cout<<"3-> Search record(s) "<<endl;
    cout<<"4-> Edit data "<<endl;
    cout<<"5-> Delete records from file "<<endl;
    cout<<"6-> Exit to program windows"<<endl;
    cout<<"------------------------------"<<endl;


}
int Music::check(char rec[])
{
    ifstream mem5("MUWORLD",ios::binary);
    if(!mem5)
    {
        cout<<"not enough space";
        exit(0);
    }
    Music checks;
    int k=0;
    mem5.seekg(0);
    while(mem5.read((char*)&checks,sizeof(checks)))
    {
        if(strcmp(checks.Track_Id,rec)==0)
        {
            k++;
            return k;

        }

    }
    mem5.close();
    return k;
}
void Music::test()
{
    ifstream memo;
    memo.open("MUWORLD");
    memo.seekg(0,ios::end);
    int n;
    n=memo.tellg()/sizeof(global);
    cout<<"\n\t\t number of records present in the file are="<<n<<endl;
    cout<<"---------------------"<<endl;

}
void Music::enter_data()
{
    cout<<"WELCOME TO MUSIC MILLENIUM"<<endl<<endl;
    chk:
        cout<<"ENTER TRACK's IDENTITY"<<endl;
        gets(Track_Id);
        if(check(Track_Id)>=1)
        {
            cout<<"The Id entered already exists,please enter a new Id"<<endl;
            goto chk;
        }
        cout<<"~Enter track's name"<<endl;
        gets(Track_Name);
        cout<<"~Enter track's category:AUDIO/VIDEO/MP3...."<<endl;
        gets(Category);
        cout<<"~enter track's marketing board"<<endl;
        gets(Marketing_Brand);
        cout<<"~Enter track's year of release:22 july 2016 etc..."<<endl;
        gets(Year_of_release);
        cout<<"~Enter track's stock"<<endl;
        cin>>Stock_record;
        cout<<"~enter track's price"<<endl;
        cin>>Record_Price;
}
char Music::Choice(char*s)
{
    cout<<"\n MOFDIFY \t"<<s<<"\t"<<"Y/N";
    char ch;
    ch=getch();
    if((ch=='y')||(ch=='Y'))
        return 'Y';
    else
         return 'n';

}
void Music::enter_datas()
{
//clrscr();
    global.show_data();
    cout<<endl;
    gotoxy(25,25);
    if(Choice("track's name")=='Y')
    {
        cout<<"\n ENTER TRACK's NAME"<<endl;
        gets(Track_Name);

    }
    cout<<endl;
    if(Choice("CATEGORY")=='Y')
    {
        cout<<"\n ENTER NEW CATEGORY"<<endl;
        gets(Category);
    }
    cout<<endl;
    {
        if(Choice("MARKETING BRAND")=='Y')
        {
            cout<<"'\n ENTER NEW BRAND"<<endl;
            gets(Marketing_Brand);

        }
        cout<<endl;
        if(Choice("TRACKS STOCK")=='Y')
        {
            cout<<"\n \tENTER NEW STOCK"<<endl;
            cin>>Stock_record;

        }
        cout<<endl;
        if(Choice("PRICE OF RECORD")=='Y')
        {
            cout<<"\n ENTER NEW PRICE"<<endl;
            cin>>Record_Price;

        }
        cout<<endl;
    }




void Music::search()
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
            cout<<"Enter tracks Id to search:"<<endl;
            gets(searchh);
            mem1.close();
            mem1.open("MUWORLD");
            while(mem1.read((char*)&global,sizeof(global)))
                {
                    if(strcmp(global.Track_Id,searchh)==0)
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
    void Music::view_data()
    {
        ifstream mem3;
        mem3.open("MUWORLD",ios::binary);
        if(!mem3)
        {
            cout<<"No space present";
            getch();
            exit(0);

        }
        global.test();
        char chy='y';
        int x=0;y=0;
        char choice1;
        char Id[10];
        while(chy=='y'||chy=='Y')
        {
            mem3.seekg(0);
            aid();
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
                cout<<"Enter tracks Id"<<endl;
                gets(Id);
                while(mem3.read((char*)&global,sizeof(global)))
                {
                    if(strcmp(global.Track_Id,Id)==0)
                    {
                        global.show_data();
                        x++;

                    }
                }
                mem3.seekg(0);
                mem3.close();
                if(x==0)
                    cout<<"No such Id present,enter proper Id";
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
                mem3.close();
                if(y==0)
                    cout<<"NO DATA PRESENT"<<endl<<endl;
                break;
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





