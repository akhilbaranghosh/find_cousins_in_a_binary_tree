#include <bits/stdc++.h>
using namespace std;
class node{
    int val;
    node* left;
    node* right;
public:
    node(){};
    node(int val):val(val),left(0),right(0){};
    node(int val,node* left):val(val),left(left){};
    int getVal() const {
        return val;
    }

    void setVal(int val) {
        node::val = val;
    }

    node *getLeft() const {
        return left;
    }

    void setLeft(node *left) {
        node::left = left;
    }

    node *getRight() const {
        return right;
    }

    void setRight(node *right) {
        node::right = right;
    }

    node& operator=(node& n){
        this->val=n.val;
        this->left=n.left;
        this->right=n.right;
        return *this;
    }
};
int cousins_count(node* a){
    queue<node*> q;
    q.push(a);
    int parent_count=1;
    int child_count=0;
    int cousin_count=0;
    while(!q.empty()){
        vector<bool> brother_flag;
        while(parent_count--){
            node* n=q.front();
            q.pop();
            if(n->getLeft()!=0){
                q.push(n->getLeft());
                child_count++;
            }
            if(n->getRight()!=0){
                q.push(n->getRight());
                child_count++;
            }
            if(n->getLeft()!=0&&n->getRight()!=0){
                brother_flag.push_back(true);
                brother_flag.push_back(true);
            } else if(n->getRight()==0&&n->getLeft()==0){

            } else{
                brother_flag.push_back(false);
                brother_flag.push_back(false);
            }

        }
        if(brother_flag.size()>0){
            if(brother_flag[0]==true)cousin_count+=(brother_flag.size()-2);
            else cousin_count+=(brother_flag.size()-1);
        }
        parent_count=child_count;
        child_count=0;
    }
    return cousin_count;
}
int main(){
    node* n=new node(5);
    n->setLeft(new node(6));
    n->setRight(new node(7));
    n->getLeft()->setLeft(new node(2));
    n->getLeft()->setRight(new node(1));
    n->getRight()->setLeft(new node(0));
    n->getRight()->setRight(new node(5));
    n->getLeft()->getLeft()->setLeft(new node(4));
    n->getLeft()->getLeft()->setRight(new node(3));
    n->getLeft()->getRight()->setLeft(new node(1));
    n->getLeft()->getRight()->setRight(new node(6));
    n->getRight()->getLeft()->setLeft(new node(8));
    n->getRight()->getLeft()->setRight(new node(9));
    n->getRight()->getRight()->setLeft(new node(2));
    n->getRight()->getRight()->setRight(new node(3));
    cout << cousins_count(n);


}