import java.io.*;

class Main1 {
	public static void main(String args[]) {
		File file1 = new File("file1.txt");
		File file2 = new File("file2.txt");
		File filew = new File("write.txt");

		try(FileReader fr1 = new FileReader(file1);
			FileReader fr2 = new FileReader(file2);
			FileWriter fw = new FileWriter(filew)) {

			int ch;
			while((ch=fr1.read()) != -1) {
				System.out.print((char)ch);
				fw.write((char)ch);
			}
			System.out.println();
			while((ch=fr2.read()) != -1) {
				System.out.print((char)ch);
				fw.write((char)ch);
			}

		}catch(Exception e) {
			System.out.println(e);
		}

	}
}