class Solution {
    public:
        int solve(int m,int n,int i,int j){
            if(i==m-1 && j == n-1){// are we at our target location
                return 1;// if yes then enter here and return 1
            }
            int take_right=0;// one choice is to go right
            int take_down=0;// other to go down
            if(j<n-1){// if we can go right 
                take_right=solve(m,n,i,j+1);// this tells us all the ways from right to target
            }
            if(i<m-1){// if we can go down
                take_down=solve(m,n,i+1,j);// this tellus du all the ways from down cell to target
            }
            return take_right+take_down;// this return all the ways from current cell to target cell
        }
        int solveMemo(int m,int n,int i,int j,vector<vector<int>> & dp){
            // the dp(i,j) here represents number of unique paths from (i,j) to (m-1,n-1)
            if(i==m-1 && j == n-1){// are we at our target 
                return dp[i][j]=1;// if yes then return 1
            }
            if(dp[i][j]!=-1){// if already we have solved this case
                return dp[i][j];//
            }
            int take_right=0;//this one is for storing all the unique ways to target from current position if take right
            int take_down=0;// this one is for if we take down
            if(j<n-1){//if taking right is possible 
                take_right=solveMemo(m,n,i,j+1,dp);// update_our_variable
            }
            if(i<m-1){// if taking down is possible
                take_down=solveMemo(m,n,i+1,j,dp);// update_our_variable
            }
            return dp[i][j]=take_right+take_down;// store our answer in dp array
        }
    
        int solveTabu(int m,int n){
            vector<vector<int>> dp(m,vector<int>(n,-1));// it shall store solutions of the subproblem where dp[i][j] represents number of ways of getting to (m-1,n-1) from (i,j)
            dp[m-1][n-1]=1;// our base case
            for(int j=n-1;j>=0;j--){//// Fill from bottom-right to top-left because dp[i][j]
    // depends on dp[i][j+1] and dp[i+1][j]
    // we shall keep our columns constant and change row in one interation so loop starts with j and loop for row is nested inside it 
                for(int i=m-1;i>=0;i--){// loop for row
                    if(i==m-1 && j==n-1)continue;// if we are the base case cell skip that iteration
                    int take_right=0;// number of ways to reach goal if we take right
                    int take_down=0;// number of ways to reach goal if take down
                    if(j<n-1){// if taking right is available 
                        take_right=dp[i][j+1];// update variable
                    }
                    if(i<m-1){// if taking down is available 
                        take_down=dp[i+1][j];// take down and update variable
                    }
                    dp[i][j]=take_right+take_down; // storing number of unique ways from i,j to m-1,n-1 cell
                }
            }
            return dp[0][0];// our answer
        }
        int uniquePaths(int m, int n) {
            // brute force: Recursion
            // time complexity: O(2**(m+n)) for each cell along longest path we have got two option: go down or right
            // space complexity:O(m+n) is maximum recursion depth for the case for longest path
            //return solve(m,n,0,0);
    
    
            // memoization : Recursion + Dynamic Programming
    
            // time complexity is O(mn+mn) for initializing the dp grid at the time of declaration + filling the grid by function solveMemo 
    
            // space complexity: O(mn + (m+n)) for grid and recursion stack space
    
            // vector<vector<int>> dp(m,vector<int>(n,-1));
            // // dp[i][j]: represents unique paths from cell (i,j) to (m-1,n-1)
            // return solveMemo(m,n,0,0,dp);
    
            //tabulation dp recursion
            // time complexity: O(mn) for filling the dp array  as Every cell of the dp table is computed exactly once.
            // space complexity : O(mn) for dp array
            return solveTabu(m,n);
        }
    };