class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> counts;
        for(int i=0; i< nums.size(); i++){
            counts[nums[i]]++;
        }
        for(int i=1; i<= nums.size(); i++){
            if(counts.find(i) == counts.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};