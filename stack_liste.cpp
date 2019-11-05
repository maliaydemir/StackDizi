#include <iostream>
using namespace std;
  //youtube labirent çözüm için stack model araþtýr
//soru  hanoi kuleleri 2üzeri n -1 hamledir
//soru stringi tersten yazma
//tekbaðlý listeyi stack ile kullan (basaekle ve bastanoku/bastan sil)

struct node
{
	int data;
	node *next;
};


pair<node*,node*> pop(node *r){
		node *yrd =r;
	if (r==NULL)
	{
		cout<<"stack boþ";
		
	}
	else
	{
		r=yrd->next;
		yrd->next=NULL;

	}
			return make_pair(r,yrd);
}
node *push(node *r,int x){
	node *yrd=new node;
	yrd->data=x;
	yrd->next=r;
	r=yrd;
	return r;
	
}
void yazdir(node *r){
	while (r!=NULL)
	{
		cout<<r->data<<" ";
		r=r->next;
	}
}

void main(){

	node *root1=NULL;
	node *root2=NULL;
	for (int i = 0; i < 16; i++)
	{
		root1=push(root1,i+1);
	}
	yazdir(root1);
	
	system("pause");

	for (int i = 0; i < 3; i++)
	{
		pair <node*,node*> d=pop(root1);
		root1=d.first;
		root2=push(root2,d.second->data);

	}
	

	yazdir(root1);
	system("pause");
	
	yazdir(root2);
	system("pause");
}