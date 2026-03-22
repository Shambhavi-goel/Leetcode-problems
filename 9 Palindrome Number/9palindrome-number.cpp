class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int num= x;
        long int n= 0;
       while(x>0){
        int r= x % 10;
        n= n*10 + r;
        x= x/10;
       } 
       if(num == n){
        return true;
       }
       else{
        return false;
       }
    }
};