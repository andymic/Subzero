#include <iostream>
#include "linked_list.h"
#include <string>
using namespace std;

int Node::id_gen=1;
//void header()
//{
//	cout<<"ID"<<"\t"
//		<<"Nickname"<<" "
//		<<"Name"<<"\t"
//		<<"Email"<<"\t"
//		<<"Account Name"<<"\t"
//		<<"Password"<<endl;
//}
void Node::SetNode(string nckname, string name, string email, string acc_name,string password)
{
	this->nckname=nckname;
	this->name=name;
	this->email=email;
	this->acc_name=acc_name;
	this->password=password;
}

void Linked_list::Add(string nckname, string name, string email, string acc_name,string password)
{
	Node * node= new Node();
	Node * temp=head;
	node->SetNode(nckname,name,email,acc_name,password);
	node->next=NULL;

	if(temp==NULL)
	{
		head=node;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=node;
	}
	

}
void Linked_list::Print()
{
	Node * temp=head;
	if(temp==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->id<<"\t"
				<<temp->nckname<<"\t"
				<<temp->name<<"\t"
				<<temp->email<<"\t"
				<<temp->acc_name<<"\t"
				<<temp->password<<endl;

			temp=temp->next;
		}
	}
}