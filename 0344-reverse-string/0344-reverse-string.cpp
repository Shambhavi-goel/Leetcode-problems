class Solution {
public:
    void reverseString(vector<char>& s) {
        int n= s.size();
        for(int i=0; i< ceil(n/2); i++){
            int val = abs(i- (n-1));
            int swap;
            swap= s[i];
            s[i]= s[val];
            s[val]= swap;
        }
    }
};