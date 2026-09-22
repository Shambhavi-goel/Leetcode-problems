class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int max=0;
        for(int x: nums){
            if(freq[x] > max){
                max= freq[x];
            }
        }
        int count=0;
        for(int x: nums){
            if(freq[x]==max){
                count++;
            }
        }
        return count;
    }
};