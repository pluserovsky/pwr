/*Stworzyæ okno o tytule swoje imiê i nazwisko.
Na oknie dodaæ panel na którym bêdzie rysowane ko³o chodz¹ce za kursorem myszy (MouseMotionListener, paintComponent). 
Ko³o ma pojawiaæ siê gdy siê wjedzie na panel i znikaæ gdy siê wjedzie na jakiœ element (MouseListener: MouseEntered, MouseExited),
 ko³o ma siê wype³niaæ gdy kliknie siê jakiœ przycisk (MouseListener: MousePressed, MouseRelesed).
Na panelu ma byæ przycisk autor wyœwietlaj¹cy okienko z imieniem, nazwiskiem i numerem albumu (JOptionPane).
Na panelu ma byæ nieedytowalne pole tekstowe i JLabel Sekundy: gdzie bêdzie siê zlicza³y sekundy od uruchomienia programu (W¹tki, Thread.sleep),
 przycisk restujacy stoper.
Na panelu ma byæ przycisk Dodaj pude³ko, Usuñ pude³ko, Usuñ wszystkie i WidokKolekcji (zawiera JTable, jest gotowy w dostarczonym szkielecie).
 Klasa pude³ko jest zrobiona posiada String nazwa i String rozmiar,
  trzeba j¹ dostosowaæ aby mo¿na by³o przechowywaæ obiekty tej klasy w HashSet (Prze³adowaæ metody equals i hashCode).
Przyciski maj¹ dodawaæ, usuwaæ pude³ka i czyœciæ kolekcjê HashSet. */

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Collection;
import javax.swing.BorderFactory;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

import java.awt.Color;
import java.awt.Dimension;
import java.util.*;

public class krzychu extends JFrame implements ActionListener, MouseListener, MouseMotionListener {

	private static final long serialVersionUID = 1L;

	HashSet<Pudelko> hashSet = new HashSet<Pudelko>();

	WidokHashSet widokHashSet;

	JLabel etykieta_nazwy = new JLabel(" Nazwa Pude³ka: ");
	JTextField pole_nazwy = new JTextField(15);
	JLabel etykieta_rozmiaru = new JLabel("Rozmiar Pude³ka: ");
	JTextField pole_rozmiaru = new JTextField(15);
	JLabel etykieta_stoperu = new JLabel("Czas trwania programu: 0 sek");

	JButton przycisk_dodaj = new JButton("Dodaj");
	JButton przycisk_usun = new JButton("Usun");
	JButton przycisk_autor = new JButton("Autor");
	JButton przycisk_wyczysc = new JButton("Wyczysc");
	JButton przycisk_reset = new JButton("Reset");

	Stoper stoper = new Stoper(etykieta_stoperu);
	
	public krzychu() {
		super("Krzysztof Dombek - kolokwium 21 grudnia 2016r.");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(700, 800);

		JPanel panel = new JPanel();
		panel.add(etykieta_nazwy);
		panel.add(pole_nazwy);
		panel.add(etykieta_rozmiaru);
		panel.add(pole_rozmiaru);

		przycisk_dodaj.addActionListener(this);
		panel.add(przycisk_dodaj);
		przycisk_usun.addActionListener(this);
		panel.add(przycisk_usun);
		przycisk_autor.addActionListener(this);
		panel.add(przycisk_autor);
		przycisk_wyczysc.addActionListener(this);
		panel.add(przycisk_wyczysc);
		przycisk_reset.addActionListener(this);
		panel.add(przycisk_reset);
		

		widokHashSet = new WidokHashSet(hashSet, 300, 200, "HashSet:");
		panel.add(widokHashSet);
		panel.add(etykieta_stoperu);
		stoper.start();
		
		setContentPane(panel);
		setVisible(true);

		addMouseMotionListener(this);
		addMouseListener(this);
	}

	public void actionPerformed(ActionEvent evt) {
		String nazwaPudelka, rozmiarPudelka;
		Object zrodlo = evt.getSource();

		if (zrodlo == przycisk_dodaj) {
			nazwaPudelka = pole_nazwy.getText();
			rozmiarPudelka = pole_rozmiaru.getText();
			if (!nazwaPudelka.equals("") && !rozmiarPudelka.equals("")) {
				hashSet.add(new Pudelko(nazwaPudelka, rozmiarPudelka));

				pole_nazwy.setText("");
				pole_rozmiaru.setText("");
			}

		} else if (zrodlo == przycisk_autor) {
			JOptionPane.showMessageDialog(this, "Autor : Krzysztof Dombek");
		} else

		if (zrodlo == przycisk_usun) {
			nazwaPudelka = pole_nazwy.getText();
			rozmiarPudelka = pole_rozmiaru.getText();
			Pudelko pudelko1 = new Pudelko(nazwaPudelka, rozmiarPudelka);
			hashSet.remove(pudelko1);
		} else

		if (zrodlo == przycisk_wyczysc) {
			hashSet.clear();
		} else
		if(zrodlo == przycisk_reset) {
			stoper.resetTime();
		}

		widokHashSet.refresh();
	}

	class WidokHashSet extends JScrollPane {
		private static final long serialVersionUID = 1L;

		private JTable tabela;
		private DefaultTableModel modelTabeli;
		private Collection<Pudelko> collection;

		WidokHashSet(Collection<Pudelko> collection, int szerokosc, int wysokosc, String opis) {
			String[] kolumny = { "Nazwa pude³ka:", "Rozmiar pude³ka:" };
			modelTabeli = new DefaultTableModel(kolumny, 0);
			tabela = new JTable(modelTabeli);
			tabela.setRowSelectionAllowed(false);
			this.collection = collection;
			setViewportView(tabela);
			setPreferredSize(new Dimension(szerokosc, wysokosc));
			setBorder(BorderFactory.createTitledBorder(opis));

		}

		void refresh() {
			modelTabeli.setRowCount(0);
			for (Pudelko key : collection) {
				String[] kolumny = { key.nazwaPudelka, key.rozmiarPudelka };
				modelTabeli.addRow(kolumny);
			}
		}
	}

	public static void main(String[] args) {
		new krzychu();
	}

	

	@Override
	public void mouseDragged(MouseEvent a) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseMoved(MouseEvent a) {
		getGraphics().drawOval((int) (a.getX()), (int) (a.getY()), 12, 12);
		repaint();
	}

	@Override
	public void mouseClicked(MouseEvent a) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseEntered(MouseEvent a) {
		if (a.getSource() == przycisk_autor) {
			getGraphics().drawOval((int) (a.getX()), (int) (a.getY()), 12, 12);
			repaint();
		}

	}

	@Override
	public void mouseExited(MouseEvent a) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mousePressed(MouseEvent a) {
		getGraphics().setColor(Color.BLACK);
		getGraphics().fillOval((int) (a.getX()), (int) (a.getY()), 12, 12);

	}

	@Override
	public void mouseReleased(MouseEvent a) {
		// TODO Auto-generated method stub

	}

}




