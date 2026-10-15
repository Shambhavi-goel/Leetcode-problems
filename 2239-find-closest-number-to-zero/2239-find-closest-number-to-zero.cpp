class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans= INT_MAX;
        int max=0;
        for(int i=0; i< nums.size(); i++){
            if((abs(nums[i]) < ans) || (abs(nums[i]) == ans && nums[i]>max)){
                ans= abs(nums[i]);
                max= nums[i];
            }
        }
        return max;
    }
};