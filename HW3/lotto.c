#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_winning_line(const char *line, const char *winning[], int win_count) {
    for (int i = 0; i < win_count; i++) {
        if (strstr(line, winning[i]) != NULL) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    FILE *infile = fopen("lotto.txt", "r");
    FILE *outfile = fopen("win.txt", "w");

    if (!infile || !outfile) {
        perror("檔案開啟失敗");
        return 1;
    }

    
    const char *winning_numbers[] = { " 02", " 04", " 06" };
    int win_count = sizeof(winning_numbers) / sizeof(winning_numbers[0]);

    char line[256];
    while (fgets(line, sizeof(line), infile)) {
        
        if (line[0] == '[') {
            if (is_winning_line(line, winning_numbers, win_count)) {
                fputs(line, outfile); 
            }
        }
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}
