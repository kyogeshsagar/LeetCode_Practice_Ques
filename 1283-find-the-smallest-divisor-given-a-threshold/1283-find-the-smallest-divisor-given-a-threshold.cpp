class Solution {
public:
    int findMax(vector<int>& nums) {
        int maxi = nums[0];
        for (int x : nums)
            maxi = max(maxi, x);
        return maxi;
    }

    int calculateSum(vector<int>& nums, int divisor) {
        int sum = 0;

        for (int x : nums) {
            sum += (x + divisor - 1) / divisor;   // ceil(x/divisor)
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calculateSum(nums, mid) <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};