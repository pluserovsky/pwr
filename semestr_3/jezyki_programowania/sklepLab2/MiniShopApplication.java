package sklepLab2;


import sklepLab2.Account;
import sklepLab2.ConsoleUserDialog;
import sklepLab2.MiniShop;
import sklepLab2.MiniShopApplication;
import sklepLab2.UserDialog;

/* 
 *  Program MiniShopApplication
 *  Autor: Łukasz Broll 225972
 *   Data: 1 pazdziernika 2016 r.
 */


class MiniShopApplication {

	public static void main(String[] args) {
		new MiniShopApplication();
	}

	/* Tu mo�na wybra� spos�b, w jaki aplikacja MiniBankApplication
	 * b�dzie si� komunikowa�a z u�ytkownikiem.
	 * 
	 * Klasa ConsoleUserInterface implenentuje metody umo�liwiaj�ce
	 * wy�wietlanie komunikat�w oraz wczytywanie danych bezpo�rednio
	 * w konsoli, czyli wykorzystywane s� standardowe strumienie 
	 * wej�cia/wyj�cia:  System.out,  System.in,   System.err
	 * 
	 * Klasa ConsoleUserInterface implenentuje metody umo�liwiaj�ce
	 * wy�wietlanie komunikat�w oraz wczytywanie danych w oknach
	 * dialogowych wy�wietlanych przez klas�  JOptionPane.
	 * 
	 *  PONI�EJ PROSZ� WYBRA� KLAS�, KLAS�, KT�RA MA ZOSTA� U�YTA
	 *  DO REALIZACJI DIALOGU Z U�YTKOWNIKIEM.
	 *  (Prosz� odkomentowa� wybran� instrukcj� kt�ra tworzy obiekt UI)
	 */
	//private UserDialog UI = new ConsoleUserDialog();
	private UserDialog UI = new JOptionPaneUserDialog();


	private static final String GREETING_MESSAGE =
			"Program MINISKLEP\n" +
					"Autor: Łukasz Broll\n" +
					"Data: 30 października 2016 r.\n";

	private static final String SHOP_MENU = 
			"SKLEP - M E N U   G Ł Ó W N E \n" +
					"1 - Zaloguj się \n" +
					"2 - Zarejestruj się \n"  +
					"0 - Zakończ program \n";		

	private static final String ACCOUNT_MENU =
			"\n1 - Doładowanie konta \n" +
					"2 - Przeglądanie dostępnych towarów \n" + 
					"3 - Zakup towarów \n" +
					"4 - Historia zakupów \n" +
					"5 - Zmiana hasła \n" +
					"6 - Usuń konto \n" +
					"0 - Wyloguj się z konta \n";

	private static final String SELLER_MENU =
			"\n1 - Dodaj nowy towar do magazynu \n" +
					"2 - Przeglądaj towary dostępne w magazynie\n" +
					"3 - Edycja przedmiotów w magazynie \n" + 
					"4 - Wycofywanie towarów z oferty\n" +
					"5 - Sprawdzanie utargu \n" +
					"6 - Generator faktury \n" +
					"7 - Lista zarejestrowanych klientów \n" +
					"8 - Zmień hasło sprzedawcy\n" +
					"0 - Wyloguj się z konta \n";


	private static final String ACCOUNTS_NAME = "MINISHOP_ACCOUNTS.BIN";
	private static final String STUFF_NAME = "MINISHOP_STUFF.BIN";
	private static final String SELLER_PASSWORD = "admin123";


	private static final String SHOP_NAME = "\nPiekarnia 'Ciasto'\nWrocław, ul. Bułkowa 123\n";

	private MiniShop shop = new MiniShop();


