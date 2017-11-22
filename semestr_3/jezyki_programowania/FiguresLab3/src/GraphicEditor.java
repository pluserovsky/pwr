
/*
 *  Program EdytorGraficzny - aplikacja z graficznym interfejsem
 *   - obs�uga zdarze� od klawiatury, myszki i innych element�w GUI.
 *
 *  Autor: Łukasz Broll, ...
 *   Data: 27. 11, 2016 r.
 */

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Iterator;
import java.util.Random;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

abstract class Figure {

	static Random random = new Random();

	protected boolean selected = false;

	public boolean isSelected() {
		return selected;
	}

	public void filled(Graphics g) {

	}

	public void select() {
		selected = true;
	}

	public void select(boolean z) {
		selected = z;
	}

	public void unselect() {
		selected = false;
	}

	protected void setColor(Graphics g) {

		if (selected) {

			g.setColor(Color.RED);

		} else {
			g.setColor(Color.BLACK);
		}

	}

	public abstract boolean isInside(float px, float py);

	public boolean isInside(int px, int py) {
		return isInside((float) px, (float) py);
	}

	protected String properties() {
		String s = String.format("  Pole: %.0f  Obwod: %.0f", computeArea(), computePerimeter());
		if (isSelected())
			s = s + "   [SELECTED]";
		return s;
	}

	abstract String getName();

	abstract float getX();

	abstract float getY();

	abstract float computeArea();

	abstract float computePerimeter();

	abstract void move(float dx, float dy);

	abstract void scale(float s);

	abstract void draw(Graphics g);

	@Override
	public String toString() {
		return getName();
	}

}

class Point extends Figure {

	protected float x, y;
	protected Color c;

	Point() {
		this.x = random.nextFloat() * 400;
		this.y = random.nextFloat() * 400;
	}

	Point(float x, float y, Color c) {
		this.x = x;
		this.y = y;
		this.c = c;
	}

	@Override
	public boolean isInside(float px, float py) {
		// by umo�liwi� zaznaczanie punktu myszk�
		// miejsca odleg�e nie wi�cej ni� 6 le�� wewn�trz
		return (Math.sqrt((x - px) * (x - px) + (y - py) * (y - py)) <= 6);
	}

	@Override
	String getName() {
		return "Point(" + x + ", " + y + ")";
	}

	@Override
	float getX() {
		return x;
	}

	@Override
	float getY() {
		return y;
	}

	@Override
	float computeArea() {
		return 0;
	}

	@Override
	float computePerimeter() {
		return 0;
	}

	@Override
	void move(float dx, float dy) {
		x += dx;
		y += dy;
	}

	@Override
	void scale(float s) {
	}

	@Override
	void draw(Graphics g) {

		g.setColor(c);
		g.fillOval((int) (x - 3), (int) (y - 3), 6, 6);
	}

	String toStringXY() {
		return "(" + x + " , " + y + ")";
	}

}

class Circle extends Point {
	float r;

	Circle() {
		super();
		r = random.nextFloat() * 100;
	}

	Circle(float px, float py, float pr, Color c) {
		super(px, py, c);
		r = pr;
	}

	@Override
	public boolean isInside(float px, float py) {
		return (Math.sqrt((x - px) * (x - px) + (y - py) * (y - py)) <= r);
	}

	@Override
	String getName() {
		return "Circle(" + x + ", " + y + ")";
	}

	@Override
	float computeArea() {
		return (float) Math.PI * r * r;
	}

	@Override
	float computePerimeter() {
		return (float) Math.PI * r * 2;
	}

	@Override
	void scale(float s) {
		r *= s;
	}

	@Override
	void draw(Graphics g) {
		g.setColor(c);
		g.drawOval((int) (x - r), (int) (y - r), (int) (2 * r), (int) (2 * r));
	}

