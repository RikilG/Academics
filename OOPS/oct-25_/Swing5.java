import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/*
<applet code="Swing5" width="500" height="400"></applet>
*/

public class Swing5 extends JApplet implements ItemListener{
	
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
		jl = new JLabel();
		JCheckBox cb = new JCheckBox("Bits");
		cb.addItemListener(this);
		add(cb);
		JCheckBox cb2 = new JCheckBox("Pilani");
		cb2.addItemListener(this);
		add(cb2);
		JCheckBox cb3 = new JCheckBox("Hyderabad");
		cb3.addItemListener(this);
		add(cb3);
		JCheckBox cb4 = new JCheckBox("Campus");
		cb4.addItemListener(this);
		add(cb4);
		add(jl);
	}

	public void itemStateChanged(ItemEvent e) {
		JCheckBox c = (JCheckBox)e.getItem();
		if(c.isSelected())
			jl.setText(c.getText() + " is selected.");
		else
			jl.setText(c.getText() + " is not selected.");
	}

}