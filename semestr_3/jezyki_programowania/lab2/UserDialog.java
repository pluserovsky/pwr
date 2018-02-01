package sklepLab2;


/* 
 *  Interfejs UserDialog
 *  
 *  Prosta biblioteka metod do realizacji
 *  dialogu z u�ytkownikiem w prostych aplikacjach
 *  bez graficznego interfejsu u�ytkownika.
 *  
 *  Autor: Pawel Rogalinski
 *   Data: 1 pazdziernika 2016 r.
 */

public interface UserDialog{
	
	 /** Komunikat o b��dnym formacie wprowadzonych danych. */
    static final String ERROR_MESSAGE =
          "Nieprawid�owe dane!\nSpr�buj jeszcze raz.";

  
	public void printMessage(String message);
	
	public void printInfoMessage(String message);
	
	public void printErrorMessage(String message);
	
	public void clearConsole();
	
	public String enterString(String prompt);
	
	public char enterChar(String prompt);
	
	public int enterInt(String prompt);
	
	public float enterFloat(String prompt);
	
	public double enterDouble(String prompt);
}
