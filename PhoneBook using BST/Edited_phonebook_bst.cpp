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
struct node *input(struct node *);
void inorder(int i);
void inorderinside(struct node *);
struct node *insert(struct node *);
struct node *insertinside(struct node *,struct node *);
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
for(int i=0;i<=26;i++)
    {
    	head[i] = (struct node*)malloc(sizeof(struct node));
		 head[i]=NULL;
         
     }
int option;
printf("\n**********************************************************************************************PHONEBOOK************************************************************************************************************");
printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
load();
do{
	cout<<"\nMENU\n 1)INSERT\n2)PRINT\n3)SEARCH(*for representation)\n4)EXIT\n5)ENTER YOU CHOICE\n";
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
		break;
		
		default:
		cout<<"ENTER VALID CHOICE\n";
	
	}
	
}while(option!=4);

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
	return head;
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
		
		strcpy(name, c);
		ob.getline(c, 40);
		strcpy(number, c);
		ob.getline(c, 40);
		strcpy(address, c);
		ob.getline(c, 40);
		strcpy(email, c);
		if(c[0] != NULL ){	
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
