#include <iostream>
#include <cstring>
#include<stdlib.h>
#include<fstream>


using namespace std;

class student
{

string roll;
string GR;
string name;
string contactno;
 int marks;

public:
 student(){}
  void getdata();
  void display();
  void mark(int);
}s[101];
void student::mark(int m)
{
marks=m;

}
void student::getdata()
{

 //system("COLOR 70");
while(roll.size()!=6)
{ fflush(stdin);
  cout<<"\n\n\nEnter roll no.:";
getline(cin,roll);

if(roll.size()!=6){cout<<"\nReenter correct Roll number\n";}
}

  fflush(stdin);
  cout<<"Enter name:";
getline(cin,name);


while(GR.size()!=8)
{  fflush(stdin);
  cout<<"Enter GR No:";
getline(cin,GR);
if(GR.size()!=8){cout<<"\nReenter correct GR number\n";}

}
  while(contactno.size()!=10)
 { cout<<"Enter contact no:";
 fflush(stdin);
 getline(cin,contactno);
 if(contactno.size()!=10){cout<<"\nReenter correct Contact number\n";}
 }
  system("CLS");

}
void student::display()
{
  cout<<"\n---------------------------------------------------------------------------------\n";
  cout<<"\nRoll no      ::"<<roll;
  cout<<"\nName         ::"<<name;
  cout<<"\nGR no        ::"<<GR;
  cout<<"\nContact No   ::"<<contactno;
  cout<<"\nMarks        ::"<<marks;

  cout<<"\n----------------------------------------------------------------------------------\n";

}


class question
{
private:
string correctans;
string question;
string option1;
string option2;
string option3;
string option4;


public:
void getquestion();
void questdisplay();
int correction(string,int);
}q[101];

void question::getquestion()
{
fflush(stdin);
cout<<"\nEnter the question:";
getline(cin,question);
fflush(stdin);
cout<<"Enter option 1:";
getline(cin,option1);
fflush(stdin);
cout<<"Enter option 2:";
getline(cin,option2);
fflush(stdin);
cout<<"Enter option 3:";
getline(cin,option3);
fflush(stdin);
cout<<"Enter option 4:";
getline(cin,option4);
fflush(stdin);
cout<<"Enter correct answer:";
getline(cin,correctans);
return;

}
void question::questdisplay()
{
cout<<question<<"\n";
cout<<option1<<"\n";
cout<<option2<<"\n";
cout<<option3<<"\n";
cout<<option4<<"\n";
}

int question::correction(string answer,int total)
{
if(answer.compare(correctans)==0)
{
if(answer!="a"&&answer!="b"&&answer!="c"&&answer!="d")
{throw "Incorect Option Entered";}
  total++;
return total;
}
return total;
}




class exam
{
 public:
 void instructions();
}e;
void exam::instructions()
{

       cout<<"\n---------------------------------------------------------------------\n\n";
       cout<<"INSTRUCTIONS...........\n\n";
       cout<<"Total Questions = 10\n\n";
       cout<<"Enter the right option to answer\n\n";
       cout<<"Total Marks = 10\n\n";

       cout<<"Mark less than 5 , Fail\n\n";
       cout << "Good luck!\n";
       cout<<"----------------------------------------------------------------------\n\n";
       cout << "\n\n";



}

class studentlogin
{

string user;
string pass;
public:
void addlogin();
int validatelogin(string,string);
void viewID();
}sl[10],fc;



int studentlogin::validatelogin(string userID,string Password)
{
if(userID.compare(user)==0&&Password.compare(pass)==0)
{
cout<<"LOGIN SUCCESSFULL";
return 1;
}
return 0;
}



void studentlogin::addlogin()
{
fflush(stdin);
cout<<"\nEnter User ID for login:";
getline(cin,user);
fflush(stdin);
cout<<"Enter password for login:";
getline(cin,pass);
}

void studentlogin::viewID()
{
cout<<user<<"\t\t"<<pass<<"\n";

}




