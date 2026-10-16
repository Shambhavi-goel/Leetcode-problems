class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i=triangle.size()-2; i>=0; i--){
            for(int idx=0; idx<=i; idx++){
            triangle[i][idx] += min(triangle[i+1][idx], triangle[i+1][idx+1]);
           
        }}
        return triangle[0][0];
    }
};