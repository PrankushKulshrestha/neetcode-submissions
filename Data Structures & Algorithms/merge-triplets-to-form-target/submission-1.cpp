class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        bool foundI = 0;
        bool foundJ = 0;
        bool foundK = 0;

        for(int i = 0 ; i < n ; i++){

            if(triplets[i][0] > target[0] ||
            triplets[i][1] > target[1] || 
            triplets[i][2] > target[2] ){
                continue;
            }

            if(triplets[i][0] == target[0]){
                foundI = 1;
            }
            if(triplets[i][1] == target[1]){
                foundJ = 1;
            }
            if(triplets[i][2] == target[2]){
                foundK = 1;
            }

        }

        return foundI && foundJ && foundK;
    }
};
