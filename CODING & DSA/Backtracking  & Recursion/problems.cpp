You can apply this structure to many other backtracking problem, I'll add more question in the future.
Permutations : https://leetcode.com/problems/permutations/

class Solution {
public:
    
    void solve(int pos, vector<int> &num, vector<vector<int>> &result){
        if(pos == num.size()){
            result.push_back(num);
        }
        else{
            for(int i=pos; i<num.size(); i++){
                swap(num[i], num[pos]);
                solve(pos+1, num, result);
                swap(num[i], num[pos]);
            }
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums, ans);
        return ans;
    }
};
Permutations II (contains duplicates) : https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permutations;
    
    void permute(vector<int>& nums, int start){
        
        if (start == nums.size())  permutations.push_back(nums); 
        unordered_set<int> seen;  
        for (int i = start; i < nums.size(); i++) {
            if (seen.find(nums[i]) == seen.end()) {
                swap(nums[start], nums[i]);
                permute(nums, start+1);
                swap(nums[start], nums[i]);  // backtrack
                seen.insert(nums[i]); 
            }
        }
    }

    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() < 2)  return {nums}; 
        permute(nums, 0);
        return permutations;
    }
};
Subsets : https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> powerset;
    vector<int> sets;
    
    void generateSets(vector<int>& nums, int index){
        powerset.push_back(sets);
        for(int i=index; i< nums.size(); i++){
            sets.push_back(nums[i]);
            generateSets(nums, i+1);
            sets.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        generateSets(nums, 0);
        return powerset;
    }
};
Subsets II (contains duplicates) : https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> powerset;
    vector<int> sets;
    
    void generateSets(vector<int>& nums, int index){
        powerset.push_back(sets);
        for(int i=index; i< nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue; // skip duplicates
            sets.push_back(nums[i]);
            generateSets(nums, i+1);
            sets.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generateSets(nums,0);
        return powerset;
    }
};







PRINT SUBSEQUENCES:


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int 
void subsequences(vector<int> arr,int i,int n,vector<int> &temp)
{
    if(i==n)
    {
       for(int i:temp) cout<<i<<" ";
       cout<<endl;
        return;
    }
    temp.push_back(arr[i]);
    subsequences(arr,i+1,n,temp);
    temp.pop_back();
    subsequences(arr,i+1,n,temp);  
}
int32_t main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/welcome/Desktop/coding_stuf/codeforces/input.txt", "r", stdin);
        freopen("C:/Users/welcome/Desktop/coding_stuf/codeforces/output.txt", "w", stdout);
    #endif         
       int test=1; 
       cin>>test;
       for(int tt=1;tt<=test;tt++) {
        //cout<<" #"<<"test case #"<<i<<endl;
          //cout<<"case #"<<tt<<": \n";
          int n;
          cin>>n;
         vector<int>arr(n);
       for(int i=0;i<n;i++) {
           arr[i]=i;
       }
        vector<int> t;
        subsequences(arr,0,n,t);
     
    }
 
}
 


⇒  PERMUTATIONS:
void helper(vector<int>& nums,vector<vector<int>> &ans,vector<int> temp,int dp[]  )
{
    
    if(temp.size()==nums.size()) {ans.push_back(temp);return;}
    else if(temp.size() >=nums.size() ) return;
    
    for(int i=0;i<nums.size();i++)
    {
        if(dp[i]==0)
        {
            dp[i]=1; temp.push_back(nums[i]) ;
            helper(nums,ans,temp,dp);

            dp[i]=0;  temp.pop_back();

        }
    }
    
    
}
    return C[n][k];
}
