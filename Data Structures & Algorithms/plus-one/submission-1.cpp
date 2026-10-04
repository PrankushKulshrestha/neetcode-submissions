class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        for(;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                break;
            }
            digits[i]=0;
        }
        if(i<0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
