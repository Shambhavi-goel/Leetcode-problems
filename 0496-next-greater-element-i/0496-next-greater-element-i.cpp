class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i< nums1.size(); i++){
            int k;
            int flag=0;
            for(int j=0; j< nums2.size(); j++){
                if(nums2[j]==nums1[i]){
                    k=j;
                    break;
                }
            }
            for(int x=k+1; x< nums2.size(); x++){
                if(nums2[x] > nums2[k]){
                    ans.push_back(nums2[x]);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};