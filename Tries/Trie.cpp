#include <iostream>
#include <string> 
#include <cstring> 
#include <vector>

using namespace std; 

//Lecture 1: Tries

int N = 26; 

class Trie {
public: 
	Trie * arr[N]; 
	bool isleaf; 
	Trie() {
		int i = 0; 
		for(i=0;i<N;i++) arr[i] = NULL; 
		isleaf = false; 
	}

	void insert(string s) {
		int lens = s.size(): 
		int i = 0; 
		Trie * curr = this: 
		for(i=0;i<lens;i++) {
			int c = s[i] - 'a'; 
			if(curr->arr[c] ==  NULL) {
				curr->arr[c] = new Trie();  
			}
			curr = curr->arr[c]; 
		}
		curr->isleaf = 1; 
	}

	bool search(string s) {
		Trie * curr = this; 
		int i = 0, lens = s.size(); 
		for(i=0;i<lens;i++) {
			int c = s[i] - 'a'; 
			if(curr->arr[c] == NULL) return false; 
			else curr = curr->arr[c]; 
		}
		if(curr->isleaf) return true; 
		return false; 
	}
}

//driver program
int main() {
	vector<string> keys(5); 
	keys[0] = "brown";
	keys[1] = "fox"; 
	keys[2] = "jumped"; 
	keys[3] = "lazy"; 
	keys[4] = "quick"; 

	string s1 = "bear"; 
	string s2 = "quick";

	Trie tr(); 
	int i = 0; 
	for(i=0;i<keys.size();i++) tr.insert(keys[i]); 
	if(tr.search(s1)) cout<<"Found: "<<s1<<endl;
	if(tr.search(s2)) cout<<"Found: "<<s2<<endl;


}
