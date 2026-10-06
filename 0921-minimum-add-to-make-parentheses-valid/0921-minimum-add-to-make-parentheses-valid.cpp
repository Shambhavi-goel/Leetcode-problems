class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int balance=0;
        for(int i=0; i< s.size(); i++){
            if(s[i]=='('){
                balance++;
            }
            else{
                balance--;
                if(balance<0){
                    ans++;
                    balance=0;
                }
            }
        }
        ans+= balance;
        return ans;
    }
};