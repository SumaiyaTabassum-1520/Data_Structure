#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
struct linkedList
{
    int value;
    linkedList *next;
};
linkedList *getNode(int val)
{
    linkedList *temp=(linkedList*)malloc(sizeof(linkedList));
    temp->value=val;
    temp->next=NULL;
    return temp;
}

void print(linkedList *node)
{
    while(node!=NULL)
    {
        cout << node->value<< "->";
        node=node->next;
    }
    cout<<endl;
}

linkedList* addToBeginning(linkedList *node,int val)
{
    linkedList *temp=getNode(val);
    temp->next=node;
    return temp;
}

linkedList* addToEnd(linkedList *node, int val)
{
    linkedList *browse;
    if(node==NULL)
    {
        node=getNode(val);
    }
    else
    {
        browse = node;
        while(browse->next!=NULL)
        {
            browse=browse->next;
        }
        linkedList *temp = getNode(val);
        browse->next=temp;
    }
    return node;
}

linkedList *Insert(linkedList *node, int val, int position)
{
    if(node==NULL)
    {
        linkedList *temp=getNode(val);
        return temp;
    }
    else if(position==1)
    {
        addToBeginning(node,val);
    }
    else
    {
        linkedList *prev=NULL,*browse=node;
        for(int i=1; i<position && browse!=NULL; i++)
        {
            prev=browse;
            browse=browse->next;
        }

        // A|-> B|->Temp|->C|->null

        linkedList *temp = getNode(val);
        temp->next=browse;
        prev->next=temp;
    }
    return node;
}

linkedList *DeleteFront(linkedList *node)
{
    if(node==NULL)
    {
        return node;
    }
    linkedList *temp=node;
    node=node->next;
    temp->next=NULL;
    free(temp);
    return node;
}

linkedList *DeleteLast(linkedList *node)
{

    // A|-> B|-> C|->NULL
    // A|->NULL
    linkedList *prev=NULL,*browse=node;
    if(node==NULL)
    {
        return node;
    }
    while(browse->next!=NULL)
    {
        prev=browse;
        browse=browse->next;
    }
    if(prev!=NULL)
    {
        prev->next=NULL;
    }
    else
    {
        node=NULL;
    }
    free(browse);
    return node;
}

linkedList *DeletePosition(linkedList *node,int position)
{
    // NULL
    // A|-> B|-> C|->NULL
    // A|->NULL

    if(node==NULL)
    {
        return node;
    }
    else if(position==1)
    {
        return DeleteFront(node);
    }
    else
    {
        linkedList *browse=node,*prev=NULL;
        for(int i=1 ; i<position && browse->next!=NULL ; i++)
        {
            prev=browse;
            browse=browse->next;
        }
        if(prev==NULL)
        {
            node=NULL;
        }
        else
        {
            prev->next=browse->next;
            browse->next=NULL;
        }
        free(browse);

    }
    return node;

}


linkedList* reverseLinkedList(linkedList *node)
{
    stack<linkedList*>stk;
    linkedList *rev=NULL,*temp;
    if(node==NULL)
    {
        return node;
    }
    while(node!=NULL)
    {
        temp=node;
        node=node->next;
        temp->next=NULL;
        stk.push(temp);
    }
    // stack
    // rev 3 ->2->5->9
    // temp ->9
    while(!stk.empty())
    {
        if(rev==NULL){
            rev=stk.top();
            temp=rev;
            stk.pop();
            continue;
        }
        temp->next=stk.top();
        temp=temp->next;
        stk.pop();
    }
    return rev;
}

// Duplicate Check
linkedList *removeDuplicate(linkedList *node)
{
    // 10-->11-->10-->2-->10-->2-->NULL
    // [10]=0,[2]=0,[11]=0
    bool duplicate[10000]= {false}; //we will toggle if we find the variable Amra dhore nicchi node er value 0-9999 er moddhe hobe
    linkedList *prev=NULL,*browse=node;
    if(node==NULL)
    {
        return node;
    }
    // 10-->11-->2-->NULL
    // [10]=1,[2]=1,[11]=1
    //browse Null
    //prev  2-> null
    //temp
    while(browse->next!=NULL)
    {
        if(duplicate[browse->value]==false)
        {
            duplicate[browse->value]=true;
        }
        else
        {
            linkedList *temp = browse;
            browse=browse->next;
            prev->next=browse;
            temp->next=NULL;
            free(temp);
            continue;
        }
        prev=browse;
        browse=browse->next;
    }
    if(duplicate[browse->value]==true)
    {
        linkedList *temp = browse;
        browse=browse->next;
        prev->next=browse;
        temp->next=NULL;
        free(temp);
    }
    return node;
}
void chooseOption()
{
    printf("Enter 1 to Insert node in LinkedList\n");
    printf("Enter 2 to Print LinkedList\n");
    printf("Enter 3 to insert node at beginning\n");
    printf("Enter 4 to insert node at any position\n");
    printf("Enter 5 to delete node from last\n");
    printf("Enter 6 to delete node from beginning\n");
    printf("Enter 7 to delete node from any position\n");
    printf("Enter 8 to reverse the LinkedList\n");
    printf("Enter 9 to remove duplicate data\n");

}

int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return a-b;
}

int main()
{

    int (*op)(int a,int b)=&sub; //function pointer variable
    linkedList *root = getNode(10);
    root= addToEnd(root,20);
    root= addToEnd(root,5);
    print(root);

    int data,position;
    int c;
    while(1)
    {
        chooseOption();
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            cin>>data;
            root=addToEnd(root,data);
            break;
        case 2:
            print(root);
            break;
        case 3:
            cin>>data;
            root=addToBeginning(root,data);
            break;
        case 4:
            cout<<"Insert data: "<<endl;
            cin>>data;
            cout<<"Position: "<<endl;
            cin>>position;
            root=Insert(root,data,position);
            break;
        case 5:
            root=DeleteLast(root);
            break;
        case 6:
            root=DeleteFront(root);
            break;
        case 7:
            cout<<"Position: "<<endl;
            cin>>position;
            root=DeletePosition(root,position);
            break;
        case 8:
            root=reverseLinkedList(root);
            break;
        case 9:
            root=removeDuplicate(root);
            break;
        }


    }
    return 0;
}
