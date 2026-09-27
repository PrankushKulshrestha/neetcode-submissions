class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i=0; i<cost.size(); i++) {
            gas[i] -= cost[i];
        }
        int l=0, r=0;
        int cur_gas = 0;
        int len = 0;
        while (len < gas.size()) {
            if (cur_gas >= 0) {
                cur_gas += gas[r];
                r = (r+1) % gas.size();
            } else {
                l = (l-1+gas.size()) % gas.size();
                cur_gas += gas[l];
            }
            len++;
        }
        if (cur_gas < 0) {
            return -1;
        }
        return l;
    }
};
