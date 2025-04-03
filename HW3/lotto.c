#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int is_winning_line(const char *line, int win1, int win2, int win3) {
    int num;
    const char *ptr = line;
    

    while(*ptr && *ptr != ':') ptr++;
    if(*ptr == ':') ptr++;
    
  
    while(*ptr) {
        if(sscanf(ptr, "%d", &num) == 1) {
            if(num == win1 || num == win2 || num == win3) {
                return 1;
            }
           
            while(*ptr && *ptr != ' ') ptr++;
            while(*ptr == ' ') ptr++;
        } else {
            break;
        }
    }
    return 0;
}

int main()
{
    
    int n;
    scanf("%d",&n);
    int num[5][7];
    int temp=0;
    srand(1);
    
    for(int i=0; i<n; i++)
    {
        int use[70]={0};
        for(int j=0; j<7; )
        {
            temp=rand()%69+1;
            if(use[temp]==0)
            {
                num[i][j]=temp;
                use[temp]=1;
                j++;
            }
        }
    }
    
    FILE* fp = fopen("lotto.txt", "w+");
    int c=0;
    fprintf(fp, "========= lotto649 =========\n");
    for(int a=0; a<5; a++)
    {
        fprintf(fp, "[%d]:",a+1);
        for(int b=0; b<7; b++)
        {
            if(c>=n)
            {
                fprintf(fp, " __");
            } 
            else
            {
                fprintf(fp, " %02d", num[a][b]);
            }
        }
        c++;
        fprintf(fp, "\n");
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

   
    int win1, win2, win3;
    printf("請輸入三個要檢查的中獎號碼（用空格分隔）：");
    scanf("%d %d %d", &win1, &win2, &win3);
    
    FILE *infile = fopen("lotto.txt", "r");
    FILE *outfile = fopen("win.txt", "w");

    if (!infile || !outfile) {
        perror("檔案開啟失敗");
        return 1;
    }

    char line[256];
    int winning_count = 0;
    
    fprintf(outfile, "中獎號碼：%02d %02d %02d\n", win1, win2, win3);
    fprintf(outfile, "========= 中獎清單 =========\n");
    
    while(fgets(line, sizeof(line), infile)) {
        if(line[0] == '[') {
            if(is_winning_line(line, win1, win2, win3)) {
                fputs(line, outfile);
                winning_count++;
            }
        }
    }
    
    if(winning_count == 0) {
        fprintf(outfile, "無中獎組數\n");
    } else {
        fprintf(outfile, "========= 共 %d 組中獎 =========\n", winning_count);
    }

    fclose(infile);
    fclose(outfile);
    
    printf("兌獎結果已寫入 win.txt\n");
    return 0;

    }
