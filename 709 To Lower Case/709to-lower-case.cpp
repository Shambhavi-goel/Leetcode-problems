class Solution {
public:
    string toLowerCase(string s) {
        string t;
        for(int i=0; i< s.length(); i++){
            int n= (int)s[i];
            if(n>= 65 && n<=90){
            int a= n+32;
            t.push_back((char)a);
            }
            else{
            t.push_back((char)n); 
            } 
        }
        return t;
    }
};