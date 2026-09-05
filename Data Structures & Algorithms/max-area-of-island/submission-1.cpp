class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& grid){
         int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        int sum=1;
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;++i){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
               sum+=dfs(nr,nc,vis,grid);
            }
        }
      return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
              if(!vis[i][j] && grid[i][j]==1){
                maxi=max(maxi,dfs(i,j,vis,grid));
              }
            }
        }
        return maxi;
    }
};
