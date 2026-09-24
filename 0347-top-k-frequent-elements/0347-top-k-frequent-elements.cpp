class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> ans;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        for(int count = 0; count < k; count++) {
            int maxFreq = 0;
            int element = 0;

            for(auto i : freq) {
                if(i.second > maxFreq) {
                    maxFreq = i.second;
                    element = i.first;
                }
            }

            ans.push_back(element);
            freq.erase(element);
        }
        return ans;
    }
};