class Solution {
public:
    vector<int> buff;
    
    int count(vector<int>& nums, int begin, int mid, int end) {
        int ans = 0;
        int j = mid + 1;
        for (int i = begin; i <= mid; i++) {
            while (j <= end && nums[i] > nums[j] * 2LL) j++;
            ans += j - (mid + 1);
        }
        return ans;
    }
    
    void merge(vector<int>& nums, int begin, int mid, int end) {
        int i = begin;
        int j = mid + 1;
        for (int k = begin; k <= end; k++)
            buff[k] = (j > end || (i <= mid && nums[i] <= nums[j])) ? nums[i++] : nums[j++];
        for (i = begin; i <= end; i++) nums[i] = buff[i];
    }
    
    int sort(vector<int>& nums, int begin, int end) {
        if (begin < end) {
            int mid = (begin + end) / 2;
            int ans = sort(nums, begin, mid) + sort(nums, mid + 1, end) + count(nums, begin, mid, end);
            merge(nums, begin, mid, end);
            return ans;
        }
        else return 0;
    }
    
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        buff.resize(len);
        return sort(nums, 0, len - 1);
    }
};
