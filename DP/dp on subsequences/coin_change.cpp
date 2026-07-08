class Solution {
    public:
        int solve(vector<int> & coins,int amount ,int i){
            if(amount<0) return INT_MAX;
            int n = coins.size();
            if(i==n){
                if(amount==0) return 0;
                return INT_MAX;
            }
            int denomination=coins[i];
            int pick=solve(coins,amount-denomination,i);
            if(pick!=INT_MAX) pick=pick+1;
            int not_pick=solve(coins,amount,i+1);
            int answer=min(pick,not_pick);
            return answer;
        }
        int solveMemo(vector<int> & coins,int amount ,int i,vector<vector<int>> & dp){
            if(amount<0) return INT_MAX;
            int n = coins.size();
            if(i==n){
                if(amount==0) return 0;
                return INT_MAX;
            }
            if(dp[i][amount]!=-1) return dp[i][amount];
            int denomination=coins[i];
            int pick=solveMemo(coins,amount-denomination,i,dp);
            if(pick!=INT_MAX) pick=pick+1;
            int not_pick=solveMemo(coins,amount,i+1,dp);
            int answer=min(pick,not_pick);
            return dp[i][amount]=answer;
        }
        int solveTabu(vector<int> & coins,int amount){
            int n= coins.size();
            vector<vector<int>> dp(n+1,vector<int>(amount+1,-2));
            for(int i=1;i<=amount;i++){
                dp[n][i]=INT_MAX;
            }
            dp[n][0]=0;
            for(int i=n-1;i>=0;i--){
                int denomination=coins[i];
                for(int j=0;j<=amount;j++){
                    int pick;
                    if(j-denomination>=0){
                        pick = dp[i][j-denomination];
                    }
                    else pick = INT_MAX;
                    if(pick!=INT_MAX) pick++;
                    int not_pick=dp[i+1][j];
                    dp[i][j]= min(pick,not_pick);
                }
            }
            if(dp[0][amount]==INT_MAX) return -1;
            return dp[0][amount];
        }
        int coinChange(vector<int>& coins, int amount) {
            //Brute Force Approach:
            // TC: O(a raised N) where a is maximum numbre of times an element is picked
            // SC: ()
            // int ans=solve(coins,amount,0);
            // if(ans==INT_MAX) return -1;
            // return ans;
    
            // memoization approach
            // TC:O(coins.size() times amount )
            // SC:O(coins.size() times amount + recursion depth)
            // int n = coins.size();
            // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
            // // minimum no of coins required to form amount j using coins from ith indice and onwards 
            // int ans=solveMemo(coins,amount,0,dp);
            // if(ans==INT_MAX) return -1;
            // return ans;
    
            // tabulation approach
            // tc : O(n*amount+amount)
            // sc: O(n*amount)
            return solveTabu(coins,amount);
        }
    
    };