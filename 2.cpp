#include <iostream>

using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* res = new ListNode((p1->val + p2->val) % 10);
		ListNode* head = res;
		int c = (p1->val + p2->val) / 10;
		p1 = p1->next;
		p2 = p2->next;
		while (p1 != NULL || p2 != NULL) {
			int x = c;
			if (p1 != NULL) {
				x += p1->val;
				p1 = p1->next;
			}
			if (p2 != NULL) {
				x += p2->val;
				p2 = p2->next;
			}
			cout << x << ",";
			c = x / 10;
			ListNode* buff = new ListNode(x % 10);
			cout << buff->val << endl;
			res->next = buff;
			res = res->next;
		}
		if (c > 0) {
			ListNode* buff = new ListNode(c);
			res->next = buff;
		}

		return head;
	}
};
