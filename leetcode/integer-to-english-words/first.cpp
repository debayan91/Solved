class Solution {
public:
    string ones(long num) {
        if (num == 0) {
            return "";
        }
        switch (num) {
        case 1:
            return "One";

        case 2:
            return "Two";

        case 3:
            return "Three";

        case 4:
            return "Four";

        case 5:
            return "Five";

        case 6:
            return "Six";

        case 7:
            return "Seven";

        case 8:
            return "Eight";

        case 9:
            return "Nine";
        }
        return "";
    }
    string ones2(long num) {
        if (num == 0) {
            return "";
        }
        switch (num) {
        case 10:
            return "Ten";

        case 11:
            return "Eleven";

        case 12:
            return "Twelve";

        case 13:
            return "Thirteen";

        case 14:
            return "Fourteen";

        case 15:
            return "Fifteen";

        case 16:
            return "Sixteen";

        case 17:
            return "Seventeen";

        case 18:
            return "Eighteen";

        case 19:
            return "Nineteen";
        }
        return "";
    }
    string tens(long num) {
        if (num == 0) {
            return "";
        }
        switch (num) {
        case 2:
            return "Twenty";

        case 3:
            return "Thirty";

        case 4:
            return "Forty";

        case 5:
            return "Fifty";

        case 6:
            return "Sixty";

        case 7:
            return "Seventy";

        case 8:
            return "Eighty";

        case 9:
            return "Ninety";
        }
        return "";
    }
    string hundred(long num) {
        if (num == 0)
            return "";
        if (num < 10)
            return ones(num);
        if (num < 20)
            return ones2(num);
        string s = "";
        if (num > 99) {
            long h = num / 100; // hundred's place
            num %= 100;         // rest
            s += ones(h) + " Hundred";
            s += (hundred(num).empty() ? "" : " " + hundred(num));
            return s;
        }
        long t = num / 10;
        num %= 10;
        s += tens(t);
        s += (ones(num).empty() ? "" : " " + ones(num));
        return s;
    }
    string numberToWords(long num) {
        long i;
        if (num == 0)
            return "Zero";
        if (num <= 999)
            return hundred(num);
        if (num <= 999999) {
            string thousand = hundred(num / 1000);
            string hundred1 = hundred(num % 1000);
            return thousand + " Thousand" + (hundred1.empty() ? "" : " " + hundred1);
        }
        if (num <= 999999999) {
            string million = hundred(num / 1000000);
            num = num % 1000000;
            string thousand = hundred(num / 1000);
            string hundred1 = hundred(num % 1000);
            return million + " Million" + (thousand.empty() ? "" :  " " + thousand + " Thousand" ) + (hundred1.empty() ? "" : " " + hundred1);
        }
        string billion = hundred(num / 1000000000);
        num = num % 1000000000;
        string million = hundred(num / 1000000);
        num = num % 1000000;
        string thousand = hundred(num / 1000);
        string hundred1 = hundred(num % 1000);
        return billion + " Billion" + (million.empty() ? "" : " " + million + " Million") + (thousand.empty() ? "" : " " + thousand + " Thousand") + (hundred1.empty() ? "" : " " + hundred1);
    }
};