import javax.swing.*;
import java.awt.*;

class SwingDemo {

	SwingDemo() {
		JFrame jf = new JFrame("My Frame");
		jf.setSize(300,300);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
						//allows to specify what happens when clicked on close( HIDE_ON_CLOSE  DO_NOTHING_ON_CLOSE)
		JLabel jl = new JLabel("hello");
		JLabel jl1 = new JLabel("hello1");
		//jf.add(jl); //this instance of jframe add jlabel
		//jf.add(jl1);(multiple labels add results in only last label executing
		
		jf.add(jl,BorderLayout.EAST);
		jf.add(jl1,BorderLayout.WEST);
		jf.setVisible(true); //by defualt label frame is not visible so make it visible
	}
	
	public static void main(String args[]) {
		//event dispatching thread. main thread does not handle events (new feature - anonymus inner class)
		SwingUtilities.invokeLater(new Runnable() { public void run() { new SwingDemo();}});
		 // new thread doing everything dont want main to handel GUI
		}
}

//default layout in awt is flow layout
//default layout in swing is border layout
//passive gui code above
