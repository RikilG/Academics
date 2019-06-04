import java.awt.*;
import java.awt.event.*;

/*
	This is not an applet
	Run normally to open file dialog.
*/

class SampleFrame extends Frame {
	SampleFrame(String title) {
		super(title);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}
}

class Gui2 {
	public static void main(String args[]) {
		Frame f = new SampleFrame("This is The Title");
		f.setVisible(true);
		f.setSize(300,300);
		FileDialog fd = new FileDialog(f,"File Dialog");
		fd.setVisible(true);
	}
}