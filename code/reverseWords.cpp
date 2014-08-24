/*
1. split the string into words first, and then reverse
2. How to find the words? 
Each time, get the index of the first non-space character, and then get the word.
Pay attention to the boundary condition
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		vector<string> tokens;
		int index = 0;
		while(index <=(s.length()-1) && (index = s.find_first_not_of(" ", index))!=string::npos) {
			string tmp = "";
			int start = index;
			while(s[start]!=' '&&start<=(s.length()-1)) {
				tmp += s[start];
				start++;
			}
			tokens.push_back(tmp);
			index = start+1;
	   }
	   s.clear();
	   for (int i=tokens.size()-1; i>=0; i--) {
			if(i==tokens.size()-1) {
				s += tokens[i];
			} else {
				s += " " + tokens[i];
			}
		}
    }
};

int main()
{
	Solution sol;
	string s = " the sky is blue ";
	sol.reverseWords(s);
	cout << s << endl;
	return 0;
}



