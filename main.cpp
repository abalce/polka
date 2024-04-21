#include"pudelko.h"
int main()
{

    Pudelko* p1=new A(true);
    Pudelko* p2=new A(false);
    Pudelko* p3=new B(false,"bialy");
    Pudelko* p4=new C(true);


    Polka p;

    p.postaw(p1);
    p.postaw(p2);
    p.postaw(p3);
    p.postaw(p4);

    cout<<p<<endl;

    p-=('A');

    cout<<p<<endl;

    Polka nowap=p;

    cout<<"Nowa polka:\n"<<nowap<<endl;

    delete p1;
    delete p2;
    delete p3;
    delete p4;


    return 0;
}
