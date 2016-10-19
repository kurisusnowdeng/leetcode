class Solution {
private:
	int *hash;
	int *idx;
	int q;
public:
	void push(int x, int i) {
		int key = ((x % q) * (x % q)) % q;
		while (idx[key] >= 0) {
			key = (key + 1) % q;
		}
		hash[key] = x;
		idx[key] = i;
	}

	int find(int x) {
		int key = ((x % q) * (x % q)) % q;
		while (hash[key] != x) {
			if (idx[key] < 0) {
				return -1;
			}
			key = (key + 1) % q;
		}
		return idx[key];
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		res.clear();
		q = (nums.size() << 1) + 1;
		hash = new int[q];
		idx = new int[q];
		memset(hash, 0xff, sizeof(int) * q);
		memset(idx, 0xff, sizeof(int) * q);
		for (int i = 0; i < nums.size(); i++) {
			push(nums[i], i);
		}
		for (int i = 0; i < nums.size(); i++) {
			int j = find(target - nums[i]);
			if (j >= 0 && j != i) {
				res.push_back(i);
				res.push_back(j);
				break;
			}
		}
		delete[] hash;
		delete[] idx;
		return res;
	}
};
