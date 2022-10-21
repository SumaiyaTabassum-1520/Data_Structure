#include<stdio.h>
struct Stack
{
    int arr[10000];
    int idx;
    Stack()
    {
        idx = -1;
    }
    void push(int val)
    {
        idx++;
        arr[idx]=val;

    }
    void pop()
    {
        if(!isEmpty())
        {
            idx--;
        }
    }
    int top()
    {
        return arr[idx];
    }
    bool isEmpty()
    {
        if (idx == -1)
        {
            return true;
        }
        else
        {

            return false;
        }

    }
} ;


int main()
{
    Stack object=Stack();
    int c;
    while(1)
    {
        printf("enter your choice :1-push\n\t\t   2-pop\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            int val;
            scanf("%d",&val);
            object.push(val);
            break;
        case 2:
            if(object.isEmpty()==false){
            printf("%d\n",object.top());
            }
            else
            {
                printf("Stack is empty\n");
            }
            object.pop();
            break;
        default:
            printf("wrong option\n");
        }

    }
    return 0;
}
