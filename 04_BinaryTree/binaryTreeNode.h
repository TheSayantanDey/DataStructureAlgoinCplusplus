template <typename T>
class binaryTreeNode{
    public:
    T data;
    binaryTreeNode * left;
    binaryTreeNode * right;

    binaryTreeNode(int data){
        this->data = data;
        left  = NULL;
        right = NULL;
    }
    ~binaryTreeNode(){
        delete left;
        delete right;
    }
};