class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=-1;
        for(int i= nums.size()-1; i>=0; i--){
            for(int j=0; j< nums.size(); j++){
                if(nums[j] == -nums[i]){
                    ans= nums[i];
                    return ans;
                }
            }
        }
        return ans;
    }
};