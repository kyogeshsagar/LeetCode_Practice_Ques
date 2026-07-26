class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case: (-2^31) / (-1) = 2^31
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of answer
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long before taking absolute value
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Find largest divisor * 2^k <= a
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        if (negative) {
            ans = -ans;
        }

        return (int)ans;
    }
};