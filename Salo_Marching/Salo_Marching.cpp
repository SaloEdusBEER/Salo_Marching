#include <iostream>
#include "vec2.h"

using namespace std;

int clamp(int value, int MIN, int MAX) {
    int a = fmax(fmin(value, MAX), MIN);
    return a;
}

int main()
{
    const int width = 120;
    const int height = 30;
    float aspect = (float)width / height; // сохраняю соотношение сторон
    float pixel_aspect = 11.0f / 24.0f; // размер пикселя в нормализованных координатах
    char gradient[] = " .,-~:;=!*#$@"; // градиент символов для отображения яркости
    int grdienst_size = sizeof(gradient) - 2; // размер градиента (без нулевого символа)

    char* screen = new char[height * width + 1];
    screen[height * width] = '\0'; // добавляю нулевой символ в конец строки для корректного вывода
    for (int time = 0; time < 10000; time++) {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                vec2 uv = vec2(i, j) / vec2(width ,height) * 2.0f - 1.0f; // нормализованные координаты пикселя
                
                char symbol= ' ';              
                uv.x *= aspect * pixel_aspect;
                uv.x += sin(time * 0.002);

                float dist = sqrt(uv.x * uv.x + uv.y * uv.y); // вычисляю длину в символах
                int color_index = (int)1.0f / dist; // индекс символа в градиенте
                color_index = clamp((int)1.0f / dist, 0, grdienst_size); // ограничиваю индекс градиента

                symbol = gradient[color_index]; // получаю символ из градиента
                screen[i + j * width] = symbol;
            }
        }
        printf(screen); // выводим экран в консоль, используя printf для форматирования строки
    }
   
    
}


