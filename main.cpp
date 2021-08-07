#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstring>
#include<ctype.h>
#include<windows.h>
#define PASSWORD "abhishek"

using namespace std;
void adminsong();
void displaysong();
void deletesong();
void searchsong();
void modifyplaylist();
void usersongs();

const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;
const int LIGHTRED = 12;
const int GREENISH = 71;
const int LIGHTBLUE = 9;
const int YELLOW = 6;

class playlist
{
 public:
 string sname;
 char songnum[10];
 string sduration;
 string sartist;
 char playnum[10];
 string playname;
 string playduration;
 string playartist;

}s;

void changeColour(int colour) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
}

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void displaysong2(){
 fstream file;
 int i=0;
 file.open("songs.txt",ios::in);
 if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(1);
 }
 gotoxy(23,1);
 cout<<setw(15)<<"Song ID"<<setw(15)<<"Song Name"<<setw(20)<<"Song Duration"
     <<setw(18)<<"Artist"<<endl;
 gotoxy(23,2);
 for(i=0;i<75;i++)
    printf("-");
    cout<<"\n";
    i = 3;
 while((file.read((char*)&s,sizeof(s))))
{
  gotoxy(23,i++);
    cout<<setw(12)<<s.songnum<<setw(18)<<s.sname<<setw(15)<<s.sduration<<setw(22)<<s.sartist <<endl;
}
    file.close();
}





void landingpage()
{
    system("cls");
    gotoxy(30,6);
    //cout<<"**"<<endl;
    for(int i=0; i<62; i++){ Sleep(2);cout << char(88);}
    gotoxy(36,8);
    cout<<"\t   MUSIC PLAYLIST MANAGEMENT SYSTEM"<<endl;
    gotoxy(30,10);
    //cout<<"**\n";
    for(int i=0; i<62; i++){ Sleep(2);cout << char(88);}
    gotoxy(46,14);
    changeColour(GREEN);
    cout<<"Press any key to continue...";
    _getch();
    system("cls");
}

void adminsong(){
     fstream file;
     char test;
     file.open("songs.txt",ios::app);
     if(!file){
     changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
     exit(1);
 }
 displaysong2();
 cout<<"\n\n\n";
 while(1){
        changeColour(GREEN);
         cout<<"\n\n\n\n\t\t\t\t\t\t\t---- ADD SONG ----\n";
        changeColour(WHITE);

         cout<<"\n\t\t\t\t\t\tEnter the song ID: ";
         cin >> s.songnum;

         cout<<"\n\t\t\t\t\t\tEnter the song name: ";
         getline(cin >> ws, s.sname);

         cout<<"\n\t\t\t\t\t\tEnter the song duration: ";
         getline(cin >> ws, s.sduration);

         cout<<"\n\t\t\t\t\t\tEnter the song artist: ";
         getline(cin >> ws, s.sartist);

         file.write((char*)&s,sizeof(s));
         changeColour(GREEN);

         cout<<"\n\n\t\t\t\t\t\t---Record Entered Successfully---\n";
         changeColour(YELLOW);

         cout<<"\n\n\t\t\t\t    Press 'y' to add another record or any other key to go back. ";
         changeColour(WHITE);
             test=getche();
             system("cls");
             if(!(test==89 || test==121))
                break;
    }
 file.close();
}





void usersongs(){
    fstream file,temp;
    int i=0;
    char num[10];
    file.open("playlist.txt",ios::app);
if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(0);
}
temp.open("songs.txt",ios::out|ios::in);
if(!temp){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(0);
}
displaysong2();
changeColour(GREEN);
         cout<<"\n\n\n\n\t\t\t\t\t\t\t---- ADD SONG ----\n";
        changeColour(WHITE);
