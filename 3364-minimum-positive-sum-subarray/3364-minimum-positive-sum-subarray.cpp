class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       int min= INT_MAX;
       for(int i=0; i< nums.size(); i++){
        int count=0;
        int sum=0;
        for(int j=i; j< nums.size(); j++){
            count++;
            sum += nums[j];
            if(count >= l && count <=r){
                if(sum > 0){
                    if(sum < min){
                        min= sum;
                    }
                }
            }
            else{
                continue;
            }
        }
       }
       if(min == INT_MAX){
        return -1;
       } 
       return min;
    }
};