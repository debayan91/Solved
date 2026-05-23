class Solution {
public:
    int compareVersion(string a, string b) {
        vector<int> parts_a;

        stringstream ss(a);

        string x;

        while (getline(ss, x, '.')) {
            parts_a.push_back(stoi(x));
        }

        vector<int> parts_b;

        stringstream sss(b);

        string y;

        while (getline(sss, y, '.')) {
            parts_b.push_back(stoi(y));
        }

        // ---------------------------

        for(int i : parts_b) cout << i << " ";

        int n1 = parts_a.size();
        int n2 = parts_b.size();

        int i = 0;
        while(i < n1 && i < n2){
            if(parts_a[i] > parts_b[i]) return 1;
            else if(parts_b[i] > parts_a[i]) return -1;
            i++;
        }
        if(i == n1 && i == n2) return 0;
        if(i == n1){
            while(i < n2 && parts_b[i] == 0) i++;
            if(i == n2) return 0;
            else return -1;
        }else{
            while(i < n1 && parts_a[i] == 0) i++;
            if(i == n1) return 0;
            else return 1;
        }
    }
};