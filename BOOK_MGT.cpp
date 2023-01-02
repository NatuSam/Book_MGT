#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
struct book{
    string b_id;
    string b_name;
    string b_a_name;
    string b_st;
    string s_id;
    string b_ad;
    book *nxt;
};
typedef book *bnode;
fstream booktbl;
string b_id2;
string b_name2;
string b_a_name2;
string b_st2;
string s_id2;
string b_ad2;

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

   void insertb(bnode *head, bnode b){
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

void updateb (bnode *head, bnode b, bnode prev){
    
      a:
      cout<<"which part to update?\n";
      cout<<"1.Book ID\n2.Book Name\n3.Book A_Name\n4.Book status\n5.student id\n 6.Book Address on table\n";
      cin>>ch;
      switch (ch)
      {
    case 1:
      cout <<"Enter the book Id\n";
      cin>>b_id2;
      b->b_id=b_id2;
        break;
    case 2:
      cout <<"Enter the book Name\n";
      cin>>b_name2;
      b->b_name=b_name2;
      break;
    case 3:
      cout <<"Enter the book Author Name\n";
      cin>>b_a_name2;
      b->b_a_name=b_a_name2;
        break;
    case 4:
    {
      cout <<"Enter the book status\n";
      cin>>b_st2;
      b->b_st=b_st2;
      if(b_st2 == "A"){
        b->s_id ='\0';
        cout <<"Enter the table address of the book\n";
      cin >>b_ad2;
      b->b_ad=b_ad2;
      }
      else if(b->b_st == "r")
      {
        cout <<"Enter the Id of the student\n";
      cin >>s_id2;
      b->s_id=s_id2;
      }
      if(b->b_st == "a")
      {
      cout <<"Enter the Book Address on table\n";
      cin>>b_ad2;
      b->b_ad=b_ad2;
      }
    }
      break;
    case 5:
     if(b->b_st == "r")
      {
      cout <<"Enter the student id\n";
      cin>>s_id2;
      b->s_id=s_id2;
      }
      else {
        cout<<"The book is available\n";
      }
        break;
    case 6:
     if(b->b_st == "a")
      {
      cout <<"Enter the Book Address on table\n";
      cin>>b_ad2;
      b->b_ad=b_ad2;
      }
      else {
        cout<<"The book is rented\n";
      }
        break;
      default:
      cout <<"wrong input\n";
      
        break;
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

bnode searchb(bnode head, bnode b2, bnode &b3, string bid){
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
            cout <<"\nBook ID  Book Name   Author Name   B Status   stu Id(if rented)   TBLAddress(if available)";
        while (head!= NULL)
        {cout <<"\n**************************************************************************\n";
            cout << head->b_id<<"     "<< head->b_name<<"       "<< head->b_a_name<<"             "<< head->b_st;
            if(head->b_st=="r"){
                cout<<"        "<<head->s_id;
            }
            if(head->b_st=="a"){
                cout<<"                         "<<head->b_ad;
            }
            head = head->nxt;
        }
        }
        else
        cout<< "\nThe list is empty!\n ";
  }

bnode sortprevb(bnode head, string bid){
     b2 = NULL;
     b3 = NULL;
     int i=0;
     found = false;
     while(head != NULL && !found){
        
         if(head->b_id == bid){
             b2 = head;
             found = true;
         }
        else{
            i=1;
            b3 = head;
            head = head ->nxt;
        }
     }
     if(i==1)
     return b3;
     else if(i==0)
     return NULL;
 }

bnode sort(bnode head){
    bnode b= head;
    bnode curr,curr2;
    pos=NULL;

    while(b->nxt!=NULL)
    {
    curr = b->nxt;
    if(b->b_id>curr->b_id){
    string temp_id= b->b_id;
    pos = sortprevb(head,temp_id);
    if(pos==NULL){
        curr2 = curr->nxt;
        head = curr;
        b->nxt= curr2;
        curr->nxt=b;
    }
    else{
        pos->nxt=curr;
        b->nxt=curr->nxt;
        curr->nxt=b;

    }
    b=head;
    }
    else{
        b=b->nxt;
    }

 }
 return head;
}

void load(bnode *head){
        booktbl.open("BookTable.txt", ios::in);
        char row[100];
        
            booktbl >>row;
            int j=0;
            int i=0;
        char s1[20];
        char s2[20];
        char s3[20];
        char s4[20];
        char s5[20];
            while (row[j]!='\0')
            {
        b = getbnode();
        for(int a=0;a<20;a++){
            s1[a]='\0';
            s2[a]='\0';
            s3[a]='\0';
            s4[a]='\0';
            s5[a]='\0';
        }
        
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
            while ((row[j]!=';')&&(row[j]!='.'))
            {
                s4[i]=row[j];
                i++;
                j++;
            }
            b->b_st= s4;
            if(row[j] == '.'){
                j++; i=0;
                while (row[j]!=';')
            {
                s5[i]=row[j];
                i++;
                j++;
            }
            if(b->b_st =="r")
            b->s_id=s5;
            else
            b->b_ad=s5;
            }
            j++; i=0;
            insertb(&(*head), b);  
          }
        booktbl.close();
}

  void save(bnode head) {
      if(head!=NULL)
        {
        booktbl.open("BookTable.txt", ios::out);
        while (head!= NULL)
        {
            booktbl << head->b_id<<"."<< head->b_name<<"."<< head->b_a_name<<"."<<head->b_st;
              if(head->b_st=="r"){
                booktbl<<"."<<head->s_id;
              }
              if(head->b_st=="a"){
                booktbl<<"."<<head->b_ad;
              }
              booktbl<<";";
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
     cout<< "5.Update\n";
     cout<< "6.Search\n";
     cout<< "7.Sort\n";
     cout<< "8.Exit\n";
     cout<< "\nEnter your choice\n";
     cin>>ch;
     return ch;
 }
int main(){
    create(& head);
    load(&head);
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
        if(b_st2=="r")
        {
           cout<<"\nEnter the student id\n";
        cin>>s_id2; 
        }
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
            b= searchb(head,b2,b3,b_id2);
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
        cout<<"Enter the Book ID of the book to be updated\n";
        cin>>b_id2;
        b= searchb(head,b2,b3,b_id2);
        if(b!=NULL)
            updateb(&head,b,b3);
            else
            cout<<"No Book by that ID";
        break;
        case 6:
        cout<<"Enter the Book ID of the book to be searched\n";
        cin>>b_id2;
        b=searchb(head,b2,b3,b_id2);
        cout << b->b_id<<"     "<< b->b_name<<"       "<< b->b_a_name<<"     "<< b->b_st;
            if(b->b_st=="r"){
                cout<<"     "<<b->s_id;
            }
      cout<<endl;
      break;
      case 7:
      head = sort(head);
      display(head);
      break;
        case 8:
        cout<<"Good Bye!";
        break;
        default:
            break;
        }
    }while(ch!=8);
    return 0;
}
