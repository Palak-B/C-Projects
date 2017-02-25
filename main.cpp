#include <iostream>
#include <stdlib.h>
using namespace std;
class sll
{
    sll* next;
    int info;

public:
    void insert_beg();
    void insert_end();
    void delete_beg();
    void delete_end();
    void display();
    sll* header;
    sll()
    {
        header=NULL;
    }
};
void sll::insert_beg()
{
    sll* temp=new sll;
    temp->next=NULL;
    cout<<"Enter value"<<endl;
    cin>>temp->info;
    if(header==NULL)
    {
      header=temp;
      return ;
    }
    else
    {
      temp->next=header;
      header=temp;
      return;
    }
}
void sll::insert_end()
{
    sll* temp=new sll;
    temp->next=NULL;
    cout<<"Enter value"<<endl;
    cin>>temp->info;
    if(header==NULL)
    {

        //temp->next=cur;
        header=temp;
        //delete(cur);
        return;
    }
    else
    {
    sll* cur=header;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    return ;
    }
}
void sll::delete_beg()
{
    if(header==NULL)
    {
        cout<<"Underflow"<<endl;
        return ;
    }
    sll* temp=header;
    header=header->next;
    delete(temp);
    return;
}
void sll::delete_end()
{
    if(header==NULL)
    {
        cout<<"underflow";
        return ;
    }
    sll* cur=header;
    if(cur->next==NULL)
    {
        delete(cur);
        header=NULL;
        return;
    }
    while(cur->next->next!=NULL)
    {
        cur=cur->next;
    }
    delete(cur->next);
    cur->next=NULL;
    return;
}
void sll::display()
{
    sll* cur=header;
    if(cur==NULL)
    {
        cout<<"empty";
        return;
    }
    while(cur!=NULL)
    {
        cout<<cur->info;
        cur=cur->next;
    }
    cout<<endl;
    return;
}
int main()
{
    sll s;
    //s.header=NULL;
    //sll* h=s.header;
cout<<"Press 1 for Stack and 2 for Queue"<<endl;
int ch;
cin>>ch;
switch(ch)
{
case 1:
    {

        int k;
        while(1)
        {
        cout<<"Implementing Stack"<<endl;
        cout<<"1-push"<<endl<<"2-pop"<<endl<<"3-print"<<endl<<"4exit";
        cin>>k;
        switch(k)
        {
        case 1:
            {
                s.insert_end();
                break;
            }
        case 2:
            {
                s.delete_end();
                break;
            }
        case 3:
            {
                s.display();
                break;
            }
        default:
            exit(0);
        }
        }
        break;
    }
case 2:
    {

        int k;
        while(1)
        {
        cout<<"Implementing Queue"<<endl;
        cout<<"1-push"<<endl<<"2-pop"<<endl<<"3-print"<<endl<<"4-exit";
        cin>>k;
        switch(k)
        {
        case 1:
            {
                s.insert_end();
                break;
            }
        case 2:
            {
                s.delete_beg();
                break;
            }
        case 3:
            {
                s.display();
                break;
            }
        default:
            exit(0);
        }
    }
    break;
}
    //cout << "Hello world!" << endl;

}
 return 0;
}
