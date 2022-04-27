#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<stdbool.h>
#include <Windows.h>

using namespace std;

struct node
{
char name[30];
char number[15];
char address[40];
char email[40];
struct node *left, *right, *mid;
};
struct node* deleteNodecenter(struct node* root, char key[],char number[]);
struct node* searchin(struct node* root,char name[]);
void modify(struct node* ptr);
void savein(struct node *head,char fn[]);
void gosave();
void insertstackpush(struct node* temp);
void load();
struct node* pop(struct node*stack);
//void display();
void display();
void print();
void save();
//void savetofile(char i,int hash);
void savein(struct node *head,char fn[]);
struct node *input(struct node *);
void deletestackpush(struct node* );
struct node* deleteNode(struct node*root[], char key[]);
struct node* deleteNodeinside(struct node*, char key[],char number[]);
struct node *findmin(struct node *tree);
void inorder(int i);
void inorderinside(struct node *);
//struct node *insert(struct node *head[],struct node *new_node);
struct node *insertinside(struct node *,struct node *);
struct node *findmin(struct node *tree);
struct node *insertstack = NULL,*deletestack = NULL,*head[26];


int main(){
struct node *n_node,*ptr;
char ans;
char n[30],num[15];
int hash,k =0;
for(int i=0;i<26;i++)
    {
	head[i]=NULL;    
    }
int option;
char key[40];
int temp_status;
printf("\n**********************************************************************************************PHONEBOOK************************************************************************************************************");
printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
load();
do{
	cout<<"\nMENU\n 1)INSERT\n2)PRINT\n3)SEARCH AND MODIFY\n4)DELETE A CONTACT\n5)EXIT\nENTER YOU CHOICE\n";
	cin>>option;
	
	switch(option)
	{
		case 1:
			do{	
				n_node = input(n_node);
				hash = int(n_node->name[0]) % 65;
				//strcpy(n,n_node->name);
				insertstackpush(n_node);
				head[hash] = insertinside(head[hash],n_node);
				cout<<"\nCONTINUE ? (y/n)\t";
				cin>>ans;
			}while(ans == 'y' || ans == 'Y');
			
		break;
			
		case 2:
		//cout<<" PRINT\n";
		print();
		break;
		
		case 3:
		cout<<"ENTER THE NAME TO BE SEARCHED\n";
		cin>>key;
		while(key[k] != '\0'){
		key[k] = toupper(key[k]);
		k++;
		}
		
		hash = int (key[0]) % 65;
		ptr = searchin(head[hash], key);
		if(ptr!=NULL){
			cout<<"\n\nNAME :  "<< ptr -> name<<endl;
			cout<<"NUMBER :  "<< ptr -> number<<endl;
			cout<<"ADDRESS :  "<< ptr -> address<<endl;
			cout<<"E-MAIL :  "<< ptr -> email<<endl;
			cout<<"\n\nDo you want to modify? (y/n)\n\n"<<endl;
			cin>>ans;
			if(ans == 'y' || ans == 'Y'){
				
				modify(ptr);
				//deletestackpush(ptr);
			}
			
		}
		k=0;
		//display();
		//cout<<" SEARCH(*for representation)\n";
		break;
		
		case 4:
		cout<<"ENTER THE NAME\n";
		cin>>key;
		cout<<"ENTER THE NUMBER\n";
		cin>>num;
		while(key[k] != '\0'){
		key[k] = toupper(key[k]);
		k++;
		}
		hash = int (key[0]) % 65;
		head[hash] = deleteNodeinside(head[hash],key,num);
		k=0;
		break;
		
		case 5:
	
		break;
		
		default:
		cout<<"ENTER VALID CHOICE\n";
		break;
	
	}
	
}while(option!=5);
//save();
gosave();
return 0;
}



struct node *insertinside(struct node *head,struct node *new_node)
{
	if(head == NULL)
	{
		new_node -> left = NULL;
		new_node -> right = NULL;
		head = new_node;
		//insertstackpush(new_node);
	}
	else
	{
		

	

		if(strcmp(head -> name, new_node -> name) == 0)
		{
			if(strcmp(head -> number, new_node -> number) == 0){
				cout<<"\n\t\tAlready exist!!!!"<<endl;
			}
			else{
				head -> mid = insertinside(head -> mid, new_node);
				//insertstackpush(new_node);
			}
			
		}	
		else if(strcmp(head -> name, new_node -> name) > 0)
		{
			head -> left = insertinside(head -> left, new_node);
			//insertstackpush(new_node);
		}
		else
		{
			head -> right = insertinside(head -> right, new_node);
			//insertstackpush(new_node);
		}
	}
	return head;
}



