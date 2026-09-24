class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for(int i=0; i< s.size(); i++){
            freq[s[i]]++;
        }
        int a= freq[s[0]];
        for(auto x: freq){
            if(x.second != a){
                return false;
            }
        }
        return true;
    }
};