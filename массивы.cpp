
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
    // подходящим участком считаем последовательность цветков, в которой не встречаются подряд 3 одинаковых цветка
    vector<int> ends; // i-тый элемент является номером максимального конца i-того подходящего участка
    vector<int> begs; // i-тый элемент является номером максимального начала i-того подходящего участка
    begs.push_back(1);
    int counter = 1; // хранит количество одинаковых элементов подряд до i-го на данный момент 
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            counter++;
        }
        else { // если закончился ряд повторяющихся чисел
            if (counter >= 3) {
                ends.push_back(i - (counter - 2));
                begs.push_back(i - 1);
            }
            counter = 1; // закончился ряд повторяющихся чисел, начинаем новый, счетчик = 1
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
// точно работающая версия. минус - использование массивов (тратится много памяти)
