#include <unordered_map>
int solve(string & s, int k){
    int n = s.length();
    int ans =0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> helper;
        for(int j =i;j<n;j++){
            char element = s[j];
            helper[element]++;
            if(helper.size()>k){
                break;
            }
            ans = max(ans,j-i+1);
        }
    }
    return ans;
}
int SlidingWindows(string & s, int k){
    int n = s.size();
    int i = 0,j =0;
    unordered_map<char,int> helper;
    int ans =0;
    while(j<n){
        char element = s[j];
        helper[element]++;
        while(i<=j && helper.size()>k){
            int left_element=s[i];
            helper[left_element]--;
            if(helper[left_element]==0){
                helper.erase(left_element);
            }
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
}
int kDistinctChars(int k, string &str)
{
    // Write your code here
    // Brute Force :
    // Tc:O(N*N) SC: O(N)
   // return solve(str,k);

   // Optimal Solution
   // TC: O(N) SC: O(N)
   return SlidingWindows(str,k);
}

