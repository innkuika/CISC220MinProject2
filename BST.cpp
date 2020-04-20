#include <iostream>

using namespace std;


//void printTreeIO(TNode* n);
//void printTreePre(TNode* n);
//void printTreePost(TNode* n);

TNode *remove(string s);
TNode *removeNoKids(TNode *tmp);
TNode *removeOneKids(TNode *tmp, bool leftFlag);
TNode *find(TNode* n,string s);


int main()
{
    return 0;
}


bool insert(string s)
{

}

TNode *find(string s)
{
    if
}

TNode *find(TNode* n,string s)
{
   if(n-> data == s){
	   cout << "the node holding " << s << endl;
       return n;
   }if(n->val < val){
       if(n-> right != NULL)
       return find(n->right, s);
   }
    if(n-> val > val){
        if(n-> left != NULL)
        return find(n->left, s);
    }
    return NULL;
}


}

void printTreeIO(TNode* n)
{
    if(n == NULL){
        return;
    }
    else{
        printTreeIO(n->left);
        n->printNode();
        printTreeIO(n->right);
    }
}

void printTreePre(TNode* n)
{
    if(n == NULL){
        return;
    }
    else{
        n->printNode();
        printTreeIO(n->left);
        printTreeIO(n->right);
    }
}

void printTreePost(TNode* n)
{
    if(n == NULL){
        return;
    }
    else{
        printTreeIO(n->left);
        printTreeIO(n->right);
        n->printNode();
    }
}


TNode *remove(string s)
{
    if(tmp->left == nullptr && tmp->right == nullptr)
    {
        *removeNoKids(TNode *tmp);
    }
    else if(tmp->left == nullptr && tmp->right != nullptr)
    {
        *removeOneKids(TNode *tmp, bool leftFlag);
    }
    else if(tmp->left != nullptr && tmp->right == nullptr)
    {
        *removeOneKids(TNode *tmp, bool leftFlag);
    }
}

TNode *removeNoKids(TNode *tmp)
{
    delete tmp;
    return *removeNoKids;
}

TNode *removeOneKids(TNode *tmp, bool leftFlag)
{
    leftFlag = true;
    if(tmp->left == nullptr && tmp->right != nullptr)
    {
    	leftFlag = false;
        node *tmp = root;
        root = root->left;
        delete tmp;
        tmp = NULL;
    }
    else if(tmp->left != nullptr && tmp->right == nullptr)
    {
        node *tmp = root;
        root = root->right;
        delete tmp;
        tmp = NULL;
    }
    return ;
}
