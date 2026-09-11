class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>for_s;
        unordered_map<char, int> for_tt;

        if(s.size() != t.size()){
            return false;
        }
        for(int i=0; i< s.size(); i++){
            for_s[s[i]]++;
        }
        for(int i=0; i< t.size(); i++){
            for_tt[t[i]]++;
        }
        for(auto x: for_tt){
            if((for_s.find(x.first) == for_s.end()) || 
            (for_s[x.first] != x.second )){
                return false;
            }
        }
        return true;
    }
};