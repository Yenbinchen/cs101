int main()
{
    for (int i = 1; i <= 81; i++){  
        int x = (i - 1) % 9 + 1;   
        int y = (i - 1) / 9 + 1;   
        printf("%d*%d=%d\t", y, x, x * y);
        if (x == 9)                
            printf("\n");
    }
    return 0;
}
