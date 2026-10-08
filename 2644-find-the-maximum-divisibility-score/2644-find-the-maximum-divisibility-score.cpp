class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max=0;
        int answer= divisors[0];
        for(int i=0; i< divisors.size(); i++){
            int count=0;
            for(int j=0; j< nums.size(); j++){
                if(nums[j]%divisors[i]==0){
                    count++;
                }
            }
             if(count > max || (count == max && divisors[i] < answer)) {
                max = count;
                answer = divisors[i];
            }
        }

        return answer;
    }
};