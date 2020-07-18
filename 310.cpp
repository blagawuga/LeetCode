class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            vector<int> v(1, 0);
            return v;
        }
        // Create graph
        map<int, set<int>> graph;
        for (vector<int> e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        // Create degree set
        vector<int> degree(n, 0);
        for (pair<int, set<int>> p: graph) {
            degree[p.first] = p.second.size();
        }
        
        // Create leaf set
        set<int> leaveSet;
        for (int i=0; i<n; i++) {
            if (graph[i].size() == 1) 
                leaveSet.insert(i);
        }
        
        // Remove leaves and update the leaf set
        while (n > 2) {
            n -= leaveSet.size();
            // New leaveSet
            set<int> newLeaves;
            // Remove leave nodes
            for (int i: leaveSet) {
                int pos = *(graph[i].begin()); // only 1 element in graph list if leaf element
                graph[pos].erase(i);
                
                if (graph[pos].size() == 1) 
                    newLeaves.insert(pos);
            }
            leaveSet = newLeaves;
        }
        vector<int> v(leaveSet.begin(), leaveSet.end());
        return v;
    }
};