	public MiniShopApplication() {
		UI.printMessage(GREETING_MESSAGE);

		try {
			shop.loadAccountsFromFile(ACCOUNTS_NAME);
			shop.loadStuffFromFile(STUFF_NAME);
			UI.printMessage("Konta zostały wczytane z pliku " + ACCOUNTS_NAME);
			UI.printMessage("Towar został wczytany z pliku " + STUFF_NAME);
		} catch (Exception e) {
			UI.printErrorMessage(e.getMessage());
		}

		while (true) {
			UI.clearConsole();

			try {

				switch (UI.enterInt(SHOP_MENU + "==>> ")) {
				case 1:
					loginAccount();
					break;
				case 2:
					createNewAccount();
					break;
				case 0:
					try {
						shop.saveAccountsToFile(ACCOUNTS_NAME);
						UI.printMessage("Konta zostały zapisane do pliku " + ACCOUNTS_NAME);
						shop.saveStuffToFile(STUFF_NAME);
						UI.printMessage("Towar został zapisany do pliku " + STUFF_NAME);
					} catch (Exception e) {
						UI.printErrorMessage(e.getMessage());
					}

					UI.printInfoMessage("\nProgram zakończył działanie!");
					System.exit(0);
				}  // end of switch(option)
			} catch (Exception e) {
				UI.printErrorMessage(e.getMessage());
			}
		}
	}


	public  void listAllAccounts() {
		StringBuilder list = new StringBuilder("\nAKTUALNA LISTA KONT:\n");
		list.append(shop.listAccounts());		
		UI.printMessage(list.toString());
	}
	public  void listAllStuff() {
		StringBuilder list = new StringBuilder("\nAKTUALNA LISTA TOWARU:\n");
		list.append(shop.listStuff());		
		UI.printMessage(list.toString());
	}


	public  void createNewAccount() {	
		String newNick, newAdress, newPassword,isSeller, newId;


		Account newAccount;

		UI.printMessage("\nTWORZENIE NOWEGO KONTA\n");
		while(true) {
			newId = UI.enterString("Podaj ID (PESEL):");
			if (newId.equals("")) return;  // rezygnacja z tworzenia nowego konta
			if (shop.findAccount(newId)!=null) {
				UI.printErrorMessage("Konto już istnieje");
				continue;
			}
			newNick = UI.enterString("Wybierz nazwę konta:");
			newPassword = UI.enterString("Podaj hasło:");	
			newAdress = UI.enterString("Podaj adres:");


			try {
				newAccount = shop.createAccount(newNick);
				newAccount.setPassword("", newPassword);
				newAccount.setAdress(newAdress);
				newAccount.setId(newId);
			} catch (Exception e) {
				UI.printErrorMessage(e.getMessage());
				continue;
			}

			while(true)
			{
				isSeller = UI.enterString("Hasło sprzedawcy (jako klient zostaw puste):");	
				if(isSeller.equals(SELLER_PASSWORD))
				{
					newAccount.setIsSeller(true);
					UI.printMessage("Konto sprzedawcy zostało utworzone");
				}
				else if(isSeller.equals(""))
				{
					UI.printMessage("Konto klienta zostało utworzone");
				}
				else if(!isSeller.equals(""))
				{
					UI.printMessage("Błędne hasło sprzedawcy, jako klient zostaw puste.");
					continue;
				}
				break;
			}

			break;
		}
	}

	public  void createNewStuff() {	
		String newName;
		double newPrize;
		int newAmount;

		Stuff newStuff;

		UI.printMessage("\nTWORZENIE NOWEGO TOWARU\n");
		while(true) {
			newName = UI.enterString("Podaj nazwę towaru:");
			if (newName.equals("")) return;  // rezygnacja z tworzenia nowego konta
			if (shop.findStuff(newName)!=null) {
				UI.printErrorMessage("Towar już istnieje");
				continue;
			}
			newPrize = UI.enterDouble("Podaj cenę za sztukę:");
			newAmount = UI.enterInt("Podaj ilość towaru:");	


			try {
				newStuff = shop.createStuff(newName);
				newStuff.setPrize(newPrize);
				newStuff.setAmount(newAmount);

			} catch (Exception e) {
				UI.printErrorMessage(e.getMessage());
				continue;
			}

			break;
		}
	}

