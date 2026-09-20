class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int final_count=0;
        for(int i=0; i< nums.size(); i++){
            int count=0;
            while(nums[i]>0){
                int r= nums[i] % 10;
                nums[i] /= 10;
                count++;
            }
            if(count % 2 ==0){
                final_count++;
            }
        }
        return final_count;
    }
};