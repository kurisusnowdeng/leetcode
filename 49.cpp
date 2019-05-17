class Solution {
public:

struct Node {
	char val;
	int idx;
	Node *left;
	Node *right;
};

void sort(string &s, int low, int high) {
	char pivot = s[(low + high) / 2];
	int i = low;
	int j = high;
	char temp;
	while (i <= j) {
		while (s[i] < pivot) ++i;
		while (s[j] > pivot) --j;
		if (i <= j) {
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			++i;
			--j;
		}
	}
	if (low < j) sort(s, low, j);
	if (i < high) sort(s, i, high);
}

Node *find(string &s, int i, Node *p) {
	if (i == s.length()) {
		return p;
	}
	Node *pre = p;
	Node *next = p->left;
	if (next == nullptr) {
		Node *new_p = new Node;
		new_p->idx = -1;
		new_p->val = s[i];
		new_p->left = nullptr;
		new_p->right = nullptr;
		next = new_p;
		pre->left = next;
	}
	else {
		while (next != nullptr && next->val != s[i]) {
			pre = next;
			next = next->right;
		}
		if (next == nullptr) {
			Node *new_p = new Node;
			new_p->idx = -1;
			new_p->val = s[i];
			new_p->left = nullptr;
			new_p->right = nullptr;
			next = new_p;
			pre->right = next;
		}
	}
	return find(s, i + 1, next);
}

void solve(string s, Node *r, vector<vector<string>> &a) {
	string buff = s;
	int len = buff.length();
	sort(buff, 0, len - 1);
	Node *p = find(buff, 0, r);
	if (p->idx < 0) {
		p->idx = a.size();
		vector<string> item;
		item.clear();
		a.push_back(item);
	}
	a[p->idx].push_back(s);
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	res.clear();

	Node *root = new Node;
	root->idx = -1;
	root->val = 0;
	root->left = nullptr;
	root->right = nullptr;

	for (auto str : strs) {
		solve(str, root, res);
	}

	return res;
}

};
