class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        string ans;
        int val=0;
        for(int i=1; i< suits.size()-1; i++){
            if((suits[i]== suits[i-1]) && (suits[i] == suits[i+1])){
                val++;
            }
        }
        if(val==3){
            ans= "Flush";
            return ans;
        }
        sort(ranks.begin(), ranks.end());
        int max=0;
        for(int i=0; i< ranks.size(); i++){
            int count=1;
            for(int j= i+1; j< ranks.size(); j++){
                if(ranks[i] == ranks[j]){
                    count++;
                }
            }
            if(count> max){
                max= count;
            }
        }
        if(max>=3){
            ans= "Three of a Kind";
            return ans;
        }
        else if(max==2){
            ans= "Pair";
            return ans;
        }
        else{
            ans= "High Card";
        }
        return ans;
    }
};