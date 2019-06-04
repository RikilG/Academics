import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/*
<applet code="Swing" width="500" height="400"></applet>
*/

public class Base extends JApplet {
	
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
		
	}

}