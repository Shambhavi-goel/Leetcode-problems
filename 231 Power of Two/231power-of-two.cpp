class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num=n;
        int i=0;
        while(n>0){
            if((pow(2,i))==num){
                return true;
            }
            n=n/2;
            i++;
        }
        return false;
    }
};