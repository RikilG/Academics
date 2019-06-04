package practice1;

import java.util.*;

interface Shape {
	public double getArea();
}

class Rectangle implements Shape {
	double length;
	double width;
	
	Rectangle(double length, double width){
		this.length = length;
		this.width = width;
	}
	public double getArea(){
		return length*width;	
	}
	public String toString(){
		return "Class Rectangle. "+ getArea();
	}
}

class Triangle implements Shape {
	double base;
	double height;
	
	Triangle(double base, double height){
		this.base = base;
		this.height = height;
	}
	public double getArea(){
		return 0.5*base*height;
	}
	public String toString(){
		return "Class Triangle. " + getArea();
	}
}

class Runner {
	public static void main(String args[]){
		Shape s1 = new Rectangle(1,2);
		System.out.println(s1);
		System.out.println(s1.getArea());
		Shape s2 = new Triangle(3,4);
		System.out.println(s2);
		System.out.println(s2.getArea());
		//Shape s3 = new Shape("green");
	}
}
