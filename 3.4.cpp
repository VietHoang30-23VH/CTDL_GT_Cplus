#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};
void Nhap(DATHUC &B, double x, int y)
{
    DONTHUC *d=new DONTHUC(x, y);
    Node*p= new Node(d);
    if(B.head==nullptr) B.head=p;
    else B.tail->next=p;
    B.tail=p;
}

void Nhap(DATHUC &dathuc,double heso, int somu)
{
    DONTHUC *donthuc=new DONTHUC (heso,somu);
    Node *p=new Node(donthuc);
    if (dathuc.head==nullptr) dathuc.head= p;
    else dathuc.tail->next=p;
    dathuc.tail=p;
    
}
double TinhDaThuc(DATHUC B,double x)
{
    double result=0;
    Node *p=B.head;
    while (p!=nullptr)
    {
        result+= (p->data->heso) * pow (x, p->data->somu);
        p=p->next;
    }
    return result;
}
void XuatDonThuc(DONTHUC *donthuc) {
    if (donthuc == nullptr) return;
    double h = donthuc->heso;
    int n = donthuc->somu;
    if (h == 0) return; 
    if (n == 0) {
        cout << h; 
        return;
    }
    if (h > 0) 
    {
        if (n == 1) cout << h << "x"; 
        else cout << h << "x^" << n; 
    } 
    else 
    {
        if (n == 1) cout << "-x"; 
        else cout << "-x^" << n; 

        h = -h; 
    }

    
    if (h != 1 && h != -1) cout << h;
}


void Xuat(DATHUC &dathuc) {
    Node *p = dathuc.head;

    if (p == nullptr) {
        cout << "0";
        return;
    }

    XuatDonThuc(p->data);
    p = p->next;

    while (p != nullptr) {
        if (p->data->heso > 0) cout << " + ";
        else cout << " - ";
        XuatDonThuc(p->data);

        p = p->next;
    }
}


int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}