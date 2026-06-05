#include <iostream>
#include <vector>
using namespace std;

int count_subsequences_with_sumk(vector<int> & sequence,int index,int n,int sum){
    if(index==n){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    if(sum<0){return 0;}

    int c1=count_subsequences_with_sumk(sequence,index+1,n,sum-sequence[index]);
    int c2=count_subsequences_with_sumk(sequence,index+1,n,sum);
    return c1+c2;
}
int main(){

    vector<int> a;
    a={3,1,2,5,4,2,4,1,7,8,9,3,4,2};
    // a.push_back(3);
    // a.push_back(1);
    // a.push_back(2); 
    
    int k=6;

    
    cout<<count_subsequences_with_sumk(a,0,a.size(),k); //time complexity is O(2^N) and space complexity is O(N+N)=O(2N)=O(N)
    cout<<endl;

    return 0;
}