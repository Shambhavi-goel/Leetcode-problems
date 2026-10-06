class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        double mean=0;
        int val= arr.size()*0.05;
        for(int i=val; i< arr.size()-val; i++){
            mean += arr[i];
        }
        mean /= arr.size()-2*val;
        return mean;
    }
};