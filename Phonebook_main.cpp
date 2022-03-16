#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>

using namespace std;

void print();
void search();

struct node{
char name[30];
char number[15];
char address[40];
char email[40];
struct node *next, *prev;
};

struct node *insert(struct node *);
//struct node *head = NULL;

// Inializing a position in array of pointers for each of 26 alphabets

struct node *head[26];

struct node *insert(struct node *head[]){
struct node *new_node, *ptr;
int hash;
fstream ob;

char name[30];
char number[15];
char address[40];
char email[40];
char ans;

do{
  
cout<<"\nENTER NAME  :  ";  
cin.getline(name,30);


while((strlen(name)==0)){																					//
	
		cout<<"\nENTER NAME  :  ";
		cin.getline(name,30);
		
}  
	

cout<<"\nENTER NUMBER :  ";
   cin.getline(number,15);
   
   while(strlen(number)!=10)
{
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
   //cout<< hash<<"\n";
   
   
new_node = (struct node*)malloc(sizeof(struct node));
  
// Copy it to the new node
  
strcpy(new_node -> name, name);
strcpy(new_node -> number, number);
strcpy(new_node -> address, address);
strcpy(new_node -> email, email);


cout<<new_node -> number<<endl;

if(head[hash]== NULL){
new_node -> next = NULL;
new_node -> prev = NULL;
head[hash] = new_node;
}

else{
ptr = head[hash];
while(ptr -> next != NULL){ptr = ptr -> next;}
ptr -> next = new_node;
ptr -> next -> prev = ptr;
ptr -> next -> next = NULL;
}
ob.open("Phonebook.txt",ios::app);
ob<<name<<"\n"<<number<<"\n"<<address<<"\n"<<email<<"\n";
ob.close();
cout<<"\nCONTINUE ? (y/n)\t";
cin>>ans;
}while(ans == 'y');
cout<<"\nINSERTION COMPLETED\n";

//return head[hash];
}

int main(){
//struct node *head = NULL;
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
printf(" INSERT \n");
insert(head);
cout<< head[0] -> number;
//if(head[1] != NULL){ cout<< head[1]-> add;}
//cout<<head[1]-> address;
break;

case 2:
cout<<" PRINT\n";
print();
break;

case 3:
cout<<" SEARCH(*for representation)\n";
search();
break;

case 4:
break;

default:
cout<<"ENTER VALID CHOICE\n";

}
}while(option!=4);

return 0;
}

void print()
{
	cout<<"printing ";
	struct node *ptr;
	for(int i =0;i<=26;i++){
		if(head[i] == NULL){ continue;}
		ptr = head[i];
		while(ptr != NULL){
			cout<<i<<"\n";
			cout<<"\n\nNAME :  "<< ptr -> name;
			cout<<"\nNUMBER :  "<< ptr -> number;
			cout<<"\nADDRESS :  "<< ptr -> address;
			cout<<"\nE-MAIL :  "<< ptr -> email;
		ptr = ptr -> next;
		}
	}
/*fstream ob;
char s[30];
ob.open("Phonebook.txt",ios::in);
while(!ob.eof())
{
ob.getline(s,50);;
cout<<s<<"\n";
}
ob.close();*/
}

void search()
{
char in[30];
char ph[10];

cout<<"Enter Name\n";
cin.getline(in,30);

cout<<"Enter Name\n";
cin.getline(in,30);

cout<<"Enter phone number\n";
cin.getline(ph,10);

ifstream ob;
string s;
string s1;
string ad;
string em;
int ct=0;

ob.open("Phonebook.txt",ios::in);

while(!ob.eof())
{
	getline(ob,s);
	getline(ob,s1);
	getline(ob,ad);
	getline(ob,em);
           
	if((in==s)&&(s1==ph))
	{
		cout<<"SUBSCRIBER DETAILS\n";
		cout<<"Name: "<<in;
		cout<<"\nPhone number: "<<ph;
		cout<<"\nAddress: "<<ad;
		cout<<"\nEmail-ID: "<<em;
		ct++;
		break;
	}

}

if(ct==0)
{
cout<<"\nRecord not found!\n";
}

else{
	cout<<"\nSEARCH COMPLETED\n";
}
ob.close();
}
