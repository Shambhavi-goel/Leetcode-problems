class Solution {
public:
    string triangleType(vector<int>& nums) {
        if( (nums[0]+nums[1] <= nums[2]) || (nums[1]+nums[2] <= nums[0]) || (nums[0]+nums[2] <= nums[1])) {
            return "none";
        }
        int count=0;
        for(int i=0; i< nums.size(); i++){
            for(int j=i+1; j< nums.size(); j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
        }
        if(count==3){
            return "equilateral";
        }
        else if(count==0){
            return "scalene";
        }
        else{
            return "isosceles";
        }
        return "none";
    }
};