class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int count=0;
        int first= word[0];
        for(int i=1; i< n; i++){
            if(first >= 65 && first <= 90){
                if(word[i] >= 65 && word[i] <= 90){
                    count++;
                }
            }
            if(first >= 97 && first <= 122){
                if(word[i] >= 65 && word[i] <= 90){
                    return false;
                }
            }
        }
        if(count != 0 && count != n-1){
            return false;
        }
        return true;
    }
};