void print()
{	
	//cout<<"printing ";
	for(int i =0;i<=26;i++){
		if(head[i] == NULL){ continue;}
		if(head[i] != NULL){
			inorderinside(head[i]);
			//inorder(i);
		}
	}
}
	

void inorderinside(struct node *head)
{
	
	if(head != NULL){
		
		inorderinside(head -> left);
		
		cout<<"\n\nNAME :  "<< head -> name;
		cout<<"\nNUMBER :  "<< head -> number;
		cout<<"\nADDRESS :  "<< head -> address;
		cout<<"\nE-MAIL :  "<< head -> email;		
		inorderinside(head -> mid);
		inorderinside(head -> right);
	}


	 
}

void load(){
struct node *new__node;
int hash ;
	char name[30];
	char number[15];
	char address[40];
	char email[40];
	char c[40];
	cout<<"\n\n\n\t\tPlease wait for a moment\n";
	cout<<"\t\tRetrieving data form file\n\n";
	char fn[] = "C:/Users/Admin/Documents/PhoneBook/Directory_A.txt";
	Sleep(1000);
	for(char i = 'A'; i <= 'Z' ; ++i){
		fn[45] = i;
		hash = int(i) % 65;
		//cout<< fn<< endl;
	fstream ob(fn);
	while(!ob.eof()){
		ob.getline(c, 40);
		if(c[0] != '\0' ){
			strcpy(name, c);
			ob.getline(c, 40);
			strcpy(number, c);
			ob.getline(c, 40);
			strcpy(address, c);
			ob.getline(c, 40);
			strcpy(email, c);
	
			new__node = (struct node*)malloc(sizeof(struct node));
			//cout<< name<<endl;
			strcpy(new__node -> name, name);
			strcpy(new__node -> number, number);
			strcpy(new__node -> address, address);
			strcpy(new__node -> email, email);
			head[hash] = insertinside(head[hash],new__node);	
		}
	}
	ob.close();
	ob.open(fn,ios::trunc);
	ob.close();
}
}

struct node *input(struct node *ne_node){
	
	char name[30];
	char number[15];
	char address[40];
	char email[40];
	int k = 0;
	//cout<<"\nENTER NAME  :  ";  
	cin.getline(name,30);
	
	
	while((strlen(name)==0)){
																						
		cout<<"\nENTER VALID NAME  : ";
		cin.getline(name, 30);
			
			
	} 
	while(name[k] != '\0'){
		name[k] = toupper(name[k]);
		k++;
	}	
	
	
	cout<<"\nENTER NUMBER :  ";
	   cin.getline(number,15);
	   
		while(strlen(number)!=10){
	   		cout<<"\nENTER NUMBER  :  ";
			cin.getline(number,15);
	   }
	   
			
	//cout<<number<<endl;	
	  cout<<"\nENTER ADDRESS :  ";
	   cin.getline(address,40); 
	   
	//cout<<number<<endl;
	   cout<<"\nENTER E-MAIL :  ";
	   cin.getline(email,40);
	   

	ne_node = (struct node*)malloc(sizeof(struct node));
	strcpy(ne_node -> name, name);
	strcpy(ne_node -> number, number);
	strcpy(ne_node -> address, address);
	strcpy(ne_node -> email, email);
	
	return ne_node;
  }


struct node* deleteNodeinside(struct node* root, char key[],char number[])
{
	struct node* temp;
	char mob_num[15];
	if (root== NULL){
		 return root;
	}
    /*   
	if(strcmp(root -> name,key) == 0){
		if(strcmp(root -> number,number) != 0){
			if(root ->mid-> mid != NULL){
			root->mid = deleteNodeinside(root -> mid , key,number);
			}

		}

			
	}*/
		
    if (strcmp(root -> name,key) > 0){
	//if(strcmp(root -> number,key) == 0){
    	 root->left = deleteNodeinside(root->left, key,number);
    //}
	}
       
 

    else if (strcmp(root -> name,key) < 0){
    	//if(strcmp(root -> number,key) == 0){
    	 root->right = deleteNodeinside(root->right, key,number);
    //}
	}
   

			
	 
 

