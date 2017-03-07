Sobolewski Konrad 270820 AR

AAL - 10 - LS HOTEL
Grup� n os�b nale�y zakwaterowa� najtaniej w hotelu tak ,aby ka�da osoba osobi�cie lub poprzez przyjaciela mia�a dost�p do telewizora i �azienki( nie wyst�puje pokoj z obiema rzeczami).

Aby program wykona� si� poprawnie nale�y wpierw wprowadzi� ilo�� os�b do zakwaterowania (2) , nast�pnie wprowadzi� lub wygenerowa� losowo relacje mi�dzy nimi (3) , u�y� algorytmu do znajdowania przybli�onego optymalnego rozwi�zania (4), oraz wy�wietli� wynik(5). Mo�na tak�e zobacz szczeg�owe informacje o grafie (6). 

Konwencje danych wej�ciowych i wynik�w:
- liczba os�b n>1,
- liczba relacji m>=n-1 && m<n*(n-1)/2,
- po wykonaniu wi�kszo�� operacji nale�y wcisn�� ponownie dowolny guzik ,aby   przej�� do dalszych etap�w,
- prezentowanymi wynikami to:
	a) liczba os�b z pokoiem z telewizorem,
	b) liczba os�b z pokoiem z �azienk�,
	c) liczba os�b z pokoiem z pustym pokoiem,
	d) rachunek zakwaterowania wszystkich os�b,
	e) czas wykonywania algorytmu.
- prezentowane informacje w testach:
	a) suma znajomych w kraw�dzi
	b) znajomi poszczeg�lnej osoby
	c) przydzielony pok�j poszczeg�lnym osobom

Do rozwi�zania zadania wyst�puj� 4 struktury danych: Person,Edge,Menu,AboutAlgorithm

Person:  przechowuje informacje o ilo�ci swoich znajomych,swoje id,pok�j 		jaki zosta� jej przydzielony , oraz czy wyst�pi�a w czasie 			wykonywania algorytmu

Edge:	przechowuje informacje o kraw�dzi grafu , gdzie jego wierzcho�kami jest 	dw�ch znajomych oraz wsp�ln� sum� znajomych w kraw�dzi.

Menu :  s�u�y do interfejsu oraz proces�w tworzenia danych.

AboutAlgorithm : Zawiera funkcje potrzebne do rozwi�zania problemu.

Algorytm przydzielania pokoi:
Polega on na przeszukiwaniu kraw�dzi grafu. Aby zwi�kszy� prawdopodobie�stwo problemu kraw�dzie zosta�y posortowane malej�co wzgl�dem sumy znajomych w kraw�dzi. Nast�pnie z kraw�dzi jest wybierana osoba kt�ra ma wi�cej znajomych. Zabiegi te pozwalaj� nam na zacz�cie przypisywania pokoi od osoby kt�ra ma najwi�kszy wp�yw w grafie . Im wi�cej os�b ma do niej dost�p , tym bardziej mo�liwe ,�e jego znajomi dostan� ta�szy pok�j. Dla wybranej osoby sprawdzamy , wszystkich znajomych jakich posiada i wzgl�dem przyjaciela z kraw�dzi przydzielamy jej pok�j. Nast�pnie ta sama procedura jest wykonywana dla drugiego wierzcho�ka kraw�dzi. Dok�adna procedura opisana w pe�nej dokumentacji.

Program przyjmuje jako dane wej�ciowe jedynie cyfry . Istniej� metody zabezpieczaj�ce przed wprowadzeniem innych danych.
	