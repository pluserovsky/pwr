
/* 
 *  Komunikator sieciowy
 *   - program serwera
 *
 *  Autor: Lukasz Broll
 *   Data: 16 stycznia 2017 r.
 */

import java.net.*;
import java.util.Map.Entry;
import java.util.concurrent.ConcurrentHashMap;
import java.io.*;

import javax.swing.*;
import java.awt.event.*;

class PhoneBookServer extends JFrame implements ActionListener, Runnable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JLabel e_odbiorca = new JLabel("Odbiorca:");
	private JLabel e_mess = new JLabel("Napisz:");
	private JLabel e_text = new JLabel("Dialog:");
	private JComboBox<Object> menuKlient = new JComboBox<Object>();
	private JTextField message = new JTextField(20);
	private JTextArea textArea = new JTextArea(15, 18);
	private JScrollPane scroll = new JScrollPane(textArea, ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
			ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);

	static final int SERVER_PORT = 15000;
	private String host;
	private ServerSocket serwer;

	PhoneBookServer() {
		super("SERWER");
		setSize(300, 340);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		JPanel panel = new JPanel();
		panel.add(e_odbiorca);
		menuKlient.setPrototypeDisplayValue("#########################");
		panel.add(menuKlient);
		panel.add(e_mess);
		panel.add(message);
		message.addActionListener(this);
		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		panel.add(e_text);
		textArea.setEditable(false);
		panel.add(scroll);

		setContentPane(panel);
		Thread t = new Thread(this); // Uruchomienie dodatkowego watka
		t.start(); // czekajacego na nowych klientow
		setVisible(true);
	}

	synchronized public void wypiszOdebrane(WatekPhoneBookClient watekPhoneBookClient, String s) {
		String pom = textArea.getText();
		textArea.setText(watekPhoneBookClient.getNazwa() + " >>> " + s + "\n" + pom);
	}

	synchronized public void wypiszWyslane(WatekPhoneBookClient k, String s) {
		String pom = textArea.getText();
		textArea.setText(k.getNazwa() + " <<< " + s + "\n" + pom);
	}

	synchronized void dodajKlienta(WatekPhoneBookClient watekPhoneBookClient) {
		menuKlient.addItem(watekPhoneBookClient);
	}

	synchronized void usunKlienta(WatekPhoneBookClient watekPhoneBookClient) {
		menuKlient.removeItem(watekPhoneBookClient);
	}

	public void actionPerformed(ActionEvent evt) {
		String m;
		Object src = evt.getSource();
		if (src == message) {
			WatekPhoneBookClient k = (WatekPhoneBookClient) menuKlient.getSelectedItem();

			if (k != null) {
				try {
					m = message.getText();
					k.getOutput().writeObject(m);
					wypiszWyslane(k, m);
					if (m.equals("exit")) {
						usunKlienta(k);
					}
				} catch (IOException e) {
					System.out.println("Wyjatek serwera " + e);
				}
			}

		}
		repaint();
	}

	public void run() {
		Socket s;
		// inicjalizacja po³¹czeñ sieciowych
		try {
			host = InetAddress.getLocalHost().getHostName();
			serwer = new ServerSocket(SERVER_PORT);
		} catch (IOException e) {
			System.out.println(e);
			JOptionPane.showMessageDialog(null, "Gniazdko dla serwera nie mo¿e byæ utworzone");
			System.exit(0);
		}
		System.out.println("Serwer zosta³ uruchomiony na hoscie " + host);
		// koniec inicjalizacji po³¹czeñ sieciowych

		while (true) {
			try {
				s = serwer.accept();
				if (s != null) {
					new WatekPhoneBookClient(this, s);
				}
			} catch (IOException e) {
				System.out.println("BLAD SERWERA: Nie mozna polaczyc sie z klientem ");
			}
		}
	}

	public static void main(String[] args) {
		new PhoneBookServer();
	}

}

class WatekPhoneBookClient implements Runnable {
	private Socket socket;
	private ObjectOutputStream output;
	private ObjectInputStream input;

	private String nazwa;
	private PhoneBookServer okno;

	WatekPhoneBookClient(PhoneBookServer server, Socket s) throws IOException {
		okno = server;
		socket = s;
		Thread t = new Thread(this); // Utworzenie dodatkowego watka
		t.start(); // do obslugi komunikacji sieciowej
	}

	public String getNazwa() {
		return nazwa;
	}

	public ObjectOutputStream getOutput() {
		return output;
	}

	public String toString() {
		return nazwa;
	}

