class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>tmp;
        tmp.push_back(0);
        dfs(0, graph, ans, tmp);
        return ans;
    }
    
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>> &ans,                        vector<int> &tmp)
    {
        if(node == graph.size() - 1) {
            ans.push_back(tmp);
            return;
        }
        for(int x: graph[node])
        {
            tmp.push_back(x);
            dfs(x, graph, ans, tmp);
            tmp.pop_back();
        }
    }
};