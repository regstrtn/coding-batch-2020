//abdulaleemfaizan@gmail.com

#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include<ctime>
#include<time.h>

using namespace std;

int main()
{



    int countLines=0,i=0,n1,j=0,countChars=0;

    string lines,str[2000],inputStr;

    ifstream theFile("shakespeare.txt");



    while(getline(theFile,lines)){
            str[i]=lines;


        countLines+=1;//to Know the number of lines//1394

        i++;
    }



    time_t start ,finish;

    time(&start);



    while(j!=5){//Runs for 5 times giving the user 5 sentences to type

    n1=rand() % countLines;

    cout<<str[n1]; //outputs any random line

    cout<<"\nEnter the sentence which you see:\n";

    getline(cin,inputStr);

    countChars+=inputStr.size();

    j++;

    }

    time(&finish);

    time_t seconds=(finish-start);//per sec

    cout<<"The number of characters you have typed are "<<countChars<<".\n";

    cout<<"your typing speed is ";

    printf("%ld seconds.",seconds);



    theFile.close();

    return 0;
}
