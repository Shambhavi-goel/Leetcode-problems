class Solution {
public:
    int maxFreqSum(string s) {
        int max_vowel=0;
        int max_constant=0;
        unordered_map<char, int> freq;
        for(int i=0; i< s.size(); i++){
            freq[s[i]]++;
        }
        for(auto x: freq){
            if(x. first == 97 || x. first == 101 || x. first == 105 || x. first == 111 || x. first == 117){
                if(x.second> max_vowel){
                    max_vowel= x.second;
                }
            }
            else{
                if(x.second> max_constant){
                    max_constant= x.second;
                }
            }
        }
        return (max_vowel + max_constant);
    }
};