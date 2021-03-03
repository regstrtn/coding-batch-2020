// raashid12anwar@gmail.com

/*
  In the name of ALLAH
  Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;

mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

int main() {
  string words[2000], read;
  int Total_characters = 0, Total_time = 0;
  ifstream infile("shakespeare.txt");
  for(int i = 0; i < 2000; i++)
    infile >> words[i];
  for(int i = 0; i < 5; i++) {
    int random = rng() % 7;
    cout << words[random] << "\n";
    time_t before_type, after_type;
    before_type = time(NULL);
    cin >> read;
    after_type = time(NULL);
    Total_time += after_type - before_type;
    Total_characters += (int)words[random].size();
  }
  cout << "Total number of characters you typed : " << Total_characters << "\n";
  cout << fixed << setprecision(4) << "Characters per minute speed : " << (double(Total_time) / 60.0) << "\n";
}
