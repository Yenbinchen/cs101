#include <stdio.h>
void replace_all(char* str, char oldChar, char newChar){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==oldChar){
            str[i]=newChar;
        }
    }
    
}

int main(){
    char str[100], oldChar = 'a', newChar = 'A';
    scanf("%s", str);

    replace_all(str, oldChar, newChar);
    printf("%s", str);

    return 0;
}
