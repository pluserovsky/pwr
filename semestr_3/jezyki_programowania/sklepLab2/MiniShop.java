package sklepLab2;


/* 
 *  Program Sklep internetowy
 *  Autor: Lukasz Broll
 *   Data: 30-1-2016 r.
 */


import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;


class MiniShop implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	private ArrayList<Account> listOfAccounts = new ArrayList<Account>(); //lista kont

	
	
	public Account createAccount(String owner) throws Exception {
		if (owner==null || owner.equals("")) throw(new Exception("Nazwa konta nie mo�e by� pusta"));
		if (findAccount(owner)!=null) throw(new Exception("Konto ju� istnieje"));
		Account newAccount = new Account(owner);
		listOfAccounts.add( newAccount );
		return newAccount;
	}
	
	
	public void removeAccount(Account account) throws Exception {
		if (account==null) throw(new Exception("Brak konta"));
		listOfAccounts.remove(account);
	}
	
	
	public Account findAccount(String id) {
		for (Account account : listOfAccounts)
			if (account.getId().equals(id)) return account;
		return null;
	}
	
	
	public Account findAccount(String id, String password) {
		Account account = findAccount(id);
		if (account!=null){
			if (!account.checkPassword(password)) account = null;
		}
		return account;
	}
	
	
	public String listAccounts(){
		StringBuilder sb = new StringBuilder();
		int n = 0;
		for (Account account : listOfAccounts){
			if (n++ != 0) sb.append("\n");		
			sb.append(account.toString());
		}
		return sb.toString();
	}
	
	public double allCashed(){
		double cashed=0;
		for (Account account : listOfAccounts){
			cashed = cashed + account.getCashed();
		}
		return cashed;
	}
	
	void saveAccountsToFile(String fileName) throws Exception {
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName));
		out.writeObject(listOfAccounts);
		out.close();
	}
	
	
	@SuppressWarnings("unchecked")
	void loadAccountsFromFile(String fileName) throws Exception {
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName));
		listOfAccounts = (ArrayList<Account>)in.readObject();
		in.close();
	}
	
private ArrayList<Stuff> listOfStuff = new ArrayList<Stuff>(); //lista towaru
	
	
	public Stuff createStuff(String name) throws Exception {
		if (name==null || name.equals("")) throw(new Exception("Nazwa towaru nie może być pusta"));
		if (findStuff(name)!=null) throw(new Exception("Towar jest już w systemie."));
		Stuff newStuff = new Stuff(name);
		listOfStuff.add( newStuff );
		return newStuff;
	}
	
	
	public void removeStuff(Stuff stuff) throws Exception {
		if (stuff==null) throw(new Exception("Brak towaru"));
		listOfStuff.remove(stuff);
	}
	
	
	public Stuff findStuff(String name) {
		for (Stuff stuff : listOfStuff)
			if (stuff.getName().equals(name)) return stuff;
		return null;
	}
	
	
	public String listStuff(){
		StringBuilder sb = new StringBuilder();
		int n = 0;
		for (Stuff stuff : listOfStuff){
			if (n++ != 0) sb.append("\n");		
			sb.append(stuff.toString());
		}
		return sb.toString();
	}
	
	
	
	void saveStuffToFile(String fileName) throws Exception {
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName));
		out.writeObject(listOfStuff);
		out.close();
	}
	
	
	@SuppressWarnings("unchecked")
	void loadStuffFromFile(String fileName) throws Exception {
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName));
		listOfStuff = (ArrayList<Stuff>)in.readObject();
		in.close();
	}
	
	
}

