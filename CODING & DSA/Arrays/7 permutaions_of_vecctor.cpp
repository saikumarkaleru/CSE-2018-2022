//https://leetcode.com/problems/permutations/

/*
void possible_permute(vector<vector<int>> &res, vector<int>& nums, int start_idx) {
        
        if(start_idx == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        
        for (int idx = start_idx; idx < nums.size(); idx++) {
            swap(nums[idx], nums[start_idx]);
            possible_permute(res, nums, start_idx + 1);
            swap(nums[idx], nums[start_idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        possible_permute(res, nums, 0);
        
        return res;
    }

    */