	public void loginAccount() {
		String nick, password;
		Account account;
		boolean isSeller;

		UI.printMessage("\nLOGOWANIE DO KONTA\n");

		nick = UI.enterString("Podaj ID konta:");
		password = UI.enterString("Podaj hasło:");

		account = shop.findAccount(nick, password);
		if (account == null) {
			UI.printErrorMessage("Błędne dane");
			return;
		}
		isSeller = account.getIsSeller();
		if(isSeller == false)
		{

			while (true) {
				UI.printMessage("\nJESTEŚ ZALOGOWANY DO KONTA KLIENTA ");
				UI.printMessage("Identyfikator konta: " + account.getId());
				UI.printMessage("Właściciel konta: " + account.getOwner());
				UI.printMessage("Dostępne środki: " + account.getBalance()+"\n");

				try {

					switch (UI.enterInt(ACCOUNT_MENU + "==>> ")) {
					case 1:
						payInMoney(account);
						break;
					case 2:
						listAllStuff();
						break;
					case 3:
						buyStuff(account,password);
						break;
					case 4:
						accountHistory(account, password);
						break;
					case 5:
						password = changePassword(account, password);
						break;
					case 6:
						if (removeAccount(account, password) == false)
							break;
						account = null;
						return;
					case 0:
						account = null;
						UI.printMessage("Nastąpiło wylogowanie z konta");
						return;
					}
				} catch (Exception e) {
					UI.printErrorMessage(e.getMessage());
				}
			}
		}
		if(isSeller == true)
		{

			while (true) {
				UI.printMessage("\nJESTEŚ ZALOGOWANY DO KONTA SPRZEDAWCY ");
				UI.printMessage("Identyfikator konta: " + account.getId());
				UI.printMessage("Właściciel konta: " + account.getOwner() + "\n");

				try {

					switch (UI.enterInt(SELLER_MENU + "==>> ")) {
					case 1:
						createNewStuff();
						break;
					case 2:
						listAllStuff();
						break;
					case 3:
						editStuff();
						break;
					case 4:
						removeStuff();
						break;
					case 5:
						allCash(); //utarg
						break;
					case 6:
						invoiceGenerator(); //generator faktury
					case 7:
						listAllAccounts();
						break;
					case 8:
						password = changePassword(account, password);
						break;
					case 0:
						account = null;
						UI.printMessage("Nastąpiło wylogowanie z konta");
						return;
					}
				} catch (Exception e) {
					UI.printErrorMessage(e.getMessage());
				}
			}
		}
	}


	public void invoiceGenerator() {
		
		listAllAccounts();
		Account account;
		String accountName,invoice;
		UI.printMessage("GENERATOR FAKTURY");
		accountName = UI.enterString("Wybierz ID klienta: ");
		account = shop.findAccount(accountName);
		if(account!=null)
		{
			invoice = SHOP_NAME + "Dane klienta:\n" +
					account.getOwner() + "\n" +
					account.getAdress() +"\n" +
					"Lista zakupów:" + "\n" +
					account.getHistory() + "\n" +
					"Łączna kwota do zapłaty"+ "\n" +
					account.getCashed() + "\n";
			UI.printMessage(invoice);
		}
		else {
			UI.printMessage("Nie znaleziono klienta.");
		}
		
		
		
		
	}


	public void accountHistory(Account account, String password) {
		String history = account.getHistory();
		UI.printInfoMessage("HISTORIA ZAKUPÓW KLIENTA\n"+history);
		
	}


	public boolean removeStuff() throws Exception  {
		String answer,stuffName;
		Stuff stuff;

		listAllStuff();
		UI.printMessage("\nUSUWANIE TOWARU");
		stuffName = UI.enterString("Podaj nazwę towaru: ");
		stuff = shop.findStuff(stuffName);

		answer = UI.enterString("Czy na pewno usunąć ten przedmiot? (TAK/NIE)");
		if (!answer.equals("TAK")) {
			UI.printErrorMessage("\nPrzedmiot nie został usunięty");
			return false;
		}

		shop.removeStuff(stuff);

		UI.printInfoMessage("\nPrzedmiot usunięty.");
		return true;

	}


