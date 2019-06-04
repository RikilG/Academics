class CmdArgs {

	public static void main(String args[]){
		
		int sum=0;
		
		for(String i:args){
			//System.out.print(i + " ");
			sum += Integer.parseInt(i);
		}
		System.out.println("\nSum = "+sum);
		/*
		for(int i=0;i<args.length;i++){
			System.out.println(args[i]);
			sum += Integer.parseInt(args[i]);
		}
		*/
		
	}
	
}
