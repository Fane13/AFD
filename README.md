# AFD
 Pentru a salva in memorie automatul ostru am folosit o structura numita Stari in care avem o variabila de tip int numit stare in care vom gasi numele starii , un vector de tip int cu 2
elemente numit proprietate in care in primul element vom avea valoarea1 daca starea in care ma aflu este initiala , 0 in caz contrar si in al doilea element vom avea valoarea 1 daca starea
actuala este finala , o in caz contrar si un vector de perechi numit tranzitii in care in primul element al perechii memorez starea in care merg si in al doilea element memorez literele .
   Functia citire_automat are ca paramatrii un vector de elemente de tip Stari in care se vor memora starile ,un sir de caractere numit nume_fisier in care am numele fisierului din care
citesc automatul , si 2 variabile de tip int in care voi memora numarul de stari respetiv de tranzitii ale automatului.
   Functia verificare_cuvant are ca parametrii , vectorul de Stari , un element de tip string in care am cuvantul pe care vreau sa il verific , variabila de tip int index_litera care reprezinta a cata litera
din cuvant o verific si variabila de tip int index_stare care reprezinta starea in care ma aflu. Functia este recursiva si functioneaza prin parcurgerea campului tranzitii din structura astfel incat daca
daca litera din cuvant corespunde cu litera consumata pe tranzitia catre o stare , reapelez functia pentru acea stare si cresc index_litera pentru a verifica urmatoarea litera din cuvant.Daca in vreun punct ajung sa termin cuvantul,
verific daca starea in care ma aflu este satre finala si daca da intorc 1 - valoare care exprima faptul ca acest cuvant este acceptat de autmat.
