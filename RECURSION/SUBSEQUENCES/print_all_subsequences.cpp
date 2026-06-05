#include <iostream>
#include <vector>
using namespace std;

void print_all_subsequences(vector<int> & sequence,int index,int n,vector<int> &subseq){
    if(index==n){
        for(int i: subseq){
            cout<<i;
        }
        cout<<" ";
        return;
    }

    print_all_subsequences(sequence,index+1,n,subseq);
    subseq.push_back(sequence[index]);
    print_all_subsequences(sequence,index+1,n,subseq);
    subseq.pop_back();
    return;
}
int main(){

    vector<int> a;

    a.push_back(3);
    a.push_back(1);
    a.push_back(2);   

    // a={3,1,2};
    
    vector<int> subseq;
    print_all_subsequences(a,0,a.size(),subseq); //time complexity is O((2^N)*N) and space complexity is
    //O(N)
    cout<<endl;

    return 0;
}