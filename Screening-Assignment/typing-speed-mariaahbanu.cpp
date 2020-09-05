//mariaahbanu@gmail.com
//Mariah Banu

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <time.h>
using namespace std;

int main(){

    //Read File:
    string lines[1396];
    std::string line;
    std::ifstream file("shakespeare.txt");
    for(int i=0; getline(file, line); i++){
        lines[i]=line;
    }
    file.close();

    //Display, Time And Read 5 Random Lines:
    int charTyped=0;
    time_t begin, end;
    time(&begin);
    for(int i=0; i<5; i++){
        cout<<lines[rand()%1396]<<endl;
        getline(cin,line);
        charTyped+=line.size();
    }
    time(&end);

    //Calculate Values for Result:
    float elapsed = end - begin;
    float elapsedMin = elapsed/60.0;
    float speed = (charTyped/5)/elapsedMin;

    //Display Result:
    cout<<endl<<endl<<"----------------Result----------------";
    cout<<endl<<"You typed "<<charTyped<<" characters in "<<elapsed<<" seconds!";
    cout<<endl<<"Your typing speed is "<<speed<<" WPM."<<endl;
}

