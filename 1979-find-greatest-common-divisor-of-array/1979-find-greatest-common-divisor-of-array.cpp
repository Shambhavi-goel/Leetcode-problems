class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans=1;
        sort(nums.begin(), nums.end());
        int start= nums[nums.size()-1];
        int end= nums[0];
        for(int i=end; i>= 1; i--){
            if(start%i==0 && end%i==0){
                ans= i;
                return ans;
            }
        }
        return ans;
    }
};