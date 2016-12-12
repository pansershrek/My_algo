#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct treap{
    long long y,key,val;
    struct treap *l,*r;
};
typedef struct treap *ptree;
ptree n_node(long long key,long long val)
{
    ptree n_t=(ptree) malloc(sizeof(struct treap));
    n_t->key=key;
    n_t->val=val;
    n_t->y=(rand()<<7)^(rand());
    return n_t;
}
void merge(ptree *t,ptree l,ptree r)
{
    if (!l || !r)
        *t=l?l:r;
    else
    {
        if (l->y > r->y)
        {
            merge(&l->r,l->r,r);
            *t=l;
        }
        else
        {
            merge(&r->l,l,r->l);
            *t=r;
        }
    }
}
void split(ptree t,ptree *l,ptree *r,int key)
{
    if (!t)
    {
        *l=NULL;
        *r=NULL;
    }
    else
        if (t->key >key)
        {
            split(t->l,l,&(t)->l,key);
            *r=t;
        }
    else
        {
            split(t->r,&(t)->r,r,key);
            *l=t;
        }
}
void ser(ptree t,long long key)
{
    if (!t)
        return;
    ptree l=NULL,r=NULL,l1=NULL,r1=NULL;
    split(t,&l,&r,key-1);
    split(r,&l1,&r1,key);
    if (l1)
    {
        printf("%lld %lld\n",l1->key,l1->val);
    }
    merge(&r,l1,r1);
    merge(&t,l,r);
}
void del(ptree *t,ptree n_t)
{
    if (!(*t))
        return;
    ptree l=NULL,r=NULL,l1=NULL,r1=NULL;
    split(*t,&l,&r,n_t->key-1);
    split(r,&l1,&r1,n_t->key);
    r=r1;
    merge(t,l,r);
    free(n_t);
}
void ins(ptree *t,ptree n_t)
{
    if (*t==NULL)
    {
        *t=n_t;
        return;
    }
    ptree l=NULL,r=NULL,l1=NULL,r1=NULL;
    split(*t,&l,&r,n_t->key-1);
    split(r,&l1,&r1,n_t->key);
    if (l1)
    {
        l1->val=n_t->val;
        free(n_t);
    }
    else
        l1=n_t;
    merge(&r,l1,r1);
    merge(t,l,r);

}
void clean(ptree t)
{
    if (!t) return;
    if (t->l) clean(t->l);
    if (t->r) clean(t->r);
    free(t);
    return;
}
int main(void)
{
    ptree T=NULL;
    char ch;
    scanf("%c",&ch);
    while (ch!='F')
    {
        if (ch=='A')
        {
            long long key,val;
            scanf("%lld%lld\n",&key,&val);
            ins(&T,n_node(key,val));
        }
        else
            if (ch=='D')
            {
                long long key;
                scanf("%lld\n",&key);
                del(&T,n_node(key,0));
            }
        else
            {
                long long key;
                scanf("%lld\n",&key);
                ser(T,key);
            }
        scanf("%c",&ch);
    }
    clean(T);
    return 0;
}