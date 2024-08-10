#include <iostream>

int main() 
{
    int a, b;
    printf("Nhập vào hệ số a và b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    if (a == 0)
    {
        if (b == 0)
        {
            printf("Phương trình có vô số nghiệm\n");
        }
        else
        {
            printf("Phương trình vô nghiệm\n");
        }
    }
    else
    {
        double x = -1.0 * b / a;
        printf("Vậy phương trình %dx + %d = 0 có nghiệm x = %0.2f\n", a, b, x);
    }

    return 0; // Trả về 0 để biểu thị chương trình kết thúc thành công
}
