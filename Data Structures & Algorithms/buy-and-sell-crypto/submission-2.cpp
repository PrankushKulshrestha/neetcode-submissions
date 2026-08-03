class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=0;i<prices.size();i++){
            int buy=prices[i];
            for(int j=i+1;j<prices.size();j++){
                int sell=prices[j];
                res=max(res,sell-buy);
            }
        }
        return res;
    }
};
