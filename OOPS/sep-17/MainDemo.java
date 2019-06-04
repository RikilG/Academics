package practice2;
import java.util.Scanner;

interface GeometricObject {
	public double getPerimeter();
	public double getArea();
}

interface Resizable {
	public void resize(int percent);
}

class Circle implements GeometricObject {
	protected double radius = 1.0;
	public static final double PI = 1.14159;
	
	public Circle(){
		System.out.print(">>Enter circle radius : ");
		Scanner sc = new Scanner(System.in);
		radius = sc.nextDouble();
	}
	public Circle(double radius){
		this.radius = radius;
	}
	public double getPerimeter(){
		return 2*PI*radius;
	}
	public double getArea(){
		return PI*radius*radius;
	}
}

class ResizableCircle extends Circle implements Resizable {
	public ResizableCircle(){
		super();
	}
	public ResizableCircle(double radius){
		super(radius);
	}
	public void resize(int percent){
		radius = ((double)percent/100)*radius;
	}
}

class Runner {
	
	public static void main(String args[]){
		Circle c1 = new Circle();
		ResizableCircle c2 = new ResizableCircle();
		
		System.out.println("c1 : \n" + c1.getPerimeter());
		System.out.println(c1.getArea() + "\n");
		System.out.println("c2 : \n" + c2.getPerimeter());
		System.out.println(c2.getArea() + "\n");
		c2.resize(50);
		System.out.println("Resized c2 : \n" + c2.getPerimeter());
		System.out.println(c2.getArea() + "\n");
		//System.out.println(Circle.PI);
	}	
	
}
