class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[1005];
        memset(visited, false, sizeof visited);
        dfs(0, visited, rooms);
        
        for(int i = 0; i < rooms.size() ; i++){
            if(!visited[i])
                return false;
        }
        
        return true;
    }
    
    void dfs(int node, bool visited[1005], vector<vector<int>>& rooms)
    {
        if(visited[node])
            return;
        visited[node] = true;
        
        for(int n: rooms[node]){
            dfs(n, visited, rooms);
        }
    }
    
    
    
};