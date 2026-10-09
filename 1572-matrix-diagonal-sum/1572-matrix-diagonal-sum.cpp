class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n= mat.size();
        int sum=0;
        for(int i=0; i< mat.size(); i++){
            sum += mat[i][i];
            sum += mat[i][mat.size()-1-i];
        }
        if(mat.size()%2==1){
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};