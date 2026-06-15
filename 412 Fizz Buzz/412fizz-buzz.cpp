class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=0; i<n; i++){
            if((i+1)%3==0 && (i+1)%5==0){
                answer.push_back("FizzBuzz");
            }
            if((i+1)%3==0 && (i+1)%5!=0){
                answer.push_back("Fizz");
            }
            if((i+1)%3!=0 && (i+1)%5==0){
                answer.push_back("Buzz");
            }
            if((i+1)%3!=0 && (i+1)%5!=0){
                answer.push_back(to_string(i+1));
            }
        }
        return answer;
    }
};