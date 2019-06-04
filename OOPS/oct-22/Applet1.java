import java.awt.event.*;
import java.applet.*;
import java.awt.*;

/*
<applet code="Applet1.class" width="300" height="300"></applet>
*/

public class Applet1 extends Applet implements ActionListener {
	
	Button btn;
	TextField tf;
	TextField tf2;

	public void init() {
		tf = new TextField();
		tf.setBounds(35,45,250,20);
		tf.setText("Username");
		tf2 = new TextField();
		tf2.setBounds(35,70,250,20);
		tf2.setText("Password");
		btn = new Button("Login");
		btn.setBounds(215,100,60,30);
		add(btn);
		add(tf);
		add(tf2);
		btn.addActionListener(this);
		setLayout(null);
	}

	public void actionPerformed(ActionEvent ae) {
		tf.setText("Welcome to event handling using applets.");
		System.out.println("Application is exiting.");
	    setVisible(false);
	    //dispose();
	    if(true)
	    System.exit(0);
	}
}