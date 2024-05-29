#include "labs.h"



int lab1()
{
int A;
int B;
int C;
int P;
printf("A=");
scanf("%d",&A);
printf("B=");
scanf("%d",&B);
printf("C=");
scanf("%d",&C);
P= (A*A*A + B*B)/(A-C);
printf ("distance = %d\n",P);
return 0;
}


int lab2()
{
    float x, E;
    printf("Vvedite x: ");
    scanf("%f", &x);
    printf("Vvedite E: ");
    scanf("%f", &E);

    float sum = 1.0; // первый элемент ряда
    float term = x; // текущий элемент ряда
    int n = 1; // номер текущего элемента

    while (term > E) {
        sum += term;
        n++;
        term *= x / n;
    }

    printf("Summa pervyh %d elementov ryada: %.4f\n", n, sum);

    return 0;
}



int lab3()
{
    int c;
    int wordCount = 0; // Счётчик слов в предложении
    int inWord = 0; // Флаг, указывающий, что мы находимся внутри слова

    printf("Vvedite predlojenie: ");

    while (scanf("%c", &c) == 1 && c != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            if (!inWord) {
                inWord = 1; // Меняем флаг, если начинается новое слово
                wordCount++;
            }
        } else {
            inWord = 0; // Сбрасываем флаг, если символ - пробел или перевод строки
        }
    }

    printf("Slov v predlojenii: %d\n", wordCount);

    return 0;
}



int lab4()

{
    int customStrlen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

    int customStrncmp(char *str1, char *str2, int n) {
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                return 1;
            }
        }
        return 0;
    }

    void removeWordsWithPrefix(char *str, char *prefix) {
        int i = 0, j = 0;
        int start = 0, end = 0;
        int len = customStrlen(str);
        int prefixLen = customStrlen(prefix);

        while (i < len) {
            if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
                start = i + 1;
                end = i + 1;
            } else {
                while (i < len && str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
                    i++;
                    end++;
                }

                if (end - start >= prefixLen && customStrncmp(&str[start], prefix, prefixLen) == 0) {
                    for (int k = start; k < end; k++) {
                        str[k] = ' ';
                    }
                }
            }

            i++;
        }
    }

    int main() {
        char str[100];
        char prefix[20];

        printf("Vvedite stroku slov: ");
        scanf("%[^\n]", str);

        printf("Vvedite prristavku: ");
        scanf("%s", prefix);

        printf("Before: %s\n", str);
        removeWordsWithPrefix(str, prefix);
        printf("After: %s\n", str);

        return 0;
}
}

int lab5 ()
{
    int n=10;
    int arr[n]; // Объявляем массив из 10 целых чисел
    int i, isMirror = 1; // Переменная для использования в циклах и флаг для проверки зеркальности (изначально установлен в 1 - true)
    printf("Vvedite 10 celyh chisel:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Сохраняем введенные значения в массив
    }

    // Проверяем, является ли массив зеркальным
    for (i = 0; i < n/2; i++) { // Проходим только половину массива (5 элементов)
        if (arr[i] != arr[(n-1) - i]) { // Если элементы на соответствующих позициях не равны друг другу
            isMirror = 0; // Устанавливаем флаг в 0 (false)
            break; // Прерываем цикл, так как уже известно, что массив не зеркальный
        }
    }

    // Выводим результат
    if (isMirror == 1) {
        printf("Massiv yavlyaetsya zerkalnym.\n");
    } else {
        printf("Massiv ne yavlyaetsya zerkalnym.\n");
    }

    return 0;
}

int lab6 ()
{
    int array[M][K];
    int positiveCount = 0;
    int negativeCount = 0;

    // Ввод массива
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            printf("Vvedite znachenie array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
            if (array[i][j] > 0) {
                positiveCount++;
            } else if (array[i][j] < 0) {
                negativeCount++;
            }
        }
    }

    // Обнуление элементов
    if (positiveCount < negativeCount) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < K; j++) {
                if (array[i][j] < 0) {
                    array[i][j] = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < K; j++) {
                if (array[i][j] > 0) {
                    array[i][j] = 0;
                }
            }
        }
    }

    // Вывод массива
    printf("Itogovii massiv:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}



// Функция для замены серий из 3 и более единиц на нули
unsigned long long replaceSeries(unsigned long long N) {
    unsigned long long mask = 0;//Маска- последовательность битов,
    unsigned long long result = N;
    int count = 0;

    for (int i = 0; i < 64; i++) {
        if (N & (1ULL << i)) {
            count++;
        } else {
            if (count >= 3) {
                mask |= ((1ULL << count) - 1) << (i - count);
            }
            count = 0;
        }
    }

    // Обработка случаев, когда серия из 1 находится в конце числа
    if (count >= 3) {
        mask |= ((1ULL << count) - 1) << (64 - count);
    }

    // Замена серий из 1 на 0
    result &= ~mask;

    return result;
}

int lab7 () {
    unsigned long long N;
    printf("Vvedite dlinnoe celoe chislo N: ");
    scanf("%llu", &N);

    unsigned long long result = replaceSeries(N);
    printf("Rezultat: %llu\n", result);

    return 0;
}
