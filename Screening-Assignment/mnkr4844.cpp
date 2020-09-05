//mnkr4844@gmail.com
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h> 
#include <time.h>
#include <string>
using namespace std;
int main()
{
string lines[2000] ;
ifstream myfile("shakespeare.txt");
int x=0;
string messageVar;

time_t begin, end;
time(&begin);
while(!myfile.eof())
{
    getline(myfile, lines[x], '\n');
    x++;
}
int random;
double total_length = 0;
for(int i=0;i<5;i++){
random = rand() % 10 + 1;
cout<<lines[random]<<endl;
//cin.ignore();
getline(cin, messageVar);

total_length = total_length + messageVar.length();
}
time(&end);
time_t elapsed = end - begin;
double typespeed = total_length/elapsed;
cout <<"Time Taken :"<<elapsed <<"s"<< endl;
cout<<"Number of characters typed:"<<total_length<<endl;
cout<<"Number of characters typed per minute:"<<typespeed<<endl;

}
