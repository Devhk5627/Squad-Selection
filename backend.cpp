#include<fstream>
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
//ADMIN PASS: admin
class squad
{
    char names[4][200];
    string oper[4];
public:
    friend istream &operator>>(istream &in,squad &s);
    friend ostream &operator<<(ostream &out,squad &s);
    void assign_op();
};
istream &operator>>(istream &in,squad &s)//INPUT DETAILS OF SQUAD MEMBERS
{
    for(int i=0;i<4;i++)
    {
        cout<<"Enter Name of Squad Member "<<i+1;
        cin>>s.names[i];
    }
}
ostream &operator<<(ostream &out,squad &s)//OUTPUT DETAILS OF SQUAD MEM AND ASSIGNED OPERATORS
{
    for(int i=0;i<4;i++)
    {
        cout<<"\nMember Name:"<<s.names[i];
        cout<<"\nOperator Assigned :"<<s.oper[i];
    }
}
void squad::assign_op()//FUNCTION TO ASSIGN OPERATORS
{

    char line[20][20];
    int counter=0,x=0;
    int a;
    ifstream File("Character.txt");
    while(!File.eof())
    {
        File>>line[x];
        counter++;
        x++;
    }

    for(int i=0;i<4;i++)
    {
        a=rand()%10;
        //File.seekg(a,File.beg);
        //File>>oper[i];
        oper[i]=line[a];
    }
}
void add()//ADMIN FUNC::ADD NEW OPERATOR TO FILE
{
    ofstream f1;
    f1.open("Character.txt",ios::app);
    char name[20];
    cout<<"Enter Operator Name you want to add";
    cin>>name;
    f1<<"\n";
    f1<<name;
    f1.close();
}
void rem()//ADMIN FUNC::REMOVE OPERATOR FROM FILE
{
    char name[20];
    cout<<"Enter Name you want to remove from list";
    cin>>name;
    ifstream f1("Character.txt");
    ofstream f2;
    f2.open("temp.txt", ofstream::out);
    string a;
    while(!f1.eof())
    {
        getline(f1,a);
        if(a!=name)
        f2<<a;
        f2<<"\n";
    }
     f2.close();
     f1.close();
     remove("Character.txt");
     rename("temp.txt","Character.txt");

}
main()
{
    srand(time(NULL));
    int x,y,z,i=0;
    char pwd[10],a,c;
    //MAIN MENU
    do{
    Main:
     system("cls");
    cout<<"***********MENU*************"<<endl;
    cout<<"1.ADMIN"<<endl;
    cout<<"2.USER"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"Enter option [1/2/3]"<<endl;
    cin>>x;
    switch(x)
    {
    case 1:
        {
            char d;
            cout<<"Enter password ";
            while(i<5)
            {
            pwd[i]=getch();
            cout<<"*";
            ++i;
            }
            getch();
            if(strcmpi(pwd,"admin")==0)
            {
            do
            {
            //ADMIN MENU
            system("cls");
            cout<<"********ADMIN MENU********"<<endl;
            cout<<"1.ADD OPERATOR"<<endl;
            cout<<"2.REMOVE OPERATOR"<<endl;
            cout<<"3.Main Menu"<<endl;
            cout<<"Enter Choice"<<endl;
            cin>>y;
            switch(y)
            {
            case 1:
                {
                add();
                break;
                }
            case 2:
                rem();
                break;
            case 3:
                goto Main;
                break;
            default:
                cout<<"Wrong option";

            }
            cout<<"Do you want to continue using Admin Menu";
            cin>>d;
            }while(d=='y'||d=='Y');
            }
            break;
        }
    case 2:
        {
        squad s;
        cin>>s;
        s.assign_op();
        cout<<s;
        break;
        }
    case 3:
        {
            exit(0);
            break;
        }
    default:
            cout<<"Wrong Option Chosen";
            break;
    }
    cout<<"\nDo you want to continue";
    cin>>c;
    }while(c=='y'||c=='Y');

}
