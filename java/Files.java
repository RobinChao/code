import java.io.*;
import java.util.*;

class Files {
	public static void main(String[] args) {
		String filename = "file1";
		File file = new File(filename);

		System.out.println("\nWriting to file '" + filename + "' ...");
		try {
			FileOutputStream fout = new FileOutputStream(file);

			for(int i = 0; i < 10; ++i)
				fout.write(("This is line " + (i+1) + "\n").getBytes());

			fout.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}

		System.out.println("\nReading file '" + filename + "' as blocks ...");
		try {
			FileInputStream fin = new FileInputStream(file);
			int nBytes = fin.available();
			byte[] bytes = new byte[nBytes];

			fin.read(bytes);

			System.out.println("available bytes = " + nBytes);
			System.out.println("read bytes = '" + new String(bytes) + "'");

			fin.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}

		System.out.println("\nReading file '" + filename + "' byte by byte ...");
		try {
			FileInputStream fin = new FileInputStream(file);
			int b;

			while( (b = fin.read()) != -1) {
				System.out.printf("0x%x '%c' ", b, b);
			}
			System.out.println();

			fin.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}

		System.out.println("\nReading file '" + filename + "' line by line with BufferedReader ...");
		try {
			FileInputStream fin = new FileInputStream(file);
			BufferedReader bufReader = new BufferedReader(new InputStreamReader(fin));
			String line;

			while((line = bufReader.readLine()) != null) {
				System.out.println("line read = '" + line + "'");
			}
			System.out.println();

			bufReader.close();
			fin.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}

		System.out.println("\nReading file '" + filename + "' line by line with Scanner ...");
		try {
			Scanner sc = new Scanner(file);
			String line;

			while(sc.hasNextLine()) {
				line = sc.nextLine();
				System.out.println("line read = '" + line + "'");
			}
			System.out.println();

			sc.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}