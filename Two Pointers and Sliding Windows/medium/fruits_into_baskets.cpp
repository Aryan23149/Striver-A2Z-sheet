class Solution {
    public:
        int solve(vector<int> & fruits){
            // brute force : 
            int n = fruits.size();
            int answer=0;
            for(int i=0;i<n;i++){
                unordered_map<int,int> helper;
                for(int j=i;j<n;j++){
                    int element= fruits[j];
                    helper[element]++;
                    if(helper.size()> 2){
                        break;
                    }
                    else{
                        answer=max(answer,j-i+1);
                    }
                }
            }
            return answer;
        }
        int slidingWindow(vector<int> & fruits){
            int n = fruits.size();
            int i = 0;
            int j=0;
            unordered_map<int,int> helper;
            int ans=0;
            while(j<n){
                // int element= fruits[j];
                while(j<n && helper.size()<=2){
                    int element= fruits[j];
                    helper[element]++;
                    if(helper.size()<=2) ans=max(ans,j-i+1);
                    j++;
                }
                while(i<=j && helper.size()>2){
                    int element_rhs = fruits[i];
                    if(helper[element_rhs]>1){
                        helper[element_rhs]--;
                    }
                    else{
                        helper.erase(element_rhs);
                    }
                    i++;
                }
            }
            return ans;
        }
        int totalFruit(vector<int>& fruits) {
            // Brute Force Approach 
            // Time Complexity: O(N*N)
            // Space Complexity: O(N)
            //return solve(fruits);
    
            // Optimized Approach :Using Two Pointer And SLiding WIndows
            // Time Complexity: O(N)
            // Space Complexity:O(N)
            return slidingWindow(fruits);
        }
    };