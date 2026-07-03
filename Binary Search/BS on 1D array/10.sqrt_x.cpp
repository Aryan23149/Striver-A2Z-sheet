class Solution {
    public:
        int mySqrt(int x) {
            // binary search approach 
            // tc: O(LogX) sc: O(1)
            if(x==0) return 0;
            long long int low = 1;
            long long int high = x;
            long long  mid;
            long long int global_answer=0;
            while(low<=high){
                mid=low+(high-low)/2;
                long long int ans=mid*mid;
                if(ans<x){
                    low=mid+1;
                    global_answer=mid;
                }
                else if(ans>x){
                    high=mid-1;
                }
                else{
                    return mid;
                }
            }
            return global_answer;
        }
    };