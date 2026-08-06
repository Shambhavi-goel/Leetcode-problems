class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max= nums[nums.size()-1];
        int count=1;
        for(int i= (nums.size()-2); i>= 0; i--){
            if(nums[i]<max){
                max= nums[i];
                count++;
            } 
            if(count==3){
            return max;
        }
        }
        return nums[nums.size()-1];
    }
};