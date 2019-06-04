import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SwingDemo1 {
	JLabel jl;
	SwingDemo1() {
		JFrame jf = new JFrame("Renegade");
		jf.setLayout(new FlowLayout());
		jf.setSize(300,300);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton jb1 = new JButton("one");
		JButton jb2 = new JButton("two");  //whenever you define instance of component - add component, defint event handler, and        )
		jb1.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
							jl.setText("Button 1 was pressed");}});
		jb2.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
							jl.setText("Button 2 was pressed");}});
		jf.add(jb1);
		jf.add(jb2);
		jl = new JLabel("press a button");
		jf.add(jl);
		jf.setVisible(true);
	}
	
	public static void main(String args[]) {
		SwingUtilities.invokeLater(new Runnable() { 
													public void run() {  new SwingDemo1(); }
												  });
	}	
		
}


