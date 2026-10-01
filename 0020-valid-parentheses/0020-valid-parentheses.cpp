class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(int i=0; i< s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                ans.push(s[i]);
            }
            else{ 
            if(ans.empty()) return false;
            if(s[i]==')'){
                if(ans.top()== '('){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(ans.top()== '{'){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(ans.top()== '['){
                    ans.pop();
                }
                else{
                    return false;
                }
            }}
        }
        return ans.empty();
    }
};