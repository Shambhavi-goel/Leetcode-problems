class Solution {
public:
bool check(string s1, string s2) {
    int a = 0, b = 0;

        for(char c : s1) {
            a |= (1 << (c - 'a'));
        }

        for(char c : s2) {
            b |= (1 << (c - 'a'));
        }

        return (a & b) == 0;
    
}
    int maxProduct(vector<string>& words) {
        int max=0;
        for(int i=0; i< words.size(); i++){
            for(int j=i+1; j< words.size(); j++){
                if((check(words[i],words[j])) && (words[i].size()*words[j].size()> max)){
                    max= words[i].size()*words[j].size();
                }
            }
        }
        return max;
    }
};