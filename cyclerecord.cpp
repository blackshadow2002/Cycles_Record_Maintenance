#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

class cycle
 {
   int warrant,Refno;
   float Price;
   char Modname[70],Descri[300];
   void assign()
   {
     if(Price>=5000&&Price<=8000)
       warrant=12;
     else if(Price>8000&&Price<=16000)
       warrant=18;
     else if(Price>16000)
       warrant=24;
   }
   public:
   void enterdetails()
   {
     cout<<"\nEnter Reference No.(4 digits only):";
     cin>>Refno;
     cout<<"\nEnter Model Name:";
     gets(Modname);
     cout<<"\nEnter Description:";
     gets(Descri);
     cout<<"\nEnter Price:";
     cin>>Price;
     assign();
   }
   void showdetails()
   {
     cout<<"\nReference No:- "<<Refno;
     cout<<"\n\nModel Name:- "<<Modname;
     cout<<"\n\nDescription:- "<<Descri;
     cout<<"\n\nPrice of the cycle(in Rs):- "<<Price;
     cout<<"\n\nWarranty Period(in months):-"<<warrant;
   }
   int getref()
   { return Refno; }
 }S;

 void apprecord()
 {
    ofstream fout;
    char ans='y';
    fout.open("cycle.dat",ios::binary||ios::app);
    fout.seekp(0,ios::end);
    while(ans=='y')
    {
      cout<<"\nEnter the details";
      S.enterdetails();
      fout.write((char*)&S,sizeof(S));
      cout<<"\nRecord added.";
      cout<<"\nWant to add more(y/n)...";
      cin>>ans;
    }
    fout.close();
  }

  void search()
  {
    int r;char found1='n';
    cout<<"\nEnter reference no:";
    cin>>r;
    ifstream f("cycle.dat",ios::binary);
    cout<<"\nTHE SEARCHED RESULTS ARE:";
    while(!f.eof())
    {
      f.read((char*)&S,sizeof(S));
      if(r==S.getref())
      {
	S.showdetails();
	found1='y';
	break;
      }
    }
    cout<<"\n\n";
    if(found1=='n')
    cout<<"\nReference No. not found:";
    f.close();
  }

  void main()
  {
    clrscr();
    int n;
    do
    {
      cout<<"\n       *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*   \n";
      cout<<"\n            HERCULES CYCLES FRANCHISE        \n";
      cout<<"\n       *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*   \n";
      cout<<"\n         CHOOSE YOUR REQUIREMENT:";
      cout<<"\n           1.ADD A RECORD OF CYCLE";
      cout<<"\n           2.SEARCH A CYCLE THROUGH REF.NO";
      cout<<"\n           3.Exit";
      cin>>n;
      switch(n)
      {
       case 1:apprecord();break;
       case 2:search();break;
       case 3:exit(0);break;
       default:"\nWrong choice";break;
      }
     }while(n>=1&&n<=3);
  }

