#include <bits/stdc++.h>
using namespace std;

long long s_to_i(string s)
{
    long long p=1, ans=0;
    for(long long i = (long long) s.length()-1; i >= 0; i--)
    {
        ans+=p * (s[i]-'0');
        p=10;
    }
    return ans;
}

long long len(long long x) {
    long long len =0;
    while(x%10) {
        x /= 10;
        len++;
    }
    return len;
}

long long operate(long long op1, long long op2, long long xy) {
    return len(op1) + len(op2) + xy;
}

long long getNumberBeforeOperator(string &s, long long posFin) {
    posFin--;
    long long posDebut = posFin;
    int longueur = (int) s.size();
    while(posDebut >= 0 && posDebut < longueur && s[posDebut] != '+' && s[posDebut] != '*' ) posDebut--;
    posDebut++;
    if(posDebut >= longueur) return 1;
    return s_to_i(s.substr(posDebut, posFin-posDebut+1));
}

long long getNumberAfterOperator(string &s, long long posDebut) {
    posDebut++;
    long long posFin = posDebut, longueur = (long long) s.size();
    while(posFin < longueur && posFin >= 0 && s[posFin] != '+' && s[posFin] != '*' ) posFin++;
    posFin--;
    return s_to_i(s.substr(posDebut, posFin-posDebut+1));
}

char getNextOperator(string &s, long long *pos) {
    (*pos)++;
    int longueur = (int) s.size();
    while(*pos < longueur && s[*pos] != '*' && s[*pos] != '+') (*pos)++;
    if(*pos >= longueur)
        return ' ';
    return s[*pos];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("l.in", "r", stdin);
//    freopen("input.txt.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    string  s;
    long long x, y;
    cin >> s >> x >> y;
    int longueur = (int) s.size();
    long long i=0, totalTime = 0;
    char op = getNextOperator(s, &i), previousOp;
    vector<long long> values;
    while(op != ' ') {
        previousOp = op;
        if(op == '*') {
            // calculating the products
            long long firstNumber = getNumberBeforeOperator(s, i);
            vector<long long> numbers;
            numbers.push_back(firstNumber);
            long long previousPos = i;
            op = getNextOperator(s, &i);
            while(op == '*') {
                previousPos = i;
                numbers.push_back(getNumberBeforeOperator(s, i));
                op = getNextOperator(s, &i);
            }
            long long lastNumber = getNumberAfterOperator(s, previousPos);
            numbers.push_back(lastNumber);

            // replacing the substring with its value
            sort(numbers.begin(), numbers.end());
            long long op1 = numbers[0], op2, _longueur = (long long) numbers.size();
            for (long long j = 1; j < _longueur; ++j) {
                op2 = numbers[j];
                totalTime += operate(op1, op2, y);
                op1 = op1 * op2;
            }
            values.push_back(op1);
        }
        else {
            if (op == '+') {
                // calculating the sums
                while (op == '+') {
                    values.push_back(getNumberBeforeOperator(s, i));
                    op = getNextOperator(s, &i);
                }
            }
        }
    }


    sort(values.begin(), values.end());
    long long op1 = values[0], op2, _longueur = (long long) values.size();
    for (long  long j = 1; j < _longueur; ++j) {
        op2 = values[j];
        totalTime += operate(op1, op2, x);
        op1 = op1 + op2;
    }

    cout << op1 << ' ' << totalTime;

    return 0;
}