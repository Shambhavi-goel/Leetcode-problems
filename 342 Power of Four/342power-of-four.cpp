class Solution {
public:
    bool isPowerOfFour(int n) {
        int num=n;
        int i=0;
        while(n>0){
            if((pow(4,i))==num){
                return true;
            }
            n=n/4;
            i++;
        }
        return false;
    }
};