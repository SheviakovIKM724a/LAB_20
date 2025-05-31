#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(const vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n / 2; ++i) {
        if (vec[i] != vec[n - 1 - i])
            return false;
    }
    return true;
}

int sumBetweenNegatives(const vector<int>& vec) {
    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] < 0) {
            if (firstNeg == -1) firstNeg = i;
            lastNeg = i;
        }
    }

    if (firstNeg == -1 || lastNeg == -1 || firstNeg == lastNeg)
        return 0;

    int sum = 0;
    for (int i = firstNeg + 1; i < lastNeg; ++i) {
        sum += vec[i];
    }
    return sum;
}

int main() {
    system("chcp 1251 > nul"); // Підключення української мови (для Windows)
    vector<int> vec(10);
    cout << "Введіть 10 цілих чисел:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> vec[i];
    }

    if (isPalindrome(vec)) {
        cout << "Вектор є паліндромом.\n";
    }
    else {
        cout << "Вектор не є паліндромом.\n";
    }

    int sum = sumBetweenNegatives(vec);
    cout << "Сума елементів між першим і останнім від’ємними: " << sum << endl;

    return 0;
}
