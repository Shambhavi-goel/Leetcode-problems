class Solution {
public:
    void dfs(vector<vector<bool>> &visited, vector<vector<char>> &grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j] != '1'){
            return;
        }
        visited[i][j]=true;
        dfs(visited, grid, i-1, j, n, m);
        dfs(visited, grid, i, j+1, n, m);
        dfs(visited, grid, i+1, j, n, m);
        dfs(visited, grid, i, j-1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int islands=0;

        vector<vector<bool>> visited(n,  vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== '1' && !visited[i][j]){
                    dfs(visited, grid, i, j, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};