int main()
{int swtch,swtch1=0,swtch2,flag,flag1=0;
int i=0,z=0,y,x=0;
int j,Nq;
char ready;
string Answer,userID,password,fcuser,fcpass;
int n;

while(swtch!=3)
{
//---------------------COUNTS NUMBER OF RECORDS---------------------------------
fstream file;
file.open("count.txt",ios::in);
file>>i;
file.close();
//----------------------------------------------------
//NUMBER OF OF QUESTIONS
file.open("quescount.txt",ios::in);
file>>z;
file.close();

//------------------------------------------------
//Number of Student login IDs
file.open("logcount.txt",ios::in);
file>>x;
file.close();

//-----------------------------------------------
int total=0;



cout<<"\n\n\n\t\t\tLOGIN\n1)Student Login\t\t\t\t2)Faculty login\t\t\n\nChoose Option:-";
cin>>swtch;






switch(swtch)
{
case 1://STUDENT LOGI

cout<<"\nStudent login\n\n";
fflush(stdin);
cout<<"Enter User ID/Roll no:";
getline(cin,userID);
cout<<"Enter Password:";
getline(cin,password);

flag=0;
file.open("studentlogin.txt",ios::in);
for(y=0;y<x;y++)
{
file.read((char*)&sl[y],sizeof(sl[y]));
flag=sl[y].validatelogin(userID,password);
if(flag==1){break;}
}
file.close();


if(flag==0)
{
cout<<"\nACCESS DENIED\nYou have entered incorect User ID/Password\n";
break;
}

//------------------EXAM STARTS----------------------------------------------------------------
s[i].getdata();

cout<<"\nAre you ready to take the exam(y/n):";
cin>>ready;
if(ready=='y'||ready=='Y')
{e.instructions();

file.open("QUESTIONS.txt",ios::in);
for(n=0;n<z;n++)
{file.read((char*)&q[n],sizeof(q[n]));
q[n].questdisplay();
cout<<"\nYour Answer:";
fflush(stdin);
getline(cin,Answer);
try {
total=q[n].correction(Answer,total);}
catch (const char* msg)
{ cout<<msg;
 }
}
file.close();

cout<<"\n\n!! RESULT !!\n\nYOU HAVE SCORED  "<<total<<"/"<<z;

//---------------------WRITING RESULTS IN STUDENT FILE-----------------------------
file.open("studentinfo.txt",ios::app);
s[i].mark(total);
file.write((char*)&s[i],sizeof(s[i]));
file.close();
i++;
file.open("count.txt",ios::out);
file<<i;
file.close();
}

break;

//--------------------------------------------------------------------------------------------------------------------------------------

case 2://FACULTY LOGIN

fflush(stdin);
cout<<"\nEnter Faculty UserID: ";
getline(cin,userID);
fflush(stdin);
cout<<"Enter Faculty Password: ";
getline(cin,password);
 system("CLS");

file.open("facultylogin.txt",ios::in);
file.read((char*)&fc,sizeof(fc));
flag1=fc.validatelogin(userID,password);
file.close();

if(userID=="teacher"&&password=="teacher")
{
 cout<<"\n\nLOGIN SUCCESSFULL\n";
 flag1=1;
}
if(flag1==0)
{cout<<"\n\tACCESS DENIED\nYou have Entered wrong User Id/Password\n";
break;
}
//----------------------------LOGIN COMPLETE-------------------------------------------------------------

swtch1=0;
while(swtch1!=7)
{//NUMBER OF OF QUESTIONS
file.open("quescount.txt",ios::in);
file>>z;
file.close();

//------------------------------------------------
//Number of Student login IDs
file.open("logcount.txt",ios::in);
file>>x;
file.close();

//-----------------------------------------------

cout<<"\n\n\n1)View Result of students\t\t2)Add Questions\t\t\t3)Display All Question\n\n4)Add Student\t\t5)Display Login Details of Students\t\t6)Change faculty login\t\t7)Log Out\n\nChoose Option:-";
cin>>swtch1;
switch(swtch1)
{
 case 1:
//View Result
file.open("studentinfo.txt",ios::in);
for(j=0;j<i;j++)
{file.read((char*)&s[j],sizeof(s[j]));
s[j].display();
}
file.close();
break;



case 2:
cout<<"How many questions do you want to add:";
cin>>Nq;
file.open("QUESTIONS.txt",ios::app);
for(j=z;j<z+Nq;j++)
{
q[j].getquestion();
file.write((char*)&q[j],sizeof(q[j]));
}
z=z+Nq;
file.close();
file.open("quescount.txt",ios::out);
file<<z;
file.close();
break;




case 3:
cout<<"\nDisplaying All the questions\n";
file.open("QUESTIONS.txt",ios::in);
for(n=0;n<z;n++)
{file.read((char*)&q[n],sizeof(q[n]));
q[n].questdisplay();
cout<<"\n\n";
}
file.close();
break;




case 4:
 Nq=0;
 j=0;
cout<<"\nHow many students login ID do you want to add:";
cin>>Nq;
file.open("studentlogin.txt",ios::app);
for(j=x;j<x+Nq;j++)
{
sl[j].addlogin();
file.write((char*)&sl[j],sizeof(sl[j]));
}
x=x+Nq;
file.close();

file.open("logcount.txt",ios::out);
file<<x;
file.close();
break;





case 5:
j=0;
cout<<"Displaying login ID of students";
cout<<"\nUSER ID\t\tPassword\n";
file.open("studentlogin.txt",ios::in);
for(j=0;j<x;j++)
{
file.read((char*)&sl[j],sizeof(sl[j]));
sl[j].viewID();
}
file.close();
break;




case 6:
cout<<"\nChange faculty login\n";
cout<<"\nEnter New Faculty User ID and Password:";

file.open("facultylogin.txt",ios::out);
fc.addlogin();
file.write((char*)&fc,sizeof(fc));
cout<<"\n\nUSER ID AND PASSWORD CHANGED SUCCESSFULLY!!\n";
swtch1=7;
break;

case 7:
cout<<"\nLogging Out\n";
system("CLS");
break;





}
}
break;






default:
cout<<"Choose appropriate option";
break;

}




}



return 0;

}

