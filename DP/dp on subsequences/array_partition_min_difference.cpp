// link :https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
int solve(vector<int> & nums,int i,int sum1,int sum){
    if(i==nums.size()){
        return abs(sum1-sum);
    }
    int pick_for_subset_one=INT_MAX;
    pick_for_subset_one=solve(nums,i+1,sum1+nums[i],sum-nums[i]);
    int not_pick_for_subset_one=solve(nums,i+1,sum1,sum);
    return min(pick_for_subset_one,not_pick_for_subset_one);
}
int solveMemo(vector<int> & nums,int i,int sum1,int sum,vector<vector<int>> & dp){
    if(i==nums.size()){
        return abs(sum1-sum);
    }
    if(dp[i][sum1]!=-1) return dp[i][sum1];
    int pick_for_subset_one=INT_MAX;
    pick_for_subset_one=solveMemo(nums,i+1,sum1+nums[i],sum-nums[i],dp);
    int not_pick_for_subset_one=solveMemo(nums,i+1,sum1,sum,dp);
    return dp[i][sum1]=min(pick_for_subset_one,not_pick_for_subset_one);
}
int solvTabu(vector<int> & arr){
    int n = arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    for(int i=0;i<sum+1;i++){
        int s1=i;
        int s2=sum-i;
        dp[n][i]=abs(s1-s2);
    }
    for(int i=n-1;i>=0;i--){
        int element=arr[i];
        for(int j=sum;j>=0;j--){
            int pick=INT_MAX;
            if(j+element<=sum){
                pick=dp[i+1][j+element];
            }
            int not_pick=dp[i+1][j];
            dp[i][j]=min(pick,not_pick);
        }
    }
    return dp[0][0];
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Brute Force Approach
    // time complexity : O(2^N)
    // space complexity : O(N)
	// int sum=0;
    // for(int i=0;i<arr.size();i++){
    //     sum+=arr[i];
    // }
    // return solve(arr,0,0,sum);

    // Memoization Approach
    // time complexity:O(N*SUM)
    // space complexity:O(N*SUM+N)
    //where N is number of elements in arr
    // SUM is the sum of the elements of the array
    // int sum=0;
    // for(int i=0;i<arr.size();i++){
    //     sum+=arr[i];
    // }
    // vector<vector<int>> dp(n,vector<int> (sum+1,-1));
    // dp[i][j] here represents minimum difference between sum of subset 1 elements and 
    // sum of subset 2 elements such that 
    //  elements and sum of subset 2 elements
    // from index i to n-1 given current sum of subset 1 elements is j
    // return solveMemo(arr,0,0,sum,dp);
    // tabulation approach : 
    // time complexity :O(N*SUM) space complexity:O(N*SUM)
   return solvTabu(arr);
}