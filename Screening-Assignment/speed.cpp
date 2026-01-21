//khanparvez82.pk@gmail.com
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<fstream>
using namespace std;
int main()
{
    int i=0,v,j;
    double  minsperchar;

    string myText=" ";
	string lines[2000];
	string user;
	std::ifstream MyReadFile("shakespeare.txt");
	while(getline(MyReadFile,myText))
    {
	lines[i]=myText;
	i=i+1;

    }
    int size=0;
    time_t count=0;

    for(j=1;j<=5;j++)
    {
    srand (time(0));
    // Start measuring time
    time_t begin, end;
    time(&begin);

    v=rand() % i;
	cout<<"\n"<<lines[v]<<"\n";
	printf("\n");
	getline(cin, user);


			// Stop measuring time and calculate the elapsed time
    time(&end);
    time_t elapsed = end - begin;
    size=size+user.size();
    count=count+elapsed;
    }


    printf("\n\nOutput:\nTime measured: %ld seconds.\n", count);
    minsperchar=((double)(count))/((double)(size*60));
    cout<<"Total no.of characters: "<<size<<"\n";
    cout<<"Characters per minute :" <<minsperchar<<"\n";
    MyReadFile.close();
    return 0;

}
