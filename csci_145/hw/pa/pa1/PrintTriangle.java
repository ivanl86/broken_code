package hw.pa.pa1;

public class PrintTriangle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int i = 0; i < 6; ++i) {
			for (int j = 5 - i; j >= 0; --j) {
				System.out.print(" ");
			}
			for (int k = 5 - i; k < 6; ++k) {
				System.out.print("*");
			}
			System.out.println();
		}
	}

}
