/* 
 *  Laboratorium 5 - 15 grudnia 2009/ WT / N / 7:30
 *
 *  Autor: Lukasz Przywarty - 171018
 *   Data: 11 stycznia 2009
 */

import javax.swing.*;
import java.awt.event.*;
import java.util.*;

/** 
 * Klasa ProducentKonsument impementuje interfejs ActionListener oraz rozszerza klase JFrame 
 * co w nastepstwie umozliwia obsluge zdarzen generowanych przez przyciski 
 */ 
public class ProducentKonsument extends JFrame implements ActionListener
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	//utworzenie zmiennych opisow pol, pol tekstowych oraz przyciskow	
	JLabel przebiegSymulacjiLabel = new JLabel ("Przebieg symulacji:");
    JTextArea symulacjaNotScroll = new JTextArea();
	JScrollPane symulacjaScroll;
    JButton startButton = new JButton("Start");
    JButton wstrzymajButton = new JButton("Wstrzymaj");
    JButton wznowButton = new JButton("Wznow");
    JLabel producentLabel = new JLabel ("Ile producentow:");
    JTextField producentText = new JTextField(10);
    JLabel konsumentLabel = new JLabel ("Ile Konsumentow:");
    JTextField konsumentText = new JTextField(10);
    JLabel buforLabel = new JLabel ("Pojemnosc bufora:");
    JTextField buforText = new JTextField(10);
    
    //utworzenie zmiennej bufora
    Bufor c = new Bufor();
    
    //deklaracje tablic zawierajacych poszczegolne watki typu producent/konsument
	Producent producenci[];
	Konsument konsumenci[];

    //konstruktor
    ProducentKonsument()
    {	
    	//opis okienka dialogowego
    	super("Producent - Konsument");
     	//rozmiar okienka
     	setSize(600,350);
     	//opis dzialania w momencie wcisniecia przycisku zamkniecia
     	 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     	//stworzenie nowego panelu
     	JPanel panel = new JPanel();
     	//rozmieszczenie elementow w panelu
     	panel.setLayout(null);
     	
		//pole tekstowe wyswietlajace wynik symulacji nie bedzie edytowalne
		symulacjaNotScroll.setEditable(false);
		//informacja pojawiajaca sie na ekranie po najechaniu na pole tekstowe
     	symulacjaNotScroll.setToolTipText("Przebieg symulacji");
    	//'zawijanie' wierszy
    	symulacjaNotScroll.setLineWrap(true);
     	
     	//utworzenie 'przewijalnego' pola tekstowego
     	symulacjaScroll = new JScrollPane(symulacjaNotScroll);
 		symulacjaScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
     	
     	//okreslenie rozmiaru i lokalizaji poszczegolnych elementow
     	przebiegSymulacjiLabel.setBounds(10, 10, 130, 20);
     	symulacjaScroll.setBounds(10,40,400,250);
        startButton.setBounds(430,40,130,30);
     	wstrzymajButton.setBounds(430,80,130,30);
     	wznowButton.setBounds(430,120,130,30);
     	producentLabel.setBounds(430, 160, 130, 20);
     	producentText.setBounds(430,180,130,20);	
     	konsumentLabel.setBounds(430, 200, 130, 20);
     	konsumentText.setBounds(430,220,130,20);	
     	buforLabel.setBounds(430, 250, 130, 20);
		buforText.setBounds(430,270,130,20);	
     	
     	//dodanie sluchaczy zdarzen
     	startButton.addActionListener(this); 
     	wstrzymajButton.addActionListener(this); 
     	wznowButton.addActionListener(this);  
     	
     	//umieszczenie w oknie opisow pol, pol tekstowych oraz przyciskow
     	panel.add(przebiegSymulacjiLabel); 
     	panel.add(symulacjaScroll);
     	panel.add(startButton);
     	panel.add(wstrzymajButton);
     	panel.add(wznowButton);
     	panel.add(producentLabel); 
     	panel.add(producentText); 
     	panel.add(konsumentLabel); 
     	panel.add(konsumentText);
     	panel.add(buforLabel);
     	panel.add(buforText);
     	
     	setContentPane(panel);  
     	setVisible(true);
    }
 	
 	/**
 	 * Klasa Producent rozszerza klase 'Watek' oraz implementuje watek producenta
 	 */
 	class Producent extends Thread
	{
		//zmienne pomocnicze
		char item = 'A';
		boolean pleaseWait = false;
		Bufor buf;
		int number;
		
		//konstruktor domyslny
		public Producent(Bufor c, int number)
		{ 
			buf = c;
			this.number = number;
		}
		
	   /**
     	* Metoda okresla dzialanie po uruchomieniu watku Producent
     	*/
		public void run()
		{ 
			char c;
			while(true)
			{
				c = item++;
				buf.put(number, c);
			
				synchronized (this) 
				{
                	while (pleaseWait) 
					try 
					{
						wait();
					} 
					catch (InterruptedException e) { }
				}
				try 
				{
					sleep((int)(Math.random() * 500));
				} 
				catch (InterruptedException e) { }
			}
		}
	}
	
	/**
 	 * Klasa Konsument rozszerza klase 'Watek' oraz implementuje watek konsumenta
 	 */
	class Konsument extends Thread
	{
		//zmienne pomocnicze
		Bufor buf;
	    int number;
		boolean pleaseWait = false;
		
		//konstruktor domyslny
		public Konsument(Bufor c, int number)
		{ 
			buf = c;
			this.number = number;
		}
		
	   /**
     	* Metoda okresla dzialanie po uruchomieniu watku Konsument
     	*/
		public void run()
		{ 
			while(true)
			{ 
				buf.get(number);
				synchronized (this) 
				{
                	while (pleaseWait) 
					try 
					{
						wait();
					}
				 	catch (InterruptedException e) { }
				}
				try 
				{
					sleep((int)(Math.random() * 500));
				} 
				catch (InterruptedException e) { }
			}
		}
	}
	/**
 	 * Klasa Bufor umozliwia zsynchronizowane dostarczanie (przez producenta)
 	 * oraz pobieranie (przez konsumenta) wartosci z bufora.
 	 */
	class Bufor
	{
		//zmienna zawartosci
		private int pojemnosc = 1;
		//zmienna prywatna okreslajaca dostepnosc danej wartosci
		private int available = 0;
		private char contents;
	


		//synchronizowana metoda umozliwiajaca pobranie wartosci w bufora
		public synchronized int get(int kons)
		{
			//wyswietlenie komentarza (w konsoli i polu tekstowym)
			symulacjaNotScroll.append("Konsument #" + kons + " chce zabrac\n");
			System.out.println("Konsument #" + kons + " chce zabrac");
			
			//jesli bufor jest pusty...
			while (available == 0)
			{
				try 
				{ 
					//...nastepuje czekanie
					System.out.println("Konsument #" + kons + "   bufor pusty - czekam");
					symulacjaNotScroll.append("Konsument #" + kons + "   bufor pusty - czekam\n");
					wait();
				} 
				catch (InterruptedException e) { }
			}
			//jesli jakas wartosc znajduje sie w buforze zaznaczamy, ze gdy ja zabierzemy bufor pozostanie pusty
			available--;
			//nastepuje pobranie wartosci
			System.out.println("Konsument #" + kons + "      zabral: " + contents);
			symulacjaNotScroll.append("Konsument #" + kons + "      zabral: " + contents +"\n");
			//automatyczne przewijanie na koniec pola tekstowego
			symulacjaNotScroll.setCaretPosition(symulacjaNotScroll.getDocument().getLength());
			notifyAll();
			return contents;
		}
		
		//synchronizowana metoda umozliwiajaca umieszczenie wartosci w buforze
		public synchronized void put(int prod, char value)
		{
			//wyswietlenie komentarza (w konsoli i polu tekstowym)
			System.out.println("Producent #" + prod + "  chce oddac: " + value);
			symulacjaNotScroll.append("Producent #" + prod + "  chce oddac: " + value + "\n");
			
			//jesli bufor zawiera jakas wartosc (dostepnosc)...
			while (available == pojemnosc)
			{
				try 
				{ 
					//...nie mozemy umiescic w nim wartosci wiec czekamy
					System.out.println("Producent #" + prod + "   bufor zajety - czekam");
					symulacjaNotScroll.append("Producent #" + prod + "   bufor zajety - czekam\n");
					wait();
				} 
				catch (InterruptedException e) { }
			}
			
			contents = value;
			//oznaczamy ze zostawimy jakas wartosc
			available++;
			//umieszczamy dana wartosc w buforze
			System.out.println("Producent #" + prod + "       oddal: " + value);
			symulacjaNotScroll.append("Producent #" + prod + "       oddal: " + value + "\n");
			symulacjaNotScroll.setCaretPosition(symulacjaNotScroll.getDocument().getLength());
			notifyAll();
		}
		public void ustawPojemnosc(int poj) 
    	{ 
    		pojemnosc = poj; 
    	}
	}
	
	/**
	 * Metoda sprawdzajaca poprawnosc wprowadzonych danych
	 * @return true - gdy liczba jest calkowita
	 * @return false w przeciwnym wypadku
	 */
	public boolean validateNumber(String num) 
	{
        try 
        {
           	Integer.parseInt(num);
            return true;
        } 
        catch (Exception e) 
        {
            return false;
        }
    }
    
    
 
 /**  
  * Metoda umozliwia wykonywanie operacji po kliknieciu w odpowiedni przycisk:
  *	<ul>
  *	 <li> start - wystartowanie watkow. Ponowne wcisniecie powoduje wystartowanie watkow od poczatku</li>
  *  <li> wstrzymaj - wstrzymanie (w dowolnym momencie) watkow</li>
  *  <li> wznow - ponowne odpalenie watkow (od momentu, w ktorym zatrzymalismy watki)</li>
  * </ul>
  */
 public void actionPerformed (ActionEvent evt)
 { 
    	
    	//zmienna obiektowa zrodlo - do obslugi klikniecia przyciskow
    	Object zrodlo = evt.getSource();
    	
    	//zmienne pomocnicze typu String
    	String ko, pr, pb;
    	  	
     	//jesli kliknelismy w przycisk 'Start'
     	if (zrodlo==startButton)
        { 
			//pobranie zawartosci pol tekstowych
			pr=producentText.getText();
			ko=konsumentText.getText();
			pb=buforText.getText();
			
			//jesli pola tekstowe sa puste uzytkownik otrzymuje stosowny komunikat
			if(ko.equals("") && pr.equals("") && pb.equals(""))
			{	
				JOptionPane.showMessageDialog(null, "Nie wprowadzono ilosci producentow i konsumentow, oraz pojemnosci bufora");
			}
			else if(ko.equals(""))
			{	
				JOptionPane.showMessageDialog(null, "Nie wprowadzono ilosci konsumentow");
			}
			else if(pr.equals(""))
			{	
				JOptionPane.showMessageDialog(null, "Nie wprowadzono ilosci producentow");
			}
			else if(pb.equals(""))
			{	
				JOptionPane.showMessageDialog(null, "Nie wprowadzono pojemnosci bufora");
			}
			//sprawdzanie poprawnosci wprowadzonych liczb
			else if(!(validateNumber(pr)) || !(validateNumber(ko)))
			{
            	JOptionPane.showMessageDialog(null, "Liczba producentow i konsumentow musi byc calkowita");
        	}
        	else if(!(validateNumber(pb)))
			{
            	JOptionPane.showMessageDialog(null, "Rozmiar bufora musi byc liczba calkowita");
        	}			
			else 
			{
				//konwersja zawartosci pola tekstowego do liczby typu int
				int ileProducentow = Integer.parseInt(pr);
				int ileKonsumentow = Integer.parseInt(ko);
				int pojemnoscBufora = Integer.parseInt(pb);
				
				//stworzenie tablic producentow i konsumentow
				producenci = new Producent[ileProducentow];
    			konsumenci = new Konsument[ileKonsumentow];
				
				c.ustawPojemnosc(pojemnoscBufora);
				
				//utworzenie poszczegolnych producentow i konsumentow
				for(int i = 0; i<ileProducentow; i++)
				{	
					producenci[i] = new Producent(c, i+1);
				}
				for(int i = 0; i<ileKonsumentow; i++)
				{	
					konsumenci[i] = new Konsument(c, i+1);
				}
				
				//wystartowanie watkow producentow i konsumentow
				for(Konsument k : konsumenci)
				{	
					k.start();
				}
				for(Producent p : producenci)
				{	
					p.start();
				}
			}
        } 
        
        //jesli kliknelismy w przycisk 'Wstrzymaj'
        if (zrodlo==wstrzymajButton)
        { 

           	//zatrzymanie watkow
           	for(Producent p : producenci)
			{
           		synchronized (p) 
           		{
        			p.pleaseWait = true;
    			}
			}
    		
    		for(Konsument k : konsumenci)
			{
           		synchronized (k) 
           		{
        			k.pleaseWait = true;
    			}
			}
        } 
        	
        //jesli kliknelismy w przycisk 'Wznow'
        if (zrodlo==wznowButton)
        {   
			//ponowne uruchomienie watkow
			for(Producent p : producenci)
			{
           		synchronized (p) 
           		{
       				p.pleaseWait = false;
        			p.notify();
    			}
			}
			
			for(Konsument k : konsumenci)
			{
           		synchronized (k) 
           		{
       				k.pleaseWait = false;
        			k.notify();
    			}
			}		
        } 
    }
   
    /**  
  	 * Metoda wywoluje okno programu
     */
    static  public void main(String arg[])
    { 
    	new  ProducentKonsument();      
    } 
 }