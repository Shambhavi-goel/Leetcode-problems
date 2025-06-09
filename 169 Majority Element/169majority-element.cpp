class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0, ans=0;
        for(int i=0; i< nums.size(); i++){
            if(freq==0){
                ans= nums[i];
            }
            if(ans==nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        int count=0;
        for(int i: nums){
            if(i==ans){
                count++;
            }
        }
        if(count> (nums.size()/2)){
            return ans;
        }
        else{
            return -1;
        }
    }
};