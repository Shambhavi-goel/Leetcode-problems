class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num >= 10){
            sum=0;
        while(num > 0){
            int r= num%10;
            num = num/10;
            sum += r;
        }
        num= sum;
        }
        return num;
    }
};