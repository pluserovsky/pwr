import javax.swing.JLabel;
public class Stoper extends Thread{
	
	private int time;
	private JLabel labelTime;
	
	public void resetTime() {
		this.time = 0;
	}
	
	
	Stoper(JLabel labelTime) {
	this.time = 0;
	this.labelTime = labelTime;
	
	}
		
	public void run() {
		
		while(true) {
	
			try {
				time++;
				sleep(1000);
				labelTime.setText("Czas trwania programu: " + Integer.toString(time) + " sek");
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}
		
		
		

}