//manvisingh.alwar@gmail.com

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string line,str[1500],test,sen;
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
        cout<<"**Typing Speed Test**"<<endl;
        time(&begin);
        int i=0;
        while(i<5)
        {
            k=rand()%1396;
            sen=str[k];
            cout<<sen<<endl;
            getline(cin,test);
            length+=test.size();
            i++;
        }
        time(&end);
        timeDiff=end-begin;
        cout<<"Characters typed: "<<length<<endl;
        cout<<"Time taken : "<<timeDiff<<" seconds"<<endl;
        cout<<"Character count: "<<(length*60)/timeDiff<<" /minute"<<endl;
    }
    else
        cout<<"OOPS SOME ERROR...."<<endl;
}
