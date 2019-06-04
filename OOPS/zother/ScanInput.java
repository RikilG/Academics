import java.util.Scanner;
class ScanInput {
	
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		String name = sc.nextLine();
		int age = sc.nextInt();
		long mobile = sc.nextLong();
		char gender = sc.next().charAt(0);
		
		System.out.println();
		System.out.println("Name : "+name);
		System.out.println("Age : "+age);
		System.out.println("Mobile : "+mobile);
		System.out.println("Gender : "+gender);
		
	}
	
}
