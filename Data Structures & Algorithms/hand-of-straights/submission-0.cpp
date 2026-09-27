class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int,int> freq;
        for (int x : hand) freq[x]++;
        for (auto [x, count] : freq) {
            if (count == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                if (freq[x + i] < count) return false;
                freq[x + i] -= count;
            }
        }
        return true;
    }
};
