class MyExp extends Exception {
	String s = null;
	
	MyExp(String string){
		s = string;
	}
	
	public String toString(){
		return s;
	}
	
	public String getMessage(){
		return s;
	}
}


class Main3 {

	static void Test(String s) throws MyExp{
		if(s==null){
			throw new MyExp("String is null.");
		}
	}	
	
	public static void main(String args[]){
		try{
			//int x = 5/0;
			Test(null);
		}catch(MyExp e){
			System.out.println(e.getMessage());
			e.initCause(new ArithmeticException());
			//e.initCause(new ArrayIndexOutOfBoundsException());
			//will cause illegalstate exception(Runtime)
			System.out.println(e.getCause());
		}
	}
}
