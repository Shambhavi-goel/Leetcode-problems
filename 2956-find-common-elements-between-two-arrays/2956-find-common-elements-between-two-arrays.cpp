class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        for(int i=0; i< nums1.size(); i++){
            freq1[nums1[i]]++;
        }
        for(int i=0; i< nums2.size(); i++){
            freq2[nums2[i]]++;
        }
        vector<int> ans(2);
        int count1=0;
        int count2=0;
        for(int i=0; i< nums1.size(); i++){
            if(freq2.find(nums1[i]) != freq2.end()){
                count1++;
            }
        }
        for(int i=0; i< nums2.size(); i++){
            if(freq1.find(nums2[i]) != freq1.end()){
                count2++;
            }
        }
        ans[0]= count1;
        ans[1]= count2;
        return ans;
    }
};