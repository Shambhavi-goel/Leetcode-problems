
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Part 1: Calculate cost for every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Compare characters in each group
                    for (int rem = 0; rem < d; rem++) {

                        int left = l + rem;
                        int right = r - ((len - 1 - rem) % d);

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // Part 2: Dynamic Programming
        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 2 * parts; i <= n; i++) {

                for (int p = 2 * (parts - 1); p <= i - 2; p++) {

                    if (dp[parts - 1][p] == INF)
                        continue;

                    dp[parts][i] = min(
                        dp[parts][i],
                        dp[parts - 1][p] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
