// Miraan Ejaz: miraanejaz15@gmail.com

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h> 
#include <time.h>
#include <string>

using namespace std;

int main()
{
    string lines[1396];
	string quote;
	ifstream infile;
	infile.open("shakespeare.txt");  
    int n=0;
	while(getline(infile, quote))  
	  {
	     lines[n] = quote;
		 n++;
	  }
		
	srand(time(NULL));
	cout<<"Press any key to start checking your typing speed.";
	getline(cin, quote);
    int totalChar=0;
    time_t begin, end;
    time(&begin);
    for(int i=0; i<5; i++){
        cout<<lines[rand()%n]<<endl;
        getline(cin,quote);
        totalChar+=quote.size();
    }
    time(&end);
	
	time_t elapsed = end - begin;
	infile.close();
	cout<<"Total characters typed: "<<totalChar<<"\n";
    cout<<"Total time taken(in secs): "<<elapsed<<"\n";
    cout<<"Total characters typed per minute: "<<(totalChar * 60)/elapsed<<endl;
	return 0;
}
	
	

    
 
	
	