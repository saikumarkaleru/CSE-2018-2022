class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for (int i = 1; i < n; i++) {
            vector<int> temp;
            temp.push_back(1);
            
            vector<int> last = res[i-1];
            for (int j =1; j < last.size(); j++) {
                temp.push_back(last[j-1] + last[j]);
            }
            
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};