
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // подход€щим участком считаем последовательность цветков, в которой не встречаютс€ подр€д 3 одинаковых цветка
    vector<int> ends; // i-тый элемент €вл€етс€ номером максимального конца i-того подход€щего участка
    vector<int> begs; // i-тый элемент €вл€етс€ номером максимального начала i-того подход€щего участка
    begs.push_back(1);
    int counter = 1; // хранит количество одинаковых элементов подр€д до i-го на данный момент 
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            counter++;
        }
        else { // если закончилс€ р€д повтор€ющихс€ чисел
            if (counter >= 3) {
                ends.push_back(i - (counter - 2));
                begs.push_back(i - 1);
            }
            counter = 1; // закончилс€ р€д повтор€ющихс€ чисел, начинаем новый, счетчик = 1
        }
    }
    ends.push_back(n);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < ends.size(); i++) {
        if (ends[i] - begs[i] > ans2 - ans1) {
            ans1 = begs[i];
            ans2 = ends[i];
        }
    }
    cout << ans1 << " " << ans2;
}
// точно работающа€ верси€. минус - использование массивов (тратитс€ много пам€ти)