	/*
	 * @Override public void filled(Graphics g) {
	 * 
	 * setColor(g); // rysowanie wypelnionego kola g.fillOval((int) x, (int) y,
	 * (int) (r), (int) (r)); }
	 */

	/*
	 * public void fillColor(Graphics g) { String sRGB = null; int rgb = 0; rgb
	 * = Integer.parseInt(JOptionPane.showInputDialog(sRGB)); Color set = new
	 * Color(rgb); g.setColor(set);
	 * 
	 * }
	 */

}

class Elipse extends Point {
	float r, z;

	Elipse() {
		super();
		r = random.nextFloat() * 100;
		z = random.nextFloat() * 100;

	}

	Elipse(float px, float py, float pr, float pz, Color c) {
		super(px, py, c);
		r = pr;
		z = pz;
	}

	@Override
	public boolean isInside(float px, float py) {
		return ((x - px) * (x - px)) / (r * r) + ((y - py) * (y - py)) / (z * z) < 1;

	}

	@Override
	String getName() {
		return "Elpise(" + x + ", " + y + ")";
	}

	@Override
	float computeArea() {
		return (float) Math.PI * r * z;
	}

	@Override
	float computePerimeter() {
		return 0;
	}

	@Override
	void scale(float s) {
		r *= s;
		z *= s;
	}

	@Override
	void draw(Graphics g) {
		g.setColor(c);
		g.fillOval((int) (x - r), (int) (y - r), (int) (2 * r), (int) (2 * z));
	}

	/*
	 * @Override public void filled(Graphics g) {
	 * 
	 * setColor(g); // rysowanie wypelnionego kola g.fillOval((int) x, (int) y,
	 * (int) (r), (int) (z)); }
	 */

	/*
	 * public void fillColor(Graphics g) { String sRGB = null; int rgb = 0; rgb
	 * = Integer.parseInt(JOptionPane.showInputDialog(sRGB)); Color set = new
	 * Color(rgb); g.setColor(set);
	 * 
	 * }
	 */

}

class Triangle extends Figure {
	Point point1, point2, point3;

	Triangle() {
		point1 = new Point();
		point2 = new Point();
		point3 = new Point();
	}

	Triangle(Point p1, Point p2, Point p3) {
		point1 = p1;
		point2 = p2;
		point3 = p3;
	}

	@Override
	public boolean isInside(float px, float py) {
		float d1, d2, d3;
		d1 = px * (point1.y - point2.y) + py * (point2.x - point1.x) + (point1.x * point2.y - point1.y * point2.x);
		d2 = px * (point2.y - point3.y) + py * (point3.x - point2.x) + (point2.x * point3.y - point2.y * point3.x);
		d3 = px * (point3.y - point1.y) + py * (point1.x - point3.x) + (point3.x * point1.y - point3.y * point1.x);
		return ((d1 <= 0) && (d2 <= 0) && (d3 <= 0)) || ((d1 >= 0) && (d2 >= 0) && (d3 >= 0));
	}

	@Override
	String getName() {
		return "Triangle{" + point1.toStringXY() + point2.toStringXY() + point3.toStringXY() + "}";
	}

	@Override
	float getX() {
		return (point1.x + point2.x + point3.x) / 3;
	}

	@Override
	float getY() {
		return (point1.y + point2.y + point3.y) / 3;
	}

	@Override
	float computeArea() {
		float a = (float) Math
				.sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
		float b = (float) Math
				.sqrt((point2.x - point3.x) * (point2.x - point3.x) + (point2.y - point3.y) * (point2.y - point3.y));
		float c = (float) Math
				.sqrt((point1.x - point3.x) * (point1.x - point3.x) + (point1.y - point3.y) * (point1.y - point3.y));
		float p = (a + b + c) / 2;
		return (float) Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}

	@Override
	float computePerimeter() {
		float a = (float) Math
				.sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
		float b = (float) Math
				.sqrt((point2.x - point3.x) * (point2.x - point3.x) + (point2.y - point3.y) * (point2.y - point3.y));
		float c = (float) Math
				.sqrt((point1.x - point3.x) * (point1.x - point3.x) + (point1.y - point3.y) * (point1.y - point3.y));
		return a + b + c;
	}

