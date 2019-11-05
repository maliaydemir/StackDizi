#include <iostream>
using namespace std;
//youtube labirent çözüm için stack model araþtýr
//soru  hanoi kuleleri 2üzeri n -1 hamledir
//soru stringi tersten yazma

int boyut = 4;
int top = -1;
int top2 = -1;
int *dizi = new int[boyut];
int *dizi2 = new int[4];//diziden pop edilen verileri hafýzada tutar (ctrl+z) //boyutunu kýsýtlý tuttum

						//ctrl z ve y gibi ileri geri gidebilecek pop edilenleri 2. stacke atama yap
void pop() {
	//top deðiþkeninin -1 olma durumuna bak ekle
	//hesapla(dizi[top]);
	if (top == -1)
	{
		//dizi boþ demektir pop edilecek veri de yoktur
		return;
	}
	if (top2 == 3)
	{
		//dizi2 limiti doldu alttan silerek yeni geleni üste ekle
		for (int i = 0; i < 4; i++)
		{
			dizi2[i] = dizi2[i + 1];
		}
		dizi2[top2] = dizi[top];
	}
	else
	{
		dizi2[++top2] = dizi[top];
	}

	top--;
	if (top == boyut / 2 - 1)
	{
		//stack hafýza küçültülmeli
		int *d = new int[boyut / 2];
		//pop ve pushta kopyalama ayný farklý fonks hallet
		for (int i = 0; i < boyut / 2; i++)
		{
			d[i] = dizi[i];
		}
		dizi = d;
		d = NULL;
		boyut = boyut / 2;
	}

}
void push(int x) {
	if (top == boyut - 1)
	{
		//hafýza doludur
		//cout<<"Stack dolu"<<endl;
		int *d = new int[boyut * 2];
		for (int i = 0; i <= top; i++)
		{
			d[i] = dizi[i];
		}//yeni dizimize kopyaladýk
		dizi = d;
		d = NULL;
		boyut = boyut * 2;
	}
	dizi[++top] = x;


}
void yazdir() {
	for (int i = top; i > -1; i--)
	{
		cout << dizi[i] << " ";
	}
	cout << endl;
}

void main() {

	for (int i = 0; i < 17; i++)
	{
		push(i + 1);
		cout << boyut << " ";
	}
	cout << endl;
	yazdir();
	cout << "-----------------" << endl;
	for (int i = 0; i < 9; i++)
	{
		pop();
	}
	yazdir();
	cout << boyut << endl;
	system("pause");
	for (int i = 0; i < 4; i++)
	{
		cout << dizi2[i] << " ";
	}
	system("pause");

}