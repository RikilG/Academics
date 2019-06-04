import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/*
<applet code="Swing2" width="500" height="400"></applet>
*/

public class Swing2 extends JApplet {

	JTextField j;

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
		j = new JTextField(15);
		add(j);
		JLabel jl = new JLabel();
		add(jl);

		j.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				jl.setText(j.getText());
				j.setText("");
			}
		});
	}
}