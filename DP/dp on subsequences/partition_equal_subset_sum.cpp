class Solution {
    public:
        bool solve(vector<int> & nums, int i ,int n,int subset_sum1,int subset_sum2){
            if(i==n){
                if(subset_sum1==subset_sum2){
                    return true;
                }
                return false;
            }
            int pick= solve(nums,i+1,n,subset_sum1+nums[i],subset_sum2-nums[i]);
            int not_pick=solve(nums,i+1,n,subset_sum1,subset_sum2);
            return pick || not_pick;
        }
    
        bool solveMemo(vector<int> & nums, int i ,int n,int subset_sum1,int subset_sum2,vector<vector<int>>& dp){
            if(i==n){
                if(subset_sum1==subset_sum2){
                    return true;
                }
                return false;
            }
            if(dp[i][subset_sum1]!=-1) return dp[i][subset_sum1];
            int pick= solveMemo(nums,i+1,n,subset_sum1+nums[i],subset_sum2-nums[i],dp);
            int not_pick=solveMemo(nums,i+1,n,subset_sum1,subset_sum2,dp);
            return dp[i][subset_sum1]=(pick || not_pick);
        }
        bool solveTabu(vector<int> & nums){
            int n= nums.size();
            int sum= accumulate(nums.begin(),nums.end(),0);
            if(sum%2==1) return false;
    
            vector<vector<int>>  dp(n+1,vector<int> (sum+1,-1));
            // can we have sum_of_subset1 as j from index i to n-1
            for(int j=sum;j>=0;j--){
                dp[n][j] = 0;
            }
            dp[n][0]=1;
            for(int i=n-1;i>=0;i--){
                int element= nums[i];
                for(int j=sum;j>=0;j--){
                    int pick;
                    if(j >= element){ pick = dp[i+1][j-element];}
                    else pick = false;
                    int not_pick=dp[i+1][j];
                    dp[i][j]=pick || not_pick;
                }
            }
            return bool(dp[0][sum/2]);
        }
        bool canPartition(vector<int>& nums) {
            // brute force approash
            // time complexity: O(2^N) for each elements we have two options...whether to put in subset 1 or not
            // space complexity : O(N)  recursion stack space which is directly proportional to depth of recursion tree
            // int sum_of_nums=accumulate(nums.begin(), nums.end(),0);
            // if(sum_of_nums%2==1) return false;
            // return solve(nums,0,nums.size(),0,sum_of_nums);
    
            //memoization approach
            // time complexity = O(N * K) where K =
            // int n = nums.size();
            // int sum_of_nums=accumulate(nums.begin(), nums.end(),0);
            // if(sum_of_nums%2==1) return false;
            // vector<vector<int>> dp(n,vector<int> (sum_of_nums+1,-1));
            
            // // dp [i] [j] = can sum of subset 1 elements choosen  from index i to n-1 be j using pick or not _ approach from this indice and onwards
            // return solveMemo(nums,0,n,0,sum_of_nums,dp);
    
            // approach 3 : tabulation code of this problem
            // time complexity: O(n*k)
            // space complexity: O(n*k)
            return solveTabu(nums);
        }
    };