class Solution {
    public:
        int solve(vector<vector<int>> & obstacleGrid,int i , int j,int m , int n){
            if(obstacleGrid[i][j]==1) return 0;
            if(i==m-1 && j==n-1 ) {
                return 1;
            }
            int take_right=0;
            int take_down=0;
            if(j<n-1) take_right= solve(obstacleGrid,i,j+1,m,n);
            if(i<m-1) take_down=solve(obstacleGrid,i+1,j,m,n);
            return take_right+take_down;
        }
        int solveMemo(vector<vector<int>> & grid,int i , int j , int m, int n , vector<vector<int>> & dp){
            if(grid[i][j]==1) return dp[i][j]=0;
            if(i==m-1 && j==n-1) return dp[i][j]=1;
            if(dp[i][j]!=-1) return dp[i][j];
            int take_right=0;
            int take_down=0;
            if(j<n-1){
                take_right=solveMemo(grid,i,j+1,m,n,dp);
            }
            if(i<m-1){
                take_down=solveMemo(grid,i+1,j,m,n,dp);
            }
            return dp[i][j]=take_right+take_down;
        }
        int solveTabu(vector<vector<int>> & grid){
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<long long int >> dp(m,vector<long long int> (n,-1));
            if(grid[m-1][n-1]==0) dp[m-1][n-1]=1;
            else return 0;
            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i==m-1 && j ==n-1 ) continue;
                    if(grid[i][j]==1){
                        dp[i][j]=0;
                        continue;
                    }
                    long long int take_right =0;
                    long long int take_down =0;
                    if(j<n-1){
                        take_right=dp[i][j+1];
                    }
                    if(i<m-1){
                        take_down=dp[i+1][j];
                    }
                    dp[i][j]= take_right+take_down;
                }
            }
            return dp[0][0];
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            // brute force approach: 
            // Time Complexity: O(2 ^ (m+n))// length of required path from 0,0 to m-1,n-1 is m+n and thus for every cell along the way we have got two choices....whether to move right or down
            // Space Complexity: O(m+n) for recursion stack space
            // int m = obstacleGrid.size();
            // int n= obstacleGrid[0].size();
            // return solve(obstacleGrid,0,0,m,n);
    
            // memoization dp approach:
            // Time Complexity: O(mn) for initializing the dp array and solving all subproblems
            // Space Complexity: O(mn + (m+n)) for dp 2d array and recursion stack space
            // int m= obstacleGrid.size();
            // int n = obstacleGrid[0].size();
            // vector<vector<int>> dp(m,vector<int>(n,-1));
            // return solveMemo(obstacleGrid,0,0,m,n,dp);
            // tabulation dp approach:
    
            // tabulation approach 
            // time complexity : O(mn)... each subproblem is computed once in constant time complexity and there are mn number of subproblems
            // space complexity : O(mn)...storing all subproblems in dp array 
            return solveTabu(obstacleGrid);
        }
    };