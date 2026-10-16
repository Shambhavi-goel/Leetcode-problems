class Solution {
public:
    const long long MOD = 1000000007;

    struct Node {
        long long sum, sq, lazy;
    };

    vector<Node> tree;
    int n;

    void build(int node, int l, int r) {
        tree[node] = {0, 0, 0};
        if (l == r) return;

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) return;

        long long v = tree[node].lazy;
        int mid = (l + r) / 2;

        for (int child : {node * 2, node * 2 + 1}) {
            long long len = (child == node * 2)
                ? mid - l + 1 : r - mid;

            tree[child].sq =
                (tree[child].sq + 2 * v * tree[child].sum
                 + v * v % MOD * len) % MOD;

            tree[child].sum =
                (tree[child].sum + v * len) % MOD;

            tree[child].lazy =
                (tree[child].lazy + v) % MOD;
        }

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            long long len = r - l + 1;
            long long v = 1;

            tree[node].sq =
                (tree[node].sq + 2 * tree[node].sum
                 + len) % MOD;

            tree[node].sum = (tree[node].sum + len) % MOD;
            tree[node].lazy = (tree[node].lazy + v) % MOD;
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(1, 0, n - 1, prev + 1, i);
            last[nums[i]] = i;

            ans = (ans + tree[1].sq) % MOD;
        }

        return ans;
    }
};