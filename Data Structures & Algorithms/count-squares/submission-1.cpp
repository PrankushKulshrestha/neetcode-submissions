class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> pnt;
    CountSquares() {
        //
    }
    
    void add(vector<int> point) {
        pnt[point[0]][point[1]]++; //x,y++
    }
    
    int count(vector<int> point) {
        int x = point[0]; //check for this x axis
        int side;
        int res = 0;
        int mlt = 1;

        for(auto [y, cnt] : pnt[x]){
            //all y axis and counts

            mlt = cnt;
            side = abs(point[1] - y);  //add this side
            if(side == 0)
                continue;
            //calculate other 2 points
            if((pnt[x+side].find(y) != pnt[x+side].end())
                && (pnt[x+side].find(point[1]) != pnt[x+side].end())){
                    mlt = mlt * pnt[x+side][y] * pnt[x+side][point[1]];

                    res += mlt;
            }

            mlt = cnt;
            if((pnt[x-side].find(y) != pnt[x-side].end())
                && (pnt[x-side].find(point[1]) != pnt[x-side].end())){
                    mlt = mlt * pnt[x-side][y] * pnt[x-side][point[1]];

                    res += mlt;
            }
        }

        return res;
    }
};