cout<<"\n\t\t\t\t\t\t       Enter the song ID: ";
cin>>num;
while((temp.read((char*)&s,sizeof(s))))
{
if(!(strcmp(s.songnum,num)))
{
 i=1;
 strcpy(s.playnum,s.songnum);
 s.playname = s.sname;
 s.playduration = s.sduration;
 s.playartist = s.sartist;
 file.write((char*)&s,sizeof(s));
 break;
 } else{
 file.write((char*)&s,sizeof(s));
        }
    }

    changeColour(GREEN);
         cout<<"\n\n\t\t\t\t\t\t---Song Added to the playlist---\n";
    changeColour(WHITE);
    changeColour(YELLOW);
    cout <<"\n\n\t\t\t\t\t\t   Press any key to continue..";
    changeColour(WHITE);
    getch();
    system("cls");
}







void displaysong(){
 fstream file;
 int i=0;
 file.open("songs.txt",ios::in);
 if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(1);
 }
 gotoxy(23,1);
 cout<<setw(15)<<"Song ID"<<setw(15)<<"Song Name"<<setw(20)<<"Song Duration"
     <<setw(15)<<"Artist"<<endl;
 gotoxy(23,2);
 for(i=0;i<75;i++)
    printf("-");
    cout<<"\n";
    i = 3;
 while((file.read((char*)&s,sizeof(s))))
{
  gotoxy(23,i++);
    cout<<setw(12)<<s.songnum<<setw(18)<<s.sname<<setw(15)<<s.sduration<<setw(20)<<s.sartist <<endl;
}
    file.close();
    changeColour(GREEN);
    gotoxy(47,i+3);
    cout<<"Press any key to continue..." <<endl;
    changeColour(WHITE);
    getch();
    system("cls");
}



 void displayplaylist(){
 fstream file;
 int i=0;
 file.open("playlist.txt",ios::in);
 if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(1);
 }
 gotoxy(23,1);
 cout<<setw(15)<<"Song ID"<<setw(15)<<"Song Name"<<setw(20)<<"Song Duration"<<setw(15)<<"Artist"<<endl;
 gotoxy(23,2);
 for(i=0;i<75;i++)
    printf("-");
    cout<<"\n";
    i = 3;
 while((file.read((char*)&s,sizeof(s))))
{
  gotoxy(23,i++);
    cout<<setw(12)<<s.playnum<<setw(18)<<s.playname<<setw(18)<<s.playduration<<setw(16)<<s.playartist<<endl;
}
    file.close();
    changeColour(GREEN);
    gotoxy(47,i+3);
    cout<<"Press any key to continue..." <<endl;
    changeColour(WHITE);
    getch();
    system("cls");
}

void displayplaylist2(){
 fstream file;
 int i=0;
 file.open("playlist.txt",ios::in);
 if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(1);
 }
 gotoxy(23,1);
 cout<<setw(15)<<"Song ID"<<setw(15)<<"Song Name"<<setw(20)<<"Song Duration"<<setw(15)<<"Artist"<<endl;
 gotoxy(23,2);
 for(i=0;i<75;i++)
    printf("-");
    cout<<"\n";
    i = 3;
 while((file.read((char*)&s,sizeof(s))))
{
  gotoxy(23,i++);
    cout<<setw(12)<<s.playnum<<setw(18)<<s.playname<<setw(18)<<s.playduration<<setw(16)<<s.playartist <<endl;
}
    file.close();
}


void deleteadminsong()
{
fstream file,temp;
    int i=0;
    char name[100];
    displaysong2();
    file.open("songs.txt",ios::out|ios::in);

if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
}
temp.open("temp.txt",ios::app);
if(!temp){
 cout<<"can not able to open file\n";
 exit(0);
}
    changeColour(GREEN);
    cout<<"\n\n\n\n\t\t\t\t\t\t      --- Delete Song ---\n";
    changeColour(WHITE);
    cout<<"\n\n\t\t\t\t\t     Enter the song ID to be deleted: ";
    cin >> name;
while((file.read((char*)&s,sizeof(s))))
{
if(!(strcmp(s.songnum,name)))
{
    i++;
    continue;
}
else
    temp.write((char*)&s,sizeof(s));
}

