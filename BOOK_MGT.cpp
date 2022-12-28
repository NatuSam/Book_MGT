#include <iostream>
#include <string.h>
using namespace std;
struct bookQ{
    string b_id;
    string b_name;
    string b_a_name;
    bookQ *nxt;
};
typedef bookQ *bnode;
bnode head, b, pre,pos,last,b2,b3;
int x,ch,y;
bool found;
void create(bnode *head){
    *head = NULL;
}
bool is_empty(bnode head){
    if(head ==NULL)
    return true;
    else
    return false;
}
bnode getbnode(){
    return new bookQ; 
}
void freebnode(bnode b){
    delete b;
}

 void insertb (bnode *head, bnode b){
     if(*head ==NULL)
     {*head = b;
     b->nxt =NULL;
     }
     else{
      last= *head;
      while(last->nxt!=NULL)
      {
          last =last->nxt;
      }
          last->nxt= b;
          b->nxt = NULL;
  }
   }

void deleteb (bnode *head, bnode b, bnode prev){
     if(prev ==NULL)
     {
        if(*head ==NULL)
         cout<<"\n no book to delete";
     else{
      b =*head;
      *head = b-> nxt;
      freebnode(b);
     }
     }
     else{
      prev-> nxt =  b-> nxt ;
       freebnode(b);
     }
  }
bnode prevb(bnode head, bnode b2, bnode &b3, string bid){
     b2 = NULL;
     b3 = NULL;
     found = false;
     while(head != NULL && !found){
         if(head->b_id == bid){
             b2 = head;
             found = true;
         }
        else{
            b3 = head;
            head = head ->nxt;
        }
     }
 return b2;
 }
 void display(bnode head){
      if(head!=NULL)
        {
        while (head!= NULL)
        {cout <<"\n**********\n";
            cout << head->b_id<<", "<< head->b_name<<", "<< head->b_a_name;
        head = head -> nxt;
        }
        }
        else
        cout<< "\n\n The list is empty!";
  }
  int menu(){
     cout<< "Menu\n";
     cout<< "1.Insert\n";
     cout<< "2.Delete\n";
     cout<< "3.Display\n";
     cout<<"4.Exit\n";
     cout<< "Enter your choice\n";
     cin>>ch;
     return ch;
 }
int main(){
    create(& head);
    string b_id2;
    string b_name2;
    string b_a_name2;
    do{
        ch =menu();
        switch (ch)
        {
        case 1:
        {
        cout<<"Enter Book Id\n";
        cin>>b_id2;
        cout <<"\n Enter book Name\n";
        cin>>b_name2;
        cout<<"\nEnter Book Author Name\n";
        cin>>b_a_name2;
        b=getbnode();
        b->b_id=b_id2;
        b->b_name=b_name2;
        b->b_a_name=b_a_name2;
        insertb(&head, b);
        }
            break;
        case 2:
        {
            cout<<"\n enter the book id of the book to be deleted :\t";
            cin>>b_id2;
            b= prevb(head,b2,b3,b_id2);
            deleteb(&head,b,b3);
        }
        break;
        case 3:
        {
            display(head);
        }
        default:
            break;
        }
    }while(ch!=4);
    return 0;
}