	@Override
	void move(float dx, float dy) {
		point1.move(dx, dy);
		point2.move(dx, dy);
		point3.move(dx, dy);
	}

	@Override
	void scale(float s) {
		Point sr1 = new Point((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3, null);
		point1.x *= s;
		point1.y *= s;
		point2.x *= s;
		point2.y *= s;
		point3.x *= s;
		point3.y *= s;
		Point sr2 = new Point((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3, null);
		float dx = sr1.x - sr2.x;
		float dy = sr1.y - sr2.y;
		point1.move(dx, dy);
		point2.move(dx, dy);
		point3.move(dx, dy);
	}

	@Override
	void draw(Graphics g) {
		setColor(g);
		g.drawLine((int) point1.x, (int) point1.y, (int) point2.x, (int) point2.y);
		g.drawLine((int) point2.x, (int) point2.y, (int) point3.x, (int) point3.y);
		g.drawLine((int) point3.x, (int) point3.y, (int) point1.x, (int) point1.y);
	}

}

class Rectangle extends Point {
	protected float width, height;

	Rectangle() {
		super();
		this.width = random.nextFloat() * 400;
		this.height = random.nextFloat() * 400;
	}

	Rectangle(float px, float py, float width, float height, Color c) {
		super(px, py, c);
		this.width = width;
		this.height = height;
	}

	@Override
	public boolean isInside(float px, float py) {
		return (x <= px && px <= x + width && y <= py && py <= y + height);
	}

	@Override
	String getName() {
		return "Rectangle{" + getX() + getY() + +width + ";" + height + "}";
	}

	@Override
	float computeArea() {
		return (width * height);
	}

	@Override
	float computePerimeter() {
		return (2 * width + 2 * height);
	}

	@Override
	void move(float dx, float dy) {
		super.move(dx, dy);
	}

	@Override
	void scale(float s) {
		width = width * s;
		height = height * s;
	}

	@Override
	void draw(Graphics g) {
		g.setColor(c);
		g.fillRect((int) x, (int) y, (int) width, (int) height);
		/*
		 * g.drawLine((int) x, (int) y, (int) (x + width), (int) y);
		 * g.drawLine((int) (x + width), (int) y, (int) (x + width), (int) (y +
		 * height)); g.drawLine((int) (x + width), (int) (y + height), (int) x,
		 * (int) (y + height)); g.drawLine((int) x, (int) (y + height), (int) x,
		 * (int) y); }
		 */
	}

	@Override
	public void filled(Graphics g) {
		setColor(g);
		// rysowanie wypelnionego prostokata
		g.fillRect((int) x, (int) y, (int) width, (int) height);
	}
}

class Square extends Point {

	protected float z;

	/** bok kwadratu */

	Square() {
		super();
		this.z = random.nextFloat() * 400;

	}

	public Square(float px, float py, float z, Color c) {
		super(px, py, c);
		this.z = z;
	}

	@Override
	public boolean isInside(float px, float py) {
		return (x < px && px < x + z && y < py && py < y + z);
	}

	@Override
	public float computeArea() {
		return (z * z);
	}

	@Override
	public float computePerimeter() {
		return (4 * z);
	}

	@Override
	public void move(float dx, float dy) {
		super.move(dx, dy);
	}

	@Override
	public void scale(float s) {
		z = z * s;
	}

	@Override
	String getName() {
		return "Square{" + getX() + getY() + z + "}";
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(c);
		/*
		 * g.fillRect((int) x, (int) y, (int) z, (int) z); g.drawLine((int) x,
		 * (int) y, (int) (x + z), (int) y); g.drawLine((int) (x + z), (int) y,
		 * (int) (x + z), (int) (y + z)); g.drawLine((int) (x + z), (int) (y +
		 * z), (int) x, (int) (y + z)); g.drawLine((int) x, (int) (y + z), (int)
		 * x, (int) y);
		 */
		g.fillRect((int) x, (int) y, (int) z, (int) z);
	}

	@Override
	public void filled(Graphics g) {
		// ustawienie kolorow
		setColor(g);
		// rysowanie wypelnionego kwadratu
		g.fillRect((int) x, (int) y, (int) z, (int) z);
	}
}

class Picture extends JPanel implements KeyListener, MouseListener, MouseMotionListener {

	private static final long serialVersionUID = 1L;
	private static final String AUTHOR = "Łukasz Broll\n" + "Nr indeksu: 225972\n" + "Politechnika Wrocławska\n"
			+ "Wydział Elektroniki: Informatyka\n" + "27.11.2016r";
	private int mouseX, mouseY;
	private final String DESCRIPTION = "OPIS PROGRAMU\n\n" + "Aktywna klawisze:\n"
			+ "   strzalki ==> przesuwanie figur\n" + "   SHIFT + strzalki ==> szybkie przesuwanie figur\n"
			+ "   +,-  ==> powiekszanie, pomniejszanie\n" + "   DEL  ==> kasowanie figur\n"
			+ "   p  ==> dodanie nowego punktu\n" + "   c  ==> dodanie nowego kola\n"
			+ "   t  ==> dodanie nowego trojkata\n" + "   r  ==> dodanie nowego prostokąta\n"
			+ "   s  ==> dodanie nowego kwadratu\n" + "   e  ==> dodanie nowej elipsy\n" + "\nOperacje myszka:\n"
			+ "   klik ==> zaznaczanie figur\n" + "   ALT + klik ==> zmiana zaznaczenia figur\n"
			+ "   przeciaganie ==> przesuwanie figur\n" + "obsługa kolorów, wymiaru i miejsca tworzenia obiektu";
	Vector<Figure> figures = new Vector<Figure>();

	/*
	 * UWAGA: ta metoda b�dzie wywo�ywana automatycznie przy ka�dej potrzebie
	 * odrysowania na ekranie zawarto�ci panelu
	 *
	 * W tej metodzie NIE WOLNO !!! wywo�ywa� metody repaint()
	 */
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		for (Figure f : figures)
			f.draw(g);
	}

	void saveFiguresToFile(String fileName) throws Exception {
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName));
		out.writeObject(figures);
		out.close();
	}

	void loadFiguresFromFile(String fileName) throws Exception {
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName));
		figures = new Vector<Figure>();
		in.readObject();
		in.close();
	}

	void addFigure(Figure fig) {
		for (Figure f : figures) {
			f.unselect();
		}
		fig.select();
		figures.add(fig);
		repaint();
	}

	void moveAllFigures(float dx, float dy) {
		for (Figure f : figures) {
			if (f.isSelected())
				f.move(dx, dy);
		}
		repaint();
	}

	void scaleAllFigures(float s) {
		for (Figure f : figures) {
			if (f.isSelected())
				f.scale(s);
		}
		repaint();
	}

	public String toString() {
		String str = "Rysunek{ ";
		for (Figure f : figures)
			str += f.toString() + "\n         ";
		str += "}";
		return str;
	}

	void move(float dx, float dy) {
		for (Figure f : figures) {

			if (f.isSelected())
				f.move(dx, dy);
		}
		repaint();
	}

	void color(Graphics g) {
		for (Figure f : figures) {

			if (f.isSelected()) {
				String sRGB = null;
				int rgb = 0;
				rgb = Integer.parseInt(JOptionPane.showInputDialog("Wpisz RGB koloru:", sRGB));
				Color set = new Color(rgb);
				g.setColor(set);
			}
		}
		repaint();
	}

	/*
	 * Impelentacja interfejsu KeyListener - obs�uga zdarze� generowanych przez
	 * klawiatur� gdy focus jest ustawiony na ten obiekt.
	 */
	public void keyPressed(KeyEvent evt)
	// Virtual keys (arrow keys, function keys, etc) - handled with keyPressed()
	// listener.
	{
		int dist;
		if (evt.isShiftDown())
			dist = 10;
		else
			dist = 1;
		switch (evt.getKeyCode()) {
		case KeyEvent.VK_UP:
			moveAllFigures(0, -dist);
			break;
		case KeyEvent.VK_DOWN:
			moveAllFigures(0, dist);
			break;
		case KeyEvent.VK_LEFT:
			moveAllFigures(-dist, 0);
			break;
		case KeyEvent.VK_RIGHT:
			moveAllFigures(dist, 0);
			break;
		case KeyEvent.VK_DELETE:
			Iterator<Figure> i = figures.iterator();
			while (i.hasNext()) {
				Figure f = i.next();
				if (f.isSelected()) {
					i.remove();
				}
			}
			repaint();
			break;
		}
	}

	public void keyReleased(KeyEvent evt) {
	}

	public void keyTyped(KeyEvent evt)
	// Characters (a, A, #, ...) - handled in the keyTyped() listener.
	{
		char znak = evt.getKeyChar(); // reakcja na przycisku na naci�ni�cie
										// klawisza
		switch (znak) {
		case 'p':
			addFigure(new Point());
			break;
		case 'c':
			addFigure(new Circle());
			break;
		case 't':
			addFigure(new Triangle());
			break;
		case 'r':
			addFigure(new Rectangle());
			break;
		case 's':
			addFigure(new Square());
			break;
		case 'e':
			addFigure(new Elipse());
			break;

		case '+':
			scaleAllFigures(1.1f);
			break;
		case '-':
			scaleAllFigures(0.9f);
			break;
		}
	}

	/*
	 * Implementacja interfejsu MouseListener - obs�uga zdarze� generowanych
	 * przez myszk� gdy kursor myszki jest na tym panelu
	 */
	public void mouseClicked(MouseEvent e)
	// Invoked when the mouse button has been clicked (pressed and released) on
	// a component.
	{
		int px = e.getX();
		int py = e.getY();
		for (Figure f : figures) {
			if (e.isAltDown() == false)
				f.unselect();
			if (f.isInside(px, py))
				f.select(!f.isSelected());
		}
		repaint();
	}

	public void mouseEntered(MouseEvent e)
	// Invoked when the mouse enters a component.
	{
	}

	public void mouseExited(MouseEvent e)
	// Invoked when the mouse exits a component.
	{
	}

	public void mousePressed(MouseEvent e)
	// Invoked when a mouse button has been pressed on a component.
	{
		mouseX = e.getX();
		mouseY = e.getY();
	}

	public void mouseReleased(MouseEvent e)
	// Invoked when a mouse button has been released on a component.
	{
	}

	public void mouseDragged(MouseEvent e) {

		int nMouseX = e.getX();
		int nMouseY = e.getY();
		float px = 0, py = 0;

		px += nMouseX - mouseX;
		py += nMouseY - mouseY;

		move(px, py);

		mouseX = nMouseX;
		mouseY = nMouseY;
		repaint();
	}

	public void mouseMoved(MouseEvent e) {
	}

	public String description() {
		return DESCRIPTION;

	}

	public String author() {
		return AUTHOR;

	}
}

