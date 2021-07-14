Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        int n  = nums.size();
        int k = factorial(n);
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            vec.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }
        return vec;
    }
    int factorial(int n)
    {
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    }




    class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        arr = []
        def permu(nums, c, arr, path):
            if c >= len(nums):
                arr.append(path)
                return
            for num in nums:
                if num not in path:
                    permu(nums, c+1, arr, path + [num])
        permu(nums, 0, arr, [])
        return arr
        



