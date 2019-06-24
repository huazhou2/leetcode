class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix,0, matrix.size()*matrix[0].size()-1,target);
        
    }
    bool binarySearch(vector<vector<int> >& nums, int left, int right, int target) {
        if (left==right) 
            return (nums[left/nums[0].size()][left%nums[0].size()]==target);
        else if (left>right) return false;
        int mid=(left+right)/2;
        int row_idx=mid/nums[0].size(), col_idx=mid%nums[0].size();
        if (nums[row_idx][col_idx]==target) return true;
        else if (nums[row_idx][col_idx]>target) return binarySearch (nums,left,mid-1,target);
        else return binarySearch(nums,mid+1,right,target);
    }

};
