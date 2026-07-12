class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        string h1,m1,s1,h2,m2,s2;
        h1 = s.substr(0, 2);
        m1 = s.substr(3, 2);
        s1 = s.substr(6, 2);
        h2 = e.substr(0, 2);
        m2 = e.substr(3, 2);
        s2 = e.substr(6, 2);
        int a =  - (stoi(h1)*3600+stoi(m1)*60+stoi(s1)) + (stoi(h2)*3600+stoi(m2)*60+stoi(s2));
        return a;
    }
};