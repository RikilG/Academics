import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/*
<applet code="Swing4" width="500" height="400"></applet>
*/

public class Swing4 extends JApplet {

	JLabel jl;
	JToggleButton jb;
	
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
		jl = new JLabel("Button is OFF");
		jb = new JToggleButton("On/Off");
		jb.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				if(jb.isSelected())
					jl.setText("Button is ON");
				else
					jl.setText("Button is OFF");
			}
		});
		add(jb);
		add(jl);
	}

}