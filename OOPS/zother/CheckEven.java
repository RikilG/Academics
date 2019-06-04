import java.util.Scanner;

class CheckEven {
	
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		System.out.print("\nEnter number1 : ");
		int x = sc.nextInt();
		System.out.print("Enter number2 : ");
		int y = sc.nextInt();
		System.out.print("Enter number3 : ");
		int z = sc.nextInt();
		x += y + z;
		System.out.println("Sum is : "+x+"\n");
		if(x%2 == 0){
			System.out.println("Sum is an even Number.\n");
		}
		else{
			System.out.println("Sum is an odd Number.\n");
		}
		
	}
	
}
