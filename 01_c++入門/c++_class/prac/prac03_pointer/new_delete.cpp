#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    int *p1 = (int *)malloc(sizeof(int));
    // (型名*)malloc(確保する領域のサイズ)

    int *p2 = (int *)malloc(sizeof(int) * 5); 
    // int[5] の領域を確保する場合

    free(p1); // メモリの解放
    free(p2); // メモリの解放
    
    return 0;
}