//hamzakari043@gmail.com


#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int num_words(string sentence);
int main()
{
  string sentence;
  time_t starttime;
  time_t endtime;
  cout << "I am going to calculate the number of words per minute you can accomplish.\n";
  cout << " Please type:\nFare you well. Mark him. He is addressed. Are we all ready? Liberty!";
  cout<<endl<<endl<<"Press enter and then start typing...";
  cin.get();
  time(&starttime);
  getline(cin, sentence);
  time(&endtime);
  cout << "I took you this many whole seconds:" << endtime-starttime<<endl;
  cout<<"To type in the sentence: "<<sentence;
  return 0;
}
int num_words(string sentence)
{
  return 0;
}
