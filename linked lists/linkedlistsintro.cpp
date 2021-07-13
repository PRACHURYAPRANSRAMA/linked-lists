//
//  main.cpp
//  linked lists
//
//  Created by PRACHURYA PRAN SARMA'SVELAR on 25/03/21.
//

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <iterator>
#include <map>
#include <math.h>

using namespace std;

#define pb     push_back
#define endl    '\n'
#define pll    pair<int,int>
#define vll    vector<int>
#define all(a) (a).begin(),(a).end()
#define x       first
#define y      second
#define sz(x)  (int)x.size()
#define hell   1000000007
#define lbnd   lower_bound
#define ubnd   upper_bound
#define bs     binary_search
#define mi     map<int,int>
#define gcd(a,b)  __gcd((a),(b))
#define lcm(a,b)  ((a)*(b)) / gcd((a),(b))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie


struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
    int size;
    
    node* get_node(int val)
    {
        node *temp = new node;
        temp -> data=val;
        temp -> next=NULL;
        
        return temp;
    }
    
public:
    linked_list(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void print()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->next == NULL)//last element
            {
                cout<<endl;
            }
            else
            {
                cout<<" --> ";
            }
            temp=temp->next;
        }
    }
    
    void push_back(int val)
    {
//        node *temp = new node;
//        temp -> data=val;
//        temp -> next=NULL;
        node *temp = get_node(val);
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail -> next=temp;
            tail=temp;
        }
        size++;
    }

    int get_size()
    {
        return size;
    }
    void push_front(int val)
    {
        node *temp = get_node(val);
//        node *temp=new node;
//        temp -> data =val;
//        temp -> next =NULL;
        if(head ==NULL)
        {
            head=tail=temp;
        }
        else
        {
            temp -> next=head;
            head = temp;
        }
        size++;
    }
    void insert(int index,int val)
    {
        if(index>size|| index<0)
        {cout<<"Not possible to insert "<<val<<" at position "<<index<<endl;
            return;
        }
      else if(index==0)
        {
            push_front(val);
        }
        else
        {
            node *new_node = get_node(val);
            node *prev=head;
            for(int i=0;i<index-1;i++,prev=prev->next);
            // this for loop is similar to-
            //for(int i=0;i<index-1;i++)
            // {prev=prev->next};
            new_node -> next = prev-> next;
            prev->next=new_node;
            size++;
        }}
    void print_kth(int index)
    {
        if(index>=size||index<0)
        {
            cout<<"Out of bound index"<<endl;
            return;
        }
        node *temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        cout<< temp-> data <<endl;
        
    }
    void delete_kth(int index)
    {
        if(index>=size||index<0)
        {
            cout<<"Out of bound index"<<endl;
            return;
        }
        
    
            node *cur=head;
            node *prev=head;
            if(index==0)
            {
                head= head -> next;
                free(cur);
                size--;
                return;
            }
            for(int i=0;i<index;i++)
            {
                prev=cur;
                cur=cur -> next;
            }
            prev-> next=cur->next;
            free(cur);
            size--;
           if(index==size-1)//cur is my tail and cur is now deleted
            {
                tail=prev;
            }
           
        }
    
    
    void printRecursively(node *temp)
    {
        if(temp==NULL)
        {
            cout<<endl;
            return;
        }
        cout<<"-->"<<temp->data;
        printRecursively(temp->next);
        return;
    }
 
    void printjust(node *temp)
    {
        if(temp==NULL)
        {
            cout<<endl;
            return;
        }
        printRecursively(temp->next);
        cout<<"-->"<<temp->data;
     
        return;
    }
    void printReverse(node *temp)
    {
        if(temp->next==NULL)// temp is the last element
        {
            head=temp;
            return;
        }
        printRecursively(temp->next);
        node *next= temp->next;
        next ->next=temp;
        temp->next=NULL;
        return;
        
    }
    node *get_tail()
    {
        return tail;
    }
    
    node *get_head()
    {
        return head;
    }
};


int main()

{
    linked_list p;
    
    p.push_back(6);
    p.push_back(5);
    p.push_back(9);
    p.push_front(90);
    p.insert(2,20);
    p.insert(10,50);
    p.insert(0,34);
    p.insert(6, 80);
    p.print_kth(2);
    p.delete_kth(2);
    p.print();
    p.printRecursively(p.get_head());
   p.printjust(p.get_head());
    p.printReverse(p.get_tail());
    cout<<p.get_size()<<endl;
    
}
