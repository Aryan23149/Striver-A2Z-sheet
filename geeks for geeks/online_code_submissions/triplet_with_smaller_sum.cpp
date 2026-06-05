class Solution {
    public:
      int countTriplets(int sum, vector<int>& arr) {
          // code here
          // brute force approach 
          // time complexity is O(N*N)
          // space complexity is O(1)
          // int n = arr.size();
          // int count =0;
          // for(int i=0;i<n-2;i++){
          //     for(int j=i+1;j<n-1;j++){
          //         for(int k=j+1;k<n;k++){
          //             int sum_of_triplet = arr[i]+arr[j]+arr[k];
          //             if(sum_of_triplet<sum){
          //                 count++;
          //             }
          //         }
          //     }
          // }
          
          // return count;
          // optimal solution
          // Time complexity : O(N*N)
          // Space Complexity : O(1)
          int n= arr.size();
          sort(arr.begin(),arr.end());
          int count=0;
          for(int i=0;i<n-2;i++){
              int fixed_element=arr[i];
              int j=i+1;
              int k=n-1;
              int to_find=sum-fixed_element;
              while(j<k){
                  if(arr[j]+arr[k]>=to_find){
                      k--;
                  }
                  else{
                      count+=k-j;
                      j++;
                  }
              }
          }
          return count;
      }
  };