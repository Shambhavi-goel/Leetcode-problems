class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> freq;
        int n= grid.size();
        for(int i=0; i< grid.size(); i++){  
            for(int j=0; j< grid[0].size(); j++){
                freq[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        for(int i=1; i<= n*n; i++){
            if(freq[i]==2){
                ans[0]= i;
            }
            if(freq[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};