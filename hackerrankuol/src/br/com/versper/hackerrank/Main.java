package br.com.versper.hackerrank;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        final String fileName = System.getenv("OUTPUT_PATH");
        BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
        int res;
        int _n;
        _n = Integer.parseInt(in.nextLine().trim());


        int _p_size = 0;
        _p_size = Integer.parseInt(in.nextLine().trim());
        int[] _p = new int[_p_size];
        int _p_item;
        for(int _p_i = 0; _p_i < _p_size; _p_i++) {
            _p_item = Integer.parseInt(in.nextLine().trim());
            _p[_p_i] = _p_item;
        }

        res = getUmbrellas(_n, _p);
        bw.write(String.valueOf(res));
        bw.newLine();

        bw.close();
    }

    static int getUmbrellas(int n, int[] p) {
        int minUmbrellas = -1;
        for (int i : p) {
            int umbrellas = n / i;
            System.out.println("umbrellas=" + umbrellas);
            if (0 == n % i) {
                minUmbrellas = minUmbrellas < 0 ? umbrellas : Math.min(minUmbrellas, umbrellas);
                System.out.println("minp=" + minUmbrellas + " i=" + i);
            }
        }
        System.out.println("return=" + minUmbrellas);
        return minUmbrellas;
    }
}
