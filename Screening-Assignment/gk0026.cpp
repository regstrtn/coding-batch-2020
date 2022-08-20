// GK0026@myamu.ac.in
//or
// kumarprince2510@gmail.com

#include <iostream>
#include <string>
#include <time.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
ifstream input_file;

int main(){
     int tt=0,tc=0;
     string line,typed;
     cout<<"you have to type the exact word shown on your screen consecutively:  \n\n\n";
     
     for(int i=0;i<5;i++){
     
        srand(time(0));         // to generate random on every loop
        int rn=rand()%1000;
        int j=0;
        
        input_file.open("shakespeare.txt");   //open txt file
        while(j++<rn)                       
        getline(input_file,line);
        getline(input_file,line);
        cout<<line<<endl;
        //cout<<rn<<endl;
        
        time_t start,stop;
        time(&start);           //start time in sec from jan 1 1970
        getline(cin,typed);
        tc+=typed.size();
        time(&stop);             //end time in sec from jan 1 1970
        
        double time_taken = double(stop - start);
        tt+=time_taken;
        input_file.close();
     }
     
     cout<<"\n\nTotal characters: "<<tc;
     cout<<"\nTotal time (secs): "<<tt;
     cout<<"\nCharacters per second: "<<(tc)/tt;
     cout<<"\nCharacters per Minute: "<<(tc*60)/tt;
     cout<<"\nCharacters per hour: "<<(tc*60*60)/tt<<endl;
     return 0;
     
 }
