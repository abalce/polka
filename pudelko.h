#ifndef PUDELO
#define PUDELO

#include<iostream>
#include<vector>

using namespace std;

class Pudelko
{
private:
    bool puste;
public:
    Pudelko(bool puste) : puste(puste) {}
    virtual ~Pudelko()=default;
    virtual void print() const =0;
    virtual char gettyp()=0;
    bool czypuste() const {return puste;}
};

class A : public Pudelko
{
public:
    A(bool puste) : Pudelko(puste) {}
    ~A()
    {
        cout<<"\nUsuwam A: ";
        if(czypuste()==true)
        {
            cout<<"puste";
        }
        else
        {
            cout<<"niepuste";
        }
        cout<<endl;
    }
    void print() const override
    {
        cout<<"A(";
        if(czypuste()==true)
        {
            cout<<"puste";
        }
        else
        {
            cout<<"niepuste";
        }
        cout<<")";

    }

    char gettyp() {return 'A';}
};

class B : public Pudelko
{
private:
    string kolor;
public:
    B(bool puste, string kolor) : Pudelko(puste), kolor(kolor) {}
    ~B()
    {
        cout<<"\nUsuwam B: ";
        if(czypuste()==true)
        {
            cout<<"puste";
        }
        else
        {
            cout<<"niepuste";
        }
        cout<<endl;
    }

    void print() const override
    {
        cout<<"B(";
        if(czypuste()==true)
        {
            cout<<"puste";
        }
        else
        {
            cout<<"niepuste";
        }
        cout<<")";

    }

    char gettyp() {return 'B';}
    string getkolor() {return kolor;}
};

class C : public Pudelko
{
public:
    C(bool puste) : Pudelko(puste) {}
    ~C()
    {
        cout<<"\nUsuwam C: ";
        if(czypuste()==true)
        {
            cout<<"puste";
        }
        else
        {
            cout<<"niepuste";
        }
        cout<<endl;
    }
    void print() const override
    {
        cout<<"C(";
        if(czypuste()==true)
        {
            cout<<"puste";
        }
        else
        {
            cout<<"niepuste";
        }
        cout<<")";

    }

    char gettyp() {return 'C';}
};


///polka

class Polka
{
private:
    vector<Pudelko*>poleczka;
public:
    Polka()=default;
    ~Polka()
    {
        poleczka.clear();
        cout<<"\nusunieta polka"<<endl;
    }
    void postaw(Pudelko* p)
    {
        poleczka.push_back(p);
    }

    friend ostream& operator<<(ostream& os, const Polka& p)
    {
        for(const auto* p : p.poleczka)
        {
            p->print();
            os<<" -> ";
        }
        os<<"//Koniec polki//";
        return os;
    }

    void operator-=(char typ)
    {
        int i=0;
        while(i<poleczka.size()){
            if(poleczka[i]->gettyp()==typ)
            {
                poleczka.erase(poleczka.begin()+i);
            }
            else
            {
                i++;
            }
        }
    }

    Polka(const Polka& other)
    {
        for(auto* p : other.poleczka)
        {
            switch(p->gettyp())
            {
            case 'A':
               poleczka.push_back(new A(p->czypuste()));
               break;
            case 'B':
                poleczka.push_back(new B(p->czypuste(),dynamic_cast<B*>(p)->getkolor()));
                break;
            case 'C':
                poleczka.push_back(new C(p->czypuste()));
                break;
            }
        }
    }
};

#endif // PUDELO
