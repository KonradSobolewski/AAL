Sobolewski Konrad 270820 AR

AAL - 10 - LS HOTEL
Grupê n osób nale¿y zakwaterowaæ najtaniej w hotelu tak ,aby ka¿da osoba osobiœcie lub poprzez przyjaciela mia³a dostêp do telewizora i ³azienki( nie wystêpuje pokoj z obiema rzeczami).

Aby program wykona³ siê poprawnie nale¿y wpierw wprowadziæ iloœæ osób do zakwaterowania (2) , nastêpnie wprowadziæ lub wygenerowaæ losowo relacje miêdzy nimi (3) , u¿yæ algorytmu do znajdowania przybli¿onego optymalnego rozwi¹zania (4), oraz wyœwietliæ wynik(5). Mo¿na tak¿e zobacz szczegó³owe informacje o grafie (6). 

Konwencje danych wejœciowych i wyników:
- liczba osób n>1,
- liczba relacji m>=n-1 && m<n*(n-1)/2,
- po wykonaniu wiêkszoœæ operacji nale¿y wcisn¹æ ponownie dowolny guzik ,aby   przejœæ do dalszych etapów,
- prezentowanymi wynikami to:
	a) liczba osób z pokoiem z telewizorem,
	b) liczba osób z pokoiem z ³azienk¹,
	c) liczba osób z pokoiem z pustym pokoiem,
	d) rachunek zakwaterowania wszystkich osób,
	e) czas wykonywania algorytmu.
- prezentowane informacje w testach:
	a) suma znajomych w krawêdzi
	b) znajomi poszczególnej osoby
	c) przydzielony pokój poszczególnym osobom

Do rozwi¹zania zadania wystêpuj¹ 4 struktury danych: Person,Edge,Menu,AboutAlgorithm

Person:  przechowuje informacje o iloœci swoich znajomych,swoje id,pokój 		jaki zosta³ jej przydzielony , oraz czy wyst¹pi³a w czasie 			wykonywania algorytmu

Edge:	przechowuje informacje o krawêdzi grafu , gdzie jego wierzcho³kami jest 	dwóch znajomych oraz wspóln¹ sumê znajomych w krawêdzi.

Menu :  s³u¿y do interfejsu oraz procesów tworzenia danych.

AboutAlgorithm : Zawiera funkcje potrzebne do rozwi¹zania problemu.

Algorytm przydzielania pokoi:
Polega on na przeszukiwaniu krawêdzi grafu. Aby zwiêkszyæ prawdopodobieñstwo problemu krawêdzie zosta³y posortowane malej¹co wzglêdem sumy znajomych w krawêdzi. Nastêpnie z krawêdzi jest wybierana osoba która ma wiêcej znajomych. Zabiegi te pozwalaj¹ nam na zaczêcie przypisywania pokoi od osoby która ma najwiêkszy wp³yw w grafie . Im wiêcej osób ma do niej dostêp , tym bardziej mo¿liwe ,¿e jego znajomi dostan¹ tañszy pokój. Dla wybranej osoby sprawdzamy , wszystkich znajomych jakich posiada i wzglêdem przyjaciela z krawêdzi przydzielamy jej pokój. Nastêpnie ta sama procedura jest wykonywana dla drugiego wierzcho³ka krawêdzi. Dok³adna procedura opisana w pe³nej dokumentacji.

Program przyjmuje jako dane wejœciowe jedynie cyfry . Istniej¹ metody zabezpieczaj¹ce przed wprowadzeniem innych danych.
	