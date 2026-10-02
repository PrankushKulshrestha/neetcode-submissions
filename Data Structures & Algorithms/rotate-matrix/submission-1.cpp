// O(n^2) time to visit each cell 
// O(1) space
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int T = 0, B = n-1, L = 0, R = n-1;
        while( L < R )
        {
            // rotation by layer, the offset should start at 0
            // starting with the outer layer, rotate all cells from L to R-1
            // the offset is for the cell we rotate next to the corner
            for(int i = 0; i < R-L; ++i)
            {
                // top left -> top right
                int temp = matrix[T+i][R];
                matrix[T+i][R] = matrix[T][L+i];

                // top right -> bottom right
                int temp1 = matrix[B][R-i]; //store bottom right
                matrix[B][R-i] = temp;

                // bottom right -> bottom left 
                temp = matrix[B-i][L];
                matrix[B-i][L] = temp1;

                // bottom left -> top left 
                matrix[T][L+i] = temp; 
            }
            ++L; 
            ++T; 
            --R;
            --B;
        }
    }
};
