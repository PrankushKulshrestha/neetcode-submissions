class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> g(26);
        vector<int> indegree(26,0);
        vector<int> present(26,0);
        for(auto& w:words)
            for(char c:w) present[c-'a']=1;
        for(int i=0;i+1<words.size();i++){
            string& a=words[i];
            string& b=words[i+1];
            int n=min(a.size(),b.size());
            int j=0;
            while(j<n&&a[j]==b[j]) j++;
            if(j==n){
                if(a.size()>b.size()) return "";
                continue;
            }
            int u=a[j]-'a',v=b[j]-'a';
            g[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<26;i++)
            if(present[i]&&indegree[i]==0) q.push(i);
        string ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans+=char('a'+u);
            for(int v:g[u])
                if(--indegree[v]==0) q.push(v);
        }
        int count=0;
        for(int x:present) count+=x;
        return ans.size()==count?ans:"";
    }
};
