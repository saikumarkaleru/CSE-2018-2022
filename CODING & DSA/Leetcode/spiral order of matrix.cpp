class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        vector<int> res;
        int i;
        while(left <= right and top <= bottom) {
            // traverse from left to right in the top row
            for(i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            // now that top row is done,decrement the top pointer
            top++;
            // traverse from top to bottom in the rightmost column
            for(i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left > right || top > bottom) break;
            // traverse from right to left in the bottom row
            for(i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            // // traverse from bottom to top in the left most column
            for(i=bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return res;
    }
};











Given a positive integer n,
generate an n x n matrix filled with elements from 1 to n^2 in spiral order.



 int top=0, down=n-1;
    int left=0,right=n-1;
    int dir=0;
    int num=1;      //a number to assign
    
    //traversing the matrix spirally
    while(top<=down && left<=right)
    {
        if(dir==0)
        {   //dir = left->right
            for(int i=left;i<=right;i++)
            {
                spiral[top][i]=num;
                num++;
            }
            top++;
        }
        else if(dir==1)
        {   //dir = top->down
            for(int i=top;i<=down;i++)
            {
                spiral[i][right]=num;
                num++;
            }
            right--;
        }
        else if(dir==2)
        {   ////dir = right->left
            for(int i=right;i>=left;i--)
            {
                spiral[down][i]=num;
                num++;
            }
            down--;
        }
        else if(dir==3)
        {   //dir = down->top
            for(int i=down;i>=top;i--)
            {
                spiral[i][left]=num;
                num++;
            }
            left++;
        }
        
        dir=(dir+1)%4;      //calculating direction to travel
    }
 return spiral;
}
};