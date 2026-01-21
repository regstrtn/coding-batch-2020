// numan.ejaz1897@gmail.com

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;


int main(){
    srand(time(0));
    std::fstream newfile;
    newfile.open("shakespeare.txt",std::ios::out | std::ios::in);
    string lines[2000];
    int count = 0;
    if (newfile.is_open()){ 
      string tp;
      while(getline(newfile, tp)){
         lines[count]=tp;
         count++;
      }
      newfile.close();
    }
    time_t begin, end;
    time_t elapsed = 0;
    int len_chars=0;
    string user_input;
    for (int j = 0; j < 5; j++){
        int rand_idx = int(count*(rand()/(RAND_MAX + 1.0)));
        string rand_line = lines[rand_idx];
        cout << "Rewrite the following line:\n" << rand_line << endl;
        time(&begin);
        getline(cin, user_input);
        time(&end);
        elapsed += (end-begin);
        len_chars += user_input.size();
        cout << endl;
    }
    cout << "Number of characters = " << len_chars << endl;
    cout << "Time taken  = " << elapsed << " seconds" << endl;
    cout << "Typing speed = " << len_chars*60.0/elapsed << " characters per minute " << endl;
}