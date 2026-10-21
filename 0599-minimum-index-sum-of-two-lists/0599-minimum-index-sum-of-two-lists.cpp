class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<vector<int>> ans;
        vector<string> final_ans;
        for(int i=0; i< list1.size(); i++){
            for(int j=0; j< list2.size(); j++){
                if(list1[i]==list2[j]){
                    ans.push_back({i,j});
                }
            }
        }
        int min= INT_MAX;
        for(int i=0; i< ans.size(); i++){
             int sum = ans[i][0] + ans[i][1];

            if(sum < min) {
                min = sum;
                final_ans.clear();
                final_ans.push_back(list1[ans[i][0]]);
            }
            else if(sum == min) {
                final_ans.push_back(list1[ans[i][0]]);
            }
        }
        return final_ans;
    }
};