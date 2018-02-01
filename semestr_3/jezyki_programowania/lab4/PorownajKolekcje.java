
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

public class PorownajKolekcje extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;

	Vector<String> vector = new Vector<String>();
	ArrayList<String> arraylist = new ArrayList<String>();
	LinkedList<String> linkedlist = new LinkedList<String>();
	HashSet<String> hashset = new HashSet<String>();
	TreeSet<String> treeset = new TreeSet<String>();

	WidokKolekcji widokVector;
	WidokKolekcji widokArrayList;
	WidokKolekcji widokLinkedList;
	WidokKolekcji widokHashSet;
	WidokKolekcji widokTreeSet;

	JLabel etykieta_dane = new JLabel("  Dane:");
	JTextField pole_dane = new JTextField(10);
	JButton przycisk_dodaj = new JButton("Dodaj");
	JButton przycisk_usun = new JButton("Usuń");
	JButton przycisk_wyczysc = new JButton("Wyczyść");
	JButton przycisk_autor = new JButton("Autor");
	JButton przycisk_sortuj = new JButton("Sortuj listy");

	public PorownajKolekcje() {
		super("Porownanie działania kolekcji");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(600, 500);

		JPanel panel = new JPanel();
		panel.add(etykieta_dane);
		panel.add(pole_dane);

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

		widokHashSet = new WidokKolekcji(hashset, 150, 200, "hashSet:");
		panel.add(widokHashSet);

		widokTreeSet = new WidokKolekcji(treeset, 150, 200, "treeSet:");
		panel.add(widokTreeSet);

		widokVector = new WidokKolekcji(vector, 150, 200, "vector:");
		panel.add(widokVector);

		widokArrayList = new WidokKolekcji(arraylist, 150, 200, "arrayList:");
		panel.add(widokArrayList);

		widokLinkedList = new WidokKolekcji(linkedlist, 150, 200, "linkedList:");
		panel.add(widokLinkedList);

		setContentPane(panel);
		setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent evt) {
		String dane;
		Object zrodlo = evt.getSource();

		if (zrodlo == przycisk_dodaj) {
			dane = pole_dane.getText();
			if (!dane.equals("")) {
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
			dane = pole_dane.getText();
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
		new PorownajKolekcje();
	}
}

class WidokKolekcji extends JScrollPane {
	private static final long serialVersionUID = 1L;

	private JTable tabela;
	private DefaultTableModel modelTabeli;

	private Vector<String> vector;
	private ArrayList<String> arraylist;
	private LinkedList<String> linkedlist;
	private TreeSet<String> treeset;
	private HashSet<String> hashset;

	WidokKolekcji(HashSet<String> hashset, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Dane:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.hashset = hashset;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	WidokKolekcji(Vector<String> vector, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Dane:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.vector = vector;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	public WidokKolekcji(ArrayList<String> arraylist, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Dane:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.arraylist = arraylist;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	public WidokKolekcji(LinkedList<String> linkedlist, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Dane:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.linkedlist = linkedlist;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	public WidokKolekcji(TreeSet<String> treeset, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Dane:" };
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
			String dane = vector.elementAt(i);
			String[] wiersz = { dane };
			modelTabeli.addRow(wiersz);
		}

	}

	public void refreshLinkedList() {
		modelTabeli.setRowCount(0);

		for (int i = 0; i < linkedlist.size(); i++) {
			String dane = linkedlist.get(i);
			String[] wiersz = { dane };
			modelTabeli.addRow(wiersz);
		}

	}

	public void refreshArrayList() {
		modelTabeli.setRowCount(0);

		for (int i = 0; i < arraylist.size(); i++) {
			String dane = arraylist.get(i);
			String[] wiersz = { dane };
			modelTabeli.addRow(wiersz);
		}

	}

	public void refreshTreeSet() {
		modelTabeli.setRowCount(0);
		Iterator<String> iter = treeset.iterator();
		while (iter.hasNext()) {
			String dane = iter.next();
			String[] wiersz = { dane };
			modelTabeli.addRow(wiersz);

		}

	}

	public void refreshHashSet() {
		modelTabeli.setRowCount(0);
		Iterator<String> iter = hashset.iterator();
		while (iter.hasNext()) {
			String dane = iter.next();
			String[] wiersz = { dane };
			modelTabeli.addRow(wiersz);

		}
	}

}
