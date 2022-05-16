class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int visited[55][55];
        for(int i = 0; i < 55; i++)
            for(int j = 0; j < 55; j++)
                visited[i][j] = 0;
        
        
        int idx = 1;
        int mx = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                   // printf("%d %d\n", i, j);
                    int total = dfs(grid, visited, i, j, idx);
                    mx = max(mx, total);
                    //printf("total = %d\n", total);
                }
            }
        }
        return mx;
    }
    
    int dfs(vector<vector<int>>& grid, int visited[55][55], int x, int y, int idx)
    {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        if(x < 0 || x >= grid.size())
            return 0;
        
        if(y < 0 || y >= grid[0].size())
            return 0;
        
        if(!grid[x][y])
            return 0;
        
        if(visited[x][y])
            return 0;
        
        visited[x][y] = idx;
        
        int res = 1;
        for(int i = 0; i < 4; i++){
            int ddx = x + dx[i];
            int ddy = y + dy[i];
            
            res += dfs(grid, visited, ddx, ddy, idx);
        }
        return res;
    }
};