class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i=0; i< arr.size(); i++){
            freq[arr[i]]++;
        }
        int max=-1;
        for(int i=0; i< arr.size(); i++){
            if(freq[arr[i]] > max && (freq[arr[i]] == arr[i])){
                max= arr[i];
            }
        }
        return max;
    }
};