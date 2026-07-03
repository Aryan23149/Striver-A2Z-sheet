class Solution {
    public:
      int upperBound(vector<int>& arr, int target) {
          // code here
          // appraoch 1: linear search O(N) and O(1) for tc and sc
          // as soon as find the element > target return its index
          
          // approach 2 : binary search O(logN) and O(1) for tc and sc
          int n= arr.size();
          int low = 0;
          int high =n-1;
          while(low<=high){
              int mid =low+(high-low)/2; 
              int element= arr[mid];
              if(element>target){
                  high=mid-1;
              }
              else {
                  low=mid+1;
              }
          }
          return high+1;
      }
  };
  