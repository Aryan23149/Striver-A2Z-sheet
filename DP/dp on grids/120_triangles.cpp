class Solution {
    public:
        int solve(vector<vector<int>> & triangle,int i ,int j ,int m,int n){
            if(i>=m){
                return 0;
            }// if we exceed number of rows in triangle then this returning 0 would not change result in pick variables
            int pick_this=INT_MAX;// if we pick current element for row i  
            int pick_right=INT_MAX;//if we pick adjacent element for row i
            if(i<m && j<n){// can only pick current element if row < m and j is < n 
                pick_this=solve(triangle,i+1,j,m,n+1)+triangle[i][j];
                // we pick current element and solve subproblem where we are at row i+1 and can only choose element j or j+1 of i+1th row...since in next row we have one extra element in column so n+1
            }
            if(i<m &&j<n-1){
                pick_right=solve(triangle,i+1,j+1,m,n+1)+triangle[i][j+1];
                // we pick adjacent element and solve subproblem where we are at row i+1 and can only choose element j+1  or j+2 for i+1th row...since in next row we have one extra element in column so n+1
            }
            return min(pick_this,pick_right);// pick the choice leading to minimum sum
        }
        int solveMemo(vector<vector<int>> & triangle,int i ,int j ,int m,int n,vector<vector<int>> & dp){
            if(i>=m){
                return 0;
            }// if we exceed number of rows in triangle then this returning 0 would not change result in pick variables
            if(dp[i][j]!=105) return dp[i][j];
            int pick_this=INT_MAX;// if we pick current element for row i  
            int pick_right=INT_MAX;//if we pick adjacent element for row i
            if(i<m && j<n){// can only pick current element if row < m and j is < n 
                pick_this=solveMemo(triangle,i+1,j,m,n+1,dp)+triangle[i][j];
                // we pick current element and solve subproblem where we are at row i+1 and can only choose element j or j+1 of i+1th row...since in next row we have one extra element in column so n+1
            }
            if(i<m && j<n-1){
                pick_right=solveMemo(triangle,i+1,j+1,m,n+1,dp)+triangle[i][j+1];
                // we pick adjacent element and solve subproblem where we are at row i+1 and can only choose element j+1  or j+2 for i+1th row...since in next row we have one extra element in column so n+1
            }
            return dp[i][j]=min(pick_this,pick_right);// pick the choice leading to minimum sum
        }
        int solvE(vector<vector<int>> & triangle,int i,int j){
            if(i==triangle.size()){
                return 0;
            }
            int down=solvE(triangle,i+1,j);
            int diagonal = solvE(triangle,i+1,j+1);
            return triangle[i][j] + min(down,diagonal);
        }
        int solvEMemo(vector<vector<int>> & triangle,vector<vector<int>> &dp,int i,int j){
            if(i==triangle.size()-1){
                return triangle[i][j];
            }
            if(dp[i][j]!=INT_MAX) return dp[i][j];
            int down=solvEMemo(triangle,dp,i+1,j);
            int diagonal = solvEMemo(triangle,dp,i+1,j+1);
            return dp[i][j]= triangle[i][j] + min(down,diagonal);
        }
        int solvETabu(vector<vector<int>> & triangle){
            int m = triangle.size();
            int n = m;
            vector<vector<int>> dp(m,vector<int> (m,105));
            for(int i=m-1;i>=0;i--) dp[m-1][i]=triangle[m-1][i];
            for(int i=m-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int down=dp[i+1][j];
                    int diagonal =dp[i+1][j+1];
                    dp[i][j]= triangle[i][j] + min(down,diagonal);
                }
            }
            return dp[0][0];
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            // brute force // based on pick current and pick right
            // time : O(2^(m))
            // sc : O(m)
            //return solve(triangle,0,0,triangle.size(),1);
    
            // brute force based on pick current and minimum of down and diagonal element in next row
            // return solvE(triangle,0,0);
    
    
            // memoization approach
            // int m = triangle.size();
            // vector<vector<int>> dp(m,vector<int> (m,105));
            // return solveMemo(triangle,0,0,m,1,dp);
    
            //memoization of down digonal 
            // int m = triangle.size();
            // vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
            // return solvEMemo(triangle,dp,0,0);
    
            // tabulation approach
            return solvETabu(triangle);
        }
    };