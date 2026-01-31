#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = 0; // костыль на случай, если в конце 3 повтора. нужен, чтобы вызвалась проверка на максимум (она когда 3+ повтора и текущий элемент не повтор)
    int counter = 1;
    int beg = 1, cur_beg = 1, end = 1, cur_end = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            counter++;
        }
        else { // если закончился ряд повторяющихся чисел
            if (counter >= 3) {
                cur_end = i - (counter - 2);
                if (cur_end - cur_beg > end - beg) {
                    end = cur_end;
                    beg = cur_beg;
                }
                cur_beg = i - 1;
            }
            counter = 1; // закончился ряд повторяющихся чисел, начинаем новый, счетчик = 1
        }
    }
    if (a[n - 1] - cur_beg > end - beg) {
        end = cur_end;
        beg = n;
    }
    cout << beg << " " << end;
}
// не используются массивы. вроде работает правильно.
