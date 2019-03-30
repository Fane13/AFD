#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;
struct Stari {
    int stare; /// starea in care te afli
    int proprietate[2]; /// proprietate[0] == 1 daca este stare initiala / == 0 in caz contrar
                        /// proprietate[1] == 1 daca este stare finala / == 0 in caz contrar
    vector<pair<int, string>> tranzitii; /// memoreaza tranzitiile cu starea in care merge si litera pe care o verifica
};

void citire_automat(vector<Stari> *stari, char *nume_fisier, int &numar_stari, int &numar_tranzitii) {
    ifstream fin(nume_fisier);
    fin >> numar_stari >> numar_tranzitii;
    int stare_initiala, stare_actuala, index, numar_stari_finale, iterator;
    vector<int> stari_finale;
    fin >> stare_initiala >> numar_stari_finale;
    for (iterator = 0; iterator < numar_stari_finale; iterator++) {
        int aux;
        fin >> aux;
        stari_finale.push_back(aux);
    }
    iterator = 0;
    fin >> stare_actuala;
    for (index = 0; index < numar_tranzitii; index++) {

        Stari t;
        t.stare = stare_actuala;
        if (t.stare == stare_initiala) t.proprietate[0] = 1;
        else t.proprietate[0] = 0;
        if (t.stare == stari_finale[iterator]) {
            t.proprietate[1] = 1;
            iterator++;
        } else t.proprietate[1] = 0;
        pair<int, string> auxiliar;
        fin >> auxiliar.first;
        fin >> auxiliar.second;
        t.tranzitii.push_back(auxiliar);
        fin >> stare_actuala;
        while (stare_actuala == t.stare && index < numar_tranzitii) {
            pair<int, string> auxiliar2;
            fin >> auxiliar2.first;
            fin >> auxiliar2.second;
            t.tranzitii.push_back(auxiliar2);
            index++;
            fin >> stare_actuala;
        }

        stari->push_back(t);

    }



}

int verificare_cuvant(vector<Stari> stari, string cuvant, int index_litera, int index_stare) {
    if (cuvant == "lambda" && stari[index_stare].proprietate[1] == 1) return 1;
    if (index_litera == cuvant.size())
        if (stari[index_stare].proprietate[1] == 1) return 1;
    for (int index = 0; index < stari[index_stare].tranzitii.size(); index++) {
        if (stari[index_stare].tranzitii[index].second.size() == 2) {
            if (stari[index_stare].tranzitii[index].second[0] == cuvant[index_litera] ||
                stari[index_stare].tranzitii[index].second[1] == cuvant[index_litera])
                return verificare_cuvant(stari, cuvant, index_litera + 1, stari[index_stare].tranzitii[index].first);
        } else if (stari[index_stare].tranzitii[index].second[0] == cuvant[index_litera])
            return verificare_cuvant(stari, cuvant, index_litera + 1, stari[index_stare].tranzitii[index].first);
    }
    return 0;

}

int main() {
    vector<Stari> stari;
    int numar_stari, numar_tranzitii;
    char nume_fisier[] = "afn.in";
    citire_automat(&stari, nume_fisier, numar_stari, numar_tranzitii);
    string cuvant;
    cout << "cuvantul pe care vrem sa il verificam :";
    cin >> cuvant;
    int index = 0;
    while (stari[index].proprietate[0] != 1) {
        index++;
    }
    if (verificare_cuvant(stari, cuvant, 0, index)) cout << "cuvantul este acceptat";
    else cout << "cuvantul nu este acceptat";


}
