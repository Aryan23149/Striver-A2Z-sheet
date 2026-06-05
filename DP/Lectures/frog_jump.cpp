
#include <bits/stdc++.h> 
// problem solved on coding ninjas named frog jump
// int solveFrogJump(int index,int n,vector<int> &heights){
//     if(index==n-1){
//         return 0;
//     }
//     int jump1= abs(heights[index+1]-heights[index]) + solveFrogJump(index+1,n,heights);
//     int jump2= INT_MAX;
//     if(index+2<n){
//         jump2=abs(heights[index+2]-heights[index]) + solveFrogJump(index+2,n,heights);
//     }
//     return min(jump1,jump2);
// }
// int solveFrogJumpMemo(int index,int n,vector<int> &heights,vector<int> &dp){
//     if(index==n-1){
//         return 0;
//     }
//     if(dp[index]!=-1){
//         return dp[index];
//     }
//     int jump1= abs(heights[index+1]-heights[index]) + solveFrogJumpMemo(index+1,n,heights,dp);
//     int jump2= INT_MAX;
//     if(index+2<n){
//         jump2=abs(heights[index+2]-heights[index]) + solveFrogJumpMemo(index+2,n,heights,dp);
//     }
//     dp[index]=min(jump1,jump2);
//     return dp[index];
// }
int solveFrogJumpTabu(int n,vector<int> &heights,vector<int> &dp){
    for(int i=n-1;i>=1;i--){
        int jump1=abs(heights[i-1]-heights[i]) + dp[i+1]; 
        int jump2 =INT_MAX;
        if(i+2<=n){
            jump2=abs(heights[i-1]-heights[i+1])+ dp[i+2];
        }
        dp[i]=min(jump1,jump2);
    }
    return dp[1];
}
int solveFrogJumpOptimizedTabu(int n,vector<int> &heights){
    int next1=0;
    int next2=0;
    int current;
    for(int i=n-2;i>=0;i--){
        int jump1=abs(heights[i]-heights[i+1]) + next1;
        int jump2 =INT_MAX;
        if(i+2<n){
            jump2=abs(heights[i]-heights[i+2])+ next2;
        }
        current=min(jump1,jump2);
        next2=next1;
        next1=current;
    }
    return current;
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // brute force : tc:O(2*n) sc: O(n)
    // return solveFrogJump(0,n,heights);

    // using memoization
    // tc: O(n) SC:O(n+n+n)
    // int n=height.size();
    // vector<int> dp(n,-1);
    // return solveFrogJumpMemo(0,n,height,dp);

    //using tabulation
    // tc: O(n)  for fillinng up the dp array 
    //SC:O(N+N) for storing min cost to go from (i+1)th stair to nth stair array and n for heights array
    //  int n = height.size();
    // vector<int> dp(n+1,-1); for 
    // dp[n]=0;
    // return solveFrogJumpTabu(n,heights,dp);

    // using optimized space and tabulation
    // tc: O(N) and sc(O(1))
    int n=height.size();
    return solveFrogJumpOptimizedTabu(n,heights);
}