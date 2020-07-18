class Solution {
public:
    void clear( std::queue<int> &q )
    {
       std::queue<int> empty;
       std::swap( q, empty );
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        int diameter = 0;
        // Create graph
        map<int, vector<int>> graph;
        for (vector<int> e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(graph.size(), 0);
        
        // BFS to last leaf node
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int front = 0;
        
        while(!q.empty()) {
            front = q.front();
            q.pop();
            
            for (int nbr: graph[front]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        
        fill(visited.begin(), visited.end(), 0);
        int lastNode = front;
        clear(q);
                
        // BFS to last leaf node
        q.push(lastNode);
        visited[lastNode] = 1;
        front = lastNode;
        
        while(!q.empty()) {
            front = q.front();
            q.pop();
            
            for (int nbr: graph[front]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        
        int otherLastNode = front;
        
        fill(visited.begin(), visited.end(), 0);
        clear(q);
                
        // BFS to last leaf node
        q.push(lastNode);
        visited[lastNode] = 1;
        front = lastNode;
        
        vector<int> parent(graph.size(), -1);
        
        while(!q.empty()) {
            front = q.front();
            q.pop();
            
            for (int nbr: graph[front]) {
                if (!visited[nbr]) {
                    parent[nbr] = front;
                    if (nbr == otherLastNode) 
                        break;
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        
        int p = otherLastNode;
        while (p != lastNode) {
            p = parent[p];
            diameter++;
        }
        
        return diameter;
    }
};