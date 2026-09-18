class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(char ch : s) {
           if(isalnum(ch)) {
              temp += tolower(ch);
           }
        }

        int flag=0;
        for(int i=0; i< temp.size(); i++){
            if(temp[i] != temp[temp.size()-1-i]){
                flag=1;
            }
        }
        if(flag==0){
            return true;
        }
        return false;
    }
};