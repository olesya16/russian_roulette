#include <iostream>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    cout << "=== Игра 'Русская рулетка' ===" << endl;
    cout << "Правила: 6 патронов, 1 пуля. Крутим барабан и стреляем." << endl;
    cout << "Выживешь — получишь 100 очков. Проиграешь — Game Over." << endl;
    cout << "----------------------------------" << endl;

    // Генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> bullet_pos(1, 6);  // Позиция пули (1 из 6)
    uniform_int_distribution<> spin(1, 6);        // Вращение барабана

    int score = 0;
    char choice;

    do {
        cout << "\nКрутим барабан...";
        this_thread::sleep_for(chrono::seconds(1));

        int chamber = spin(gen);  // Номер текущей камеры
        int bullet = bullet_pos(gen);  // Где пуля

        cout << "\nНажми Enter, чтобы выстрелить...";
        cin.ignore();  // Ожидание ввода

        if (chamber == bullet) {
            cout << "БАХ! Ты проиграл." << endl;
            cout << "Итоговый счет: " << score << endl;
            break;
        } else {
            cout << "Щелк! Пустую." << endl;
            score += 100;
            cout << "Текущий счет: " << score << endl;
        }

        cout << "\nСыграем еще? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Игра окончена. Твой счет: " << score << endl;
    return 0;
}
