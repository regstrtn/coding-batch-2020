//siddhant.singh.2914@gmail.com
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string mytext,arr[2000],v2;
    int k=0,v3,l2;
    ifstream file("shakespeare.txt");
   if (file.is_open()) {
    while (getline(file, mytext)) {
        arr[k] = mytext;
        k++;
    }
    file.close();
}
time_t start , end;
cout << "Let's calculate your typing speed" << endl;
time(&start);
for(int i=0;i<5;i++)
{
v3 = rand() % 1396 ;
cout << arr[v3]<<endl;
a1 : getline(cin,v2);
if(v2!=arr[v3])
{
    cout << "Error : please check the sentence you typed" << endl;
    goto a1;
}
l2 += v2.size();
}
time(&end);
time_t timetaken = end - start;
cout << "Total characters : " << l2 << endl;
cout << "Time taken : "  << timetaken << " seconds" << endl;
cout << "Character count is " << (l2 * 60)/timetaken << "characters/minute" << endl;



}