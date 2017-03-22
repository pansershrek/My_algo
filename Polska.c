#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s,add="";
string s1;
vector <string> a;
vector <string> q;
vector <int> ans;
int op=0,sl=0;
bool f=false;
bool to_str(string ss,ll &ans)
{
    ll sum=0;
    ll m=1;
    while (!ss.empty())
    {
        if (ss[ss.size()-1]>='0' && ss[ss.size()-1]<='9')
        {
            sum+=m*(ll(ss[ss.size()-1])-ll('0'));
            m*=10;
            ss.pop_back();
        }
        else
            break;
    }
    ans=sum;
    return ss.empty();
}
bool er(int x)
{
    int y=x;
    while (y>=0 && s[y]==' ')
        y--;
    if (y<0) return true;
    int z=x;
    while (z<s.size() && s[z]==' ')
        z++;
    if (z==s.size())
        return true;
    if (s[z]>='0' && s[z]<='9' && s[y]>='0' && s[y]<='9')
        return false;
}
int main()
{
    getline(cin,s);
    for (int i=0;i<s.size() && !f;i++)
    {
        if ((s[i]==' ') && !er(i))
            f=true;
        if (s[i]!=' ')
            s1+=s[i];
    }
    for (int i=0;i<s1.size() && !f;i++)
    {
        if (s1[i]!='+' && s1[i]!='-' && s1[i]!='*' && s1[i]!='(' && s1[i]!=')')
            add+=s1[i];
        else
        {
            if (add!="")
            {
                a.push_back(add);
                sl++;
                add="";
            }

            if (s1[i]=='(')
            {
                q.push_back("(");
            }
            else
            if (s1[i]==')')
            {
                while (!q.empty() && q[q.size()-1]!="(")
                {
                    a.push_back(q[q.size()-1]);
                    q.pop_back();
                }
                if (q.empty())
                    f=true;
                else
                    q.pop_back();
            }
            else
             if (s1[i]=='*')
             {
                 op++;
                 while (!q.empty() && q[q.size()-1]=="*")
                 {
                     a.push_back(q[q.size()-1]);
                     q.pop_back();
                 }
                 q.push_back("*");
             }
             else
             {
                 op++;
                 while (!q.empty() && q[q.size()-1]!="(")
                 {
                     a.push_back(q[q.size()-1]);
                     q.pop_back();
                 }
                 s="";
                 s+=s1[i];
                 q.push_back(s);
             }

        }
    }
    if (add!="")
    {
        sl++;
        q.push_back(add);
    }
    while (!q.empty())
    {
        a.push_back(q[q.size()-1]);
        q.pop_back();
    }
    if (sl-1!=op)
        f=true;
    for (int i=0;i<a.size() && !f;i++)
    {
        if (a[i]!="+" && a[i]!="-" && a[i]!="*")
        {
            ll add=0;
            if (to_str(a[i],add))
                ans.push_back(add);
            else
                f=true;
        }
        else
            if (ans.size()<2)
                f=true;
            else
            {
                ll a1=ans[ans.size()-1];
                ans.pop_back();
                ll b=ans[ans.size()-1];
                ans.pop_back();
                if (a[i]=="+")
                {
                    ans.push_back(a1+b);
                }
                else
                    if (a[i]=="*")
                    {
                        ans.push_back(a1*b);
                    }
                    else
                    {
                        ans.push_back(b-a1);
                    }
            }

    }
    if (ans.size()!=1)
        f=true;
    if (f) cout<<"WRONG";
    else
        cout<<ans[0];
    return 0;
}
