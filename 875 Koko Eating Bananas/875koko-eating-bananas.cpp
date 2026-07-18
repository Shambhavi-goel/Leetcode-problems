class Solution {
public:
    long long int caltotalhours(vector<int> &piles, int mid){
        long long int totalhours=0;
        for(int i=0; i< piles.size(); i++){
            totalhours += ceil((double)piles[i]/(double)mid);
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high= *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid= low + (high-low)/2;
            long long int totalhours = caltotalhours(piles, mid);

            if(totalhours<=h){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};