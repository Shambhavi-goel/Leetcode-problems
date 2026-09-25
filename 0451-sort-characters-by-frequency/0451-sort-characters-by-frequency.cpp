class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(int i=0; i< s.size(); i++){
            freq[s[i]]++;
        }
        vector<pair<char, int>> v;

        for(auto x : freq) {
            v.push_back({x.first, x.second});
        }

        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        string ans = "";
        for(auto x : v) {
            for(int i = 1; i <= x.second; i++) {
                ans += x.first;
            }
        }
        return ans;
    }
};