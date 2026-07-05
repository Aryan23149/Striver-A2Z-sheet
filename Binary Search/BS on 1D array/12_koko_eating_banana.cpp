class Solution {
    public:
        bool check(vector<int> & piles,long long int speed,long long int h){
            long long int total_hours=0;
            for(int pile : piles){
                total_hours+=(pile+speed-1)/speed;
            }
            return total_hours<=h;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            // approach 1 : binary search on answer O(nlogn)
            long long int low = 1;
            auto maxIt =max_element(piles.begin(), piles.end());
            long long int high = *maxIt;
            long long int mid ;
            long long int global_answer=1;
            while(low<=high){
                mid = low +(high- low)/2;
                bool speed_fine= check(piles,mid,1LL*h);
                if(speed_fine){
                    global_answer= mid;
                    high = mid -1;
                }
                else{
                    low= mid+1;
                }
            }
            return global_answer;
        }
    };