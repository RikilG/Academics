import java.sql.*;

class DbTest {
	public static void main(String args[]) {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/student","root","root");
			Statement s = con.createStatement();
			ResultSet rs = s.executeQuery("select * from students");
			while(rs.next()) {
				System.out.println(rs.getInt(1)+" "+rs.getString(2));
			}
			con.close();
		}catch(Exception e) {
			System.out.println(e);
			e.printStackTrace();
		}
	}
}
