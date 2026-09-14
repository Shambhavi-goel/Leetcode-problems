class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int sum= 0;
        for(int i=0; i< nums.size(); i++){
            if(freq[nums[i]] == 1){
                sum += nums[i];
            }
        }
        return sum;
    }
};