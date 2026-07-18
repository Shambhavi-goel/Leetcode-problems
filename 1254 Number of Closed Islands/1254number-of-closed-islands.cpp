class Solution {
public:
    void dfs(vector<vector<bool>> &visited, vector<vector<int>> &grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j] != 0){
            return;
        }
        visited[i][j]=true;
        dfs(visited, grid, i-1, j, n, m);
        dfs(visited, grid, i, j+1, n, m);
        dfs(visited, grid, i+1, j, n, m);
        dfs(visited, grid, i, j-1, n, m);
    }
        
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int islands=0;

        vector<vector<bool>> visited(n,  vector<bool>(m, false));

// Top and bottom rows
for (int j = 0; j < m; j++) {
    dfs(visited, grid, 0, j, n, m);
    dfs(visited, grid, n - 1, j, n, m);
}

// Left and right columns
for (int i = 0; i < n; i++) {
    dfs(visited, grid, i, 0, n, m);
    dfs(visited, grid, i, m - 1, n, m);
}
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== 0 && !visited[i][j]){
                    dfs(visited, grid, i, j, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};