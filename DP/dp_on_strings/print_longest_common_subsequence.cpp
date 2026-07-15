string solveTabu(string & s1,string & s2){
	int n = s1.length();
	int m= s2.length();
	vector<vector<int>>  dp(n+1,vector<int> (m+1,0));
	// dp[i][j] : length of lcs of strings made from first i and first j characters of s1 and s2
	for(int i=1;i<=n;i++){
		int char_in_s1=s1[i-1];
		for(int j=1;j<=m;j++){
			int char_in_s2=s2[j-1];
			if(char_in_s1==char_in_s2){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int i= n;
	int j=m;
	string ans="";
	while(i>=1 && j>=1){
		char char_in_s1=s1[i-1];
		char char_in_s2=s2[j-1];
		if(char_in_s1==char_in_s2){
			ans=char_in_s1+ans;
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	return ans;
}
string findLCS(int n, int m,string &s1, string &s2){
	// Brute Force Approach
	// Time Complexity:O(nm)
	// Space Complexity:O(nm)
	return solveTabu(s1,s2);
}