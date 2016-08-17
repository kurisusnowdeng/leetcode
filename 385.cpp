#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
private:
	int value;
	bool flag;
	vector<NestedInteger> list;
public:
	// Constructor initializes an empty nested list.
	NestedInteger() {
		value = 0;
		flag = false;
		list.clear();
	}

	// Constructor initializes a single integer.
	NestedInteger(int value) {
		this->value = value;
		this->flag = true;
		list.clear();
	}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const {
		return flag;
	}

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const {
		return value;
	}

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value) {
		this->value = value;
		this->flag = true;
	}

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni) {
		list.push_back(ni);
	}

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const {
		return list;
	}
};

class Solution {
public:
	NestedInteger deserialize(string s) {
		int x = 0;
		int base = 1;
		bool num = true;
		stack<NestedInteger*> st;
		NestedInteger* cur = NULL;
		while (!st.empty()) {
			st.pop();
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') {
				num = false;
				cur = new NestedInteger();
				x = 0;
				base = 1;
				st.push(cur);
			}
			else if (s[i] == ',' || s[i] == ']') {
				if (num) {
					NestedInteger buff = NestedInteger(x);
					st.top()->add(buff);
				}
				if (s[i] == ']') {
					cur = st.top();
					st.pop();
					if (!st.empty()) {
						st.top()->add(*cur);
					}
					else {
						st.push(cur);
					}
				}
				x = 0;
				base = 1;
				num = false;
			}
			else if (s[i] == '-') {
				base = -1;
				num = false;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				x = x * 10 + base * (s[i] - 48);
				num = true;
			}
		}
		if (num) {
			NestedInteger* buff = new NestedInteger(x);
			st.push(buff);
		}

		return *(st.top());
	}
};

int main() {
	NestedInteger result;
	Solution test;
	result = test.deserialize("[123,[456,[789]]]");
	result = test.deserialize("324");
	result = test.deserialize("000");
	result = test.deserialize("-324");
	result = test.deserialize("[[-456,[789]],-123]");
	return 0;
}