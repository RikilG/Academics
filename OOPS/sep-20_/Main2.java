
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

class Main2 {

	static void newExp() throws Exception{
		System.out.println("Inside newExp().");
		throw new MyExp("Thrown Exception Successfully...");
	}
	
	public static void main(String args[]){
		try{
			newExp();
		}catch(Exception e){
			System.out.println("Message from Exception : "+e.getMessage()+"\n\nStack Trace : ");
			e.printStackTrace();
		}
		//String s = ""; // this does not generate null pointer exception;
		//Stirng s; // generates complation error;
		String s = null;
		int x = s.length();
	}
}
