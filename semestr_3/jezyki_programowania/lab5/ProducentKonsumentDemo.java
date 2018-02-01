import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

/* 
 *  Problem producenta i konsumenta
 *
 *  Autor: Lukasz Broll 225972
 *   Data: 6 stycznia 2017 r.
 */
class ProducentKonsumentDemo extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;

	Bufor c = new Bufor();

	Producent[] producents;
	Konsument[] konsumenents;

	Integer integers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	JButton startButton = new JButton("Start");
	JButton stopButton = new JButton("Stop");
	JButton resumeButton = new JButton("Kontynuuj");
	JComboBox<Integer> ProducentAmount = new JComboBox<>(integers);
	JComboBox<Integer> KonsumentAmount = new JComboBox<>(integers);
	JComboBox<Integer> BuforAmount = new JComboBox<>(integers);
	JLabel ProducentAmountLabel = new JLabel("Iloœæ producentów:");
	JLabel KonsumentAmountLabel = new JLabel("Iloœæ konsumentów:");
	JLabel BuforAmountLabel = new JLabel("Rozmiar bufora:");

	JTextArea logArea = new JTextArea();
	JScrollPane scrollLogArea;

	public ProducentKonsumentDemo() {
		super("Producent - konsument: Lukasz Broll");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(450, 500);

		JPanel panel = new JPanel();
		panel.setLayout(null);

		logArea.setEditable(false);
		logArea.setLineWrap(true);

		scrollLogArea = new JScrollPane(logArea);
		scrollLogArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrollLogArea.setBounds(10, 10, 420, 300);
		startButton.setBounds(10, 320, 130, 30);
		stopButton.setBounds(150, 320, 130, 30);
		resumeButton.setBounds(290, 320, 130, 30);
		ProducentAmountLabel.setBounds(20, 360, 120, 30);
		KonsumentAmountLabel.setBounds(150, 360, 120, 30);
		BuforAmountLabel.setBounds(300, 360, 120, 30);
		ProducentAmount.setBounds(20, 400, 50, 30);
		KonsumentAmount.setBounds(150, 400, 50, 30);
		BuforAmount.setBounds(300, 400, 50, 30);

		startButton.addActionListener(this);
		stopButton.addActionListener(this);
		resumeButton.addActionListener(this);

		panel.add(startButton);
		panel.add(stopButton);
		panel.add(resumeButton);
		panel.add(scrollLogArea);
		panel.add(ProducentAmount);
		panel.add(KonsumentAmount);
		panel.add(BuforAmount);
		panel.add(KonsumentAmountLabel);
		panel.add(ProducentAmountLabel);
		panel.add(BuforAmountLabel);

		setVisible(true);
		setContentPane(panel);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		Object src = e.getSource();

		if (src == startButton) {
			int amountProducers = 0, amountKonsumers = 0, buforSize = 0;

			buforSize = BuforAmount.getSelectedIndex();
			Bufor c = new Bufor();
			c.SetBuforSize(buforSize);
			amountProducers = ProducentAmount.getSelectedIndex();
			producents = new Producent[amountProducers];
			for (int i = 0; i < amountProducers; i++) {
				producents[i] = new Producent(c, i + 1);
				producents[i].start();
			}

			amountKonsumers = KonsumentAmount.getSelectedIndex();
			konsumenents = new Konsument[amountKonsumers];
			for (int i = 0; i < amountProducers; i++) {
				konsumenents[i] = new Konsument(c, i + 1);
				konsumenents[i].start();
			}

		}
		if (src == stopButton) {

			for (Producent p : producents) {
				synchronized (p) {
					p.pleaseWait = true;
				}
			}

			for (Konsument k : konsumenents) {
				synchronized (k) {
					k.pleaseWait = true;
				}
			}
		}
		if (src == resumeButton) {

			for (Producent p : producents) {
				synchronized (p) {
					p.pleaseWait = false;
					p.notify();
				}
			}

			for (Konsument k : konsumenents) {
				synchronized (k) {
					k.pleaseWait = false;
					k.notify();
				}
			}
		}

	}

	class Producent extends Thread {
		public boolean pleaseWait = false;

		char item = 'A';

		Bufor buf;
		int number;

		public Producent(Bufor c, int number) {
			buf = c;
			this.number = number;
		}

		public void run() {
			char c;
			while (true) {
				c = item++;
				buf.put(number, c);
				synchronized (this) {
					while (pleaseWait)
						try {
							wait();
						} catch (InterruptedException e) {
						}
				}
				try {
					sleep((int) (Math.random() * 1000));
				} catch (InterruptedException e) {
				}
			}
		}
	}

	class Konsument extends Thread {
		public boolean pleaseWait = false;
		Bufor buf;
		int number;

		public Konsument(Bufor c, int number) {
			buf = c;
			this.number = number;
		}

		public void run() {
			while (true) {
				buf.get(number);
				synchronized (this) {
					while (pleaseWait)
						try {
							wait();
						} catch (InterruptedException e) {
						}
				}
				try {
					sleep((int) (Math.random() * 1000));
				} catch (InterruptedException e) {
				}
			}
		}
	}

	class Bufor {
		private char contents;
		private int available = 0, buforSize = 1;

		public synchronized int get(int kons) {
			logArea.append("Konsument #" + kons + " chce zabrac\n");
			System.out.println("Konsument #" + kons + " chce zabrac");
			while (available == 0) {
				try {
					logArea.append("Konsument #" + kons + "   bufor pusty - czekam\n");
					System.out.println("Konsument #" + kons + "   bufor pusty - czekam");
					wait();
				} catch (InterruptedException e) {
				}
			}
			available--;
			logArea.append("Konsument #" + kons + "      zabral: " + contents + "\n");
			System.out.println("Konsument #" + kons + "      zabral: " + contents);
			logArea.setCaretPosition(logArea.getDocument().getLength());
			notifyAll();
			return contents;
		}

		public synchronized void put(int prod, char value) {
			logArea.append("Producent #" + prod + "  chce oddac: " + value + "\n");
			System.out.println("Producent #" + prod + "  chce oddac: " + value);

			while (available == buforSize) {
				try {
					logArea.append("Producent #" + prod + "   bufor zajety - czekam\n");
					System.out.println("Producent #" + prod + "   bufor zajety - czekam");
					wait();
				} catch (InterruptedException e) {
				}
			}
			contents = value;
			available++;
			logArea.append("Producent #" + prod + "       oddal: " + value + "\n");
			System.out.println("Producent #" + prod + "       oddal: " + value);
			logArea.setCaretPosition(logArea.getDocument().getLength());
			notifyAll();
		}

		public void SetBuforSize(int buforSize) {
			this.buforSize = buforSize;
		}
	}

	public static void main(String[] args) {
		new ProducentKonsumentDemo();

	}
}