if(i==1)
{
 file.close();
 temp.close();
 remove("songs.txt");
 rename("temp.txt","songs.txt");
 remove("temp.txt");
 changeColour(GREEN);
 cout<<"\n\n\t\t\t\t     The entered song ID is found and deleted Successfully\n";
 changeColour(WHITE);
}else{
    changeColour(RED);
 cout<<"\n\n\t\t\t\t\t       The entered song ID is not found\n";
 changeColour(WHITE);
 remove("temp.txt");
}
    changeColour(GREEN);
    cout <<"\n\n\t\t\t\t\t\t  Press any key to continue..";
    changeColour(WHITE);
    getch();
    system("cls");
}



void deleteusersong()
{
fstream file,usertemp;
int i=0;
char name[100];

file.open("playlist.txt",ios::out|ios::in);

if(!file){
 changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
 exit(0);
}
usertemp.open("usertemp.txt",ios::app);
if(!usertemp){
 cout<<"can not able to open file\n";
 exit(0);
}
displayplaylist2();
changeColour(GREEN);
    cout<<"\n\n\n\n\t\t\t\t\t\t      --- Delete Song ---\n";
    changeColour(WHITE);
    cout<<"\n\n\t\t\t\t\t     Enter the song ID to be deleted: ";
cin >> name;
while((file.read((char*)&s,sizeof(s))))
{
if(!(strcmp(s.playnum,name)))
{
    i++;
    continue;
}
else
    usertemp.write((char*)&s,sizeof(s));
}

if(i==1)
{
 file.close();
 usertemp.close();
 remove("playlist.txt");
 rename("usertemp.txt","playlist.txt");
 remove("usertemp.txt");
 changeColour(GREEN);
 cout<<"\n\n\t\t\t\t     The entered song ID is found and deleted Successfully\n";
 changeColour(WHITE);
}else{
 changeColour(RED);
 cout<<"\n\n\t\t\t\t\t       The entered song ID is not found\n";
 changeColour(WHITE);
 remove("usertemp.txt");
}
    changeColour(YELLOW);
    cout <<"\n\n\t\t\t\t\t\t  Press any key to continue..";
    changeColour(WHITE);
    getch();
    system("cls");
}






void modifyrecord(){
 fstream file,temp;
    int i=0;
    char number[10];
    file.open("songs.txt",ios::out|ios::in);
    displaysong2();
if(!file){
     changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
     exit(0);
}
temp.open("temp.txt",ios::app);
if(!temp){
     cout<<"Cannot open file\n";
     exit(0);
}
    changeColour(GREEN);
    cout<<"\n\n\n\n\t\t\t\t\t\t\t --- MODIFY ---";
    changeColour(WHITE);
    cout<<"\n\n\n\t\t\t\t\t     Enter the song ID to be modified: ";
    cin>>number;
while((file.read((char*)&s,sizeof(s))))
{
if(!(strcmp(s.songnum,number)))
{
 i=1;
    changeColour(GREEN);
     cout<<"\n\n\t\t\t\t\t\t\t--Record Found--";
     changeColour(WHITE);
     cout<<"\n\n\t\t\t\t\t\t  Enter the new song ID: ";
     cin>>s.songnum;
     cout<<"\n\t\t\t\t\t\t  Enter the new song name: ";
     cin>>s.sname;
     cout<<"\n\t\t\t\t\t\t  Enter the duration: ";
     cin>>s.sduration;
     cout<<"\n\t\t\t\t\t\t  Enter the artist: ";
     cin>>s.sartist;
     temp.write((char*)&s,sizeof(s));
     continue;
 } else{
     temp.write((char*)&s,sizeof(s));
}
}
if(i==1)
{
     file.close();
     temp.close();
     remove("songs.txt");
     rename("temp.txt","songs.txt");
     remove("temp.txt");
     changeColour(YELLOW);
     cout<<"\n\n\t\t\t\t\t\t     The Record is modified.\n";
     changeColour(WHITE);
}else{
    changeColour(RED);
     cout<<"\n\n\t\t\t\t\t       The entered song ID is not found.\n";
     changeColour(WHITE);
     remove("temp.txt");
    }
    changeColour(GREEN);
    cout<<"\n\n\t\t\t\t\t\t  Press any key to continue..";
    changeColour(WHITE);
    getch();
    system("cls");
}



