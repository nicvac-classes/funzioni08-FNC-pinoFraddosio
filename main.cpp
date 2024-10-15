#include <iostream>
#include <string>
using namespace std;


string Inputsegno(){
    string c;
    do{
        cout<<"Inserire il tipo di operazione che deve essere efettuata: (I = innaffiare, P = piantare, R = racogliere, S = sole, T = reset, X = fine)";
        cin>>c;
    }while(c != "I" && c != "P" && c != "R" && c != "S" && c != "T" && c != "X");

    return c;
}

int Reset_Giardino(int capacita_max){
    capacita_max = 0;
    return capacita_max;
}

int Innaffia(int umidita){
    int umidita_nuova;
    umidita_nuova = umidita + 10;
    return umidita_nuova;
}

int Pianta(int numPiante){
    int piante_tot;
    do{
        cout<<"Quante painte piantare:";
        cin>>piante_tot;
        if(piante_tot <= 0){
            cout<<"Inserire un numero diverso o maggiore di 0"<<endl;
        }
    }while(piante_tot <= 0);
    piante_tot = numPiante + piante_tot;
    return piante_tot;
}

int Raccogli(int numPiante){
    int piante_tot;
    do{
        cout<<"Quante piante raccogliere: ";
        cin>>piante_tot;
        if(piante_tot <= 0){
            cout<<"Inserire un numero diverso o uguale a 0"<<endl;
        }
    }while(piante_tot <= 0);
    piante_tot = numPiante - piante_tot;
    return piante_tot;
}

int Sole(int umidita){
    int umidita_nuova;
    umidita_nuova = umidita - 10;
    return umidita_nuova;
}

int main() {
    int max,umidita = 0,piante=0;
    string operazione;
    cout<<"Inserire la capacità massima del giardino: ";
    cin>>max;
    do{
        cout<<"Il numero di umidità del gardino è pari a: "<<umidita<<"; il numero di piante è: "<<piante<<"La capacità massima è di: "<<max<<endl;
        operazione = Inputsegno();
        if(operazione == "I"){
            umidita = Innaffia(umidita);
        }
        if(operazione == "P" && piante < max){
            piante = Pianta(piante);
        }
        else if(piante >= max){
            cout<<"non puoi piantare più piante"<<endl;
        }
        if(operazione == "R"){
            piante = Raccogli(piante);
        }
        if(operazione == "S"){
            umidita = Sole(umidita);
        }
        if(operazione == "T"){
            max = Reset_Giardino(max);
            umidita = Reset_Giardino(max);
            piante = 0;
        }
    }while(operazione != "X");
    

    cout<<"Il gioco è finito!"<<endl;
    return 0;
}


