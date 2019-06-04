import java.util.Scanner;

class SumLast {

	public static void main(String args[]){
	
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number : ");
		int x = sc.nextInt();
		System.out.print("How many digits do you want??? : ");
		int n = sc.nextInt();
		int sum = 0;
		//x = x%10 + x/10;
		for(int i=1;i<=n;i++){
			//System.out.println(n%10);
			//System.out.println(n/10);
			sum += x%10;
			x /= 10;
		}
		System.out.println("Sum of last n digits is : "+sum);
	
	}

}
