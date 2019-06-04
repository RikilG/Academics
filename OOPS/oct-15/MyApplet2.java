import java.applet.Applet;
import java.awt.*;

/*
<applet code="MyApplet2" width=500 height=300></applet>
*/

public class MyApplet2 extends Applet implements Runnable {

	String s;
	int x;
	Thread t;

	public void init() {
		s = "BITS-Hyd;";
		x = 0;
		t = new Thread(this);
		t.start();
	}

	public void run() {
		try {
			while(true) {
				repaint();
				Thread.sleep(200);
				x+=20;
			}
		}
		catch(Exception e){
			repaint();
		}
	}

	public void paint(Graphics g) {
		g.setFont(new Font("Serif",Font.BOLD,20));
		Dimension d = getSize();
		int y = d.height/2;
		g.drawString(s,x,y);
	}

}