import java.util.Scanner;

class Palindrome{
	
	String str;
	
	Palindrome(){
		Scanner sc = new Scanner(System.in);
		System.out.print(">>Enter String : ");
		str = sc.nextLine();
		System.out.println();
	}
	
	void isPalindrome(){
		for(int i=0;i<=((str.length()+1)/2);i++){
			if(str.charAt(i)!=str.charAt(str.length()-i-1)){
				System.out.println("Not a palindrome...");
				return;
			}
		}
		System.out.println("This is a Palindrome...");
	}
	
}

class Main_Palindrome{
	
	public static void main(String args[]){
	
		Palindrome p = new Palindrome();
		p.isPalindrome();
	
	}
	
}
