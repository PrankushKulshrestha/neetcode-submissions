class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> a(26, 0);
        for(auto i:s){
            a[i-'a']+=1;
        }
        for(auto i:t){
            a[i-'a']-=1;
        }
        int ans=1;
        for(auto i:a){
            if(i!=0){
                ans=0;
                break;
            }
        }
        return ans;
    }
};
