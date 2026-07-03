class Solution {
    public:
      int countFreq(vector<int>& arr, int target) {
        // solved on gfg: http://geeksforgeeks.org/problems/number-of-occurrence2259/1
          // time complexity: O(2*LogN)==O(logN) and sc: O(1)
          int lower_bound_index=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
          int upper_bound_index=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
          return upper_bound_index-lower_bound_index;
      }
  };
  