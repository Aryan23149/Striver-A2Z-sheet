class Solution {
    public:
        int solve(int i,int j,int m,int n,vector<vector<int>> & grid){
            if(i==m-1 && j==n-1) return grid[m-1][n-1];
            long long int take_down=INT_MAX,take_right=INT_MAX;
            long long int current_value=grid[i][j];
            if(j<n-1){
                take_right=solve(i,j+1,m,n,grid)+current_value;
            }
            if(i<m-1){
                take_down=solve(i+1,j,m,n,grid)+ current_value;
            }
            return min(take_right,take_down);
        }
        int solveMemo(int i ,int j , int m,int n , vector<vector<int>> & grid,vector<vector<int>> &dp){
            if(i==m-1 && j==n-1) return dp[m-1][n-1]=grid[m-1][n-1];
            if(dp[i][j]!=-1) return dp[i][j];
            long long int take_down=INT_MAX,take_right=INT_MAX;
            long long int current_value=grid[i][j];
            if(j<n-1){
                take_right=solveMemo(i,j+1,m,n,grid,dp)+current_value;
            }
            if(i<m-1){
                take_down=solveMemo(i+1,j,m,n,grid,dp)+ current_value;
            }
            return dp[i][j]=min(take_right,take_down); 
        }
        int solveTabu(vector<vector<int>> & grid){
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<long long int>> dp(m,vector<long long int> (n,-1));
            dp[m-1][n-1]=grid[m-1][n-1];
            for(int i=m-1;i>=0;i--){
                for(int j = n-1;j>=0;j--){
                    if(i==m-1 && j==n-1) continue;
                    long long int take_down=INT_MAX,take_right=INT_MAX;
                    long long int current_value=grid[i][j];
                    if(j<n-1){
                        take_right=dp[i][j+1]+current_value;
                    }
                    if(i<m-1){
                        take_down=dp[i+1][j]+current_value;
                    }
                    dp[i][j]=min(take_right,take_down);
                }
            }
            return dp[0][0];
        }
        int minPathSum(vector<vector<int>>& grid) {
            // brute force approach
            // tc: O(2^(m+n)) length of maximum path is m+n-2 and for each cell on the path we have 2 choices whether to move right or move down
            // sc: O(m+n) recursion stack space : as maximum depth of recursion shall be m+n-2
            // int m= grid.size();
            // int n= grid[0].size();
            // return solve(0,0,m,n,grid);
    
            // memoization
            //tc: O(mn) for initialization of dp array and solving mn subproblems taking constant time each
            //sc: O((mn)+(m+n))=O(mn) for dp array and recursion stack space
            // int m= grid.size();
            // int n = grid[0].size();
            // vector<vector<int>>  dp(m,vector<int> (n,-1));
            // return solveMemo(0,0,m,n,grid,dp);
    
            // tabulation
            // tc: O(mn) for initialization of dp array + solving mn subproblems where each problem requiires constant time to be solved
            // sc : O(mn ) for dp array storing subproblems solution
            
            return solveTabu(grid);
        }
    }; 