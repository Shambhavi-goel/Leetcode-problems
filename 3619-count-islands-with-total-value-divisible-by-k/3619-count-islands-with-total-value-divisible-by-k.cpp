class Solution {
public:
long long sum=0;
void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        sum += grid[i][j];
        grid[i][j] = 0;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        // Count remaining closed islands
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
            
                if(grid[i][j] != 0) {
                    sum =0;
                    dfs(grid, i, j);

                    if(sum % k==0){
                    count++;
                }
                }
                
            }
        }

        return count;
    }
};