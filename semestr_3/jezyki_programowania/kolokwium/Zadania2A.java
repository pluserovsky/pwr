/*=======  TU PROSZE SIE PODPISAC ==============================
 *      Imie: Lukasz	
 *  Nazwisko:Broll
 *Nr indeksu:225972
 *==============================================================
 

 
 * Prosze uzupe�ni� klasy Edytor oraz Rysunek tak, by powsta�a
 * aplikacja graficzna dzia�aj�ca tak samo jak program Demonstacja.jar.
 *
 * Program jest prostym edytorem wy�wietlaj�cym ruchome k�o 
 * oraz umo�liwiaj�cym tworzenie rysunku z�o�onego z kr�tkich odcink�w 
 * wprowadzanych za pomoc� przeci�gania kursora myszki:
 *    - "rysowanie linii" - przeci�ganie kursora myszki 
 *                          bez przyci�ni�tego klawisza SHIFT 
 *      W tym trybie do listy odcink�w tworz�cych rysunek
 *      maj� by� dodawane odcinki ��cz�ce poprzedni� pozycj�
 *      kursora myszki i aktualn� pozycj� kursora myszki.
 *      
 *    - "zakre�lanie pola" - przeci�ganie kursora myszki 
 *                           z przyci�ni�tym klawiszem SHIFT
 *      W tym trybie do listy odcink�w tworz�cych rysunek
 *      maj� by� dodawane odcinki ��cz�ce pozycj� myszki zapami�tan�
 *      w momencie rozpocz�cia przeci�gania z przyci�ni�tym 
 *      klawiszem SHIFT i aktualn� pozycj� kursora myszki.
 *
 *
 * Zadanie 0:
 * Uzupe�nij klas� Edytor tak by zosta�o wy�wietlone g��wne okno aplikacji
 * o wymiarach 400 x 400 pixeli. Na Pasku tytu�owym tego okna powinno by�
 * wy�wietlone Imi� i Nazwisko autora programu. Zamkni�cie tego okna powinno
 * poprawnie zako�czy� dzia�anie ca�ej aplikacji.
 * Wn�trze okna prosz� wype�ni� panelem  (obiekt klasy Rysunek), 
 * na kt�rym b�d� rozmieszczane pozosta�e elementy GUI.
 * 
 * Zadanie 1:
 * W oknie aplikacji prosz� utworzy� menu g��wne, kt�re zawiera
 * nast�puj�ce opcje: 
 *      "Autor" - wy�wietla imi� i nazwisko autora w modalnym okno dialogowym,
 *      "Opis programu" - Wyswietla opis programu (sta�a OPIS)
 *                        w modalnym oknie dialogowym,
 *      "Zako�cz" - ko�czy dzia�anie aplikacji.
 * 
 * Zadanie 2:
 * Prosz� uzupe�ni� klas� Rysunek tak, by na panelu by�o rysowane wype�nione 
 * kolorem ��tym k�ko o promieniu 25 pixeli. K�ko ma si� p�ynie porusza� 
 * w po�owie wysoko�ci okna od lewej do prawej kraw�dzi okna z pr�dko�ci� 
 * 100 pixeeli na sekund�. (zmiana po�o�enia k�ka o 1 pixel powinna nast�powa� 
 * co 10 milisek�nd). Gdy �rodek k�ka dojedzie do prawej krawi�dzi, ma by� 
 * przeniesiony do lewej kraw�di okna.   
 * 
 * Zadanie 3:
 * W klasie Rysunek prosz� doda� kolekc� umo�lowiaj�c� zapami�tywanie 
 * odcink�w tworz�cych rysunek. 
 * UWAGA: DO PAMI�TANIA WSZYSTKICH ODCINK�W PROSZ� ZASTOSOWA� KOLEKCJ� 
 * TYPU LinkedList
 * Prosz� uzupe�ni� odpowiednie metody tak by mo�liwa by�a obs�uga
 * aplikacji za pomoc� myszki:
 *       a) przeci�ganie bez SHIFTa - dodawanie odcink�w 
 *          w trybie rysowania linii
 *          ( tzn. do listy odcink�w tworz�cych rysunek maj� by� dodawane 
 *            odcinki ��cz�ce poprzedni� pozycj� kursora myszki 
 *            i aktualn� pozycj� kursora myszki)
 *       b) przeci�ganie z SHIFTem  - dodawanie odcink�w 
 *          w trybie zakre�lania pola
 *          (tzn. do listy odcink�w tworz�cych rysunek maj� by� dodawane 
 *           odcinki ��cz�ce pozycj� myszki zapami�tan� w momencie rozpocz�cia 
 *           przeci�gania z przyci�ni�tym klawiszem SHIFT 
 *           i aktualn� pozycj� kursora myszki).
 *           
 * 
 * Zadanie 4:
 * Prosz� uzupe�ni� odpowiednie metody tak by mo�liwa by�a obs�uga
 * aplikacji za pomoc� klawiatury:
 *      a) "STRZA�KI"  - przesuwanie wszystkich
 *         narysowanych na ekranie odcink�w,
 *      d) klawisz "k" "K" - kasowanie wszystkich odcink�w 
 *         tworz�cych rysunek
 * 
 * 
 * Zadanie 5:
 *  W panelu g��wnym aplikacji prosz� utworzy�: 
 *      - nieedytowalne pole tekstowe w kt�rym b�dzie wy�wietlana
 *        aktualna liczba odcink�w tworz�cych rysunek,
 *      - przycisk "Kasuj" kt�ry b�dzie umo�liwia� kasowanie
 *        wszystkich odcink�w tworz�cych rysunek.
 *  Prosz� uzupe�ni� pozosta�e metody tak by pole tekstowe by�o
 *  aktualizowane po ka�dym dodaniu lub usuni�ciu odcinka.
 *  
 *
 */