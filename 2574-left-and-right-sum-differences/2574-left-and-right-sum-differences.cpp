class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> leftsum(nums.size());
        leftsum[0]= 0;
        for(int i=1; i< nums.size(); i++){
            leftsum[i] = leftsum[i-1] + nums[i-1];
        }
        vector<int> rightsum(nums.size());
        rightsum[nums.size()-1]= 0;
        for(int i=nums.size()-2; i>=0; i--){
            rightsum[i] = rightsum[i+1] + nums[i+1];
        }
        for(int i=0; i< leftsum.size(); i++){
            ans[i]= abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};