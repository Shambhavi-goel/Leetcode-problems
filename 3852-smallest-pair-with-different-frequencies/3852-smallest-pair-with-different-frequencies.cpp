class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int min_x= INT_MAX;
        int min_y= INT_MAX;
        int flag=0;

        for(int i=0; i< nums.size(); i++){
            for(int j=0; j< nums.size(); j++){
                if((nums[i] < nums[j]) && (freq[nums[i]] != freq[nums[j]])){
                    if(nums[i] < min_x ||
                       (nums[i] == min_x && nums[j] < min_y)){
                        min_x= nums[i];
                        min_y= nums[j];
                        flag=1;
                    }
                }
            }
        }
        if(flag==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(min_x);
        ans.push_back(min_y);
        return ans;
    }
};