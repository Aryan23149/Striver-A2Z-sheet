class Solution {
    // solved On gfg: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
public:
int solve(string &s1, string &s2,int n ,int m,int lcs){
    if(n==-1 || m==-1) {
        return lcs;
    }
    int char_in_s1=s1[n];
    int char_in_s2=s2[m];
    if(char_in_s1==char_in_s2){
        return solve(s1,s2,n-1,m-1,lcs+1);
    }
    else{
        return max(max(solve(s1,s2,n-1,m,0),solve(s1,s2,n,m-1,0)),lcs);
    }
}
int solveMemo(string &s1,string &s2, int i,int j,vector<vector<int>> & dp){
    if(i==-1 || j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int char_in_s1=s1[i];
    int char_in_s2=s2[j];
    if(char_in_s1==char_in_s2){
        return dp[i][j] =solveMemo(s1,s2,i-1,j-1,dp)+1;
    }
    else{
        return dp[i][j] =0;
    }
}
int solveTabu(string s1,string s2){
    int n= s1.length();
    int m= s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int i=1;i<=n;i++){
        int char_in_s1=s1[i-1];
        for(int j=1;j<=m;j++){
            int char_in_s2=s2[j-1];
            if(char_in_s1==char_in_s2){
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}
int longCommSubstr(string& s1, string& s2) {
    // code here
    // time complexity: O(2 raised N+M)
    // space complexity: O(m+n)
    //return solve(s1,s2,s1.length()-1,s2.length()-1,0);
    
    // memoization
    // time complexity: O(nm)
    // space complexity:O(nm+(n+m))
    // int n = s1.length();
    // int m= s2.length();
    // vector<vector<int>> dp(n,vector<int> (m,-1));
    // // dp[i][j] : if we considers first i+1 character of string 1 and first y+1 characters of string y then dp[i][j] means
    // // length of lcs of these two strings meaning lcs character must include character at i th index in string 1 and character at jth index in string 2

    // int ans =INT_MIN;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         ans=max(ans,solveMemo(s1,s2,i,j,dp));
    //     }
    // }
    // return ans;
    
    // Tabulation Approach:
    // Time Complexity: O(nm) Space Complexity: O(nm)
    return solveTabu(s1,s2);
}
};