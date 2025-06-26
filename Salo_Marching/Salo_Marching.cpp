#include <iostream>
#include <math.h>
using namespace std;

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
                float x = (float)i / width * 2.0f - 1.0f; // делаю ширину экрана от -1 до 1
                float y = (float)j / height * 2.0f - 1.0f; // делаю высоту экрана от -1 до 1
                char symbol= ' ';              
                x *= aspect * pixel_aspect;
                x += sin(time * 0.002);

                float dist = sqrt(x * x + y * y); // вычисляю длину в символах
                int color_index = (int)1.0f / dist; // индекс символа в градиенте
                if(color_index<0) color_index = 0; // ограничиваю индекс градиента
                else if(color_index > grdienst_size) color_index = grdienst_size; // ограничиваю индекс градиента

                symbol = gradient[color_index]; // получаю символ из градиента
                screen[i + j * width] = symbol;
            }
        }
        printf(screen); // выводим экран в консоль, используя printf для форматирования строки
    }
   
    
}


