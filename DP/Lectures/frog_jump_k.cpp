// this was orignally solved on gfg problem named is minimal cost
class Solution {
    public:
      int ftabu(int n,int k,vector<int> &heights){
          vector<int> dp(n,-1);// min jumps needed to move from i th index to n-1th index
          dp[n-1]=0;// no jumps needed to move from n-1 th step to n-1 step is 0
          for(int i=n-2;i>=0;i--){// for rest of the elements upto first element
              int min_jump=INT_MAX;// let initial min jump be max int value
              int jump=INT_MAX;
              for(int j=1;j<=k;j++){// check for all jump values
                  if(i+j<n){
                      jump=abs(heights[i+j]-heights[i])+dp[i+j];
                      min_jump=min(min_jump,jump);
                  }
              }
              dp[i]=min_jump;
          }
          return dp[0];
      }
      int fmemo(int index,int n, int k,vector<int> & heights,vector<int> &dp){
          if(index==n-1){
              return 0;
          }
          int min_cost=INT_MAX;
          int jump;
          if(dp[index]!=-1){
              return dp[index];
          }
          for(int i =1;i<=k;i++){
              if(index+i<n){
                  jump=fmemo(index+i,n,k,heights,dp)+abs(heights[index]-heights[index+i]);
                  min_cost=min(min_cost,jump);
              }
          }
          dp[index]=min_cost;
          return dp[index];
      }
      int func(int index,int n,int k,vector<int> & heights){
          if(index==n-1){
              return 0;
          }
          int min_cost=INT_MAX;
          int jump;
          for(int i =1;i<=k;i++){
              if(index+i<n){
                  jump=func(index+i,n,k,heights)+abs(heights[index]-heights[index+i]);
              }
              min_cost=min(min_cost,jump);
          }
          return min_cost;
      }
      int minimizeCost(int k, vector<int>& arr) {
          // Code here
          // recursive approach :
          // time complexity:O(k raised n)
          // space complexity:O(n+n)
          // return func(0,arr.size(),k,arr);
          
          // approach 2: recursion + memoization
          // Time:
          // “O(n·k), since there are n states and each state tries up to k transitions.”
          // Space:
          // “O(n) auxiliary space due to dp array and recursion stack.”
          // int n=arr.size();
          // vector<int> dp(n,-1);
          // return fmemo(0,n,k,arr,dp);
          
          //approach 3: tabulation 
          // time complexity is O(n*K) nested loops overall runs nk times
          // space complexity is O(n+n) for dp array and input array
          int n=arr.size();
          return ftabu(n,k,arr);
          
      }
  };