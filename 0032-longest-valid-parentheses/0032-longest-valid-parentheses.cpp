class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlength=0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i< s.size(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int length= i- st.top();
                    maxlength= max(length, maxlength);
                }
            }
        }
        return maxlength;
    }
};