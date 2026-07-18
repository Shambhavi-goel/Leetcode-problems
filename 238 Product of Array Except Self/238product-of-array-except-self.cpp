class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==1){
            return {1};
        }
        vector<int> prefixMul(nums.size());
        prefixMul[0] = nums[0];
        for(int i=1; i< nums.size(); i++){
            prefixMul[i] = prefixMul[i-1] * nums[i];
        }
        vector<int> suffixMul(nums.size());
        suffixMul[nums.size()-1] = nums[nums.size()-1];
        for(int i=(nums.size()-2); i>=0; i--){
            suffixMul[i] = suffixMul[i+1] * nums[i];
        }
        vector<int> ans(nums.size());
        for(int i=0; i< nums.size(); i++){
            if(i==0){
                ans[i]= suffixMul[i+1];
            }
            else if(i== (nums.size()-1)){
                ans[i]= prefixMul[i-1];
            }
            else{ ans[i]= prefixMul[i-1]*suffixMul[i+1];}
        }
        return ans;
    }
};