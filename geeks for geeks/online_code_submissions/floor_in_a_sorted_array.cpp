https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
class Solution {
    public:
    // orignally solved on gfg: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
      int findFloor(vector<int>& arr, int x) {
          int upper_bound_index= upper_bound(arr.begin(),arr.end(),x)-arr.begin();
          if(upper_bound_index==0) return -1;
          return upper_bound_index-1;
      }
  };
  