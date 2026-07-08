// coding ninjas: https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
#include <bits/stdc++.h>
int mod = 1e9+7; 
int solve(vector<int> & arr, int i ,int n, int s1,int s2,int d){
    if(i==n){
        if(s1-s2==d){
            return 1;
        }
        return 0;
    }
    int element=arr[i];
    int pick=solve(arr,i+1,n,s1+element,s2-element,d)%mod;
    int not_pick=solve(arr,i+1,n,s1,s2,d)%mod;
    return (pick+not_pick)%mod;
}
int solveMemo(vector<int> & arr,int i,int n,int s1,int s2,int d,vector<vector<int>> &dp){
    if(i==n){
        if(s1-s2==d){
            return 1;
        }
        return 0;
    }
    if(dp[i][s1]!=-1) return dp[i][s1];
    int element=arr[i];
    int pick=solveMemo(arr,i+1,n,s1+element,s2-element,d,dp)%mod;
    int not_pick=solveMemo(arr,i+1,n,s1,s2,d,dp)%mod;
    return dp[i][s1]=(pick+not_pick)%mod;
}
int solveTabu(vector<int> & arr,int d){
    int n= arr.size();
    int sum=0;
    for(int i : arr) sum+=i;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    //dp[i][j]=count of partitions made from index i to n-1 such that s1-s2=d given s1 accumulated before index i is j
    for(int j=0;j<=sum;j++){
        int s1=j;
        int s2=sum-j;
        if(s1-s2==d){
            dp[n][j]=1;
        }
        else dp[n][j]=0;
    }
    for(int i=n-1;i>=0;i--){
        int element= arr[i];
        for(int j=sum;j>=0;j--){
            int pick=0;
            if(j+element<=sum){
                pick=dp[i+1][j+element]%mod;
            }
            int not_pick=dp[i+1][j]%mod;
            dp[i][j]=(pick+not_pick)%mod;
        }
    }
    return dp[0][0]%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Brute Force Approach
    // pick or not pick Approach for the subset 1 corresponding to partition 1
    // time complexity: O(2 raised n) for each elements two choices
    /// space complexity :O(n) due to recursion stack space 
    // int s2=0;
    // for(int i: arr) s2+=i;
    // return solve(arr,0,n,0,s2,d);

    //Memoization Approach
    // time complexity: O(n*k) space complexity:O(nk+n)
    // int s2=0;
    // for(int i: arr) s2+=i;
    // vector<vector<int>> dp(n,vector<int> (s2+1,-1));
    // // dp[i][j] = sum of subset 1 - sum of subset 2 elements
    // // picked from index i to n-1 while current sum of subset 1 
    // //elements which have already been picked from index till indice i-1 is j
    // return solveMemo(arr,0,n,0,s2,d,dp);

    // time complexity:O(nk) Space complexity: O(nk)
    return solveTabu(arr,d);
}
