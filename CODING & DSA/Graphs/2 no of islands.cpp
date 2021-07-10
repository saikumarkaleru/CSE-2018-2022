class Solution {
public:
    bool is_valid(int i,int j,int m,int n)
    {
      if(i<0 || j<0 || i>=m || j>=n)
      {
        return false;
      }
      return true;
    }
    void dfs(int x,int y,int n,int m,vector<vector<bool>>&vis,vector<vector<char>>& grid)
    {
      vis[x][y]=true;
     // count++;
      int dx[]={-1,1,0,0};
      int dy[]={0,0,-1,1};
      for(int i=0;i<4;i++)
      {
        int new_x=dx[i]+x;
        int new_y=dy[i]+y;
        if(is_valid(new_x,new_y,m,n) && !vis[new_x][new_y] && grid[new_x][new_y]=='1')
        {
          dfs(new_x,new_y,n,m,vis,grid);
        }
      }
      
    }
    int numIslands(vector<vector<char>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      vector<vector<bool>>vis(m,vector<bool>(n,false));
      int count=0;
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(grid[i][j]=='1' && !vis[i][j])
          {
            dfs(i,j,n,m,vis,grid);
            count++;
          }
        }
      }
      return count;
        
    }
};