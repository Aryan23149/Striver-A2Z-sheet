class Solution {
    public:
        int solve(vector<int> & coins,int amount ,int i){
            if(amount<0) return 0;
            if(i==coins.size()){
                if(amount==0){
                    return 1;
                }
                return 0;
            }
            int coin= coins[i];
            int pick=solve(coins,amount-coin,i);
            int not_pick=solve(coins,amount,i+1);
            return pick + not_pick;
        }
        int solveMemo(vector<int> & coins,int amount , int i ,vector<vector<int>> & dp){
            if(amount<0) return 0;
            if(i==coins.size()){
                if(amount==0){
                    return 1;
                }
                return 0;
            }
            if(dp[i][amount]!=-1) return dp[i][amount];
            int coin= coins[i];
            int pick=solveMemo(coins,amount-coin,i,dp);
            int not_pick=solveMemo(coins,amount,i+1,dp);
            return dp[i][amount]=pick + not_pick;
        }
    
    
    
        int solveTabu(vector<int> & coins, int amount){
            long long int n =coins.size();
            vector<vector<long long int>> dp(n+1,vector<long long int> (amount+1,0LL));
            for(int i = 0; i <= n; i++){
                dp[i][0] = 1;
            }
            for(int i=n-1;i>=0;i--){
                long long int coin = coins[i];
                for(int j=1;j<=amount;j++){
                    long long int remaining_amount_if_picked=j-coin;
                    long long int pick;
                    if(remaining_amount_if_picked<0){
                        pick=0;
                    }
                    else{
                        pick = dp[i][remaining_amount_if_picked];
                    }
                    long long int not_pick=dp[i+1][j];
                    if (pick + not_pick > INT_MAX) {
                        dp[i][j] = (long long int)INT_MAX + 1; 
                    } else {
                        dp[i][j] = pick + not_pick;
                    }
    
                }
            }
            return (int)dp[0][amount];
        }
    
    
        int change(int amount, vector<int>& coins) {
            // brute force approach
            // time complexity : O(2^N)
            // space complexity: O(N)
            //return solve(coins,amount,0);
    
            // memoization apporach
            // Time complexity: O(n*amount)  for solving n*amount number of subproblems each requiring constant time
            // Space complexity: O(n*amount + n) for dp array and recursion stack space
            // int n = coins.size();
            // vector<vector<int>> dp(n,vector<int> (amount+1,-1));
            // dp[i][j] here represents number of ways of having amount j using coins from index i and onwards
            // return solveMemo(coins,amount,0,dp);
    
            // tabulation approach
            // Time complexity: O(n*amount)  for solving n*amount number of subproblems each requiring constant time
            // Space complexity: O(n*amount) for dp array
            return solveTabu(coins,amount);
        }
    };