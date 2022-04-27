#include <stdio.h>
#define ERROR_FILE_OPEN -3


int enteredNumber();
int sumOfNumbers();
int productOfDigits();

#include <stdlib.h>
int main() {
   FILE *output=NULL;
   int number;

   output= fopen("output.bin","wb");
   if(output==NULL){
       printf("Error");
       exit(ERROR_FILE_OPEN);
   }
    scanf("%d",&number);
    fwrite(&number,sizeof (int),1,output);
    fclose(output);

    printf("calculation result: %d",sumOfNumbers()-productOfDigits());

}

    int enteredNumber() {
    FILE *input = NULL;
    int number;
    input = fopen("output.bin", "rb");

    fread(&number, sizeof(int), 1, input);
    fclose(input);
    return number;
}

    int sumOfNumbers(){
    int number=enteredNumber();
    int sum=0;
    while (number!=0){
        sum+=number%100;
        number/=100;
    }
    return sum;
}

    int productOfDigits(){
    int number=enteredNumber();
    int multiplication=1;
    while (number!=0){
       multiplication*=number%10;
        number/=10;
    }
    return multiplication;
}



