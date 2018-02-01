/*=======  TU PROSZE SIE PODPISAC ==============================
 *      Imie: Lukasz	
 *  Nazwisko:Broll
 *Nr indeksu:225972
 *==============================================================
 

 
 * Prosze uzupe³niæ klasy Edytor oraz Rysunek tak, by powsta³a
 * aplikacja graficzna dzia³aj¹ca tak samo jak program Demonstacja.jar.
 *
 * Program jest prostym edytorem wyœwietlaj¹cym ruchome kó³o 
 * oraz umo¿liwiaj¹cym tworzenie rysunku z³o¿onego z krótkich odcinków 
 * wprowadzanych za pomoc¹ przeci¹gania kursora myszki:
 *    - "rysowanie linii" - przeci¹ganie kursora myszki 
 *                          bez przyciœniêtego klawisza SHIFT 
 *      W tym trybie do listy odcinków tworz¹cych rysunek
 *      maj¹ byæ dodawane odcinki ³¹cz¹ce poprzedni¹ pozycjê
 *      kursora myszki i aktualn¹ pozycjê kursora myszki.
 *      
 *    - "zakreœlanie pola" - przeci¹ganie kursora myszki 
 *                           z przyciœniêtym klawiszem SHIFT
 *      W tym trybie do listy odcinków tworz¹cych rysunek
 *      maj¹ byæ dodawane odcinki ³¹cz¹ce pozycjê myszki zapamiêtan¹
 *      w momencie rozpoczêcia przeci¹gania z przyciœniêtym 
 *      klawiszem SHIFT i aktualn¹ pozycjê kursora myszki.
 *
 *
 * Zadanie 0:
 * Uzupe³nij klasê Edytor tak by zosta³o wyœwietlone g³ówne okno aplikacji
 * o wymiarach 400 x 400 pixeli. Na Pasku tytu³owym tego okna powinno byæ
 * wyœwietlone Imiê i Nazwisko autora programu. Zamkniêcie tego okna powinno
 * poprawnie zakoñczyæ dzia³anie ca³ej aplikacji.
 * Wnêtrze okna proszê wype³niæ panelem  (obiekt klasy Rysunek), 
 * na którym bêd¹ rozmieszczane pozosta³e elementy GUI.
 * 
 * Zadanie 1:
 * W oknie aplikacji proszê utworzyæ menu g³ówne, które zawiera
 * nastêpuj¹ce opcje: 
 *      "Autor" - wyœwietla imiê i nazwisko autora w modalnym okno dialogowym,
 *      "Opis programu" - Wyswietla opis programu (sta³a OPIS)
 *                        w modalnym oknie dialogowym,
 *      "Zakoñcz" - koñczy dzia³anie aplikacji.
 * 
 * Zadanie 2:
 * Proszê uzupe³niæ klasê Rysunek tak, by na panelu by³o rysowane wype³nione 
 * kolorem ¿ó³tym kó³ko o promieniu 25 pixeli. Kó³ko ma siê p³ynie poruszaæ 
 * w po³owie wysokoœci okna od lewej do prawej krawêdzi okna z prêdkoœci¹ 
 * 100 pixeeli na sekundê. (zmiana po³o¿enia kó³ka o 1 pixel powinna nastêpowaæ 
 * co 10 milisekónd). Gdy œrodek kó³ka dojedzie do prawej krawiêdzi, ma byæ 
 * przeniesiony do lewej krawêdi okna.   
 * 
 * Zadanie 3:
 * W klasie Rysunek proszê dodaæ kolekcê umo¿lowiaj¹c¹ zapamiêtywanie 
 * odcinków tworz¹cych rysunek. 
 * UWAGA: DO PAMIÊTANIA WSZYSTKICH ODCINKÓW PROSZÊ ZASTOSOWAÆ KOLEKCJÊ 
 * TYPU LinkedList
 * Proszê uzupe³niæ odpowiednie metody tak by mo¿liwa by³a obs³uga
 * aplikacji za pomoc¹ myszki:
 *       a) przeci¹ganie bez SHIFTa - dodawanie odcinków 
 *          w trybie rysowania linii
 *          ( tzn. do listy odcinków tworz¹cych rysunek maj¹ byæ dodawane 
 *            odcinki ³¹cz¹ce poprzedni¹ pozycjê kursora myszki 
 *            i aktualn¹ pozycjê kursora myszki)
 *       b) przeci¹ganie z SHIFTem  - dodawanie odcinków 
 *          w trybie zakreœlania pola
 *          (tzn. do listy odcinków tworz¹cych rysunek maj¹ byæ dodawane 
 *           odcinki ³¹cz¹ce pozycjê myszki zapamiêtan¹ w momencie rozpoczêcia 
 *           przeci¹gania z przyciœniêtym klawiszem SHIFT 
 *           i aktualn¹ pozycjê kursora myszki).
 *           
 * 
 * Zadanie 4:
 * Proszê uzupe³niæ odpowiednie metody tak by mo¿liwa by³a obs³uga
 * aplikacji za pomoc¹ klawiatury:
 *      a) "STRZA£KI"  - przesuwanie wszystkich
 *         narysowanych na ekranie odcinków,
 *      d) klawisz "k" "K" - kasowanie wszystkich odcinków 
 *         tworz¹cych rysunek
 * 
 * 
 * Zadanie 5:
 *  W panelu g³ównym aplikacji proszê utworzyæ: 
 *      - nieedytowalne pole tekstowe w którym bêdzie wyœwietlana
 *        aktualna liczba odcinków tworz¹cych rysunek,
 *      - przycisk "Kasuj" który bêdzie umo¿liwia³ kasowanie
 *        wszystkich odcinków tworz¹cych rysunek.
 *  Proszê uzupe³niæ pozosta³e metody tak by pole tekstowe by³o
 *  aktualizowane po ka¿dym dodaniu lub usuniêciu odcinka.
 *  
 *
 */