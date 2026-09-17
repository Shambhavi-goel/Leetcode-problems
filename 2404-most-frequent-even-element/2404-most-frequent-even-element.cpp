class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int max= 0;
        int ans=-1;
        for(int x: nums){
            if(x % 2 == 0){
                if(freq[x] > max){
                    max= freq[x];
                    ans=x;
                }
            }
        }
        return ans;
    }
};