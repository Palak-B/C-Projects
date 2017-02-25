#include <iostream>
#include<conio.h>
using namespace std;

class dll
{
 dll *rlink;
 dll *header;
 dll *llink;
 int info;
 public:
     dll()
     {
         header=NULL;
     }
     void ins_beg();
     void ins_end();
     void display(dll*);
     dll* concat(dll x1,dll x2);
};
void dll::ins_beg()
{
    dll* temp=new dll;
    temp->rlink=temp->llink=NULL;
    cout<<"insert value"<<endl;
    cin>>temp->info;
    if(header==NULL)
    {
        header=temp;
        return;
    }
    else
    {
     temp->rlink=header;
     header->llink=temp;
    //(header->rlink)->llink=temp;
    header=temp;
    return;
    }
}
void dll::ins_end()
{
    dll* temp=new dll;
    cout<<"insert value"<<endl;
    cin>>temp->info;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(header==NULL)
    {
        header=temp;
        return ;
    }
    dll* cur=header;

    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return;
}
dll* dll::concat(dll x1,dll x2)
{
    dll* cur=x1.header;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=x2.header;
    x2.header->llink=cur;
    return x1.header;
}
void dll::display(dll *header)
{
    dll* cur=header;
    while(cur!=NULL)
    {
        cout<<cur->info;
        cur=cur->rlink;

    }
    return;
}
int main()
{
    dll x1,x2,x;
    int c=1;
    cout<<"Enter values in x1"<<endl;
    while(c==1)
    {
        x1.ins_end();
        cout<<"Press 1 to continue,2to exit"<<endl;
        cin>>c;
    }
    cout<<"Enter values in x2"<<endl;
    while(c==2)
    {
        x2.ins_end();
        cout<<"Press 2 to continue,3to exit"<<endl;
        cin>>c;
    }
    dll* k=x.concat(x1,x2);
    x.display(k);
    //cout << "Hello world!" << endl;
    return 0;
}
