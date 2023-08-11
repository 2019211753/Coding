import java.io.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String numbers = in.readLine();
        String[] strNumbers = numbers.split(" ");
        int n = Integer.parseInt(strNumbers[0]);
        int n1 = Integer.parseInt(strNumbers[1]);
        int[] array = new int[n];
        int[] search = new int[n1];
        int[] re = new int[2 * n1];

        numbers = in.readLine();
        strNumbers = numbers.split(" ");
        for (int i = 0; i < strNumbers.length; i++) {
            array[i] = Integer.parseInt(strNumbers[i]);
        }

        for (int i = 0; i < n1; i++) {
            search[i] = Integer.parseInt(in.readLine());
        }
        in.close();

        sort(array, search, re, n, n1);
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < n1; i++) {
            out.write(Integer.toString(re[2 * i]));
            out.write(" ");
            out.write(Integer.toString(re[2 * i + 1]));
            out.newLine();
        }
        out.flush();
        out.close();
    }
}