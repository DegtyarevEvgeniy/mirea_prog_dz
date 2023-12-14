#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>


struct Animal {
    int x;
    int y;
    int age;
    char symbol;
};

struct Environment {
    int grassCount;
    float grassRegrowthRate;
    float naturalDisasterProbability;
};

void moveAnimal(Animal& animal) {
    int randomX = rand() % 3 - 1;
    int randomY = rand() % 3 - 1;
    animal.x += randomX;
    animal.y += randomY;
}

void displayInteraction(const std::vector<Animal>& herbivores, const std::vector<Animal>& predators, const Environment& environment) {
    // Отображение поля в консоли
    std::vector<std::vector<char>> field(20, std::vector<char>(30, '.'));

    for (const auto& herbivore : herbivores) {
        field[herbivore.y][herbivore.x] = 'H';
    }

    for (const auto& predator : predators) {
        field[predator.y][predator.x] = 'P';
    }

    for (int i = 0; i < environment.grassCount; ++i) {
        int x = rand() % 30;
        int y = rand() % 20;
        field[y][x] = 'G';
    }

    for (const auto& row : field) {
        for (char cell : row) {
            std::cout << std::setw(2) << cell;
        }
        std::cout << std::endl;
    }
}

void interaction(std::vector<Animal>& herbivores, std::vector<Animal>& predators) {
    for (auto& predator : predators) {
        for (auto& herbivore : herbivores) {
            float distance = std::sqrt(std::pow(predator.x - herbivore.x, 2) + std::pow(predator.y - herbivore.y, 2));
            if (distance < 1) {
                predator.symbol = 'P';
                predator.age++;
                herbivore.age++;
                if (predator.age > 50) {
                    predator.x = -1000;
                }
                if (herbivore.age > 50) {
                    herbivore.x = -1000;
                }
            }
        }
    }
}

void updateEnvironment(Environment& environment) {
    // Моделируем изменения в окружающей среде
    environment.grassCount += static_cast<int>(environment.grassCount * environment.grassRegrowthRate);
    
    // Моделируем природные катаклизмы
    if (rand() % 100 < environment.naturalDisasterProbability) {
        std::cout << "Наступил природный катаклизм!" << std::endl;
        // Ваш код для обработки катаклизма
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::vector<Animal> herbivores;
    std::vector<Animal> predators;

    Environment environment;
    environment.grassCount = 50;
    environment.grassRegrowthRate = 0.01;
    environment.naturalDisasterProbability = 5.0;

    // Инициализация параметров популяции травоядных
    for (int i = 0; i < 5; ++i) {
        Animal herbivore;
        herbivore.x = rand() % 30;
        herbivore.y = rand() % 20;
        herbivore.age = rand() % 10;
        herbivore.symbol = 'H';
        herbivores.push_back(herbivore);
    }

    // Инициализация параметров популяции хищников
    for (int i = 0; i < 2; ++i) {
        Animal predator;
        predator.x = rand() % 30;
        predator.y = rand() % 20;
        predator.age = rand() % 10;
        predator.symbol = 'P';
        predators.push_back(predator);
    }

    // Основной цикл программы
    for (int step = 0; step < 10; ++step) {
        // Обновление положения животных
        for (auto& herbivore : herbivores) {
            moveAnimal(herbivore);
        }
        for (auto& predator : predators) {
            moveAnimal(predator);
        }

        // Взаимодействие между хищниками и травоядными
        interaction(herbivores, predators);

        // Обновление окружающей среды
        updateEnvironment(environment);

        // Просмотр взаимодействия в консоли
        displayInteraction(herbivores, predators, environment);

        std::cout << "Шаг " << step + 1 << std::endl;

        std::cout << "Нажмите Enter для продолжения...";
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ожидание нажатия Enter
       }
    return 0;
}
