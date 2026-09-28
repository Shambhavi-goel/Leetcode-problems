class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=0;
        for(int i=0; i< accounts.size(); i++){
            int val=0;
            for(int j=0; j< accounts[i].size(); j++){
                val += accounts[i][j];
            }
            if(val> max){
                max= val;
            }
        }
        return max;
    }
};