#include <bits/stdc++.h> 
bool solve(vector<int> & arr, int k,int i ,int n){
    if(k<0) return false;
    if(i==n){
        if(k==0) return true;
        return false;
    };
    bool pick,not_pick;
    pick=solve(arr,k-arr[i],i+1,n);
    if(pick==true) return true;
    not_pick=solve(arr,k,i+1,n);
    if(not_pick==true) return true;
    return false;
}

bool solveMemo(vector<int> & arr, int k,int i ,int n,vector<vector<int>> &dp){
    if(k<0) return false;
    if(i==n){
        if(k==0) return true;
        return false;
    };
    if(dp[i][k]!=-1){return dp[i][k];}
    bool pick,not_pick;
    pick=solveMemo(arr,k-arr[i],i+1,n,dp);
    if(pick==true) return bool(dp[i][k]=1);;
    not_pick=solveMemo(arr,k,i+1,n,dp);
    if(not_pick==true) return bool(dp[i][k]=1);
    return bool(dp[i][k]=0);
}
bool solveTabu(int n ,int k , vector<int> & arr){
    if(k<0) return false;
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    for(int i=k;i>=1;i--){
        dp[n][i]=0;
    }
    dp[n][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=k;j>=0;j--){

            bool pick,not_pick;

            int sum=j-arr[i];
            if(sum<0){
                pick=false;
            }
            else pick=bool(dp[i+1][sum]);

            not_pick=bool(dp[i+1][j]);

            if(pick || not_pick) dp[i][j]=1;
            else dp[i][j]=0;
        }
    }
    return bool(dp[0][k]);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // brute force appraoch: tc: O(2^n) and sc: O(n)
    // return solve(arr,k,0,n);

    // memoization
    // tc: O(N*K) for solving n*k subproblems solving each once using constant time hence total O(NK)
    //  sc: O(N*K + n for storing nk subproblems solutions and maximum recustion depth is O(N)
   // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // dp[i][j] means can we gather sum j from index i to n-1 using pick or not pick approach
    // recurrence: dp[i][j]=dp[i+1][j-arr[i]] + dp[i+1][j]
   // return bool(solveMemo(arr,k,0,n,dp));
// tabulation approach tc: O(nk) sc : O(nk)
   return solveTabu(n,k,arr);
}