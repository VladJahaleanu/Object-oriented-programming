#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Card_standard;
class Card_premium;

class Card
{
protected:
    string nr_card;
    string nume_detinator;
    string data_expirare;
    int cvv;
    double credit;

    static int nr_carduri;

public:
    Card();
    Card(string nr, string nume, string exp, int cod, double crd);
    Card(const Card& ob);
    virtual void afisare();
    Card& operator= (Card& ob);
    friend istream& operator>> (istream&, Card&);
    friend ostream& operator<< (ostream&, Card&);
    static void afisare_nr_carduri(){cout<<"Numarul total de carduri este: "<<nr_carduri<<endl;}
    void extragere_std();
    void extragere_premium();

    ~Card(){/*cout<<"\ndestr Card";*/}
};

int Card::nr_carduri;

class Card_standard: public Card
{
protected:
    int limita_extragere;
    double comision_depasire_limita;

    static int nr_carduri_standard;

public:

    Card_standard();
    Card_standard(string nr, string nume, string exp, int cod, double crd, int limita, double comision): Card(nr, nume, exp, cod, crd){ limita_extragere = limita; comision_depasire_limita = comision; nr_carduri_standard++;}
    Card_standard& operator= (Card_standard& ob);
    friend istream& operator>> (istream&, Card_standard&);
    friend ostream& operator<< (ostream&, Card_standard&);
    void extragere_std();
    void extragere_premium();
    static void afisare_nr_carduri_std(){cout<<"Numarul de carduri standard este: "<<nr_carduri_standard<<endl;}
    void afisare();
    ~Card_standard(){/*cout<<"\ndestr std_card";*/}
};

int Card_standard::nr_carduri_standard;

class Card_premium: public Card_standard
{
    double cashback;

    static int nr_carduri_premium;

public:
    Card_premium();
    Card_premium(string nr, string nume, string exp, int cod, double crd, int limita, double comision, double cash): Card_standard(nr, nume, exp, cod, crd, limita, comision){ cashback = cash; nr_carduri_premium++;}
    friend istream& operator>> (istream&, Card_premium&);
    friend ostream& operator<< (ostream&, Card_premium&);
    Card_premium& operator= (Card_premium& ob);
    void extragere_premium();
    void afisare();
    static void afisare_nr_carduri_prem(){cout<<"Numarul de carduri premium este: "<<nr_carduri_premium<<endl;}
    ~Card_premium(){/*cout<<"\ndestr prem_card";*/}


};

int Card_premium::nr_carduri_premium;

Card::Card()
{
    nr_card = "necunoscut";
    nume_detinator = "necunoscut";
    data_expirare = "necunoscut";
    cvv = 000;
    credit = 0.0;

    nr_carduri++;
}

Card::Card(string nr, string nume, string exp, int cod, double crd)
{
    nr_card = nr;
    nume_detinator = nume;
    data_expirare = exp;
    cvv = cod;
    credit = crd;

    nr_carduri++;
}

Card::Card(const Card& ob)
{
    nr_card = ob.nr_card;
    nume_detinator = ob.nume_detinator;
    data_expirare = ob.data_expirare;
    cvv = ob.cvv;
    credit = ob.credit;

    nr_carduri++;
}

Card& Card::operator= (Card& ob)
{
    if(this != &ob)
    {
        nr_card = ob.nr_card;
        nume_detinator = ob.nume_detinator;
        data_expirare = ob.data_expirare;
        cvv = ob.cvv;
        credit = ob.credit;
    }
    return *this;
}

istream& operator>> (istream& in, Card& ob)
{
    in.get();
    cout<<"Introduceti numarul cardului: "; getline(in, ob.nr_card);
    cout<<"Introduceti numele detinatorului cardului: "; getline(in, ob.nume_detinator);
    cout<<"Introduceti data expirarii cardului: "; getline(in, ob.data_expirare);
    cout<<"Introduceti CVV-ul cardului: "; in>>ob.cvv;
    cout<<"Introduceti creditul aflat pe card: "; in>>ob.credit;
    return in;
}

