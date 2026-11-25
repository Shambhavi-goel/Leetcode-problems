
class Solution {
public:
    const long long MOD1 = 1000000007;
    const long long MOD2 = 1000000009;
    const long long BASE = 131;

    vector<long long> h1, h2, p1, p2;

    bool check(int len, int n) {
        unordered_map<unsigned long long, int> mp;

        for(int i = 0; i + len <= n; i++) {

            long long hash1 = (h1[i + len] -
                h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

            long long hash2 = (h2[i + len] -
                h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

            unsigned long long key =
                (static_cast<unsigned long long>(hash1) << 32)
                | static_cast<unsigned int>(hash2);

            mp[key]++;
        }

        for(auto it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        // Precompute prefix hashes and powers
        for(int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }

        int low = 1;
        int high = n;
        int ans = n;

        // Binary search for minimum valid length
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(mid, n)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
