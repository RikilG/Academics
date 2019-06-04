import java.awt.*;
import javax.swing.*;

/*
<applet code="Swing1" width="500" height="400"></applet>
*/

public class Swing1 extends JApplet {
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
		ImageIcon i = new ImageIcon("abstract.jpeg");
		JLabel j = new JLabel("Hello jpg image",i,JLabel.CENTER);
		add(j);
	}
}