class Solution {
    // gfg : https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
    public:
      long long int ntimes_number(long long int mid,long long int n){
          long long int ans = 1;
          for(int i =0;i<n;i++){
              ans*=mid;
          }
          return ans;
      }
      int nthRoot(int n, int m) {
          // Code here
          if(m==0) return 0;
          long long  int low = 1;
          long long int high = m;
          long long mid;
          long long global_answer =1;
          while(low<=high){
              mid=low + (high - low)/2;
              long long int answer = ntimes_number(mid,1LL*n);
              if(answer > m){
                  high = mid -1;
              }
              else{
                  low= mid+1;
                  global_answer=mid;
              }
          }
          if(ntimes_number(global_answer,1LL*n)==1LL*m){
              return global_answer;
          }
          return -1;
      }
  };