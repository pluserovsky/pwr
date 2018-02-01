import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Created by Luk on 2016-12-18. Stworzyć okno o tytule swoje imię i nazwisko.
 * Na oknie dodać panel na którym będzie rysowane koło chodzące za kursorem
 * myszy (MouseMotionListener, paintComponent). Koło ma pojawiać się gdy się
 * wjedzie na panel i znikać gdy się wjedzie na jakiś element (MouseListener:
 * MouseEntered, MouseExited), koło ma się wypełniać gdy kliknie się jakiś
 * przycisk (MouseListener: MousePressed, MouseRelesed). Na panelu ma być
 * przycisk autor wyświetlający okienko z imieniem, nazwiskiem i numerem
 * albumu (JOptionPane). Na panelu ma być nieedytowalne pole tekstowe i JLabel
 * Sekundy: gdzie będzie się zliczały sekundy od uruchomienia programu
 * (Wątki, Thread.sleep), przycisk restujacy stoper. Na panelu ma być przycisk
 * Dodaj pudełko, Usuń pudełko, Usuń wszystkie i WidokKolekcji (zawiera
 * JTable, jest gotowy w dostarczonym szkielecie). Klasa pudełko jest zrobiona
 * posiada String nazwa i String rozmiar, trzeba ją dostosować aby można
 * było przechowywać obiekty tej klasy w HashSet (Przeładować metody equals
 * i hashCode). Przyciski mają dodawać, usuwać pudełka i czyścić kolekcję
 * HashSet.
 */
public class xxx extends JFrame implements ActionListener, MouseListener, MouseMotionListener {
	JButton autor = new JButton("Autor");

	public xxx() {
		super("Lukasz");
		setSize(500, 500);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		JPanel panel = new JPanel();

		panel.add(autor);
		setContentPane(panel);
		setVisible(true);
	}

	public static void main(String[] args){
		new xxx();
	}
	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub

	}

}
