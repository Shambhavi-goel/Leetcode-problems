class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> freq;
        int original=n;
        while(n>0){
            int r= n % 10;
            n= n/10;
            freq[r]++;
        }
        int min=INT_MAX;
        int least= INT_MAX;
        n= original;
        while(n>0){
            int r= n%10;
            n= n/10;
            if(freq[r] < min || (freq[r] == min && r < least)){
                min= freq[r];
                least = r;
            }
        }
        return least;
    }
};