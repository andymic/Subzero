#pragma once
#include <string>
using namespace std;

class Node
{
public:
	int id;
	static int id_gen;
	string nckname;
	string name;
	string email;
	string acc_name;
	string password;
	Node * next;
	Node(){id=id_gen++; };
	void SetNode(string nckname, string name, string email, string acc_name,string password);
	/* data */
};

class Linked_list
{
	Node *head;
public:
	Linked_list(){head=NULL;};
	void Print();
	void Add(string nckname, string name, string email, string acc_name,string password);
	Node* Search(int id);
	void Delete(int id);
	~Linked_list(){};
	/* data */
};