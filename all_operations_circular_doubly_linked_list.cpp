#include <iostream>
using namespace std;

class cdllnode{
public:
    int data;
    cdllnode*next;
    cdllnode*prev;
    cdllnode(int data)
    {
        this-> data=data;
        this->next=nullptr;
        this->prev=nullptr;                 
    }
};


class cdlllist{
    public:
    
    cdllnode*addnode_beg(cdllnode*&head, int data)
    {
        if(head==nullptr)
        {
            cdllnode*newnode=new cdllnode(data);
            head=newnode;
            newnode->next=newnode;
            newnode->next=newnode;
            return head;
        }

        else{
                cdllnode*newnode=new cdllnode(data);
                cdllnode*temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                newnode->next=head;
                head->prev=newnode;
                temp->next=newnode;
                newnode->prev=temp;
                head=newnode;
        }

        return head;
    }

    cdllnode*addnode_end(cdllnode*&head, int data)
    {
        if(head==nullptr)
        {
            cdllnode*newnode=new cdllnode(data);  
            head=newnode;
            newnode->next=newnode;
            newnode->next=newnode;
            return head;

        }
        cdllnode*newnode=new cdllnode(data);
        cdllnode*temp=head;

        while(temp->next!=head)
            temp=temp->next;

        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        head->prev=newnode;
        return head;
       
    }
    
    cdllnode*deletenode_beg(cdllnode*head)
    {
        if(head==nullptr)
            return head;
        cdllnode*temp=head;
        while(temp->next!=head)
          temp=temp->next;
        cdllnode*todelete=head;
        head=head->next;
        head->prev=temp;
        temp->next=head;
        delete(todelete);
        return head;
    }

    cdllnode*deletenode_end(cdllnode*head)
    {
          if(head==nullptr)
            return head;
        cdllnode*temp=head;
        while(temp->next->next!=head)
            temp=temp->next;
        
        cdllnode*lastnode=temp->next;
        temp->next=head;
        head->prev=temp;
        delete(lastnode);
        return head;
    }
   

    cdllnode*createlist(cdllnode*head)
    {
        cout<<"ENTER THE NUMBER OF NODES IN THE LIST"<<endl;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            head=addnode_end(head, data);
        }

        return head;
    }
    
    void printlist(cdllnode*head)
    {
        cdllnode*temp=head;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
};


int main()
{
    cdlllist cdll;
    cdllnode*head=nullptr;
    head=cdll.createlist(head);
    head=cdll.addnode_beg(head, 0);
    head=cdll.addnode_end(head, 0);
    head=cdll.deletenode_beg(head);
    head=cdll.deletenode_end(head);
    
    cdll.printlist(head);
    return 0;
}