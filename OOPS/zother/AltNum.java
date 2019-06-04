import java.util.Scanner;

class AltNum {

	public static void main(String args[]){
	
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter start no : ");
		int start = sc.nextInt();
		System.out.print("Enter end no : ");
		int end = sc.nextInt();
		do{
			start += 2;
			if(start!=end){
				System.out.println(start);
			}
			
		}while(start < end);
	
	}

}