    else {
    //	if(root->mid == NULL){
		
    	cout<<"NAME::"<<root -> name<<endl;
    	cout<<"NAME::"<<root -> number<<endl;
    	cout<<"NAME::"<<root -> address<<endl;
    	if(strcmp(root -> number,number) == 0){
		
    	if(root->mid != NULL){
    		temp = findmin(root->mid);
    	strcpy(root -> name,temp -> mid-> name);
		strcpy(root -> number,temp  -> mid->  number);
		strcpy(root -> address,temp  -> mid->  address);
		strcpy(root -> email,temp  -> mid->  email);
        free(temp->mid);
		temp -> mid = NULL;
        return root;
    		
    	}
		}
		if(strcmp(root -> number,number) != 0){
			temp = root;
			while(strcmp(temp-> mid ->number,number)!=0){
				temp=temp->mid;
			}
			temp -> mid = temp -> mid -> mid;
			free(temp-> mid);
			return root;
		}
         if (root->left == NULL) {
            temp = root->right;
            deletestackpush(root);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
        	deletestackpush(root);
            free(root);
            return temp;
        }
 
	
        temp = findmin(root->right);
 	    /*if(root -> mid !=NULL){
    	temp = root -> mid;
        deletestackpush(root);
        free(root);
        return temp;
		}*/

        strcpy(root -> name,temp -> name);
		strcpy(root -> number,temp ->  number);
		strcpy(root -> address,temp ->  address);
		strcpy(root -> email,temp ->  email);
		
        root->right = deleteNodeinside(root->right, temp->name,temp ->  number);
		deletestackpush(root);
//}
/*	else{
		temp = root -> mid;
        deletestackpush(root);
        free(root);
        return temp;		
		
	}*/
    }
    return root;
}


struct node* deleteNodecenter(struct node* root, char key[],char number[]){
	
	struct node* temp;
	char mob_num[15];
	if (root== NULL){
		return root;
	}
    
	if(strcmp(root -> name,key) == 0){
		if(root -> mid != NULL){
			if(strcmp(root -> number,key) != 0){
				
				root->mid = deleteNodecenter(root->mid, key,number);
			}

		}	
	}

	temp = root -> mid;
	while(temp -> mid!=NULL){
		temp = temp->mid;
	}
	cout<<"Name::::::::"<<temp ->  number<<endl;
	strcpy(root -> name,temp -> name);
	strcpy(root -> number,temp ->  number);
	strcpy(root -> address,temp ->  address);
	strcpy(root -> email,temp ->  email);
	root -> mid = deleteNodecenter(temp->mid, temp -> name,temp ->  number);
	//free(root);
	return root;
}




struct node* findmin(struct node* tree)
{
    struct node* node1 = tree;
    if(tree -> mid ==NULL){
	while (node1 != NULL && node1->left != NULL)
        node1 = node1->left;
    return node1;
    	
	}
	else if(tree -> mid !=NULL){
		while (node1 != NULL && node1->mid ->mid!= NULL)
        node1 = node1->mid;
    return node1;
	}

}

void insertstackpush(struct node* temp){
	struct node* newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	
	strcpy(newnode -> name,temp -> name);
	strcpy(newnode -> number,temp ->  number);
	strcpy(newnode -> address,temp ->  address);
	strcpy(newnode -> email,temp ->  email);
	newnode->left = insertstack;
	insertstack = newnode;
	
}

void display() {
   struct node* ptr;
   if(insertstack==NULL)
   cout<<"stack is empty";
   else {
      ptr = insertstack;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->name <<" ";
         ptr = ptr->left;
      }
   }
}

void deletestackpush(struct node* temp){
	struct node* newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	
	strcpy(newnode -> name,temp -> name);
	strcpy(newnode -> number,temp ->  number);
	strcpy(newnode -> address,temp ->  address);
	strcpy(newnode -> email,temp ->  email);
	
	newnode->left = deletestack;
	deletestack = newnode;
	
}


