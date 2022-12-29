#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
struct book{
    string b_id;
    string b_name;
    string b_a_name;
    string b_st;
    book *nxt;
};
fstream booktbl;
string b_id2;
string b_name2;
string b_a_name2;
string b_st2;
typedef book *bnode;
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
    return new book; 
}
void freebnode(bnode b){
    delete b;
}

 void insertfirst(bnode *head, bnode b){
     if(*head ==NULL)
     {*head = b;
     b-> nxt =NULL;
     }
     else{
       b-> nxt = *head;
      *head = b;
     }
 }
   void insertb(bnode *head, bnode p){
     if(*head ==NULL)
     insertfirst(&(*head), b);
     else{
      last= *head;
      while(last->nxt!=NULL)
      {
          last =last->nxt;}
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
     cout<<"\n Node Deleted!";
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
            cout << head->b_id<<", "<< head->b_name<<", "<< head->b_a_name<<", "<< head->b_st;
        head = head->nxt;
        }
        }
        else
        cout<< "\nThe list is empty!\n ";
  }
void load(bnode *head){
        booktbl.open("BookTable.txt", ios::in);
        char row[100];
        char s1[5];
        char s2[20];
        char s3[20];
        char s4[3];
        b = getbnode();
            booktbl >>row;
            int j=0;
            int i=0;
            
            while (row[j]!='\0')
            {
            while (row[j]!='.')
            {
                s1[i]=row[j];
                i++;
                j++;
            }
            b->b_id= s1; 
            j++; i=0;
            while (row[j]!='.')
            {
                s2[i]=row[j];
                i++;
                j++;
            }
            b->b_name= s2;
            j++; i=0;
            while (row[j]!='.')
            {
                s3[i]=row[j];
                i++;
                j++;
            }
            b->b_a_name= s3;
            j++; i=0;
            while (row[j]!=';')
            {
                s4[i]=row[j];
                i++;
                j++;
            }
            b->b_st= s4;
            cout<<b->b_id<<", "<< b->b_name<<", "<< b->b_a_name<<", "<<b->b_st<<endl;
            j++; i=0;
            insertb(head,b); 
          }
        booktbl.close();
}
  void save(bnode head) {
      if(head!=NULL)
        {
        booktbl.open("BookTable.txt", ios::out);
        while (head!= NULL)
        {
            booktbl << head->b_id<<"."<< head->b_name<<"."<< head->b_a_name<<"."<<head->b_st<<";";
            head = head -> nxt;
        }
        booktbl.close();
        }
        else
        cout<< "\nThe list is empty!\n";
  }
  int menu(){
     cout<< "\nMenu\n";
     cout<< "1.Insert\n";
     cout<< "2.Delete\n";
     cout<< "3.Display\n";
     cout<< "4.Save\n";
     cout<< "5.Load\n";
     cout<< "6.Exit\n";
     cout<< "\nEnter your choice\n";
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
        cout<<"\nEnter Book Status\n";
        cin>>b_st2;
        b=getbnode();
        b->b_id=b_id2;
        b->b_name=b_name2;
        b->b_a_name=b_a_name2;
        b->b_st=b_st2;
        insertb(&head, b);
        }
            break;
        case 2:
        {
            cout<<"\n enter the book id of the book to be deleted :\t";
            cin>>b_id2;
            b= prevb(head,b2,b3,b_id2);
            if(b!=NULL)
            deleteb(&head,b,b3);
            else
            cout<<"No Book by that ID";
        }
        break;
        case 3:
        {
            display(head);
        }
        break;
        case 4:
        save(head);
        break;
        case 5:
        load(&head);
        break;
        case 6:
        cout<<"Good Bye!";
        break;
        default:
            break;
        }
    }while(ch!=6);
    return 0;
}