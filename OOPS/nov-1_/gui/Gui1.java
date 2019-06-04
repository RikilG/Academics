import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="Gui1.class" height="500" width="500"></applet>
*/
class MenuFrame extends Frame {
	MenuFrame(String title) {
		super(title);
		MenuBar mbar = new MenuBar();
		setMenuBar(mbar);

		Menu file = new Menu("File");
		MenuItem item1,item2,item3;
		file.add(item1 = new MenuItem("New"));
		file.add(item2 = new MenuItem("Open"));
		//to put a seperator
		file.add(new MenuItem("-"));
		file.add(new MenuItem("dummy"));
		file.add(new MenuItem("-"));
		file.add(item3 = new MenuItem("Close"));
		mbar.add(file);

		Menu edit = new Menu("Edit");
		MenuItem eCut,eCopy,ePaste;
		edit.add(eCut = new MenuItem("Cut"));
		edit.add(eCopy = new MenuItem("Copy"));
		edit.add(ePaste = new MenuItem("Paste"));
		edit.add(new MenuItem("-"));
		Menu sub = new Menu("Special");
		MenuItem subi1,subi2,subi3;
		sub.add(subi1 = new MenuItem("First"));
		sub.add(subi2 = new MenuItem("Second"));
		sub.add(subi3 = new MenuItem("Third"));
		edit.add(sub);
		mbar.add(edit);

		MyWindowAdapter adp = new MyWindowAdapter(this);
		addWindowListener(adp);

		MyMenuHandler h = new MyMenuHandler(this);
		item1.addActionListener(h);
		item2.addActionListener(h);
		item3.addActionListener(h);

	}
}

class MyWindowAdapter extends WindowAdapter {
	MenuFrame mf;
	public MyWindowAdapter(MenuFrame m) {
		mf = m;
	}

	public void windowClosing(WindowEvent we) {
		mf.setVisible(false);
	}
}

class SampleDialog extends Dialog implements ActionListener {
	SampleDialog(Frame p, String title) {
		super(p,title,false);
		setLayout(new FlowLayout());
		setSize(130,70);
		add(new Label("Press Button"));
		Button b;
		add(b = new Button("Close"));
		b.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae) {
		dispose();
	}
}

class MyMenuHandler implements ActionListener {
	MenuFrame mf;
	public MyMenuHandler(MenuFrame m) {
		mf = m;
	}
	public void actionPerformed(ActionEvent ae) {
		String arg = ae.getActionCommand();
		if(arg.equals("Close")) {
			SampleDialog d = new SampleDialog(mf,arg);
			d.setVisible(true);
			mf.setVisible(false);
		}
		else {
			SampleDialog d = new SampleDialog(mf,arg);
			d.setVisible(true);
		}
	}
}

public class Gui1 extends Applet {
	Frame frame;

	public void init() {
		frame = new MenuFrame("Hello!!!");
		frame.setSize(200,200);
		frame.setVisible(true);
	}

	public void start() {
		frame.setVisible(true);
	}

	public void stop() {
		frame.setVisible(false);
	}

}