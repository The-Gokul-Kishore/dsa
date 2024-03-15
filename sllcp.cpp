#include<iostream>
using namespace std;
class Node
{   
    public:
    int data;
    Node* next;
    Node(int value)
    {
        data= value;
        next = NULL;
    }

};
class sll
{
	Node* head;
	public:
    
    
    sll()
    {
        head = NULL;
    }
    void insert(int val)
    {
        
        Node* newnode = new Node(val);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        Node *curr = head;
        while(curr->next !=NULL)
        {
            curr= curr->next;
        }
        curr->next = newnode;
    }
    void insertbegining(int val)
    {
        Node* newnode = new Node(val);
        if(head ==NULL)
        {
            head = newnode;
            return ;
        }
        newnode->next = head;
        head = newnode;

    }
    void insert(int val,int pos)
    {
             if(pos<1)
            {
                cout<< "error:out of bounds";
            }
            Node* newnode = new Node(val);
            if(head == NULL)
            {
                head = newnode;
                return;
            }
            if(pos==1)
            {
                newnode->next=head;
                head = newnode;
            }
            int cnt =1;
            Node *curr = head;
            while(curr->next !=NULL&&pos-1!=cnt)
            {
                curr= curr->next;
                cnt++;
            }
            if(pos-1==cnt)
            {
                cout<<cnt<<" "<<pos<<endl;
                newnode->next = curr->next;
                curr->next = newnode;
            }
            else
            {
                cout<<"error:out of bounds";
            }         
        
    }
    void deletepos(int pos)
    {
        Node* curr = head;
        int cnt = 1;
        while(curr->next !=NULL&&cnt<pos-1)
        {
            cnt++;
            curr = curr->next;
        }
        if(cnt!=pos-1)
        {
            cout<<"error:index out of bound";
        }
        else
        {
            Node* temp = curr->next;
            curr->next = temp->next;
        }
    }
    void travasal()
    {
        Node* current = head;
        cout<<"{";
        while(current!=NULL)
        {
            cout<<current->data<<"\t";
            current = current->next;
        }
        cout<<"}"<<endl;
    }
};
int main()
{   
    sll l;
    l.insert(10);
    l.insert(29);
    l.insert(112,2);
    l.insert(1,1);
    l.deletepos(3);
    l.travasal();
    l.insert(1111);
    l.insert(12,6);
    l.travasal();
    l.deletepos(2);
    l.travasal();
    return 0;
}