ostream& operator<< (ostream& out, Card& ob)
{
    cout<<"Numarul cardului: "; out<<ob.nr_card; cout<<endl;
    cout<<"Numele detinatorului cardului: "; out<<ob.nume_detinator; cout<<endl;
    cout<<"Data expirarii cardului: "; out<<ob.data_expirare; cout<<endl;
    cout<<"CVV-ul cardului: "; out<<ob.cvv; cout<<endl;
    cout<<"Creditul aflat pe card: "; out<<ob.credit; cout<<endl;

    return out;

}

Card_standard::Card_standard()
{
    limita_extragere = 0;
    comision_depasire_limita = 0;

    nr_carduri_standard++;
}

Card_standard& Card_standard::operator= (Card_standard& ob)
{
    if(this != &ob)
    {
        Card::operator=(ob);
        limita_extragere = ob.limita_extragere;
        comision_depasire_limita = ob.comision_depasire_limita;
    }

    return *this;
}


istream& operator>> (istream& in, Card_standard& ob)
{

    in>>(Card&)ob;
    cout<<"Introduceti limita de extragere: "; in>>ob.limita_extragere;
    cout<<"Introduceti comisionul de depasire a limitei de extragere: "; in>>ob.comision_depasire_limita;

    return in;
}

ostream& operator<< (ostream& out, Card_standard& ob)
{
    out<<(Card&)ob;
    cout<<"Limita de extragere a cardului este: "; out<<ob.limita_extragere; cout<<endl;
    cout<<"Comisionul de depasire a limitei de extragere: "; out<<ob.comision_depasire_limita; cout<<"%"<<endl;

    return out;
}

Card_premium::Card_premium()
{
    cashback = 0;

    nr_carduri_premium++;
}

ostream& operator<< (ostream& out, Card_premium& ob)
{
    out<<(Card_standard&)ob;
    cout<<"Cashback: "; out<<ob.cashback;cout<<"%"<<endl;

    return out;
}

istream& operator>> (istream& in, Card_premium& ob)
{
    cout<<"Atentie! acesta este un card premium, deci limita de extragere si comisionul pentru depasirea acesteia se vor incarca cu 0!"<<endl<<endl;
    in>>(Card_standard&)ob;
    cout<<"Cashback: "; in>>ob.cashback;

    return in;
}

Card_premium& Card_premium::operator= (Card_premium& ob)
{
    if(this != &ob)
    {
        Card_standard::operator=(ob);
        cashback=ob.cashback;
    }
    return *this;
}

void Card_premium::afisare()
{
    Card_standard::afisare();
    cout<<"Cashback: "<<cashback<<endl<<endl;
}

void Card_standard::afisare()
{
    Card::afisare();
    cout<<"Limita de extragere este: "<<limita_extragere<<endl<<"Comisionul de depasire a limitei este: "<<comision_depasire_limita<<endl<<endl;
}

void Card::afisare()
{
    cout<<"Numar card: "<<nr_card<<endl<<"Nume detinator: "<<nume_detinator<<endl<<"Data expirarii: "<<data_expirare<<endl<<"CVV: "<<cvv<<endl<<"Credit: "<<credit<<endl<<endl;
}

void Card_standard::extragere_std()
{
    cout<<"Creditul disponibil este: "<<credit<<", iar limita de extragere este: "<<limita_extragere<<" de lei. Introduceti suma pe care doriti s-o retrageti: ";
    try
    {
        double retragere;
        cin>>retragere;
        double com = (comision_depasire_limita/100) * retragere;
        if(retragere > credit)
        {
            throw (retragere);
        }
        else
        {
            if (retragere <= limita_extragere)
            {
                credit -= retragere;
                cout<<"Ati retras cu succes suma de "<<retragere<<" de lei!"<<endl;
            }
            else
            {
                credit = credit - retragere - com;
                cout<<"Vi s-a aplicat comisionul pentru depasirea limiteri de extragere si ati retras cu succes suma de "<<retragere<<" de lei!"<<endl;
            }
        }
    }
    catch (double r)
    {
        cout<<"Eroare! Doriti sa retrageti o suma mai mare decat creditul disponibil pe card!"<<endl<<endl;
    }

}

