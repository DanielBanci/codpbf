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
int k=0,a=1;
//a -> daca nu poate pune nod (verifica daca il sterge)
void inserareNodpasi(Nod* &prim, char caracter,Nod *&p)
{
    int cs=0,cd=0;
    Nod *nodnou = new Nod;
    nodnou->st = NULL;
    nodnou->dr = NULL;
    nodnou->prec = NULL;
    nodnou->valoare = NULL;
    if (prim == NULL)
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
                cs=1;
            }
            else
                if ( p->dr == NULL && strchr("^vid",p->valoare) )
                {
                    nodnou->prec = p;
                    p->dr = nodnou;
                    p = nodnou;
                    cd=1;
                }
                else
                   a = 0;//nu am unde pune nodul
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
                        cd=0;
                    }
                    else
                    {
                        Nod *nodscos=p;
                        p = p->prec;
                        p->st = NULL;
                        delete nodscos;
                        cs=0;
                    }
                    else
                        {delete nodnou;
                        a = 1;//am sters nodul
                        }
            }
        if(cs==1)
            cout<<"Pune nod in stanga"<<endl;
        if(cd==1)
            cout<<"Pune nod in dreapta"<<endl;
        if ( strchr("(",caracter) && a == 1)//valoarea nodului devine c (astept un operator)
            {p->valoare='c'; cout<<"Pune valoarea c (astept un operator)"<<endl;}
        else
            if ( (caracter == '^' || caracter == 'd' || caracter == 'i' || caracter=='v') && p->valoare == 'c')//pun operatorul
                {
                    p->valoare = caracter;
                    cout<<"Pune operatorul"<<endl;
                }
            else
                if ( strchr(")",caracter) && strchr("QWERTYUIOPLKJHGFDSAZXCVBNMndiv^",p->valoare))//urc o pozitie
                        {
                            if ( p->prec != NULL)
                                {
                                    p = p->prec;
                                    cout<<"Urca o pozitie"<<endl;
                                }
                            else
                            k++;//daca iese cu 1 -> arborele este complet
                        }
                else
                    if ( strchr("n",caracter) && p->valoare == 'c' && p->st == NULL ) //pun negatia
                        {
                            p->valoare = caracter;
                            cout<<"Pune negatia"<<endl;
                        }
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
                                    a = 0;
                                    cout<<"Nu e ce astept eu!"<<endl;
                                }
                        }
                        else
                            {
                                if ( strchr("QWERTYUIOPLKJHGFDSAZXCVBNM",caracter))
                                    {
                                        p->valoare = caracter;
                                        k=1;
                                        cout<<"Pun litera si urc o pozitie"<<endl;
                                    }
                                else
                                {
                                    a = 0;
                                    cout<<"Nu e ce astept eu!"<<endl;
                                }
                            }
    if (k == 1)
        cout<<"Am iesit din arbore"<<endl;
}
void inserareNod(Nod* &prim, char caracter,Nod *&p)
{
    Nod *nodnou = new Nod;
    nodnou->st = NULL;
    nodnou->dr = NULL;
    nodnou->prec = NULL;
    nodnou->valoare = NULL;
    if (prim == NULL)
        {prim = nodnou;
        p = prim;
        }
        else //pun nodul in lista
            if ( p->st == NULL )
            {
                nodnou->prec = p;
                p->st = nodnou;
                p = nodnou;
            }
            else
                if ( p->dr == NULL && strchr("^vid",p->valoare) )
                {
                    nodnou->prec = p;
                    p->dr = nodnou;
                    p = nodnou;
                }
                else
                   a = 0;//nu am unde pune nodul
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
                    }
                    else
                    {
                        Nod *nodscos=p;
                        p = p->prec;
                        p->st = NULL;
                        delete nodscos;
                    }
                    else
                        {delete nodnou;
                        a = 1;//am sters nodul
                        }
            }
        if ( strchr("(",caracter) && a == 1)//valoarea nodului devine c (astept un operator)
            p->valoare='c';
        else
            if ( (caracter == '^' || caracter == 'd' || caracter == 'i' || caracter=='v') && p->valoare == 'c')//pun operatorul
                    p->valoare = caracter;
            else
                if ( strchr(")",caracter) && strchr("QWERTYUIOPLKJHGFDSAZXCVBNMndiv^",p->valoare))//urc o pozitie
                    {
                        if ( p->prec != NULL)
                            p = p->prec;
                        else
                            k++;//daca iese cu 1 -> arborele este complet
                    }
                else
                    if ( strchr("n",caracter) && p->valoare == 'c' && p->st == NULL ) //pun negatia
                        p->valoare = caracter;
                    else
                        if ( p != prim )
                            {
                                if ( strchr("QWERTYUIOPLKJHGFDSAZXCVBNM",caracter) && strchr("^vidnc",p->prec->valoare) )//pun propozitia
                                    {
                                    p->valoare = caracter;
                                    p = p->prec;
                                    }
                                else
                                    a = 0;
                            }
                        else
                        {
                            if ( strchr("QWERTYUIOPLKJHGFDSAZXCVBNM",caracter))
                                    {
                                        p->valoare = caracter;
                                        k=1;
                                    }
                            else
                                    a = 0;
                        }
}
/*void afisarei(Nod *nod_curent)
{
    if ( nod_curent )
    {   afisarei(nod_curent->st);
        cout<<nod_curent->valoare<<" ";
        afisarei(nod_curent->dr);
    }
}*/
int main()
{
    int ok=1,x=-1;
    char s[50],rasp;
    cout<<"ATENTIE"<<endl;
    cout<<"Pentru ca programul sa functioneze corect tine-ti cont de urmatoarele notatii:"<<endl;
    cout<<"^ -> pentru conjunctie"<<endl<<"v -> pentru disjunctie"<<endl<<"i -> pentru incluziune"<<endl<<"d -> pentru dubla incluziune"<<endl<<"n -> pentru negatie"<<endl;
    cout<<"Introduceti propozitia:"<<endl;
    cin.getline(s,50);
    cout<<"Doriti sa vedeti pasii? (d/n):";
    cin>>rasp;
    for(int i=0;i<strlen(s);i++)
    {
        if ( s[i] == ' ')//sar peste spatii
            continue;
        if ( strchr("QWERTYUIOPLKJHGFDSAZXCVBNM^vid()n",s[i]) && a == 1 && k != 1 )
        {
            if ( rasp == 'd')
            {
                cout<<"citeste: "<<s[i]<<endl;
                inserareNodpasi(prim,s[i],p);
            }
            else
                inserareNod(prim,s[i],p);
        }
        else
        {
            if ( a == 1 && k != 1)//verific daca am un caracter necunoascut
                x=i;
            ok=0;
            break;
        }
    }
    if ( ok == 1 && k == 1 && a == 1)
            cout<<"Propozitia este bine formata";
    else
        {
            if( k == 1 && ok == 0)
                cout<<"Nu am terminat de citit sirul"<<endl;
            if ( x != -1)
                cout<<s[x]<<" ->caracter necunoscut";
            else
                cout<<"Propozitia nu este bine formata"<<endl;
        }
    /*if ( ok == 1 && k == 1)
        afisarei(prim);*/
    return 0;
}