void searchsong()
{
    fstream file,file2;
    int i=0,j=0,key=0;
    char name[100];
    changeColour(GREEN);
    cout<<"\n\n\t\t\t\t\t\t\t---SEARCH---";
    changeColour(WHITE);
    cout <<"\n\n\t\t\t\t\t\t     1\) Admin Search" << endl
         <<"\n\t\t\t\t\t\t     2\) Playlist Search"<<endl;
    cout <<"\n\n\t\t\t\t\t\t      Enter choice: ";
    cin >> key;
if(key == 2){
    file.open("playlist.txt",ios::out|ios::in);
    if(!file){
        changeColour(RED);
        cout<<"\n\n\t\t\t\t\t\t     File does not exist\n";
        changeColour(WHITE);
    exit(0);}
    cout<<"\n\n\t\t\t\t\t    Enter the song name to be searched: ";
    cin>>name;
    while((file.read((char*)&s,sizeof(s))))
    {
        if(!(strcmp(s.playname.c_str(),name)))
        {
        i++;
        break;
        }
    }
        if(i==1){
                changeColour(GREEN);
                cout<<"\n\n\t\t\t\t\t\t     The record is found.";
        changeColour(WHITE);
        }

        else{
                changeColour(RED);
                cout<<"\n\n\t\t\t\t\t\t   The record is not present.";
                changeColour(WHITE);
        }
        changeColour(YELLOW);
        cout<<"\n\n\n\t\t\t\t\t\t Press any key to continue..";
        changeColour(WHITE);
        getch();
        system("cls");
    }


else{
    file2.open("songs.txt",ios::out|ios::in);
    if(!file){
            changeColour(RED);
    cout<<"\n\n\t\t\t\t\t\t   File does not exist\n";
        changeColour(WHITE);
    exit(0);}
    cout<<"\n\n\t\t\t\t\t  Enter the song name to be searched: ";
    cin>>name;
    while((file2.read((char*)&s,sizeof(s))))
    {
        if(!(strcmp(s.sname.c_str(),name)))
        {
        j++;
        break;
        }
    }
        if(j==1){
            changeColour(GREEN);
                cout<<"\n\n\t\t\t\t\t\t     The record is found.";
        changeColour(WHITE);
        }
        else
            {
                changeColour(RED);
                cout<<"\n\n\t\t\t\t\t\t   The record is not present.";
                changeColour(WHITE);
            }

        changeColour(YELLOW);
        cout<<"\n\n\n\t\t\t\t\t\t  Press any key to continue..";
        changeColour(WHITE);
        getch();
        system("cls");
    }
}




