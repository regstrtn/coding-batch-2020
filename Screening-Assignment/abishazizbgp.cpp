//abishazizbgp@gmail.com

//Assumptions: String input is correct

#include<iostream>
#include<fstream>
#include<string>
#include<time.h>

using namespace std;

int main()
{
    string line,str[2000],test,sen;
    int k,length=0;
    srand(time(NULL));
    ifstream myfile("shakespeare.txt");
    if (myfile.is_open())
    {
        for(int i=0;getline(myfile, line);i++)
        {
            str[i]=line;
        }
        myfile.close();
        time_t begin,end,timeDiff;
        cout<<"Typing speed Test"<<endl;
        time(&begin);
        for(int i=0;i<5;i++)
        {
            k=rand()%1396;
	    sen=str[k];
            cout<<sen<<endl;
            getline(cin,test);
            length+=test.size();
        }
        time(&end);
        timeDiff=end-begin;
        cout<<"Total characters typed: "<<length<<endl;
        cout<<"Total Time taken : "<<timeDiff<<" seconds"<<endl;
        cout<<"Character count: "<<(length*60)/timeDiff<<" /minute"<<endl;
    }
    else
        cout<<"Enable to open File"<<endl;
} 
