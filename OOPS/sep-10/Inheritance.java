import java.util.Scanner;

class Person{
//set //display
	String name;
	
	Person(){
		System.out.println("In Person()");
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter name : ");
		this.name = sc.nextLine();
	}
	
	Person(String name){
		System.out.println("In Person(name)");
		this.name = name;
	}
	
	void setName(String name){
		this.name = name;
	}
	
	void getName(){
		System.out.println("name : " + name);
	}
	
}

class Employee extends Person{
//set //display
	int id;
	
	Employee(){
		super();
		System.out.println("In Employee()");
		this.setId();
	}
	
	Employee(String name){
		super(name);
		System.out.println("In Employee(name)");
		this.setId();
	}
	
	Employee(int id){
		super();
		System.out.println("In Employee(id)");
		this.id = id;
	}
	
	Employee(String name,int id){
		super(name);
		System.out.println("In Employee(name,id)");
		this.id = id;
	}
	
	void setId(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter id : ");
		this.id = sc.nextInt();
	}
	
	void setId(int id){
		this.id = id;
	}
	
	void getId(){
		System.out.println("Employee id : " + id);
	}
	
	void getName(){
		System.out.println("Employee name : " + name);
	} 
	
}

class Manager extends Employee{
	String position;
	
	Manager(){
		super();
		System.out.println("In Manager()");
		position = "Manager";
	}
}

class Inheritance{

	public static void main(String args[]){
		/*
		Employee e1,e2,e3,e4;
		e1 = new Employee();
		e2 = new Employee("autoName1");
		e3 = new Employee(1234);
		e4 = new Employee("autoName2",7890);
		
		System.out.println();
		
		e1.getName();
		e1.getId();
		e2.getName();
		e2.getId();
		e3.getName();
		e3.getId();
		e4.getName();
		e4.getId();
		*/
		Manager man = new Manager();
	}
	
}
