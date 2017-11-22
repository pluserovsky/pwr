
/*
 *  Demonstracja dzia�ania map typu
 *  TreeMap i zliczania wyrazow w ksiazce.
 *
 *  Autor: Lukasz Broll
 *   Data: 11 grudnia 2016 r.
 */

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class WordsMap extends JFrame implements ActionListener, Comparable<WordsMap> {

	private static final long serialVersionUID = 1L;
	private String word;
	Double d=40.0;

	TreeMap<String, Integer> treeMap = new TreeMap<String, Integer>();
	TreeMap<String, Integer> treeMap2 = new TreeMap<String, Integer>();

	WidokMapy widokTreeMap;
	WidokMapy widokTreeMap2;

	JButton przycisk_start = new JButton("Start");
	JButton przycisk_autor = new JButton("Autor");
	JButton btnNewButton = new JButton("<font color=red>AAA</font>");

	public WordsMap() {
		super("Zliczanie wyrazow Pana Tadeusza");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(400, 530);

		JPanel panel = new JPanel();

		przycisk_start.addActionListener(this);
		panel.add(przycisk_start);
		przycisk_autor.addActionListener(this);
		panel.add(przycisk_autor);
		panel.add(btnNewButton);

		widokTreeMap = new WidokMapy(treeMap, 300, 200, "Analiza alfabetyczna:");
		panel.add(widokTreeMap);

		widokTreeMap2 = new WidokMapy(treeMap2, 300, 200, "Analiza wystąpieniowa (nie działa):");
		panel.add(widokTreeMap2);

		setContentPane(panel);
		setVisible(true);
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((word == null) ? 0 : word.hashCode());
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
		WordsMap other = (WordsMap) obj;
		if (word == null) {
			if (other.word != null) {
				return false;
			}
		} else if (!word.equals(other.word)) {
			return false;
		}
		return true;
	}

	@SuppressWarnings("unchecked")
	@Override
	public void actionPerformed(ActionEvent evt) {
		Object zrodlo = evt.getSource();

		if (zrodlo == przycisk_start) {

			try {
				FileReader fr = new FileReader("pan_tadeusz.txt");
				Scanner text = new Scanner(fr);

				while (text.hasNext()) {
					word = text.next();
					if (!treeMap.containsKey(word)) {
						treeMap.put(word, 1);
					} else {
						treeMap.put(word, treeMap.get(word) + 1);
					}

				}
				text.close();
			} catch (FileNotFoundException e) {
				JOptionPane.showMessageDialog(this, "Nie ma takiego pliku!");
				e.printStackTrace();
			}
			TreeMap<String, Integer> tree = new TreeMap(new Comparator<WordsMap>() {

				@Override
				public int compare(WordsMap arg0, WordsMap arg1) {
					return treeMap.get(arg0).compareTo(treeMap.get(arg1));
				}
			});

			treeMap2.putAll(tree);

		} else

		if (zrodlo == przycisk_autor) {
			JOptionPane.showMessageDialog(this, "Autor: Lukasz Broll\nData: 11 grudnia 2016 r.");
		}
		widokTreeMap.refresh();
		widokTreeMap2.refresh();
	}

	public static void main(String[] args) {
		new WordsMap();
	}

	@Override
	public int compareTo(WordsMap o) {
		int compareAmount = treeMap.get(o).compareTo(treeMap.get(o));
		if (compareAmount == 0) {
			return word.compareTo(o.word);
		}
		return compareAmount;

	}
}

class WidokMapy extends JScrollPane {
	private static final long serialVersionUID = 1L;

	private JTable tabela;
	private DefaultTableModel modelTabeli;
	private Map<String, Integer> map;

	WidokMapy(TreeMap<String, Integer> treeMap, int szerokosc, int wysokosc, String opis) {
		String[] kolumny = { "Wyraz:", "Wystąpienia:" };
		modelTabeli = new DefaultTableModel(kolumny, 0);
		tabela = new JTable(modelTabeli);
		tabela.setRowSelectionAllowed(false);
		this.map = treeMap;
		setViewportView(tabela);
		setPreferredSize(new Dimension(szerokosc, wysokosc));
		setBorder(BorderFactory.createTitledBorder(opis));
	}

	void refresh() {
		modelTabeli.setRowCount(0);
		for (String klucz : map.keySet()) {
			int wartosc = map.get(klucz);
			String[] wiersz = { klucz, Integer.toString(wartosc) };
			modelTabeli.addRow(wiersz);
		}
	}

}