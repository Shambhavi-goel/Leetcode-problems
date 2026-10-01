class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count= arr.size()/4;
        int ans=0;
        unordered_map<int, int> freq;
        for(int i=0; i< arr.size(); i++){
            freq[arr[i]]++;
        }
        for(auto x: freq){
            if(x.second > count){
                ans= x.first;
            }
        }
        return ans;
    }
};