class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>for_ransom;
        unordered_map<char, int> for_magazine;

        for(int i=0; i< ransomNote.size(); i++){
            for_ransom[ransomNote[i]]++;
        }
        for(int i=0; i< magazine.size(); i++){
            for_magazine[magazine[i]]++;
        }
        for(auto x: for_ransom){
            if((for_magazine.find(x.first) == for_magazine.end()) || 
            (for_magazine[x.first] < x.second )){
                return false;
            }
        }
        return true;
    }
};