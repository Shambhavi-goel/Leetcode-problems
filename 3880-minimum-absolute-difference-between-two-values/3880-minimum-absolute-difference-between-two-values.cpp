class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int min=INT_MAX;
        for(int i=0; i< nums.size(); i++){
            for(int j= 0; j< nums.size(); j++){
                if(nums[i]==1 && nums[j]==2){
                    if(abs(i-j)<min){
                        min= abs(i-j);
                    }
                }
            }
        }
        if(min==INT_MAX){
            return -1;
        }
        return min;
    }
};