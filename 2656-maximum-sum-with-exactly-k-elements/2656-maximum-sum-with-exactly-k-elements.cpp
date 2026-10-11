class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int score=0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<= k; i++){
            score += nums[nums.size()-1];
            nums[nums.size()-1] += 1;
        }
        return score;
    }
};