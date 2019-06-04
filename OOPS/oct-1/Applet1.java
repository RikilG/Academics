import java.applet.*;
import java.awt.*;

public class Applet1 extends Applet {

	public void paint(Graphics g){

		g.drawString("Hello, World!!!",20,30);
		g.setColor(Color.black);
		g.drawString("Welcome",50,50);
		g.drawLine(20,30,20,300);
		g.drawRect(70,100,30,30);
		g.fillRect(170,100,30,30);
		g.drawOval(70,200,30,30);
		g.setColor(Color.cyan);
		g.fillOval(170,200,30,30);
		g.drawArc(90,150,30,30,30,270);
		g.fillArc(270,150,30,30,0,180);
	}

}