	public void run() {
		String m;
		boolean wait = true;
		try {
			output = new ObjectOutputStream(socket.getOutputStream());
			input = new ObjectInputStream(socket.getInputStream());
			nazwa = (String) input.readObject();
			okno.dodajKlienta(this);
			while (wait == true) {
				m = (String) input.readObject();
				okno.wypiszOdebrane(this, m);
				if (m.equals("exit")) {
					okno.usunKlienta(this);
					break;
				}

				if (m.startsWith("load")) {

					String fileName;
					if (m.length() > 5) {

						fileName = m.substring(5);
						output.writeObject(PhoneBook.loadContacts(fileName));
					} else
						output.writeObject("ERROR - Nie wprowadzono nazwy pliku.");
				}

				if (m.startsWith("save")) {
					String fileName;
					if (m.length() > 5) {

						fileName = m.substring(5);
						output.writeObject(PhoneBook.saveContacts(fileName));
					} else
						output.writeObject("ERROR - Nie wprowadzono nazwy pliku.");

				}
				if (m.startsWith("get")) {
					String name = m;
					name = m.substring(4);
					output.writeObject(PhoneBook.getContact(name));
				}
				if (m.startsWith("put")) {
					String name;
					String[] dataTable = m.split(" ");
					if (dataTable.length == 3) {
						name = dataTable[1];
						try {
							int number = Integer.parseInt(dataTable[2]);
							if (number != 0)
								output.writeObject(PhoneBook.putContact(name, number));
							else
								output.writeObject("ERROR - Numer telefonu nie moze byc zerem.");
						} catch (NumberFormatException e) {
							output.writeObject("ERROR - Numer telefonu jest niepoprawny.");
						}
					} else
						output.writeObject("ERROR - Wprowadz dane zgodnie z szablonem (nazwisko numer).");

				}
				if (m.startsWith("replace")) {
					String name;
					String[] dataTable = m.split(" ");
					if (dataTable.length == 3) {
						name = dataTable[1];
						try {
							int number = Integer.parseInt(dataTable[2]);
							if (number != 0)
								output.writeObject(PhoneBook.replaceContact(name, number));
							else
								output.writeObject("ERROR - Numer telefonu nie moze byc zerem.");
						} catch (NumberFormatException e) {
							output.writeObject("ERROR - Numer telefonu jest niepoprawny.");
						}
					} else
						output.writeObject("ERROR - Wprowadz dane zgodnie z szablonem (nazwisko numer).");
				}
				if (m.startsWith("delete")) {
					String name;
					name = m.substring(7);
					output.writeObject(PhoneBook.deleteContact(name));
				}
				if (m.equals("list")) {
					output.writeObject(PhoneBook.listContact());

				}
				if (m.equals("close")) {
					wait = false;
					socket.close();
					output.writeObject("OK polecenie CLOSE zosta³o wykonane poprawnie.");
				}
				if (m.equals("bye")) {

					input.close();
					output.close();
					socket.close();
					socket = null;
					output.writeObject("OK polecenie BYE zosta³o wykonane poprawnie.");

				}

			}
			input.close();
			output.close();
			socket.close();
			socket = null;
		} catch (Exception e) {
		}
	}
}

class PhoneBook {

	static ConcurrentHashMap<String, Integer> contacts = new ConcurrentHashMap<String, Integer>();

	public static String listContact() {
		StringBuilder sb = new StringBuilder();

		for (Entry<String, Integer> e : contacts.entrySet()) {
			sb.append(e.getKey() + ", ");
		}
		return "OK " + sb.toString();
	}

	public static String deleteContact(String name) {
		if (contacts.containsKey(name)) {
			contacts.remove(name);
			return "OK polecenie DELETE zosta³o wykonane poprawnie.";
		} else
			return "ERROR - Taki kontakt nie istnieje.";

	}

	public static String replaceContact(String name, int number) {
		if (contacts.containsKey(name)) {
			contacts.replace(name, number);
			return "OK polecenie REPLACE zosta³o wykonane poprawnie.";
		} else
			return "ERROR - Taki kontakt nie istnieje.";

	}

	public static String putContact(String name, int number) {
		if (!contacts.containsKey(name)) {
			contacts.put(name, number);
			return "OK polecenie PUT zosta³o wykonane poprawnie.";
		} else
			return "ERROR - Taki kontakt juz istnieje.";
	}

	public static String getContact(String name) {
		if (contacts.containsKey(name)) {
			return "OK " + contacts.get(name);
		} else
			return "ERROR - Taki kontakt nie istnieje.";

	}

	@SuppressWarnings({ "unchecked", "resource" })
	public static String loadContacts(String fileName) throws FileNotFoundException {
		ObjectInputStream in = null;
		try {

			in = new ObjectInputStream(new FileInputStream(fileName));

		} catch (IOException e) {
			return "ERROR polecenie LOAD nie zosta³o wykonane poprawnie.";

		}

		try {
			contacts = (ConcurrentHashMap<String, Integer>) in.readObject();
		} catch (ClassNotFoundException | IOException e) {

			return "ERROR polecenie LOAD nie zosta³o wykonane poprawnie.";
		}
		try {
			in.close();
		} catch (IOException e) {

			return "ERROR polecenie LOAD nie zosta³o wykonane poprawnie.";
		}
		return "OK polecenie LOAD zosta³o wykonane poprawnie.";

	}

	@SuppressWarnings("resource")
	public static String saveContacts(String fileName) {
		ObjectOutputStream out;
		try {
			out = new ObjectOutputStream(new FileOutputStream(fileName));
		} catch (IOException e) {
			e.printStackTrace();
			return "ERROR polecenie SAVE nie zosta³o wykonane poprawnie.";
		}
		try {
			out.writeObject(contacts);
		} catch (IOException e) {
			e.printStackTrace();
			return "ERROR polecenie SAVE nie zosta³o wykonane poprawnie.";
		}
		try {
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			return "ERROR polecenie SAVE nie zosta³o wykonane poprawnie.";
		}
		return "OK polecenie SAVE zosta³o wykonane poprawnie.";

	}
}
