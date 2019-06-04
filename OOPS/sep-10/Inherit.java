import java.util.Scanner;

class Person{
	String name;
	String id;
}

class Address{
	String address;
}

class Employee{
	
	Person p;
	Address a;	
	
	Employee(Person person,Address address){
		p = person;
		a = address;
	}
}
//demonstrate passing of args in constructors of person and address
//by the constructor of employee class
class Inherit{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		Person p1 = new Person();
		Address a1 = new Address();
		System.out.print("Enter name : ");
		p1.name = sc.nextLine();
		System.out.print("Enter id : ");
		p1.id = sc.nextLine();
		System.out.print("Enter address : ");
		a1.address = sc.nextLine();
		Employee e1 = new Employee(p1,a1);
		System.out.println(e1.p.name);
		System.out.println(e1.p.id);
		System.out.println(e1.a.address);
	}
}
