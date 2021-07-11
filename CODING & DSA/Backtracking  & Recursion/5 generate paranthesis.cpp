Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        funbacktrack(ans,n,"",0,0);
        return ans;
        
    }
    void funbacktrack(vector<string> &ans,int n,string curr,int open,int close)
    {
        if (curr.length()==2*n)
        {
            ans.push_back(curr);
            return;
        }
        if (open<n) funbacktrack(ans,n,curr+'(',open+1,close);
        if (close<open) funbacktrack(ans,n,curr+')',open,close+1);
    }
};