class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1;
        unordered_map<string, int> freq2;
        for(int i=0;i< words1.size(); i++){
            freq1[words1[i]]++;
        }
        for(int i=0;i< words2.size(); i++){
            freq2[words2[i]]++;
        }
        int count=0;
        for(auto x: freq1){
            if(x.second==1 && freq2[x.first]==1){
                count++;
            }
        }
        return count;
    }
};