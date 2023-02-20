#include<stdio.h>
#define left(n)(2*n)+1
#define right(n)(2*n)+2
struct Tree
{
    int arr[10000];
    int idx;
    Tree()
    {
        idx=0;
    }
    void Insert(int val)
    {
        arr[idx]=val;
        idx++;

    }
    void Swap()
    {
        int temp;
        temp=arr[0];
        arr[0]=arr[idx];
        arr[idx]=temp;
    }
    void Delete()
    {
        Swap();
        idx--;
    }
    void preorderTraverse(int node)
    {
        if(node>=idx)
        {
            return;
        }
        printf("%d\n",arr[node]);
        preorderTraverse(left(node));
        preorderTraverse(right(node));

    }
     void postorderTraverse(int node)
    {
        if(node>=idx)
        {
            return;
        }
        postorderTraverse(left(node));
        postorderTraverse(right(node));
        printf("%d\n",arr[node]);

    }
    void InorderTraverse(int node)
    {
        if(node>=idx)
        {
            return;
        }
        InorderTraverse(left(node));
        printf("%d\n",arr[node]);
        InorderTraverse(right(node));


    }

};
int main()
{
    Tree t= Tree();
    int c;
    while(1)
    {
        printf("enter your choice :1-insert\n\t\t   2-delete\n\t\t   3-to print the preorder traverse\n\t\t   4-to print the postorder traverse\n\t\t   5-to print the Inorder traverse\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            int val;
            scanf("%d",&val);
            t.Insert(val);
            break;
        case 2:
            t.Delete();
            break;
        case 3:
            t.preorderTraverse(0);
            break;
        case 4:
            t.postorderTraverse(0);
            break;
            case 5:
            t.InorderTraverse(0);
            break;
        default:
            printf("wrong option\n");
        }

    }

return 0;
}
