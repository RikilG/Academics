class ExHandling{
	public static void main(String args[]){

		String s[] = {"abc","123",null,"xyz"};
		for(int i=0;i<6;i++){
			try {
				int a = s[i].length() + Integer.parseInt(s[i]);
			}catch(NumberFormatException | ArrayIndexOutOfBoundsException | NullPointerException e){
				e.printStackTrace();
				System.out.println("Exception Caught...");
			}catch(Exception e){
				//do nothing...
			}finally{
				System.out.println("--------finally executed	");
			}
		}

	}
}