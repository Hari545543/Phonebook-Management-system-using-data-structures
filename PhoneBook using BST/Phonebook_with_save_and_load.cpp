#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>


using namespace std;



struct node
{
char name[30];
char number[15];
char address[40];
char email[40];
struct node *left, *right;
};

void load();
//void display();

void print();
void save();
void savetofile(char i,int hash);
void savein(struct node *head,char i);
struct node *input(struct node *);
struct node* deleteNode(struct node*root[], char key[]);
struct node* deleteNodeinside(struct node*, char key[]);
struct node *findmin(struct node *tree);
void inorder(int i);
void inorderinside(struct node *);
struct node *insert(struct node *head[],struct node *new_node);
struct node *insertinside(struct node *,struct node *);
struct node *findmin(struct node *tree);
struct node *head[26];


struct node *insert(struct node *head[],struct node *new_node){
struct node *ptr;
int hash;
char ans;

	new_node -> name[0] = toupper(new_node -> name[0]);
	hash = int(new_node -> name[0]) % 65;
   
   


if(head[hash] == NULL){
new_node -> left = NULL;
new_node -> right = NULL;
head[hash] = new_node;
}
	else{
		if(strcmp(head[hash] -> name,new_node -> name) > 0){
			head[hash] -> left = insertinside(head[hash] -> left, new_node);
		}
		else{
			head[hash] -> right = insertinside(head[hash] -> right, new_node);
		}
	}
//return tree;
//return head[hash];
}



int main(){
struct node *n_node;
char ans;
int hash;
for(int i=0;i<=26;i++)
    {
    	head[i] = (struct node*)malloc(sizeof(struct node));
		 head[i]=NULL;
         
     }
int option;
char key[40];
printf("\n**********************************************************************************************PHONEBOOK************************************************************************************************************");
printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
load();
do{
	cout<<"\nMENU\n 1)INSERT\n2)PRINT\n3)SEARCH(*for representation)\n4)DELETE A CONTACT\n5)EXIT\nENTER YOU CHOICE\n";
	cin>>option;
	
	switch(option)
	{
		case 1:
			do{
				n_node = input(n_node);
				insert(head,n_node);
				cout<<"\nCONTINUE ? (y/n)\t";
				cin>>ans;
			}while(ans == 'y');
		break;
			
		case 2:
		//cout<<" PRINT\n";
		print();
		break;
		
		case 3:
		//cout<<" SEARCH(*for representation)\n";
		load();
		break;
		
		case 4:
		cout<<"ENTER THE NAME\n";
		cin>>key;
		key[0] = toupper(key[0]);
		hash = int (key[0]) % 65;
		deleteNodeinside(head[hash],key);
		break;
		
		default:
		cout<<"ENTER VALID CHOICE\n";
	
	}
	
}while(option!=5);
save();
return 0;
}



struct node *insertinside(struct node *head,struct node *new_node )
{
	if(head == NULL)
	{
		new_node -> left = NULL;
		new_node -> right = NULL;
		head = new_node;
	}
	else
	{
		

	
		if(strcmp(head -> name, new_node -> name) > 0)
		{
			head -> left = insertinside(head -> left, new_node);
		}
		else
		{
			head -> right = insertinside(head -> right, new_node);
		}
	}
	
}



void print()
{	
	//cout<<"printing ";
	for(int i =0;i<=26;i++){
		if(head[i] == NULL){ continue;}
		if(head[i] != NULL){
			inorder(i);
		}
	}
}
	


void inorder(int i)
{

	inorderinside(head[i] -> left);
	cout<<"\n\nNAME :  "<< head[i] -> name;
	cout<<"\nNUMBER :  "<< head[i] -> number;
	cout<<"\nADDRESS :  "<< head[i] -> address;
	cout<<"\nE-MAIL :  "<< head[i] -> email;
	inorderinside(head[i] -> right);
	
}



void inorderinside(struct node *head)
{
	
	if(head != NULL){
		
		inorderinside(head -> left);
		
		cout<<"\n\nNAME :  "<< head -> name;
		cout<<"\nNUMBER :  "<< head -> number;
		cout<<"\nADDRESS :  "<< head -> address;
		cout<<"\nE-MAIL :  "<< head -> email;		
		
		inorderinside(head -> right);
	}


	 
}

void load(){
struct node *new__node;
	char name[30];
	char number[15];
	char address[40];
	char email[40];
	char c[40];
	cout<<"\n\n\n\t\tPlease wait for a moment\n";
	cout<<"\t\tRetrieving data form file\n\n";
	char fn[] = "C:/Users/Admin/Documents/PhoneBook/Directory_A.txt";
	for(char i = 'A'; i <= 'Z' ; ++i){
		fn[45] = i;
		
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
			insert(head,new__node);	
		}
	}
	ob.close();
	
}
}

