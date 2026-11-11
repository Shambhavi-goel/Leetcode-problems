
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long ans = LLONG_MAX;

        // Try buying x combined items
        vector<int> choices = {0, min(need1, need2), max(need1, need2)};

        for (int x : choices) {
            long long remaining1 = max(0, need1 - x);
            long long remaining2 = max(0, need2 - x);

            long long total = 1LL * x * costBoth
                            + remaining1 * cost1
                            + remaining2 * cost2;

            ans = min(ans, total);
        }

        return ans;
    }
};
