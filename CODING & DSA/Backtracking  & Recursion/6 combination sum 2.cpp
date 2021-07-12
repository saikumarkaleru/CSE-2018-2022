Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]






class Solution {
public:
    void fun(int index,vector<int>& arr, int target,vector<vector<int>> &ans,vector<int> &temp){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 or index>=arr.size())
            return;
        
        for(int i=index;i<arr.size();i++){
           if(i>index && arr[i]==arr[i-1])
            {
                continue;
            }
         
            temp.push_back(arr[i]);
            
            fun(i+1,arr,target-arr[i],ans,temp);
          
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
     vector<vector<int>> ans;
        vector<int> temp;
        fun(0, a, target,ans,temp);
        return ans;
        
    }
};