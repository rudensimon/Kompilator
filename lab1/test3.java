public class ArrayMain {
    public static void main(String[] a){
        System.out.println(new Arr().sumUp(5));
    }
}

class Arr {

    public int sumUp(int n){
        int i;
        int[] arr;
        int sum;

        arr = new int[n];   // NEW int [ expression ]
        i = 0;
        sum = 0;

        while (i < n) {
            arr[i] = i + 1;        // identifier [ expression ] = expression ;
            sum = sum + arr[i];    // expression [ expression ] (read)
            i = i + 1;
        }

        // also touches the LENGTH token
        return arr.length;   // expression . LENGTH
    }
}