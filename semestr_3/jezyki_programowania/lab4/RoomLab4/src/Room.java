
/*
 *  Demonstracja dzia�ania kolekcji typu
 *  HashSet, TreeSet, ArrayList, LinkedList, Vector.
 *
 *  Autor: Łukasz Broll
 *   Data: 11 grudnia 2016 r.
 */

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class Room extends JFrame implements ActionListener, Comparable<Room> {

	

	private static final long serialVersionUID = 1L;

	String symbol;
	int numer;
	String opis;

	Vector<Room> vector = new Vector<Room>();
	ArrayList<Room> arraylist = new ArrayList<Room>();
	LinkedList<Room> linkedlist = new LinkedList<Room>();
	HashSet<Room> hashset = new HashSet<Room>();
	TreeSet<Room> treeset = new TreeSet<Room>();

	WidokKolekcji widokVector;
	WidokKolekcji widokArrayList;
	WidokKolekcji widokLinkedList;
	WidokKolekcji widokHashSet;
	WidokKolekcji widokTreeSet;

	JLabel etykieta_symbol = new JLabel("Symbol:");
	JTextField pole_symbol = new JTextField(4);

	JLabel etykieta_numer = new JLabel("Numer:");
	JTextField pole_numer = new JTextField(4);

	JLabel etykieta_opis = new JLabel("Opis:");
	JTextField pole_opis = new JTextField(10);

	JButton przycisk_dodaj = new JButton("Dodaj");
	JButton przycisk_usun = new JButton("Usuń");
	JButton przycisk_wyczysc = new JButton("Wyczyść");
	JButton przycisk_autor = new JButton("Autor");
	JButton przycisk_sortuj = new JButton("Sortuj listy");

	public Room() {
		super("Reprezentacja pokoi w firmie");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(800, 600);

		JPanel panel = new JPanel();
		panel.add(etykieta_symbol);
		panel.add(pole_symbol);
		panel.add(etykieta_numer);
		panel.add(pole_numer);
		panel.add(etykieta_opis);
		panel.add(pole_opis);

		przycisk_dodaj.addActionListener(this);
		panel.add(przycisk_dodaj);

		przycisk_sortuj.addActionListener(this);
		panel.add(przycisk_sortuj);

		przycisk_usun.addActionListener(this);
		panel.add(przycisk_usun);

		przycisk_wyczysc.addActionListener(this);
		panel.add(przycisk_wyczysc);

		przycisk_autor.addActionListener(this);
		panel.add(przycisk_autor);

		widokHashSet = new WidokKolekcji(hashset, 200, 250, "hashSet:");
		panel.add(widokHashSet);

		widokTreeSet = new WidokKolekcji(treeset, 200, 250, "treeSet:");
		panel.add(widokTreeSet);

		widokVector = new WidokKolekcji(vector, 200, 250, "vector:");
		panel.add(widokVector);

		widokArrayList = new WidokKolekcji(arraylist, 200, 250, "arrayList:");
		panel.add(widokArrayList);

		widokLinkedList = new WidokKolekcji(linkedlist, 200, 250, "linkedList:");
		panel.add(widokLinkedList);

		setContentPane(panel);
		setVisible(true);
	}

	public Room(String symbol, int numer, String opis) {
		this.symbol = symbol;
		this.numer = numer;
		this.opis = opis;
	}

	@Override
	public void actionPerformed(ActionEvent evt) {
		String symbol, opis;
		int numer;
		

		Object zrodlo = evt.getSource();

		if (zrodlo == przycisk_dodaj) {
			symbol = pole_symbol.getText();
			numer = Integer.parseInt((pole_numer.getText()));
			opis = pole_opis.getText();
			Room dane = new Room(symbol, numer, opis);
			
			if (!dane.equals(zrodlo)) {
				hashset.add(dane);
				treeset.add(dane);
				arraylist.add(dane);
				linkedlist.add(dane);
				vector.add(dane);
			}
		} else

		if (zrodlo == przycisk_wyczysc) {
			hashset.clear();
			treeset.clear();
			arraylist.clear();
			linkedlist.clear();
			vector.clear();
		} else

		if (zrodlo == przycisk_usun) {
			symbol = pole_symbol.getText();
			numer = Integer.parseInt((pole_numer.getText()));
			opis = pole_opis.getText();
			Room dane = new Room(symbol, numer, opis);
			
			hashset.remove(dane);
			treeset.remove(dane);
			arraylist.remove(dane);
			linkedlist.remove(dane);
			vector.remove(dane);
		} else

		if (zrodlo == przycisk_sortuj) {

			arraylist.sort(null);
			linkedlist.sort(null);
			vector.sort(null);
		} else

		if (zrodlo == przycisk_autor) {
			JOptionPane.showMessageDialog(this, "Autor: Lukasz Broll \nData: 11 grudzien 2016 r.");
		}

		widokHashSet.refreshHashSet();
		widokTreeSet.refreshTreeSet();
		widokArrayList.refreshArrayList();
		widokLinkedList.refreshLinkedList();
		widokVector.refreshVector();
	}

	public static void main(String[] args) {
		new Room();
	}

	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + numer;
		result = prime * result + ((symbol == null) ? 0 : symbol.hashCode());
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
		Room other = (Room) obj;
		if (numer != other.numer) {
			return false;
		}
		if (symbol == null) {
			if (other.symbol != null) {
				return false;
			}
		} else if (!symbol.equals(other.symbol)) {
			return false;
		}
		return true;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return "Room [symbol=" + symbol + ", numer=" + numer + ", opis=" + opis + "]";
	}

	@Override
	public int compareTo(Room o) {
		int compareSymbol = symbol.compareTo(o.symbol);
		if (compareSymbol == 0) {
			return numer-o.numer;
		}
		return compareSymbol;
	}
	
}

