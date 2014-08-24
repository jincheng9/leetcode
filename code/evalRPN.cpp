/*
Reverse Polish Notation: Use Stack in STL
two operations: push, pop
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		int len = tokens.size();
		stack<string> s;
		for (int i=0; i<=len-1; i++) {
			if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
				s.push(tokens[i]);
			} else {
				string operand1 = s.top();
				int op1 = atoi(operand1.c_str());
				s.pop();
				string operand2 = s.top();
				int op2 = atoi(operand2.c_str());
				s.pop();
				stringstream ss;
				if(tokens[i]=="+") {
					int res = op1+op2;
					ss << res;
					s.push(ss.str());
				}
				if(tokens[i]=="-") {
					int res = op2-op1;
					ss << res;
					s.push(ss.str());
				}
				if(tokens[i]=="*") {
					int res = op1*op2;
					ss << res;
					s.push(ss.str());
				} 
				if(tokens[i]=="/") {
					int res = op2/op1;
					ss << res;
					s.push(ss.str());
				}
			}
		}
		return atoi(s.top().c_str());
	}
};

int main()
{
	Solution s;
	vector<string> tokens;
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	cout << s.evalRPN(tokens) << endl;
	return 0;
}