int main(){
string password;
int choice=0,key=0,count = 3;
    landingpage();
    system("cls");
    changeColour(WHITE);
 a:  gotoxy(45,1);
     cout << "MUSIC PLAYLIST MANAGEMENT SYSTEM"<<endl;


    gotoxy(49,3);
    cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    gotoxy(49,4);
    cout << char(179) << "       1.Admin       " << char(179) << endl;
    gotoxy(49,5);
    cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


    gotoxy(49,6);
    cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    gotoxy(49,7);
    cout << char(179) << "       2.User        " << char(179) << endl;
    gotoxy(49,8);
    cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

    gotoxy(49,9);
    cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    gotoxy(49,10);
    cout << char(179) << "       3.Exit        " << char(179) << endl;
    gotoxy(49,11);
    cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

    //cout << "1.Admin \n2.User\n3.Exit"<<endl;
    changeColour(GREEN);
    gotoxy(50,13);
    cout <<"Enter Your Choice: ";
    changeColour(WHITE);
    cin >> key;
    system("cls");

switch(key){
 b:  case 1: changeColour(LIGHTBLUE);
             gotoxy(50,15);
             cout << "Enter Password: ";
             changeColour(WHITE);
             cin >> password;
            system("cls");
                if( PASSWORD == password){
            while(1){
                changeColour(GREEN);
            gotoxy(53,1);
    admin:         cout <<"---- ADMIN ----"<<endl;
                changeColour(WHITE);
                gotoxy(49,3);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,4);
                cout << char(179) << "      1.Add Song     " << char(179) << endl;
                gotoxy(49,5);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


                gotoxy(49,6);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,7);
                cout << char(179) << "  2.Display Records  " << char(179) << endl;
                gotoxy(49,8);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

                gotoxy(49,9);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,10);
                cout << char(179) << "   3.Delete A Song   " << char(179) << endl;
                gotoxy(49,11);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

                gotoxy(49,12);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,13);
                cout << char(179) << "   4.Modify a File   " << char(179) << endl;
                gotoxy(49,14);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

                gotoxy(49,15);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,16);
                cout << char(179) << "  5.Search The File  " << char(179) << endl;
                gotoxy(49,17);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

                gotoxy(49,18);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,19);
                cout << char(179) << "  6.Go To User Menu  " << char(179) << endl;
                gotoxy(49,20);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
             /*cout<<"1.Add Song\n";
             cout<<"2.Display All Songs\n";
             cout<<"3.Delete A Song\n";
             cout<<"4.Search The File\n";
             cout<<"5.Go To User Menu\n";*/
             gotoxy(50,22);
             cout<<"Enter Your choice: ";
             cin>>choice;
             system("cls");
             switch(choice){
             case 1:adminsong();break;
             case 2:displaysong();break;
             case 3:deleteadminsong();break;
             case 4:modifyrecord();break;
             case 5:searchsong();break;
             case 6:goto a; break;
             default:cout<<"You entered invalid choice. Press any key to continue\n";
             _getch();
             }
            }
            }else{
                while(count>1){
                gotoxy(41,10);
                cout<<"Wrong Password ";
                changeColour(RED);
                cout <<"X";
                changeColour(WHITE);
                cout <<" ,Try Again "<<count-1 <<" more tries"<<endl;
                count--;
                goto b;
                }
                changeColour(RED);
                gotoxy(51,16);
                cout << "Are you the admin?" <<endl;
                changeColour(WHITE);
                goto a;
            }
    case 2: while(1){

                changeColour(YELLOW);
            gotoxy(53,1);
   user:          cout <<"---- USER ----"<<endl;
                changeColour(WHITE);
                gotoxy(49,3);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,4);
                cout << char(179) << "      1.Add Song     " << char(179) << endl;
                gotoxy(49,5);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


                gotoxy(49,6);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,7);
                cout << char(179) << "   2.Display Songs   " << char(179) << endl;
                gotoxy(49,8);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


                gotoxy(49,9);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,10);
                cout << char(179) << "   3.Delete A Song   " << char(179) << endl;
                gotoxy(49,11);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


                gotoxy(49,12);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,13);
                cout << char(179) << "  4.Search The File  " << char(179) << endl;
                gotoxy(49,14);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;

                gotoxy(49,15);
                cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
                gotoxy(49,16);
                cout << char(179) << "  5.Go To User Menu  " << char(179) << endl;
                gotoxy(49,17);
                cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
             /*changeColour(GREEN);
             cout <<"\n\n\nLogged in : USER"<<endl;
                changeColour(WHITE);
             cout<<"1.Add Song\n";
             cout<<"2.Display Playlist\n";
             cout<<"3.Delete Song\n";
             cout<<"4.Search Song\n";
             cout<<"5.Exit\n";*/
             gotoxy(50,20);
             cout<<"Enter your choice: ";
             cin>>choice;
             system("cls");
             switch(choice){
             case 1:usersongs();break;
             case 2:displayplaylist();break;
             case 3:deleteusersong();break;
             case 4:searchsong();break;
             case 5:goto a;
             default:cout<<"You've entered an invalid choice.Press any key to continue.\n";
             _getch();
            }
        }
    case 3: exit(0);
    default:cout<<"Enter valid Operation"<<endl;
    }
 }
