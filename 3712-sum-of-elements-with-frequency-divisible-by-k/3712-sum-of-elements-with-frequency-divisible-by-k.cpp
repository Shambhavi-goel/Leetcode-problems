class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int, int> freq;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        for(int i=0; i< nums.size(); i++){
            if(freq[nums[i]] % k ==0){
                sum += nums[i];
            }
        }
        return sum;
    }
};