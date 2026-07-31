#include <vector>
#include <iostream>
using namespace std;
class Treenode{
    public:
        int data;
        Treenode* left_node;
        Treenode* right_node;
        Treenode(int data){
            this->data=data;
            this->left_node=nullptr;
            this->right_node=nullptr;
        }
};
int main(){
    Treenode *t1= new Treenode(1);
    t1->left_node=new Treenode(2);
    t1->right_node=new Treenode(3);
    t1->right_node->right_node=new Treenode(5);
    return 0;
}