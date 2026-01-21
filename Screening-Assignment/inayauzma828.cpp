//inayauzma828@gmail.com

#include<bits/stdc++.h>
using namespace std;
int main(){
  string arr[2000];
  ifstream file("shakespeare.txt");
  string str;
  int counter = 0;
   while(getline(file, str)){
    arr[counter] = line; counter++;
   }
   
   srand(time(NULL));
   for(int i=1;i<=5;i++){
    cout << arr[rand() %10 + 1] << "\n";
   }
   
   string userInput;
   cout << "type any sentence here: ";
   time_t begin,end;
   time(&begin);
   getline(cin, userInput);
   time(&end);
   time_t duration = end-begin;
   
   int string_size = userInput.size();
   
   cout<< "Typing Speed: " << string_size/duration << "\n";
}