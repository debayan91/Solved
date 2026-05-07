class Solution {
    public int rev(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    public int sumOfPrimesInRange(int n) {
        int rev = rev(n);
        int sum = 0;

        int max, min;

        if(rev < n){
            max = n;
            min = rev;
        }else{
            max = rev;
            min = n;
        }

        //simple sieve

        int limit = (int) Math.floor(Math.sqrt(max)) + 1;

        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= limit; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= limit; i += p)
                    isPrime[i] = false;
            }
        }

        List<Integer> list = new ArrayList<>();

        for(int i = 2; i < isPrime.length; i++){
            if(isPrime[i]) list.add(i);
        }

        boolean[] range = new boolean[max - min + 1];
        Arrays.fill(range, true);

        for(int p : list){
            int start = Math.max(p * p, ((min + p - 1) / p) * p);
            while(start <= max){
                range[start - min] = false;
                start += p;
            }
        }
        if(min == 1) range[0] = false;

        for(int i = 0 ; i < range.length; i++){
            if(range[i]) sum += i + min;
        }

        return sum;
    }
}