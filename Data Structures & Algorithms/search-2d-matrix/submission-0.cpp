class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                temp.push_back(matrix[i][j]);
            }
        }
        int left = 0;
        int right = temp.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (temp[mid] == target) {
                return true;
            }
            else if (temp[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};
