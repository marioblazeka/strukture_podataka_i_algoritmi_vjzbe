# Strukture podataka i algoritmi

## 1. Apstraktni tip podataka polinom

### 1. Što su apstraktni tipovi podataka?

- Tipovi podataka koji ne postoje ugrađeni u programskom jeziku
- Programer ih sam implementira prema potrebi

### 2. Objasnite taksonomiju apstraktnih tipova podataka.

Opća taksonomija

- **linearni** (lista, red, stog)
- **hijerarhijski** (općenito stablo, binarno stablo)
- **dvodimenzionalno hijerarhijski** (usmjereni i neusmjereni graf)
- **skupovni **(skup, prioritetni red, rječnik)

### 3. Kako se zadaju apstraktni tipovi podataka?

Zadaju se navođenjem jednog ili više **tipova podataka** te jedne ili više **operacije** (_funkcije_)

### 4. Što je i od čega se sastoji implementacija apstraktnog tipa podataka?

Konkretna realizacija apstraktnog tipa podataka u nekom programskom jeziku.

Sastoji se od:

- definicije za strukture podataka kojom se prikazuju podaci iz apstraktnog tipa podataka
- potprograma (funkcija) kojima se operacije iz apstraktnog tipa podataka ostvaruju pomoću odabranih algoritama

### 5. Nabrojite i objasnite dijelove strukture podataka.

| **Dio strukture podataka** | **Objašnjenje**                                              |
| :------------------------- | ------------------------------------------------------------ |
| Ćelija                     | Varijabla koju promatramo kao zasebnu cjelinu, a ima svoj __tip__ i __adresu__. |
| Polje                      | Više ćelija istog tipa pohranjenih na uzastopnim adresama.   |
| Zapis (slog)               | Više ćelija koje ne moraju biti istog tipa, no koje su pohranjene uzastopno. |
| Pokazivač                  | Ćelija koja sadrži adresu ćelije na koju pokazuje.           |
| Kursor                     | Ćelija koja pokazuje na element nekog polja, a sadrži indeks tog elementa. |

### 6. Objasnite od čega se sastoji struktura podataka apstraktnog tipa podataka polinom.

Sastoji se od:

- jednodimenzionalno polja `values[n]`
- jednog kursora (cjelobrojne vrijednosti) koja označava duljinu polinoma

```cpp
struct polinom {
    double values[1000];
    int en;
}
```

### 7. Objasnite kako se polinom pohranjuje u polje.

Svaki element polja predstavlja koeficijent jednog člana polinoma, tako da indeks polja odgovara potenciji nad nepoznanicom $x$.

Kursor postavljamo na jedno polje dalje nego što su sve vrijednosti upisane (ako je $x^3$, onda ide na 4).

### 8. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka polinom.

| **Funkcija**         | **Opis**                                                     |
| -------------------- | ------------------------------------------------------------ |
| `Zero(&p)`           | pretvara polinom u nul-polinom                               |
| `IsZero(p)`          | provjerava da li je polinom nul-polinom                      |
| `Coef(p,pot)`        | vraća koeficijent u polinomu uz zadanu potenciju             |
| `Attach(&p,pot,val)` | pridruživanje vrijednosti uz zadanu potenciju                |
| `Degree(p)`          | vraća stupanj polinoma                                       |
| `Add(p1,p2,&p3)`     | zbraja polinome p1 i p2 (zbroj je polinom p3)                |
| `Subt(p1,p2,&p3)`    | oduzima polinome p1 i p2 (razlika je polinom p3)             |
| `Mult(p1,p2,&p3)`    | množi polinome p1 i p2 (umnožak je polinom p3)               |
| `Div(p1,p2,&p3,&p4)` | dijeli polinome p1 i p2 (kvocijent se sprema u p3, a ostatak dijeljenja u p4) |

## 2. Analiza složenosti algoritama - prvi dio

### 1. Na proizvoljnom primjeru objasnite što je masovni problem.

Problem se zadaje opisom ulaznih podataka i traženog rješenja. Kod zadavanja problema, parametri često ostaju neodređeni pa zbog toga kažemo da je problem masovan. **Masovni problem** je generalno opisan problem koji je potrebno algoritamski riješiti. Prilikom definicije masovnog problema potrebno je zadati generalni opis svih parametara i ograničenja koja rješenja masovnog problema mora zadovoljavati.

Primjer (_sortiranje_)

- ULAZ: Niz $a_1,...,a_n$ od $n$ ključeva
- IZLAZ: Permutacija niza $a_1^{'},...,a_n^{'}$ sa svojstvom da je $a_1^{'}\le...\le a_n^{'}$

### 2. Na proizvoljnom primjeru objasnite što je instanca problema.

Specificiranjem svih parametara masovnog problema dobivamo **instancu problema**. **Instanca problema** je konkretizacija ulaznih podataka. Duljina instance problema je definirana brojem podataka u instanci.

Primjer:

- niz 65,43,23,56,33,11,71,44,56,66 definira instancu problema sortiranja duljine 10

### 3. Što je algoritam?

Naziv dolazi od imena iranskog matematičara koji je napisao knjigu pod nazivom _Pravila restoracije i redukcije_. **Algoritam** je proceduralno rješenje nekog masovnog problema. Algoritam rješava određeni masovni problem ako daje rješenje za sve instance problema.

### 4. Objasnite Euklidov algoritam.

Opisao ga je grčki matematičar Euklid u svojoj knjizi _Elementi_. Prvi značaj algoritam koji se još i danas koristi, nastao u 3. stoljeću prije naše ere. Služi pronalaženju najveće zajedničke mjere dva prirodna broja.

- ULAZ: Dva prirodna broja $A$ i $B$
- IZLAZ: Najveća zajednička mjera $M(A,B)$

1. Ako je $A<B$, zamijeni im mjesta
2. Sve dok je $B\neq0$
   1. $Pom=A\bmod B$
   2. $A=B$
   3. $B=pom$
3. Vrati $A$

Za najveću zajedničku mjeru više od dva broja, prvo naći zajedničku mjeru prva dva broja, nakon toga zajedničku mjeru mjere prva dva broja i trećeg broja, itd.

### 5. Nabrojite i objasnite Knuthova svojstva algoritma.

| Svojstvo      | Opis                                                         |
| ------------- | ------------------------------------------------------------ |
| Konačnost     | Algoritam mora završiti nakon izvršenih konačno mnogo koraka. Algoritam mora biti opisan pomoću konačnog broja operacija gdje svaka operacija mora biti konačne duljine. |
| Određenost    | Svaki korak algoritma mora sadržavati nedvosmislene, točno definirane operacije. |
| Ulaz          | Svaki algoritam mora imati 0 ili više ulaza.                 |
| Izlaz         | Svaki algoritam mora imati 1 ili više izlaza.                |
| Djelotvornost | Algoritam treba biti takav da ga je moguće pomoću papira i olovke izvesti u konačnom vremenu. |

### 6. Što je korektnost algoritma?

Kažemo da je algoritam konkretan ako za svaki ulaz koji zadovoljava preduvjete problema daje rješenje koje zadovoljava postuvjete problema.

- **Parcijalna korektnost** - algoritam daje točno rješenje u slučaju da se zaustavi
- **Potpuna korektnost** - algoritam se zaustavlja za svaku instancu problema i daje točno rješenje iste

Korektnost algoritma se provjerava pretvaranjem algoritma u niz algebarskih jednadžbi.

### 7. Nabrojite i objasnite vrste korektnosti algoritma.

| Vrsta korektnosti     | Kod                                                          | Objašnjenje                                                  |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Aritmetičke operacije | ```float arit(float a, float b){<br />int s=a;<br />s=s+b;<br />s=s/2;return s;}``` | zaključujemo da ovaj algoritam vraća aritmetičku sredinu brojeva a i b |
| Selekcija ```if```    | ```float Abs (float a) { if(a<0) a=-a; else a=a; return a; }``` | Algoritam daje apsolutnu vrijednost broja a                  |
| Iteracija             | ```float Fact (int n){ int f=1; for (int i=1;i<=n;i++){ f=f*i; } return f; }``` | Vraća faktorijel od n                                        |
| Rekurzija             | ```float Fib (int n) { if (n<=1) return 1; else return Fib(n-1)+Fib(n-2); }``` | Algoritam vraća n-ti član Fibbonaccijevog niza               |

### 8. Kakav algoritam mora biti?

Algoritam je precizno i jednoznačno definiran način rješavanja problema. Algoritam mora biti:

- **djelotvoran** - u konačnom vremenu može se dobiti rezultat
- **učinkovit** - dobivanje rezultata s obzirom na utrošene resurse

### 9. Što su programi prema Wirthu?

$Algoritam + strukture \ podataka = programi$

### 10. Zbog čega se provodi analiza složenosti algoritama?

Složenost algoritma se može definirati temeljem dva osnovna kriterija:

- **Prema prostoru** potrebnom da se podaci pohrane u memoriji (rjeđe)
- **prema vremenu** potrebnom da se izvedu operacije nad podacima (češće)

Svrha analize složenosti:

- optimizirati postojeći algoritam
- pronaći ili razviti učinkovitiji algoritam

Broj operacija koje izvodi algoritam nije fiksan već ovisi o veličini ulaza. Instance problema različitih dimenzija zahtijevaju različiti broj elementarnih operacija za obradu. Masovni problem može imati i različite instance iste duljine čija vremenska složenost ne mora biti jednaka. Prema tome, složenost algoritma nije funkcija veličine već se ocjena složenosti odnosi na određenu instancu problema.

### 11. Nabrojite i objasnite vrste analize algoritama.

- **A priori**
  - procjena vremena izvođenja algoritma neovisno o korištenom programskom jeziku, prevoditelju, vrsti računala i sl.
  - trajanje izvođenja algoritma je vrijednost funkcije koja sadrži neke relevantne argumente
- **A posteriori**
  - stvarno vrijeme potrebno za izvođenje algoritma na određenom računalu
  - statistički podaci dobiveni mjerenjem na računalu

### 12. Objasnite vremensku složenost algoritma.

Točan izračun složenosti algoritma. Ne ovisi o brzini računala na kojem se algoritam izvodi već o samom algoritmu. Mjeri se brojem osnovnih operacija koje algoritam mora izvesti da bi izračunao rješenje. Svakoj naredbi jezika dodjeljuje se složenost, pa se vremenska složenost algoritma računa kao ukupna složenost svih naredbi u njemu. Ukoliko se algoritam izvodi na računalima sa različitim procesorima, broj osnovnih operacija će se razlikovati za neku multiplikativnu konstantu.

### 13. Koje naredbe u programskom jeziku C++ imaju složenost 0?

- Komentar
- Deklarativne naredbe

### 14. Kojim je naredbama u programskom jeziku C++ složenost konstanta?

- računske operacije
- operacije uspoređivanja
- pridruživanje vrijednosti
- čitanje vrijednosti
- pristupanje elementima polja
- operacije s pokazivačima

### 15. Objasnite vremensku složenost iteracije u programskom jeziku C++.

Svaki program petlje ima složenost jednaku složenosti naredbi unutar petlje, uvećanu za trajanje kontrole petlje. Ukupna složenost petlje se izračunava kao broj koraka petlje pomnožen sa složenošću jednog koraka petlje.

### 16. Objasnite vremensku složenost selekcije u programskom jeziku C++.

Složenost selekcije je jednaka složenosti njenog dijela koji se izvodi uvećanog za trajanja evaluacije izraza uvjeta.

### 17. Objasnite vremensku složenost poziva procedure ili funkcije u programskom jeziku C++.

Ako su svi argumenti elementarni tipovi podataka, onda je složenost poziva konstanta. Ako je jedan ili više argumenata polje, onda je konstanta pomnožena s veličinom polja.

### 18. Objasnite što je, zbog čega se i kako provodi asimptotska analiza algoritama.

Složenost, bez obzira radi li se o najgorem, najboljem ili prosječnom slučaju, može biti funkcija koja nije analitička, a ako i jest analitička, može zahtjevati vrlo složenu formulu za prikaz. Analitička funkcija je ona koja se može pokazati formulom izgrađenom pomoću aritmetičkih operacija i transcedentnih funkcija.

Cilj nam je aproksimativno izraziti složenost, jer je točan broj operacija vrlo teško izračunati, a takav izračun ne bi dao značajan rezultat. Osim toga, brzina rada algoritma ovisi o računalu na kojem se izvodi. Sve to ukazuje da se točan račun složenosti ne isplati. Ono što je važno i što značajno razlikuje algoritme jest koliko brzo složenost raste s porastom veličine ulaza.

Stoga ćemo funkciju složenosti aproksimirati jednostavnijom funkcijom koja će dobro opisivati rast složenosti s povećanjem nezavisne varijable. Zato je prikladno uvesti notaciju koja jednostavno opisuje brzinu rasta funkcije složenosti algoritma, odnosno _asimptotsku ocjenu rasta funkcije_.

Pri izračunu složenosti, aproksimacija se najčešće vrši tako da aproksimativna funkcija, koja je jednostavnija od same funkcije složenosti, dobro asimptotski opisuje rast složenosti. Međutim, dozvoljava se da za male vrijednosti $n$ ova aproksimacija ne vrijedi. Pretpostavlja se da će svi algoritmi, bez obzira na njihovu složenost, raditi zadovoljavajuće za male $n$, dok veći problemi nastaju s porastom veličine ulaza. Stoga se kod definicije asimptotskih ocjena funkcije dozvoljava da ocjena ne bude precizna za $n<n_0$.

Na sljedećem grafu, funkcija kojom se ocjenjuju složenost nacrtana je tako da omeđuje odozgo složenost u najgorem slučaju. Međutim, to nije nužno. Ako je $f(n)$ ocjena složenosti nekog algoritma, tada će i funkcija $f(n)+c$ također biti funkcija koja ocjenjuje složenost tog algoritma. BItno je da nas ne zanima stvarni iznos funkcije složenosti, već samo koliko brzo ta funkcija raste.

Veličina ulaza ($x$) i trajanje izračuna ($y$) su ključni faktori. Cilj je za danu funkciju $f(n)$ pronaći krivulju $g(n)$ koja aproksimira $f(n)$, što predstavlja asimptotsku analizu algoritma. Ne zanima nas točan iznos vremena izvršavanja algoritma, već samo njegov red veličine.

Procjena složenosti algoritma temelji se na ocjeni brzine rasta funkcije. Ignoriraju se konstante, osim kada je $n$ vrlo malen, odnosno kada konstante značajno utječu na performanse algoritma. Broj operacija koje algoritam izvodi nije fiksan, već ovisi o veličini ulaza. Različite instance problema iste duljine mogu zahtijevati različit broj elementarih operacije za obradu, pa njihova vremenska složenost ne mora biti jednaka. Složenost algoritma povezana je s određenom instancom problema koji se rješava algoritmom.

### 19. Nabrojite i objasnite vrste asimptotskih notacija.

Temeljna ideja asimptotske analize je imati mjeru učinkovitosti algoritama koja ne ovisi o konstantama specifičnim za računalo na kojem se algoritmi izvršavaju, ne iziskuje implementaciju algoritama kao ni vrijeme potrebno za njihovu usporedbu.

Asimptotske notacije su matematički alati za predstavljanje vremenske složenosti algoritama za asimptotsku analizu.

| Notacija            | Opis                                           | Granica                | Detalji                               |
| ------------------- | ---------------------------------------------- | ---------------------- | ------------------------------------- |
| **O** (Big-Oh)      | Gornja granica izvođenja algoritma             | Čvrsta gornja granica  | Ograničava funkciju samo odozgo       |
| **Ω** (Big-Omega)   | Donja granica izvođenja algoritma              | Čvrsta donja granica   | Ograničava funkciju samo odozdo       |
| **Θ** (Big-Theta)   | Prosječna (točna) granica izvođenja algoritma  | Gornja i donja granica | Definira točno asimptotsko ponašanje  |
| **o** (small-omega) | Labava gornja granica rasta funkcije algoritma | Labava gornja granica  | Gruba procjena maksimalnog reda rasta |
| **ω** (small-omega) | Labava donja granica rasta funkcije algoritma  | Labava donja granica   | Gruba procjena minimalnog reda rasta  |

### 20. Nabrojite, objasnite i navedite primjere za kategorije (tipove) algoritama prema složenosti.

| Tip algoritma             | Složenost    | Opis                                                         | Primjeri                                           |
| ------------------------- | ------------ | ------------------------------------------------------------ | -------------------------------------------------- |
| **Konstantan**            | O(1)         | Vrijeme izvođenja ne ovisi o veličini ulaza.                 | Dohvaćanje elementa u nizu, aritmetička operacija. |
| **Logaritamski**          | O(log n)     | Opseg problema se svakim ponavljanjem smanjuje za red veličine baze. | Binarno pretraživanje (Binary Search).             |
| **Linearan**              | O(n)         | Vrijeme izvođenja raste proporcionalno veličini ulaza.       | Sekvencijalno pretraživanje.                       |
| **Linearno-logaritamski** | O(n log n)   | Složenost raste sporije od kvadratne funkcije; koristi se kod sortiranja. | Merge Sort, Quick Sort (prosječni slučaj).         |
| **Kvadratni**             | O(n²)        | Vrijeme izvođenja raste kvadratno s veličinom ulaza; često se koristi dvostruka petlja. | Bubble Sort, Selection Sort, Insertion Sort.       |
| **Stupanjski**            | O(nᵐ), m < 1 | Poopćenje kvadratnih algoritama, često za specifične probleme visokih dimenzija. | Fibonaccijev niz, Hanojski tornjevi.               |
| **Faktorijelni**          | O(n!)        | Generira sve moguće permutacije ili kombinacije.             | Problem trgovačkog putnika (brute force).          |

| Tip algoritma                     | Složenost         |
| --------------------------------- | ----------------- |
| **Konstantan**                    | O(1)              |
| **Logaritamski**                  | O(log n)          |
| **Linearan**                      | O(n)              |
| **Linearno-logaritamski**         | O(n log n)        |
| **Kvadratni**                     | O(n²)             |
| **Stupanjski (polinomni)**        | O(nᵐ), m > 2      |
| **Podeksponentni**                | O(m log n), m > 1 |
| **Eksponentni**                   | O(mⁿ), m > 1      |
| **Faktorijelni (nadeksponentni)** | O(n!)             |

Za dovoljno veliki $n$ vrijedi:

$1 < \log n < \sqrt{n} < n < n \log n < n^2 < n^3 < \dots < 2^n < 3^n < n^n$

### 21. Na proizvoljnom primjeru objasnite big-Oh (O) notaciju.

Neka su $f,g:\mathbb{N}→\mathbb{N}$ rastuće funkcije. Kažemo da je $f(n)=O(g(n))$ ako postoje dvije pozitivne konstante $n_0 \in \mathbb{N}$ i $c\in\mathbb{R^+}$ takve da za svaki $n\ge n_0$ vrijedi $|f(n)|\le c|g(n)|$. Druga oznaka za ovo je $f(n) \le g(n)$. Ako vrijedi $f(n)=O(g(n))$, tada funkcija $f$ ne raste brže od funkcije $g$.

Na primjer, za $f(n)=2n+3$, funkcija $f(n)$ pripada klasi $n$, koja predstavlja prosječnu granicu izvođenja algoritma. Klase od $n$ do $n^n$ predstavljaju gornju granicu izvođenja algoritma. Stoga, za ovu funkciju vrijedi $f(n)=O(n),f(n)=O(n^2),f(n)=O(2^n)$, jer su $n,n^2$ i $2^n$ gornje granice izvođenja algoritma. Međutim, $f(n) \ne O(log\ n)$ jer je $log \ n$ donja granica izvođenja algoritma.

Uvijek se teži tome da gornja granica bude što bliža klasi kojoj $f(n)$ pripada. U ovom primjeru to je $O(n)$.

Primjer za složeniju funkciju: $F(n)=3n^3+2n^2+n-3$

### 22. Na proizvoljnom primjeru objasnite big-Omega (Ω) notaciju.

### 23. Na proizvoljnom primjeru objasnite big-Theta (Θ) notaciju.

### 24. Na proizvoljnom primjeru objasnite small-Oh (o) notaciju.

### 25. Na proizvoljnom primjeru objasnite small-Omega (ω) notaciju.

### 26. Nabrojite koje funkcije u implementaciji apstraktnog tipu podataka polinom pomoću polja nemaju konstantnu složenost te objasnite zašto je tome tako.

| Funkcija | Složenost | Objašnjenje                                                  |
| -------- | --------- | ------------------------------------------------------------ |
| Attach   | O(n)      | Popunjava nule između trenutnog kraja polinoma i zadane potencije. |
| Add      | O(n)      | Iterira kroz koeficijente oba polinoma kako bi ih zbrojila.  |
| Subt     | O(n)      | Iterira kroz koeficijente oba polinoma kako bi ih oduzela.   |
| Mult     | O(n²)     | Množi svaki koeficijent prvog polinoma sa svakim koeficijentom drugog polinoma. |
| Div      | O(n²)     | Ponovljeno dijeljenje uključuje oduzimanje i skaliranje kroz cijeli polinom u svakoj iteraciji. |

## 3. Analiza složenosti algoritama - drugi dio

### 1. Nabrojite i objasnite faze razvoja programskog proizvoda.

Razvoj programskog proizvoda sastoji se od dvije faze: **dizajna** i **implementacije**.

Naprije je tijekom dizajna potrebno osmisliti rješenje problema iz razloga što se programski proizvod ne može razvijati po principu pokušaja i pogreške. Jednom kad je dizajn rješenja problema dovoljno razrađen i usavršen, slijedi njegova implementacija.

DIzajn rješenja ne ovisi o sintaksi programskog jezika te se može provesti na papiru ili u nekom programu za obradu teksta. Tijekom faze dizajna nastaje algoritam, kojeg osmišljava osoba s znanjem iz domene problema. Algoritam se obliku u bilo kojem jeziku uz poželjnu primjenu matematičke notacije, neovisno o hardveru, softveru i operacijskom sustavu.

Tijekom faze implementacije nastaje program koji piše programer u odabranom programskom jeziku. Ova faza ovisi o hardveru, softveru i operacijskom sustavu.

Algoritam analiziramo kako bismo utvrdili njegovu učinkovitost, a program testiramo kako bismo utvrdili njegovu ispravnost.

### 2. Zbog čega se provodi usporedba funkcija?

Provodi se kako bi se utvrdilo da li je jedna funkcija veća od druge, manja od druge ili su obje funkcije jednake.

### 3. Nabrojite i objasnite načine usporedbe funkcija.

- Prvi je pomoću **testnih podataka**
  - ako se dokaže da su kod primjene testnih podataka rezultati prve funkcije uvijek manji od rezultata druge funkcije, onda možemo zaključiti da... (_unesi neko rješenje_)
- drugi način je za usporedbu **primjena log na obje funkcije**

### 4. U kojem slučaju možemo kod usporedbe funkcija zanemariti koeficijente?

Kad direktno uspoređujemo funkcije (ne primjenjujemo _log_ na njih), onda možemo zanemariti koeficijente, dok iste ne smijemo zanemariti kad na funkcije primjenimo log

### 5. Nabrojite i objasnite svojstva asimptotskih notacija.

