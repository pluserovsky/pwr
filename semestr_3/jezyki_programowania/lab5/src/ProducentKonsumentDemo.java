/*
 *  Problem producenta i konsumenta
 *
 *  Autor: Pawel Rogalinski
 *   Data: 1 pazdziernik 2009 r.
 */

class Producent extends Thread
{
    static char item = 'A';

    Bufor buf;
    int number;

    public Producent(Bufor c, int number){
        buf = c;
        this.number = number;
    }

    public void run(){
        char c;
        while(true){
            c = item++;
            buf.put(number, c);
            try {
                sleep((int)(Math.random() * 1000));
            } catch (InterruptedException e) { }
        }
    }
}

class Konsument extends Thread
{
    Bufor buf;
    int number;

    public Konsument(Bufor c, int number){
        buf = c;
        this.number = number;
    }

    public void run(){
        while(true){
            buf.get(number);
            try {
                sleep((int)(Math.random() * 1000));
            } catch (InterruptedException e) { }
        }
    }
}

class Bufor
{
    private char contents;
    private boolean available = false;

    public synchronized int get(int kons){
        System.out.println("Konsument #" + kons + " chce zabrac");
        while (available == false){
            try { System.out.println("Konsument #" + kons + "   bufor pusty - czekam");
                wait();
            } catch (InterruptedException e) { }
        }
        available = false;
        System.out.println("Konsument #" + kons + "      zabral: " + contents);
        notifyAll();
        return contents;
    }

    public synchronized void put(int prod, char value){
        System.out.println("Producent #" + prod + "  chce oddac: " + value);
        while (available == true){
            try { System.out.println("Producent #" + prod + "   bufor zajety - czekam");
                wait();
            } catch (InterruptedException e) { }
        }
        contents = value;
        available = true;
        System.out.println("Producent #" + prod + "       oddal: " + value);
        notifyAll();
    }
}


public class ProducentKonsumentDemo{

    public static void main(String[] args){
        Bufor c = new Bufor();
        Producent p1 = new Producent(c, 1);
        Konsument c1 = new Konsument(c, 1);
        Producent p2 = new Producent(c, 2);
        Konsument c2 = new Konsument(c, 2);
        p1.start();
        c1.start();
        p2.start();
        c2.start();
        try { Thread.sleep( 5000 );
        } catch (InterruptedException e) { }
        System.exit(0);
    }
}

