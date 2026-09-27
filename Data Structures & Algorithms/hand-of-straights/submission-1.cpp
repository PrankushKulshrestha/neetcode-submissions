class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        int maxele = *max_element(hand.begin(), hand.end());
        vector<int> v(maxele + groupSize);
        for (int x : hand) v[x]++;
        for (int i = 0; i <= maxele; i++) {
            if (v[i] == 0) continue;
            int cnt = v[i];
            for (int j = i; j < i + groupSize; j++) {
                v[j] -= cnt;
                if (v[j] < 0) return false;
            }
        }
        return true;
    }
};
