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



void print();
void inorder(int i);
void inorderinside(struct node *);
struct node *insert(struct node *);
struct node *insertinside(struct node *,struct node *);
struct node *head[26];


struct node *insert(struct node *head[]){
struct node *new_node, *ptr;
int hash;

char name[30];
char number[15];
char address[40];
char email[40];
char ans;

do{
cout<<"\nENTER NAME  :  ";  
cin.getline(name,30);


while((strlen(name)==0)){																					//
	
		cout<<"\nENTER VALID NAME  :  ";
		cin.getline(name,30);
		
		
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
   
 
   
   name[0] = toupper(name[0]);
   hash = int(name[0]) % 65;
   cout<< hash<<"\n";
   
   
new_node = (struct node*)malloc(sizeof(struct node));
strcpy(new_node -> name, name);
strcpy(new_node -> number, number);
strcpy(new_node -> address, address);
strcpy(new_node -> email, email);

if(head[hash] == NULL){
new_node -> left = NULL;
new_node -> right = NULL;
head[hash] = new_node;
}
else{
if(strcmp(head[hash] -> name,name) > 0){
head[hash] -> left = insertinside(head[hash] -> left, new_node);
}
else{
head[hash] -> right = insertinside(head[hash] -> right, new_node);
}
}
//return tree;

cout<<"\nCONTINUE ? (y/n)\t";
cin>>ans;
}while(ans == 'y');
cout<<"\nINSERTION COMPLETED\n";

//return head[hash];
}



int main(){

for(int i=0;i<=26;i++)
    {
    	head[i] = (struct node*)malloc(sizeof(struct node));
		 head[i]=NULL;
         
     }
int option;
printf("\n**********************************************************************************************PHONEBOOK************************************************************************************************************");
printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
do{
	cout<<"\nMENU\n 1)INSERT\n2)PRINT\n3)SEARCH(*for representation)\n4)EXIT\n5)ENTER YOU CHOICE\n";
	cin>>option;
	
	switch(option)
	{
		case 1:
		//printf(" INSERT \n");
		insert(head);
		break;
		
		case 2:
		//cout<<" PRINT\n";
		print();
		break;
		
		case 3:
		//cout<<" SEARCH(*for representation)\n";
		//search();
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
	cout<<"printing ";
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



