package pa_1;

public class PowerOfTwo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int val1 = 1;
		int val2 = 40;
		int val3 = 128;
		int val4 = 4096;
		String str1 = " is a power of two!";
		String str2 = " is not a power of two!";
		if (powOfTwo(val1)) {
			System.out.println(val1 + str1);
		}
		else {
			System.out.println(val1 + str2);
		}
		if (powOfTwo(val2)) {
			System.out.println(val2 + str1);
		}
		else {
			System.out.println(val2 + str2);
		}
		if (powOfTwo(val3)) {
			System.out.println(val3 + str1);
		}
		else {
			System.out.println(val3 + str2);
		}
		if (powOfTwo(val4)) {
			System.out.println(val4 + str1);
		}
		else {
			System.out.println(val4 + str2);
		}
	}

	public static boolean powOfTwo(int val) {
		return (val & (val - 1)) == 0;
	}
}