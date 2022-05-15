class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool visited[n+5];
        memset(visited, false, sizeof visited);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]){
                dfs(i, isConnected, visited);
                res++;
            }
        }
        return res;
    }
    
    void dfs(int node, vector<vector<int>>& isConnected, bool visited[205])
    {
        if(visited[node]){
            return;
        }
        
        visited[node] = true;
        
        for(int i = 0; i < isConnected[node].size(); i++)
        {
            if(isConnected[node][i]){
                dfs(i, isConnected, visited);
            }
        }
    }
};