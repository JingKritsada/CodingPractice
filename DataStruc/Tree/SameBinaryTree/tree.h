#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree
{
    class Node
    {
    public:
        friend class Tree;
        Node()
        {
            data = -1;
            left = NULL;
            right = NULL;
        }
        Node(const int x, Node *left, Node *right) : data(x), left(left), right(right) {}

    protected:
        int data;
        Node *left;
        Node *right;
    };

public:
    Tree()
    {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree()
    {
        clear(mRoot);
    }

    void clear(Node *&r)
    {
        if (!r)
            return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x)
    {
        insertAt(mRoot, x);
    }
    bool isSameBinaryTree(Tree &t)
    {
        return compare(mRoot, t.mRoot);
    }

    bool compare(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }

        if (r1 != NULL && r2 != NULL)
        {
            if (r1->data == r2->data)
            {
                return compare(r1->left, r2->left) && compare(r1->right, r2->right);
            }
        }

        return false;
    }

protected:
    void insertAt(Node *&r, int x)
    {
        if (!r)
        {
            r = new Node(x, NULL, NULL);
            mSize++;
            return;
        }
        if (r->data == x)
            return; // Do nothing
        if (x < r->data)
            insertAt(r->left, x);
        else
            insertAt(r->right, x);
    }
    Node *mRoot;
    int mSize;
};

#endif // TREE_H_INCLUDED
