
#include <stdio.h>		/* Заголовочный файл объявляет несколько целочисленных типов и макросов */
#include <stdint.h>		/* Заголовочный файл объявляет несколько целочисленных типов и макросов */

// Инициализируем первичный массив с числами
int32_t mas [] = {1, 5, 3, 9};

// Инициализируем указатель на новый массив. Начальное значение NULL
int32_t* AVG_result = NULL;
	
// Объявляем прототип функции, которая будет выполнять задание
int32_t* finding_AVG (int32_t* array_ptr, size_t array_size,int32_t* new_array_ptr_SI);	
	
// Объявляем прототип функции, которая будет вычислять сумму элементов массива
int32_t new_mas_positiv (int32_t* array_ptr, size_t array_size, int32_t* new_array_ptr_SI);		
	
//Экспортируем функцию	из main.s написанную на ассемблере.
extern void finding_AVG_asm (int32_t* array_ptr, size_t array_size, int32_t* new_array_ptr, int32_t* finding_AVG_asm_result);

// Объявляем пустой массив для передачи его адреса в функцию finding_AVG_asm
int32_t new_array_ptr [(sizeof(mas)/sizeof(int32_t))/2 + (sizeof(mas)/sizeof(int32_t))%2] = {0};

int32_t new_array_ptr_SI [(sizeof(mas)/sizeof(int32_t))/2 + (sizeof(mas)/sizeof(int32_t))%2] = {0};

int32_t finding_AVG_asm_result [1] = {0};

int main (void)
{
    // Что такое куча? Где она находится? Как работает malloc, free?
    // В какой памяти находятся локальные переменные? На каком этапе под них выделяется место?
    
	AVG_result = finding_AVG(mas, sizeof(mas)/sizeof(int32_t), new_array_ptr_SI);
    
	finding_AVG_asm (mas, sizeof(mas)/sizeof(int32_t), new_array_ptr, finding_AVG_asm_result);
	
	while (1)
	{
	}
	return 0;
}

int32_t* finding_AVG (int32_t* array_ptr, size_t array_size, int32_t* new_array_ptr_SI)
{
	int32_t AVG = 0;
    int32_t* new_mas = NULL;
    
	new_mas = new_mas_positiv(array_ptr, array_size, new_array_ptr_SI);
    
    int32_t finding_AVG_n = 0;
    
	for (int32_t i = 2 ; i < array_size/2+array_size%2; i++)
	{
        if ( new_mas[i] == 0)
        {
            break;
        }
        else
        {
            AVG = AVG + new_mas[i];
            finding_AVG_n = finding_AVG_n + 1;
        }
    }
	return AVG/finding_AVG_n;
}

int32_t new_mas_positiv (int32_t* array_ptr, size_t array_size, int32_t* new_array_ptr_SI)
{
    
    int32_t new_mas_positiv_n = 2;
        
	for (uint32_t i = 0 ; i < array_size ; i += 2)
	{
        if (*(array_ptr + i) > 0)
        {
            *(new_array_ptr_SI + new_mas_positiv_n) = *(array_ptr + i);
            new_mas_positiv_n = new_mas_positiv_n + 1;
        }
	}
    
	return new_array_ptr_SI;
}