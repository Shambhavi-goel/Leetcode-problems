class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int total_sum=0;
        int sum=0;
        for(int i=0; i< t.length(); i++){
            total_sum += (int)t[i];
        }
        for(int i=0; i< s.length(); i++){
            sum += (int)s[i];
        }
        int x= total_sum-sum;
        return (char)x;
    }
};