import java.util.Scanner;

class StackOverflow extends Exception{
	StackOverflow(String s){
		super(s);
	}
}

class StackUnderflow extends Exception{
	StackUnderflow(String s){
		super(s);
	}
}

class Stack{
	private int stack[];
	private int pos;
	private int length=10;

	Stack(){
		stack = new int[length];
		pos = -1;
	}

	Stack(int size){
		length = size;
		stack = new int[length];
		pos = -1;
	}

	public void push(int number) throws StackOverflow{
		if(pos<length-1){
			stack[++pos] = number;
		}
		else{
			throw new StackOverflow("StackOverflow Occored");
		}
	}

	public int pop() throws StackUnderflow{
		if(pos!=-1){
			return stack[pos--];
		}
		else{
			throw new StackUnderflow("StackUnderflow Occored");
			//return -1;
		}
	}

	public void printStack() {
		System.out.println("\nElements in stack : ");
		for(int i=0;i<length;i++){
			System.out.println(stack[i]);
		}
		System.out.println("\n");
	}
}

class Runner {
	public static void main(String args[]){
		System.out.print("Enter your desired stack size : ");
		Scanner sc = new Scanner(System.in);
		int length = sc.nextInt();
		Stack stack = new Stack(length);
		System.out.println("Enter Stack Elements : ");
		try{
			for(int i=0;i<=length;i++){
				stack.push(sc.nextInt());
			}
		}catch(StackOverflow e){
			System.out.println(e);
		}

		try{
			stack.printStack();
			for(int i=0;i<=length;i++){
				System.out.println(stack.pop() + "is pushed out.");
			}
		}catch(StackUnderflow e){
			System.out.println(e);
		}
	}
}