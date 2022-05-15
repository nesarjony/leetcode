class Solution {
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int visited[60][60];
        for(int i = 0; i< 60; i++)
            for(int j = 0; j < 60; j++)
                visited[i][j] = false;
        
        dfs(image, visited, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int visited[60][60], int sr, int sc, int newColor, int srcColor) {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        if (sr >= image.size()) {
            return;
        }
        
        if (sc >= image[0].size()) {
            return;
        }
        
        if(image[sr][sc] != srcColor){
            return;
        }
        
        if(visited[sr][sc])
            return;
        
        visited[sr][sc] = true;
        
        image[sr][sc] = newColor;
        
        for(int i = 0; i < 4; i++) {
            int ndx = sr + dx[i];
            int ndy = sc + dy[i];
            
            dfs(image, visited, ndx, ndy, newColor, srcColor);
        }
    }
};