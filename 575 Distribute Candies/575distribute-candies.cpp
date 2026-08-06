class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n= candyType.size()/2;
        unordered_map<int, int> freq;
        for(int x: candyType){
            freq[x]++;
        }
        int unique_candies= freq.size();
        return min(n, unique_candies);
    }
};