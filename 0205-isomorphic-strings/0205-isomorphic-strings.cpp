class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> a;
        unordered_map<char, int> b;
        for(int i=0; i< s.size(); i++){
            if(a.find(s[i]) == a.end()){
                a[s[i]]=i;
            }
            if(b.find(t[i]) == b.end()){
                b[t[i]]=i;
            }
            if(a[s[i]] != b[t[i]]){
                return false;
            }
        }
        return true;
    }
};