| Svojstvo                 | Opis                                                         |
| ------------------------ | ------------------------------------------------------------ |
| **Općenito svojstvo**    | Ako je $f(n)=O(g(n))$, tada je $a \cdot f(n)=O(g(n))$. Vrijedi i za ostale notacije |
| **Refleksivnost**        | Ako je zadan $f(n)$, tada je $f(n)=O(f(n))$, što znači da je funkcija gornja granica sama sebi. Gornja granica je jednaka ili veća od klase kojoj pripada $f(n)$. |
| **Tranzitivnost**        | Ako je $f(n)=O(g(n))$, a $g(n)=O(h(n))$, tada je $f(n)=O(h(n))$. Vrijedi i za ostale notacije. |
| **Simetrija**            | Ako je $f(n)=Θ(g(n))$, tada je $g(n)=Θ(f(n))$. Vrijedi samo za $Θ$ notaciju, odnosno kad su funkcije jednake. |
| **Kombinacija funkcija** | Ako je $f(n)=O(g(n))$, tada je $g(n)=Ω(g(n))$, tada je $f(n)=Θ(g(n))$ jer vrijedi $g(n)\le f(n) \le g(n)$. |
| **Zbrajanje funkcija**   | Ako je $f(n)=O(g(n))$ i $d(n)=O(e(n))$, tada je $f(n)+d(n)=O(max(g(n),e(n))$ |
| **Množenje funkcija**    | Ako je $f(n)=O(g(n))$ i $d(n)=O(e(n))$, tada je $f(n)*d(n)=O((g(n)*e(n))$ |

### 6. Na proizvoljnom primjeru usporedite analizu najgoreg, najboljeg i prosječnog slučaja izvođenja algoritma.

#### Analiza najgoreg slučaja izvođenja algoritma

Najčešće se provodi. Izračunava se gornja granica vremena rada algoritma. Izračunava se složenost one instance problema određene duljine za čiju obradu algoritam treba najveći broj operacija (najčešće vremena). U linearnom pretraživanju je to situacija gdje se tražena vrijednost nalazi u posljednjem indeksu polja ili se ne nalazi u polju pa je potrebno $n$ uspoređivanja. Složenost algoritma linearnog pretraživanja je u tom slučaju:

- $O(n)$
- $\Theta(n)$
- $\Omega(n)$

#### Analiza prosječnog izvođenja algoritma

Ponekad se provodi. U obzir je potrebno uzeti sve instance problema određene duljine ulaza te svakoj od njih pridružiti vjerojatnost pojavljivanja. Zbroj svih izračunatih vrijednosti se podijeli s ukupnim brojem ulaza. Moramo znati ili predvidjeti raspodjelu (distribuciju) svih mogućih slučaja jednoliko raspoređeni (uključujući slučaj da se tražena vrijednost ne nalazi u polju). Zbrojimo sve slučajeve (_usporedbe_) i podijelimo zbroj s $n$ (_veličina polja_):

$1+2+...+n= \frac{\frac{n(n+1)}{2}}{n}=\frac{n+1}{2}$

Složenost algoritma linearnog pretraživanja je u tom slučaju:

- $O(n)$
- $\Theta(n)$
- $\Omega(n)$

#### Analiza najboljeg slučaja izvođenja algoritma

Rijetko se provodi. Izračunavamo donju granicu vremena rada algoritma. Izračunava se složenost one instance problema određene duljine za čiju obradu algoritam treba najmanji broj operacija (najmanje vremena). U linearnom pretraživanju bi to bila situacija kad se tražena vrijednost nalazi u nultom indeksu polja pa imamo samo jednu operaciju uspoređivanja. Broj operacija je u najboljem slučaju konstantan (ne ovisi o $n$). Prema tome, vremenska složenost je u najboljem slučaju.

- $O(1)$
- $\Theta(1)$
- $\Omega(1)$

#### Analiza složenosti algoritama

Analiza najboljeg, prosječnog ili najgoreg slučaja dobivamo funkciju složenosti algoritma u ovisnosti o duljini ulaza. Za neke su algoritme svi slučajevi asimptotski isti, odnosno ne postoji najgori i najbolji slučaj. Primjerice, **složenost sortiranja spajanjem (Merge Sort)** je $\Theta(n \log n)$. Većina drugih algoritama sortiranja ima najgore i najbolje slučajeve.

Primjerice, najgori slučaj za **brzo sortiranje (Quick Sort)** u implementaciji prema kojoj se kao _pivot_ odabire krajnje lijeva ili krajnje desna vrijednost u polju kad je ulazni niz već sortiran istim ili obrnutim redoslijedom, a najbolji slučaj je kada pivot dijeli polje na dva jednaka dijela. Kod **sortiranja umetanjem (Insertion Sort)** se najgori slučaj događa kada je niz obrnuto sortiran, a najbolji slučaj javlja se kada je niz sortiran istim redoslijedom kao i izlaz.

Kod pisanja algoritama nisu bitne deklaracije niti ostali aspekti koji se vežu uz implementaciju algoritma u određenom programskom jeziku. Kod pisanja algoritma treba se koristiti notacijom koja će biti razumljiva svakome tko će ga koristiti.

Osim _prostora_ i _vremena_, današnji algoritmi mogu se analizirati i s aspekta:

- __mrežnog kapaciteta__ u kontekstu količine i veličine podataka koji će se prenositi u jedinici vremena
- __procesorskih registara__ koje algoritam troši ako se isti razvija za npr. drivere

Analiza se može provoditi na razini algoritma ili se može konkretizirati do razine strojnog jezika na način da se pojedini korak algoritma konkretizira u obliku naredbi. Kod vremenske analize se kao jedinica za analizu uzima naredba, a kod prostorne analize riječ jer ne znamo kojeg tipa podatka će pojedina varijabla u kodu biti.

### 7. Koji se resursi razmatraju tijekom analize složenosti algoritama?

- **Input** - duljina
- **Prostor**
- **Vrijeme**
  - Moguće i _mrežni kapacitet_, _količina energije_ i _procesorski registri_

### 8. Što predstavlja jedinicu za analizu kod vremenske, a što kod prostorne analize složenosti algoritama?

- kod vremenske - **naredba**
- kod prostorne - **riječ** (ne znamo kojeg će tipa podatka biti pojedina varijabla)

### 9. Na proizvoljnom primjeru objasnite metodu prebrojavanja učestalosti.

```cpp
Algorithm Sum(A, n)
{
    S = 0;
    for (i = 0; i < n; i++) {
        S = S + A[i];
    }
    return S;
}

```

Prvi dio `for` iteracije će se izvršiti jednom uvjet će se izvršiti $n+1$ puta, dok će se brojač izvršiti  $n$ puta. Kod izračuna složenosti je u slučaju `for` iteracija fokus na uvjet pa kažemo da će se iteracija izvršiti $n+1$ puta premda je njezina stvarna složenost $2n+2$ kada se zbroje složenosti svih dijelova zaglavlja `for` iteracije. Složenost tijela iteracije je $n$, složenost deklaracije `S` je $1$, složenost preskoka na `return` je $1$. Vremenska složenost algoritma je zbroj svih složenosti čime dobivamo polinom prvog reda $f(n)=2n+3$ pa je složenost reda $O(n)$

### 10. Na proizvoljnom primjeru objasnite metodu praćenja koda.

Zanima nas koliko puta će se izvršavati tijelo iteracije, a ne vrijeme izvršavanja iteracije tako da vrijeme izvršavanja iteracije ne uzimamo u obzir jer kod izračuna složenosti ionako uzimamo u obzir jer kod izračuna složenost ionako uzimamo u obzir red složenosti odnosno stupanj polinoma. Praćenje koda se sastoji od utvrđivanja koliko puta će se izvršiti tijelo iteracije u ovisnosti o varijablama $i$ i $j$ koje se nalaze ugniježdene `for` iteracijama. Praćenje koda je pokazalo da će se tijelo iteracije izvršiti $1 + 2 + 3 + ... + n = n(n+1)/2 \ puta$. Onda je složenost $O(n^2)$.

```cpp
for(i=0;i<n;i++) // n+1
{
    for(j=0;j<n;j++) // n * (n+1)
    {
        stmt; // n * n
    }
}
// O(n^2)
```

##  4.  Apstraktni tip podataka lista

### 1. Što je apstraktni tip podataka lista?

Niz od 0 ili više elemenata istog tipa ($a_1,..., a_n$). Za elemente je poznat njihov redoslijed u listi. Na listi su, između ostalog, dozvoljene operacije čitanja vrijednosti bilo kojeg njenog elementa, dodavanje elementa na bilo koje mjesto u listi i brisanja bilo kojeg elementa iz liste.

### 2. Što je duljina liste?

Broj elemenata u listi

### 3. Što je prazna lista?

Lista bez ijednog elementa

### 4. Koje se operacije razmatraju kod gotovo svih apstraktnih tipova podataka?

Kreiranje, dodavanje, uklanjanje, pristup, pretraga, izmjena, ispis ili pregled, brisanje

### 5. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka lista.

| **Naziv funkcije**  | **Opis funkcije**                                            |
| ------------------- | ------------------------------------------------------------ |
| **FirstL(L)**       | Funkcija koja vraća prvi element liste. Ako je lista prazna, funkcija vraća `EndL(L)`. |
| **EndL(L)**         | Funkcija koja vraća mjesto iza zadnjeg elementa liste.       |
| **NextL(p,L)**      | Funkcija koja vraća sljedbenika elementa `p`. Ako je `p` posljednji element liste, onda je `NextL(p,L)=EndL(L)`. Ako je `p=EndL(L)`, onda je funkcija nedefinirana. |
| **PreviousL(p, L)** | Funkcija koja vraća prethodnika elementa `p`. Ako je `p=FirstL(L)`, onda je funkcija nedefirana. Ako je `p=EndL(L)`, onda je `PreviousL(p,L)` posljednji element liste `L`. |
| **LocateL(x,L)**    | Funkcija koja vraća prvi element liste čija je vrijednost jednaka x. Ako takav element ne postoji, onda funkcija vraća `EndL(L)`. |
| **InsertL(x,p,L)**  | Dodaje se novi element na `p`-tu poziciju liste `L` i pridružuje mu se vrijednost `x`. Svi elementi koji su se nalazili u listi na pozicijama većim ili jednakim `p` pomiču se za jedno mjesto dalje. Moguće je dodati i novi element na poziciju `EndL(L)`. |
| **Delete(p, L)**    | Ovom se operacijom briše element s pozicije `p` iz liste `L`. Svi se elementi koji su se nalazili iza obrisanog elementa pomiču za jedno mjesto manje. |
| **RetrieveL(p, L)** | Funkcija koja vraća vrijednosti elementa liste `L` na poziciji `p`. |
| **DeleteAllL(L)**   | Funkcija koja briše sve elemente iz postojeće liste `L`.     |
| **InitL(L)**        | Funkcija za iniciranje prazne liste `L`.                     |

### 6. Koja je razlika između operacija LocateL i RetrieveL?

- `LocateL(x,L)` - funkcija koja vraća prvi element liste čija je vrijednost jednaka x. Ako takav element ne postoji, onda vraća `EndL(L)`
- `RetrieveL(p,L)` - funkcija koja vraća vrijednost elementa liste `L` na poziciji `p`.

### 7. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija liste pomoću polja?

- Jednodimenzionalnog polja dovoljno velike duljine
- Kursora koji pokazuje na `EndL(L)`, tj. na element iza posljednjeg elementa u listi

### 8. Objasnite kako se u implementaciji liste pomoću polja izvode funkcije (operacije) koje su nad istom definirane.

- **Imamo jednodimenzionalno polje** dovoljno velike duljine (\(n\)) i kursor koji pokazuje na `EndL(L)`, tj. na element iza posljednjeg elementa u listi (posljednji element u listi je na \(n-1\), a kursor je na \(n\) i ima vrijednost \(n\)).

### Funkcije i njihove operacije:
- **FirstL(L)** – Vraća vrijednost ćelije adrese \(0\).
- **EndL(L)** – Vraća adresu na koju pokazuje kursor.
- **NextL(2, L)** – Vraća sljedbenika ćelije adrese \(2\) (u ovom slučaju \(3\)) i stavlja kursor na njega.
- **NextL(4, L)** – Pokazuje na kursor koji pokazuje na `EndL(L)`, tako da će vratiti error.
- **PreviousL(1, L)** – Vraća prethodnika ćelije adrese \(1\) (u ovom slučaju \(0\)) i stavlja kursor na njega.
- **PreviousL(0, L)** – Nema prethodnika ćelije adrese \(0\), tako da vraća error.
- **LocateL(3, L)** – Provjerava vrijednosti unutar ćelija, počevši od ćelije \(0\). Kada pronađe vrijednost \(3\), vraća adresu.
- **LocateL(5, L)** – Provjerava vrijednosti unutar ćelija, počevši od ćelije \(0\). Pošto ne postoji, vraća `EndL(L)`.
- **Insert(1, 2, L)** – Prvo pomaknemo kursor na jedno polje više. Nakon toga, sve elemente sljedbenike prebacimo za jedno polje više, a na tu adresu ubacimo vrijednost \(1\).
- **Delete(2, L)** – Prvo izbrišemo vrijednost, sve elemente sljedbenike vratimo za jedno mjesto unatrag i pomaknemo kursor za jednu ćeliju unatrag.
- **RetrieveL(2, L)** – Vraća vrijednost s ćelije \(2\).
- **DeleteAllL(L)** – Stavlja kursor na ćeliju \(0\).
- **InitL(L)** – Makne sve elemente iz polja i stavlja kursor na ćeliju \(0\).

### 9. Nabrojite koje funkcije u implementaciji apstraktnog tipu podataka lista pomoću polja imaju linearnu složenost te objasnite zašto je tome tako.

- `LocateL`

- `InsertL` 

- `DeleteL`

  Jer se moraju kretati po polju, da bi našli taj element ili da bi pomakli sljedbenike elemenata

### 10. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija liste pomoću pokazivača?

Struktura je rekurzivna i sastoji se od zapisa koji sadrži:

- vrijednost elementa liste
- pokazivač na sljedeći element u listi

### 11. Zašto kažemo da je struktura podataka pomoću koje se provodi implementacija liste pomoću pokazivača rekurzivna?

Svaka ćelija sadrži pokazivač na sljedeći element. Na taj se način formira lanac povezanih ćelija, gdje svaka ćelija ima strukturu kao i prethodna, pa je zato rekurzivna.

### 12. Koji je drugi naziv za implementaciju liste pomoću pokazivača?

__Jednostruko vezana lista__

### 13. Objasnite kako se implementaciji liste pomoću pokazivača izvode funkcije (operacije) koje su nad istom definirane.

- **FirstL(L)** – Vraća pokazivač glave koji pokazuje na sljedeći element.
- **EndL(L)** – Stavlja pokazivač na prvi element i kreće se sve do zadnjeg elementa koji nema pokazivač na sljedeći element, tj. pokazuje na `NULL`.
- **NextL(p, L)** – Stavimo pokazivač na element `p` i provjeravamo ima li sljedbenika (tj. da mu pokazivač ne pokazuje na `NULL`). Ukoliko pokazuje na `NULL`, dobivamo error.
- **PreviousL(p, L)** – Stavimo pokazivač na prvi element i krećemo se po listi sve dok ne dođemo do elementa čiji je sljedbenik na poziciji `p`. Ako stavimo pokazivač na element čiji je prethodnik glava, dobivamo error.
- **LocateL(3, L)** – Pokazivač stavimo na prvi element i provjeravamo njegovu vrijednost. Ako vrijednost nije tražena, idemo na sljedbenik.
- **LocateL(5, L)** – Pokazivač ide sve dok ne dođe do elementa koji nema sljedbenika.
- **InsertL(1, p, L)** – Napravimo novu ćeliju s vrijednošću i pokazivačem. Pokazivačem idemo po elementima liste do elementa koji će biti prethodnik novog elementa. Zatim pokazivač s novog elementa postavimo na njegovog sljedbenika, a od prethodnika pokazivač preusmjerimo na novi element.
- **DeleteL(p, L)** – Idemo sve do prethodnika elementa `p`, preusmjerimo ga na budući sljedbenik i zatim izbrišemo element `p`.
- **RetrieveL(p, L)** – Vraća vrijednost na koju pokazivač pokazuje.
- **DeleteAll(p, L)** – Iz glave mičemo pokazivač na sljedeći element na koji je glava prije pokazivala, brišemo element i ponavljamo proces dok u glavi nije zapisan `NULL`.
- **InitL(L)** – Alocira glavu i postavlja pokazivač da pokazuje na `NULL`.

### 14. Nabrojite koje funkcije u implementaciji apstraktnog tipu podataka lista pomoću pokazivača imaju linearnu složenost te objasnite zašto je tome tako.

- `EndL`
- `PreviousL`
- `LocateL`
- `DeleteAllL`

Jer se moramo pokazivačima kretati po listi.

## 5. Apstraktni tip podataka stog

### 1. Što je apstraktni tip podataka stog?

Specijalna vrsta liste s restrigiranim skupom operacija. Niz istovrsnih elemenata, lista kod koje se čitanje, upisivanje i brisanje elemenata vrši samo na jednom kraju.

### 2. Gdje se kod apstraktnog tipa podataka stog izvršavaju operacije?

Kraj stoga na koji se upisuju, brišu i čitaju elementi zove se **vrh stoga**, dok se suprotni kraj stoga naziva **dno stoga**

### 3. Koji je drugi naziv za apstraktni tip podataka stog?

LIFO (_Last In, First Out_)

### 4. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka stog.

| **Funkcija/Procedura** | **Opis**                                                     |
| ---------------------- | ------------------------------------------------------------ |
| **TopS(S)**            | Funkcija koja vraća vrijednost elementa koji se trenutno nalazi na vrhu stoga |
| **PushS(x, S)**        | Procedura koja dodaje novi element s vrijednošću `x` na vrh stoga. |
| **PopS(S)**            | Procedura koja briše element s vrha stoga.                   |
| **InitS(S)**           | Procedura koja inicira prazan stog.                          |
| **IsEmptyS(S)**        | Logička funkcija koja odgovara na pitanje da li je stog prazan (vraća `true` ili `false`). |

### 5. Nabrojite primjere stoga.

CD, igračke PEZ bomboni, Lego kockice, palačinke (jedna na drugu), nasložene knjige

### 6. Koje funkcije iz apstraktnog tipa podataka lista mijenjaju funkcije TopS, PushS i PopS?

- TopS → RetrieveL(EndL(L,L),L)
- PushS → InsertL(x, EndL(L),L)
- PopS → DeleteL(PreviousL(EndL(L),L))

### 7. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija stoga pomoću polja?

- Jednodimenzionalno polje koje se puni od posljednjeg prema prvog elementu
- Kursor koji pokazuje na element iznad vrha stoga, tj. na element u polju koji je još neiskorišten

```c++
typedef int element;

struct st {
    elementtype elements[10000];
    element top;
};

typedef struct st stack;
```



### 8. Objasnite kako se implementaciji stoga pomoću polja izvode funkcije (operacije) koje su nad istim definirane.

Imamo polje, elementi su posloženi od posljednje ćelije prema 0, a na polje iznad zadnjeg popunjenog je kursor Top.

* `TopS(S)` - vraća vrijednost iz ćelije iznad $n+1$ kursora Top
* `PushS(4,S)` - stavlja vrijednost u ćeliju gdje pokazuje kursor i kursor pomiče za jedno polje manje $n-1$
* `PopS(S)` - stavlja kursor na jedno polje iznad $n-1$ i vraća vrijednost
* `IsEmptyS(S)` - ukoliko je adresa ćelije jednaka veličini polja, vraća `True`
* `InitS(S)` - stavlja kursor na $n$ ćeliju u polju

### 9. Koju složenost imaju funkcije u implementaciji apstraktnog tipu podataka stog pomoću polja?

Svi imaju složenost 1

### 10. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija stoga pomoću pokazivača?

Struktura podataka u koju se u ovoj implementaciji upisuju elementi stova slična je strukturi koja se koristi pri implementaciji liste pomoću pokazivača

- vrijednost elementa stoga
- pokazivač na sljedeći element u stogu

```c++
struct st {
    elementtype value;
    struct st *next;
}

typedef struct st stack;

typedef stack *element;
```



### 11. Objasnite kako se implementaciji stoga pomoću pokazivača izvode funkcije (operacije) koje su nad istim definirane.

- `TopS(S)` - pokazivač iz glave vraća vrijednost sljedbenika glave, odnosno elementa 1
- `PushS(S)` - pokazivač novog elementa usmjerimo na 1 element stoga i onda pokazivač iz glave usmjerimo na novi element
- `PopS(S)` - pokazivač iz glave usmjerimo na sljedeći element u stogu i brišemo prvi element
- `InitS(S)` - alocira glavu i stavlja pokazivač na `NULL`
- `IsEmptyS(S)` - provjerava da li pokazivač iz glave usmjeren na `NULL`

### 12. Koju složenost imaju funkcije u implementaciji apstraktnog tipu podataka stog pomoću pokazivača?

$O(1)$

### 13. Objasnite prefiksni, infiksni i postfiksni zapis aritmetičkog izraza.

| **Zapis**      | **Opis**                                                     | **Primjeri**                                 |
| -------------- | ------------------------------------------------------------ | -------------------------------------------- |
| **Prefiksni**  | Operator dolazi prije operanada. Nema potrebe za zagradama jer redoslijed operacija određuje pozicija operatora. | `A + B → +AB`<br>`(A + B) * C → *+A B C`     |
| **Infiksni**   | Operator se nalazi između operanada. Koriste se zagrade za složenije izraze. | `A + B`                                      |
| **Postfiksni** | Operator dolazi nakon operanada. Nema potrebe za zagradama jer redoslijed operacija definira pozicija operatora. | `A + B → A B +`<br>`(A + B) * C → A B + C *` |

### 14. Objasnite prioritete operatora i redoslijed njihove evaluacije kod pretvaranja infiksnog zapisa u postfiksni zapis.

| **Operator**   | **Prioritet** | **Asocijativnost** |
| -------------- | ------------- | ------------------ |
| `()` `[]` `{}` | 1             | -                  |
| `^`            | 2             | S desna na lijevo  |
| `*` `/`        | 3             | S lijeva na desno  |
| `+` `-`        | 4             | S lijeva na desno  |

### 15. Objasnite algoritam pretvaranja infiksnog zapisa u postfiksni zapis pomoću stoga.

Neka je T znak u infiksnom izrazu

1. Ako je T operand, dodaj ga u postfiksni zapis
2. Ako je stog prazan ili se u vrhu istog nalazi lijeva zagrada, dodaj T na vrh stoga
3. Ako je T lijeva zagrada, dodaj T na vrh stoga
4. Ako je T desna zagrada
   1. obriši znak sa vrha stoga te ga dodaj u postfiksni zapis
   2. ponavljaj korak 4.1. sve dok ne naiđeš na lijevu zagradu
   3. izbriši lijevu zagradu s vrha stoga
5. Ako T ima veći prioritet od znaka koji se nalazi na vrhu stoga, dodaj T na vrh stoga
6. Ako T ima manji prioritet od znaka koji se nalazi na vrhu stoga
   1. obriši znak sa vrha stoga te ga dodaj u postfiksni zapis
   2. usporedi prioritet znaka T i znaka koji se nakon provedbe koraka 6.1. nalazi na vrhu stoga te primijeni sljedeći odgovarajući korak
7. Ako T ima isti prioritet kao i znak koji se nalazi na vrhu stoga, primjeni pravilo asocijaltivnosti
   1. u slučaju asocijativnosti s lijeva na desno
      1. obriši znak sa vrha stoga te ga dodaj u postfiksni zapis
      2. dodaj T na vrh stoga
   2. u slučaju asocijativnosti s desna na lijevo
      1. dodaj T na vrh stoga
8. Kad dođeš do kraja izraza
   1.  obriši znak sa vrha stoga te ga dodaj u postfiksni zapis
   2. ponavljaj korak 8.1 sve dok stog ne postane prazan

### 16. Objasnite algoritam pretvaranja infiksnog zapisa u prefiksni zapis pomoću stoga.

1. preokreni infiksni zapis
2. lijevu zagradu zamijeni desnom i obrnuto
3. primijeni proceduru za pretvaranje infiksnog zapisa u postfiksni zapis
4. preokreni postfiksni zapis

## 6. Apstraktni tip podataka red

### 1. Što je apstraktni tip podataka red?

Specijalna vrsta liste sa restrigiranim skupom operacija. Prema tome, red je također niz istovrsnih elemenata.

### 2. Gdje se kod apstraktnog tipa podataka red izvršavaju operacije?

Kod reda se umetanje elemenata vrši na jednom kraju, a čitanje i brisanje elemenata na drugom kraju. Kraj reda na kojem se vrši umetanje elemenata se naziva **začelje reda** (eng. _rear_), dok se kraj na kojem se elementi brišu i čitaju naziva **čelo reda** (eng. _front_).

### 3. Koji je drugi naziv za apstraktni tip podataka red?

**FIFO-lista** (_First In, First Out_)

### 4. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka red.

| Funkcija/Procedura | Opis                                                         |
| ------------------ | ------------------------------------------------------------ |
| **FrontQ(Q)**      | Funkcija koja vraća vrijednost elementa koji se trenutno nalazi na čelu reda |
| **EnQueueQ(x, Q)** | Procedura koja dodaje novi element s vrijednošću `x` na začelje reda |
| **DeQueueQ(Q)**    | Procedura koja briše element s čela reda                     |
| **InitQ(Q)**       | Procedura koja inicira prazan red                            |
| **IsEmptyQ(Q)**    | Logička funkcija koja odgovara na pitanje je li red prazan   |

### 5. Koje funkcije iz apstraktnog tipa podataka lista i apstraktnog tipa podataka stog mijenjaju funkcije EnQueueQ, DeQueueQ i FrontQ?

- EnqueueQ → Insert(x,End(L),L) → PushS(x,S)
- DequeueQ → Delete(FirstL(L),L) → PopS(S) (koristeći petlju)
- FrontQ → RetrieveL(FirstL(L),L) → TopS(S) (koristeći petlju)

### 6. Zašto kod implementacije apstraktnog tipa podataka red pomoću polja isto mora biti cirkularno?

Cirkularno polje se koristi u implementaciji reda kako bi se efikasno iskoristio prostor. Kada dođemo do kraja polja, možemo nastaviti dodavati elemente na početak, što izbjegava potrebu za pomicanjem elemenata i omogućava stalno korištenje istog prostora. Tako se red ponaša kao beskonačan krug u kojem dodavanje i uklananje elemenata ostaje brzo i jednostavno.

### 7. Objasnite kako se postiže cirkularnost polja.

Cirkularnost polja postiže se tako da pokazivači **front** i **rear** _preskoče_ na početak polja kada dosegnu kraj, pomoću $(\text{indeks} + 1) \mod \text{veličina\_polja}$

### 8. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija reda pomoću cirkularnog polja?

- Jednodimenzionalnog cirkularnog polja
- dva kursora od kojih jedan pokazuje element na čelu reda, a drugi element na začelju reda

```cpp
typedef int element;

struct qu {
    elementtype elements[10000];
    element front, rear;
};
typedef struct qu queue;
```



### 9. Objasnite kako se implementaciji reda pomoću cirkularnog polja izvode funkcije (operacije) koje su nad istim definirane.

| Funkcija/Procedura | Opis                                                         |
| ------------------ | ------------------------------------------------------------ |
| **FrontQ(Q)**      | Vraća vrijednost na koju je postavljen kursor `front`        |
| **EnQueueQ(3, Q)** | Mičemo pokazivač `rear` za jedno mjesto više i u to polje upisujemo vrijednost `3` |
| **DeQueueQ(Q)**    | Mičemo pokazivač `front` za jedno mjesto više                |
| **IsEmptyQ(Q)**    | Gleda jesu li `front` i `rear` kursori jedan do drugog (`AddOne(rear) == front`) |
| **IsFullQ(Q)**     | Gleda je li `rear` na polju manje od `front` (`AddOne(AddOne(rear)) == front`) |
| **InitQ(Q)**       | Pomiče kursore na početak i kraj polja (`front` na `0`, `rear` na `n`) |

### 10. Objasnite kad je red kod implementacije istog pomoću cirkularnog polja pun, a kad je prazan.

- Red je pun kada se kursor rear nalazi na jednom polju manje od kursora front
- Red je prazan kada se kursor front i rear nalaze jedan do drugog u prirodnom redoslijedu

### 11. Kako provjeravamo je li red kod implementacije istog pomoću cirkularnog polja prazan?

_Vidi pitanje 10._

### 12. Kako provjeravamo je li red kod implementacije istog pomoću cirkularnog polja pun?

_Vidi pitanje 10._

### 13. Koju složenost imaju funkcije u implementaciji apstraktnog tipu podataka red pomoću cirkularnog polja?

$O(1)$

### 14. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija reda pomoću pokazivača?

Struktura koja se koristi je slična strukturi koja se koristi pri implementaciji liste pomoću pokazivača. Glavna razlika je što zaglavlje kod reda mora sadržavati dva pokazivača: jedan na početak, a drugi na kraj reda. Kako bi se izbjeglo da operacije predugo traju, novi se elementi dodaju na kraj, a brišu s početka vezane liste (reda).

```c++
struct qu {
    elementtype value;
    struct qu *next;
};
struct que {
    struct qu *front, *rear;
}
typedef struct que queue;
typedef struct qu *element;
```



### 15. Objasnite kako se implementaciji reda pomoću pokazivača izvode funkcije (operacije) koje su nad istim definirane.

| Funkcija/Procedura | Opis                                                         |
| ------------------ | ------------------------------------------------------------ |
| **FrontQ(Q)**      | Pokazivač `front` pokazuje na glavu, a glava pokazuje na prvi element i tada pročitamo njegovu vrijednost |
| **EnQueueQ(3, Q)** | Napravimo novi element, upišemo mu vrijednost, pokazivač tada zadnjeg elementa usmjerimo na novi element, a pokazivač `rear` postavimo na novi element |
| **DeQueueQ(Q)**    | Pokazivač `front` postavimo na sljedeći element              |
| **IsEmptyQ(Q)**    | Gleda je li `rear == front`, odnosno jesu li oba na `NULL`   |
| **InitQ(Q)**       | Kreiramo glavu, kreiramo pokazivače `rear` i `front`, te oba usmjerimo na glavu |

### 16. Koju složenost imaju funkcije u implementaciji apstraktnog tipu podataka red pomoću pokazivača?

$O(1)$

### 17. Što je apstraktni tip podataka dvostrani red?

eng. *deque, dequeue, double ended queue*

Omogućava izvršavanje operacije čitanja, umetanja i brisanja sa oba kraja reda. Implementacija je moguća pomoću cirkularnog polja i pomoću dvostruko vezane liste. Može se koristiti kao red i stog. Primjene: redo/undo operacije, provjera je li riječ palindrom, A-steal kod raspoređivanja poslova u višeprocesorskom radu, itd.

### 18. Nabrojite i objasnite varijante apstraktnog tipa podataka dvostrani red.

Postoje dvije varijante:

- **Sa ograničenjem na umetanje** (eng. _input restricted deque_) u kojem se operacija umetanja može izvoditi samo na jednom od krajeva, a operacije brisanja na oba kraja dvostranog reda
- **Sa ograničenjem na brisanje** (eng. _output restricted deque_) u kojem se operacije brisanja može izvoditi samo na jednom od krajeva, a operacije umetanja na oba kraja dvostranog reda

### 19. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka dvostrani red.

| Funkcija/Procedura        | Opis                                                         |
| ------------------------- | ------------------------------------------------------------ |
| **EnQueueFrontDQ(x, DQ)** | Procedura koja dodaje novi element s vrijednošću `x` na čelo reda |
| **EnQueueRearDQ(x, DQ)**  | Procedura koja dodaje novi element s vrijednošću `x` na začelje reda |
| **DeQueueFrontDQ(DQ)**    | Procedura koja briše element s čela reda                     |
| **DeQueueRearDQ(DQ)**     | Procedura koja briše element sa začelja reda                 |
| **IsEmptyDQ(DQ)**         | Logička funkcija koja odgovara na pitanje je li dvostrani red prazan |
| **GetFrontDQ(DQ)**        | Funkcija koja vraća vrijednost elementa koji se trenutno nalazi na čelu reda |
| **GetRearDQ(DQ)**         | Funkcija koja vraća vrijednost elementa koji se trenutno nalazi na začelju reda |

### 20. Objasnite kako se implementaciji dvostranog reda pomoću cirkularnog polja izvode funkcije (operacije) koje su nad istim definirane.

| Funkcija/Procedura        | Opis                                                         |
| ------------------------- | ------------------------------------------------------------ |
| **EnQueueFrontDQ(2, DQ)** | Ubacimo vrijednost na ćeliju `0`, premjestimo (front i) `rear` kursore na tu ćeliju; ako dodajemo novi element (EnQueueRearDQ), ubacimo vrijednost i premjestimo kursor `rear` |
| **DeQueueFrontDQ**        | Prebacimo kursor za ćeliju više; ako ubacujemo novi element na mjesto gdje je nekad bio element, ubacimo njegovu vrijednost i premjestimo kursor na njega |
| **EnQueueFrontDQ**        | (Ako ima već vrijednost na `0`) Upišemo vrijednost na ćeliju adrese `n` i premjestimo kursor na njega |
| **DeQueueFrontDQ**        | (Ako je ostao samo ovaj element na adresi `n`) `rear` i `front` će sada pokazivati na isti element |
| **Red je pun**            | Kada je `(front == 0 && rear == n-1) || (front == rear + 1)` |

### 21. Što je dvostruko vezana lista?

Dvostruko vezana lista je ATP kojem svaki element, osim vrijednosti, sadrži dva pokazivača:

- **pokazivač na sljedeći element** (sljedbenik)
- **pokazivač na prethodni element** (prethodnik)

### 22. Nabrojite prednosti i nedostatke dvostruko vezane liste.

| **Prednosti**                                                | **Nedostaci**                                                |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Lista se može pretraživati u oba smjera                      | Potreban je dodatni memorijski prostor za pokazivač na sljedeći element liste (može se razriješiti pomoću XOR dvostruko vezane liste) |
| Omogućava učinkovitije izvršavanje operacije umetanja, brisanja i pronalaženja prethodnika elementa liste | Kod izvršavanja operacija, potrebno je vršiti preusmjeravanje još jednog pokazivača što iziskuje dodatnih 1-2 koraka |

### 23. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija dvostruko vezane liste?

Pored podatkovne vrijednosti i pokazivača na sljedeći element liste (vrijedi za jednostruko vezanu listu), svaki element sadrži pokazivač i na prethodni element liste

```c++
struct cvor {
    int podaci;
    struct cvor *sljedeci;
    struct cvor *prethodni;
};

struct cvor *glava, *rep;
struct cvor *novicvor, *privremeni;
```

### 24. Objasnite operaciju dodavanja novog elementa na početak, kraj i određenu poziciju dvostruko vezane liste.

### 24. Operacije dodavanja u dvostruko vezanu listu

| Operacija                         | Objašnjenje                                                  |
| --------------------------------- | ------------------------------------------------------------ |
| **Umetanje na početak**           | `novicvor` pokazuje na trenutnu `glava` kao `sljedeci`; `glava->prethodni` pokazuje na `novicvor`, a `glava` se ažurira na `novicvor`. |
| **Umetanje na kraj**              | `novicvor` pokazuje na `NULL` kao `sljedeci`; trenutni `rep->sljedeci` pokazuje na `novicvor`, a `rep` se ažurira na `novicvor`. |
| **Umetanje na određenu poziciju** | Pronađe se pozicija pomoću `privremeni`, `novicvor->sljedeci` pokazuje na `privremeni->sljedeci`, a `novicvor->prethodni` na `privremeni`. Pokazivači susjednih čvorova se ažuriraju. |

### 25. Objasnite operaciju brisanja elementa sa početka, kraja i određene pozicije dvostruko vezane liste.

### 25. Operacije brisanja u dvostruko vezanoj listi

| Operacija                         | Objašnjenje                                                  |
| --------------------------------- | ------------------------------------------------------------ |
| **Brisanje sa početka**           | `privremeni = glava`; `glava` se ažurira na `glava->sljedeci`, a `glava->prethodni` postavlja se na `NULL`. `privremeni` se briše. |
| **Brisanje sa kraja**             | `privremeni = rep`; `rep` se ažurira na `rep->prethodni`, a `rep->sljedeci` postavlja se na `NULL`. `privremeni` se briše. |
| **Brisanje sa određene pozicije** | Pronađe se čvor pomoću `privremeni`, pokazivači `privremeni->prethodni->sljedeci` i `privremeni->sljedeci->prethodni` se ažuriraju, a `privremeni` se briše. |

### 26. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija dvostranog reda pomoću dvostruko vezane liste?

- čvor
  - podatak
  - pokazivač na sljedeći čvor
  - pokazivač na prethodni čvor
- pokazivač na početak reda (front)
- pokazivač na kraj reda (rear)

## 7. Apstraktni tip podataka općenito (uređeno) stablo

### 1. Što je apstraktni tip podataka općenito (uređeno) stablo?

- hijerarhijsko uređivanje podataka (nadređeni - podređeni, roditelj - dijete)
- npr. stablo T je neprazni skup podataka istog tipa koje nazivamo **čvorovi**

### 2. Koja je razlika između apstraktnih tipova podataka lista i općenito (uređeno) stablo?

- **lista** - linearno uređivanje podataka
- **stablo** - hijerarhijsko uređivanje podataka (nadređeni - podređeni, roditelj - dijete)

### 3. Objasnite pojmove čvor, korijen, potomak, predak, brat, list i unutarnji čvor u kontekstu apstraktnog tipa podataka općenito (uređeno) stablo.

**Stablo T** je neprazni konačni skup podataka istog tipa koje nazivamo **čvorovi**. Istaknuti **čvor r** naziva se **korijen** (_root_) stabla T. Ostali čvorovi grade konačni nit T<sub>1</sub>,T<sub>2</sub>,...,T<sub>k</sub> od 0 ili više manjih stabala. Manja stabla **T<sub>i</sub>** nazivaju se **podstabla** korijena **r**. Korijeni r<sub>i</sub> od T<sub>i</sub> su **djeca** od r, a r je njihov **roditelj**. **Korijen r nema roditelja**, a svaki preostali čvor ima točno jednog roditelja. **Potomak čvora x** se definira na sljedeći način:

- svako dijete čvora x je njegov potomak
- ako je čvor potomak čvora x, onda su i djeca čvora y potomci čvora x

Djeca istog čvora su **braća**. Čvor koji nema djece naziva se **list**. Čvor koji ima barem jedno dijete naziva se **unutarnji čvor**.

### 4. Objasnite pojmove stupanj čvora, stupanj stabla, razina čvora, dubina čvora, put i visina čvora u kontekstu apstraktnog tipa podataka općenito (uređeno) stablo.

**Stupanj čvora** je broj njegovih podstabala. **Stupanj stabla** je maksimalan stupanj svih čvorova. **Razina čvora** određuje se iz sljedeće definicije:

- korijen je razine 0
- razina djece čvora n iznosi n+1

**Dubina čvora** je duljina jedinstvenog puta od korijena od tog čvora. **Put** od čvora x<sub>1</sub> do čvora x<sub>n</sub> definira se:

- niz čvorova x<sub>1</sub>, x<sub>2</sub>,...,x<sub>n</sub> takvih da je x<sub>p</sub> roditelj od x<sub>p-1</sub> ($p=1,...,n-1$)
- duljina puta iznosi $n-1$ ($n$ - broj čvorova puta)

**Visina čvora** je duljina najduljeg puta od čvora do lista.

### 5. Navedite i objasnite primjere općenitog (uređenog) stabla.

Sadržaj knjige može se predstaviti uređenim stablom. Struktura države, obiteljsko stablo,...

Građa aritmetičkog izraza se može prikazati stalom. Čvorovi bez djece predstavljaju operande, a ostali čvorovi računske operacije. Uređenost stabla je važna ako su operacije nekomutativne, npr. izraz $(a + b) \cdot (a + \sqrt{c})$.

### 6. Čemu služe algoritmi za obilazak stabla?

Algoritam kojim posjećujemo čvorove stabla tako da svaki čvor posjetimo točno jednom. Namjena:

- obrada nad svim čvorovima
- uspostavljanje linearnog uređenja među čvorovima

Obilasci se zadaju rekurzivno.

### 7. Nabrojite i objasnite algoritme za obilazak stabla.

Najčešći obilasci su: 

- **preorder** (korijen, lijevi čvor, desni čvor)
- **inorder** (lijevi čvor, korijen, desni čvor)
- **postorder** (lijevi čvor, desni čvor, korijen)

Za svaki od algoritama obilaska, redoslijed posjećivanja čvorova u konkretnom stablu jednoznačno je određeno rekurzivnom definicijom tog algoritma

### 8. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka općenito (uređeno) stablo.

| **Funkcija/Procedura**  | **Opis**                                                     |
| ----------------------- | ------------------------------------------------------------ |
| `ParentT(n, T)`         | Vraća roditelja čvora `n`, a ako je `n` korijen, vraća null-čvor `Λ`. |
| `FirstChildT(n, T)`     | Vraća prvo (lijevo) dijete čvora `n`. Ako je `n` list, vraća null-čvor `Λ`. |
| `NextSiblingT(n, T)`    | Vraća sljedećeg brata čvora `n`, ako postoji. Ako je `n` najdesnije dijete, vraća null-čvor `Λ`. |
| `LabelT(n, T)`          | Vraća oznaku (vrijednost) koju sadrži čvor `n`.              |
| `RootT(T)`              | Vraća korijen stabla `T`.                                    |
| `CreateT(x, n, T)`      | Dodaje `x` kao dijete čvora `n`.                             |
| `ChangeLabelT(x, n, T)` | Mijenja oznaku čvora `n` u stablu `T` na vrijednost `x`.     |
| `DeleteT(n, T)`         | Briše čvor `n` i sve njegove potomke iz stabla `T`.          |
| `InitT(x, T)`           | Inicijalizira stablo `T` s korijenom `x`.                    |

### 9. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija općenitog (uređenog) stabla temeljem veze čvor-roditelj?

Zasniva se na tome da svakom čvoru eksplicitno zapišemo njegovog roditelja. Moguće su razne varijante zbog različitih prikaza skupa čvorova. Uzimamo za imena čvorova cijele brojeve $0,1,2,...,n-1$ gdje je $n$ broj čvorova. Stablo se prikazuje poljima, $i$-te ćelije polja opisuju $i$-ti čvor i u njima piše oznaka tog čvora odnosno kursor na roditelja. Kursor `root` pokazuje gdje je korijen stabla. Ako je `MAXNODES` veći od stvarnog broja čvorova, neke ćelije su slobodne. One se mogu označiti tako da im se upiše nemoguća vrijednost.

```c++
#define MAXNODES ...
#define LAMBDA -1

typedef int node;
typedef struct {
    node root;
    labeltype label[MAXNODES];
    node parent[MAXNODES];
} TREE;
```

### 10. Objasnite implementaciju općenitog (uređenog) stabla temeljem veze čvor-roditelj.

_Vidi pitanje prije_

### 11. Nabrojite i objasnite prednosti i mane implementacije općenitog (uređenog) stabla temeljem veze čvor-roditelj.

Opisana struktura dobro podržava operacije `Parent` i `Label`. Ostale operacije zahtjevaju pretraživanje cijelog polja. Mana je da se ne pamti redoslijed braće - stablo je zapravo neuređeno. Moguće je uvesti dodatno pravilo da su braća poredana po svojim imenima (indeksima). Tada u polju tražimo ćeliju nakon $i$-te u kojoj je upisan isti roditelj. Ova implementacija je dobra ako nema mnogo ubacivanja i/ili izbacivanja čvorova, nije potrebna uređenost stabla i pretežno se koriste operacije `Parent` i `Label`.

### 12. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija općenitog (uređenog) stabla „prvo dijete - sljedeći brat“?

Stablo se implementira pomoću polja čiji element, osim oznake čvora, sadrži i čvor koji je prvo dijete promatranog čvora koji je sljedeći brat zadanog čvora.

```c++
struct elem {
    labeltype label;
    int firstchild,nextsibling;
};
struct tr {
    struct elem elements[10000];
    int first;
}
typedef struct tr tree;
typedef int node;
```

### 13. Objasnite implementaciju općenitog (uređenog) stabla „prvo dijete - sljedeći brat“.

_vidi pitanje prije_

### 14. Nabrojite i objasnite prednosti i mane implementacije općenitog (uređenog) stabla „prvo dijete - sljedeći brat“.

Sve operacije osim `Parent` se mogu efikasno implementirati. Ova implementacija je pogodna kada ima puno ubacivanja i/ili izbacivanja čvorova ili kad se više stabala spaja u veće ili za intezivnu uporabu veza roditelj-dijete. U implementaciji se može dodati cjelobrojna varijabla (_avail_) kao globalni kursor koji će pokazivati na vezanu listu slobodnih ćelija u polju.

## 8. Apstraktni tip podataka binarno stablo

### 1. Što je apstraktni tip podataka binarno stablo?

Binarno stablo B je konačan skup podataka istog tipa koje nazivamo **čvorovi**. Za binarno stablo vrijedi sljedeće:

- B je **prazan skup** (prazno binarno stablo) ili
- postoji istaknuti čvor **k** koji se naziva **korijen** stabla B, a preostali čvorovi tvore uređeni par (B~L~,B~D~) manjih binarnih stabala

Definicija binarnog stabla je rekurzivna. Ako B sadrži korijen k, tada se definicija primjenjuje i na manja binarna stabla B~L~ i B~D~. To je uređena trojka. Nije specijalizacijea općenitog stabla već zaseban ATP. Manja binarna stabla B~L~ i B~D~ nazivaju se **lijevo** i **desno podstablo** od B. Korijen od B~L~ (ako postoji) je **lijevo dijete** od k, korijen od B~D~ (ako postoji) je **desno dijete** od k, a k je njihov **roditelj**. Ako čvor u B ima samo jedno dijete, tada nije svejedno da li je ono lijevo ili desno. Svako od podstabala B~L~ i B~D~ može imati svoja manja podstabla.

### 2. Objasnite po čemu se razlikuju općenito (uređeno) i binarno stablo.

| Tip stabla | Broj djece     | Uređenost djece                    | Struktura                   | Primjena                                    |
| ---------- | -------------- | ---------------------------------- | --------------------------- | ------------------------------------------- |
| Općenito   | Bilo koji broj | Bilo koji redoslijed               | Neograničen broj podstabala | Za fleksibilnije hijerarhije                |
| Binarno    | Najviše dva    | Jasno podijeljeno (lijevo i desno) | Najviše dva podstabla       | Efikasno pretraživanje i strukture podataka |

### 3. Nabrojite i objasnite koje se funkcije (operacije) izvode na apstraktnom tipu podataka binarno stablo.

| Funkcija/Procedura      | Opis                                                         |
| ----------------------- | ------------------------------------------------------------ |
| `ParentB(n, B)`         | Vraća roditelja čvora `n`, a ako je `n` korijen, vraća null-čvor `Λ`. |
| `LeftChild(n, B)`       | Vraća lijevo dijete čvora `n`. Ako čvor `n` nema lijevog djeteta, vraća null-čvor `Λ`. |
| `RightChild(n, B)`      | Vraća desno dijete čvora `n`. Ako čvor `n` nema desnog djeteta, vraća null-čvor `Λ`. |
| `LabelB(n, B)`          | Vraća oznaku (vrijednost) koju sadrži čvor `n`.              |
| `ChangeLabelB(x, n, B)` | Mijenja oznaku čvora `n` u stablu `B` na vrijednost `x`.     |
| `RootB(B)`              | Vraća korijen binarnog stabla `B`. Ako je stablo prazno, vraća null-čvor `Λ`. |
| `CreateLeftB(x, n, B)`  | Dodaje `x` kao lijevo dijete čvora `n`. Ako čvor `n` već ima lijevo dijete, javlja poruku pogreške. |
| `CreateRightB(x, n, B)` | Dodaje `x` kao desno dijete čvora `n`. Ako čvor `n` već ima desno dijete, javlja poruku pogreške. |
| `DeleteB(n, B)`         | Briše čvor `n` i sve njegove potomke iz binarnog stabla `B`. |
| `InitB(x, B)`           | Inicijalizira binarno stablo `B` s korijenom `x`.            |

### 4. Objasnite kako se čvorovi binarnog stabla mogu pohraniti u polje.

Primjenjuju se u svrhu implementacije  **potpunih (balansiranih) binarnih stabala**. Na svim razinama (osim posljednje) nalaze se svi čvorovi. Čvorovi na posljednjoj razini _pomaknuti_ su na lijevu stranu. Imenovanje (numeriranje) čvorova vrši se po razinama.

|               |        Korijen pohranjen u ćeliji 0        |      Korijen pohranjen u ćeliji 1      |
| ------------- | :----------------------------------------: | :------------------------------------: |
| Lijevo dijete |                   $2i+1$                   |                  $2i$                  |
| Desno dijete  |                   $2i+2$                   |                 $2i+1$                 |
| Roditelj      | $\left\lfloor \frac{i-1}{2} \right\rfloor$ | $\left\lceil \frac{i}{2} \right\rceil$ |

### 5. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija binarnog stabla pomoću polja?

Element polja se sastoji od:

- vrijednosti koja predstavlja oznaku
- logičke vrijednosti koja označava da li je određeni element polja iskorišten ili nije

```c++

```

### 6. Objasnite kako se implementaciji binarnog stabla pomoću polja izvode funkcije (operacije) koje su nad istim definirane.

_Pogledaj video predavanja i prezentaciju_

### 7. Nabrojite koje funkcije u implementaciji binarnog stabla pomoću polja imaju linearnu složenost te objasnite zašto je tome tako.

`DeleteB` - zato što ne možemo direktno izbrisati djecu čvora, nego moramo po redoslijedu brisati njegovu djecu (s lijeva na desno) pa onda i njega samog

### 8. Od čega se sastoji struktura podataka pomoću koje se provodi implementacija binarnog stabla pomoću pokazivača?

_Prirodniji prikaz_ i implementacija binarnog stabla. Čvor se sastoji od oznake i dva pokazivača - na lijevo i desno dijete.

```c++
struct tbstablo {
    int oznaka;
    tbstablo *lijevo, *desno;
};
typedef tbstablo* cvor;
typedef cvor btree;
```

### 9. Objasnite kako se implementaciji binarnog stabla pomoću pokazivača izvode funkcije (operacije) koje su nad istim definirane.

_Pogledaj video predavanja i prezentaciju_

### 10. Nabrojite koje funkcije u implementaciji binarnog stabla pomoću pokazivača imaju linearnu složenost te objasnite zašto je tome tako.

`ParentB` - zato što moramo pretražiti stablo i to slijeva na desno da dođemo do elementa čiji pokazivač pokazuje na željeni čvor

`DeleteB` - isto kao za `ParentB`, moramo prvo svu djecu izbrisati da bi izbrisali njega

## 9. Primjena binarnih stabala

### 1. Objasnite algoritam pretvaranja infiksnog zapisa u postfiksni zapis pomoću binarnog stabla.

Imamo označeno stablo (eng. _expression tree_), njegovi listovi su operandi (najčešće brojevi), a korijen i unutarnji čvorovi su operatori. Korijen je operator koji se posljednji izvodi. 

- **Postorder** obilazak (**prođe čvor s desne strane**) označenog stabla daje postfiksni zapis.

### 2. Objasnite algoritam pretvaranja infiksnog zapisa u prefiksni zapis pomoću binarnog stabla.

* **Preorder** obilazak (**prođe čvor s lijeve strane**) označenog stabla daje preorder zapis.

### 3. Nabrojite i objasnite svojstva binarnog stabla pretraživanja.

Čvorovi imaju implementirani uređaj $<$ odnosno $>$. Vrijednost lijevog djeteta je manja od korijena, a vrijednost desnog djeteta je veća od korijena.

### 4. Objasnite algoritam dodavanja novog elementa (čvora) u binarno stablo pretraživanja.

Kreće se od korijena. Ako je vrijednost koju želimo dodati manja od oznake promatranog čvora, onda u sljedećem koraku promatramo lijevo dijete promatranog čvora. Ako je vrijednost koju želimo dodati veća od oznake promatranog čvora, onda u sljedećem koraku promatramo desno dijete promatranog čvora. Ako je vrijednost koju želimo dodati jednaka oznaci promatranog čvora, onda se ista ne dodaje u stablo. Ako se vrijednost koju želimo dodati ne nalazi u stablu, ista se zapisuje u novi čvor te algoritam završava sa radom.

### 5. Objasnite algoritam traženja vrijednosti u binarnom stablu pretraživanja.

Kreće se od korijena. Ako je tražena vrijednost manja od oznake promatranog čvora, onda se prelazi na njegovo lijevo dijete. Ako je tražena vrijednost veća od oznake promatranog čvora, onda se vraća informacija da zadana vrijednost postoji u stablu. Ako algoritam dođe do razine lista i ne pronađe traženu vrijednost, isti o tome obavještava korisnika te završava sa radom.

### 6. Objasnite algoritam brisanja elementa (čvora) iz binarnog stabla pretraživanja.

Ako je čvor koji brišemo list, jednostavno ga uklonimo iz stabla. Obzirom da unutarnje čvoreve ne možemo obrisati, moramo problem brisanja unutarnjeg čvora svesti na problem brisanja lista što činimo putem zamjene vrijednosti.

Ako unutarnji čvor ima samo jedno dijete, onda se u unutarnji čvor zapisuje vrijednost iz čvora djeteta te se nakon toga briše list.

Ako unutarnji čvor ima dvoje djece, onda se u unutarnji čvor zapisuje vrijednost njegovog inorder prethodnika (čvor sa najvećom vrijednošću u lijevom podstablu) ili inorder sljedbenika (čvor sa najmanjom vrijednošću u desnom podstablu).

### 7. Nabrojite i objasnite svojstva hrpe.

Potpuno (balansirano) binarno stablo koje ima sljedeća svojstva:

- na svim razinama osim posljednje i pretposljednje svi čvorovi imaju po dvoje djece
- oznake čvorova su podaci nekog tipa na kojem je definiran totalni uređaj ($<$ odnosno $>$)
- oznake se dodaju sa lijeva na desno
- dozvoljena je operacija brisanja korijena stabla koja se izvodi na način da nakon brisanja stablo i dalje zadržava obilježja hrpe

### 8. Koje vrste hrpa postoje te po čemu se iste razlikuju?

- **max hrpa** - oznake oba djeteta su manje od oznake njihova roditelja
- **min hrpa** - oznake oba djeteta su veće od oznake njihova roditelja

### 9. Objasnite algoritam dodavanja novog elementa (čvora) u min (max) hrpu.

* **Min hrpa** - čvor se stavlja na prvo prazno mjesto u posljednjoj razini binarnog stabla. Provjerava se da li je vrijednost njegove oznake manja od oznake njegova roditelja te ukoliko jest, zamijene im se mjesta. Prethodni korak se ponavlja za novododani čvor sve dok isti ne postane korijen ili dok ne dođe do situacije da njegov roditelj ima manju oznaku od njega
* **Max hrpa** - čvor se stavlja na prvo prazno mjesto u posljednjoj razini binarnog stabla. Provjerava se da li je vrijednost njegove oznake veća od oznake njegova roditelja te ukoliko jest, zamijene im se mjesta. Prethodni korak se ponavlja za novododani čvor sve dok isti ne postane korijen ili dok ne dođe do situacije da njegov roditelj ima veću vrijednost od njega.

### 10. Objasnite algoritam brisanja korijena iz min (max) hrpe.

* **Min hrpa**
  * obriše se posljednji čvor stabla, a njegova oznaka se prepiše u korijen stabla
  * korijen postane promatrani čvor
  * utvrđuje se da li u stablu postoji situacija da bilo koje dijete promatranog čvora ima oznaku čija je vrijednost manja od oznake promatranog od oznake promatranog čvora (u ovom kontekstu roditelja) te ukoliko postoji, zamijene im se mjesta
  * promatrani čvor postaje onaj sa većom vrijednosti
  * prethodna dva koraka se ponavljaju sve dok promatrani čvor ne postane list ili dok njegova djeca nemaju oznake čije su vrijednosti veće od vrijednosti njegove oznake
* **Max hrpa**
  * obriše se posljednji čvor stabla, a njegova oznaka se prepiše u korijen stabla
  * korijen postane promatrani čvor
  * utvrđuje se da li u stablu postoji situacija da bilo koje dijete promatranog čvora ima oznaku čije je vrijednost veća od oznake promatranog čvora (u ovom kontekstu roditelja) te ukoliko postoji, zamijene im se mjesta
  * promatrani čvor postaje onaj sa manjom vrijednosti
  * prethodna dva koraka se ponavljaju sve dok promatrani čvor ne postane list ili dok njegova djeca nemaju oznake čije su vrijednosti manje od vrijednosti njegove oznake

### 11. Objasnite algoritam sortiranja pomoću hrpe (eng. heap sort).

* formiramo hrpu
* brišemo najdesniji list u posljednjoj razini i zamijenimo vrijednosti korijena i zadnjeg lista pa dalje sortiramo hrpu
  * ako imamo dva broja, biramo onaj koji je veći ili manji, ako su isti, idemo na lijevo
* izbrisane vrijednosti formiraju poredane elemente

### 12. Objasnite složenost algoritma sortiranja pomoću hrpe (eng. heap sort).

Sortiranje liste koje se temelji na algoritmu dodavanja i brisanja iz hrpe naziva se **heap sort** i jedan je od boljih algoritama sortiranja (složenost mu je $O(n \ log \ n)$, ali je sporiji od _QuickSorta_ i _MergeSorta_)

### 13. Objasnite specifičnosti implementacije hrpe.

Za hrpu je idealna implementacija binarnog stabla pomoću polja. U hrpi se uvijek stablo puni tako da se u polju u kojem je stablo zapisano elementi nalaze u prvih $n$ ćelija. Nije potrebno pamtiti koji su elementi polja zauzeti.

### 14. Nabrojite i objasnite razlike između binarnog stabla pretraživanja i hrpe.

| **Osobina**             | **Binarno stablo pretraživanja (BST)**                       | **Hrpa (Heap)**                                     |
| ----------------------- | ------------------------------------------------------------ | --------------------------------------------------- |
| **Struktura**           | Binarno stablo, lijevo čvor manji, desni veći od roditelja   | Binarno stablo, roditelj veći/manji od potomaka     |
| **Svrha**               | Brzo pretraživanje, umetanje, brisanje                       | Pronalazak maksimalnog/minimalnog elementa          |
| **Pretraživanje**       | Brzo, O(log n) u prosjeku                                    | Nije efikasno, O(n)                                 |
| **Obilazak stabla**     | Preorder, inorder, postorder (sortira podatke)               | Nema specifičan obilazak (nije sortirano)           |
| **Uravnoteženost**      | Nema obaveze uravnoteženosti, može biti nebalansirano        | Uvijek uravnotežen, visina je O(log n)              |
| **Umetanje i brisanje** | Brzo u uravnoteženom BST, ali može biti sporo u nebalansiranom | O(log n) za umetanje i brisanje                     |
| **Stabilnost**          | Može biti nestabilno u nepravilnim stablima                  | Stabilno u smislu roditelj-potomak odnosa           |
| **Primjena**            | Pretraživanje, sortiranje, održavanje sortirane liste        | Pronaći min/max element, prioritetni red, heap sort |

## 10. Hash (rasuta) tablica

### 1. Što je podatkovna struktura hash (rasuta) tablica te kako se i zbog čega ista koristi?

Podatkovna struktura u kojoj se elementi (ključevi) raspoređuju u ćelije polja primjenom hash (rasute) tablice. U hash tablici element s vrijednošću $k$ se pohranjuje na indeks $h(k)$, a ne $k$, čime je omogućeno pretraživanje u vremenu $O(1)$. Kada je skup ključeva $k$ koji se zapravo koriste manji od ukupnog broja ključeva u hash tablica, konzumira manje podatkovnog prostora. _Podatkovna složenost_ hash tablice iznosi $O(k)$ gdje je $k$ broj ključeva koji se zapravo koriste. Svrha primjene hash tablice je redukcija potrebnog memorijskog prostora.

**Hash (rasuta) funkcija** - matematička formula koja, kada se primjeni na pojedini ključ, rezultira cijelim brojem koji se može upotrijebiti kao indeks za pohranu u hash tablici (polju). Cilj hash tablice je da ključevi budu razmjerno, nasumično i uniformno raspoređeni.

### 2. Zbog čega nastaju kolizije u hash (rasutoj) tablici te kako ih je moguće minimizirati?

Kada hash funkcija za dva različita ključa rezultira istim indeksom, dolazi do kolizije. Ne postoji hash funkcija koja u potpunosti eliminira kolizije. Dobra hash funkcija će minimizirati broj kolizija na način da će uniformno rasporediti elemente po polju.

### 3. Nabrojite i objasnite svojstva dobre hash funkcije.

- **Mali utrošak resursa** - heširanje mora biti superiorno u odnosu na alternativne pristupe razmještaja elemenata. Ako se algoritam binarnog pretraživanje u sortiranom polju od $n$ elemenata sastoji od $log \ n$ usporedbi, tada izvršavanje hash funkcije treba koštati (trajati) manje od spomenutog broja usporedbi.
- **Određenost** - za isti ključ koji predstavlja ulaznu vrijednost hash funkcija mora uvijek rezultirati sa istom izlaznom vrijednošću. Navedeno se ne odnosi na hash funkcije koje ovise o vanjskim parametrima (npr. doba dana) ili memorijskoj adresi objekta koji se hešira (iz razloga što se adresa objekta tijekom procesiranja može promijeniti)
- **Uniformnost** - dobra hash funkcija treba što je moguće ravnomjernije rasporediti ključeve u raspoloživom rasponu prostora za pohranu što znači da vjerojatnost generiranja svake hash vrijednosti u spomenutom rasponu treba biti pojednaka što će minimizirati pojavljivanje kolizija.

### 4. Nabrojite i objasnite metode izračuna vrijednosti hash funkcije.

Najlakše se primjenjuju nad numeričkim ključevima. U slučajevima kada je riječ o alfanumeričkim ključevima, kao vrijednost ključa se uzima ASCII vrijednost znaka. Metode izračuna vrijednosti hash funkcija:

* metoda (modularnog) dijeljenja
* metoda množenja
* metoda srednjeg kvadrata (eng. _mid-square method_)
* metoda preklapanja (eng. _folding method_)

_Objašnjenja su u sljedećim pitanjama_

### 5. Na proizvoljnom primjeru objasnite algoritam izračuna vrijednosti hash funkcije pomoću metode (modularnog) dijeljenja.

Ukoliko heširamo cjelobrojnu vrijednost $x$, istu dijelimo sam $m$ i koristimo ostatak dijeljenja.

* $h(1234) = 1234 \mod 97 = 70$
* $h(5642) = 5642 \mod 97 = 16$

Kako bi se održalo svojstvo uniformnosti, posebnu je pozornost potrebno posvetiti odabiru vrijednosti parametra $m$.

* $m$ bi trebao biti prosti (prim) broj
* $m$ ne bi trebao biti preblizu potencija broja 2 (ako je $h(x)=x \mod 2^k$, onda će funkcija rezutirati sa najnižim $k$ bitova binarnog prikaza ključa $x$)

### 6. Koji su nedostaci metode (modularnog) dijeljenja?

Uzastopne vrijednosti ključeva će se preslikati u uzastopne hash vrijednosti. Neće doći do kolizije između uzastopnih vrijednosti ključeva, ali će uzastopni indeksi polja biti zauzeti što može dovesti do smanjenja performansi.

### 7. Na proizvoljnom primjeru objasnite algoritam izračuna vrijednosti hash funkcije pomoću metode množenja.

Koraci:

1. odabire se konstanta $A$ takva da vrijedi $0 < A < 1$
2. ključ $k$ se pomnoži s $A$
3. izluči se parcijalan dio od $kA$ (mod 1)
4. rezultat trećeg koraka se množi sa veličinom hash tablice

Iz navedenog proizlazi sljedeća hash funkcija: $h(k) =\lfloor m(kA \mod 1)\rfloor$, gdje $kA \mod 1$ daje parcijalan dio (nakon decimalnog zareza/točke) od $kA$ dok $m$ predstavlja ukupan broj indeksa (ćelije) u hash tablici. Metoda radi sa bilo kojom vrijednosti A, no optimalan odabir iste ovisi o podacima koji se heširaju.

_Primjer zadatka_

Ukoliko hash tablica ima $1000$ ćelija, na koji će indeks biti pohranjen ključ sa vrijednošću 12345?

$h(12345) = \lfloor 1000(12345 * 0.618033 \mod 1)\rfloor$   

### 8. Koja je najbolja vrijednost za parametar A kod izračuna vrijednosti hash funkcije pomoću metode množenja?

Prema Knuthu, najbolja vrijednost parametra A se izračunava na sljedeći način $\frac{\sqrt(5)-1}{2}=0.6180339887$

### 9. Na proizvoljnom primjeru objasnite algoritam izračuna vrijednosti hash funkcije pomoću metode srednjeg kvadrata.

Koraci:

1. kvadrira se vrijednost ključa $k$ odnosno izračunava se $k^2$
2. iz rezultata dobivenog u prvom koraku izlučuje se srednjih $k$ znamenki

Algoritam radi dobro jer:

* većina ili sve znamenke doprinose rezultatu
* sve znamenke iz ključa doprinose stvaranju srednjih znamenki kvadrirane vrijednosti
* rezultat nije preodređen distribucijom ni donje ni gornje znamenke iz vrijednosti ključa
* kada se primjenjuje ova metoda, jednaki broj $r$ znamenki se treba izlučiti iz svih ključeva pa prema tome vrijedi $h(k)=s$, gdje $s$ predstavlja rezultat odabira $r$ znamenki iz $k^2$

_Primjer zadatka_

Ukoliko hash tablica ima 100 ćelija, na koje ćemo pohraniti ključeve 1234 i 5642?

Obzirom da hash tablica ima 100 ćelija, indeksi će se nalaziti u rasponu od 0 do 99 što znači da su nam za raspoređivanje ključeva u hash tablicu potrebne dvije znamenke ($r=2$)

* $k=1234,k^2=1522756, h(1234)=27$
* $k=5642, k^2=31832164,h(5642)=21$

Odabrane su treća i četvrta znamenka zdesna

### 10. Na proizvoljnom primjeru objasnite algoritam izračuna vrijednosti hash funkcije pomoću metode preklapanja.

Koraci: 

1. vrijednost ključa $k$ se dijeli na dijelove $k_1,k_2,...,k_n$, gdje se svaki dio sastoji od jednakog broja znamenki osim posljednjeg dijela koji može imati manje znamenaka od prethodnih dijelova
2. dobiveni dijelovi ključa se zbrajaju odnosno izračunava se suma vrijednosti $k_1+k_2+...+k_n$

Hash vrijednost se dobiva ignoriranjem vodeće znamenke, ukoliko ista postoji. Broj znamenki u svakom dijelu ključa će varirati ovisno o veličini hash tablice. Ako je hash tablica sačinjena od 1000 ćelija, potrebne su nam tri znamenke da bi ključeve mogli pohraniti u iste. Zbog toga, svaki dio ključa mora imati tri znamenke osim posljednjeg dijela ključa koji može imati manje od 3 znamenke.

_Primjer zadatka_

Ukoliko hash tablica ima 100 ćelija, izračunajte hash vrijednosti za ključeve 5678,321 i 34567.

Obzirom da hash tablica ima 100 ćelija, svaki dio ključa, osim posljednjeg, treba biti sačinjen od dvije znamenke.

| Ključevi         | 5678               | 321    | 34567      |
| ---------------- | ------------------ | ------ | ---------- |
| Dijelovi         | 56 i 78            | 32 i 1 | 34, 56 i 7 |
| Suma             | 134                | 33     | 97         |
| Hash vrijednosti | 34 (ignorira se 1) | 33     | 97         |

### 11. Nabrojite i objasnite obilježja otvorenog adresiranja (zatvorenog heširanja).

Sve vrijednosti se pohranjuju u hash tablicu:

* Indikator (eng. _sentinel_) da je ćelija slobodna (npr $-1$) ili
* podatkovna vrijednosti

Kada dođe do kolizije, potrebno je odabrati sljedeću slobodnu ćeliju u koju će se pohraniti vrijednost ključa. Ukoliko nijedna ćelija više nije slobodna, riječ je o stanju prekoračenja kapaciteta (eng. _overflow_). Postupak pronalaženja slobodne ćelije za pohranu podatkovne vrijednosti naziva se ispitivanje (eng. _probing_). Tehniku otvorenog adresiranja moguće je implementirati pomoću linearnog ispitivanja, kvadratnog ispitivanja, dvostrukog heširanja i reheširanja.

### 12. Na proizvoljnom primjeru objasnite implementaciju otvorenog adresiranja (zatvorenog heširanja) pomoću linearnog ispitivanja.

Ukoliko se na lokaciji koju je generirala $h(x)$ nalazi podatkovna vrijednost, kolizija se rješava pomoću sljedeće hash funkcije $h(k,i)=[h'(k)+i] \mod m$, gdje je $m$ veličina hash tablice, $h'(k)=k \mod m$, a $i$ je vrijednost za ispitivanje koja se nalazi u rasponu od $0$ do $m-1$. U prvoj iteraciji ispitivanja lokacija slobodne ćelije se traži pomoću $[h'(k) \mod m$, jer je $i=0$. Ako je lokacija generirana pomoću hash funkcije iz prve iteracije zauzeta, u drugoj iteraciji ispitivanja lokacije slobodne ćelije se traži $[h'(k)+1] \mod m$, u trećoj iteraciji ispitivanja lokacija slobodne ćelije pomoću $[h'(k)+2] \mod m$, itd. Postupak se ponavlja dok se ne pronađe prva slobodna ćelija.

### 13. Objasnite složenost najboljeg i najgoreg slučaja primjene linearnog ispitivanja.

Pretraživanje se vrši na jednaki način kao i pohranjivanje. Izračunava se hash vrijednost te se vrijednost na dobivenoj lokaciji uspoređuje sa vrijednošću ključa. Ukoliko je vrijednost pronađena, vrijeme pretraživanja iznosi $O(1)$. Ukoliko vrijednost nije pronađena, vrši se slijedno pretraživanje tako dugo dok:

* tražena vrijednost nije pronađena
* funkcija pretraživanja ne naiđe na praznu ćeliju što implicira da tražene vrijednosti nema u polju
* funkcija pretraživanja prestaje s radom jer je naišla na kraj polja, a tražena vrijednost nije pronađena

U najgorem slučaju će biti potrebno izvršiti $n-1$ usporedbi te će izvođenje funkcije pretraživanja biti potrebno $O(n)$ vremena

* Vrijednost se nalazi u posljednjoj ćeliji ili iste nema u polju

Povećanje broja kolizija, povećava se udaljenost između indeksa polja izračunatih pomoću hash funkcije i lokacije traženog elementa što u konačnici povećava vrijeme pretraživanja.

### 14. Nabrojite i objasnite prednosti i nedostatke primjene linearnog ispitivanja.

Performanse linearnog ispitivanja ovise o distribuciji ulaznih vrijednosti. Glavni nedostatak je klasteriranje čime se povećava rizik da će na mjestu gdje je nastala jedna kolizija doći do pojavljivanja većeg broja kolizija.

Kada se popunjava hash tablica, oblikuju se klasteri uzastopno popunjenih ćelija te se sa povećanjem veličine klastera povećava vrijeme pretraživanja. Kod dodavanja nove vrijednosti, ista je pohranjuje na kraj klastera čime se njegova veličina dodatno pohranjuje. U većini slučajeva umetanje elemenata nailazi na situaciju kada se u polju nalaze dva klastera između kojih je jedna prazna (slobodna ćelija). Velika je vjerojatnost da će uzastopnim dodavanjem elementi završiti na kraju jednog od tih klastera pri čemu će se njihove veličina povećati za više od jedne popunjene ćelije. Što je veći broj kolizija, potreban je veći broj ispitivanja da bi se pronašla prazna ćelija što umanjuje performanse. Navedeni fenomen se naziva **primarno klasteriranje** te ga je moguće izbjeću pomoću alterantivnih oblika ispitivanja. 

### 15. Na proizvoljnom primjeru objasnite implementaciju otvorenog adresiranja (zatvorenog heširanja) pomoću kvadratnog ispitivanja.

Ako se na lokaciji koja je dobivena pomoću $h(k)$ nalazi podatkovna vrijednost, tada se kolizija rješava pomoću sljedeće funkcije: $h(k,i)=[h'(k)+c_1i+c_2i^2] \mod m$, $m$ je veličina hash tablice, $h'(k)=k \mod m$, $i$ je vrijednost za ispitivanje koja se nalazi u rasponu od $0$ do $m-1$, a $c_1$ i $c_2$ su konstante različite od nule. Problem primarnog klasteriranja se uklanja jer se umjesto linearnog provodi kvadratno pretraživanje. Za dani ključ $k$ ispituje se da li je slobodna ćelija na lokaciji $h'(k) \mod m$. Ukoliko je ćelija na spomenutoj lokaciji zauzeta, daljnja ispitivanja određena su faktorima koja kvadratno ovise o vrijednosti za ispitivanje $i$. Premda je učinak kvadratnog ispitivanja bolji od linearnog ispitivanja, da bi se maksimizirala iskoristivnost hash tablice, potrebno je ograničiti vrijednost parametara $m$, $c_1$ i $c_2$.

### 16. Nabrojite i objasnite prednosti i nedostatke primjene kvadratnog ispitivanja.

Rješava problem primarnog klasteriranja te zbog očuvanja lokaliteta reference omogućuje dobre perfomanse u kontekstu pohrane podataka u memoriji (eng. _memory cache_). Međutim, kada je riječ o pohrani podataka u memoriji, performanse linearnog pretraživanja su bolje od kvadratnog ispitivanja. Jedan od temeljnih nedostataka kvadratnog ispitivanja je da će slijed uzastopnog ispitivanja istražiti samo dio tablice, a taj dio može biti prilično malen. Ako se to dogodi, nećemo moću pronaći slobodnu ćeliju za pohranu podatkovne vrijednosti bez obzira što hash tablica nije popunjena do kraja. Kvadratno ispitivanje je podložno **sekundarnom klasteriranju** - ako postoji kolizija između dva ključa, oba će slijediti istu ispitnu sekvencu. Kod kvadratnog ispitivanja, vjerojatnost pojavljivanja višestrukih kolizija se povećava kako hash tablica postaje popunjenija. Kvadratno ispitivanje se primjenjuje kod Berkeley Fast File System (FFS) za alokaciju slobodnih memorijskih blokova.

### 17. Na proizvoljnom primjeru objasnite implementaciju otvorenog adresiranja (zatvorenog heširanja) pomoću dvostrukog heširanja.

Koristi jednu hash funkciju čiji rezultat uvećava za interval (određen drugom, nezavisnom hash funkcijom) sve dok ne pronađe slobodnu ćeliju za pohranu podatkovne vrijednosti. U slučaju dvostrukog heširanja, hash funkcija izgleda ovako: $h(k,i)=[h_1(k)+ih_2(k)] \mod m$, gdje je $m$ veličina hash tablice, $h_1$ i $h_2$ su dvije hash funkcije za koje vrijedi: $h_1(k)=k \mod m$, $h_2(k)=k \mod m'$, $i$ je vrijednost za ispitivanje koja se nalazi u rasponu od $0$ do $m-1$, a $m'$ treba biti manji od $m$, najčešće je $m'=m-1$ ili $m'=m-2$. Kod prve iteracije ispitivanja, primjenjuje se hash funkcija $[h_1(k) \mod m]$ jer je $i=0$. Ukoliko dobivena lokacija nije slobodna, traži se slobodna ćelija sa pomakom od $[h_2(k) \mod m]$ u odnosu na prethodnu lokaciju.

Obzirom da pomak može varirati sa svakim ispitivanjem jer mu je vrijednost određena pomoću druge hash funkcije, učinak dvostrukog heširanja je vrlo blizu učinku idealne sheme uniformnog heširanja. Dvostruko heširanje minimizira pojavljivanje ponovljenih kolizija te učinke primarnog i sekundarnog klasteriranja.

### 18. Nabrojite i objasnite prednosti i nedostatke primjene dvostrukog heširanja.

Premda je dvostruko heširanje učinkovit algoritam, isti iziskuje da $m$ da bude prosti (prim) broj. U našem primjeru nije bio prosti broj što je imalo za posljedicu degradaciju performansi algoritma. Da je $m$ u primjeru bio 11, algoritam bi bio djelotvorniji. Iz navedenog proizlazi da učinak algoritam ovisi o vrijednosti parametra $m$.

### 19. Na proizvoljnom primjeru objasnite implementaciju otvorenog adresiranja (zatvorenog heširanja) pomoću reheširanja.

Kad hash tablica postane gotovo puna, povećava se broj kolizija što rezultira smanjenjem performansi operacije umetanja i pretraživanja. U tom je slučaju potrebno kreirati novu hash tablicu koja će biti dvostruko veća od prve (originalne). Sve podatkovne vrijednosti će biti potrebno premijestiti iz originalne u novu hash tablicu na način da će se za svaku podatkovnu vrijednost izračunati nova hash vrijednost te nakon toga pohraniti u novu hash tablicu na način da će se za svaku podatkovnu vrijednost izračunati nova hash vrijednost te nakon toga pohraniti u novu hash tablicu. Premda je riječ o naizgled jednostavnom procesu, isti je vrlo skup te se zbog toga ne smije često provoditi.

### 20. Objasnite obilježja rješavanja kolizija pomoću tehnike ulančavanja (otvorene hash tablice).

Kod rješavanja kolizija pomoću tehnike ulančavanja (eng. _chaining_), u svakoj ćeliji hash tablice je pohranjen pokazivač do vezane liste sačinjene od podatkovnih vrijednosti koje su heširane na adresu (_indeksu_) te ćelije. Ako nijedna podatkovna vrijednost nije heširana na određenu lokaciju u hash tablici, u istoj je pohranjen `NULL` pokazivač. Traženje vrijednosti u otvorenoj hash tablici ekvivalentno je traženju vrijednosti u jednostruko vezanoj listi.

Operacija umetanja dodaje podatkovnu vrijednost na početak, kraj ili točno određenu lokaciju unutar vezane liste heširane lokacije (ovisno o tome da li vezana lista treba biti sortirana ili ne). Brisanje podatkovne vrijednost iziskuje pretraživanje liste i uklanjanje elementa iz iste. Spomenute operacije se implementiraju na identičan način kao istoimene funkcije kod implementacije liste pomoću pokazivača (jednostruko vezane liste). 

Cijena umetanja podatkovne vrijednosti iznosi $O(1)$ dok cijena pretraživanja i brisanja $O(m)$ gdje $m$ predstavlja broj elemenata liste heširane lokacije. Cijena pretraživanja i brisanja je veća zbog ispitivanja unosa na odabranoj lokaciji za željeni ključ. U najgorem slučaje će vrijeme izvođenja operacije pretraživanja biti $O(n)$ gdje je $n$ broj podatkovnih vrijednosti pohranjenih u otvorenoj hash tablici. Navedeno se manifestira kada su sve podatkovne vrijednosti pohranjene u vezanu listu iste heširane lokacije. U tom je slučaju hash tablica neučinkovita.

### 21. Nabrojite i objasnite operacije koje se izvršavaju na otvorenoj hash tablici.

Vrijeme izvođenja operacije inicijalizacije otvorene hash tablice iznosi $O(m)$. Element se pohranjuje (umeće) na početak vezane liste na čiju glavu pokazuje pokazivač koji se nalazi na lokaciji izračunatoj pomoću $h(k)$. U alternativnoj implementaciji se u ćeliji hash tablice ne stavlja glavu već prvi element. Vrijeme izvođenja ove operacije je $O(1)$ iz razloga što se novi element uvijek dodaje kao prvi element vezane liste neovisno o veličini vezane liste i ulančane (otvorene) hash tablice. U tom slučaju elementi vezane liste nisu sortirani.

Element vezane liste mogu biti sortirani, no u tom će se slučaju operacija umetanja izvoditi sporije. Elementi se pretražuju u vezanoj listi na čiju glavu pokazuje pokazivač dobiven izračunom $h(k)$. Ako je pretraživanje bilo uspješno, funkcija vraća pokazivač na čvor u kojem se nalazi tražena vrijednost, u protivnom `NULL`. Najgore vrijeme izvođenja je red veličine vezane liste. 

Da bi obrisali element u vezanoj listi čija se glava nalazi na lokaciji izračunatoj pomoću $h(k)$, trebamo utvrditi adresu njegovog prethodnika te pohraniti vrijednost pokazivača. Složenost operacije je jednaka složenosti operacije pretraživanja iz razloga što moramo pronaći prethodnika čvora kojeg uklanjamo kako bi isto izršili bez da poremetimo stanje ostalih čvorova u listi.

| Operacije                                                   | Složenost              |
| ----------------------------------------------------------- | ---------------------- |
| Inicijalizacija otvorene hash tablice                       | O(m)                   |
| Pohranjivanje (umećivanje) elementa na početak vezane liste | O(1)                   |
| Pohranjivanje elementa u ćeliji bez sortiranja liste        | O(1)                   |
| Pohranjivanje elementa u sortiranu vezanu listu             | Sporije (veća od O(1)) |
| Pretraživanje elementa u vezanoj listi                      | O(n) (najgore vrijeme) |
| Brisanje elementa u vezanoj listi                           | O(n)                   |

### 22. Objasnite složenost operacija koje se izvršavaju na otvorenoj hash tablici.

_Vidi pitanje prije_

### 23. Na proizvoljnom primjeru objasnite algoritam rješavanja kolizija pomoću tehnike ulančavanja (otvorene hash tablice).

_Vidi pitanje 21._

### 24. Nabrojite i objasnite prednosti i nedostatke ulančavanja (otvorene hash tablice).

Temeljna prednost otvorene hash tablice je da ista ostaje djelotvorna i kada je broj pohranjenih podatkovnih vrijednosti mnogo veći od broja lokacija u hash tablici. Međutim, povećanjem broja podatkovnih vrijednosti koje se pohranjuju u hash tablici, performanse otvorene hash tablice postupno (linearno) opadaju. Primjerice, otvorena hash tablica sa 1000 memorijskih lokacija i 10 000 pohranjenih podatkovnih vrijednosti će imati 5 do 10 puta slabije performanse od otvorene hash tablice sa 10 000 memorijskih lokacija. Ulančana hash tablica je 1000 puta brža od jednostavne hash tablice. Za razliku od kvadratnog testiranja, performanse ulančane hash tablice se ne smanjuju kada je više od pola prostora popunjeno. 

Kod ulančane (otvorene) hash tablice nema problema klasteriranja te stoga predstavlja učinkovit mehanizam za rješavanje problema kolizija. Nasljeđuje nedostatke vezane liste:

* kod pohrane vrijednosti, količina memorijskog prostora kojeg je potrebno alocirati kod svakog unosa za pokazivač na sljedeći element može biti značajna
* obilazak vezane liste predstavlja primjer loše učinkovitosti privremene memorije čime procesor postaje nedjelotvoran u kontekstu privremene memorije

### 25. Nabrojite i objasnite razlike između zatvorene i otvorene hash (rasute) tablice.

_Vidi pitanje prije_

### 26. Objasnite obilježja heširanja (rasipanja) sa pretincima.

Implementacija zatvorene hash tablice koja grupira hash tablicu u pretince (eng. _buckets_) na način da je $M$ ćelija (eng. _slots_) podijeljeno u $B$ pretinaca. Prema tome, svaki pretinac sadrži $M/B$ ćelija.

Kod unosa novog zapisa, primjenom hash funkcije izračunava se lokacija za pohranu. Ako izračunata lokacija nije slobodna, slijedno se pretražuju ćelije pretinca sve dok se ne pronađe prva slobodna. U slučaju da je cijeli pretinac popunjen, zapis se pohranjuje u prelivni pretinac (eng. _overflow buckets_) koji ima neograničen prostor, nalazi se na kraju tablice i dijele ga svi pretinci.

Učinkovita implementacija heširanja sa pretincima bi bila da se koristi hash funkcija koje ravnomjerno raspoređuje zapise među spremnicima tako da ih jako malen broj treba biti pohranjen u prelivni pretinac. Kod pretraživanja, upotrebljava se hash funkcija kako bi se odredio pretinac gdje bi se trebala nalaziti vrijednost. Zatim se pretinac slijedno pretražuje kako bi se pronašao željeni zapis. Ako zapis nije pronađen, a pretinac i dalje ima slobodnih ćelija, pretraživanje je dovršeno jer traženi zapis se ne nalazi u hash tablici.

Ako je pretinac pun, a traženi zapis nije pronađen, prelazi se na pretraživanje prelivnog pretinca sve dok se ne pronađe traženi zapis ili dok se ne pretraže svi zapisi koji su u prelivnom pretincu pohranjeni. Ako prelivni pretinac ima mnogo zapisa, njegovo pretraživanje može biti skupo.

### 27. Na proizvoljnom primjeru objasnite algoritam heširanja (rasipanja) sa pretincima.

### 28. Nabrojite i objasnite prednosti i nedostatke heširanja (rasipanja).

Prednosti:

* za pohranu indeksa nije potreban dodatan prostor kao u slučaju ostalih podatkovnih struktura
* omogućava brzi pristup podacima te učinkovito ažuriranje istih

Nedostaci:

* manjak lokaliteta i slijednog dohvaćanja po ključu rezultira time da su operacije umetanja i dohvaćanja podatkovnih vrijednosti poprilično nasumične
* odabir djelotvorne hash funkcije predstavlja umjetnost - nije rijetkost da se u slučaju otvorenog adresiranja stvaraju loše hash funkcije

### 29. Nabrojite i objasnite primjene heširanja.

* U situacijama kada je potrebno pristupiti velikoj količini podataka u svrhu pretraživanja i dohvaćanja istih
* indeksiranje baza podataka
  * pojedinim sustavima za upravljanje bazom podataka postoje zasebne datoteke koje se nazivaju indeksne datoteke. Kada se želi dohvatiti pojedini zapis iz baze, najprije se pronalazi identifikator zapisa (_ključ_) u indeksnoj datoteci koji upućuje na identičnu lokaciju cjelokupnog zapisa u datoteci baze podataka. Spomenuti identifikator je često pohranjen kao heširana vrijednost
  * kada bi se postigla visoka razina performansi u pristupanju datotekama u bazama podataka, koriste se dvije komplementarne tehnike. Prva je heširanje koja pohranjuje informacije u memoriju, a druga heširanje koja ubrzava pronalaženje lokacije datoteka u memoriji
* implementacija tablice simbola prevoditelja u programskom jeziku C++. Prevoditelj koristi tablice simbola u svrhu evidencija svih simbola definiranih od strane korisnika u određenom C++ programu. Heširanje pomaže prevoditelju da brzo pretraži imena varijabli i ostale atribute koji su sa spomenutim simbolima povezani
* Internet tražilice
* generiranje jedinstvenih identifikatora (npr. OIB, JMBAG) iz podataka koji se nikad ne mijenjaju (ime i prezime, datum rođenja i slično)
* potpisivanje datoteka u svrhu identifikacije. Obzirom da potpis ovisi o sadržaju datoteke, ako dođe do promjene u potpisu, navedeno implicira da je netko mijenjao sadržaj datoteke ili je došlo do gubitka podataka tijekom prijenosa. Datoteke koje sadrže ocjene studenata su heširane.
* u društvenim igrama kao što su šah ili križić kružić, heširanje se koristi u svrhu pohrane poteza igrača

## 11. Metoda pohlepe

### 1. Koje probleme rješavamo metodama za oblikovanje algoritama?

* __Optimizacijski problem__ - problem pronalaženja najmanjeg (najvećeg) rješenja problema uz zadane uvjete
* __Problem odlučivanja__ - problem pronalaženja rješenja dimenzije __K__ uz zadane uvjete

### 2. Što je problem optimizacije?

__Problem optimizacija__ (OP) zadaje se kao četvorka ($I,P,f,g$) gdje je

* $I$ skup instanci problema
* $P_i$ je prostor rješenja za instancu $i \in I$
* Prostor rješenja sadrži sva moguća rješenja za danu instancu problema $P=\{P_i:i\in I\}$
* $f:p\rightarrow R$ funkcija cilja (objektna funkcija)
* __g__ je cilj koji se definira kao optimum (minimum ili maksimum) objektne funkcije uz zadane uvjete: $g$ je funkcija $g:I \rightarrow R$

Problem optimizacije je __kombinatoran__ ako mu je skup instanci __diskretan__ (konačan ili prebrojiv) skup

__Optimizacijski problemi__

Stablo prostora stanja problema definira skup __mogućih rješenja__. U stablu postoje i rješenja koja ne zadovoljavaju zadane uvjete. Sva rješenja koja zadovoljavaju uvjete definiraju skup __prihvatljivih rješenja__. U skupu prihvatljivih rješenja problema postoji jedno ili više rješenja koja su optimalna prema objektnoj funkciji. Ona tvore skup __optimalnih rješenja__.

### 3. Što je problem odlučivanja?

__Problem odlučivanja__ (DP) zadaje se kao petorka ($I,P,f,K,g$) gdje je

* $I$ skup instanci problema
* $P_i$ je prostor rješenja za instancu $i \in I$
* Prostor rješenja sadrži sva moguća rješenja za danu instancu problema $P=\{P_i:i\in I\}$
* $f:p\rightarrow R$ objektna funkcija
* $K \in R$ zadana vrijednost problema
* $g$ je cilj koji se definira kao funkcija odlučivanja: $g$ je funkcija definirana kao $g:I \rightarrow \{0,1\}$

__Problemi odlučivanja__

__Kombinatorni problem odlučivanja__ je problem odlučivanja kod kojeg je $I$ diskretan skup. Za razliku od optimizacijskog problema, problema odlučivanja odgovara na pitanje postoji li rješenja problema dimenzije $K$. Svaki se diskretni problem optimizacije može svesti na nekoliko krugova rješavanja problema odlučivanja.

### 4. Što je i kako se provodi oblikovanje algoritama

Provodi se pomoću poznatih metoda (tehnika, strategija, pristupa). Ne postoji jamstvo da bilo koja od metoda koje ćemo obraditi daje korektno rješenje našeg problema (to moramo provjeriti). Rješenje koje dobijemo ne mora nužno biti egzaktno, već može biti i približno. Dobiveni algoritam ne mora nužno biti učinkovit, premda je praksa pokazala da su metode uspješne u rješavanju velikog broja problema.

### 5. Na proizvoljnom primjeru objasnite metodu pohlepe

Metoda (strategija, pristup) izgradnje algoritama namijenjena rješavanju srodnih skupina problema. Služi rješavanju problema optimizacije - problemi koji iziskuju minimalni ili maksimalni rezultat.

Primjer problema može biti putovanje od Pule do Zagreba koje iziskuje određenu količinu resursa, poput vremena, kilometara ili goriva. Moguće je pronaći više od jednog rješenja problema, primjerice, hodanje, vožnja biciklom, automobilom, vlakom, autobusom ili zrakoplovom. Međutim, ako stavimo određeno ograničenje na problem, poput zahtjeva da naše putovanje traje najviše šest sati, zada su neka od ponuđenih rješenja moguća (_feasible solutions_). To su rješenja koja udovoljavaju zadanom ograničenju ili uvjetu postavljenom nad problemom.

Ako dodatno kažemo da želimo na putovanje utrošiti što je manje moguće vremena (_minimum cost_), tada govorimo o problemu minimizacije (_minimization problem_). Rješenje iz skupa mogućih rješenja koje iziskuje najmanji trošak naziva se __optimalno rješenje__. Za svaki problem postoji samo jedno optimalno rješenje - ne može postojati više od jednog optimalnog rješenja za neki problem jer može biti samo jedan minimum, odnosno minimalni utrošak. Iako može postojati više od jednog mogućeg rješenja, samo jedno rješenje može biti optimalno.

Za rješavanje problema optimizacije koriste se i druge metode izgradnje algoritama, poput __dinamičkog programiranja__ te metode __grananja i ograničenja__. Prema __metodi pohlepe__, problem se rješava u etapama, pri čemu se u svakoj etapi razmatra po jedan input danog problema. Ako je taj input moguć, tada će se uključiti u rješenje. Sljedeći takvu proceduru za sve inpute, dobivamo optimalno rješenje.

Primjeri algoritma pohlepe iz svakodnevnog života uključuje kupovinu računala ili odabir zaposlenika na određenu poziciju unutar tvrtke.

__Formalnija definicija__

Metoda pohlepe temelji se na izboru jednog puta kroz stablo prostora stanja problema. U svakom koraku algoritam temeljen na metodi pohlepe izabire mogućnost koja je __lokalno optimalna__, tj. onu koja u tom trenutku najviše obećava.

Važno je napomenuti da ova metoda ne daje uvijek optimalno rješenje, pa je optimalnost potrebno dokazati za svaki pojedini algoritam temeljen na ovoj metodi.

__Princip pohlepe__ zahtjeva da iz optimalnosti podrješenja $(x_1,...,x_n)$ mora slijediti i optimalnost rješenja $(x_1,...,x_k,x_{k+1})$.

### 6. Koju vrstu problema rješavamo metodom pohlepe?

_Vidi pitanje prije_

### 7. Funkcije za implementaciju meta-algoritma temeljenog na metodi pohlepe

* `SELECT` - funkcija koja radi izbor $x$ koji je lokalno optimalan
* `FEASIBLE` - funkcija koja provjerava da li je izbor vrijednosti $x$ valjan u smislu uvjeta problema
* `UNION` - funkcija koja konkatenira (povezuje) trenutno rješenje s novim izborom $x$

### 8. Meta-algoritam temeljen na metodi pohlepe

```pseudocode
Greedy(A,n){
	sol = NULL
	for(i=0;i<n;i++){
		x=SELECT(A)
		if(FEASIBLE(sol,x))
			sol=UNION(sol,x)
	}
	return sol
}
```

### 9. Algoritam za rješavanje problema vraćanja minimalnog broja apoena i njegova složenost

Pretpostavimo da radimo u trgovini i kupcu trebamo vratiti određeni iznos novca V. Na raspolaganju imamo sve apoene u novčanicama i kovanicama određene valute (npr. 1,2,5,10,20,50,100 i 200 eura). Zadatak je da kupcu vratimo potreban iznos, a da pri tome upotrijebimo minimalan broj apoena

Primjer:

* ako trebamo vratiti iznos od 70 €, kupcu ćemo dati jednu novčanicu od 50 € i jednu novčanicu od 20 €
* ako trebamo vratiti iznos od 121 €, kupcu ćemo dati jednu novčanicu od 100 €, jednu novčanicu od 20 € i jednu kovanicu od 1 €
* ako trebamo vratiti iznos od 93 eura, kupcu ćemo dati jednu novčanicu od 50 €, dvije novčanice od 20 €, jednu kovanicu od 2 €i jednu kovanicu od 1 €

Kako bi se miminizirao broj apoena koje je potrebno dati kupcu, potrebno je krenuti od najvećeg apoena

```pseudocode
//Algoritam
1. Sortiraj apoene silazno
2. Inicijalizirajte rezultat kao prazan
3. Odaberite najveći apoen koji je manji od trenutnog iznosa
4. Dodajte odabrani apoen u rezultat. Od iznosa oduzmite vrijednost odabranog apoena
5. Ako iznos postane 0, ispišite rezultat
6. Inače ponovite korake 3 i 4 za novu vrijednost V
```

* Vremenska složenost: $O(V)$
* Pomoćni prostor: $O(V)$

Predloženi algoritam neće raditi za sve apoene:

1. Ne radi za apoene 9,6,5 i 1 eura kada kupcu treba vratiti 11 eura. Predloženi algoritam bi kao rezultat dao tri apoena (jedan od 9 eura i dva od 1 eura) dok se optimalno rješenje sastoji od dva apoena (jedan od 6 i jedan od 5 eura)
2. Ne radi za apoene od 11,5 i 1 eura kad kupcu trebamo vratiti 15 eura. Predloženi algoritam bi kao rezultat dao pet apoena (jedan od 11 eura i četiri od 1 eura) dok se optimalno rješenje sastoji od tri apoena (tri od 5 eura)

### 10. Algoritam za rješavanje problema odabira aktivnosti i njegova složenost

Zadano je $n$ aktivnosti sa vremenima njihovog početka i završetka. Potrebno je utvrditi maksimalan broj aktivnosti koje može izvršiti jedna osoba pod pretpostavkom da ista može istovremeno izvršavati samo jednu aktivnost.

Načelo pohlepe nalaže da ćemo uvijek odabrati sljedeću aktivnost čije je vrijeme završetka najmanje među preostalim aktivnostima, a vrijeme početka veće ili jednako završetka prethodno odabrane aktivnosti. Aktivnosti možemo sortirati prema njihovim vremenima završetka tako da sljedeću aktivnost uvijek smatramo kao aktivnost sa najmanjim vremenom završetka.

```pseudocode
// Algoritam
1. Sortirajte aktivnosti uzlazno prema njihovim vremenima završetka
2. Odaberite prvu aktivnost iz sortiranog polja i ispišite je
3. Za preostale aktivnosti u sortiranom polju učinite sljedeće
	a. Ako je vrijeme početka promatrane aktivnosti veće ili jednako vremenu završetka prethodno 		odabrane aktivnosti, odaberite promatranu aktivnost i ispišite je
```

__Vremenska složenost__: potrebno je $O(n \ log \ n)$ vremena ako ulazne aktivnosti nisu sortirane, odnosno $O(n)$ vremena kada su ulazne aktivnosti sortirane.

Kako algoritam pohlepe funkcionira za aktivnosti sortirane prema vremenu završetka?

Neka zadani skup aktivnosti bude $S=\{1,2,3,...,n\}$ i aktivnosti su sortirane prema vremenu završetka. Prema načelu pohlepe, uvijek se odabire aktivnost 1. Kako to da je aktivnost 1 uvijek jedno od optimalnih rješenja? Ako postoji još jedno rješenje $B$ čija prva aktivnost nije 1, onda postoji i rješenje $A$ iste veličine u kojem je aktivnost 1 prva aktivnost. Ako je $k$ prva aktivnost koju odabire $B$, tada uvijek vrijedi $A=\{B-\{k\} \cup 1\}$.

_NAPOMENA_: aktivnosti u $B$ su neovisne te $k$ ima najmanje vrijeme završetka od svih. Obzirom da $k$ nije 1, $završetak(k)>=završetak(1)$.

### 11. Algoritam za rješavanje problema minimalnog broja perona (platformi) i njegovu složenost

Uzimajući u obzir vremena događaja (dolazaka i polazaka) svih vlakova (autobusa) koji prolaze kroz kolodvor, zadatak je pronaći minimalni broj perona potrebnih za kolodvor kako nijedan vlak (autobus) ne bi čekao. Kao ulaz dobivamo dva polja koja predstavljaju vrijeme dolaska i polaska vlakova (autobusa) na nekom kolodvoru.

__Naivni pristup__: Ideja je uzeti svaki interval jedan po jedan i pronaći broj intervala koji se s njim preklapaju. Potrebno je evidentirati maksimalan broj intervala koji se preklapaju s pojedinim intervalom. Na kraju je potrebno vratiti maksimalnu vrijednost.

```pseudocode
1. Definirajte dvije ugniježdene petlje, vanjsku petlju od početka do kraja i unutarnju petlju od i+1 do kraja
2. Za svaku iteraciju vanjske petlje, pronađite broj intervala koji se sijeku s trenutnim intervalom
3. Ažurirajte odgovor s maksimalnim brojem preklapanja u svakoj iteraciji vanjske petlje
4. Ispišite odgovor
```

* Vremenska složenost: $O(n^2)$, dvije ugniježdene petlje prolaze kroz polje
* Pomoćni prostor $O(1)$, budući da nije potreban dodatni prostor

__Prvi učinkoviti pristup__: Pohranite vrijeme dolaska i vrijeme polaska za svaki vlak (autobus) i sortirajte ih na temelju vremena dolaska, a zatim provjerite je li vrijeme polaska sljedećeg vlaka (autobus) manje od vremena polaska prethodnog vlaka (autobusa) i ako je manje, povećajte broj potrebnih perona dok u protivnom broj potrebnih perona nije potrebno povećavati.

```pseudocode
1. Pohranite vrijeme dolaska i vrijeme odlaska u polje i sortirajte ga na temelju dolaska
2. Deklarirante prioritetni red (min hrpu) i pohranite vrijeme polaska prvog vlaka (autobusa) te također deklarirajte brojač i inicijalizirajte ga s 1
	a. Iterirajte kroz polje od 1 do n-1
	b. Provjerite je li vrijeme dolaska trenutnog vlaka (autobusa) manje ili jednako vremenu polaska prethodnog vlaka (autobusa) koji se nalazi na vrhu prioritetnog reda
		x. ako je navedeno istinito, dodajte novo vrijeme polaska i povećajte brojač
		y. inače, uklonite vrijeme polaska
		z. dodajte novo vrijeme polaska u prioritetni red
3. Vratite vrijednost brojača
```

* Vremenska složenost: $O(n\ log \ n)$
* Pomoćni prostor: $O(n)$

__Drugi učinkovit pristup__: Ideja je razmatrati sve događaje u sortiranom redoslijedu. Nakon što su događaji sortirano po vremenu, potrebno je u svakom trenutku evidentirati broj vlakova (autobusa) koji su stigli na kolodvor, ali sa njega još nisu otišli. Ukupan broj potrebnih platformi se u bilo kojem trenutku može dobiti oduzimanjem ukupnog broja odlazaka od ukupnog broja dolazaka do tog vremena.

Ovaj pristup pretpostavlja da vlakovi (autobusi) dolaze i odlaze na isti datum.

```pseudocode
1. Sortirajte vremena dolaska i polaska vlakova (autobusa)
2. Kreirajte dva kursora i=0 i j=0, varijablu za pohranjivanje rezultata i brojač potrebnih platformi
3. Pokrenite petlju dok i<n i j<n i usporedite i-ti element polja dolaska i j-ti element polja          odlazaka
	a. ako je vrijeme dolaska manje ili jednako vremenu odlaska, tada je potrebna još jedna platforma pa povećajte broj platformi za jedan i povećajte vrijednost kursora i
	b. inače, ako je vrijeme dolaska veće od vremena odlaska, potrebna je je jedna platforma manje pa pa je potrebno umanjiti broj potrebnih platformi za jedan i povećati vrijednost kursora j
4. ažurirajte rezultat, tj. rezultat=max(rezultat,brojac)
```

Ovaj pristup ne stvara jedinstvenu sortiranu listu svih događaja, već pojedinačno sortira polja `dolazak[]` i `polazak[]`, a zatim koristi algoritam spajanja iz sortiranja spajanjem kako bi ih zajedno obradio kao jedno sortirano polje.

* Vremenska složenost: $O(n \ log \ n)$, potrebno je jedan obilazak u vremenu $O(n)$ oba polja nakon sortiranja $O(n \ log \ n)$
* Pomoćni prostor: $O(1)$, budući da nije potreban dodatni prostor

### 12. Nabrojite koje vrste problema naprtnjače postoje te svaki od njih zasebno objasnite.

Imamo određeni skup objekata ($n$) gdje svaki objekt ima određeni profit (vrijednost, $p_i$) i težinu $w_i$. Osim toga, postoji i naprtnjača (ranac, ruksak ili općenito bilo koji kontejner) koja ima svoj kapacitet ($V$).

Problem se javlja kada imamo objekte koje želimo prenijeti pomoću naprtnjače sa jedne lokacije na drugu pri čemu je njihova ukupna težina veća od kapaciteta naprtnjače. Naprtnjaču koristimo primjerice za transfer robe kako bi istu prodali na odredišnoj lokaciji te temeljem toga ostvarili profit.

Ono što želimo napraviti je popuniti naprtnjaču sa objektima na način da ostvarimo najveći mogući profit (**problem optimizacije** odnosno **problem maksimizacije**).

Ograničenje je da ukupna težina objekata mora biti manja ili jednaka kapacitetu naprtnjače. Postoji problem 0-1 naprtnjače kod kojeg se objekt može ili staviti u naprtnjaču ili ga se uopće u istu ne može staviti (npr. perilica rublja)

* $V$ - obujam $\{(p_i,w_i):i=1,...,n\}$ cijene i obujmi predmeta

_DODATAK_: 0-1 naprtnjača, djelomična naprtnjača, višedimenzionalna naprtnjača (kilogrami i litre), višestruka naprtnjača (više ruksaka različitog kapaciteta), naprtnjača s ograničenim brojem stvari (svaka stvar se može ograničeno više puta ponijeti), dinamička naprtnjača (s vremenom se stvari mijenjaju)

### 13. Što je stablo prostora stanja problema?

Mnogi se problemi rješavaju korak po korak. Traži se $x_i$, pa onda $x_2$, itd.

Problem 0-1 naprtnjače

* $\{(6,13),(3,6),(4,8)\}$
* $V=8$

### 14. Primjena metode pohlepe u rješavanju problema naprtnjače

Vidi ova dva pitanja iznad

### 15. Algoritam za rješavanje problema realne naprtnjače i njegova složenost

Problem kod kojeg je moguće objekt staviti cijeli, ne staviti uopće ili staviti samo neki njegov dio (npr. voće, povrće). Ako pretpostavimo da je težina neke robe iskazana u kilogramima, onda primjerice ne moramo staviti svu težinu robe (npr. 7 kg objekta 4 već 3 kg, 1 kg i slično).

Ovdje bi se mogle odabrati dvije strategije punjenja naprtnjače:

* prva bi bila da se najprije odabiru objekti koji imaju najveći profit
* druga da se najprije odabiru objekti sa najmanjom težinom kako bi što više objekata stalo u naprtnjaču (više objekata, više profita)

Međutim, treba uzeti u obzir da se profit ne odnosi samo na jednu težinsku mjeru već sve za pojedini objekt (npr. ako su objekt 6 banane, onda je riječ o profitu 18 kn za 4 kg banana). Premat tome, potrebno je najprije odabrati onaj objekt koji ima najbolji omjer vrijednosti (profita) i težina. Isto kao i problem 0-1 naprtnjače, samo štu x-ovi iz $[0,1]$, a ne iz $\{1,2\}$

```pseudocode
// Algoritam pohlepe za problem realne naprtnjače
1. Za svaku se stvar izračuna relativna vrijednost p_i/w_i
2. Stvari se uzimaju redom od one s najvećom relativnom vrijednošću na niže te stavljaju u naprtnjaču sve dok sljedeća stvar više ne stane
3. Za stvar koja više ne stane izračuna se količina koja stane i njome se popuni naprtnjača
```

**Problem realne naprtnjače**

Za ulazne podatke imamo polje $e$ čiji svaki element ima dvije vrijednosti tipa `double`. Najlakše je uzeti dvodimenzionalno polje koje po jednoj dimenziji ima dva, a po drugoj $n$ elemenata. Definicija ulaznih podataka:

```c++
int n;
cout << "Upisite N: ";
cin >> n;
double (*e)[2] = new double [n][2];
for (int i=0;i<n;i++){
    cout << "Upisite p[" << i << "]: ";
    cin >> e[i][0];
    cout << "Upisite w[" << i << "]: ";
    cin >> e[i][1];
}
cout << "Unesite V: ";
double V;
cin >> V;
```

_Izračun polja relativnih vrijednosti podataka_: koristit ćemo posebno polje kako ne bismo za svaku stvar trebali tražiti. Polje ćemo sortirati silazno po relativnoj vrijednosti. Polje će biti definirano tako da, osim relativno cijene, u sebi sadrži i indeks elementa u originalnom polju. Koristit ćemo sortiranje koje ima manju složenost u najgorem slučaju.

| Algoritam  | Najgora složenost |
| ---------- | ----------------- |
| Exchange   | O(n²)             |
| Insertion  | O(n²)             |
| Bubble     | O(n²)             |
| Merge sort | O(n log n)        |
| Heapsort   | O(n log n)        |
| Quicksort  | O(n²)             |

Kako `Merge sort` zahtjeva dodatnu memoriju (nije in-place), jedini standardni algoritam sortiranja koji nam se nudi, a da ima složenosti $O(n \ log \ n)$ i da je in-place jest `heapsort`.

```c++
// Struktura polja relativnih cijena
struct rel {
    double p;
    int index;
}
// Inicijalno punjenje polja relativnih vrijednosti
rel *p = new rel [n];
for(int i=0;i<n;i++){
    p[i].p=e[i][0]/e[i][1];
    p[i].index=i;
}
// Odabir predmeta
i=0;
while(V>e[p[i].index][1]){
    r[p[i].index]=1;
    V-=e[p[i++].index][1];
}
r[p[i++].index]=V/e[p[i].index][1];
for (int j=0;j<n;i++) r[p[j].index]=0;

```

* **Složenost** $O(n\ log\ n)$

### 16. Na proizvoljnom primjeru objasnite problem optimalnog spajanja

Pretpostavimo da imamo dvije sortirane liste. Želimo ih spojiti u treću sortiranu listu. Postupak spajanja se sastoji od usporedbe slijednih elemenata u obje liste i njihovo spremanje u treću listu. Ukupno vrijeme spajanja ovisi o veličini liste ($m+n$).

Što ako imamo više listi? Ukupan broj spajanja (ukupan trošak); _zaključak_: najbolji se rezultat dobiva kada spajamo parove listi sa manjim brojem elemenata.

* ULAZ: Dan je niz od $n$ brojeva koji su uzlazno sortirani
* IZLAZ: Stablo optimalnog spajanja sortiranih datoteka u jednu sortiranu datoteku u smislu minimalnog broja čitanja vrijednosti iz datoteke

Ukupan broj spajanja je zbroj svih spojenih roditelja. Može se izračunati i kao množenje udaljenosti (koliko je puta pojedina datoteka spajana) od konačnog spajanja i veličina datoteke.

### 17. Na proizvoljnom primjeru objasnite Huffmanovo kodiranje

Metoda sažimanja (kompresije) u svrhu smanjivanja veličine datoteke u kojoj je kompromirani zapis pohranjen ili kako bi se smanjio trošak prijenosa zapisa odnosno datoteke putem mreže

* Poruka: BCCABBDDAECCBBAEDDCC

Duljina poruke je 20 znakova. Zanima nas koji je trošak prijenosa ovog zapisa odnosno njegovog prijenosa. Isti će biti mjeren u bitovima. Za prijenos alfanumeričkih podataka se koristi ASCII kodiranje pomoću kojeg je svaki znak prikazan kodom sačinjenim od osam bitova. (A 65 01000001, B 66 01000010 itd.) Obzirom da imamo 20 znakova, a svaki se prikazuje sa 8 bitova, biti će potrebno ukupno 8*20 = 160 bitova za gore navedenu poruku.

### 18. Na proizvoljnom primjeru objasnite kodove promjenjive veličine

Prema Huffmanovom kodiranju ili promjenjive (varijabilne) veličine, ne trebamo koristiti nepromjenjive kodove za alfanumeričke znakove jer se neki znakovi pojavljuju češće, a neki rjeđe od drugih. Huffmanovo kodiranje slijedi uzorak optimalnog spajanja. Svi znakovi trebaju biti poredani uzlazno prema broju njihovog pojavljivanja u poruci. U stablu se na vezu roditelja i lijevog djeteta stavlja 0, a na vezu roditelja i desnog djeteta 1. Slijedi se put od korijena kako bi se dobili kodovi za znakove.

### 19. Na proizvoljnom primjeru objasnite kodove nepromjenjive veličine

Poruka: BCCABBDDAECCBBAEDDCC

Obzirom da ne koristimo svih 128 znakova koji se nalaze u ASCII tablici odnosno na našoj tipkovnici već samo 5 velikih slova, možemo koristiti vlastite kodove koji će zauzimati manje bitova. Jedan način su kodovi nepromjenjive veličine (_fixed size encoding_). Kako imamo 5 znakova, a sa jednim bitom možemo prikazati dva znaka, sa dva bita njih 4, a sa 3 bita njih 8, biti će nam dovoljna tri bita.

Definirali smo vlastite kodove od tri bita pomoću kojih ćemo šifrirati poruku (000,001 itd.). Veličina poruke je 20*3=60 bitova. Međutim, kada se poruka šifrirana našim kodom šalje putem mreže, primatelj također treba moći dekodirati tu poruku, a da bi to mogao, mora imati tablicu sa kodovima za pojedini znak što znači da mu je pored poruke potrebno poslati i tablicu. 

Za znakove se u tom slučaju koristi ASCII kod. Kad imamo 5 znakova, a za svaki od njih će biti potrebno 8 bitova, to je ukupno 40 bitova. Osim toga, potrebno je za svih 5 znakova poslati kodove od koji se svaki sastoji od 3 bita, dakle ukupno 15 bitova. Prema tome, tablica će zauzimati 55 bitova, poruka 60 bitova, a sve zajedno 115 bitova.

### 20. Algoritam za rješavanje problema optimalnog spajanja sortiranih datoteka i njegova složenost

* ULAZ: dan je niz od $n$ brojeva koji su uzlazno sortirani
* IZLAZ: stablo optimalnog spajanja sortiranih datoteka u jednu sortiranu datoteku u smislu minimalnog broja čitanja vrijednosti iz datoteke

Osnovne odrednice algoritma:

* dvije se sortirane datoteke spajaju u jednu sortiranu korištenjem poznatog `Merge` algoritma
* složenost `Merge` algoritma je $O(n_1 + n_2)$ gdje su $n_1$ i $n_2$ duljine dvije datoteke koje se spajaju

Prema strategiji pohlepe, uzimamo uvijek dvije datoteke s najmanjim brojem elemenata. Ovakvo se stablo naziva __optimalno dvosmjerno stablo spajanja__. Primjećujemo da se ovdje radi o listi binarnih stabala. Takva se struktura naziva __šuma__ F. Šumu ćemo definirati kao listu stabala.

```pseudocode
1. ako je potrebno, sortirati listu Q
2. uzeti q1 i q2 i dodati q1+q2 tako da lista Q ostane sortirana
3. ako je |Q|>1, vrati se na korak 2
```

_Sortiranje_: koristit ćemo neko standardno sortiranje. Želimo li minimizirati ukupnu asimptotsku složenost algoritma, treba koristiti ono sortiranje koje neće povećati ukupnu složenost algoritma u najgorem slučaju.

Sada ćemo se baviti definiranjem liste. Zbog brzine rada listu ćemo izvesti pomoću polja. To nam postavlja sljedeće zahtjeve:

* da se ne događa prebacivanje elemenata u polju jer se elementi brišu na početku liste
* što se tiče prebacivanja kod umetanja, to nije problem, jer se i tako lista treba pretraživati kako bi se vidjelo gdje se element dodaje u listi.

Sljedeće je pitanje kako izraditi stabla. Operacije koje se rade su sljedeće:

* čitanje oznake korijena
* spajanje dvaju stabala u jedno kreiranjem novog korijena i dodavanjem korijena dvaju stabala kao njegove djece

Implementacija koja se koristi treba omogućiti sljedeće:

* implementaciju šume
* operacija spajanja stabala bez prepisivanja stabala

Stoga će se koristiti implementacija šume binarnih stabala u jednom polju po principu lijevo dijete-desni brat. Kod te se implementacija stabla šume povezuju u listu preko kursora na sljedećeg brata korijena stabla.

Zašto polje, a ne pokazivači? Algoritam s poljem radit će brže nego onaj s pokazivačima jer neće biti potrebna posebna alokacija memorije za svaki element. Možemo točno odrediti koliko će elemenata polja biti potrebno.

Koliko čvorova ima stablo koje reprezentira optimalno dvosmjerno stablo spajanja $n$ datoteka? $2n-1$

```c++
struct element {
    int value, child, sibling;
};
struct forest {
    int begin;
    element f[FDIM];
};
```

Sortiranje se može ostvariti na dva načina:

* sortiranjem polja
* postavljanjem kursora

Ulazno polje ćemo sortirati, a onda ga upisati u strukturu podataka koja predstavlja polja. Koristit ćemo __heapsort__ algoritam, jer je on relativno brz, a ima složenost $O(n \ log \ n)$ u najgorem slučaju.

Sada imamo sljedeći pseudokod: heapsort(a), prepiši $a$ u strukturu šume, izvedi Huffmanov greedy algoritam, ispis rješenja

Problem je što heapsort sortira polje koje počinje od prvog, a ne od nultog elementa. Kako to elegentno riješiti? Prepisivanje se vrši jednostavno. Elementi polja se jednostavno prepisuju iz polja u strukturu, a za $i$-ti element strukture se kursor na sljedećeg brata stavlja na $i$+1. Sada imamo sljedeću funkciju koja će inicijalizirati šumu.

```c++
void InitForest(int n, forest *s, int a[]){
    for(int i=0;i<n;i++){
        (*s).f[i].value=a[i];
        (*s).f[i].sibling=i+1;
    }
    (*s).f[n-1].sibling=-1; // LAMBDA vrijednost
    (*s).begin=0;
}
```

Složenost - $O(n)$

Stabla u šumi ćemo uvijek držati sortirana po veličini oznake korijena. Tada uvijek uzimamo prva dva stabla u šumi i spajamo ih u jedno stablo. Kreiramo novu šumu. Uvjet završavanja - kada treba stati s Huffmanovim algoritmom? Kada šuma ima samo jedno stablo tj. kada je `sibling` kursor stabla na koje pokazuje kursor `begin` jednak $-1$, tj.

* `while((*s).f[(*s).begin].sibling != -1)`

_Kreiranje novog stabla_: uzme se prvi sljedeći slobodni element u polju. U `value` vrijednost se upiše zbroj vrijednosti korijena dvaju stabala koja su izuzeta iz šume. Kursor `child` se namjesti na vrijednost kursora `begin`. Korijenu drugog izuzetnog stabla bi trebalo promijeniti vrijednost `sibling` kursora na $-1$, no s time ćemo malo sačekati kako ne bismo tu vrijednost morali čuvati u pomoćnoj varijabli

_Brisanje dvaju stabala s početka šume:_ Uzme se element strukture na koji pokazuje kursor `begin`. Uzme se element strukture na koji pokazuje `sibling` prvog kursora. Kursor `begin` se izjednači sa `sibling` kursorom drugog stabla. Sada se može vrijednost kursora `sibling` korijena drugog izuzetog stabla promijeniti na vrijednost $-1$

_Kreiranje nove šume_: Počinjemo od kursora `begin`. Ako je oznaka korijena novog stabla manja od prvog u šumi, novo stablo dodajemo na početak šume. Ako nije, tražimo element šume čiji je sljedbenik po oznaci korijena veći od novog stabla i novo stablo umećemo iza tog elementa (ili na kraj ako je novo stablo po korijenu veće od svih stabala u šumi). Složenost: $O(n^2)$

### 21. Objasnite što je šuma, kako se podatkovna struktura koristi za njenu implementaciju te koji se algoritam sortiranja koristi za implementaciju algoritma rješenja problema optimalnog spajanja sortiranih datoteka.

_Vidi pitanje prije_

### 22. Primjena metode pohlepe u rješavanju problema redoslijeda zadataka s rokovima

_Job sequencing with deadlines_

Ako se dovrši pojedini zadatak, dobiva se profit koji je uz taj zadatak vezan, ali se zadatak treba dovršiti u zadanom roku. Pretpostavimo da imamo stroj na kojem se izvršavaju zadaci pri čemu se u isto vrijeme može izvršavati samo jedan zadatak, a za dovršetak pojedinog zadatka je potrebna određena količina resursa (npr 1.sat). Pretpostavimo da je riječ o fotokopiraonici gdje svaki zadatak predstavlja kopiranje određenih dokumenata te je vezan uz jednu osobu. U vrijeme otvaranja fotokopiraonice, petero ljudi čeka da bude usluženo pri čemu rokovi označavaju koliko brzo pojedina osoba treba da joj dokumenti budu kopirani.

| Zadaci | Z1   | Z2   | Z3   | Z4   | Z5   |
| ------ | ---- | ---- | ---- | ---- | ---- |
| Profit | 20   | 15   | 10   | 5    | 1    |
| Rokovi | 2    | 2    | 1    | 3    | 3    |

Osoba sa zadatkom 3 je ta kojoj je najhitrije da joj dokumenti budu kopirani te ne može čekati dulje od jednog sata. Problem koji se ovdje javlja je da pokušamo izvršiti zadatke na način da maksimiziramo profit. Dakle, riječ je o problemu maksimizacije sa ograničenjem da pojedini zadatak treba biti izvršen u zadanom vremenskom roku. U ovom kontekretnom slučaju je potrebno odabrati redoslijed izvršavanja zadataka takav da profit bude maksimalan. Obzirom da se svaki zadatak izvršava sat vremena i osobe su spremne čekati najviše tri sata, možemo dovršiti samo tri od pet raspoloživih zadataka. Dakle, imamo tri vremenska razdoblje (pod pretpostavkom da fotokopiraonica radi od 8 sati):

* od 8 do 9 sati $[0,1]$:__Z2__
* od 9 do 10 sati $[1,2]$: __Z1__
* od 10 do 11 sati $[2,3]$: __Z4__

Metoda pohlepe će odabrati zadatke prema najvećem profitu. Vidimo da su zadaci već poredani silazno prema profitu, odabiremo najprije već poredani silazno prema profitu. Obzirom da je na njegovo izvršaanje moguće čekati dva sata, stavljamo ga na izvršavanje između prvog i drugog sata od otvorenja fotokopiraonice. Zatim odabiremo drugi zadatak. Njega je također potrebno izvršiti u roku od najviše 2 sata. Obzirom da je razdoblje od 9 do 10 sati zauzeto, drugi zadatak možemo jedino izvršiti u prvom vremenskom razdoblju. Nakon toga odabiremo treći zadatak koji je treći po profitu. Međutim, kako se on mora izvršiti u prvom satu od otvaranja knjižnice, a to je vremensko razdoblje već zauzeto, taj zadatak nećemo moći izvršiti. Odabiremo četvrti zadatak. Kako se na njegovo izvršavanje može čekati tri sata, stavljamo ga u treće vremensko razdoblje. Peti zadatak nećemo moći izvršiti jer su sva raspoloživa vremenska razdoblja rada stroja zauzeta, a na izvršavanje istog nije moguće čekati više od tri sata. 

Potrebno je napomenuti da je maksimalan broj vremenskih razdoblja određen vremenom zadat(a)ka na čije je izvršavanje potrebno najdulje čekati. Osim toga, rokovi predstavljaju vremenska razdoblja nakon kojih se zadaci više ne mogu izvršavati (jer u našem primjeru ljudi nisu spremni dulje čekati), no to ne znači da se oni ne mogu izvršiti ranije. Prema tome, kod odabira zadatka, isti uvijek stavljamo u ono vremensko razdoblje koje je određeno njegovim ograničenjem (rokom). Ukoliko je to vremensko razdoblje već zauzeto, onda provjeravamo da li se zadatak može izvršiti u nekom ranije raspoloživom vremenskom razdoblju.

## 12. Metoda podijeli pa vladaj

### 1. Na proizvoljnom primjeru objasnite metodu podijeli pa vladaj.

Primjer: _Merge sort_

* ako imamo niz veličine $n$, podijelimo ga na dva jednaka dijela
* rekurzivno sortiramo svaki od podnizova
* spajanjem dva sortirana podniza dobijemo sortirani niz

### 2. Koju vrstu problema rješavamo metodom podijeli pa vladaj?

Ukoliko postoji neki veliki problem $P$ veličine $n$, on se dijeli na $k$ dovoljno jednostavnih potproblema da ih je moguće riješiti te se nakon toga njihova rješenja spajaju u rješenje glavnog, polaznog problema. Ukoliko su problemi na nižoj razini također previše kompleksni, onda se i na njih primijeni ista strategija (podijeli pa vladaj).

### 3. Kad se može primijeniti metoda podijeli pa vladaj?

Potproblemi trebaju biti iste vrste (namjene) kao i polazni problem. Primjerice, ako je glavni problem namijenjen sortiranju, onda i potproblemi moraju tome isto biti namijenjeni. Dakle, potproblemi se ne mogu pretvoriti u neki drugi problem. Dekompozicija nekog događaja ili projekta na heterogene potprobleme ne predstavlja primjenu metode podijeli pa vladaj. 

Primjenom ove metode se problem rekurzivno rješava. Ukoliko ne postoji način za kombiniranje rješenja potproblema u rješenje glavnog problema, onda se ova metoda ne može primijeniti. Metoda se primjenjuje kad je:

* polazni problem moguće podijeliti na barem dva potproblema
* pojedini potproblem nije potrebno opetovano vrednovati

### 4. Od kojih se koraka sastoji primjena metode podijeli pa vladaj?

Metoda se sastoji od primjene sljedeća tri koraka:

```pseudocode
1. Podijeli probleme na manje probleme (podijeli)
2. Rekurzivno riješi potprobleme (vladaj)
3. spoji rješenja potproblema u rješenje polaznog problema (kombiniraj)
```

Poznatiji algoritmi koji se temelje na primjeni podijeli pa vladaj:

* __QuickSort__ (dijeli polazni problem na potprobleme različite veličine)
* __MergeSort__ (dijeli polazni problem na potprobleme jednake duljine)

### 5. Objasnite meta-algoritam metode podijeli pa vladaj.

```c++
DivAndC(p,q){
    if(SMALL(A,n))
        return G(A,n)
    else {
        m=DIVIDE(A,n)
        return COMBINE(DivAndC(p,m),DivAndC(m+1,q))
    }
}
```

### 6. Na proizvoljnom primjeru objasnite metodu smanji pa vladaj.

* __Linearno pretraživanje niza__: provjerava svaki element u nizu dok ne pronađe traženi ili ne dođe do kraja
* __Euklidov algoritam za najmanji zajednički djeljitelj__: Problem se smanjuje dijeljenjem većeg broja manjim sve dok ostatak nije 0
* __Pretraživanje binarnog stabla__: u svakom koraku prelazi u lijevo ili desno podstablo, ovisno o vrijednosti čvora, dok ne pronađe traženi broj ili ne dođe do kraja
* __Brojanje znamenki u broju__: problem se smanjuje dijeljenjem broja s $10$ dok broj ne postane $0$
* __Faktorijel (rekurzivno)__: smanjuje broj $n$ na $n-1$ i tako računa $n!=n*(n-1)$ dok ne dođe do $1!=1$

### 7. Objasnite meta-algoritam metode smanji pa vladaj.

Inkrementalna (induktivna) metoda koja se temelji na vezi između rješenja manje instance problema i rješenja polaznog problema.

Metoda se sastoji od primjene sljedeća tri koraka:

```pseudocode
1. Reduciraj polazni problem na manju instancu istog (smanji)
2. Rekurzivno riješi manju instancu polaznog problema (vladaj)
3. Proširi rješenje instance problema na rješenje polaznog problema (proširi)
```

__Binarno pretraživanje__ je jedan od poznatijih algoritama koji se temelje na primjeni metode smanji pa vladaj je se u svakom koraku rješava samo jedna manja instanca polaznog problema.

```c++
DecAndC(p,q){
    if(SMALL(A,n))
        return G(A,n)
    else {
        m=DIVIDE(A,n)
        p=CHOOSE(A,n,m)
        if(p="LO")
            return DecAndC(p,m)
        else
            return DecAndC(m+1,q)
    }
}
```

### 8. Nabrojite i objasnite pristupe metode smanji pa vladaj.

Postoje dva pristupa ove metode

* odozgo prema dolje (eng. _top-down_) kada se problem rješava rekurzivno
* odozdo prema gore (eng. _botttom-up_) kada se problem rješava iterativno počevši od rješenja najmanje instance problema

### 9. Nabrojite i objasnite varijante metode smanji pa vladaj.

* __smanjenje za konstantu__ tijekom koje se veličina instance smanjuje za istu konstantu (koja je najčešće jednaka jedan) tijekom svake iteracije algoritma (primjerice sortiranje umetanjem)
* __smanjenje za konstantan faktor__ tijekom koje se veličina instance smanjuje za isti konstantni faktor (koji je najčešće jednak dva jer dijelimo na dva dijela) tijekom svake iteracije algoritma (primjerice binarno pretraživanje)
* __promjenjivo smanjenje veličine__ tijekom koje smanjenje veličine instance varira među iteracijama algoritma (primjerice kod Euklidovog algoritma je vrijednost drugog argumenta uvijek manja na desnoj nego na lijevoj strani)

### 10. Što je Josipov problem te kako je moguće primijeniti metodu smanji pa vladaj u njegovom rješavanju?

Dobio je naziv po Flaviju Josipu (Flavius Josephus) židovskom povjesničaru koji se borio protiv Rimljana. Josip i njegova skupina židovskih vojnika su bili stjerani u kut i okruženi Rimljanima unutar špilje. Umjesto da se predaju i budu zarobljeni, odlučili su da se međusobno poubijaju, a da posljednja osoba napravi samoubojstvo. Odlučili su da će svi vojnici sjediti u krugu i počevši od vojnika koji sjedi na prvoj poziciji, svaki će vojnik ubiti prvog sljedećeg vojnika u smjeru kazaljke na sati.

Primjerice, ako 5 vojnika sjedi u krugu s pozicijama označenim kao 1,2,3,4,5: 1 ubije 2, 3 ubije 4, 5 ubije 1, 3 ubije 5, budući da je 3 jedini preostao, on će počiniti samoubojstvo.

Međutim, Josip nije htio biti ubijen niti počiniti samoubojstvo već se radije predao Rimljanima. Zbog toga je Josip morao utvrditi na koju poziciju u početnom krugu treba sjesti (pod uvjetom da ima ukupno $n$ vojnika i da čovjek koji sjedi na poziciji 1 dobije prvu priliku za ubojstvo) tako da on bude posljednji preživljeli čovjek u spilji.

__Generalizacija problema__: $n$ ljudi stoji u krugu i čeka da budu pogubljeni. Odbrojavanje počinje u nekom trenutku u krugu i nastavlja se oko kruga u fiksnom smjeru. U svakom koraku se određeni broj ljudi preskače i sljedeća osoba je pogubljena. Eliminacija se nastavlja oko kruga (koji postaje sve manji kako se pogubljeni ljudi uklanjanju), dok ne ostane samo jedna preživjela osoba.

$n$ označava ukupan broj osoba, a $k$ označava da je $k-1$ osoba preskočena i $k$-ta osoba pogubljena. Zadatak je odabrati mjesto u početnom krugu tako da ostanete zadnji i tako preživite. Ako je $n=7$, a $k=3$; bit će pogubljene osobe na pozicijama, 3,6,2,7,5 i 1, potrebno je odabrati poziciju 4.

Problem ima sljedeću rekurzivnu strukturu:

* $josip(n,k)=(josip(n-1,k)+k-1) \mod n +1 $
* $josip(1,k)=1$

Nakon što je prva osoba ($k$-ta od početka) pogubljena, ostaje $n-1$. Pozivamo $josip(n-1,k)$ kako bi dobili poziciju s $n-1$ osoba. Pozicija koja vraća $josip(n-1,k)$ će uzeti u obzir poziciju počevši od $k \mod n + 1$. Prema tome, moramo napraviti prilagodbu na poziciju koju je vratio $josip(n-1,k)$.

```c++
int josip(int n, int k){
    if(n==1)
        return 1;
    else
        /* Poziciju koju vraća josip(n-1,k) je potrebno
        prilagoditi jer rekurzivni poziv josip(n-1,k)
        smatra originalnu poziciju k%n+1 kao poziciju 1 */
        return (josip(n-1,k)+k-1) % n+1;
}
```

* Složenost: $O(n)$

__Primjena metode smanji pa vladaj za konstantan faktor__

Kad je $k=2$, u prvom krugu su pogubljene sve osobe na parnim pozicijama. U drugom krugu postoje dva slučaja:

* ako je $n$ __paran__ (primjerice $n=8$):
  * u prvom krugu su pogubljene osobe na pozicijama redom 2,4,6 i 8
  * u drugom krugu će se osobe koje su se u početnom krugu nalazile na pozicijama 1,3,5 i 7 nalaziti na pozicijama 1,2,3 i 4
* ako je $n$ __neparan__ (primjerice $n=7$):
  * u prvom krugu su pogubljene osobe na pozicijama redom 2,4 i 6
  * u drugom krugu će se osobe koje su se u početnom krugu nalazile na pozicijama 3,5 i 7 nalaziti na pozicijama 1,2 i 3

Ako je $n$ __paran__ i osoba je na poziciji $k$ u trenutnom krugu, tada je osoba bila na poziciji $2k-1$ u prethodnom krugu. Ako je $n$ __neparan__ i osoba je na poziciji $k$ u trenutnom krugu, tada je osoba bila na poziciji $2k-1$ u prethodnom krugu.

* ULAZ: prirodni broj $n$
* IZLAZ: prirodni broj $k \in \{1,...,n\}$ koji se naziva Josipov broj i označava se s $J(n)$

Ako imamo paran broj osoba, nakon prvog kruga situacija će biti sljedeća. Dakle, svest će se na problem veličine $n/2$, jer se u prvom krugu eliminiraju svi ljudi na parnim pozicijama, a svaki čovjek koji je stajao na poziciji $2k-1$ sada će stajati na poziciji $k$. Ako je početni broj bio veličine $2n$, on će se svesti na problem veličine $n$. Ako problem veličine $n$ daje rješenje $J(n)$, onda će biti $J(2n)=2J(n)-1$. Ako imamo neparan broj osoba, nakon prvog kruga situacija će biti sljedeća: nakon što se eliminiraju svi ljudi na parnim mjestima, biti će pogubljen čovjek na poziciji $1$, a problem će se svesti na problem veličine $(n-1)/2$. Čovjek koji sada stoji na poziciji $k$, prije je stajao na poziciji $2k+1$. Ako je početni broj bio veličine $2n+1$, on će se svesti na problem veličine $n$. Ako problem veličine $n$ daje rješenje $J(n)$, onda će biti $J(2n+1)=2J(n)+1$.

Sažeto, formula se može zapisati kao:

* $J(n)=2J(\lfloor n/2 \rfloor)+(-1)^{n+1}$
* Početni uvjet: $J(2)=1$

```c++
int J(int n){
    if (n<3) return 1;
    else
        if (n%2) return 2*J((n-1)/2)+1;
        else return 2*J(n/2)-1
}
```

Složenost: $T^J_{max}=T(n/2)+c,O(log \ n)$

Problem se može pojednostavniti na sljedeći način: ako je $n=2^m+k$ gdje je $k<2^m$, tada je $J(n)=2k+1$. U izvornom problem je bio Josip sa 40 vojnika: $40=2^5+9=32+9$, $J(n)=2 \times 9 +1$. Problem se može pojednostavniti na sljedeći način: $41=32+9=2^5+2^3+2^0$. Binarni zapis broja vojnika: $101001$. Ako se početna znamenka (najznačajniji bit) stavi na kraj binarnog zapisa broja vojnika, dobiva se Josipov broj. $010011=2^4+2^1+2^0=16+2+1=19$. Implementacija rješenja se temelji na manipulaciji bitova.

### 11. Objasnite algoritam za rješavanje Josipovog problema i njegovu složenost.

_Vidi pitanje 10._

### 12. Objasnite na koje je sve načine moguće izračunati Josipov broj.

_Vidi pitanje 10._

### 13. Objasnite primjenu metode podijeli pa vladaj u Karatsuba algoritmu.

Potrebno je izračunati umnožak dva stringa od kojih svaki predstavlja zapis jednog cijelog broja. Primjerice, umnožak stringova $110$ i $1010$ je $120$.

Neka je svaki string duljine $n$.

__Naivni pristup__:

* svaki bit drugog broja množimo sa svim bitovima prvog broja te na kraju zbrojimo sva množenja
* ovaj algoritam iziskuje $O(n^2)$ vremena

__Podijeli pa vladaj__:

* pristup se temelji na tome da podijelimo zadane brojeve na dvije polovice

* pretpostavimo da imamo stringove X i Y te da je $n$ paran broj

* $X=XL \times 2^{n/2} + XD$ (XL i XD sadrže $n/2$ najljevijih i najdesnijih bitova od X)

* $Y=YL \times 2^{n/2}+YD$ (YL i YD sadrže $n/2$ najljevijih i najdesnijih bitova od Y)

* Umnožak XY se može zapisati na sljedeći način:
  * $XY = \left(X_L \cdot 2^{n/2} + X_D\right)\left(Y_L \cdot 2^{n/2} + Y_D\right) = 2^n X_L X_D + 2^{n/2}(X_L Y_R + X_R Y_L) + X_D Y_D$
  
* Imamo četiri množenja veličine $n/2$ što znači da smo problem veličine $n$ podijelili na četiri potproblema veličine $n/2$

  Međutim, rekurzivna relacija navedenog je $T(n)=4T(n/2) + O(n)$ što je i dalje $O(n^2)$

* Kako bi dobili učinkovitiji algoritam, trebamo promijeniti srednja dva izraza tako da nam je dostatno samo jedno dodatno množenje
  * $X_L Y_D + X_D Y_L = (X_L + X_D)(Y_L + Y_D) - X_L Y_L - X_D Y_D$
  
* iz navedenog izračunamo umnožak XY
  * $XY = 2^n X_L Y_L + 2^{n/2} \left[(X_L + X_D)(Y_L + Y_D) - X_L Y_L - X_D Y_D\right] + X_D Y_D$
  
* Rekurzivna relacija navedenog je $T(n)=3T(n/2)+O(n)$ iz čega proizlazi složenost $\Theta(n \log_2 3) \approx \Theta(n^{1.5849625})$

Što ako su ulazni stringovi različite duljine? - Dodaju se nule na početku

Što ako duljina stringove nije paran broj?

* stavljamo $\lfloor n/2 \rfloor$ bitova u lijevu polovicu i $\lceil n/2 \rceil$ bitova u desnu polovicu.
* $XY = 2^{2 \cdot n/2} X_L Y_L + 2^{n/2} \left[(X_L + X_D)(Y_L + Y_D) - X_L Y_L - X_D Y_D\right] + X_D Y_D$

Riječ je o Karatsuba algoritmu namijenjenom brzom množenju velikih brojeva. 2 je stavljen kao baza jer smo problem zadali kao stringove u binarnom obliku. Ako su brojevi zapisani u decimalnom obliku, onda se u formulu umjesto 2 stavlja baza 10.

### 14. Objasnite prikaz Karatsuba algoritma pomoću stabla.

Rad Karatsuba algoritma se može prikazati pomoću stabla. Zadani problem se dijeli na potprobleme množenja jednoznamenkastih brojeva (single-digit multiplication, SDM).

Ako želimo pomnožiti brojeve 98 i 57, trebat će nam pet množenja jednoznamenkastih brojeva što je __sporije__ od klasičnog množenja kod kojeg množenje dva dvoznamenkasta broja iziskuje četiri množenja jednoznamenkastih brojeva.

Ako želimo pomnožiti brojeve 1254 i 4021, trebat će nam deset množenja jednoznamenkastih brojeva što je __brže__ od klasičnog množenja kod kojeg množenje dva četveroznamenkasta broja iziskuje šesnaest množenja jednoznamenkastih brojeva.

### 15. Objasnite algoritam za rješavanje problema nalaženja maksimuma i njegovu složenost.

ULAZ: Niz brojeva duljine $n$

IZLAZ: Pozicija $M$ najvećeg broja u nizu

* Ako je niz duljine 1, onda je jedini broj u nizu ujedno i najveći
* Ako je niz duljine veći od 1, podijelimo ga na dva podniza pojednake duljine i svakom od njih nađemo maksimum
* Maksimum cijelog niza je veći od dva maksimuma podniza

```pseudocode
Max(i,j,a){
    Ako je n>1
    	k=(i+j)/2
    	m1=Max(i,k,a)
    	m2=Max(k+1,j,a)
    	m=max{m1,m2}
    	vrati m
    Inače vrati [i]
}
```

```c++
int Max(int i, int j, float a[]){
    if(j-i>0){
        int k = (i+1)/2;
        int m1=Max(i,k,a);
        int m2=Max(k+1,j,a);
        return a[m1]>a[m2]?m1:m2;
    }
    else return i;
}
```

Složenost:

* $T(n)=2T(n/2)+c$
* $T(n)=O(n)$

### 16. Objasnite algoritam za rješavanje problema najmanje udaljenosti i njegovu složenost.

* ULAZ: $n$ točaka u ravnini ($x_i,y_i$), $i=1,...,n$
* IZLAZ: najmanja udaljenost $d$ između dvije točke

Kao pripremni korak sortirajmo točke uzlazno po $x$ koordinati, koristeći neki brzi algoritam za sortiranje, recimo __heapsort__. Podijelimo skup točaka na dva skupa tako da

* u svakom bude $n/2$ točaka
* u prvom skupu budu točke s manjom $x$ koordinatom, a u drugom skupu one s većom koordinatom

Rekurzivno tražimo najmanju udaljenost točaka u dobivenim podskupovima. Neka su to $d_1$ i $d_2$. Neka je $d=min\{d_1,d_2\}$. Odredimo točku $(x_i,y_i)$ s najvećom $x$ koordinatom u prvom skupu točaka i točku $(x_{i+1},y_{_i+1})$ s najmanjom x koordinatom u drugom skupu. Izračunamo njihovo polovište po x osi i to postaje granicom između dvaju skupova točaka. Stvorimo skup $C_1$ svih točaka iz prvog skupa koje su po $x$ osi udaljene manje od d od granice, te skup $C_2$ svih točaka iz drugog skupa koje su po $x$ osi udaljene za manje od $d$ do granice. Provjerimo udaljenost između svih točaka iz skupa $C_1$ i $C_2$. Neka je $e$ najmanja od tih udaljenosti. Tada je najmanja udaljenost dvaju točaka u skupu jednaka $min(d,e)$

```pseud
Sortiraj(T)
Napravi T1 i T2 sa po n/2 točaka
Odredi najmanju udaljenost d1 u T1
Odredi najmanju udaljenost d2 u T2
d=min{d1,d2}
odredi skupove C1 i C2
izračunaj najmanju udaljenost e neke točke C1 od neke točke iz C2
vrati min{d,e}
```

Podatke trebamo sortirati i pristupati svakome od njih izravno. Osim toga, moramo znati gdje je početak, a gdje kraj promatranog dijela polja. Iz gore rečenoga, ispada da je najbolje koristiti dvodimenzionalno polje, kod kojeg je druga dimenzija veličine 2 (x i y koordinata) te dva kursora i i j koji će pokazivati početak i kraj promatranog dijela polja.

_Primjer_ : neka su zadane točke $\{(1, 2), (5, 4), (5.2, 5), (7, 7), (7.2, 7.2)\}$. Za sortiranje ćemo koristiti __heapsort__ koji sortira po prvoj komponenti parova brojeva.

Rekurzija:

* rubni uvjet: kada je $j-i<2$ (kada imamo manje od 3 točke)
  * ako je jedna točka, onda se ne izračunava
  * ako su dvije točke, računa se $sqrt((x_2-x_1)^2+(y_2-y_1)^2)$
  * Korak
    * $K=(i+j)/2$
    * izračunati najmanju udaljenost za niz $i...k$ i $k+1...j$
    * izračunati udaljenost točaka koje su _blizu_ granici. Blizina je manja od dviju udaljenosti koje vrati korak 2
  * `if(j-i>1)`
    * podijeli niz na dva dijela
    * izračunati najmanje udaljenosti $d_1$ i$d_2$ u svakom od dijelova
    * $D=min(d_1,d_2)$
    * $x = \frac{a_{k+1,0} - a_{k,0}}{2}$
    * izračunati minimalnu udaljenost $d_3$ neke točke s lijeve strane od točke s desne strane, u obzir uzeti one točke koje od granice nisu udaljene za više od $d$
    * `return min(d1,d2,d3);`
    * `else return sqrt(pow(a[j][0]-a[i][0],2)+pow(a[j][1]-a[i][1],2));`

### Koraci za slučaj $j - i > 1$:

1. Postaviti $k = \frac{i + j}{2}$.
2. Izračunati najmanje udaljenosti $d_1$ i $d_2$ u svakom dijelu.
3. Postaviti $d = d_1 < d_2 ? d_1 : d_2$.
4. Izračunati granicu između dijelova:
   $x = \frac{a_{k+1,0} - a_{k,0}}{2}$
5. Koristiti funkciju `Stripe` s parametrima:
   $\text{Stripe}\left(\frac{a_{k,0} + a_{k+1,0}}{2}, d, k, a\right)$
6. Vratiti minimalnu udaljenost:
   $\min(d_1, d_2, d_3)$

### Ako nije zadovoljen uvjet $j - i > 1$:

Vratiti udaljenost između dvije točke $i$ i $j$:
$\sqrt{(a[j][0] - a[i][0])^2 + (a[j][1] - a[i][1])^2}$

Složenost:

* $T_{\text{max}}^{\text{Dist}}(n) \leq C_1 + 2 \cdot T_{\text{max}}^{\text{Dist}}\left(\frac{n}{2}\right) + T_{\text{max}}^{\text{Stripe}}(n) + T_{\text{max}}^{\text{Min}}$
* $T(n)∈O(n \ log \ n)$

### 17. Objasnite algoritam za množenje matrica i njegovu složenost.

Dvije se matrice mogu množiti ako je broj stupaca prve matrice jednak broju redova druge matrice. Rezultat će biti matrica će biti matrica dimenzija broja redova prve matrice i broja stupaca druge matrice. Rezultat će biti matrica dimenzija broja redova prve matrice i broja stupaca druge matrice.

```c++
for (i=0;i<n;i++){
	for(j=0;j<n;j++){
		C[i,j]=0;
		for(k=0,k<n,k++){
			C[i,j]+=A[i,k]*B[k,j];
		}
	}
}
```

Za pristupanje elementima su dovoljne prve dvije petlje, a za množenje služi treća petlja. Dakle, složenost algoritma će biti $O(n^3)$.

Ovdje treba primijeniti metodu podijeli pa vladaj gdje imamo problem kojeg podijelimo na manje probleme, do razine kada su potproblemi direktno rješivi. Kada imamo veliki problem, onda također trebamo utvrditi što su to mali problemi. U ovom kontekstu dimenzija matrica $2 \times 2$ su mali problem koji je direktno rješiv. Ovdje nisu potrebne iteracije, svaka se jednadžba izvodi u jednoj jedinici vremena, dakle, potrebne su nam četiri jedinice vremena što implicira konstantnu složenost. Ukupno ima $i$ konstantan ($8$) broj množenja. Međutim, da bi matrica $2 \times 2$ predstavljala mali problem koji je dikretno rješvim, dimenzije matrica koje predstavljaju problem kojeg rješavamo svodeći ga na manji problem moraju biti potencije broja $2$.

```c++
Algoritam MM(A,B,n){
	If(n<=2){
		C=4 formule
	}
	else {
		mid=n/2
		MM(A11,B11,n/2)+MM(A12,B21,n/2)
		MM(A11,B12,n/2)+MM(A12,B22,n/2)
		MM(A21,B11,n/2)+MM(A22,B21,n/2)
		MM(A21,B12,n/2)+MM(A22,B22,n/2)
	}
}
```

Funkcija samu sebe poziva rekurzivno na umanjenom problemu ($T(n/2)$) tj. dimenzija matrice se dijeli na dva dijela i ima osam takvih poziva. Plus prestavlja oznaku za zbrajanje matrica odnosno služi kombiniraju rješenja tj. vrijeme potrebno za zbrajanje dvije matrice od $n$ elemenata, a to je $n^2$. Navedeno vrijedi kada je $n$ veći od 2. Kada je $n$ manji ili jednak 2, koristimo one četiri formule za čije je izvođenje potrebna konstantna količina vremena (1)

Složenost 

Iz ovog proizlazi da će se i u slučaju primjene metode podijeli pa vladaj koristiti rekurzivni pozivi koji će koristiti memoriju organiziranu kao stog što implicira korištenje dodatnog podatkovnog prostora. Osim toga, složenost je kubna i kao kada smo koristili pristup za tri ugnježdene iteracije.

Definicija rekurzije:

$T(n) = 
\begin{cases} 
8T\left(\frac{n}{2}\right) + n^2 & \text{, za } n > 2 \\
1 & \text{, za } n \leq 2
\end{cases}$

---

Ako se nad tim primijeni Master teorem:
- $a = 8$, $b = 2$, $f(n) = n^2$
- $\log_b a = \log_2 8 = 3$
- $n^k = n^2$

---

Složenost će biti $\Theta(n^3)$.

Dakle, u pogledu prostora je pristup sa tri petlje bolji od metode podijeli pa vladaj.

### 18. Objasnite Strassenov algoritam i njegovu složenost.

Strassen je pristupio rješavanju ovog problema tako da je umjesto spomenute četiri formule ponudio vlastite formule pomoću kojih je broj množenja smanjio sa 8 na 7. U ovom su problemu važnija množenja od zbrajanja i oduzimanja jer ona iziskuju više vremena.

$P = (A_{11} + A_{22}) \cdot (B_{11} + B_{22})$  
$Q = (A_{21} + A_{22}) \cdot B_{11}$  
$R = A_{11} \cdot (B_{12} - B_{22})$  
$S = A_{22} \cdot (B_{21} - B_{11})$  
$T = (A_{11} + A_{12}) \cdot B_{22}$  
$U = (A_{21} - A_{11}) \cdot (B_{11} + B_{12})$  
$V = (A_{12} - A_{22}) \cdot (B_{21} + B_{22})$  

Da bi se dobilo četiri formule koje rješavaju problem množenja matrica dimenzija $2 \times 2$, formule koje je predložio Strassen se kombiniraju na sljedeći način:

$C_{11} = P + S - T + V$  
$C_{12} = R + T$  
$C_{21} = Q + S$  
$C_{22} = P + R - Q + U$  

Ako se opet primijeni podijeli pa vladaj i rekurzivni algoritam $MM$, rekurzivna relacije će biti:

$T(n) = 
\begin{cases} 
7T\left(\frac{n}{2}\right) + n^2 & \text{, za } n > 2 \\
1 & \text{, za } n \leq 2
\end{cases}$  

$\log_b a = \log_2 7 = 2.81$ 

Složenost će biti $O(n \log_2 7) = O(n^{2.81})$  jer se smanjio broj množenja, bez obzira što se povećao broj zbrajanja i oduzimanja.

### 19. Objasnite algoritam za pronalaženje medijana dva polja iste veličine i njegovu složenost.

* ULAZ: dva sortirana polja A i B od kojih je svako jednake veličine $n$
* IZLAZ: medijan polja C veličine $2n$ dobivenog spajanjem polja A i B

Primjer:

* $A[]={1,12,15,26,38}$
* $B[]={2,13,17,30,45}$
* $C[]={1,2,12,13,15,17,26,30,38,45}$

Srednje vrijednosti u poljima A i B su 15 i 17, srednja vrijednost u polju C je $(15+17)/2=16$

Obzirom da je veličina polja C u kojem tražimo medijan paran broj ($2n$), uzimamo srednje vrijednosti u poljima A i B, izračunamo njihov prosjek i zaokružimo ga na donju granicu $C=\lfloor(A+B)/2\rfloor$

Rješenje: usporedba medijana dva polja. Izračunavaju se medijani $m_1$ i $m_2$ za ulazna polja A i B. 

* Ako je $m_1=m_2$, vraća se $m_1$ (ili $m_2$). 
* Ako je $m_1 > m_2$, medijan se nalazi u jednom od sljedeća dva podskupa: 
  * od prvog elementa u polju A do $m_1$ (`A[0]`...`A[n/2]`) 
  * od $m_2$ do zadnje elementa u polju B (`B[n/2]`...`B[n-1]`) 
* Ako je $m_1 < m_2$, medijan se nalazi u jednom od sljedeća dva podskupa
  * od $m_1$ do zadnje elementa u polju A (`A[n/2]`...`A[n-1]`) 
  * od prvog elementa u polju B do $m_2$ (`B[0]`...`B[n/2]`)  
* Navedena procedura se ponavlja sve dok oba podpolja ne budu veličine 2
* Kad su polja A i B veličine 2, medijan se izračunava pomoću sljedeće formule:
  * $\text{Median} = \left\lfloor \frac{\max(A[0], B[0]) + \min(A[1], B[1])}{2} \right\rfloor$

Složenost $O(log \ n)$

### 20. Objasnite algoritam za pronalaženje maksimalne sume podskupa vrijednosti u polju i njegovu složenost.

* ULAZ: jednodimenzionalno polje u kojem su pohranjeni pozitivni i negativni cijeli brojevi
* IZLAZ: maksimalna suma podskupova susjednih vrijednosti pohranjenih u polju

Dijelimo polje na dva dijela. Pretpostavimo da znamo koja je suma vrijednosti u ta dva podpolja. Neka je X zadano polje, a Y podpolje u kojem se nalazi maksimalna suma polja X. Rezultat koji tražimo se može nalaziti:

* u lijevom podpolju što znači da je rezultat već izračunat
* u desnom podpolju što znači da je rezultat već izračunat
* u lijevom i desnom potpolju (započinje u lijevom i završava u desnom potpolju), no u tom slučaju moramo utvrditi o kojem se rezultatu radi
  * pronađemo maksimalnu sumu u lijevom podpolju i maksimalnu sumu u desnom podpolju te njihova kombinacija predstavlja rješenje problema

Cilj je utvrditi početni i završni indeks podskupa vrijednosti u polju čija je suma maksimalna. Polje dijelimo tako dugo dok ne dobijemo polje sačinjeno od jednog elementa što predstavlja bazu rekurzije. Vrijednost pohranjena u tom polju je ujedno i maksimalna suma podskupova u tom polju. Utvrđujemo maksimalnu sumu podskupa u lijevom podpolju (suma lijevog podskupa, SLP), desnom podpolju (suma desnog podskupa, SDP) i polju dobivenom spajanjem lijevog i desnog podskupa (suma spojenog podskupa, SSP)

Suma spojenog podskupa se dobiva tako da:

* od srednjeg elementa idemo na lijevu stranu i tražimo podskup vrijednosti koja ima maksimalnu sumu
* od srednje vrijednosti +1 idemo na desnu stranu i tražimo podskup koji ima maksimalnu sumu
* zbrojimo ono što smo pronašli u prethodna dva koraka

Najveća vrijednost od te tri predstavlja maksimalnu sumu podskupa promatranog (spojenog) polja: `max(SLP,SDP,SSP)`

Složenost: $\Theta(n \ log \ n)$

### 21. Nabrojite i objasnite prednosti i nedostatke primjene metode podijeli pa vladaj.

Prednosti:

* olakšava rješavanje teških problema
* primjenom višeprocesnog rada potproblema se rješavaju paralelno
* učinkovito koristi pričuvnu (eng. _cache_) memoriju bez zauzimanja puno prostora
* smanjuje vremensku složenost problema

Nedostaci:

* sastoji se od primjene rekurzije koja ponekad može biti spora
* učinkovitost ovisi o implementaciji logike
* ako se rekurzija ne upotrijebi na pravilan način, može rezultirati rušenjem sustava

## 13. Metoda pretraživanja s vraćanjem i metoda grananja i ograničenja

### 1. Na proizvoljnom primjeru objasnite primjenu metode pretraživanja s vraćanjem.

Pretpostavimo da imamo troje studenata (dva studenta i jednu studenticu) te u dvorani imamo slobodna tri sjedeća mjesta. Postavlja se pitanje na koliko načina možemo smjestiti tih troje studenata u spomenuta tri slobodna sjedeća mjesta. Odgovor je $3!$ odnosno na 6 načina. Nas zanimaju sve moguće kombinacije koje pri tome možemo dobiti. Rješenje zadanog problema se može prikazati u obliku stabla koje se naziva __stablo rješenja__ ili __stablo prostora stanja problema__. 

U našem problemu, svaka razina u stablu predstavlja jedno slobodno sjedeće mjesto (dakle, prva razina prvo sjedeće mjesto, druga drugo sjedeće mjesto, a treća razina treće sjedeće mjesto). Ako imamo dva studenta ($B_1$ i $B_2$) i jednu studenticu ($G_1$) stablo prostora stanja problema nastaje tako da uzimamo prvu osobu ($B_1$) i stavljamo ju na prvo slobodno mjesto, pa drugu na drugo slobodno mjesto ($B_2$) i treću osobu ($G_1$) na treće slobodno mjesto.

Obzirom da nemamo više osoba ni slobodnih mjesta, u sljedećem koraku se vraćamo korak natrag u stablo te uklanjamo $G_1$ sa trećeg mjesta i provjeravamo da li možemo na to mjesto staviti neku drugu osobu. Obzirom da nemamo više osoba koje bi mogle staviti na treće mjesto, vraćamo se korak natrag u stablu, uklanjamo $B_2$ sa drugog mjesta i provjeravamo da li možemo staviti neku drugu osobu na to mjesto. Obzirom da je $B_2$ već bio na drugom mjestu, a $B_1$ je na prvom mjestu, jedina osoba koju možemo smjestiti na drugo mjesto je $G_1$ dok na treće mjesto možemo staviti osobu $B_2$. 

Obzirom da nemamo više osoba ni slobodnih mjesta, u sljedećem koraku se vraćamo natrag u stablo te uklanjamo $B_2$ sa trećeg mjesta i provjeravamo da li možemo na to mjesto staviti neku drugu osobu. Obzirom da nemamo više osoba koje bi mogle staviti na treće mjesto, vraćamo se korak natrag u stablu, uklanjamo $G_1$ na drugog mjesta i provjeravamo da li možemo staviti neku drugu osobu na to mjesto. Obzirom da su $B_2$ i $G_1$ već bili na drugom mjestu, a $B_1$ je na prvom mjestu, nemamo više osoba koje bi mogli staviti na drugo mjesto, vraćamo se korak natrag u stablu te uklanjamo osobu $B_1$ sa prvog mjesta i provjeravamo koga od preostalih osoba možemo staviti na to mjesto, a da ta osoba već nije bila na prvom mjestu te se odlučujemo za osobu $B_2$. Na drugo mjesto stavljamo osobu $B_1$, a na treće $G_1$...

Postupak se ponavlja dok se u stablu ne nalaze sva moguća rješenja (u ovom slučaju njih 6)- Problemi koji se rješavaju pomoću ove metode često imaju zadana neka ograničenja koja je potrebno provjeriti te dobiti rješenja koja udovoljavaju tim ograničenjima. Pretpostavimo da je ograničenje u našem problemu da studentica $G_1$ ne smije sjediti između dva studenta ($B_1$ i $B_2$). Ako slijedimo postupak generiranja stabla prostora stanja problema, odnosno stabla rješenja iz prošlog primjera, dobit ćemo ukupno 4 rješenja koja udovoljavaju zadanom ograničenju, onda taj čvor dalje više ne razvijamo odnosno za njega kažemo da ga je ubila funkcija ograničenja.

### 2. Koja su obilježja metode pretraživanja s vraćanjem?

Ova metoda temelji se na potpunom pretraživanju stabla prostora stanja problema. Metoda funkcionira za probleme kod kojih se do rješenja može doći izvođenje niza jednostavnih odluka (ne nužno za optimizacijske i probleme odlučivanja). Metoda uvijek daje točno rješenje. Temelji se na primjeni pristupa grube sile (eng. _brute force approach_) prema kojem je potrebno isprobati sva moguća rješenja i odabrati željeno rješenje. Sličan pristup koristi i metoda dinamičkog programiranja koja je namijenjena rješavanju problema optimizacije, no metoda pretraživanja s vraćanjem se koristi kad nas zanimaju sva rješenja problema. Generalna metoda postupnog dolaska do rješenja problema koja ne jamči optimalno rješenje istog (za razliku od metode pohlepe i dinamičkog programiranja, nije namijenjena rješavanju problema optimizacije)

### 3. Koji su alternativni nazivi za metodu pretraživanja s vraćanjem?

* backtracking
* kombinatorni brute force

### 4. Koju vrstu problema rješavamo metodom pretraživanja s vraćanjem?

Služi za rješavanje problema sa zadovoljenjem postavljenih ograničenja. Rješenje velikog broja problema se sastoji od donošenja niza odluka. Primjerice, kod rješavanja problema naprtnjače donosimo odluku da li ćemo pojedini predmet staviti u naprtnjaču ili ne. Ovom se metodom inkrementalno dolazi do rješenja pri čemu se parcijalna rješenja koja ne udovoljavaju ograničenjima napuštaju.

### 5. Usporedite metodu pretraživanja s vraćanjem i pristup rješavanja problema grubom silom (eng. brute force).

Rekurzivna metoda koja predstavlja poboljšanje pristupa grube sile (eng. _brute force approach_). Dok pristup grubom silom vrednuje sve kandidate za rješenje problema, metoda pretraživanja s vraćanjem ograničava pretraživanje tako da eliminira sve kandidate koji ne udovoljavaju postavljenim ograničenjima. Zbog toga je metoda pretraživanja s vraćanjem učinkovitija od pristupa grubom silom. Koristi se kad imamo skup izbora, a ne znamo koji će izbor dovesti do točnog rješenje. Generira parcijalna rješenja koja mogu dovesti do cjelokupnog rješenja.

### 6. Objasnite primjenu stabla prostora stanja problema (stabla rješenja) u kontekstu metode pretraživanja s vraćanjem.

Rješenje se prikazuje kao $n$-torka ($x_1,x_2,...,x_n$) gdje se $x_i$ odabire iz konačnog skupa mogućih izbora $S_i$. Elementi koji tvore rješenje se odabiru na način da minimiziraju ili maksimiziraju kriterijsku funkciju $C(x_1,x_2,...,x_n)$. Pretpostavimo da je C skup ograničenja problema P dok je D skup rješenja koja udovoljavaju ograničenjima iz C:

* utvrđivanje da li je pojedino rješenje izvedivo (eng. _feasible_) ili ne predstavlja **problem odlučivanja**
* pronalaženje najboljeg rješenja predstavlja **problem optimizacije**
* ispis svih izvedivih rješenja predstavlja **problem pobrojenja**

Da bi riješila problem, ova metoda sistematski pretražuje skup svih izvedenih rješenja koji se naziva prostor rješenja. Svaki izbor (odluka) dovodi do novog skupa parcijalnih rješenja. Parcijalna rješenja se istražuju pretraživanjem prostora rješenja najprije u dubinu (eng. _depth first search, DFS_). Ako parcijalno rješenje udovoljava nekoj funkciji ograničenja, onda će se ono dalje istraživati pretraživanjem prostora najprije u dubinu. Ako parcijalno rješenje ne udovoljava ograničenju, onda se ono dalje ne istražuje već se algoritam vraća korak natrag te istražuje sljedećeg mogućeg kandidata za rješenje problema.Prostor rješenja se prikazuje stablom prostora stanja problema gdje korijen predstavlja početno stanje prije početka pretraživanja. Čvor u stablu prostora stanja problema je obećavajući ako predstavlja parcijalno konstruktivno rješenje koje može dovesti do kompletnog rješenja problema dok isti nije obećavajući ako krši ograničenja te se zbog toga isključuje iz daljnjeg razmatranja u procesu pronalaženja rješenja problema. List u stablu prostora problema ili predstavlja potpuno rješenje ili nije obećavajući čvor.

### 7. Objasnite primjenu metode pretraživanja s vraćanjem na primjeru rješavanja problema 0-1 naprtnjače.

Rješenje problema se zapisuje kao ($x_1,...,x_n$). Neka je $X=X_1 \times ... \times X_n$, pri čemu su $X_i$ skupovi iz kojih $i$-ta komponenta rješenja prima vrijednost. $P:X→R^+$ je __kriterijska funkcija__ koja pridružuje svakom rješenju vrijednost

Primjer 0-1 naprtnjače

* na primjeni pristupa grube sile se temelji i metoda grananja i ograničenja (eng. _branch and bound_). U slučaju metode pretraživanja s vraćanjem stablo prostora stanja problema se generira pretraživanjem najprije u dubinu (eng. _depth first search_,DFS) koje se ponaša kao preorder obilazak stabla
* kod metode grananja i ograničenja se stablo prostora stanja problema generira pretraživanjem najprije u širinu (eng. _breadth first search, BFS_), odnosno čvorovi se generiraju po razinama u stablu.

### 8. Usporedite načine pretraživanja prostora stanja problem

| Depth First Search (DFS)                                     | Breadth First Search (BFS)                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| lakše za izvesti (rekurzija)                                 | izvodi se iterativno                                         |
| bolje za probleme odlučivanja                                | bolje kad se traži _najkraće_ rješenje                       |
| bolje kada se traži jedno od više postojećih rješenja        | bolje kada neke grane stabla prostora stanja problema mogu biti beskonačne duljine |
| istražuje stablo prostora stanja problema u dubinu što dalje od korijena | istražuje stablo prostora stanja problema po razinama što bliže korijenu |
| implementacija se temelji na stogu (LIFO)                    | implementacija se temelji na redu (FIFO)                     |
| učinkovitiji i iziskuje manje memorije                       | sporiji i iziskuje više memorije                             |

### 9. Objasnite algoritam za rješavanje problema kraljica i njegovu složenost.

Imamo šahovsku ploču dimenzije $n \times n$ na koju trebamo smjestiti $n$ kraljica (figure koje se mogu kretati horizontalno, vertikalno i dijagonalno) na način da se krajice međusobno ne napadaju. Dakle, kraljice će se napadati ako se nalaze u istom retku, stupcu ili na dijagonali šahovske ploče. Zanima nas na koliko sve načina možemo postaviti kraljice da se one međusobno ne napadaju.

Problem sa jednom kraljicom je trivijalan. Nije moguće smjestiti 2 kraljice na šahovsku ploču dimenzije $2 \times 2$ kao ni 3 kraljice na šahovsku ploču dimenzija $3 \times 3$, a da se one međusobno ne napadaju. Minimalna dimenzija problema za koju je moguće pronaći rješenje je 4.

Kako bi reducirali ovaj kombinatorni problem, postavit ćemo još nekoliko ograničenja:

* svaka se kraljica može nalaziti samo u jednom (svom) retku (dakle, prva samo u prvom retku, druga samo u drugom retku, itd)
* u svakom stupcu se može nalaziti samo jedna kraljica
* kraljice se ne smiju napadati međusobno

Algoritam će raditi po redcima ploče. U svakom će se retku pokušati postaviti kraljica na svako od mogućih polja, te će se prijeći u drugi redak. Ako u nekom retku ne preostane ni jedno polje slobodno, treba se vratiti u prethodni redak i pokušati u prethodnom retku postaviti kraljicu na neko drugo mjesto. Ako ni u tom retku više nema mjesta, vraćamo se u prethodni redak itd. Ako generiramo stablo prostora stanja problema kada je $n=4$ (želimo smjestiti 4 kraljice na šahovsku ploču dimenzija $4x4$), a da pri tome ne uzimamo u obzir ograničenje dijagonalnog napadanja kraljica, imat ćemo:

* 1 korijen
* 4 čvora na prvoj razini
* svaki čvor prve razine će imati 3 čvora
* svaki čvor druge razine će imati 2 čvora na trećoj razini
* svaki čvor treće razine će imati 1 čvor na četvrtoj razini

Stablo će ukupno imati $1+4+(4\times3)+(4\times3\times2)+(4\times3\times2\times1)=65$ čvorova. Ako u obzir uzmemo ograničenje po kojem se kraljice ne smiju napadati dijagonalno, onda za problem dimenzije 4 dobivamo __dva__ rješenja pri čemu je drugo rješenje zrcalan odraz prvog rješenja, što znači da za problem 4 postoji samo jedno jedinstveno rješenje.

Može li se na šahovsku ploču postaviti 8 kraljica tako da ni jedna ne napda ni jednu drugu? 8 kraljica je moguće na ploču $8\times8$ razmjestiti na 4426165368 različita načina od čega samo 92 načina predstavljaju valjana rješenja gdje 12 predstavlja jedinstvena rješenja dok se preostalih 80 može generirati zrcaljenjem i rotiranjem.

```pseudocode
Algoritam N_QUEEN(k,n)
	for i <- 1 to n do
		if PLACE(k,i) then
			x[k] <- i
			if k==n then
				print [X...n]
			else
				N_QUEEN(k+1,n)
				end
			end
```

$N$ je broj kraljica. $K$ je broj kraljice koja se trenutno obrađuje, inicijalno postavljen na 1. Funkcija $PLACE(k,i)$ vraća `true` ako je $k$-tu kraljice moguće staviti u $i$-ti stupac. Ova funkcija popisuje pozicije prethodno postavljenih kraljica kako bi provjerila da li se dvije kraljice nalaze na dijagonali te da li se dvije kraljice nalaze u istom stupcu.

```pseudocode
Function PLACE(k,i)
	for j <- 1 to k - 1 do
		if x[j] == i OR (abs(x[j]-i) == abs(j-k)) then
			return false
			end
		end
	return true
```

Ako se dvije kraljice nalaze na pozicijama $(i,j)$ i ($k,l$) gdje su $i$ i $k$ stupci, a $j$ i $l$ redci na ploči, kraljice se dijagonalno napadaju ako vrijedi:

* $j – l = i - k$

  $j – l = k – i$

Iz navedenog proizlazi da se kraljice dijagonalno napadaju ako vrijedi $∣j−l∣=∣i−k∣$. $K$ je broj kraljice koja se razmatra, odnosno redak u kojem se ista nalazi. $l$ je broj stupca koji se razmatra za $k$-tu kraljicu. $x[j]$ - stupac kraljice koja se nalazi u retku $j$. Funkcija `abs()` vraća apsolutnu vrijednost argumenta. Polje x[] je n-torka rješenja. Kod metode pretraživanja s vraćanjem se na svakoj razini faktor grananja smanjuje za 1 i kreira novi problem veličine $(n-1)$. Kad imamo $n$ izbora, onda kreira $n$ različitih problema veličine $(n-1)$ na prvoj razini. Funkcija `PLACE` utvrđuje poziciju kraljice u vremenu $O(n)$, a poziva se $n$ puta. Prvu kraljicu možemo staviti u prvi stupac na $n$ načina, drugu kraljicu u drugi stupac na $n-1$ načina itd, što dovodi do složenosti $O(n \times (n-1) \times (n-2) \times ... \times 1)$. 

Rekurzivna relacija problema je $T(n)=n*T(n-1)+n^2$, složenost u najgorem slučaju $O(n^n)=O(n!)$.

### 10. Koje vrste rješenja postoje za problem kraljica?

_Vidi pitanje prije_

### 11. Objasnite algoritam za rješavanje problema sume podskupova i njegovu složenost.

Dano je $n$ različitih pozitivnih brojeva. Potrebno je pronaći sve kombinacije od tih brojeva koje daje sumu $M$.

* ULAZ: $w_1,...,w_n, M$
* IZLAZ: $\{(x_1,...,x_n):x \in \{0,1\},\sum x_i \cdot w_i=M\}$

```pseudocode
Algorithm SUB_SET_PROBLEM(i,sum,W,remSum){
	if FEASIBLE_SUB_SET(i)==1 then
		if (sum==W) then
			printX[1...i]
		end
	else
		X[i+1] <- 1
		SUB_SET_PROBLEM(i+1,sum+w[i]+1,W,remSum-w[i]+1)
		X[i+1] <- 0
		SUB_SET_PROBLEM(i+1,sum,W,remSum - w[i]+1)
		end
}
```

`i` - trenutni indeks elementa u skupu. `sum` - trenutna suma elemenata odabranih u podskupu. `W` - ciljana suma koja se      pokušava postići. `remSum` - preostala suma elemenata koji još nisu odrađeni. `FEASIBLE_SUB_SET(i)` provjerava uvjete po kojima je moguće nastaviti pretraživanje. Ako funkcija `FEASIBLE_SUB_SET(i)` vraća 1 i ako je trenutna suma jednaka `W`, tada se ispisuje trenutni odabrani podskup `X[1...i]`. Algoritam pokušava dodati ili izostaviti trenutni element i tako generira različite kombinacije podskupa.

Prvi rekurzivni poziv: Odabire trenutni element (`X[i+1] <- 1`), dodaje njegovu vrijednosti `w[i]` u sumu i oduzima ga od `remSum`. Drugi rekurzivni poziv: Ne odabire trenutni element (`X[i+1] <- 0`), zadržava trenutnu sumu i opet oduzima njegovu vrijednost od `remSum`.

```pseudocode
function FEASIBLE_SUM_SET(i)
	if (sum + remSum >= W) AND /(sum == W) OR (sum + w[i] + 1 <= W) then
		return 0
	end
	return 1
```

Ako zbroj trenutne sume `sum` i preostalog iznosa `remSum` nije barem jednak `W`, onda ne možemo dosegnuti `W`. Ako je trenutna suma `sum` već jednaka ciljanom iznosu `W`, tada smo postigli rješenje i ne trebamo nastaviti dalje. Ako je uvjet `sum + w[i] + 1 <= W` zadovoljen, tada znamo da se ne možemo približiti cilju čak ni dodavanjem `w[i] + 1`, pa se pretraživanje može zaustaviti. Ako je bilo koji od navedenih uvjeta istinit, funkcija `FEASIBLE_SUB_SET` vraća 0, što znači da se daljnje pretraživanje može zaustaviti jer nije moguće dosegnuti ciljanu sumu `W`. U stablu prostora problema na razini $i$ stablo ima $2^i$ čvorova. Ako imamo $n$ elemenata, stablo prostora stanja problema će biti sačinjeno od $1+2+2^+ 2^3 + ...+ 2^n$.

* Rekurzivna relacije je $T(n) = 1+2+2^+ 2^3 + ...+ 2^n=2^{n-1}-1$.
* Složenost: $O(2^n)$

### 12. Kako možemo poboljšati algoritam za rješavanje problema sume podskupova pomoću metode pretraživanja s vraćanjem i do čega ta poboljšanja vode?

Prvo poboljšanje:

* možemo _porezati_ grane stabla kada u nekoj grani suma prijeđe zadani $M$
  * ovo poboljšanje treba promatrati samo u onim grananjima kada za trenutni $i$ stavimo $x_i=1$, jer se inače suma ne mijenja od provjere napravljene od ($i-1)-om koraku

Drugo poboljšanje:

* možemo porezati one grane koje ne mogu dostići traženu sumu tj. one kod kojih, uzmemo li sve preostale predmete, nećemo dostići traženu sumu
  * ovo pobošljanje treba promatrati samo u onim grananjima kada za trenutni $i$ stavljamo $x_i=0$, jer se inače suma ne mijenja od provjere napravljene u ($i-1$)-om koraku
  * sumu ćemo računati na početku, te ako neku stvar ne uzmemo umanjiti sumu za njenu cijenu
* poboljšanja ovdje navedena vode nas do metode grananja i ograničenja

### 13. Na proizvoljnom primjeru objasnite primjenu metode grananja i ograničenja.

_vidi u skripti_

### 14. Koja su obilježja metode grananja i ograničenja?

Metoda rješavanja diskretnih, kombinatornih i matematičkih problema optimizacije koja generira stablo prostora stanja problema, te učinkovito pronalazi optimalno rješenje problema tako da reže sve one grane koje ne udovoljavaju ograničenju.

Premda je korisna za rješavanje problema od drugih optimizacijskih metoda kao što su metoda pohlepe i dinamičko programiranje, ista je sporija od njih te često iziskuje eksponencijalno vrijeme, ali se njega učinkovitost može povećati pažljivim odabirom grananja i ograničenja.

Funkcije ograničenja su heurističke funcije. Heuristička funkcija generira čvor koji maksimizira vjerojatnost boljeg pretraživanja ili minimizira vjerojatnost lošijeg pretraživanja. Ovisno da li je riječ o problemu maksimizacije ili problemu minimizacije, u daljnje se razmatranje odabire čvor sa najvećom odnosno najmanjom heurističkom vrijednosti, respektivno.

### 15. Koju vrstu problema rješavamo metodom grananja i ograničenja?

Metoda namijenjena rješavanju problema optimizacije i to isključivo problema minimizacije.

Generiranje stabla prostora stanja problema:

* FIFO (First In, First Out) koja se temelji na redu
* LIFO (Last in, First Out) koja se temelji na stogu
* LC (Least Cost) koje se temelji na najmanjem trošku

### 16. Na proizvoljnom primjeru objasnite generiranje prostora stanja problema kod rješavanja istog pomoću metode grananja i ograničenja.

Pretpostavimo da rješavamo problem redoslijeda zadataka sa rokovima. Imamo 4 zadatka. Problem maksimizacije profita. Da bi ga mogli riješiti primjenom metode grananja i ograničenja, pretvaramo ga u problem minimizacije penala. Za svaki čvor u stablu prostora stanja problema se određuju dvije vrijednosti:

* gornja granica (GG) kao suma svih penala osim onih koji su dio rješenja
* Trošak (T) kao suma svih penala do posljednjeg zadatka koji je razmatran

### 17. Objasnite algoritam za rješavanje problema redoslijeda zadataka s rokovima.

Ova je metoda nadogradnja metode pretraživanja s vraćanjem. LCS pretraživanje. Ne koristi se ni BFS ni DFS, već se svakom stanju definira isplativost i razvija se ona grana stabla koja ima najveću procjenjenu isplativost. Prema minimizacijskoj varijanti, ovo se pretraživanje naziva pretraživanje najmanje cijene (least/lowest cost). Funkcija procjene isplativosti je najčešće brza heuristika koja daje suboptimalno rješenje. Za čuvanje stanja koje trenutno razmatra koristi se ATP prioritetni red.

### 18. Objasnite algoritam za rješavanje problema „konjićev skok“ i njegovu složenost.

Na šahovsku je ploču $x \times n$ polja postavljen skakač. Cilj je da skakač prođe svako polje ploče u točno $n \times n -1$ poteza. Treba pronaći jedno takvo rješenje. Rješenje problema može imati dva završetka:

* ako je završna pozicija skakača jedan potez udaljeno od njegove početne pozicije na način da se tim potezom može vratiti u početnu poziciju i tako stvoriti petlju, govorimo o zatvorenom obilasku
* ako je završna pozicija skakača bilo gdje drugdje na ploči u odnosu na njegovu početnu poziciju, tada je riječ o otvorenom obilasku

Algoritam temeljimo na metodi pretraživanja s vraćanjem i to na BFS pretraživanju. Skakač u svakom trenutku može napraviti najviše 8 različitih poteza. Najprije je potrebno napraviti funkciju koja provjerava valjanost poteza u polje ($i,j$) na šahovskoj ploči: `IS_VALID(i,j,sol)`. `sol` je matrica u kojoj se nalaze svi potezi koje je skakač napravio. Potez je valjan ako se nalazu unutar šahovske ploče (ako se $i$ i $j$ nalaze između $1$ i $N$) i ako polje na koje želimo pomaknuti skakača već nije zauzeto. Sva slobodna polja na šahovskoj ploči ćemo označiti sa `sol[i][j] == -1`.

```pseudocode
IS_VALID(i,j,sol)
	if (i>=1 and i<=N and j<=N and sol[i][j]==-1)
		return TRUE
	return FALSE
```

Iz polja ($i,j$) na šahovskoj ploči je moguće napraviti 8 poteza pa ćemo alocirati dva polja koja će nam služiti za provjeru svih mogućih poteza iz promatranog polja. Prema tome, ako se skakač nalazi u polju ($i,j$) iteracijom kroz spomenuta dva polja možemo pronaći moguće poteze kao što su primjerice ($i+2,j+1$), ($i+1,j+2$), itd. 

Sad ćemo napraviti funkciju za pronalaženje rješenja gdje će argumenti iste biti matrica rješenja, polje na kojem se trenutno skakač nalazi (inicijalno će to biti ($1,1$)). brojač poteza i dva polja za provjeru mogućih poteza: `KNIGHT-TOUR(sol,i,j,step_count,x_move,y_move)`. Naprije provjeravamo da li je rješenje pronađeno, ako je pronađeno: `step_count == N*N`, funkcija vraća true.

```pseudocode
KNIGHT-TOUR(sol,i,j,step_count,x_move,y_move)
	if step_count == N*N
		return TRUE
```

U sljedećem koraku odabiremo jedan od mogućih poteza i provjeravamo da li on vodi do rješenja. Ako potez ne vodi do rješenja, tad odabiremo sljedeći od mogućih poteza. Ako nijedan od mogućih poteza ne vodi rješenjeu, vraća se `false`- Moguće poteze provjeravamo iteracijom kroz polja `x_move` i `y_move`.

```pseudocode
KNIGHT-TOUR(sol,i,j,step_count,x_move,y_move)
	...
	for k in 1 to 8
		next_i = i + x_move[k]
		next_j = j + y_move[k]
```

Sada trebamo provjeriti da li je polje (`i+x_move[k],j+y_move[k]`) valjano ili nije. Ako je valjano, onda možemo napraviti potez skakačem na to polje.

`sol[i+x_move[k]][j+y_move[k]] = step_count`

Isto tako, provjeravamo da li nas taj put vodi do rješenja ili ne.

`if KNIGHT-TOUR(sol,i+x_move[k],j+y_move[k], step_count+1,x_move,y_move)`

Vraćamo `True` ako put vodi do rješenja.

```pseudocode
KNIGHT-TOUR(sol, i, j, step_count, x_move, y_move)
    ...
    for k in 1 to 8
        ...
        if IS-VALID(i + x_move[k], j + y_move[k])
            sol[i + x_move[k]][j + y_move[k]] = step_count
            if KNIGHT-TOUR(sol, i + x_move[k], j + y_move[k], step_count + 1, x_move, y_move)
                return TRUE
```

Ako nas potez ne vodi do rješenja, onda odabiremo neki drugi potez (petlja će iterirati u sljedeći potez). Osim toga, polje (`i+x_move[k],j+y_move[k]`) u matrici rješenja ćemo postaviti na $-1$ obzirom da smo provjerili taj put te nas on ne vodi do rješenja. Na kraju se vraća false ako ga ne vrati nijedan od prethodnih koraka.

```pseudocode
KNIGHT-TOUR(sol, i, j, step_count, x_move, y_move)
    ...
    for k in 1 to 8
        ...
        sol[i + x_move[k], j + y_move[k] = -1]
    return FALSE

KNIGHT-TOUR(sol, i, j, step_count, x_move, y_move)
    if step_count == N * N
        return TRUE

    for k in 1 to 8
        next_i = i + x_move[k]
        next_j = j + y_move[k]
        if IS-VALID(next_i, next_j, sol)
            sol[next_i][next_j] = step_count
            if KNIGHT-TOUR(sol, next_i, next_j, step_count + 1, x_move, y_move)
                return TRUE
            sol[next_i][next_j] = -1
    return FALSE
```

Imamo $n \times n$ polja na šahovskoj ploči i maksimalno 8 mogućih poteza iz polja, pa je najgori slučaj izvođenja složenosti $O(8^{n^2})$.

Međutim, nemamo iz svakog polja jednaki broj poteza. Primjerice, iz prvog polja su moguća samo 2 poteza. Ako to uzmemo u obzir, tad se vrijeme izvođenja reducira za faktor i postaje $O(k^{n^2})$, no to je i dalje loše vrijeme izvođenja

### 19. Objansite algoritam za rješavanje problema 0-1 naprtnjače i njegovu složenost.

Moguće je staviti cijeli objekt ili ga ne staviti u naprtnjaču, nije moguće staviti samo dio objekta. Riječ je o problemu maksimizacije profita. Obzirom da je metoda grananja i ograničenja namjenjena rješavanju problema minimizacije, potrebno je problem maksimizacije pretvoriti u problem minimizacije tako da stavke profita pretvorimo u negativne vrijednosti te ih po rješenju problema ponovno vraćamo u pozitivne vrijednosti. 

Koristit ćemo __LCS__. Za svaki čvor u stablu prostora stanja problema potrebno je odrediti:

* __gornju granicu__ (eng. _upper bound_) - uzimaju se cijeli objekti
* __trošak__ (eng. _cost_) - uzimaju se dijelovi objekata, samo za potrebe izračuna

Gornja granica i trošak predstavljaju sumu profita. Trošak se izračunava kao suma profita svih predmeta koji stanu u naprtnjaču koji se zbraja sa omjerom profita i težine predmeta koji ne stane u naprtnjaču pomnožen sa razlikom kapaciteta naprtnjače i sume težine predmeta koji su cijeli stali u naprtnjaču.

Rješenje može biti:

* varijabilno (podskup objekata) - npr $S = \{x_1,x_2\}$
* fiksno (svi objekti uz naznaku da li su uključeni ili nisu) - npr. $S=\{1,0,1,0\}$

Mi ćemo prikazati fiksno rješenje problema.

*  $V=15$
* gornja granica = $\infty$

1. Trošak za prvi čvor (korijen u stablu prostora stanja problema)
   * uzimamo prva tri objekta jer ako dodamo i četvrti, premašuje se $V$
   * suma težine prva tri objekta je $2+4+6=12$
   * od obujma naprtnjače se oduzima težina objekata koji su u nju stavljeni čime dobivamo preostali kapacitet naprtnjače: $15-12=3$
   * izračun troška za prvi čvor: $10+10+12+(18/9)*3=38$
   * trošak prvo čvora je $-38$
   * gornja granica za prvi čvor (suma istih vrijednosti kao i za trošak, samo bez razlomaka): $10+10+12=32$ (također uzimamo negativnu vrijednost)
   * obzirom da je -32 manje od beskonačno, gornja granica postaje -32
2. Gornja granica i trošak za drugi čvor (lijevo dijete korijena - prvi objekt je uključen, ostaje isti ($-32$ i $-38$))
3. Trošak za treći čvor (desno dijete korijena - prvi objekt nije uključen)
   * uzimamo drugi i treći objekt jer ako dodamo i četvrti, premašuje se $V$
   * suma težine drugog i trećeg objekta je $4+6=10$
   * od obujma naprtnjače se oduzima težina objekta koji su u nju stavljeni čime dobivamo preostali kapacitet naprtnjače: $15-10=5$
     * izračun troška = $10+12+(18/9)*5=32$
     * trošak trećeg čvora je $-32$
   * gornja granica trećeg čvora: $10+12=22$, dakle $-22$
   * za svaki se čvor provjerava da li je njegov trošak veći od trenutne gornje granice. Ako jest, onda se ta grana više ne razvija.
   * Obzirom da je trošak trećeg čvora ($-32$) jednaka trenutnoj gornjoj granici, grana se dalje može razvijati.
   * Za svaki se čvor provjerava da li je njegova gornja granica manja od trenutne gornje granice. Ako jest, potrebno je ažurirati gornju granicu. U našem se slučaju nije, pa gornja granica ostaje $-32$. Obzirom da slijedimo LCS, manji trošak ima drugi čvor (lijevo dijete korijena: $-32$), tako da dalje njega razvijamo
4. Gornja granica i trošak za četvrti čvor (lijevo dijete drugog čvora - drugi objekt je uključen)
5. Trošak za peti čvor (desno dijete drugog čvora - drugi objekt nije uključen)
   * uzimamo prvi i treći objekt jer ako dodamo i četvrti, premašuje se $V$
   * suma težina prvog i trećeg objekta je $2+6=8$
   * od obujma naprtnjače se oduzima težina objekata koji su u nju stavljeni čime dobivamo preostali kapacitet naprtnjače: $15-8=7$
   * izračun troška: $1+12+(18/9)*7=36$
   * trošak čvora je -36
   * gornja granica petog čvora: $10+22=22$, dakle $-22$
   * Da slijedimo FIFO pristup, razvijali bi šesti čvor kao lijevo dijete trećeg čvora
   * međutim, kako slijedimo LCS pristup jer njime brže dolazimo do rješenja, razmatramo trošak trećeg ($-32$), četvrtog ($-38$) i petog čvora ($-36$), koji su trenutno listovi u stablu
   * obzirom da četvrti čvor ima najmanji trošak, dalje njega razvijamo
6. gornja granica i trošak za šesti čvor (lijevo dijete četvrtog čvora - treći objekt je uključen) ostaje $-32$ i $-38$
7. Trošak za sedmi čvor (desno dijete četvrtog čvora - treži objekt nije uključen)
   * uzimamo prvi, drugi i četvrti objekt
   * suma težina objekta je 15
   * izračun troška: $10+10+18=38$
   * trošak čvora je $-38$
   * Gornja granica sedmog čvora: $10+10+18=38$, dakle $-38$
   * gornja granica sedmog čvora je manja od trenutne gornje granice pa istu treba ažurirati na $-38$
   * Dalje se razmatraju težine aktivnih čvorova
   * Kada su trošak trećeg ($-32$) i ($-36$) veće od gornje granice ($-38$), njih dalje nećemo razvijati
   * Šesti i sedmi čvor imaju isti trošak, no kako razvijanje šestog čvora pretpostavlja razmatranje četvrtog objekta za što znamo da nije moguće rješenje, nastavljamo sa razvojem sedmog čvora
8. Gornja granica i trošak za osmi (lijevo dijete sedmi čvor - četvrti objekt je uključen) ostaje $38$ i $-38$
9. Trošak za deveti čvor (desno dijete sedmog čvora - četvrti objekt nije uključen)
   * uzimamo prvi i drugi objekt
   * suma težina objekta je $2+4=6$
   * izračun troška: $10+10=20$
   * trošak čvora je $-20$
   * obzirom da je trošak devetog čvora veći od trenutne gornje granice, on se dalje ne razvija
   * Jedini preostali aktivan čvor je osmi te put od korijena do njega predstavlja rješenje, a ono je $S=\{1,1,0,1\}$, ukupan profit je $10+10+18=38$, a iskorišteni kapacitet naprtnjače je $2+4+9=15$

### 20. Usporedite metodu pretraživanja s vraćanjem sa metodom grananja i ograničenja.

| Pretraživanje s vraćanjem                                    | Grananje i ograničenja                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| rješava problem odlučivanja                                  | rješava probleme optimizacije                                |
| čvorovi se u stablu prostora stanja problema generiraju pretraživanjem najprije u dubinu | čvorovi se u stablu prostora stanja problema generiraju pretraživanjem najprije u širinu |
| kada donesu lošu odluku ili odabir, poništava ga vraćanjem korak unatrag | odustaje od trenutnog optimalnog rješenja kad naiđe na bolje optimalno rješenje |
| temelji se na funkciji izvodivosti                           | temelji se na funkciji ograničenja                           |
| sljedeći korak može dovesti do loše odluke ili odabira       | sljedeći korak uvijek vodi prema optimalnom rješenju         |
| pretraživanje se zaustavlja uspješnim pronalaženjem rješenja u stablu prostora stanja problema | da bi se pronašlo optimalno rješenje, potrebno je pretražiti cijelo stablo prostora stanja problema |
| učinkovitije od grananja i ograničenja                       | ima manju učinkovitost od pretraživanja s vraćanjem          |

## 14. Metoda dinamičkog programiranja

### 1. Nabrojite i objasnite obilježja metode dinamičkog programiranja.

Jednako kao i metoda pohlepe služi rješavanju problema optimizacije. Za razliku od metode pohlepe kod koje se slijedi određena procedura da bi se pronašlo optimalno rješenje, kod dinamičkog programiranja se pronalaze sva rješenja te se odabire najbolje. Zbog toga provedba dinamičkog programiranja iziskuje više vremena od metode pohlepe. Problemi se najčešće rješavaju primjenom rekurzivnih formula.

Od programskim konstrukata se u pravilu koriste iteracije, a ne rekurzije. Dinamičko programiranje slijedi princip optimalnosti prema kojem se problem može riješiti temeljem slijeda odluka. Prema tome, kod metode pohlepe se odluka donosi jednom, a kod dinamičkog programiranja u svakoj iteraciji provedbe metode.

Imamo 15 poziva za izračun petog člana Fibbonaccijevog niza. Obzirom da temeljem $n-2$ ne možemo doći do zaključka, radimo aproksimaciju rekurzivne relacije sa $n-1$

* $T(n)=2T(n-1)+1$
* riječ je o dva rekurzivna poziva i zbrajanju (1)

Prema Master teoremu za opadajuće funkcije, složenost je $O(2n)$ i to je gornja granica složenosti algoritma. Možemo primjetiti da se pojedini pozivi funkcije ponavljaju. Kako bi smanjili složenost algoritma, pohraniti ćemo rezultat poziva funkcije sa istim argumentom u globalno polje tako da se isti više ne mora pozivati. Riječ je konceptu __memoizacije__.

_Fibbonaccijev niz_

Primjenom koncepta memoizacije, broj poziva funkcije je sa 15 smanjen na 6. Za $Fib(n)$ će biti potrebno $n+1$ poziva funkcije čime je složenost algoritma sa eksponencijalne smanjena na linearnu - $O(n)$. Nije uvijek slučaj da primjena memoizacije rezultira toliko drastičnim smanjenjem složenosti. Iz primjera je vidljivo da se primjenom memoizacije generira stablo, izbjegavaju se nepotrebni pozivi funkcija, te se rezultat dobiva potrebnim pozivima funkcija čiji su rezultati pohranjeni u globalno polje. Iz tog se razloga memoizacija još naziva __top-down pristup__. 

Pored memoizacije, u dinamičkom se programiranju češće se koristi iterativni pristup odnosno pristup __tabeliranja__ (eng. _tabulation_). Kod primjene tabelarnog pristupa, rješenje odnosno globalno polje se generira od manjih vrijednosti prema većima pa ga nazivamo još i __bottom-up pristup__. Primjenom dinamičkog programiranja možemo razviti vlastiti pristup za rješavanje problema.

### 2. Koju vrstu problema rješavamo metodom dinamičkog programiranja?

### 3. Usporedite metodu dinamičkog programiranja i metodu pohlepe.

### 4. Nabrojite i objasnite pristupe koji se koriste u rješavanju problema pomoću metode dinamičkog programiranja.

### 5. Na proizvoljnom primjeru objasnite pristup memoizacije.

### 6. Na proizvoljnom primjeru objasnite pristup tabeliranja.

### 7. Objasnite algoritam za rješavanje problema 0-1 naprtnjače i njegovu složenost.

Cjelobrojna naprtnjača. $V$ - obujam naprtnjače, $p$ - cijena, $w$ - obujam predmeta. Stupci označavaju da nećemo odmah razmatrati sav kapacitet naprtnjače nego ćemo u svakoj iteraciji isti povećati za 1. Retci označavaju da nećemo odmah razmatrati sve objekte, već najprije nijedan, pa samo prvi, pa prvi i drugi itd. Odnosno, kada smo u $n$-tom retku, razmatramo sve objekte od tog retka uključujući i objekt u $n$-tom retku. U ćelije se upisuje ostvareni profit. 

Ako ne uključimo nijedan objekt, onda prvi redak popunjavamo nulama jer ne ostvarujemo nikakav profit. Ako je riječ o naprtnjači kapaciteta nula, također ne ostvarujemo profit, tako da prvi stupac isto popunjavamo nulama. 

Sada razmatramo prvi objekt težine 2 pa njegov profit pohranjujemo u stupac 2. Obzirom da ne možemo objekt težine 2 smjestiti u naprtnjaču težine 1, u ćeliju stupca 1 prepisujemo vrijednost iz prethodne ćelije koja se nalazi u istom stupcu, dakle 0. Bez obzira na povećanje kapaciteta naprtnjače, mi i dalje razmatramo samo prvi objekt, pa će profit za sve ostale pacitete naprtnjale iznositi 1.

U sljedećoj iteraciji razmatramo prvi i drugi objekt. Drugi objekt možemo staviti u naprtnjaču samo kada je njen kapacitet jednak težini drugog objekta, dakle 3, pa ostvarujemo profit 2. Za manje težine naprtnjače prepisujemo vrijednosti iz prethodnog retka. Ako uzmemo u obzir prvi i drugi objekt, njihova težina je 5 što znači da ih možemo staviti zajedno u naprtnjaču kada je njen kapacitet 5 te profit tada iznosi 3. U prethodnu ćeliju se stavlja vrijednost ili iz prethodnog retka ili stupca, ovisno koja je veća, jer težimo maksimizaciji profita, pa u istu stavljamo vrijednost 2. Bez obzira na povećanje kapaciteta naprtnjače, mi i dalje razmatramo samo prvi i drugi objekt, pa će profit za sve ostale kapacitete naprtnjače iznositi 3.

U sljedećoj iteraciji razmatramo prvi, drugi i treći objekt. Treći objekt možemo staviti u naprtnjaču samo kada je njen kapacitet jednak težini trećeg objekta, dakle 4, pa ostvarujemo profit 5. U ovom trenu možemo sa prvim i drugim objektom popuniti kapacitet naprtnjače od 5, ali se ostvaruje manji profit nego ako u naprtnjaču stavljamo treći objekt. Kada razmatramo prvi i treći objekt, njihova težina iznosi 6, a profit koji ostvaruje je također 6. Kada razmatramo drugi i treći objekt, njihova težina iznosi 7, a profit koji ostvarujemo je također 7. Za manju težinu naprtnjače prepisujemo vrijednost iz prethodnog retka, dakle 5. Kako ne možemo uključiti sva tri objekta jer svi zajedno teže 10, u stupcu prepisujemo vrijednost iz prethodne ćelije u istom retku, dakle 7.

Iz navedenog proizlazi da se tablica može popunjavati prema formuli:

$V[i, w] = \max\{V[i-1, w], V[i-1, w-w[i]] + P[i]\}$  

$V[4, 1] = \max\{V[3, 1], V[3, 1-5] + 6\}$  

$V[4, 1] = \max\{V[3, 1], V[3, -4] + 6\}$  

Nedefinirana vrijednost je označena crvenom bojom pa se u obzir uzima samo vrijednost označena zelenom bojom. Negativne vrijednosti će se dobivati do težine 5 zbog čega se vrijednosti u ćelijama do iste prepisuju iz prethodnog retka.

$V[4, 5] = \max\{V[3, 5], V[3, 5-5] + 6\} = \max\{5, 0 + 6\} = 6$  

$V[4, 6] = \max\{V[3, 6], V[3, 6-5] + 6\} = \max\{6, 0 + 6\} = 6$  

$V[4, 7] = \max\{V[3, 7], V[3, 7-5] + 6\} = \max\{7, 1 + 6\} = 7$  

$V[4, 8] = \max\{V[3, 8], V[3, 8-5] + 6\} = \max\{7, 2 + 6\} = 8$  

Tablica se može i direktno popuniti, bez korištenja formula. 

Četvrti objekt možemo staviti u naprtnjaču samo kad je njen kapacitet jednak težini objekta, dakle 5, pa ostvarujemo profit 6. Za manje težien naprtnjače prepisujemo vrijednosti iz prethodnog retka. Kombinacijom četvrtog i drugog objekta popunjavamo težinu 7 i ostvarujemo profit 7, a za manju težinu prepisujemo vrijednost iz prethodnog retka. Kombinacijom četvrtog i drugog objekta popunjavamo težinu 8 i ostvarujemo profit 8.

### 8. Objasnite algoritam za rješavanje problema ulančanog množenja matrica i njegovu složenost.

Neka je dano $k$ matrica $M_0,...M_{p-1}$. Neka je matrica $M_i$ dimenzija $m_i \times n_i$. Za svaki $k=2,...,p$ vrijedi da je $m_{k-1}=n_k$. Meta-problem je izračunati $M_0 \times M_{p-1}$. 

Problem je učiniti to u čim je manje moguće operacija. Kako je množenje matrica asocijativno, potrebno je odrediti kojim redoslijedom treba množiti matrice da bi se minimizirao ukupan broj operacija. Pogledajmo koliko je potrebno operacija za množenje matrica dimenzije $i \times j$ i $j \times k$.

* $A = 2 \times 3$
* $B=3\times2$
* $C=2\times2$

Broj množenja je $2 \times 3 \times 2 =12$. Jasno je da ovaj algoritam radi s $i \times j \times k$ zbrajanja i isto toliko množenja. Rezultat je matrica dimenzija $i \times k$.

_Ulanačano množenje matrica_

* $A_1 = 2 \times 3, \quad A_2 = 3 \times 4, \quad A_3 = 4 \times 2$  
* $A_1 \times A_2 \times A_3$

Kojim redoslijedom množiti matrica da broj množenja bude što manji?

* $A_1 \times A_2 \times A_3$  
* $A_4 = A_1 \times A_2 = 2 \times 3 \times 4 = 24$  
* $A_5 = A_4 \times A_3 = 2 \times 4 \times 2 = 16$

Ukupan broj množenja = 40

* $A_1 \times A_2 \times A_3$  
* $A_4 = A_2 \times A_3 = 3 \times 4 \times 2 = 24$  
* $A_5 = A_1 \times A_4 = 2 \times 3 \times 2 = 12$  

Ukupan broj množenja = 36

* $A_1 = d_0 \times d_1 = 2 \times 3,$  
* $A_2 = d_1 \times d_2 = 3 \times 4,$  
* $A_3 = d_2 \times d_3 = 4 \times 2$  
* $A_1 \times A_2 \times A_3$

Kojim redoslijedom množiti matrice da broj množenja bude što manji?

* $A_1 \times A_2 \times A_3$ 
*  $A_4 = A_2 \times A_3 = 3 \times 4 \times 2 = 24$
*  $C_{1, 1} = 0$ 
* $C_{2, 3} = 24$   $A_5 = A_1 \times A_4 = 2 \times 3 \times 2 = 12$
* $d_0 \times d_1 \times d_3$

Ukupan broj množenja: $C_{i, k} + C_{k+1, j} + d_{i-1} \times d_k \times d_j = C_{1, 1} + C_{2, 3} + d_0 \times d_1 \times d_3 = 36$

_Formula za izračun troška ulančanog množenja matrica_

$C_{i, k} + C_{k+1, j} + d_{i-1} \times d_k \times d_j = C_{1, 1} + C_{2, 3} + d_0 \times d_1 \times d_3 = 36$

Broj mogućih kombinacija množenja dobiva se primjenom Katalonovog broja uz modifikaciju da se umjesto $n$ koristi $n-1$.

$\frac{2(n-1)c_{n-1}}{n}$

Iz primjera je vidljivo da ovakav pristup nije učinkovit. Osim toga, potrebno je primijeniti da se pojedine kombinacije $C[i,j]$ ponavljaju. Zbog toga ćemo naprije krenuti u pronalaženje izračuna minimalnog troška od manje prema većoj razlici između $i$ i $j$ u $C[i,j]$.

Za pohranu rezultata koristit ćemo dvije tablice. U tablici $C$ u kojoj će $i$ biti retci, a $j$ stupci će pohranjivati trošak množenja pri čemu ćemo istu po dijagonali popuniti nulama (poznate vrijednosti) odnosno tamo gdje je razlika između $i$ i $j$ jednaka 0, zatim iznad dijagonale popunjavamo ćelije gdje je razlika između $i$ i $j$ jednaka 1, itd.

U tablici $K$ ćemo pohranjivati vrijednost od $k$ za koju smo pronašli minimalni trošak.

Složenost:

* Broj vrijednosti u tablici: $1+2+3+4 = \frac{4(4+1)}{2}$
* za $n$ matrica vrijedi: $\frac{n(n+1)}{2}=n^2$
* da bi se dobila vrijednost, razmatra se $n$ vrijednosti od $k$ između $i$ i $j$: $n^2 \times n = O(n^3)$

### 9. Objasnite algoritam za rješavanje problema kreiranja optimalnog binarnog stabla pretraživanja i njegovu složenost.

Maksimalan broj usporedbi je jednak visini stabla i predstavlja trošak pretraživanja u slučaju kada je isto uspješno (vrijednost je pronađena) i kada pretraživanje nije uspješno (vrijednost nije pronađena). Za $n$ vrijednosti moguće je konstruirati $T(n)=\frac{2n_{c_n}}{n+1}$ binarnih stabala pretraživanja (BST).

Za vrijednost: $10,20,30: T(3)$

* $= \frac{2 \cdot 3C_3}{4} = \frac{6C_3}{4} = \frac{\binom{6}{3}}{4} = \frac{\frac{6 \cdot 5 \cdot 4}{3 \cdot 2 \cdot 1}}{4} = 5$

Želimo pronaći BST sa minimalnom visinom odnosno minimalnim brojem usporedbi. Ukoliko imamo $n$ vrijednosti, imat ćemo $n+1$ (null) čvorova koji rezultira neuspješnim pretraživanjem (označavaju se sa kvadratom). Kod rješavanja problema u obzir uzimamo vjerojatnost čija suma mora biti jednaka 1.

Postoje dvije vjerojatnosti:

* vjerojatnost uspješnog pretraživanja ($p_i$) za vrijednost koje se nalaze u BST($p_i$)
* vjerojatnost neuspješnog pretraživanja ($q_i$) za vrijednosti koje se ne nalaze u BST, odnosno manje su ili veće od pojedine vrijednosti koje se nalaze u BST

Vremenska složenost: $\Theta(n^3)$, zbog triju ugniježđeni petlji ($m,i,r$)

Prostorna složenost: $\Theta(n^2)$ za pohranu $e,w,i$ root
