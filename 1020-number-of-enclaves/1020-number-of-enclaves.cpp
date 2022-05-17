class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int visited[502][502];
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                visited[i][j] = 0;
            }
        }
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if((i == 0 || i == grid.size()-1 || j == 0 || j == grid[i].size() -1 )  && (!visited[i][j]) && grid[i][j] == 1) {
                    dfs(grid, visited, i, j, 1);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if((!visited[i][j]) && grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int visited[502][502], int x, int y, int idx)
    {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        
        if(visited[x][y]) return;
        if(!grid[x][y]) return;
        
        visited[x][y] = idx;
        
        for(int i = 0; i < 4; i++) {
            int dxx = x + dx[i];
            int dyy = y + dy[i];
            
            dfs(grid, visited, dxx, dyy, idx);
        }
    }
};