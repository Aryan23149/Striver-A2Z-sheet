class Solution {
    public:
      int lowerBound(vector<int>& arr, int target) {
          // brute force is linear search and as soon as get arr[index] >= target return index
          // time complexity is O(N)
          // space compelxity is O(1)
          
          
          // approach 2: binary search
          // time complexity : O(logN)
          // space comlexity : O(1)
          int n = arr.size();
          int low= 0;
          int high=n-1;
          while(low<=high){
              int mid =( low+((high-low)/2));
              int element = arr[mid];
              if(element>=target){
                  high=mid-1;
              }
              else if(element<target){
                  low=mid+1;
              }
          }
          return high+1;
      }
  };