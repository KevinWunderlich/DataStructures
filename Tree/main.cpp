// CS 501 Project 5
// Kevin Wunderlich

#include <iostream>
using namespace std;
class treenode_type
{
public:
    int info;
    int nodelevel;
    treenode_type *left;
    treenode_type *right;
};

int leafcount(treenode_type *p);
int twochildcount(treenode_type *p);
int onechildcount(treenode_type *p);
void findleaflevels(treenode_type *p);
void setleft(int x);
void setright(int x);
void inorder(treenode_type *p);
void postorder(treenode_type *p);
void preorder(treenode_type *p);

treenode_type *p,*q,*root,*s;
int number, height(0),leaf(0),minleaf(0),maxleaf(0),i;
int lvl;
int main()
{
    cout << "Enter first value: \n";
    cin >> number;
    cout << number << "\n";
    root = new treenode_type;
    (*root).info = number;
    (*root).nodelevel = 0;
    (*root).left = NULL;
    (*root).right = NULL;
    cout <<"Enter other numbers: ";
    cin >> number;
    for(i=2;i<11;i++)
    {
        lvl = 0;
        p = root;
        q = p;
        while ((number != (*p).info) && (q!= NULL))
        {
            p = q;
            if (number < (*p).info)
                q = (*p).left;
            else
                q = (*p).right;
            lvl++;
        }
        
        if (number == (*p).info)
            cout << number << " is a duplicate \n";
        else if (number < (*p).info)     // Sets node to left if number less than p.info//
        {
            setleft(number);
            cout << number <<" is a left child of "<< (*p).info << "\n";
        }
        else    // Sets node to right if number greater than p.info//
        {
            setright(number);
            cout << number <<" is a right child of "<< (*p).info << "\n";
        }
        cin >> number;
    }
   
    height = lvl;
    
    cout << "The tree traversed INORDER is \n";
    p = root;
    inorder(p);

    cout << "The tree traversed POSTORDER is \n";
    p = root;
    postorder(p);
    
    cout << "The tree traversed PREORDER is \n";
    p = root;
    preorder(p);

    cout << "Height of tree is " << height << "\n";
    p = root;
    cout << "There are " << twochildcount(p) << " nodes with two children." << "\n";
    p = root;
    cout << "There are " << onechildcount(p) << " nodes with one child." << "\n";
    p = root;
    cout << "There are " << leafcount(p) << " leaf nodes." << "\n";
    p = root;
    findleaflevels(p);
    cout << "Maximum leaf level is " << maxleaf << "\n";
    cout << "Minimum leaf level is " << minleaf << "\n";

    system("pause");
    return 0;
}


void setleft(int x)   // Sets node to left //
{
    treenode_type *q;
    q = new treenode_type;
    (*q).info = x;
    (*q).left = NULL;
    (*q).right = NULL;
    (*q).nodelevel = lvl;
    (*p).left = q;
}
void setright(int x)
{
    treenode_type *q;
    q = new treenode_type;
    (*q).info = x;
    (*q).left = NULL;
    (*q).right = NULL;
    (*q).nodelevel = lvl;
    (*p).right = q;
}

int leafcount(treenode_type *r)
{
    if(r == NULL)
        return 0;
    if((*r).left == NULL && (*r).right == NULL)
       return 1;
    else
        return leafcount((*r).left) + leafcount((*r).right);
}
int twochildcount(treenode_type *r)
{
    if(r == NULL)
        return 0;
    if((*r).left != NULL && (*r).right != NULL)
    {
        return 1 + twochildcount((*r).left) + twochildcount((*r).right);
    }
    else
        return twochildcount((*r).left) + twochildcount((*r).right);
}
int onechildcount(treenode_type *r)
{
    if(r == NULL)
        return 0;
    if((*r).left == NULL && (*r).right != NULL)
        return 1 + onechildcount((*r).right);
    else if((*r).left != NULL && (*r).right == NULL)
        return 1 + onechildcount((*r).left);
    else
        return onechildcount((*r).left) + onechildcount((*r).right);
}


void findleaflevels(treenode_type *r)
{
    if (r != NULL)
    {
        if((*r).left == NULL && (*r).right == NULL)
        {
            if ((*r).nodelevel < minleaf)
                minleaf = (*r).nodelevel;
            else
                minleaf = (*r).nodelevel;
            if ((*r).nodelevel > maxleaf)
                maxleaf = (*r).nodelevel;
        }
        findleaflevels((*r).left);
        findleaflevels((*r).right);
    }
}

//in order tree traversal 
void inorder(treenode_type *r)
{
    if (r != NULL)
    {
        inorder((*r).left);
        cout << (*r).info << " (Level " << (*r).nodelevel << ")\n";
        inorder((*r).right);
    }
}

//preoder tree traversal
void preorder(treenode_type *r)
{
    if (r != NULL)
    {
        cout << (*r).info << " (Level " << (*r).nodelevel << ")\n";
        inorder((*r).left);
        inorder((*r).right);
    }
}

//postorder tree traversal
void postorder(treenode_type *r)
{
    if (r != NULL)
    {
        inorder((*r).left);
        inorder((*r).right);
        cout << (*r).info << " (Level " << (*r).nodelevel << ")\n";
    }
}

