class Solution {
public:
    int countTriples(int n) {
        int count=0;
        int a=0, b=0; 
        for(int i=1; i<= n; i++){
            a= i*i;
            for(int j=1; j<= n; j++){
                b= j*j;
                int c = sqrt(a + b);
                if(c * c == a + b && c <= n){
                    count++;
                }
            }
        }
        return count;
    }
};