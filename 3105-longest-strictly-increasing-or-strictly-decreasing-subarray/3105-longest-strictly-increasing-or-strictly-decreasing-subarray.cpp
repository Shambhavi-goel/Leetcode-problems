class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max1=1;
        int max2=1;

        for(int i=0; i< nums.size(); i++){
            int count=1;
            for(int j=i+1; j< nums.size(); j++){
                if(nums[j-1]< nums[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count> max1){
                max1= count;
            }
        }

        for(int i=0; i< nums.size(); i++){
            int count=1;
            for(int j=i+1; j< nums.size(); j++){
                if(nums[j-1]> nums[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count> max2){
                max2= count;
            }
        }

        return max(max1, max2);
    }
};