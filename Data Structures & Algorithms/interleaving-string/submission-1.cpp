class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n  = s1.size() ;
        int m  = s2.size() ;
        if((n+m)!=s3.size()) return false ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;
        return solve(dp,0,0,0,s1,s2,s3) ; 
    }
    bool solve(vector<vector<int>>&dp,int i,int j, int k , string& s1, string& s2,string& s3){
        if(k==s3.size()&&i==s1.size()&&j==s2.size()){
            return true ; 
        }
        else if(k==s3.size()&&(i!=s1.size()||j!=s2.size())) return false ;
        if(dp[i][j]!=-1) return dp[i][j] ; 
        bool res = false ;
        if(i<s1.size()&& s1[i]==s3[k]) res = solve(dp,i+1,j,k+1,s1,s2,s3) ; 
        if(!res&&j<s2.size()&&s2[j]==s3[k]) res = solve(dp,i,j+1,k+1,s1,s2,s3); 
        dp[i][j] = res ; 
        return dp[i][j] ; 
    }
};
