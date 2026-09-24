class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int count=0;
        for(auto x: freq){
            if(x.second > floor(nums.size()/3)){
                if(freq.find(x.first) != freq.end()){
            ans.push_back(x.first);
            }
            }
        }
        return ans;
    }
};