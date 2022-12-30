#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

struct Phantu
{
	int giatri;
	int color;
	Phantu* next;
	Phantu(int giatri)
	{
		this->giatri=giatri;
		next =NULL;
	};
	Phantu()
	{
	};
};

struct Tap
{
	int n; //số phần tử 
	Phantu* phantu[100];	
};

int k = 2;
int n[4];
Tap O;
Tap E;
Tap Econ[3];

void Them(Tap& A, Phantu* x, int pos)
{
	// Dich chuyen mang de tao o trong truoc khi them.
	for (int i = A.n + 1; i > pos; i--) {
		A.phantu[i] = A.phantu[i - 1];
	}
	// Chen val tai pos
	A.phantu[pos] = x;
	// Tang so luong phan tu sau khi chen.
	++A.n;
}

void Xoa(Tap& A, Phantu* x) {
	int pos;
	int dem = 0;
	for (int i = 1; i <= A.n; i++)
	{
		if (x->giatri == A.phantu[i]->giatri)
		{
			pos = i;
			dem++;
		}
	}
	if (dem == 0)
		return;
	// Dich chuyen mang
	for (int i = pos; i < A.n; i++) {
		A.phantu[i] = A.phantu[i + 1];
	}
	// Giam so luong phan tu sau khi xoa.
	--A.n;
}

Phantu* succ(Phantu* x)
{
	return x->next;
}

bool independent(Tap A, Phantu* x, Phantu* y)
{
	Them(A, x, A.n);
	Xoa(A, y);
	return true ;
}

void repaint(Phantu*& x, Phantu*& y)
{
	bool test = true;
	while (test==true)
	{
		y = succ(x);
		int j = x->color;
		
		Xoa(Econ[j], x);
		cout<<"...";		
		j = y->color;
		Them(Econ[j], x, Econ[j].n);
		x->color = j;
		x = y;
		int dem = 0;	     
		for (int i = 1; i <= E.n; i++)
		{	
			if (E.phantu[i]->giatri == x->giatri)
				dem++;
		}
		if (dem == 0)
		{
			test = false;
		}
			
	}
	
}

void augment(int t)
{
	for (int i = 1; i <= 7; i++)
	{
		E.phantu[i]->next = NULL;
	}
	Tap A = E;
	Tap B;
	if (t > 0)
	{
		B.phantu[1] = O.phantu[t];
		B.n = 1;
	}
	else B = O;

	while (B.n != 0)
	{
		Tap C;
		C.n = 0;
		for (int i = 1; i <= B.n; i++)
		{
			for (int l = 1; l <= A.n; l++)
			{
				int j = B.phantu[i]->color;
				Phantu* y = B.phantu[i];
				Phantu* x = A.phantu[l];
				if (independent(Econ[j], x, y) == true)
				{				
					x->next = y;
					Xoa(A, x);
					Them(C, x, C.n);
					if (x->color == 0)
					{
						
						repaint(x,y);
					}					
				}
			}
		}
		B=C;
	} 
}


int main()
{

	//Taọ tập E0=E;
	E.n=7;
	Econ[0] = E;
	n[1] = 7;
	n[2] = 6;
	//Gán giá trị và tô màu 0 cho các phần tử của E 
	for (int i = 1; i <= 7; i++)
	{
		E.phantu[i] = new Phantu(i);
		E.phantu[i]->color = 0;
	}
	
	for (int i = 1; i <= 7; i++)
	{
		cout<< E.phantu[i]->giatri<<" "<<E.phantu[i]->color<<endl ;
	}
	//Gán các tập con của E =null
	for (int j = 1; j <= k; j++)
	{
		Econ[j].n = 0;
	}

	//tô màu cho các phần tử O
	for (int j = 1; j <= k; j++)
	{
		O.phantu[j]=new Phantu();
		O.phantu[j]->color = j;	
		O.phantu[j]->giatri=j+8;
	}


	for (int j = 1; j <= k; j++)
	{
		for (int i = 1; i <= n[j]; i++)
		{
			augment(j);
		}
	}

	while (Econ[0].phantu != NULL)
	{
		augment(0);
	}

	for (int j = 1; j <= k; j++)
	{
		cout << "(";
		for (int i = 1; i <= Econ[j].n; i++)
		{
			cout << Econ->phantu[i]->giatri << " ,";
		}
		cout << ")";
		cout << "mau cua tap con la mau :" << j;
	}

}










































