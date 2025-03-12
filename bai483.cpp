// Bài 483: Hãy khai báo kiểu dữ liệu biểu diễn khái niệm đường tròn trong mặt phẳng Oxy
// và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này

#include <stdio.h>

// Khai báo kiểu dữ liệu đường tròn với tọa độ tâm (x0, y0) và bán kính R
struct duongTron {
    float x0, y0, R;
};

typedef struct duongTron dt; // Định nghĩa kiểu mới `dt` để dễ sử dụng

// Hàm nhập dữ liệu cho đường tròn
void nhap(dt *a) {
    printf("Nhập lần lượt x0, y0 và R cách nhau bởi khoảng trắng: ");
    scanf("%f %f %f", &a->x0, &a->y0, &a->R);

    // Kiểm tra nếu bán kính không hợp lệ (<= 0) thì yêu cầu nhập lại
    while (a->R <= 0) {
        printf("Bán kính phải lớn hơn 0. Nhập lại R: ");
        scanf("%f", &a->R);
    }
}

// Hàm xuất phương trình đường tròn ra màn hình
void xuat(dt a) {
    // In phần (x - x0)^2
    if (a.x0 == 0) 
        printf("x^2 ");  // Nếu x0 = 0 thì chỉ in x^2
    else if (a.x0 > 0) 
        printf("(x - %.2f)^2 ", a.x0);
    else 
        printf("(x + %.2f)^2 ", -a.x0); // Nếu x0 âm thì đổi dấu khi in

    // In phần (y - y0)^2
    if (a.y0 == 0) 
        printf("+ y^2 ");  // Nếu y0 = 0 thì chỉ in y^2
    else if (a.y0 > 0) 
        printf("+ (y - %.2f)^2 ", a.y0);
    else 
        printf("+ (y + %.2f)^2 ", -a.y0); // Nếu y0 âm thì đổi dấu khi in
    
    // In phần bán kính bình phương
    printf("= %.2f", a.R * a.R);
}

int main() {
    dt a;  // Khai báo một đường tròn
    nhap(&a); // Nhập dữ liệu cho đường tròn
    xuat(a);  // Xuất phương trình đường tròn

    return 0;
}
