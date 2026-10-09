class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<int> copy= heights;
        sort(copy.begin(), copy.end(), greater<int>());
        for(int i=0; i< copy.size(); i++){
            for(int j=0; j< copy.size(); j++){
                if(heights[j]==copy[i]){
                    ans.push_back(names[j]);
                }
            }
        }
        return ans;
    }
};