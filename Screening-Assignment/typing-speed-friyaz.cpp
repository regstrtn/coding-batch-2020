// faisalriyaz011@gmail.com

// Input string is not compared with the dispalyed string. Honesty from the user is assumed.

#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    string inputstring, displaystring;
    int totaltime = 0, totalchars = 0;
    
    for(int i = 0; i < 5; i++)
    {
        ifstream infile("shakespeare.txt");
        srand (time(NULL));
        int nth = rand() % 1390;

        for(int j = 0; j < nth; j++)
            getline(infile, displaystring);

        getline(infile, displaystring);
        cout<<displaystring;
        const clock_t begin_time = time(NULL);
        getline(cin, inputstring);
        totalchars += inputstring.size();
        totaltime += time(NULL) - begin_time;
    }
    
    cout<<"Total characters: "<<totalchars<<"\n";
    cout<<"Total time(secs): "<<totaltime<<"\n";
    cout<<"Characters per Minute: "<<(totalchars * 60.0)/totaltime;
    
    return 0;    
}
