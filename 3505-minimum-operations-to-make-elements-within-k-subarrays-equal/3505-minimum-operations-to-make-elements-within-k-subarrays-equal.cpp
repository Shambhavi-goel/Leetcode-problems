
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        // Keep left size equal to or one greater than right.
        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(prev(left.end()));
                sumL -= val;

                right.insert(val);
                sumR += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.begin());
                sumR -= val;

                left.insert(val);
                sumL += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }
            balance();
        };

        // Calculate the cost of every window of size x.
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long c = median * left.size() - sumL
                            + sumR - median * right.size();

                cost.push_back(c);
            }
        }

        // DP: minimum cost to select exactly j windows
        // from the first i elements.
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element.
                curr[i] = curr[i - 1];

                // Select the window ending at i-1.
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
