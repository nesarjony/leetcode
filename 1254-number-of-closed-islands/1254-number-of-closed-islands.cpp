class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int visited[103][103];
        
        for(int i = 0; i < 103; i++) {
            for(int j = 0; j < 103; j++) {
                visited[i][j] = 0;
            }
        }
        int idx = 1;
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0 && !visited[i][j]){
                    dfs(grid, visited, i, j, idx);
                    idx++;
                }
                
            }
        }
        
        map<int,int>mp;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if((i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size() - 1) && visited[i][j]){
                    if(!mp.count(visited[i][j])){
                        idx--;
                        mp[visited[i][j]] = 1;
                    }
                }
                
            }
        }
        
        return idx - 1;
        
    }
    
    void dfs(vector<vector<int>> &grid, int visited[103][103], int x, int y, int idx)
    {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        if(x < 0 || x >= grid.size()) return;
        if(y < 0 || y >= grid[0].size()) return;
        
        if(grid[x][y])
            return;
        
        if(visited[x][y])
            return;
        
        visited[x][y] = idx;
        
        for(int i = 0; i < 4; i++){
            int dxx = x + dx[i];
            int dyy = y + dy[i];
            
            dfs(grid, visited, dxx, dyy, idx);
        }
    }
};