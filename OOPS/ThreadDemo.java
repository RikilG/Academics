class MyThread implements Runnable {
	Thread t;
	String name;
	MyThread(String name) {
		this.name = name; 
		t = new Thread(this,name);
		t.start();
	}
	
	public void run() {
		if(name == "Thread1") {
			for(int i=1;i<=10;i++) {
				System.out.println(i);
			}
		}
		if(name == "Thread2") {
			for(int i=11;i<=20;i++) {
				System.out.println(i);		
		}
	}
}		
}

class ThreadDemo {
	public static void main(String args[]) {
		MyThread t1 = new MyThread("Thread1");
		MyThread t2 = new MyThread("Thread2");
		System.out.println(t1.t);
		t1.t.setName("hello");
		System.out.println(t1);
		//System.out.println(
			try{ t1.t.join();
				 t2.t.join(); }
				catch(InterruptedException ie) {System.out.println(ie);}
			}
	}

	
		
		
