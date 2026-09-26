class Solution {
public:
bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
    int dayOfYear(string date) {
        vector<int> months(12);
        for(int i=0; i< 12; i++){
            if(i==1){
                months[i]= 28;
            }
            else if(i==3 || i==5 || i==8 || i==10){
                months[i]= 30;
            }
            else{
                months[i]= 31;
            }
        }
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if(isLeapYear(year)) {
            months[1] = 29;
        }

        int ans = day;

        for(int i = 0; i < month - 1; i++) {
            ans += months[i];
        }

        return ans;
    }
};