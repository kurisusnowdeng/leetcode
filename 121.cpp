class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> f(prices.size());
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (prices[i] > prices[j]) {
                    if (f[i] < f[j] + prices[i] - prices[j])
                        f[i] = f[j] + prices[i] - prices[j];
                }
            }
        }
        int max = 0;
        for (int x : f) {
            max = x > max ? x : max;
        }
        return max;
    }
};
