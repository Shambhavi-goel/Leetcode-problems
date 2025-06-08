class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i< nums.size(); i++){
            for(int j=0; j< nums.size();){
                if(i!=j && nums[i]==nums[j]){
                    nums.erase(nums.begin()+j);
                }
                else{
                    j++;
                }
            }
        }
        return nums.size();
    }
};