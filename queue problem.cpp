#include<stdio.h>
struct Queue
{
    int arr[10000];
    int Front,Back;
    Queue()
    {
        Front = -1;
        Back = -1;
    }
    bool isEmpty()
    {
        if (Front==-1 && Back== -1)
        {
            return true;
        }
        else
        {

            return false;
        }

    }
    void Insert(int value)
    {
        if(isEmpty())
        {
            Front=0;
        }
        Back=Back+1;
        arr[Back]=value;

    }
    void Delete()
    {
        if(isEmpty())
        {
            return ;
        }
        if(Front==Back)
        {
            Front=Back=-1;
        }
        else
        {
            Front++;
        }

    }
    int getBack()
    {
        if(!isEmpty())
    {
        return arr[Back];
        }
        return -1;
    }

    void display()
    {
        int i;
        for(i=Front ; i<=Back ; i++)
        {
                printf("%d\n",arr[i]);
        }

    }
};

int main()
{
    Queue q=Queue();
    int c;
    while(1)
    {
        printf("enter your choice :1-insert\n\t\t   2-delete\n\t\t   3-to print the queue\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            int val;
            scanf("%d",&val);
            q.Insert(val);
            break;
        case 2:
            q.Delete();
            break;
        case 3:

            if(q.isEmpty()==false)
            {
                 q.display();
            }
            else{
                 printf("The queue is empty\n");
            }
            break;
        default:
            printf("wrong option\n");
        }

    }
    return 0;
}
