#include<iostream>
using namespace std;
class TreeNode{
    public:
    int key ;
    TreeNode *right,*left;
    TreeNode(int val)
    {
        key =val;
        right=left=NULL;
    }
};
class BinaryTree
{
    private :
    TreeNode* root;
    public:
    BinaryTree()
    {
        root= NULL;
    }
    void inserter(int val,TreeNode* Root)
    {
        if(Root->key<val)
        {   
            if(Root->right==NULL)
            {
                TreeNode *newnode = new TreeNode(val);
                Root->right = newnode;
            }
            else{
                inserter( val , Root->right);
            }
        }
        else if(Root->key==val){
            return ;
        }
        else 
        {
            if(Root->left==NULL)
            {
                TreeNode *newnode = new TreeNode(val);
                Root->left = newnode;
                return;
            }
            else{
                inserter(val,Root->left);
            }
        }
        return ;
    }
    void insert(int val)
    {
        TreeNode *newnode = new TreeNode(val);
        if(root == NULL)
        {
            root = newnode;
            return ;
        }
        inserter(val,root);
    }
    void display(TreeNode* disp)
    {
        if(disp==NULL)return;
        if(disp->left!=NULL)
        cout<<disp->left->key<<" ";
        if(disp->right!=NULL)
        cout<<disp->right->key<<" ";
        display(disp->left);display(disp->right);
    }
    void travasal()
    {
        if(root!=NULL)cout<<root->key<<' ';
        else {
            cout<<"error:tree is empty"<<endl;
            return;
        }
        display(root);
    }
};

int main()
{
    BinaryTree dt;
    dt.insert(10);
    dt.insert(23);
    dt.insert(7);
    dt.insert(2);
    dt.insert(50);
    dt.insert(25);
    dt.insert(70);
    dt.travasal();
}
