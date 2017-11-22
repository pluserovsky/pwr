/* 
 *  Komunikator sieciowy
 *   - program uruchamiajacy serwer i dwóch klientów
 *
 *  Autor: Lukasz Broll
 *   Data: 16 stycznia 2017 r.
 */

class Tester {
	
	public static void main(String [] args){
		new PhoneBookServer();
		
		try{
			Thread.sleep(1000);
		} catch(Exception e){}
			
	  	new PhoneBookClient("Klient");

	}
	
}


