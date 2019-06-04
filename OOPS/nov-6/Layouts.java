import java.awt.*;
import java.awt.event.*;

class Layouts extends Frame {
	Layouts() {
		Button b1,b2,b3,b4,b5;
		b1 = new Button("b1");
		b2 = new Button("b2");
		b3 = new Button("b3");
		b4 = new Button("b4");
		b5 = new Button("b5");

		setLayout(new GridLayout(2,3,2,2));
		setSize(300,300);
		add(b1);
		add(b2);
		//setLayout(new FlowLayout());
		add(b3);
		add(b4);
		add(b5);
		setVisible(true);
	}

	public static void main(String args[]) {
		new Layouts();
	}
}