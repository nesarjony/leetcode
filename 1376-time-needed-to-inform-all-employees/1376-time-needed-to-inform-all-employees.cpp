class Solution {
public:
    map<int, vector<int> > graph;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0; i < manager.size(); i++) {
            if(manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }
        
        return solve(n, headID, informTime);
    }
    
    int solve(int n, int headID, vector<int>& informTime)
    {
        int total = 0;
        int visited = 0;
        for(int v: graph[headID])
        {
            total = max(total, informTime[headID] + solve(n, v, informTime));
        }
        return total;
    }
};