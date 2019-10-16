#include<iostream>
#include<string.h>
#include<stack> 
using namespace std;

typedef struct node{
    char data;
    struct node *lchild,*rchild;

}BinTree;

typedef struct node1{
    BinTree *btnode;
    bool isFirst;
}BTNode;

void creatBinTree(char*s,BinTree *&root)  //创建二叉树，s为形如A(B,C(D,E))形式的字符串 
{
    int i;
    bool isRight=false;
    stack<BinTree*> s1;          //存放结点 
    stack<char> s2;              //存放分隔符
    BinTree *p,*temp;
    root->data=s[0];
    root->lchild=NULL;
    root->rchild=NULL;
    s1.push(root);
    i=1;
    while(i<strlen(s))
    {
        if(s[i]=='(')
        {
            s2.push(s[i]);
            isRight=false;
        }    
        else if(s[i]==',')    
        {
            isRight=true;
        }
        else if(s[i]==')')
        {
            s1.pop();
            s2.pop();
        }
        else if(isalpha(s[i]))
        {
            p=(BinTree *)malloc(sizeof(BinTree));
            p->data=s[i];
            p->lchild=NULL;
            p->rchild=NULL;
            temp=s1.top();
            if(isRight==true)    
            {
                temp->rchild=p;
                cout<<temp->data<<"的右孩子是"<<s[i]<<endl;
            }
            else
            {
                temp->lchild=p;
                cout<<temp->data<<"的左孩子是"<<s[i]<<endl;
            }
            if(s[i+1]=='(')
                s1.push(p);
        }
        i++;
    }    
}

void display(BinTree *root)        //显示树形结构 
{
    if(root!=NULL)
    {
        cout<<root->data;
        if(root->lchild!=NULL)
        {
            cout<<'(';
            display(root->lchild);
        }
        if(root->rchild!=NULL)
        {
            cout<<',';
            display(root->rchild);
            cout<<')';
        }
    }
}

void preorder1(BinTree *root){
    if (root){
        cout<<root->data<<" ";
        preorder1(root->lchild);
        preorder1(root->rchild);
    }
}

void inOrder1(BinTree *root)      //递归中序遍历
{
    if(root!=NULL)
    {
        inOrder1(root->lchild);
        cout<<root->data<<" ";
        inOrder1(root->rchild);
    }
} 

void postOrder1(BinTree *root)    //递归后序遍历
{
    if(root!=NULL)
    {
        postOrder1(root->lchild);
        postOrder1(root->rchild);
        cout<<root->data<<" ";
    }    
} 

void preorder2(BinTree*root){
    stack<BinTree*>s;
    BinTree* p=root;
    while(p||!s.empty()){
        while(p){
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty()){
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

void inOrder2(BinTree *root)      //非递归中序遍历
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->data<<" ";
            s.pop();
            p=p->rchild;
        }
    }    
} 

void postorder2(BinTree*root){
    stack<BTNode*>s;
    BinTree*p=root;
    BTNode*temp;
    while(p||!s.empty()){
        while(p){
            BTNode *btn=(BTNode*)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty()){
            temp=s.top();
            s.pop();
            if(temp->isFirst){
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;
            }
            else{
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }
}
//
void postorder3(BinTree* root){
    stack<BinTree*> s;
    BinTree* cur,*pre=nullptr;
    s.push(root);
    while(!s.empty()){
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild))){
            cout<<cur->data<<" ";
            s.pop();
            pre=cur;
        }
        else{
            if(cur->rchild)
                s.push(cur->rchild);
            if(cur->rchild)
                s.push(cur->lchild);
        }
    }

}

int main(){
    char s[100];
    while(scanf("%s",s)){
        BinTree *root=(BinTree *)malloc(sizeof(BinTree));
        creatBinTree(s,root);
        display(root);
        cout<<endl;
        preorder1(root);
        cout<<endl;
        preorder2(root);
        cout<<endl;
        inOrder1(root);
        cout<<endl;
        inOrder2(root);
        cout<<endl;
        postOrder1(root);
        cout<<endl;
        postorder2(root);
        cout<<endl;
        postorder3(root);

    }
}

