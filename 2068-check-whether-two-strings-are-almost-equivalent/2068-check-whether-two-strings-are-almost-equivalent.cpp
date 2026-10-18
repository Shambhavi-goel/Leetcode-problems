class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for(int i=0; i< word1.size(); i++){
            freq1[word1[i]]++;
        }
        for(int i=0; i< word2.size(); i++){
            freq2[word2[i]]++;
        }
        for(char c= 'a'; c<= 'z'; c++){
            if(abs(freq1[c]- freq2[c])>3){
                return false;
            }
        }
        
        return true;
    }
};