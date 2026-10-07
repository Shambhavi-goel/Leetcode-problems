class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    void solve(string &s, int i, int lremove, int rremove,
               int balance, string &curr) {

        if (i == s.size()) {
            if (lremove == 0 && rremove == 0 && balance == 0)
                st.insert(curr);
            return;
        }

        // Remove
        if (s[i] == '(' && lremove > 0)
            solve(s, i + 1, lremove - 1, rremove, balance, curr);

        if (s[i] == ')' && rremove > 0)
            solve(s, i + 1, lremove, rremove - 1, balance, curr);

        // Keep
        if (s[i] == '(') {
            curr.push_back('(');
            solve(s, i + 1, lremove, rremove, balance + 1, curr);
            curr.pop_back();
        }
        else if (s[i] == ')') {
            if (balance > 0) {
                curr.push_back(')');
                solve(s, i + 1, lremove, rremove, balance - 1, curr);
                curr.pop_back();
            }
        }
        else {
            curr.push_back(s[i]);
            solve(s, i + 1, lremove, rremove, balance, curr);
            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        ans.clear();
        st.clear();

        int balance = 0;
        int lremove = 0;
        int rremove = 0;

        for (char c : s) {
            if (c == '(')
                balance++;
            else if (c == ')') {
                if (balance > 0)
                    balance--;
                else
                    rremove++;
            }
        }

        lremove = balance;

        string curr = "";

        solve(s, 0, lremove, rremove, 0, curr);

        for (auto x : st)
            ans.push_back(x);

        return ans;
    }
};