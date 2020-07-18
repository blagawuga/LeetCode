class Solution {
public:
    int pickNext(vector<int> list) {
        for (auto x: list) {
            if (!x) 
                return x;
        }
        
        return -1;
    }
    
    void BFS(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j, int &k) {
        k++;
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        q.push(make_pair(i, j));
        
        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            

            //Bottom neighbour
            if (front.first+1 < n && front.second < m && !visited[front.first+1][front.second] && grid[front.first+1][front.second] == '1') {
                visited[front.first+1][front.second] = 1;
                q.push(make_pair(front.first+1, front.second));
            }
            // Top neighbour           
            if (front.first-1 >= 0 && front.second< m && !visited[front.first-1][front.second] && grid[front.first-1][front.second] == '1') {
                visited[front.first-1][front.second] = 1;
                q.push(make_pair(front.first-1, front.second));
            }
            // Left neighbour           
            if (front.first < n && front.second-1 >= 0 && !visited[front.first][front.second-1] && grid[front.first][front.second-1] == '1') {
                visited[front.first][front.second-1] = 1;
                q.push(make_pair(front.first, front.second-1));
            }
            // Right neighbour             
            if (front.first < n && front.second+1 < m && !visited[front.first][front.second+1] && grid[front.first][front.second+1] == '1') {
                visited[front.first][front.second+1] = 1;
                q.push(make_pair(front.first, front.second+1));   
            }        
        }
            
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) 
            return 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        int k=0;
        cout << grid.size() << " " << grid[0].size();
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j< grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = 1;
                    BFS(grid, visited, i, j, k);
                }
                    
            }
        }
        
        return k;
    }
};