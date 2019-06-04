interface MyIf1 {
	
	double PI = 3.1415;

	void meth1();
	default void methdef(){
		System.out.println("default methoddef() form interface.");
	}
}

interface MyIf2 extends MyIf1 {
	void methNew();
}

class C1 implements MyIf1 {

	public void meth1(){
		//PI = 0; // compilation error.
		System.out.println("c1's version of meth1() form my interface.");
	}
	
	public void methdef(){
		System.out.println("overriden methdef form interface.");
	}
	
	public void meth2(){
		System.out.println("c1's version of meth2() non-interface method.");
	}
}

class C2 implements MyIf1 {

	public void meth1(){
		System.out.println("c2's version of meth1() form my interface.");
	}
}

class Main1 {

	public static void main(String args[]){
		C1 ob1 = new C1();
		ob1.meth1();
		ob1.methdef();
		//ob1.meth2(); //compilation error
		C2 ob2 = new C2();
		ob2.meth1();
		ob2.methdef();
	}
}
