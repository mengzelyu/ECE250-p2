#include <iostream>
#include "chain.h"
#include <string>

hash::hash(long long size){
	hashtable = new Node*[size];
}

hash::~hash(){
	Node *temp1;
	Node *temp2;
	for (int i=0; i<size; ++i){
		temp2=hashtable[i];
		while (temp2!=NULL){
			temp1=temp2;
			temp2=temp2->next;
			delete temp1;
		}
	}
	delete[] hashtable;
	size=0;	
}

long long hash::hashfunc(long long key){
    long long index;
    index = key % size;
    return index;
}

void hash::insert(long long key, std::string caller){
	long long index=hashfunc(key);
	Node *temp=new Node;
	Node *temp1=new Node;
	Node *temp2=new Node;
	temp2= hashtable[index];
	while (temp2 != NULL && temp2->pnum < key){
		temp1=temp2;
		temp2=temp2->next;
	}
	temp1->next=temp;
	temp->pnum=key;
	temp->next=temp2;
	temp->caller=caller;
}

long long hash::search(long long key){
	long long index=hashfunc(key);
	Node *temp=new Node;
	temp=hashtable[index];
	while (temp!= NULL && temp->pnum<=key){
		if (temp->pnum=key){
			return index;
		}
		temp=temp->next;
	}
	throw "not found";
}

void hash::delete_key(long long key){
	long long index;
	try {
		index=search(key);
	}
	catch (std::string message){
		throw "failure";
	}
	Node *temp1=new Node;
	Node *temp2=new Node;
	temp2=hashtable[index];
	while (temp2!= NULL && temp2->pnum<=key){
		if (temp2->pnum=key){
			temp1->next=temp2->next;
			delete temp2;
			break;
		}
		temp1=temp2;
		temp2=temp2->next;
	}
}

void hash::print(long long index){
	Node *temp=new Node;
	temp=hashtable[index];
	while (temp != NULL){
		std::cout << temp->pnum;
		if (temp->next != NULL){
			std::cout << " ";
		}
		temp=temp->next;
	}
}
