import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Collection;
import java.util.HashSet;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

/**
 * Created by Luk on 2016-12-18. StworzyÄ‡ okno o tytule swoje imiÄ™ i nazwisko.
 * Na oknie dodaÄ‡ panel na ktĂłrym bÄ™dzie rysowane koĹ‚o chodzÄ…ce za kursorem
 * myszy (MouseMotionListener, paintComponent). KoĹ‚o ma pojawiaÄ‡ siÄ™ gdy siÄ™
 * wjedzie na panel i znikaÄ‡ gdy siÄ™ wjedzie na jakiĹ› element (MouseListener:
 * MouseEntered, MouseExited), koĹ‚o ma siÄ™ wypeĹ‚niaÄ‡ gdy kliknie siÄ™ jakiĹ›
 * przycisk (MouseListener: MousePressed, MouseRelesed). Na panelu ma byÄ‡
 * przycisk autor wyĹ›wietlajÄ…cy okienko z imieniem, nazwiskiem i numerem
 * albumu (JOptionPane). Na panelu ma byÄ‡ nieedytowalne pole tekstowe i JLabel
 * Sekundy: gdzie bÄ™dzie siÄ™ zliczaĹ‚y sekundy od uruchomienia programu
 * (WÄ…tki, Thread.sleep), przycisk restujacy stoper. Na panelu ma byÄ‡ przycisk
 * Dodaj pudeĹ‚ko, UsuĹ„ pudeĹ‚ko, UsuĹ„ wszystkie i WidokKolekcji (zawiera
 * JTable, jest gotowy w dostarczonym szkielecie). Klasa pudeĹ‚ko jest zrobiona
 * posiada String nazwa i String rozmiar, trzeba jÄ… dostosowaÄ‡ aby moĹĽna
 * byĹ‚o przechowywaÄ‡ obiekty tej klasy w HashSet (PrzeĹ‚adowaÄ‡ metody equals
 * i hashCode). Przyciski majÄ… dodawaÄ‡, usuwaÄ‡ pudeĹ‚ka i czyĹ›ciÄ‡ kolekcjÄ™
 * HashSet.
 */
public class test extends JFrame implements Runnable, ActionListener {

	private static final long serialVersionUID = 1L;

	int sekundy = 0, x, y;
	JButton autorButton = new JButton("Autor");
	JButton stoperButton = new JButton("Reset stoper");
	JButton dodajButton = new JButton("Dodaj");
	JButton usunButton = new JButton("Usun");
	JButton wyczyscButton = new JButton("Wyczysc");
	JTextField nazwaField = new JTextField(15);
	JTextField rozmiarField = new JTextField(15);

	JLabel sekundyLabel = new JLabel();

	HashSet<Pudelko> lista = new HashSet<Pudelko>();

	WidokHashSet widokhashset;

	public test() {
		super("Lukasz Broll");

		setSize(500, 500);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		JPanel panel = new JPanel();

		autorButton.addActionListener(this);
		stoperButton.addActionListener(this);
		dodajButton.addActionListener(this);
		usunButton.addActionListener(this);
		wyczyscButton.addActionListener(this);
		panel.add(autorButton);
		panel.add(stoperButton);
		panel.add(dodajButton);
		panel.add(usunButton);
		panel.add(wyczyscButton);
		panel.add(sekundyLabel);

		widokhashset = new WidokHashSet(lista, 200, 300, "Lista");
		panel.add(widokhashset);

		panel.add(rozmiarField);
		panel.add(nazwaField);
		setContentPane(panel);
		setVisible(true);

		Thread stoper = new Thread(this);
		stoper.start();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		Object src = e.getSource();
		String nazwa, rozmiar;
		if (src == autorButton) {
			JOptionPane.showMessageDialog(this, "Lukasz Broll");
		}
		if (src == dodajButton) {

			nazwa = nazwaField.getText();
			rozmiar = rozmiarField.getText();
			if (nazwa != "" && rozmiar != "") {

				Pudelko p = new Pudelko(nazwa, rozmiar);
				lista.add(p);
			}
		}
		if (src == usunButton) {
			nazwa = nazwaField.getText();
			rozmiar = rozmiarField.getText();
			if (nazwa != "" && rozmiar != "") {

				Pudelko p = new Pudelko(nazwa, rozmiar);
				lista.remove(p);
			}
		}
		if (src == wyczyscButton) {
			lista.clear();
		}
		if (src == stoperButton) {
			sekundy = -1;
		}
		widokhashset.refresh();
	}

	@Override
	public void run() {
		String text;
		while (true) {
			try {
				Thread.sleep(1000);
				sekundy++;
				text = Integer.toString(sekundy);
				sekundyLabel.setText(text);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}

	}

	
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

class Pudelko implements Comparable<Pudelko> {

	String nazwaPudelka;
	String rozmiarPudelka;

	public Pudelko(String nazwa, String rozmiar) {
		this.nazwaPudelka = nazwa;
		this.rozmiarPudelka = rozmiar;
	}

	@Override
	public int compareTo(Pudelko o) {
		int compareRozmiar = rozmiarPudelka.compareTo(o.rozmiarPudelka);
		if (compareRozmiar == 0) {
			int compareNazwa = nazwaPudelka.compareTo(o.nazwaPudelka);
			return compareNazwa;
		}

		return compareRozmiar;
	}

	@Override
	public String toString() {
		return "Pudelko [nazwaPudelka=" + nazwaPudelka + ", rozmiarPudelka=" + rozmiarPudelka + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((nazwaPudelka == null) ? 0 : nazwaPudelka.hashCode());
		result = prime * result + ((rozmiarPudelka == null) ? 0 : rozmiarPudelka.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (getClass() != obj.getClass()) {
			return false;
		}
		Pudelko other = (Pudelko) obj;
		if (nazwaPudelka == null) {
			if (other.nazwaPudelka != null) {
				return false;
			}
		} else if (!nazwaPudelka.equals(other.nazwaPudelka)) {
			return false;
		}
		if (rozmiarPudelka == null) {
			if (other.rozmiarPudelka != null) {
				return false;
			}
		} else if (!rozmiarPudelka.equals(other.rozmiarPudelka)) {
			return false;
		}
		return true;
	}
}

class Mouse extends JPanel implements MouseMotionListener, MouseListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int x, y;

	public Mouse() {

		addMouseListener(this);
		addMouseMotionListener(this);
		test start=new test();
	}
	public static void main(String[] args) {
		new Mouse();
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.drawOval(x, y, 50, 50);

	}

	@Override
	public void mouseClicked(MouseEvent e) {

	}

	@Override
	public void mousePressed(MouseEvent e) {
		x = e.getX();
		y = e.getY();
		repaint();

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		x = e.getX();
		y = e.getY();
		repaint();
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		x = e.getX();
		y = e.getY();
		this.repaint();

	}

	@Override
	public void mouseExited(MouseEvent e) {
		x = e.getX();
		y = e.getY();
		this.repaint();

	}

	@Override
	public void mouseDragged(MouseEvent e) {
		x = e.getX();
		y = e.getY();
		this.repaint();

	}

	@Override
	public void mouseMoved(MouseEvent e) {
		x = e.getX();
		y = e.getY();

		repaint();

	}

}