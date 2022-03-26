#include <fstream>
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define VERDE 10
#define ALB 7
#define ROSU 12
int main()
{
    int al_patrulea=INT_MIN, al_treilea=INT_MIN, al_doilea=INT_MIN, masina2, masina3, masina4, n,v[101],a[101],maxx,ok;
    ifstream fin("cursa_masini.in");
    ofstream fout("cursa_masini.out");

    int raspuns;


    fin>>n;
    cout<<endl;

    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
        fin>>v[i];
    }
    cout<<endl;
    do
    {
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), VERDE);
        cout << "            MASINILE DE RALIU            \n";
        Sleep(1500);
        cout<<endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), VERDE);
        cout << "Bine ati venit la RaceCarOrganizer! Cu ajutorul algoritmului veti putea organiza raliuri. \n\n";
        Sleep(3000);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), ALB);
        cout << "1.Cea mai rapida masina din concurs.\n";
        Sleep(300);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), ALB);
        cout << "2.Cele mai rapide 3 masini.\n";
        Sleep(300);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), ALB);
        cout<<"3.Verifica daca masinile sunt plasate corect pe randuri (cele din randul din dreapta fiind pare).\n";
        Sleep(300);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), ALB);
        cout<<"4.Masinile in ordinea potrivita pentru raliu.\n";
        Sleep(300);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), ALB);
        cout<<"5.Masinile eliminate/accidentate din raliu.\n";
        Sleep(300);
        cout<<endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "0. EXIT.\n";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cin >> raspuns;

        system("CLS");
        switch(raspuns)
        {
        case 1:
        {
            Sleep(300);
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
            fout<<"Determinati cea mai rapida masina.\n"<<endl;




            maxx=0;
            int numar;
            for(int i=1; i<=n; i++)
            {
                if(v[i]>maxx)
                {
                    maxx=v[i];
                    numar=i;
                }
            }
            cout<<"Cea mai rapida masina este masina cu numarul "<<a[numar]<<" cu viteza de "<<maxx<<"km/h."<<endl;
            cout<<endl;


            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "\n Pentru a va reintoarce la meniu, apasati orice tasta.";
            getch();
            system("CLS");
            break;
        }
        case 2:
        {

            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
            fout<<"Determinati primele 3 cele mai rapide masini."<<endl;

            al_doilea=v[1];
            al_treilea=v[1];
            al_patrulea=v[1];
            masina2=a[1];
            masina3=a[1];
            masina4=a[1];
            for(int i=1; i<=n; i++)
            {
                if(v[i]>al_doilea)
                {
                    al_patrulea=al_treilea;
                    al_treilea=al_doilea;
                    al_doilea=v[i];
                    masina4=masina3;
                    masina3=masina2;
                    masina2=a[i];
                }
                else if(v[i]>al_treilea)
                {
                    al_patrulea=al_treilea;
                    al_treilea=v[i];
                    masina4=masina3;
                    masina3=a[i];
                }
                else if(v[i]> al_patrulea)
                {
                    al_patrulea=v[i];
                    masina4=a[i];
                }


            }
            cout<<"Primele cele mai rapide 3 masini sunt: masina "
                <<masina2<<" "<<"cu"<<" "<<al_doilea<<"km/h, "
                <<" masina "<<masina3<<" cu "<<al_treilea<<"km/h, si "
                <<"masina "<<masina4<<" cu "<<al_patrulea<<"km/h."<<endl;
            cout<<endl;
            Sleep(500);
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "\n Pentru a va reintoarce la meniu, apasati orice tasta.";
            getch();
            system("CLS");
            break;
        }
        case 3:
        {
            ok=1;
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 13);
            fout<<"Verificati daca masinile de pe pozitii impare au numar par de km/h"<<endl;
            int i=1;
            while(i<=n)
            {
                if(v[i]%2==1)
                    ok=0;
                i=i+2;
            }
            if(ok==0)
                cout<<"Nu toate masinile de pe pozitii impare au numar par de km/h";
            else
                cout<<"Toate masinile de pe pozitii impare au numar par de km/h";
            cout<<endl;
            Sleep(500);
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "\n Pentru a va reintoarce la meniu, apasati orice tasta.";
            getch();
            system("CLS");
            break;
        }
        case 4:
        {

            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
            fout<<"Organizati masinile in ordinea potrivita pentru raliu."<<endl;
            int aux;
            for(int i=1; i<=n-1; i++)
                for(int j=i+1; j<=n; j++)
                    if(v[i]>v[j])
                    {
                        aux=v[i];
                        v[i]=v[j];
                        v[j]=aux;
                        aux=a[i];
                        a[i]=a[j];
                        a[j]=aux;

                    }
            cout<<"Ordinea masinilor (de sus in jos) este: ";
            cout<<endl;

            for(int i=1; i<=n; i++ )
            {
                cout<<a[i]<<" "<<v[i];
                cout<<endl;
            }
            cout<<"In ordinea aceasta cursa va fi destul de echilibrata"<<endl;
            Sleep(500);
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "\n Pentru a va reintoarce la meniu, apasati orice tasta.";
            getch();
            system("CLS");
            break;
        }

        case 5:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout<<"Actuala lista de masini este "<<endl;
            for(int i=1; i<=n; i++)
            {
                cout<<a[i]<<" "<<v[i]<<"km/h"<<endl;
                fout<<a[i]<<" "<<v[i]<<"km/h"<<endl;
            }
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout<<"Eliminati masinile intre pozitiile p si q din raliu."<<endl;
            fout<<"Eliminati masinile intre pozitiile p si q din raliu."<<endl;
            int p,q,i,diff;
            cout<<"Introduceti p: ";
            cin>>p;
            cout<<"Introduceti q: ";
            cin>>q;
            diff=q-p-1;
            for(i=q;i<=n;i++)
            {
                a[i-diff]=a[i];
                v[i-diff]=v[i];
            }
            n=n-diff;
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout<<"Noua ordine a masinilor, dupa eliminare, este: "<<endl;
            for(int i=1; i<=n; i++)
            {
                cout<<a[i]<<" "<<v[i]<<"km/h"<<endl;
                fout<<a[i]<<" "<<v[i]<<"km/h"<<endl;
            }
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "\n Pentru a va reintoarce la meniu, apasati orice tasta.";
            getch();
            system("CLS");
        }
        case 0:
            break;
        default:
        {
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<"TASTA INCORRECTA. Pentru a va reintoarce la meniu, apasati orice tasta."<<endl;
            getch();
            system("CLS");
        }
        }

    }
    while(raspuns!=0);
}
