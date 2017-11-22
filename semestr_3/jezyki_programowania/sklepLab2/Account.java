package sklepLab2;



/* 
 *  Program Sklep internetowy
 *  Autor: Lukasz Broll
 *   Data: 30-1-2016 r.
 */

import java.io.Serializable;


public class Account implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	private String   id;					// identyfikator
	private String adress;               // adres
	private String owner;              // nazwisko w�a�ciciela
	private long   passwordCode;       // kod has�a
	private double balance;            // dostepna kwota pieniedzy
	private Boolean isSeller;			//sprawdzenie dostępu konta
	private double cashed;			//suma wydanych pieniedzy klienta
	private String history;			// historia zakupów
	
	
	Account(String owner){
		this.owner = owner;
		passwordCode = 0;
		balance = 0;
		isSeller=false;
		cashed=0;
		history = "";
	}
	
	
	public String getHistory(){
		return history;
	}
	
	public void setHistory(String history){
		this.history = history;
	}
	
	public String getId(){
		return id;
	}
	
	public void setId(String id){
		this.id = id;
	}
	
	public double getCashed(){
		return cashed;
	}
	
	public void setCashed(double cashed){
		this.cashed = cashed;
	}
	public boolean getIsSeller(){
		return isSeller;
	}
	
	public void setIsSeller(boolean isSeller){
		this.isSeller = isSeller;
	}
	
	public String getAdress(){
		return adress;
	}
	
	public void setAdress(String adress){
		this.adress = adress;
	}
	
	public void setOwner(String owner){
		this.owner = owner;
	}
	
	
	public String getOwner(){
		return owner;
	}
	
	
	public boolean checkPassword(String password) {
		if (password==null) return false;
		return password.hashCode()==passwordCode;
	}
	
	
	public void setPassword(String oldPassword, String newPassword) throws Exception {
		if (!checkPassword(oldPassword)) throw new Exception("B��dne has�o");
		passwordCode = newPassword.hashCode(); 
	}
	
	
	public double getBalance(){
		return balance;
	}
	public void setBalance(double balance){
		this.balance = balance;
	}
	
	
	public void payIn(double amount) throws Exception {
		if (amount<0) throw new Exception("Wp�ata nie mo�e by� ujemna");
		balance += amount;
	}
	
	public void payOut(String password, double amount) throws Exception {
		if (!checkPassword(password)) throw new Exception("B��dne has�o");
		if (amount<0) throw new Exception("Wyp�ata nie mo�e by� ujemna");
		if (amount>balance) throw new Exception("Brak �rodk�w na koncie");
		balance -= amount;
	}
	
	
	public void transfer(String password, double amount, 
			Account account) throws Exception {
		if (account==null) throw new Exception("Nieznane konto docelowe");
		payOut(password, amount);
		account.payIn(amount);
	}
	
	
	public String toString(){
		return String.format("ID:%s Nazwisko: %s Adres: %s Utarg: %s ",id, owner, adress, cashed);
	}

	
}

