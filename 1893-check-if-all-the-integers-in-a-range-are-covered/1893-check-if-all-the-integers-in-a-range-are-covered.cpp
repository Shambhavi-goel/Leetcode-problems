class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int, int> freq;
        for(int i=0; i< ranges.size(); i++){
            for(int j= ranges[i][0]; j<= ranges[i][1]; j++){
                freq[j]++;
            }
        }
        for(int i=left; i<= right; i++){
            if(freq.find(i) == freq.end()){
                return false;
            }
        }
        return true;
    }
};