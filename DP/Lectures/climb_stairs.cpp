#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(46,-1);
vector<int> tabulation_dp(46,0);
int solveClimbStairUsingOptimizedTabulation(int n){
    if(n<0){return -1;}
    int prev1=1;
    int prev2=1;
    int current;
    for(int i=2;i<=n;i++){
        current=prev1+prev2;
        prev1=prev2;
        prev2=current;
    }
    return current;
}
int solveClimbStairsUsingTabulation(int n,vector<int> &tabulation_dp){
    if(n<0){return -1;}
    tabulation_dp[0]=1;
    tabulation_dp[1]=1;
    for(int i=2;i<=n;i++){
        tabulation_dp[i]=tabulation_dp[i-1]+tabulation_dp[i-2];
    }
    return tabulation_dp[n];
}

int solveClimbStairsUsingMemoization(int n,vector<int> & dp){
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=solveClimbStairsUsingMemoization(n-1,dp) + solveClimbStairsUsingMemoization(n-2,dp);
    return dp[n];
}
int climbStairs(int n){
    // brute force approach 
    // time complexity:O(2 raised n) as solving recurrance takes this much time 
    // space complexity:O(n) as depth of recursion is n at maximum
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    int num_of_ways=climbStairs(n-1)+climbStairs(n-2);
    return num_of_ways;
}
int main(){
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    cout<<solveClimbStairsUsingMemoization(n,dp)<<endl;
    cout<<solveClimbStairsUsingTabulation(n,tabulation_dp)<<endl;
    cout<<solveClimbStairUsingOptimizedTabulation(n)<<endl;
    return 0;
}