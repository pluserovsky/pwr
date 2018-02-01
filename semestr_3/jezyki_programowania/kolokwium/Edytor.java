import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

/*=======  TU PROSZE SIE PODPISAC ==============================
 *      Imie:
 *  Nazwisko:
 *Nr indeksu:
 *==============================================================
 */

class Odcinek {
	private int x1, y1, x2, y2;

	/*
	 * Konstruktor tworz�cy nowy obiekt Odcinek px, py - wsp�rz�dne pocz�tku
	 * odcinka kx, ky - wsp�rz�dne ko�ca odcinka
	 */
	public Odcinek(int px, int py, int kx, int ky) {
		x1 = px;
		y1 = py;
		x2 = kx;
		y2 = ky;
	}

	public void przesun(int dx, int dy) {
		x1 += dx;
		y1 += dy;
		x2 += dx;
		y2 += dy;
	}

	public void rysuj(Graphics g) {
		g.drawLine(x1, y1, x2, y2);
	}
}

class Rysunek extends JFrame implements  ActionListener {

	public void actionPerformed(ActionEvent evt) {

	}

}

public class Edytor extends JFrame implements KeyListener, MouseListener, MouseMotionListener, Runnable, {

	private static final long serialVersionUID = 1L;

	private final String OPIS = "OPIS PROGRAMU\n\n" + "Aktywna klawisze:\n" + "   strzalki   ==> przesuwanie rysunku\n"
			+ "   k , K  ==> kasowanie rysunku\n" + "\nOperacje myszka:\n" + "   przeciaganie   ==>  rysowanie lini\n"
			+ "   SHIFT + przeciaganie   ==>  zakre�lanie pola"
			+ "\nWIDAC ZE KOLO SIE PORUSZA NA EKRANIE TYLKO GDY RUSZA SIE MYSZKA";

	
	// ***obs�uga zdarze� przez s�uchacza zdarze� KeyListener ***
		public void keyPressed(KeyEvent e) {
			
		}

		public void keyReleased(KeyEvent evt) {
		}

		public void keyTyped(KeyEvent evt) {
		}

		// ***obs�uga zdarze� przez s�uchacza zdarze� MouseListener
		public void mouseClicked(MouseEvent e) {

		}

		public void mouseEntered(MouseEvent e) {
			
		}

		public void mouseExited(MouseEvent e) {
		}

		public void mousePressed(MouseEvent e) {

		}

		public void mouseReleased(MouseEvent e) {
		}

		// ***obs�uga zdarze� przez s�uchacza zdarze� MouseMotionListener***
		public void mouseDragged(MouseEvent e) {
			
		}

		public void mouseMoved(MouseEvent e) {

		}

		// ***implementacja interfejsu Runnable***
		@Override
		public void run() {


		}

		@Override
		public void actionPerformed(ActionEvent e) {
			

		}

	public static void main(String[] args) {
		Rysunek rysunek = new Rysunek();

	}

}