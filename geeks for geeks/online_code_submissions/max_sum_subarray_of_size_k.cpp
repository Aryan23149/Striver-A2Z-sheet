class Solution {
    public:
      int maxSubarraySum(vector<int>& arr, int k) {
  
          // brute force logic :
          // TC: O(N*N)
          // SC: O(1)
          // int n = arr.size();
          // int maxi_sum=INT_MIN;
          // for(int i=0;i<n;i++){
          //     int sum=0;
          //     for(int j=i;j<n && j<i+k;j++){
          //         sum+=arr[j];
          //         maxi_sum=max(sum,maxi_sum);
          //     }
          // }
          // return maxi_sum;
          
          // optimal approach
          int n = arr.size();
          int i=0;int j=0;
          int sum=0;int maxi_sum=INT_MIN;
          while(j<n){
              sum+=arr[j];
              while(j-i+1>k){sum-=arr[i++];}
              maxi_sum=max(maxi_sum,sum);
              j++;
          }
          return maxi_sum;
      }
  };