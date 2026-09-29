class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long int max=0;
        for(int i=0; i< nums.size(); i++){
            for(int j=i+1; j< nums.size(); j++){
                for(int k= j+1; k< nums.size(); k++){
                    long long value = (1LL * (nums[i] - nums[j])) * nums[k];

                    if(value > max) {
                        max = value;
                    }
                }
            }
        }
        return max;
    }
};