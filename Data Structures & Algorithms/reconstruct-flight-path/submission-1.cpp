class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> a;

        for(const auto& t:tickets){
            a[t[0]].push_back(t[1]);
        }
        for (auto& [s,d]:a){
            sort(d.rbegin(),d.rend());
        }
        vector<string> res;
        stack<string> stk;
        stk.push("JFK");

        while(!stk.empty()){
            string curr = stk.top();
            if(a[curr].empty()){
                res.push_back(curr);
                stk.pop();
            }
            else{
                string nxt = a[curr].back();
                a[curr].pop_back();
                stk.push(nxt);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
