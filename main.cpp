#include <iostream>
#include <stdlib.h>

using namespace std;

class list
{
    list* head=NULL;
    list* tail=NULL;
    list* next;
    int val;
public:
    void ins();
    void display();
    void del();
    void insb();
    void reverse();
    void delalt();
};
void list::ins()
{
list* temp=new list;
cout<<"Enter the information to be inserted"<<endl;
int x;
cin>>x;
temp->val=x;
temp->next=NULL;
if(head==NULL)
{
    head=temp;
    return;
}
temp->next=head;
head=temp;
}
void list::insb()
{
    cout<<"Enter the element b4 which we have to insert the new element"<<endl;
    int k;
    cin>>k;
    cout<<"Enter the element to insert"<<endl;
    int c;
    cin>>c;
    list* cur=head;
    while(cur->next->val!=k)
    {
        cur=cur->next;
    }
    list* e =cur->next;
    list* temp=new list;
    temp->val=c;
    temp->next=e;
    cur->next=temp;

}
void list::reverse()
{
    list*r=NULL;
    list*p=head;
    list*q=p->next;
    if(head==NULL)
    {
        cout<<"empty";
        return;
    }
    while(q!=NULL)
    {
        //r=p;
        p->next=r;
        r=p;
        p=q;
        q=q->next;
    }
    p->next=r;
    head=p;

}
void list::delalt()
{
    list*cur=head;
    if(head==NULL)
    {
        cout<<"empty";
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    while(cur->next->next!=NULL)
    {
    list*c=cur->next;
    cur->next=cur->next->next;
    delete(c);
    cur=cur->next;
    }
    if(cur->next)
    {
        delete(cur->next);
        cur->next=NULL;
    }
}
void list::del()
{
    if(head==NULL)
    {
        cout<<"empty";
        return;
    }
list* cur=head;
head=head->next;
delete(cur);
}
void list::display()
{
    list*cur=head;
    while(cur!=NULL)
    {
        cout<<cur->val<<" ";
        cur=cur->next;
    }
}
int main()
{
    list l;
    int k;
    int p=1;
    while(p)
    {
        cout<<"1. insert 2. delete 3. display 4. exit 5. insert before 6. reverse 7. delete_alternate"<<endl;
        cin>>k;
        switch(k)
        {
    case 1:
        {
        l.ins();
        break;
        }
    case 2:
        {
        l.del();
        break;
        }
    case 3:
        {
        l.display();
        break;
        }
    case 4:
        {
        exit(0);
        break;
        }
    case 5:
        {
            l.insb();
            break;
        }
    case 6:
        {
            l.reverse();
            break;
        }
    case 7:
        {
            l.delalt();
            break;
        }
    default:
        cout<<"invalid";

    }
    }

    //cout << "Hello world!" << endl;
    return 0;
}
