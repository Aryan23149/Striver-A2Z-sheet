// coding ninjas : https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM
int mod = 1e9+7;
int solve(vector<int> & arr,int i , int n , int k){
	if(k<0) return 0;
	if(i==n){
		if(k==0){
			return 1;
		}
		return 0;
	}
	int pick=solve(arr,i+1,n,k-arr[i]);
	int not_pick=solve(arr,i+1,n,k);
	return pick+not_pick;
}
long long int solveMemo(vector<int> & arr, long long int i ,long long int n,int k,vector<vector<long long int>> & dp){
	if(k<0) return 0;
	if(i==n){
		if(k==0){
			return 1;
		}
		return 0;
	}
	if(dp[i][k]!=-1) return dp[i][k];
	long long int pick=solveMemo(arr,i+1,n,k-arr[i],dp);
	long long int not_pick=solveMemo(arr,i+1,n,k,dp);
	return dp[i][k]= (pick+not_pick)%mod;
}
int solveTabu(vector<int> & arr, int k){
	int n = arr.size();
	vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
	for(int i=0;i<=k;i++){
		dp[n][i]=0;
	}
	dp[n][0]=1;
	for(int i=n-1;i>=0;i--){
		int element= arr[i];
		for(int j=k;j>=0;j--){
			int pick =0;
			if(j-element>=0) pick =dp[i+1][j-element];
			int not_pick= dp[i+1][j];
			dp[i][j]=(pick+not_pick)%mod;
		}
	}
	return dp[0][k]%mod;

}
int findWays(vector<int>& arr, int k)
{
	// Brute Force Approach of Pick and Not_pick approach
	// Time Complexity: O(2 raised N)
	// Space Complexity: O(N)
	//return solve(arr,0,arr.size(),k);


	// Memoization: 
	// Time Complexity : O(n*k) 
	// space complexity: O(n*k+n)
	// long long int n =arr.size();
	// vector<vector<long long int>> dp(n,vector<long long int>(k+1,-1));
	// // dp[i][j] = how many subsets from index i to n we can have such that their sum is j
	// return solveMemo(arr,0,n,k,dp);

	// tabulation:
	// time complexity : O(n*k)
	// space complexity : O(n*k)
	return solveTabu(arr,k);
}