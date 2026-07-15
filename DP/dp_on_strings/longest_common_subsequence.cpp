class Solution {
    public:
        int solve(string& s1,string& s2,int n, int m){
            if(n==-1 || m==-1){
                return 0;
            }
            char char_in_s1=s1[n];
            char char_in_s2=s2[m];
            if(char_in_s1==char_in_s2){
                return 1 + solve(s1,s2,n-1,m-1);
            }
            else{
                return max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
            }
        }
        int solveMemo(string& text1,string& text2,int n , int m,vector<vector<int>> & dp){
            if(n==-1 || m==-1){
                return 0;
            }
            if(dp[n][m]!=-1) return dp[n][m];
            char char_in_s1=text1[n];
            char char_in_s2=text2[m];
            if(char_in_s1==char_in_s2){
                return dp[n][m]=solveMemo(text1,text2,n-1,m-1,dp)+1;
            }
            return dp[n][m]=max(solveMemo(text1,text2,n-1,m,dp),solveMemo(text1,text2,n,m-1,dp));
        }
        int solveTabu(string & s1,string &s2){
            int n= s1.length();
            int m= s2.length();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            // dp[i][j]: longest common subsequence of string s1 where character only from indice 0 to i-1 are considered  and length of string s2 where character only from indice 0 to j-1 are considered
            for(int i=1;i<=n;i++){
                char char_in_s1=s1[i-1];
                for(int j=1;j<=m;j++){
                    char char_in_s2=s2[j-1];
                    if(char_in_s1==char_in_s2) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[n][m];
        }
        int longestCommonSubsequence(string text1, string text2) {
            // brute force approach:
            // time complexity: O(2 raised (n+m)) in worst cases where no character matches we may have to pick which string last character to remove first one or last one and since length of strings are n and m respectively thus 2 raised n+m is the time complexity
            // Space complexity: O(m+n) for recursion stack space
           // return solve(text1,text2,text1.length()-1,text2.length()-1);
    
           // memoization approach 
           // TC: O(nm) SC: O(nm+(n+m))
        //    int n =text1.size();
        //    int m= text2.size();
        //    vector<vector<int>> dp(n,vector<int>(m,-1));
        //    return solveMemo(text1,text2,n-1,m-1,dp);
    
        // tabualation approach
        // time complexity: O(nm) Space Complexity:O(nm)
            return solveTabu(text1,text2);
        }
    };