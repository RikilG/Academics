import java.awt.*;
import java.awt.event.*;

class AwtTest extends Frame {
	AwtTest() {
		TextArea ta = new TextArea();
		TextField tf = new TextField("File Name");
		Button b1,b2,b3;
		b1 = new Button("Save As");
		b2 = new Button("Submit");
		b3 = new Button("Exit");

		setLayout(new BorderLayout());
		add(ta,BorderLayout.CENTER);
		Panel p = new Panel();
		p.setLayout(new GridLayout(2,1));
		Panel p1 = new Panel();
		p1.setLayout(new GridLayout(1,2));
		p1.add(b1);
		p1.add(tf);
		Panel p2 = new Panel();
		p2.setLayout(new FlowLayout());
		p2.add(b2);
		p2.add(b3);
		p.add(p1);
		p.add(p2);
		add(p,BorderLayout.SOUTH);

		b3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae){
				System.exit(0);
			}
		});

		setSize(500,500);
		setVisible(true);
	}
	public static void main(String args[]) {
		new AwtTest();
	}
}