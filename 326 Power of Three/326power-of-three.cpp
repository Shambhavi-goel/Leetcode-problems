class Solution {
public:
    bool isPowerOfThree(int n) {
        int num=n;
        int i=0;
        while(n>0){
            if((pow(3,i))==num){
                return true;
            }
            n=n/3;
            i++;
        }
        return false;
    }
};