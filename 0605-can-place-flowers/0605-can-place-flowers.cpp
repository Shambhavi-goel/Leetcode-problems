class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
         if(flowerbed.size() == 1) {
            if(flowerbed[0] == 0)
                count++;
            return count >= n;
        }
        for(int i=0; i< flowerbed.size(); i++){
            if(i==0 && flowerbed[i]==0 && flowerbed[i+1]!=1){
                flowerbed[i]=1;
                count++;
            }
            else if(i== flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]!=1){
                flowerbed[i]=1;
                count++;
            }
            else if(i > 0 && i < flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                flowerbed[i]=1;
                count++;
            }
        }
        if(count >=n){
            return true;
        }
        return false;
    }
};