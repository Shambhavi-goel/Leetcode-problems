class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size());
        ans[arr.size()-1]= -1;
        for(int i=arr.size()-2; i>=0; i--){
            ans[i] = max(ans[i+1], arr[i+1]);
        }
        return ans;
    }
};