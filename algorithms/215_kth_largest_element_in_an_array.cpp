class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
    const int size_n = nums.size();
    int left = 0, right = size_n;
    while (left < right) {
        int i = left, j = right - 1, povit = nums[left];
        while(i <= j) {
            while (i <= j && nums[i] >= povit) i++;
            while (i <= j && nums[j] < povit) j--;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        if (j == k - 1) return nums[j];
        if (j < k - 1) left = j + 1;
        else right = j;
    }
}
};
