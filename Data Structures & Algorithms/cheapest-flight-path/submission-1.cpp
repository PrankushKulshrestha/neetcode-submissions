class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1001);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp;
            temp=dist;
            for(int i=0;i<flights.size();i++){
                if(dist[flights[i][0]]>1000)continue;
                if(dist[flights[i][0]]+flights[i][2]<temp[flights[i][1]]){
                    temp[flights[i][1]]=dist[flights[i][0]]+flights[i][2];
                }
                
            }
            dist=temp;
        }
        return (dist[dst]>1000)?-1:dist[dst];
    }
};
