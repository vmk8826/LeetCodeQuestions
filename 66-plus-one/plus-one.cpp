class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>digit;
        int carry=1,i=digits.size()-1;
        while(i>=0&&carry){
          int now=digits[i]+carry;
          digit.push_back(now%10);
          i--;
          carry=now/10;
        }
        while(i>=0){
            digit.push_back(digits[i]);
            i--;
        }
        while(carry){
            digit.push_back(carry%10);
            carry=carry/10;
        }
        reverse(digit.begin(),digit.end());
        return digit;
    }
};