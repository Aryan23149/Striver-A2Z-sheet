class Solution {
    public:
    // gfg: Ceil in a Sorted Array : https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
      int findCeil(vector<int>& arr, int x) {
          // code here
          int lower_bound_index=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
          if(lower_bound_index==arr.size()) return -1;
          return lower_bound_index;
      }
  };