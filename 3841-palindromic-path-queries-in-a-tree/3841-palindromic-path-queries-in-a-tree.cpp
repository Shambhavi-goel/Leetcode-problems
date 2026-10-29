
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            while (i <= n + 1) {
                bit[i] ^= val;
                i += i & -i;
            }
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }

        int query(int i) {
            int ans = 0;
            while (i > 0) {
                ans ^= bit[i];
                i -= i & -i;
            }
            return ans;
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), pref(n);

        auto mask = [](char c) {
            return 1 << (c - 'a');
        };

        // Iterative DFS: Euler tour and binary lifting
        int timer = 0;
        stack<tuple<int, int, int>> st;
        st.push({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.top();
            st.pop();

            if (state == 0) {
                tin[u] = ++timer;
                up[0][u] = p;

                for (int k = 1; k < LOG; k++)
                    up[k][u] = up[k - 1][up[k - 1][u]];

                pref[u] = (u == 0 ? 0 : pref[p]) ^ mask(s[u]);

                st.push({u, p, 1});

                for (int v : adj[u]) {
                    if (v != p) {
                        depth[v] = depth[u] + 1;
                        st.push({v, u, 0});
                    }
                }
            } else {
                tout[u] = timer;
            }
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);

            int diff = depth[a] - depth[b];

            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    a = up[k][a];

            if (a == b) return a;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }

            return up[0][a];
        };

        Fenwick fw(n);
        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int change = mask(s[u]) ^ mask(c);

                fw.rangeUpdate(tin[u], tout[u], change);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int pu = pref[u] ^ fw.query(tin[u]);
                int pv = pref[v] ^ fw.query(tin[v]);

                int pathMask = pu ^ pv ^ mask(s[w]);

                // At most one character can have an odd frequency.
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