	private void editStuff() {
	
		String answer,stuffName;
		int newAmount;
		double newPrize;
		Stuff stuff;

		listAllStuff();
		UI.printMessage("\nEDYTOWANIE TOWARU");
		stuffName = UI.enterString("Podaj nazwę towaru: ");
		stuff = shop.findStuff(stuffName);
		newAmount = UI.enterInt("Podaj nową ilość towaru: ");
		newPrize = UI.enterDouble("Podaj nową cenę towaru: ");
		answer = UI.enterString("Czy zapisać zmiany? (TAK/NIE)");
		if (!answer.equals("TAK")) {
			UI.printErrorMessage("\nZmiany nie zostały zapisane.");
		}
		stuff.setAmount(newAmount);
		stuff.setPrize(newPrize);
		UI.printInfoMessage("\nZmiany zostały zapisane.");
	}



	public void buyStuff(Account account, String password) {
		
		String answer,stuffName, newHistory, oldHistory;
		int stuffAmount, stuffOldAmount;
		double oldBalance,newBalance,oldCashed;
		Stuff stuff;
		listAllStuff();
		
		UI.printMessage("\nZAKUPY TOWARU");
		
		stuffName = UI.enterString("Podaj nazwę towaru: ");
		stuff = shop.findStuff(stuffName);
		if(stuff!=null)
		{
			
		
		stuffOldAmount = stuff.getAmount();
		stuffAmount = UI.enterInt("Podaj ilość towaru: ");
		
		while((stuffOldAmount-stuffAmount)<0){
			UI.printErrorMessage("\nBrak wystarczającej ilości towaru w sklepie.");
			stuffAmount = UI.enterInt("Podaj ilość towaru: ");
		}
		newBalance = stuffAmount * stuff.getPrize();
		oldBalance = account.getBalance();
		while((oldBalance-newBalance)<0){
			UI.printErrorMessage("\nBrak środków na koncie.");
			stuffAmount = UI.enterInt("Podaj ilość towaru: ");
			newBalance = stuffAmount * stuff.getPrize();
		}
		
		answer = UI.enterString("Czy na pewno chcesz kupić? (TAK/NIE)");
		if (!answer.equals("TAK")) {
			UI.printErrorMessage("\nTowar nie został kupiony.");
		}
		
		stuff.setAmount(stuffOldAmount-stuffAmount);
		account.setBalance(oldBalance-newBalance);
		oldCashed = account.getCashed();
		
		account.setCashed(oldCashed+newBalance); //dodawanie łącznego utargu
		
		oldHistory= account.getHistory();
		newHistory = stuff.toStringHistory(stuffAmount, stuff.getPrize());
		
		account.setHistory(oldHistory + "\n" + newHistory);
		UI.printInfoMessage("\nZmiany zostały zapisane.");
		}
		else
		{
			UI.printErrorMessage("\nNie znaleziono wybranego towaru.");
		}
	}
	
	public void payInMoney(Account account)throws Exception {
		double amount;
		UI.printMessage("\nWPłATA NA KONTO");
		amount = UI.enterDouble("Podaj kwotę: ");
		account.payIn(amount);
	}


	public void allCash() {
		double cash;
		cash = shop.allCashed();
		UI.printInfoMessage("\nŁĄCZNY UTARG SKLEPU: " + cash + " zł.");
		
}

	public  String changePassword(Account account, String password) throws Exception {
		String newPassword;

		UI.printMessage("\nZMIANA HAS�A DO KONTA");
		newPassword = UI.enterString("Podaj nowe has�o: ");
		account.setPassword(password, newPassword);
		return newPassword;
	}


	public boolean removeAccount(Account account, String password) throws Exception {
		String answer;

		UI.printMessage("\nUSUWANIE KONTA");
		answer = UI.enterString("Czy na pewno usun�� to konto? (TAK/NIE)");
		if (!answer.equals("TAK")) {
			UI.printErrorMessage("\nKonto nie zosta�o usuni�te");
			return false;
		}

		shop.removeAccount(account);

		UI.printInfoMessage("\nKonto zosta�o usuni�te");
		return true;
	}


	}

