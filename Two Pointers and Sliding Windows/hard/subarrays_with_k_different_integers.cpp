class Solution {
    public:
        int solve(vector<int> & nums,int k){
            int  n = nums.size();
            int count = 0;
            for(int i=0;i<n;i++){
                unordered_map<int,int> helper;
                for(int j=i;j<n;j++){
                    int element = nums[j];
                    helper[element]++;
                    if(helper.size()>k){
                        break;
                    }
                    else if(helper.size()==k) count++;
                }
            }
            return count;
        }
        int slidingWindows(vector<int> &nums,int k){
            int n = nums.size();
            int i =0;int j=0;
            int count =0;
            unordered_map<int,int> helper;
            while(j<n){
                int element = nums[j];
                helper[element]++;
                while(helper.size()>k){
                    int left_element= nums[i];
                    helper[left_element]--;
                    if(helper[left_element]==0){
                        helper.erase(left_element);
                    }
                    i++;
                }
                count+=j-i+1;
                j++;
            }
            return count;
        }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            // brute force solution
            // time complexity:O(N*N)
            // space complexity:O(N)
            //return solve(nums,k);
    
            // using two pointers and sliding windows
            // time complexity:
            // space complexity:
            return slidingWindows(nums,k)-slidingWindows(nums,k-1);
        }
    };