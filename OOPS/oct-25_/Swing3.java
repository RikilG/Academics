import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/*
<applet code="Swing3" width="500" height="400"></applet>
*/

public class Swing3 extends JApplet implements ActionListener {
	
	JLabel jl;

	public void init() {
		try{
			SwingUtilities.invokeAndWait(
				new Runnable() {
					public void run() {
						makeGUI();
					}
				});
		}catch(Exception e){

		}
	}

	private void makeGUI() {
		setLayout(new FlowLayout());
		ImageIcon i1 = new ImageIcon("google.png");
		JButton jb1 = new JButton(i1);
		jb1.setActionCommand("Google Search");
		jb1.addActionListener(this);
		add(jb1);
		ImageIcon i2 = new ImageIcon("mickey.jpeg");
		JButton jb2 = new JButton(i2);
		jb2.setActionCommand("A Mouse");
		jb2.addActionListener(this);
		add(jb2);
		ImageIcon i3 = new ImageIcon("think.jpeg");
		JButton jb3 = new JButton(i3);
		jb3.setActionCommand("Small Thinker");
		jb3.addActionListener(this);
		add(jb3);
		jl = new JLabel("Hello World!!!");
		add(jl);
	}

	public void actionPerformed(ActionEvent e) {
		jl.setText("You Selected " + e.getActionCommand());

	}

}