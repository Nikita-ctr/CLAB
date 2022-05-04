#include <stdio.h>
#include <stdlib.h>
#define ERROR_FILE_OPEN -3

//Выполнить слияние двух рассортированных бинарных файлов в третий
//упорядоченный файл. Сортировок не использовать. Дополнительных массивов и файлов не использовать



int merge();

int main() {
    FILE *file1,*file2=NULL;
    int number1;
    int number2;

    file1= fopen("output1.bin","wb");
    file2= fopen("output2.bin","wb");
    if(file1==NULL || file2==NULL){
        printf("Error");
        exit(ERROR_FILE_OPEN);
    }
    scanf("%d",&number1);
    fwrite(&number1,sizeof (int),1,file1);
    scanf("%d",&number1);
    fwrite(&number2,sizeof (int),1,file2);

    fclose(file1);
    fclose(file2);


    merge();
    }
  int merge(){
        FILE *input = NULL;
        int number;

        input = fopen("output1.bin", "rb");
        if (input == NULL) {
            printf("Error opening file");
            getchar();
            exit(ERROR_FILE_OPEN);
        }

        fread(&number, sizeof(int), 1, input);
        printf("%d", number);

        fclose(input);
        getchar();


}


