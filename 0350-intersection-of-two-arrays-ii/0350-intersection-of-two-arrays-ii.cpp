class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        for(int i=0; i< nums1.size(); i++){
            freq1[nums1[i]]++;
        }
        for(int i=0; i< nums2.size(); i++){
            freq2[nums2[i]]++;
        }
        vector<int> ans;
        for(int i=0; i< nums1.size(); i++){
            if(freq1[nums1[i]] >0 && freq2[nums1[i]]>0){
                ans.push_back(nums1[i]);
                freq1[nums1[i]]--;
                freq2[nums1[i]]--;
            }
        }
        return ans; 
    }
};