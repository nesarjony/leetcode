class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>graph[n + 5];
        int visited[n+5];
        
        memset(visited, false, sizeof visited);
        
        for(int i= 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        return dfs(source, destination, graph, visited);
    }
    
    bool dfs(int node, int dest, vector<int>graph[], int visited[]) {
        
        if(node == dest) {
            return true;
        }
        
        visited[node] = true;
        
        for(int v: graph[node]) {
            if(visited[v]) {
                continue;
            }
            
            if (dfs(v, dest, graph, visited)){
                return true;
            }
        }
        
        return false;
    }
};