struct node *input(struct node *ne_node){
	
	char name[30];
	char number[15];
	char address[40];
	char email[40];
	
	cout<<"\nENTER NAME  :  ";  
	cin.getline(name,30);
	
	
	while((strlen(name)==0)){
																						
		cout<<"\nENTER VALID NAME  : ";
		cin.getline(name, 30);
			
			
	} 
		
	
	cout<<"\nENTER NUMBER :  ";
	   cin.getline(number,15);
	   
		while(strlen(number)!=10){
	   		cout<<"\nENTER NUMBER  :  ";
			cin.getline(number,15);
	   }
	   
			
	cout<<number<<endl;	
	  cout<<"\nENTER ADDRESS :  ";
	   cin.getline(address,40); 
	   
	cout<<number<<endl;
	   cout<<"\nENTER E-MAIL :  ";
	   cin.getline(email,40);
	   

	ne_node = (struct node*)malloc(sizeof(struct node));
	strcpy(ne_node -> name, name);
	strcpy(ne_node -> number, number);
	strcpy(ne_node -> address, address);
	strcpy(ne_node -> email, email);
	
	return ne_node;
  }
  
void save()
{	char j;
	//cout<<"printing ";
	for(j = 'A'; j <= 'Z' ; ++j){
		int hash = int(j) % 65;
		if(head[hash] == NULL){ continue;}
		if(head[hash] != NULL){
			savetofile(j,hash);
		}
	}
}

  
void savetofile(char i,int hash){
	ofstream ob;
	char fn[] = "C:/Users/Admin/Documents/PhoneBook/Directory_A.txt";
	fn[45] = i;
	cout<<"\n\n\n\t\tPlease wait for a moment\n";
	cout<<"\t\tSaving data to file\n\n";
	ob.open(fn,ios::trunc);
	ob.close();
	
	ob.open(fn,ios::out |ios::app);
	ob<<"\n"<<head[hash] -> name<<"\n"<<head[hash] -> number<<"\n"<<head[hash] -> address<<"\n"<<head[hash] -> email;
	ob.close();	
	savein(head[hash] -> left,i);
	savein(head[hash] -> right,i);
 
}

void savein(struct node *head,char i){	
	ofstream ob;
	char fn[] = "C:/Users/Admin/Documents/PhoneBook/Directory_A.txt";
	fn[45] = i;
	if(head != NULL){
		
		
		ob.open(fn,ios::out | ios::app);
		ob<<"\n"<<head -> name<<"\n"<<head -> number<<"\n"<<head -> address<<"\n"<<head -> email;
		ob.close();
		savein(head -> left,i);
		savein(head -> right,i);
	}
}
 /* 
struct node* deleteNode(struct node* root[], char key[])
{
    int hash = int (key[0]) % 65;
	if (root[hash] == NULL)
        return root[hash];
 

    if (strcmp(root[hash] -> name,key) > 0)
        root[hash]->left = deleteNodeinside(root[hash]->left, key);
 

    else if (strcmp(root[hash] -> name,key) < 0)
        root[hash]->right = deleteNodeinside(root[hash]->right, key);
 

    else {
    	
        if (root[hash]->left == NULL) {
            struct node* temp = root[hash]->right;
            free(root[hash]);
            return temp;
        }
        else if (root[hash]->right == NULL) {
            struct node* temp = root[hash]->left;
            free(root[hash]);
            return temp;
        }
 

        struct node* temp = findmin(root[hash]->right);
 

        root[hash]= temp;
 

        root[hash]->right = deleteNodeinside(root[hash]->right, temp->name);
    }
    return root[hash];
}*/

struct node* deleteNodeinside(struct node* root, char key[])
{
	struct node* temp;
	if (root== NULL)
        return root;
 

    if (strcmp(root -> name,key) > 0){
    	 root->left = deleteNodeinside(root->left, key);
	}
       
 

    else if (strcmp(root -> name,key) < 0){
    	 root->right = deleteNodeinside(root->right, key);
	}
       
 

    else {
    	
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
 

        temp = findmin(root->right);
 

        strcpy(root -> name,temp -> name);
		strcpy(root -> number,temp ->  number);
		strcpy(root -> address,temp ->  address);
		strcpy(root -> email,temp ->  email);

        root->right = deleteNodeinside(root->right, temp->name);
    }
    return root;
}

struct node* findmin(struct node* tree)
{
    struct node* node1 = tree;
 
    while (node1 != NULL && node1->left != NULL)
        node1 = node1->left;
 
    return node1;
}