void gosave(){
	fstream ob;
	char fn[] = "C:/Users/Admin/Documents/PhoneBook/Directory_A.txt", c[40];
	int i = 0,hash,j;
	//int coun = count(insertstack);
	//for(i=0;i<coun;i++){
	Sleep(2000);
	while(insertstack !=NULL){
		//hash = int(insertstack -> name[0]) % 65;
		fn[45] = insertstack -> name[0];
		ob.open(fn,ios::app);
		ob<<"\n"<<insertstack -> name<<"\n"<<insertstack -> number<<"\n"<<insertstack -> address<<"\n"<<insertstack -> email;	
		ob.close();
		insertstack = pop(insertstack);
	//	void display();
	}
	//coun =  count(deletestack);
	//for(j=0;j<coun;j++){
	while(deletestack != NULL){
		//cout<< fn[45]<<endl;
		hash = int(deletestack -> name[0]) % 65;
		fn[45] = deletestack -> name[0];
		ob.open(fn,ios::out);
		savein(head[hash],fn);
		ob.close();
		deletestack = pop(deletestack);
	}
}


struct node* pop(struct node*stack) {
	struct node* temp;
	if(stack != NULL){
	
      temp = stack;
      //temp = top;
      stack = stack->left;
	  free(temp);
	  return stack;
}
}




void savein(struct node *head,char fn[]){	
	ofstream ob;
	//char fn[] = "C:/Users/Admin/Documents/PhoneBook/Directory_A.txt";
	//fn[45] = i;	

		
	//	ob.close();
	if(head != NULL){
			//ofstream ob(fn);
		//ob.open(fn,ios::trunc);
		//ob.close();
		ob.open(fn,ios::app);
		ob<<"\n"<<head -> name<<"\n"<<head -> number<<"\n"<<head -> address<<"\n"<<head -> email;
		ob.close();
		savein(head -> left,fn);
		savein(head -> right,fn);
	}
}

struct node* searchin(struct node* root,char name[])

{
if(root==NULL)
{
cout<<"\nElement not in list";
return root;
}

else if(strcmp(root->name,name)==0)
{
	return root;

}

else if(strcmp(root->name,name)<0)
{
root->right = searchin(root->right,name);
return root->right;

}

else if(strcmp(root->name,name)>0)
{
root->left = searchin(root->left,name);

return root->left;
}

}



void modify(struct node* ptr)
{
char a;int hash1,hash,k=0;
struct node*ptr1 =  (struct node*)malloc(sizeof(struct node));
cout<<"\nWhich entity has to be modified??\nN - NAME\nA - ADDRESS\nP - PHONE NUMBER\nE - MAIL_ID\n";
cin>>a;

switch(a)
{
case ('N'):

char name[30];
//cout<<"\nEnter name of subscriber: ";
cin.getline(name,30);

 while(strlen(name)==0)
{  
   cout<<"\nEnter name of subscriber: ";
cin.getline(name,30);
}
while(name[k] != '\0'){
name[k] = toupper(name[k]);
k++;
}
hash1 = int(name[0]) % 65;
hash = int(ptr -> name[0]) % 65;
strcpy(ptr1->name,name);
strcpy(ptr1->address,ptr->address);
strcpy(ptr1->number,ptr->number);
strcpy(ptr1->email,ptr->email);

head[hash1] = insertinside(head[hash1], ptr1);
print();
head[hash] = deleteNodeinside(head[hash],ptr -> name,ptr -> number);
print();

cout<<"\n\nNAME:::::"<<ptr1 -> name<<endl;
deletestackpush(ptr1);
deletestackpush(ptr);
break;


case ('A'):
char address[40];
//cout<<"\nEnter address of subscriber: ";
cin.getline(address,40);

 while(strlen(address)==0)
{  
   cout<<"\nEnter address of subscriber: ";
cin.getline(address,40);
}
strcpy(ptr->address,address);
deletestackpush(ptr);
break;

case ('P'):
   char no[20];
    //cout<<"\nEnter phone number of subscriber: ";
cin.getline(no,20);

 while(strlen(no)!=10)
{  
   cout<<"\nEnter phone number of subscriber: ";
cin.getline(no,20);
}

strcpy(ptr->number,no);
deletestackpush(ptr);
break;

case ('E'):
char mail[40];
//cout<<"\nEnter E-mail ID of subscriber: ";
cin.getline(mail,40);

 while(strlen(mail)==0)
{  
   cout<<"\nEnter E-mail ID of subscriber: ";
cin.getline(mail,40);
}

strcpy(ptr->email, mail);
deletestackpush(ptr);
break;

default:
cout<<"\nUnrecognized character entered!\nKindly re-enter character from list";

}
    }
