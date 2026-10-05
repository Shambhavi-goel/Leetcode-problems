class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        stack<int> ans;
        ans.push(0);

        for(int i=0; i< s.size(); i++){
            if(s[i]=='('){
                ans.push(0);
            }
            else{
                int current = ans.top();
                ans.pop();

                if(current == 0) {
                    ans.top() += 1;
                }
                else {
                    ans.top() += 2 * current;
            }}
        }
        return ans.top();
    }
};