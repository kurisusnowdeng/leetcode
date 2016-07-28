#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int prio(char c) {
		int p = 1;
		if (c == '*' || c == '/') p++;
		return p;
	}

	int getresult(int a, int b, char op) {
		int res = a;
		if (op == '+') {
			res = res + b;
		}
		else if (op == '-') {
			res = res - b;
		}
		else if (op == '*') {
			res = res * b;
		}
		else if (op == '/') {
			res = res / b;
		}
		return res;
	}

	int calculate(string s) {
		stack<int> opr;
		stack<char> op;
		while (!opr.empty()) {
			opr.pop();
		}
		while (!op.empty()) {
			op.pop();
		}

		int x = 0;
		char c;
		for (int i = 0; i < s.length(); i++) {
			c = s[i];
			if (c >= '0' && c <= '9') {
				x = x * 10 + c - 48;
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/'){ // + - * /
				opr.push(x);
				x = 0;
				while (!op.empty() && !(prio(c) > prio(op.top()))) {
					int a, b;
					int res;

					if (!opr.empty()) {
						b = opr.top();
						opr.pop();
					}
					else {
						return -1;
					}
					if (!opr.empty()) {
						a = opr.top();
						opr.pop();
					}
					else {
						return -1;
					}
					
					res = getresult(a, b, op.top());
					op.pop();

					opr.push(res);
				}
				op.push(c);
			}
		}

		opr.push(x);
		while (!op.empty()) {
			int a, b;
			int res;

			if (!opr.empty()) {
				b = opr.top();
				opr.pop();
			}
			else {
				return -1;
			}
			if (!opr.empty()) {
				a = opr.top();
				opr.pop();
			}
			else {
				return -1;
			}

			res = getresult(a, b, op.top());
			op.pop();

			opr.push(res);
		}

		return opr.top();
	}
};

int main() {
	Solution test;
	cout << test.calculate("3+2*2") << endl;
	cout << test.calculate("3+5/2") << endl;
	cout << test.calculate("3/2*2") << endl;
	cout << test.calculate("3-5/2") << endl;
	system("pause");
	return 0;
}