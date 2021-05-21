// dayanandpathak751@gmail.com
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
    string lines[2000];
    string line;
    ifstream infile("shakespeare.txt");
    int n = 0;
    while (getline(infile, line)) {
        lines[n++] = line;
    }

    srand(time(NULL));
    infile.close();     
	cout << "Typing speed checker : press any key to start...";
	getline(cin, line);
	int t = 5;
	long char_count = 0;
    auto start = high_resolution_clock::now();
	while(t--){
		string str;
		int rand_num = rand() % n;
		cout << lines[rand_num] << endl;
		getline(cin, str);
		char_count += str.length();
	}
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast <seconds> (stop - start);
	cout << "No of characters typed : " << char_count << endl;
	cout << "Time taken : " << duration.count() << " seconds" << endl;
	cout << "Typing speed : " << char_count * 60 / duration.count() << " characters / min" << endl;
}