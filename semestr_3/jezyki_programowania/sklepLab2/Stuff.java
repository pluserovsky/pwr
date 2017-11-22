package sklepLab2;



/* 
 *  Program Sklep internetowy
 *  Autor: Lukasz Broll
 *   Data: 30-1-2016 r.
 */

import java.io.Serializable;


public class Stuff implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	private String name;               // nazwa towaru
	private double prize;              // cena jednostkowa
	private int amount;            // liczba sztuk
	
	
	Stuff(String name){
		this.name = name;
		prize = 0;
		amount = 0;
	}
	
	public String getName(){
		return name;
	}
	public double getPrize(){
		return prize;
	}
	public int getAmount(){
		return amount;
	}
	
	
	public void setName(String name){
		this.name = name;
	}
	public void setPrize(double prize){
		this.prize = prize;
	}
	public void setAmount(int amount){
		this.amount = amount;
	}

	
	public String toString(){
		return String.format("%s: %s zl, %s sztuk ", name, prize, amount);
	}
	public String toStringHistory(int amount, double prize){
		return String.format("%s: %s zl, %s sztuk ", name, prize, amount);
	}


	
}