void Card_premium::extragere_premium()
{
    cout<<"Creditul disponibil este: "<<credit<<", fara restrictii privind suma de extragere. Introduceti suma pe care doriti s-o retrageti: ";

    try
    {
        double retragere;
        cin>>retragere;
        if(retragere > credit)
        {
            throw (retragere);
        }
        else
        {
            credit -= retragere;
            credit += (cashback/100)*retragere;
            cout<<"Ati retras cu succes suma de "<<retragere<<" de lei si datorita cashback-ului v-au fost restituiti "<<(cashback/100)*retragere<<" de lei"<<endl;
        }
    }
    catch (double r)
    {
        cout<<"Eroare! Doriti sa retrageti o suma mai mare decat creditul disponibil pe card!"<<endl<<endl;
    }
}

int main()
{
    Card_standard c1;
    const type_info& ti1 = typeid(c1);      ///pt a-l putea folosi mai departe, la extrageri.

    Card **v; ///vectorul de obiecte

    int n;
    cout<<"Introduceti numarul de carduri pe care doriti sa le memorati: "; cin>>n;
    cout<<endl;

    v=new Card*[n];

    for(int i = 0; i < n; i++)
    {
        int optiune;
        cout<<"Alegeti tipul de card(1= card standard sau 2= card premium) pe care doriti sa-l memorati pe pozitia "<<i<<": ";cin>>optiune;
        cout<<endl;
        if(optiune == 1)
        {
            v[i] = new Card_standard;
            cin>>*dynamic_cast<Card_standard*>(v[i]);/// downcasting
        }
        else
            if(optiune == 2)
        {
            v[i] = new Card_premium;
            cin>>*dynamic_cast<Card_premium*>(v[i]);/// downcasting
        }
        else
        {
            cout<<"Alegeti o optiune valida!"<<endl;
            i--;
        }
    }

    cout<<endl;

    int run = 1;

    while(run)
    {
        int opt;
        cout<<"Alegeti optiunea: \n 1= Retragere bani de pe un card. \n 2= Afisarea datelor unui card existent.\n";
        cin>>opt;
        cout<<endl;

            if (opt == 1)
                {
                    int nrc;
                    cout<<"Alegeti numarul cardului de pe care doriti sa retrageti bani: ";
                    cin>>nrc;
                    const type_info& ti = typeid(*v[nrc]);
                    if(ti == ti1)
                        {
                            Card_standard cs;
                            cs = *(Card_standard*)v[nrc];
                            cs.extragere_std();
                            *(Card_standard*)v[nrc] = cs;
                            //*(Card_standard*)v[nrc]->extragere_std();
                        }
                    else
                        {
                            Card_premium cp;
                            cp = *(Card_premium*)v[nrc];
                            cp.extragere_premium();
                            *(Card_premium*)v[nrc] = cp;
                        }
                    }
            else
                if(opt == 2)
                {
                    int nrc1;
                    cout<<"Alegeti numarul cardului caruia doriti sa-i afisati datele: ";
                    cin>>nrc1;
                    cout<<*v[nrc1];
                    cout<<endl;
                }
            else
                {
                    cout<<"Adaugati o optiune valida!"<<endl;
                }



        cout<<"Continuati? 1/0: ";
        cin>>run;
        cout<<endl<<"*********************"<<endl;
    }


    cout<<endl<<"FINAL"<<endl;




    return 0;
}
