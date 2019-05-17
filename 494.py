class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        n = len(nums)
        cnt = 0
        s = []
        for x in nums:
            cnt += x
            s += [cnt]
        if S > cnt or S < -cnt:
            return 0
        
        f = [[0 for i in range(2 * cnt + 1)] for i in range(n)]
        pivot = cnt
        f[0][pivot + nums[0]] += 1
        f[0][pivot - nums[0]] += 1
        # print(0, f[0])
        for i in range(1,n):
            for j in range(-s[i], s[i] + 1):
                if j - nums[i] >= -s[i]:
                    f[i][pivot + j] += f[i - 1][pivot + j - nums[i]]
                if j + nums[i] <= s[i]:
                    f[i][pivot + j] += f[i - 1][pivot + j + nums[i]]
            # print(i, f[i])
        
        return f[n - 1][pivot + S]
        
