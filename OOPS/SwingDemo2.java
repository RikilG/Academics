import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
<applet code="SwingDemo2" width=800 height=600></applet>
*/

public class SwingDemo2 extends JApplet {
	JButton jb1,jb2;
	JLabel jl;
	public void init() {
		try {
			SwingUtilities.invokeAndWait(new Runnable() { public void run() { makeGUI(); } });
	   	}
	}
	
	private void makeGUI() {
		
		setLayout(new FlowLayout());
		
		JButton jb1 = new JButton("one");
		JButton jb2 = new JButton("two");  //whenever you define instance of component - add component, defint event handler, and        )
		jb1.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
							jl.setText("Button 1 was pressed");}});
		jb2.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
							jl.setText("Button 2 was pressed");}});
		jl = new JLabel("press a button");
		add(jb1);
		add(jb2);
	
}
