#include <iostream>
#include <vector>

using namespace std;

class Vector
{
    int n;      ///numarul de elemente
    int *v;

public:
    Vector(int nr, int sz); ///constructor pt initializarea cu un nr dat pe toate componentele

    Vector();

    Vector(int sz);

    Vector (const Vector&);

    Vector operator=(Vector);

    void set_size(int sz){ n = sz;}

    void set_element (int nr, int i) { v[i] = nr; }

    void set_vector (int nr)
    {
        for (int i = 0; i < n; i++)
            v[i] = nr;
    }

    int get_size () { return n;}

    int get_element (int i) { return v[i];}

    void suma();

    void maxim_poz();

    void sortare();

    void reactualizare(int nr, int sz);

    void afisare();

    friend istream& operator>> (istream& in, Vector& ob);

    friend ostream& operator<< (ostream& out, Vector& ob);

    ~Vector();
};

Vector::Vector(int nr, int sz) ///constructor pt initializarea cu un nr dat pe toate componentele
{
    v = new int[sz];
    n = sz;


    for (int i = 0; i < sz; i++)
        v[i]=nr;
}

Vector::Vector()
{
    n = 0;
    v = new int [n];

}

Vector::Vector(int sz)
{
    v = new int[sz];
    n = sz;
    for (int i = 0; i < sz; i++)
        cin>>v[i];

}

Vector::Vector (const Vector& vec)
{
    n = vec.n;

    v = new int[n];

    for(int i=0; i<n; i++)
        v[i]=vec.v[i];

}

Vector::~Vector()
{
    delete[] v;

}

Vector Vector::operator=(Vector ob)
{
    if(this != &ob)
    {
        this->n = ob.n;

        this->v = new int[this->n];

        for(int i = 0; i < this->n; i++)
            this->v[i] = ob.v[i];
    }

    return *this;
}

void Vector::suma()
{
    int i, s=0;

    for(i = 0; i < n; i++)
        s += v[i];

    cout<<s<<endl;
}

void Vector::maxim_poz()
{
    int maxi=v[0], i, poz=0;

    for(i = 1; i < n; i++)
    {
        if(maxi < v[i])
        {
            maxi=v[i];
            poz=i;
        }
    }
    cout<<"Maximul este "<< maxi<< " si se afla pe pozitia "<< poz<<"\n";
}

void Vector::sortare()
{
    int i, j, aux;

    for(i = 0; i < n-1; i++)
        for(j = i+1; j< n; j++)
            if(v[i] > v[j])
    {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
    }
}

void Vector::reactualizare(int nr, int sz)
{
    v = new int[sz];
    n = sz;

    for(int i = 0; i < sz; i++)
        v[i] = nr;

}

void Vector::afisare ()
{
    cout<<"numarul de elemente= "<<n<<"\n";

    for (int i = 0; i < n; i++)
        cout<< v[i]<< " ";
}

istream& operator>> (istream& in, Vector& ob)
{
    cout<<"Dimensiunea vectorului= ";
    in >> ob.n;

    for (int i = 0; i < ob.n; i++)
        {
            cout<<"elementul aflat pe pozitia "<<i<< " a vectorului= ";
            in>>ob.v[i];
        }

    return in;

}

ostream& operator<< (ostream& out, Vector& ob)
{
    cout<<"Dimensiunea vectorului= ";
    out<<ob.n<<endl;
    cout<<"elementele din vector: ";
    for(int i=0; i < ob.n; i++)
    {
        out<<ob.v[i]<<" ";
    }

    cout<<endl;

    return out;
}

int main()
{
    vector <Vector> vectori;

    int run = 1;

    while (run)
    {
        int option;
        cout<<"introduceti optiunea: \n 1 = adaugati un Vector cu un numar de elemente dat de la tastatura si fiecare element dat de la tastatura \n 2 = adaugati un vector cu un numar de elemente specificat si un numar dat pe toate pozitiile \n 3 = reactualizarea numarului de componente al unui Vector existent si initializarea componentelor cu un numar dat \n 4 = calculul si afisarea sumei unui vector existent \n 5 = afisarea maximului si pozitiei acestuia dintr-un vector existent \n 6 = sortarea crescatoare a unui Vector existent \n 7 = afisarea unui vector existent \n";
        cin>>option;

        switch (option)
        {
            case 1:
                {
                    Vector a;
                    cin>>a;
                    vectori.push_back(a);
                    break;
                }

            case 2:
                {
                    cout<<"Introduceti numarul de elemente: ";
                    int sizze;
                    cin>>sizze;
                    cout<<endl<<"introduceti numarul care se va afla pe toate pozitiile: ";
                    int nrr;
                    cin>>nrr;
                    cout<<endl;
                    Vector b(nrr, sizze);
                    vectori.push_back(b);
                    break;
                }

            case 3:
                {
                    cout<<"Introduceti indexul vectorului pe care doriti sa-l reactualizati: ";
                    int idx;
                    cin>>idx;
                    cout<<endl<<"Introduceti numarul nou de elemente: ";
                    int sznou;
                    cin>>sznou;
                    cout<<endl<<"introduceti numarul nou ce se va afla pe toate pozitiile vectorului: ";
                    int nrnou;
                    cin>>nrnou;
                    vectori[idx].reactualizare(nrnou, sznou);
                    break;
                }

            case 4:
                {
                    cout<<endl<<"introduceti indexul vectorului caruia doriti sa-i calculati suma: ";
                    int idxx;
                    cin>>idxx;
                    vectori[idxx].suma();
                    break;
                }

            case 5:
                {
                    cout<<endl<<"introduceti indexul vectorului caruia doriti sa-i aflati maximul: ";
                    int idxxx;
                    cin>>idxxx;
                    vectori[idxxx].maxim_poz();
                    break;
                }

            case 6:
                {
                    cout<<endl<<"introduceti indexul vectorului pe care doriti sa-l sortati crescator: ";
                    int id;
                    cin>>id;
                    vectori[id].sortare();
                    break;
                }
            case 7:
                {
                    cout<<endl<<"introduceti indexul vectorului pe care doriti sa-l afisati: ";
                    int idd;
                    cin>>idd;
                    vectori[idd].afisare();
                    break;
                }

            default:
                cout<<"Optiune invalida!"<<endl;
        }

        cout << "Continuati? 1/0: ";
        cin >> run;
        cout <<endl<< "*********************" << endl;
    }


    cout<<endl<<endl<<"FINAL!";



    return 0;
}
