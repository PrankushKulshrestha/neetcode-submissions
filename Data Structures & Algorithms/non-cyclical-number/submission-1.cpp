class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            int temp=n;
            int sum=0;
            while(temp>0){
                int digit=temp%10;
                sum+=digit*digit;
                temp=temp/10;
            }
            n=sum;
        }
        return n==1;
    }
};
