class Solution {
    public:
        int solve(vector<int> & g,vector<int> & s,int i,int j){
            if(i==g.size() || j==s.size()){
                return 0;
            }
            int current_child_greed=g[i];
            int this_cookie=s[j];
            int give_cookie=0;
            if(current_child_greed<=this_cookie){
                give_cookie=solve(g,s,i+1,j+1)+1;
            }
            else{
                give_cookie=solve(g,s,i,j+1);
            }
            int skip_this_child=solve(g,s,i+1,j);
            return max(give_cookie,skip_this_child);
        }
        int solveMemo(vector<int> & g,vector<int> & s,int i,int j,vector<vector<int>>& dp){
            if(i==g.size() || j==s.size()){
                return 0;
            }
            if(dp[i][j]!=-1) return dp[i][j];
            int current_child_greed=g[i];
            int this_cookie=s[j];
            int give_cookie=0;
            if(current_child_greed<=this_cookie){
                give_cookie=solveMemo(g,s,i+1,j+1,dp)+1;
            }
            else{
                give_cookie=solveMemo(g,s,i,j+1,dp);
            }
            int skip_this_child=solveMemo(g,s,i+1,j,dp);
            return dp[i][j]=max(give_cookie,skip_this_child);
        }
        int solveTabu(vector<int> & g,vector<int> &s){
            int n =g.size();
            int m = s.size();
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            vector<vector<int>> dp(n+1,vector<int> (m+1,0));
            for(int i=n-1;i>=0;i--){// greed array traversal 
                int current_child_greed=g[i];
                for(int j=m-1;j>=0;j--){//  cookie array traversal
                    int this_cookie=s[j];
                    int give_cookie=0;
                    if(current_child_greed<=this_cookie){
                        give_cookie=dp[i+1][j+1]+1;
                    }
                    else{
                        give_cookie=dp[i][j+1];
                    }
                    int skip_this_child=dp[i+1][j];
                    dp[i][j]=max(give_cookie,skip_this_child);
                }
            }
            return dp[0][0];
        }
        int findContentChildren(vector<int>& g, vector<int>& s) {
            // optimal approach: greedy algorithms
            // tc: O(nlogn) sc: O(1)
            // sort(g.begin(),g.end());
            // sort(s.begin(),s.end());
            // int i=0,j=0;
            // int n=g.size(),m=s.size();
            // int count=0;
            // while(i<n&&j<m){
            //     if(g[i]>s[j]){
            //         j++;
            //     }
            //     else{
            //         count++;
            //         j++;
            //         i++;
            //     }
            // }
            // return count;
    
            // brute force approach
            // time complexity: O(2 raised (n+m) +nlogn +mlogm )
            // space complexity: (n+m)
            // sort(g.begin(),g.end());
            // sort(s.begin(),s.end());
            // return solve(g,s,0,0);
    
            // memoization approach
            // sort(g.begin(),g.end());
            // sort(s.begin(),s.end());
            // int n =g.size();int m=s.size();
            // vector<vector<int>> dp(n,vector<int>(m,-1));
            // // dp[i][j] means maximum number of children that can be satisfied by considering kids from indice i to n-1 indice that are to be satisfied using cookies from indice j to m-1
            // return solveMemo(g,s,0,0,dp);
    
            // tabulation approach
            return solveTabu(g,s);
        }
    };