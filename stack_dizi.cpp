#include <iostream>
using namespace std;
//youtube labirent ��z�m i�in stack model ara�t�r
//soru  hanoi kuleleri 2�zeri n -1 hamledir
//soru stringi tersten yazma

int boyut = 4;
int top = -1;
int top2 = -1;
int *dizi = new int[boyut];
int *dizi2 = new int[4];//diziden pop edilen verileri haf�zada tutar (ctrl+z) //boyutunu k�s�tl� tuttum

						//ctrl z ve y gibi ileri geri gidebilecek pop edilenleri 2. stacke atama yap
void pop() {
	//top de�i�keninin -1 olma durumuna bak ekle
	//hesapla(dizi[top]);
	if (top == -1)
	{
		//dizi bo� demektir pop edilecek veri de yoktur
		return;
	}
	if (top2 == 3)
	{
		//dizi2 limiti doldu alttan silerek yeni geleni �ste ekle
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
		//stack haf�za k���lt�lmeli
		int *d = new int[boyut / 2];
		//pop ve pushta kopyalama ayn� farkl� fonks hallet
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
		//haf�za doludur
		//cout<<"Stack dolu"<<endl;
		int *d = new int[boyut * 2];
		for (int i = 0; i <= top; i++)
		{
			d[i] = dizi[i];
		}//yeni dizimize kopyalad�k
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