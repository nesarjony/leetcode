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
        
        return bfs(source, destination, graph, visited);
    }
    
    bool bfs(int source, int dest, vector<int>graph[], int visited[]) {
    
        queue<int>Q;
        
        Q.push(source);
        
        while(!Q.empty()) {
            int node = Q.front();
            Q.pop();
            
            if (node == dest) {
                return true;
            }
            
            visited[node] = true;
            
            for(int i = 0; i < graph[node].size(); i++) {
                int v = graph[node][i];
                if(!visited[v]) {
                    Q.push(v);
                }
            }
        }
        
        return false;
    }
};