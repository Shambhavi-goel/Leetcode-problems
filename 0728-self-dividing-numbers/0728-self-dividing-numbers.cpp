class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> ans;
      for(int i= left; i<= right; i++){
        int flag=0;
        int j=i;
        while(j > 0){
            int r= j % 10;
            j= j/10;
            if(r==0){
                flag=1;
            }
            if(r!=0 && i % r != 0){
                flag=1;
            }
        }
        if(flag==0){
            ans.push_back(i);
        }
      }  
      return ans;
    }
};