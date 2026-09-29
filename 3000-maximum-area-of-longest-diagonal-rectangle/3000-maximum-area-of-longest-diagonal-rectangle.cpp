class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max=0;
        int area=0;
        for(int i=0; i< dimensions.size(); i++){
           int diagonal = dimensions[i][0] * dimensions[i][0]
                         + dimensions[i][1] * dimensions[i][1];

            int currentArea = dimensions[i][0] * dimensions[i][1];

            if(diagonal > max) {
                max = diagonal;
                area = currentArea;
            }
            else if(diagonal == max && currentArea > area) {
                area = currentArea;
            }
        }
        return area;
    }
};