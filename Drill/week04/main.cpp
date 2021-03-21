#include "std_lib_facilities.h"

class B1{
public: 
	virtual void vf(){
		cout << "B1::vf" << endl;
	}
	void f(){
		cout << "B1::f" << endl;
	}
	virtual void pvf()=0;

};

class D1 : public B1{
public:
	void vf() override{
		cout << "D1::vf" << endl;
	}
	void f(){
		cout << "D1::f" << endl;
	}
	void pvf() override{
		cout << "D1::pvf" << endl;
	}
};

class D2 : public D1{
public:
	void pvf() override{
		cout << "D2::pvf" << endl;
	}
};

class B2{
public:
	virtual void pvf(){
		cout << "B2::pvf" << endl;
	}
};

class D21 : public B2{
	string str="D21 string\n";
public:
	void pvf() override{
		cout << str << endl; 
	}
};

class D22 : public B2{
	int n=15;
public:
	void pvf() override{
		cout << n << endl;
	}
};

void f(B2 &p){
	p.pvf();
};

int main(){
	D1 d1;
	d1.vf();
	d1.f();

	B1 &b1=d1;
	b1.vf();
	b1.f();

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	return 0;
}