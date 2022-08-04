class Solution {
public:
    
    uint32_t reverseBits(uint32_t n, uint32_t digit) {
        if(digit == 0) return n%2; 
        return (n%2)<< digit|reverseBits(n>>1, digit-1);
    }
    uint32_t reverseBits(uint32_t n) {
        return reverseBits(n, 31);
    }
};
