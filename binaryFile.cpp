#include <stdio.h>

void ghiFile(){
    FILE* fp;
    // Đây là cách ghi trên máy Win
    // fopen_s(&fp, "c:\\Document\\nhapMonLT\\binaryFile.bin", "wb");

    fp = fopen("binaryFile.bin", "wb");

    if (fp != NULL) {
        int n = 3;
        fwrite(&n, sizeof(int), 1, fp);

        int a[3] = {1, 2, 3};
        fwrite(a, sizeof(int), 3, fp);

        fclose(fp);
    } else {
        printf("Khong mo duoc file!\n");
    }
}

void docFile(){
    FILE* fp;

    fp = fopen("binaryFile.bin", "rb");

    if(fp != NULL){
        int n;
        fread(&n, sizeof(int), 1, fp);
        printf("\nSố n = %d: ", n);

        int a[3];
        fseek(fp, -4, SEEK_CUR);
        fread(a, sizeof(int), 3, fp);
        printf("\nMảng a là: ");
        for(int i = 0; i < 3; i++){
            printf("%5d",a[i]);
        }

        fclose(fp);
    } else{
        printf("Khong mơ duoc file!");
    }
}

int main() {
    docFile();
    return 0;
}
