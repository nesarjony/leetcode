class Solution {
public:
    bool visited[100005];
    map<int, vector<int>> graph;
    int makeConnected(int n, vector<vector<int>>& connections) {
        memset(visited, false, sizeof visited);
        
        if(connections.size() < n-1) {
            return -1;
        }
        
        for(int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
    
        int group = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visit(i);
                group++;
            }
        }
        
        int red = connections.size() - ((n - 1) - (group - 1));
        if(red < (group-1))
            return -1;
        else
            return (group - 1);
    }
    
    void visit(int node)
    {
        if(visited[node])
            return;
        
        visited[node] = true;
      
        for(int u: graph[node]){
            visit(u);
        }
    }
};