
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Rysunek extends JPanel implements ActionListener, MouseMotionListener, Runnable, MouseListener {
	private static final long serialVersionUID = 6787238289682460549L;

	int sekundy = 0;

	JLabel licznik = new JLabel("licznik");
	JTextField poleLicznik = new JTextField(3);
	JButton przyciskReset = new JButton("reset licznika");

	Boolean clicked = false;
	Boolean czyRysowac = true;
	int x, y;
	int r = 20;

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (czyRysowac == true) {
			g.drawOval((int) (this.x - r / 2), (int) (this.y - r / 2), (int) (this.r), (int) (this.r));
			if (clicked == true) {
				g.setColor(Color.blue);
				g.fillOval((int) (this.x - r / 2), (int) (this.y - r / 2), (int) (this.r), (int) (this.r));
			}
		}
	}

	Rysunek() {
		this.add(licznik);
		this.add(poleLicznik);
		this.add(przyciskReset);
		poleLicznik.setEditable(false);
		przyciskReset.addActionListener(this);
		addMouseListener(this);
		addMouseMotionListener(this);
		Thread licznik = new Thread(this);
		licznik.start();
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
		this.repaint();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		Object source = e.getSource();
		if (source == przyciskReset) {
			sekundy = 0;
			poleLicznik.setText("0");
			System.out.println("wcisnieto reset");
		}

	}

	@Override
	public void run() {
		while (true) {

			poleLicznik.setText(Integer.toString(sekundy));
			sekundy++;
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

	@Override
	public void mouseClicked(MouseEvent e) {
	}

	@Override
	public void mousePressed(MouseEvent e) {
		clicked = true;
		repaint();
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		clicked = false;
		repaint();
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		czyRysowac = true;

		this.repaint();
	}

	@Override
	public void mouseExited(MouseEvent e) {
		czyRysowac = false;
		this.repaint();

	}

}

class koloo extends JFrame implements ActionListener, Runnable, MouseListener, MouseMotionListener {

	private static final long serialVersionUID = 1L;

	JButton autor = new JButton("Autor");
	JButton reset = new JButton("Reset");
	JTextField sekundy = new JTextField();
	JLabel sekundyLabel = new JLabel("Sekundy:");

	int i = 0, x, y;

	public koloo() {
		super("Lukasz Broll");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(500, 500);

		Rysunek panel = new Rysunek();
		sekundy.setEditable(false);
		sekundy.setSize(100, 100);

		autor.addActionListener(this);
		reset.addActionListener(this);
		addMouseListener(this);
		addMouseMotionListener(this);

		panel.setLayout(null);
		autor.setBounds(10, 10, 100, 30);
		sekundyLabel.setBounds(10, 50, 100, 30);
		sekundy.setBounds(10, 80, 100, 30);
		reset.setBounds(10, 110, 100, 30);
		panel.add(autor);
		panel.add(sekundyLabel);
		panel.add(sekundy);
		panel.add(reset);

		setContentPane(panel);
		setVisible(true);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		Object source = e.getSource();

		if (source == autor) {
			JOptionPane.showMessageDialog(this, "Autor: Lukasz Broll");
		}
		if (source == reset) {
			i = 0;
		}
	}

	public static void main(String[] args) {
		koloo k = new koloo();
		Thread t = new Thread(k);
		t.start();

	}

	@Override
	public void run() {

		String time;
		while (true) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			i++;
			time = Integer.toString(i);
			sekundy.setText(time);
		}

	}

	@Override
	public void mouseDragged(MouseEvent e) {
		getGraphics().drawOval(e.getX(), e.getY(), 10, 10);
		repaint();
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		getGraphics().drawOval(e.getX(), e.getY(), 10, 10);
		repaint();
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		getGraphics().setColor(Color.BLACK);
		getGraphics().fillOval(e.getX(), e.getY(), 10, 10);
		repaint();

	}

	@Override
	public void mousePressed(MouseEvent e) {
		getGraphics().setColor(Color.BLACK);
		getGraphics().fillOval(e.getX(), e.getY(), 10, 10);
		repaint();
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		getGraphics().setColor(Color.BLACK);
		getGraphics().fillOval(e.getX(), e.getY(), 10, 10);
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		getGraphics().drawOval(e.getX(), e.getY(), 10, 10);
	}

	@Override
	public void mouseExited(MouseEvent e) {
		getGraphics().drawOval(e.getX(), e.getY(), 10, 10);

	}

}