class WidokKolekcji extends JScrollPane {
	private static final long serialVersionUID = 1L;

	private JTable tabela;
	private DefaultTableModel modelTabeli;

	private Vector<Room> vector;
	private ArrayList<Room> arraylist;
	private LinkedList<Room> linkedlist;
	private TreeSet<Room> treeset;
	private HashSet<Room> hashset;

	WidokKolekcji(HashSet<Room> hashset, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Symbol:", "Numer:", "Opis:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.hashset = hashset;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	WidokKolekcji(Vector<Room> vector, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Symbol:", "Numer:", "Opis:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.vector = vector;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	public WidokKolekcji(ArrayList<Room> arraylist, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Symbol:", "Numer:", "Opis:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.arraylist = arraylist;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	public WidokKolekcji(LinkedList<Room> linkedlist, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Symbol:", "Numer:", "Opis:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.linkedlist = linkedlist;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	public WidokKolekcji(TreeSet<Room> treeset, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Symbol:", "Numer:", "Opis:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.treeset = treeset;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	void refreshVector() {
		modelTabeli.setRowCount(0);

		for (int i = 0; i < vector.size(); i++) {
			Room dane = vector.elementAt(i);
			String[] wiersz = { dane.symbol, Integer.toString(dane.numer), dane.opis };
			modelTabeli.addRow(wiersz);
		}

	}

	public void refreshLinkedList() {
		modelTabeli.setRowCount(0);

		for (int i = 0; i < linkedlist.size(); i++) {
			Room dane = linkedlist.get(i);
			String[] wiersz = { dane.symbol, Integer.toString(dane.numer), dane.opis };
			modelTabeli.addRow(wiersz);
		}

	}

	public void refreshArrayList() {
		modelTabeli.setRowCount(0);

		for (int i = 0; i < arraylist.size(); i++) {
			Room dane = arraylist.get(i);
			String[] wiersz = { dane.symbol, Integer.toString(dane.numer), dane.opis };
			modelTabeli.addRow(wiersz);
		}

	}

	public void refreshTreeSet() {
		modelTabeli.setRowCount(0);
		Iterator<Room> iter = treeset.iterator();
		while (iter.hasNext()) {
			Room dane = iter.next();
			String[] wiersz = { dane.symbol, Integer.toString(dane.numer), dane.opis };
			modelTabeli.addRow(wiersz);

		}

	}

	public void refreshHashSet() {
		modelTabeli.setRowCount(0);
		Iterator<Room> iter = hashset.iterator();
		while (iter.hasNext()) {
			Room dane = iter.next();
			String[] wiersz = { dane.symbol, Integer.toString(dane.numer), dane.opis };
			modelTabeli.addRow(wiersz);

		}
	}

}