public class GraphicEditor extends JFrame implements ActionListener {

	private static final long serialVersionUID = 3727471814914970170L;

	protected Picture picture;

	private JMenu[] menu = { new JMenu("Figury"), new JMenu("Edytuj"), new JMenu("Pomoc") };

	private JMenuItem[] items = { new JMenuItem("Punkt"), new JMenuItem("Kolo"), new JMenuItem("Trojkat"),
			new JMenuItem("Prostokat"), new JMenuItem("Kwadrat"), new JMenuItem("Elipsa"),
			new JMenuItem("Wypisz wszystkie"), new JMenuItem("Przesun w gore"), new JMenuItem("Przesun w dol"),
			new JMenuItem("Powieksz"), new JMenuItem("Pomniejsz"), new JMenuItem("Autor"),
			new JMenuItem("Instrukcja"), };

	private JButton buttonPoint = new JButton("Punkt");
	private JButton buttonCircle = new JButton("Kolo");
	private JButton buttonRectangle = new JButton("Prostokąt");
	private JButton buttonSquare = new JButton("Kwadrat");
	private JButton buttonTriangle = new JButton("Trojkat");
	private JButton buttonElipse = new JButton("Elipsa");

	public GraphicEditor() {
		super("Super Edytor Graficzny");
		setSize(600, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		for (int i = 0; i < items.length; i++)
			items[i].addActionListener(this);

		// dodanie opcji do menu "Figury"
		menu[0].add(items[0]);
		menu[0].add(items[1]);
		menu[0].add(items[2]);
		menu[0].add(items[3]);
		menu[0].add(items[4]);
		menu[0].add(items[5]);
		menu[0].addSeparator();
		menu[0].add(items[6]);

		// dodanie opcji do menu "Edytuj"
		menu[1].add(items[7]);
		menu[1].add(items[8]);
		menu[1].addSeparator();
		menu[1].add(items[9]);
		menu[1].add(items[10]);

		// dodanie opcji do menu "Pomoc"
		menu[2].add(items[11]);
		menu[2].add(items[12]);

		// dodanie do okna paska menu
		JMenuBar menubar = new JMenuBar();
		for (int i = 0; i < menu.length; i++)
			menubar.add(menu[i]);
		setJMenuBar(menubar);

		picture = new Picture();
		picture.addKeyListener(picture);
		picture.setFocusable(true);
		picture.addMouseListener(picture);
		picture.addMouseMotionListener((MouseMotionListener) picture);
		picture.setLayout(new FlowLayout());

		buttonPoint.addActionListener(this);
		buttonCircle.addActionListener(this);
		buttonTriangle.addActionListener(this);
		buttonRectangle.addActionListener(this);
		buttonSquare.addActionListener(this);
		buttonElipse.addActionListener(this);

		picture.add(buttonPoint);
		picture.add(buttonCircle);
		picture.add(buttonTriangle);
		picture.add(buttonRectangle);
		picture.add(buttonSquare);
		picture.add(buttonElipse);

		setContentPane(picture);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent evt) {
		Object zrodlo = evt.getSource();
		int x = 0, y = 0, r = 0, z = 0, a = 0, b = 0, m = 0, n = 0, v = 0, l = 1;

		if (zrodlo == buttonPoint) {
			x = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x:", x));
			y = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y:", y));
			m = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość R (0-255):", m));
			n = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość G (0-255):", n));
			v = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość B (0-255):", v));
			l = Integer.parseInt(JOptionPane.showInputDialog("Wpisz wartość przezroczystości (0-255):", l));
			Color c = new Color(m, n, v, l);
			picture.addFigure(new Point(x, y, c));
		}
		if (zrodlo == buttonCircle) {

			x = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x:", x));
			y = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y:", y));
			r = Integer.parseInt(JOptionPane.showInputDialog("Wpisz r:", r));
			m = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość R (0-255):", m));
			n = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość G (0-255):", n));
			v = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość B (0-255):", v));
			l = Integer.parseInt(JOptionPane.showInputDialog("Wpisz wartość przezroczystości (0-255):", l));
			Color c = new Color(m, n, v, l);
			picture.addFigure(new Circle(x, y, r, c));
		}
		if (zrodlo == buttonTriangle) {
			x = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x pierwszego punktu:", x));
			y = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y pierwszego punktu:", y));
			a = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x drugiego punktu:", x));
			b = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y drugiego punktu:", y));
			r = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x trzeciego punktu:", x));
			z = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y trzeciego punktu:", y));
			m = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość R (0-255):", m));
			n = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość G (0-255):", n));
			v = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość B (0-255):", v));
			l = Integer.parseInt(JOptionPane.showInputDialog("Wpisz wartość przezroczystości (0-255):", l));
			Color c = new Color(m, n, v, l);
			picture.addFigure(new Triangle(new Point(x, y, c), new Point(a, b, c), new Point(r, z, c)));
		}
		if (zrodlo == buttonRectangle) {
			x = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x:", x));
			y = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y:", y));
			a = Integer.parseInt(JOptionPane.showInputDialog("Wpisz długość:", x));
			b = Integer.parseInt(JOptionPane.showInputDialog("Wpisz szerokość:", y));
			m = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość R (0-255):", m));
			n = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość G (0-255):", n));
			v = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość B (0-255):", v));
			l = Integer.parseInt(JOptionPane.showInputDialog("Wpisz wartość przezroczystości (0-255):", l));
			Color c = new Color(m, n, v, l);
			picture.addFigure(new Rectangle(x, y, a, b, c));
		}
		if (zrodlo == buttonSquare) {
			x = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x:", x));
			y = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y:", y));
			z = Integer.parseInt(JOptionPane.showInputDialog("Wpisz długość:", x));
			m = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość R (0-255):", m));
			n = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość G (0-255):", n));
			v = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość B (0-255):", v));
			l = Integer.parseInt(JOptionPane.showInputDialog("Wpisz wartość przezroczystości (0-255):", l));
			Color c = new Color(m, n, v, l);

			picture.addFigure(new Square(x, y, z, c));
		}
		if (zrodlo == buttonElipse) {

			x = Integer.parseInt(JOptionPane.showInputDialog("Wpisz x:", x));
			y = Integer.parseInt(JOptionPane.showInputDialog("Wpisz y:", y));
			a = Integer.parseInt(JOptionPane.showInputDialog("Wpisz a:", a));
			b = Integer.parseInt(JOptionPane.showInputDialog("Wpisz b:", b));
			m = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość R (0-255):", m));
			n = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość G (0-255):", n));
			v = Integer.parseInt(JOptionPane.showInputDialog("Wpisz kod koloru RGB wartość B (0-255):", v));
			l = Integer.parseInt(JOptionPane.showInputDialog("Wpisz wartość przezroczystości (0-255):", l));
			Color c = new Color(m, n, v, l);
			picture.addFigure(new Elipse(x, y, a, b, c));
		}

		if (zrodlo == items[0])
			picture.addFigure(new Point());
		if (zrodlo == items[1])
			picture.addFigure(new Circle());
		if (zrodlo == items[2])
			picture.addFigure(new Triangle());
		if (zrodlo == items[3])
			picture.addFigure(new Rectangle());
		if (zrodlo == items[4])
			picture.addFigure(new Square());
		if (zrodlo == items[5])
			picture.addFigure(new Elipse());
		if (zrodlo == items[6])
			JOptionPane.showMessageDialog(null, picture.toString());

		if (zrodlo == items[7])
			picture.moveAllFigures(0, -10);
		if (zrodlo == items[8])
			picture.moveAllFigures(0, 10);
		if (zrodlo == items[9])
			picture.scaleAllFigures(1.1f);
		if (zrodlo == items[10])
			picture.scaleAllFigures(0.9f);
		if (zrodlo == items[11])
			JOptionPane.showMessageDialog(null, picture.author());
		if (zrodlo == items[12])
			JOptionPane.showMessageDialog(null, picture.description());

		picture.requestFocus(); // przywrocenie ogniskowania w celu przywrocenia
								// obslugi zadarez� pd klawiatury
		repaint();
	}

	public static void main(String[] args) {
		new GraphicEditor();
	}

}
