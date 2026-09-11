class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> freq;

        for(int i=0; i< arr.size(); i++){
            freq[arr[i]]++;
        }

        for(int i=0; i< arr.size(); i++){
            int target = arr[i] * 2;

            if(freq.find(target) != freq.end()){
                if(target != arr[i] || freq[target] > 1){
                    return true;
                }
            }
        }
        return false;
    }
};