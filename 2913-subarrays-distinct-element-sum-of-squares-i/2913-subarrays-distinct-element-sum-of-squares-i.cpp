class Solution {
public:
    int sumCounts(vector<int>& nums) {
        set<int> s;
        int ans=0;
        for(int i=0; i< nums.size(); i++){
            s.clear();
            for(int j=i; j< nums.size(); j++){
                s.insert(nums[j]);
                ans += s.size()*s.size();
            }
        }
        return ans;
    }
};