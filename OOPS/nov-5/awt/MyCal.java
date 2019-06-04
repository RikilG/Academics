import java.awt.*;
import java.awt.event.*;

public class MyCal extends Frame implements WindowListener,ActionListener {

	Label l1,l2,l3;
	TextField tf1,tf2,tf3;
	Button b1,b2,b3;
	
	MyCal() {
		l1 = new Label("Num 1 : ");
		l2 = new Label("Num 2 : ");
		l3 = new Label("Result : ");
		l1.setBounds(30,30,30,20);
		l2.setBounds(30,60,30,20);
		l3.setBounds(30,90,40,20);
		
		tf1 = new TextField();
		tf2 = new TextField();
		tf3 = new TextField();
		tf1.setBounds(70,30,30,20);
		tf2.setBounds(70,60,30,20);
		tf3.setBounds(70,90,30,20);
		
		b1 = new Button("+");
		b2 = new Button("-");
		b3 = new Button("Reset");
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b1.setBounds(30,120,30,20);
		b2.setBounds(80,120,30,20);
		b3.setBounds(130,120,50,20);
		
		add(l1);
		add(l2);
		add(l3);
		add(tf1);
		add(tf2);
		add(tf3);
		add(b1);
		add(b2);
		add(b3);
		
		setSize(300,300);
		setLayout(null);
		setVisible(true);
		
		addWindowListener(this);
	}
	
	//methods in ActionListener
	public void actionPerformed(ActionEvent e) {
		int n1 = Integer.parseInt(tf1.getText());
		int n2 = Integer.parseInt(tf2.getText());
		int result;
		
		if(b1.hasFocus()) { //can also use get coordinates. ae.getLabel().equals("+")(not working)
			result = n1+n2;
			tf3.setText(Integer.toString(result));
		}
		else if(b2.hasFocus()) { //ae.getLabel().equals("-")(not working)
			result = n1-n2;
			tf3.setText(Integer.toString(result));
		}
		else if(b3.hasFocus()) { //ae.getLabel().equals("-")(not working)
			tf1.setText("");
			tf2.setText("");
			tf3.setText("");
		}
	}
	
	// methods in WindowListener
	public void windowDeactivated(WindowEvent e) {}
	public void windowActivated(WindowEvent e) {}
	public void windowDeiconified(WindowEvent e) {}
	public void windowIconified(WindowEvent e) {}
	public void windowClosed(WindowEvent e) {
		System.exit(0);
	}
	public void windowClosing(WindowEvent e) {}
	public void windowOpened(WindowEvent e) {}
	public static void main(String args[]) {
		new MyCal();
	}
}
