#include <vector>
using namespace std;


template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(int data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i=0;i<this->children.size();i++){
            delete this->children[i];
        }
        // cout<<"Node deleted !"<<endl;
    }

};