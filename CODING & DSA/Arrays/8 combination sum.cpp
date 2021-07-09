
/* https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.




*/


class Solution {
    
    void fun( int pos,vector<int>& arr, int target,vector<int> &temp, vector<vector<int>> &ans){
        
        if(target==0){
            ans.push_back(temp);
        }
        if(pos==arr.size() or target<0){
            return;
        }
        for(int i=pos;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            fun(i,arr,target-arr[i],temp,ans);
            temp.pop_back();
        }
    
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
         vector<vector<int>> ans;
         vector<int> temp;
        fun(0,candidates,target,temp,ans);
        return ans;
    
    }
};