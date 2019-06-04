import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/*
<applet code="MyApplet2" width=800 height=600></applet>
*/
 
public class MyApplet2 extends Applet {

	Button b1,b2,b3,b4;
	TextField t;

	public void init(){

		setLayout(new BorderLayout());

		t = new TextField(12);
		add(t,BorderLayout.CENTER);
		b1 = new Button("Top");
		add(b1,BorderLayout.NORTH);
		b2 = new Button("Bottom");
		add(b2,BorderLayout.SOUTH);
		b3 = new Button("Right");
		add(b3,BorderLayout.EAST);
		b4 = new Button("Left");
		add(b4,BorderLayout.WEST);
	}
}