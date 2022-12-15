#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        cout<<"s er size "<<s.size()<<endl;
        stack <char> stk;
        int i;
        bool flag = true;
        for( i=0 ; i < s.size() ; i++)
        {
            if(s[i]=='(')
            {
                stk.push(')');
            }
            else if(s[i]=='{')
            {
                stk.push('}');
            }
            else if(s[i]=='[')
            {
                stk.push(']');
            }
            else if(stk.empty()==true){
                cout<<"stk empty break"<<endl;
                flag=false;
                break;
            }
            else if(stk.top()==s[i])
            {
                cout<<"stack empty na and top match paise "<<stk.size()<<endl;
                stk.pop();
            }
            else
            {
                cout<<"else e dhuke break kortesi"<<endl;
                flag=false;
                break;
            }
        }
        cout<<i<<" " << s.size()<<" " << stk.size()<<" " <<stk.top()<<endl;
        if(stk.empty()!=true)
        {
            cout<<"stack empty na "<<endl;
            flag=false;
        }
        return flag;

    }
};

/*#include<bits/stdc++.h>
using namespace std;

stack <char> stk;
char s[100000];

void Clear()
{
    while(stk.empty()!=true)
    {
        stk.pop();
    }
}
bool isValid(char *s)
{
    int i;
    bool flag = true;
    cout<<"for e dhuktesi"<<endl;
    Clear();
    for( i=0 ; i < s[i]!=0 ; i++)
    {
        cout<<i<<" "<<s[i]<<endl;
        if(s[i]=='(')
        {
            stk.push(')');
        }

        else if(s[i]=='{')
        {
            stk.push('}');
        }

        else if(s[i]=='[')
        {
            stk.push(']');
        }

        else if(stk.empty()!=true && stk.top()==s[i])
        {
            cout<<stk.size()<<" 11 "<<s[i]<<endl;
            stk.pop();
        }
        else
        {
            flag=false;
            cout<<"if e dhuki na"<<endl;
            break;
        }
    }
    cout<<"loop complete"<<endl;
    if(stk.empty()!=true)
    {
        flag=false;
        cout<<"if e dhuki"<<endl;
    }
    return flag;
}
*/
int main()
{
    string s;
    cin>>s;
    Solution sln = Solution();
    if(sln.isValid(s)==true)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;

}
