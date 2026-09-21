class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> freq;
        for(int i=0; i< num.size(); i++){
            char r= num[i];
            freq[r]++;
        }
        for(int i=0; i< num.size(); i++){
            if((freq[i + '0']) != num[i] - '0'){
                return false;
            }
        }
        return true;
    }
};