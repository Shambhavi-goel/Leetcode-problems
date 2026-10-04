class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long int sum=0;
        for(int i=1; i<= k; i++){
            int maximum = max_element(gifts.begin(), gifts.end())-gifts.begin();
            int max= *max_element(gifts.begin(), gifts.end());
            gifts[maximum]= sqrt(max);
        }
        for(int i=0; i< gifts.size(); i++){
            sum += gifts[i];
        }
        return sum;
    }
};