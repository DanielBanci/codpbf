#include <iostream>
#include <cstring>
using namespace std;
struct Nod
{
    char valoare;
    struct Nod *st, *dr, *prec;
};
Nod *prim=NULL,*p=NULL;
// prim retine primul nod din lista
// p retine pozitia curenta
int k=0,k1=1,a=1;
void inserareNod(Nod* &prim, char caracter,Nod *&p)
{
    //Creeam noul nod
    Nod *nodnou = new Nod;
    nodnou->st = NULL;
    nodnou->dr = NULL;
    nodnou->prec = NULL;
    nodnou->valoare = NULL;
    if (prim == NULL) // In cazul in care lista noastra este vida, punem elementul in lista
        {prim = nodnou;
        cout<<"Pune primul nod"<<endl;
        p = prim;
        }
        else //pun nodul in lista
            if ( p->st == NULL )
            {
                nodnou->prec = p;
                p->st = nodnou;
                p = nodnou;
                cout<<"Pune nod in stanga"<<endl;
            }
            else
                if ( p->dr == NULL && strchr("^vid",p->valoare) )
                {
                    nodnou->prec = p;
                    p->dr = nodnou;
                    p = nodnou;
                    cout<<"Pune nod in dreapta"<<endl;
                }
                else
                   a = 0;
//Daca valoarea nu e litera mare,negatie sau paranteza nodul trebuie sters
    if (!(strchr("QWERTYUIOPLKJHGFDSAZXCVBNM(",caracter)))
            {
                if( nodnou->prec != NULL )
                    if ( p->prec->dr != NULL )
                    {
                        Nod *nodscos = p;
                        p = p->prec;
                        p->dr = NULL;
                        delete nodscos;
                        cout<<"Sterge nodul din dreapta"<<endl;
                    }
                    else
                    {
                        Nod *nodscos=p;
                        p = p->prec;
                        p->st = NULL;
                        delete nodscos;
                        cout<<"Sterge nodul din stanga"<<endl;
                    }
                    else
                        {delete nodnou;
                        a = 1;
                        }
            }
        if ( strchr("(",caracter))//valoarea nodului devine c (astept un operator)
            {p->valoare='c'; cout<<"Pune valoarea c"<<endl;}
        else
            if ( (caracter == '^' || caracter == 'd' || caracter == 'i' || caracter=='v') && p->valoare == 'c')//pun operatorul
                {
                    p->valoare = caracter;
                    cout<<"Pune operatorul"<<endl;
                }
            else
                if ( strchr(")",caracter) )//urc o pozitie
                        { cout<<"Urca o pozitie"<<endl;
                            if ( p->prec != NULL)
                                p = p->prec;
                            else
                            k++;//daca iese cu 1 -> arborele este complet
                        }
                else
                    if ( strchr("n",caracter) && p->valoare == 'c' && p->st == NULL ) //pun negatia
                        {p->valoare = caracter; cout<<"Pune negatia"<<endl;}
                        else
                            if ( p != prim )
                            {
                                if ( strchr("QWERTYUIOPLKJHGFDSAZXCVBNM",caracter) && strchr("^vidnc",p->prec->valoare) )//pun propozitia
                                    {
                                    p->valoare = caracter;
                                    p = p->prec;
                                    cout<<"Pune litera si urca o pozitie"<<endl;
                                    }
                                else
                                {
                                    a = 0;cout<<"NU E CE ASTEPT EU!"<<endl;
                                }
                            }
                            else
                                {
                                    a = 0;cout<<"NU E CE ASTEPT EU!"<<endl;
                                }
}
void afisarei(Nod *nod_curent)
{
    if ( nod_curent )
    {   afisarei(nod_curent->st);
        cout<<nod_curent->valoare<<" ";
        if ( !(strchr("^divnQWERTYUIOPLKJHGFDSAZXCVBNM",nod_curent->valoare))) k1=0;
        afisarei(nod_curent->dr);
    }
}
int main()
{
    int ok=1;
    char s[50];
    cout<<"ATENTIE"<<endl;
    cout<<"Pentru ca programul sa functioneze corect tine-ti cont de urmatoarele notatii:"<<endl;
    cout<<"^ -> pentru conjunctie"<<endl<<"v -> pentru disjunctie"<<endl<<"i -> pentru incluziune"<<endl<<"d -> pentru dubla incluziune"<<endl<<"n -> pentru negatie"<<endl;
    cout<<"Introduceti propozitia:";
    cin.getline(s,50);
    if (strlen(s)>1)
        {for(int i=0;i<strlen(s);i++)
            {cout<<"citeste: "<<s[i]<<endl;
                if ( s[i] == ' ')//sar peste spatii
                    continue;
                if ( strchr("QWERTYUIOPLKJHGFDSAZXCVBNM^vid()n",s[i]) && a == 1 )
                    inserareNod(prim,s[i],p);
                else
                {
                    ok=0;
                    break;
                }
            }
        }
    else
        if (strchr("QWERTYUIOPLKJHGFDSAZXCVBNM",s[0]))
            k = 1;
    if ( ok == 1 && k == 1)
        afisarei(prim);
    cout<<"ok="<<ok<<endl<<"k1="<<k1<<endl<<"k="<<k<<endl;
    if ( ok == 1 && k1 ==1 && k == 1 )
        cout<<"Propozitia este bine formata";
    else
        cout<<"Propozitia nu este bine formata";

    return 0;
}
