#include <iostream>
#include <vector>
using namespace std;
void combination_sum(vector<int> &array,int target,int n,int index,vector<int> & subseq){
    if(target==0){
        for(int i: subseq){
            cout << i <<" ";
        }
        cout<<endl;
        return;
    }
    if(target < 0 || index == n){
        return;
    }

    combination_sum(array,target,n,index+1,subseq);
    subseq.push_back(array[index]);
    combination_sum(array,target-array[index],n,index,subseq);
    subseq.pop_back();
    return;

}
int main(){
    vector<int> array;
    array={2};
    int target;
    target=1;
    vector<int> subseq;
    combination_sum(array,target,array.size(),0,subseq);
    return 0;
}