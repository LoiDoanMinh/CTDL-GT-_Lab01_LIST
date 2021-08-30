#include <iostream>
using namespace std;
struct node
{
	int data;
	node* pnext;
};
typedef struct node NODE;
struct list
{
	NODE* phead;
	NODE* ptail;
};
typedef struct list LIST;
void KhoiTaoList(LIST& l);
NODE* KhoiTaoNode(int x);
void ThemVaoDau(LIST& l, NODE* p);
void ThemVaoCuoi(LIST& l, NODE* p);
void NhapDSLKVaoDau(LIST& l);
void NhapDSLKVaoCuoi(LIST& l);
void Xuat(LIST l);
void menu(LIST& l);
void XuatNguoc(LIST l, NODE* p);
int DemSoNODE(LIST l);
bool TimKiemNODE(LIST l, int x);
int XoaNODEdau(LIST& l);
int XoaNODEcuoi(LIST& l);
int XoaNODESauNODEq(LIST& l,NODE* q);
int XoaNODEX(LIST& l,int x);
int ThemNODEvaoViTriN(LIST& l,int x, int n);

int main()
{
	LIST l;
	KhoiTaoList(l);
	menu(l);
	system("pause");
	
}
void KhoiTaoList(LIST& l)
{
	l.phead = l.ptail = NULL;
}
NODE* KhoiTaoNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\n Cap Phat Khong Thanh Cong";
		return NULL;
	}
	else
	{
		p->data = x;
		p->pnext = NULL;
	}
	return p;
}
void ThemVaoDau(LIST& l, NODE* p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}
void ThemVaoCuoi(LIST& l, NODE* p)
{
	if (l.phead==NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}
void NhapDSLKVaoDau(LIST& l)
{
	int n;
	cout << "\n Nhap so luong phan tu : ";
	cin >> n;
	KhoiTaoList(l);
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "\n Nhap gia tri : ";
		cin >> x;
		NODE* p = KhoiTaoNode(x);
		if (p != NULL)
		{
			ThemVaoDau(l, p);
		}
	}
}
void NhapDSLKVaoCuoi(LIST& l)
{
	int n;
	cout << "\n Nhap so luong phan tu : ";
	cin >> n;
	KhoiTaoList(l);
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "\n Nhap gia tri : ";
		cin >> x;
		NODE* p = KhoiTaoNode(x);
		if (p != NULL)
		{
			ThemVaoCuoi(l, p);
		}
	}
}
void Xuat(LIST l)
{
	cout<< endl;
	for (NODE*p=l.phead; p != NULL; p = p->pnext)
	{
		cout << p->data << " ";
	}
}
void menu(LIST& l)
{
	int luachon;
	system("cls");
	while (1)
	{
		cout << "\t\t\t==========MENU==========";
		cout << "\n\t 1.Nhap DSLK(them vao dau) Va xuat danh sach";
		cout << "\n\t 2.Nhap DSLK(them vao cuoi) Va xuat danh sach";
		cout << "\n\t 3.Xuat Nguoc Danh Sach";
		cout << "\n\t 4.Dem So node trong dslk";
		cout << "\n\t 5.Tim kiem Node co truong bang X";
		cout << "\n\t 6.Xoa Node dau trong DSLK ";
		cout << "\n\t 7.Xoa Node Cuoi trong DSLK ";
		cout << "\n\t 8.Xoa Node co khoa bang X ";
		cout << "\n\t 9.Them Node co khoa X vao vi tri n ";
		cout << "\n\t 0.Thoat chuong trinh";
		cout << "\n\t\t\t==========END==========";
		cout << "\n nhap lua chon : ";
		cin >> luachon;
		if (luachon < 0 || luachon>9)
		{
			cout << "\n lua chon ko hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapDSLKVaoDau(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 2)
		{
			NhapDSLKVaoCuoi(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			if (l.phead == NULL)
			{
				cout << "DSLK rong : ";
			}
			else
			{
				NODE* p = l.phead;
				cout << " DSLK nguoc : ";
				XuatNguoc(l, p);
				system("pause");
			}
		}
		else if (luachon == 4)
		{
			int kq = DemSoNODE(l);
			cout << "\n So Node trong danh sach lien ket : " << kq;
			cout << endl;
			system("pause");
		}
		else if (luachon == 5)
		{
			int x;
			cout << "\n Nhap khoa X can tim: x = ";
			cin >> x;
			if (TimKiemNODE(l, x))
				cout << "\n Ton Tai NODE co khoa la X !";
			else
				cout << "\n Khong Ton Tai NODE co khoa la X !";
			system("pause");
		}
		else if (luachon == 6)
		{
			if (XoaNODEdau(l) == 1)
				cout << " Xoa Node Thanh Cong!";
			else
				cout << " danh sach rong !";
			Xuat(l);
			system("pause");
		}
		else if (luachon == 7)
		{
			if (XoaNODEcuoi(l) == 1)
				cout << "\n xoa node thanh cong !";
			else
				cout << "\n danh sach rong !";
			Xuat(l);
			system("pause");
		}
		else if (luachon == 8)
		{
			int x;
			cout << "\n Nhap vao khoa X can xoa : x = ";
			cin >> x;
			if (XoaNODEX(l, x) == 0)
			{
				cout << "\n Khong ton tai khoa x !";
			}
			else
			{
				cout << "\n Xoa node thanh cong ! \n";
				Xuat(l);
			}
			system("pause");
		}
		else if (luachon == 9)
		{
			int x;
			cout << "\n Nhap gia tri khoa x can them : x = ";
			cin >> x;
			int n;
			cout << "\n Nhap vi tri can them : n = ";
			cin >> n;
			ThemNODEvaoViTriN(l,x,n);
			Xuat(l);
			system("pause");
		}
		else
			break;
	}
}
void XuatNguoc(LIST l, NODE* p)
{
	if (p == NULL)
	{
		return;
	}
	else
	{
		XuatNguoc(l, p->pnext);
		cout << p->data << " ";
	}
}
int DemSoNODE(LIST l)
{
	int count = 0;
	NODE* p = l.phead;

	for (l.phead; p != NULL; p = p->pnext)
	{
		count++;
	}
	return count;
}
bool TimKiemNODE(LIST l, int x)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->data == x)
			return true;
	}
	return false;
}
int XoaNODEdau(LIST& l)
{
	NODE* p;
	if (l.phead != NULL)
	{
		p = l.phead;
		l.phead = l.phead->pnext;
		delete(p);
		if (l.phead == NULL)
		{
			l.ptail = NULL;
		}
		return 1;
	}
	return 0;
}
int XoaNODEcuoi(LIST& l)
{
	if (l.phead == NULL)
		return 0;
	else
	{
		for (NODE* k = l.phead; k != NULL; k = k->pnext)
		{
			if (k->pnext == l.ptail)
			{
				NODE* p = l.ptail;
				l.ptail = p;
				delete(p);
				k->pnext = NULL;
                return 1;
			}
        }
	}
}
int XoaNODESauNODEq(LIST& l, NODE* q)
{
	NODE* p;
	if (q != NULL)
	{
		p = q->pnext;
		if (p != NULL)
		{
			if (p == l.ptail)
			{
				l.ptail = q;
			}
			q->pnext = p->pnext;
			delete(p);
		}
		return 1;
	}
	else 
		return 0;
}
int XoaNODEX(LIST& l,int x)
{
	NODE* p = l.phead;
	NODE* q = NULL;
	for (p; (p != NULL)&&(p->data!=x); p = p->pnext)
	{
		q = p;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
		XoaNODESauNODEq(l, q);
	else
		XoaNODEdau(l);
	return 1;
}
int ThemNODEvaoViTriN(LIST& l,int x, int n)
{
	NODE* k = KhoiTaoNode(x);
	if (n == 0 || l.phead == NULL)
	{
		ThemVaoDau(l,k);
		return 1;
	}
	else
	{
		int count = 1;
		NODE* p = l.phead;
		for (p; p != NULL && count != n; p = p->pnext)
		{
			count++;
		}
		if (count != n)
		{
			cout << "\n vi tri khong hop le !";
			return 0;
		}
		else
		{
			k->pnext = p->pnext;
			p->pnext = k;
		}
	}
}
