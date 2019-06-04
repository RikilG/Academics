import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/*
<applet code="MyApplet" width=800 height=600></applet>
*/

public class MyApplet extends Applet implements ActionListener,ItemListener,AdjustmentListener,MouseMotionListener {

	Label l1,l2;
	Button b1,b2;//Buttons are passive interfaces. add a listner.
	Checkbox c1,c2,c3;
	Choice ch1;
	List lt1;
	Scrollbar hsb,vsb;
	TextField t1,t2;
	String mb="",mc="",mch="",mlt="",msg="";

	public void init(){
		int w = Integer.parseInt(getParameter("width"));
		int h = Integer.parseInt(getParameter("height"));
		vsb = new Scrollbar(Scrollbar.VERTICAL,0,1,0,h);
		hsb = new Scrollbar(Scrollbar.HORIZONTAL,0,1,0,w);
		ch1 = new Choice();
		lt1 = new List(3,false);
		l1 = new Label("One");
		l2 = new Label("Two");
		b1 = new Button("Yes");
		b2 = new Button("No");
		c1 = new Checkbox("Morning");
		c2 = new Checkbox("Afternoon");
		c3 = new Checkbox("Evening");
		t1 = new TextField(16);
		t2 = new TextField(10);

		lt1.add("Thursday");
		lt1.add("Friday");
		lt1.add("Saturday");
		lt1.add("Holiday");
		lt1.add("WorkingDay");
		lt1.select(2);//default selection.
		ch1.add("Sunday");
		ch1.add("Monday");
		ch1.add("Tuesday");
		ch1.add("Wednesday");
		t2.setEchoChar(' ');

		vsb.addAdjustmentListener(this);
		hsb.addAdjustmentListener(this);
		addMouseMotionListener(this);//mouse is already active.
		b1.addActionListener(this);//will call actionPerformed.
		b2.addActionListener(this);
		c1.addItemListener(this);
		c2.addItemListener(this);
		c3.addItemListener(this);
		ch1.addItemListener(this);
		lt1.addActionListener(this);

		add(vsb);
		add(hsb);
		add(l1);//add all items to layout.
		add(l2);
		add(b1);
		add(b2);
		add(c1);
		add(c2);
		add(c3);
		add(ch1);
		add(lt1);
		add(t1);
		add(t2);
	}

	public void paint(Graphics g){
		msg = "Vertical : "+vsb.getValue()+" Horizontal : "+hsb.getValue();
		mch = "Choice Item : " + ch1.getSelectedItem();
		mlt = "List Item : " + lt1.getSelectedItem();//didnotWork
		g.drawString(mb,60,160);
		g.drawString(mc,60,180);
		g.drawString(mch,60,200);
		g.drawString(mlt,60,220);
		g.drawString(msg,60,240);
		g.drawString(t1.getText(),60,270);
		g.drawString(t2.getText(),60,290);
	}

	public void actionPerformed(ActionEvent ae){
			String str = ae.getActionCommand();
			if(str.equals("Yes"))
				mb = "You pressed Yes...";
			else
				mb = "You pressed No...";
			repaint();
	}

	public void itemStateChanged(ItemEvent ie){
		mc = "Checkbox selected :";
		if(c1.getState())
			mc = mc + " Morning";
		if(c2.getState())
			mc = mc + " Afternoon";
		if(c3.getState())
			mc = mc + " Evening";
		repaint();
	}

	public void adjustmentValueChanged(AdjustmentEvent ae){
		repaint();
	}

	public void mouseDragged(MouseEvent me){
		int x = me.getX();
		int y = me.getY();
		vsb.setValue(y);
		hsb.setValue(x);
		repaint();
	}

	public void mouseMoved(MouseEvent me){
		//requried empty constructor for implementation;
	}
}