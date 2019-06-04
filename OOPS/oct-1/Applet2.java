import java.applet.*;
import java.awt.*;

public class Applet2 extends Applet {

	public void paint(Graphics g){

		g.setColor(Color.red);
		g.fillArc(90,100,100,100,0,90);
		g.setColor(Color.blue);
		g.fillArc(90,100,100,100,90,20);
		g.setColor(Color.green);
		g.fillArc(90,100,100,100,110,60);
		g.setColor(Color.yellow);
		g.fillArc(90,100,100,100,170,50);
		g.setColor(Color.pink);
		g.fillArc(90,100,100,100,220,90);
		g.setColor(Color.black);
		g.fillArc(90,100,100,100,310,50);

		int nosex[] = {300,310,290};
		int nosey[] = {130,155,155};
		g.setColor(Color.yellow);
		g.fillOval(225,70,150,150);
		g.setColor(Color.blue);
		g.fillOval(260,105,22,22);
		g.fillOval(320,105,22,22);
		g.setColor(Color.red);
		g.fillArc(255,135,90,65,180,180);
		g.setColor(Color.pink);
		//g.drawLine(300,130,310,155);
		//g.drawLine(300,130,290,155);
		//g.drawLine(310,155,290,155);
		g.fillPolygon(nosex,nosey,3);

	}

} 