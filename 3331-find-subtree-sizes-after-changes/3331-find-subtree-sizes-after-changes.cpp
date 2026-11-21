
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n);
        vector<int> order;

        // Step 1: Find new parents using original tree
        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            int old = last[c];

            if(u == 0) {
                newParent[u] = -1;
            }
            else {
                if(old != -1)
                    newParent[u] = old;
                else
                    newParent[u] = parent[u];
            }

            last[c] = u;
            order.push_back(u);

            for(int v : adj[u]) {
                dfs(v);
            }

            // Restore previous ancestor
            last[c] = old;
        };

        dfs(0);

        // Step 2: Calculate subtree sizes
        vector<int> ans(n, 1);

        for(int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};
