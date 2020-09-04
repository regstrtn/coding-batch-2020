//zarrar1607@gmail.com
/*
Creator: Misbah Zarrar
Github : https://github.com/zarrar1607/
*/
#include<bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#define BUFF_SIZE 2000

int main(){
    /*=================
    Input File
    ===================*/
    ifstream in("shakespeare.txt");
    string str;
    vector<string> Lines;
    while (getline(in, str)){
        if(str.size() > 0)
            Lines.push_back(str);
    }
    in.close();
    //for(string &line : Lines)
        //cout<<line<<endl;
    /*=================
    Display 5 Lines
    ===================*/
    int totalCharacters = 0;
    for(int i =0 ; i<5 ; i++){
        int r = rand() % BUFF_SIZE;
        cout<<Lines[r]<<endl;
        totalCharacters+=Lines.size();
    }
    /*=================
    Countdown 3 secs
    ===================*/
    cout << "\n--------------------Time Remaining--------------------\n";
    sleep(1);
    int counter = 3;
    while (counter >= 1){
        cout << "\r\t\t\t  " << counter << flush;
        sleep(1);
        counter--;
    }
    cout << "\n--------------------------GO--------------------------\n";
    /*=================
    Reading User Input
    ===================*/
    string input;
    clock_t Tstart, Tend;
    Tstart = clock();
    int noOfCharacters = 0;
    for(int i =0 ; i<5 ; i++){
        getline(cin,input);
        noOfCharacters+=input.size();
    }
    /*=================
    Displaying Result
    ===================*/
    Tend = clock();
    double seconds = (double)(Tend - Tstart) / CLOCKS_PER_SEC;

    cout << "\n========================RESULT========================\n";
    cout << "Number of characters typed: " << noOfCharacters <<"/" << totalCharacters << endl;
    cout << "Time taken to type        : " << seconds << " seconds" <<endl;
    cout << "Typing speed              : "<< (seconds/6)*60 << " words per minute"<<endl;
    cout << "          ****Note: Accuracy unknown****";
    cout << "\n======================================================\n";
    return 0;
}
