//write a program to implement to add sub mul div operatins on complex numbers.

import java.util.Scanner;

class Complex {
	
	float x;
	float y;
	
	void set(){
		Scanner sc = new Scanner(System.in);
		System.out.println("\nNew complex number...");
		System.out.print("Enter real part : ");
		x = sc.nextFloat();
		System.out.print("Enter imaginary part : ");
		y = sc.nextFloat();
	}
	
	void show(){
		System.out.println(x + "+i" + y);
	}
	
	Complex add(Complex b, Complex c){
		Complex a = new Complex();
		a.x = b.x + c.x;
		a.y = b.y + c.y;
		System.out.println("Sum is = " + a.x + "+i" + a.y);
		return a;
	}
	
	Complex sub(Complex b, Complex c){
		Complex a = new Complex();
		a.x = b.x - c.x;
		a.y = b.y - c.y;
		System.out.println("Difference is = " + a.x + "+i" + a.y);
		return a;
	}
	
	Complex mul(Complex b, Complex c){
		Complex a = new Complex();
		a.x = b.x*(c.x) - b.y*(c.y);
		a.y = b.x*(c.y) + b.y*(c.x);
		System.out.println("Product is = " + a.x + "+i" + a.y);
		return a;
	}
	
	Complex div(Complex b, Complex c){
		Complex a = new Complex();
		c.y = -c.y;
		a = mul(b,c);
		c.y = -c.y;
		a.x = a.x/(c.x*c.x + c.y*c.y);
		a.y = a.y/(c.x*c.x + c.y*c.y);
		System.out.println("Quotient is = " + a.x + "+i" + a.y);
		return a;
	}
	
}

class Main_Complex {
	
	public static void main(String args[]){
	
		Complex c1 = new Complex();
		Complex c2 = new Complex();
		Complex c = new Complex();
		c1.set();
		c2.set();
		c1.show();
		c2.show();
		c.add(c1,c2);
		c.sub(c1,c2);
		c.mul(c1,c2);
		c.div(c1,c2);
	
	}
	
}
