Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.








class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        
       int i = 0, j = mat[0].size() - 1;
        // element
 
        while (i < mat.size() && j >= 0)
        {
            if (mat[i][j] == x)
         
                return true;
          
            if (mat[i][j] > x)
                j--;
            else 
                i++;
        }
        return false;
        
    }
};