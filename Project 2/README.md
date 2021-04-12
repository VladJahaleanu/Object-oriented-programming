Cerinte pentru cel de-al doilea proiect din cadrul cursului de Programare Orientata pe Obiecte:

- Toate clasele vor conține obligatoriu constructori de inițializare, parametrizați și de copiere; destructor; operatorii „=”, „>>”, „<<” supraîncărcați corespunzător, moșteniri & encapsulare 
- Clasele derivate trebuie sa contina constructori parametrizati (prin care sa se evidentieze transmiterea parametrilor catre constructorul din clasa de baza) si destructori.
- În fiecare proiect vor fi ilustrate conceptele de upcasting, downcasting, funcții virtuale (pure – unde se consideră mai natural)
- Utilizarea de variabile și de funcții statice
- Citirea informațiilor complete a n obiecte, memorarea și afișarea acestora
- Meniu interactiv
- Rezolvarea corectă a cerințelor suplimentare corespunzatoare fiecarei teme

Tema 12. Se dau clasele:
-	Card (string nrCard, string NumeDetinator, string data_expirare, int CVV, double credit)
-	Card_standard (int limitaExtragere, double comisionDepasireLimita) : Card
-	Card premium (double cashback) : Card_Standard

Permiteti printr-o metoda sa extrageti bani de pe un card. Sa se verifice ca aceasta suma sa nu fie mai mare decat creditul. Sa se modifice creditul la extragere in functie de card standard sau premium. Daca depaseste limita cardului standard atunci se aplica comisionul pentru diferenta de bani. Daca se extrage de pe un card premium sa primeasca inapoi cashback/100 * suma retrasa.
