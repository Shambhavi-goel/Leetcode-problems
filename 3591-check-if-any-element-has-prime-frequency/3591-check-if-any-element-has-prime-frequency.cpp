class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        for(int i=0; i< nums.size(); i++){
            int f = freq[nums[i]];
            bool prime = true;

            if(f < 2)
                prime = false;

            for(int j = 2; j <= f / 2; j++) {
                if(f % j == 0) {
                    prime = false;
                    break;
                }
            }

            if(prime)
                return true;
        }
        return false;
    }
};