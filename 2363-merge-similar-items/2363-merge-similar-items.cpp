class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> items;

        for(int i=0; i< items1.size(); i++){
            items[items1[i][0]] += items1[i][1];
        }
        for(int i=0; i< items2.size(); i++){
            items[items2[i][0]] += items2[i][1];
        }
        vector<vector<int>> ans;
        for(auto x : items){
            ans.push_back({x.first, x.second});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};