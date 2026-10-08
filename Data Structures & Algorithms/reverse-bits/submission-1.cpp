class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        int new_n = 0;
        int pw = 31;
        while (n > 0) {
            int carry = (n & 1);
            n = n >> 1;
            new_n += carry * pow(2, pw);
            pw--;
        }
        return new_n;
    }
};
