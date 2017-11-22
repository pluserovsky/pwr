package sklepLab2;


/* 
 *  Klasa ConsoleUserDialog 
 *  - implementacja interfejsu UserDialog. 
 *  
 *  Prosta biblioteka metod do realizacji
 *  dialogu z u�ytkownikiem w prostych aplikacjach
 *  bez graficznego interfejsu u�ytkownika.
 *  
 *  Autor: Pawel Rogalinski
 *   Data: 1 pazdziernika 2016 r.
 *   
 *   
 *  Program Sklep internetowy
 *  Autor: Lukasz Broll
 *   Data: 30-1-2016 r.
 

 */

import javax.swing.JOptionPane;

public class JOptionPaneUserDialog implements UserDialog {

    private StringBuilder messageBuilder = new StringBuilder();

	   
    public void printMessage(String message) {
		messageBuilder.append(message);
		messageBuilder.append("\n");
	}
	
	
    public void printInfoMessage(String message) {
		messageBuilder.append(message);
		messageBuilder.append("\n");
		JOptionPane.showMessageDialog(null, messageBuilder);
		messageBuilder = new StringBuilder();
	}
	
	
    public void printErrorMessage(String message) {
		messageBuilder.append(message);
		messageBuilder.append("\n");
		JOptionPane.showMessageDialog(null, messageBuilder, "", JOptionPane.ERROR_MESSAGE);
		messageBuilder = new StringBuilder();
	}
	
	
    
	public void clearConsole(){
		messageBuilder.append("\n\n");
	}

	
   
	public String enterString(String prompt) {
		messageBuilder.append(prompt);
		String message = JOptionPane.showInputDialog(messageBuilder);
		messageBuilder = new StringBuilder();
		if (message!=null) return message;
		return "";
	}
	
	
    
	public char enterChar(String prompt) {
		boolean isError;
		char c = ' ';
		do {
			isError = false;
			try {
				c = enterString(prompt).charAt(0);
			} catch (IndexOutOfBoundsException e) {
				printErrorMessage(ERROR_MESSAGE);
				isError = true;
			}
		} while (isError);
		return c;
	}

	
    
	public int enterInt(String prompt) {
        boolean isError;
        int i = 0;
        do{
            isError = false;
            try{ 
                i = Integer.parseInt(enterString(prompt));
            } catch(NumberFormatException e){
            	printErrorMessage(ERROR_MESSAGE);
            	isError = true;
            }
        }while(isError);
        return i;
    }
	
	
    
	public float enterFloat(String prompt) {
        boolean isError;
        float d = 0;
        do{
            isError = false;
            try{
                d = Float.parseFloat(enterString(prompt));
            } catch(NumberFormatException e){
            	printErrorMessage(ERROR_MESSAGE);
                isError = true;
            }
        } while(isError);
        return d;
    }   
	
	
   

	public double enterDouble(String prompt) {
        boolean isError;
        double d = 0;
        do{
            isError = false;
            try{
                d = Double.parseDouble(enterString(prompt));
            } catch(NumberFormatException e){
            	printErrorMessage(ERROR_MESSAGE);
                isError = true;
            }
        }while(isError);
        return d;
    }
    
    
}
