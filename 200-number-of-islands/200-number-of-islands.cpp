class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        bool visited[310][310];
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                visited[i][j] = false;
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, bool visited[310][310], int x, int y)
    {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        
        if(x >= grid.size())
            return;
        if(y >= grid[0].size())
            return;
        
        if(visited[x][y])
            return;
        
        if(grid[x][y] != '1')
            return;
        
        visited[x][y] = true;
        
        for(int i = 0; i < 4; i++){
            int ndx = x + dx[i];
            int ndy = y + dy[i];
            
            dfs(grid, visited, ndx, ndy);
        }
    }
};