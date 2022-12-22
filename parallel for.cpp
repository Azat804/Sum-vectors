// parallel for.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
void Print(int* mas,int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
}

int main()
{
    int id = 0;
    int i = 0;
    int j = 0;
    int n = 80;
    int k;
    int* a = new int[n];
    int* b=new int[n];
    int* c = new int[n];
    int* d = new int[n];
    int *e=new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
        b[i] = i + 1;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
    }
    printf("Mas a=\n");
    Print(a, n);
    printf("Mas b=\n");
    Print(b, n);
    double t1 = omp_get_wtime();
#pragma omp parallel private(id)
    {id = omp_get_thread_num();
    k = omp_get_num_threads();
    for (int j = 0; j < n / k; j++) {
        c[j + id * n / k] = b[j + id * n / k] + a[j + id * n / k];
    }

    }
    printf("Mas a+b=\n");
    for (int ii = 0; ii < n; ii++) {
        printf("%d ", c[ii]);
    }
    double t2 = omp_get_wtime();
    printf("\nTime 1=%f\n", t2 - t1);
    
#pragma omp parallel for
    for (int p = 0; p < n; p++) {
        d[p] = a[p] + b[p];
    }
    printf("Mas a+b=\n");
    for (int jj = 0; jj < n; jj++) {
        printf("%d ", d[jj]);
    }
    double t3 = omp_get_wtime();
    printf("\nTime 2=%f\n", t3 - t2);
    for (int kk = 0; kk < n; kk++) {
        e[kk] = a[kk] + b[kk];
    }
    printf("Mas a+b=\n");
    for (int pp = 0; pp < n; pp++) {
        printf("%d ", e[pp]);
    }
    double t4 = omp_get_wtime();
    printf("\nTime 3=%f\n", t4 - t3);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
