
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int m = queries.size();

        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> cnt(n + 1, 0);
        vector<int> ans(m, 0);

        int l = 0, r = 0;
        int active = 0;

        for (auto it : q) {
            int time = it.first;
            int idx = it.second;

            int start = time - x;

            // Add logs up to the current query time
            while (r < logs.size() && logs[r][1] <= time) {
                int id = logs[r][0];

                if (cnt[id] == 0)
                    active++;

                cnt[id]++;
                r++;
            }

            // Remove logs before the starting time
            while (l < r && logs[l][1] < start) {
                int id = logs[l][0];

                cnt[id]--;

                if (cnt[id] == 0)
                    active--;

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
