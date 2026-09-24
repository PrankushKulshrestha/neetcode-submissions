class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n==0 || m==0) return m==0?n:m;

        // dp[i][j] - min no. of operations needed to make word1[..i] equal word2[..j]
        // dp[i][j]:
        //    dp[i-1][j-1]     if word1[i]==word2[j]
        //    dp[i-1][j-1]+1   if word1[i]!=word2[j]
        //    dp[i][j-1]+1
        //    dp[i-1][j]+1

        // vector<vector<int>>dp(n+1, vector<int>(m+1,INT_MAX));
        // dp[0][0] = 0;
        // for(int i=1; i<=n; i++) dp[i][0]=i;
        // for(int j=1; j<=m; j++) dp[0][j]=j;
        // vector<int>odp(m+1, INT_MAX);
        // odp[0] = 0;
        // for(int i=1; i<=m; i++) odp[i] = i;
        
        vector<int>dp(m+1, INT_MAX);
        for(int i=0; i<=m; i++) dp[i] = i;
        for(int i=1; i<=n; i++) {
            // vector<int>ndp(m+1, INT_MAX);
            // ndp[0] = i;
            int diag = i-1;
            dp[0] = i;
            for(int j=1; j<=m; j++) {
                char c1 = word1[i-1];
                char c2 = word2[j-1];

                int temp = dp[j]; 
                dp[j] = diag;
                if(c1!=c2) dp[j]++;

                dp[j] = min(dp[j], min(dp[j-1]+1, temp+1));
                diag = temp;
                // ndp[j] = odp[j-1];
                // if(c1!=c2) ndp[j]++;
                // ndp[j] = min(ndp[j], min(ndp[j-1]+1, odp[j]+1));
                // dp[i][j] = dp[i-1][j-1];
                // if(c1!=c2) dp[i][j]++;
                // dp[i][j] = min(dp[i][j], min(dp[i][j-1]+1, dp[i-1][j]+1));
            }
            // odp = ndp;
        }
        // return dp[n][m];
        // return odp[m];
        return dp[m];
    }
};
