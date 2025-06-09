#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define W 10
#define H 1
#define B (W - 2)

int main() {
    srand((unsigned)time(NULL));
    int a = 0; 
    int b = 2; 
    int c = H; 
    int d = H; 
    int e = 3; 
    int f = 0; 
    int g;     
    char n[20];
    int hasS = 0, hasT = 0, hasM = 0, hasL = 0; 
    int turn = 0;

    printf("야옹이 이름: ");
    scanf("%s", n);
    Sleep(1000);
    system("cls");

    while (1) {
        turn++;
        printf("==================== 현재 상태 =============\n");
        printf("현재까지 만든 수프: %d개\n", a);
        printf("CP: %d 포인트\n", f);
        printf("%s 기분(0~3): %d\n", n, e);

        char* mdesc[] = {
            "기분이 매우 나쁩니다.", "심심해합니다.",
            "식빵을 굽습니다.", "골골송을 부릅니다."
        };
        printf("%s\n", mdesc[e]);

        printf("집사와의 관계(0~4): %d\n", b);
        char* bdesc[] = {
            "곁에 오는 것조차 어합니다.", "간식 자판기 취급입니다.",
            "그럭저럭 쓸만한 집사입니다.", "훌륭한 집사로 인정 받고 있습니다.",
            "집사 껌딱지입니다."
        };
        printf("%s\n", bdesc[b]);
        printf("============================================\n");

        printf("###############\n#H");
        for (int i = 2; i < W - 1; i++) {
            if (hasT && i == 3) printf("T");
            else if (hasS && i == 6) printf("S");
            else printf(" ");
        }
        printf("B#\n#");
        for (int i = 0; i < W; i++) {
            if (i == c) printf("C");
            else if (i == d && d != c) printf(".");
            else printf(" ");
        }
        printf("#\n###############\n");

        printf("\n어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1. 긁어 주기\n");
        if (hasM) printf("2. 장난감 쥐로 놀아 주기\n");
        if (hasL) printf("3. 레이저 포인터로 놀아 주기\n");
        printf("> ");
        scanf("%d", &g);

        int r = rand() % 6 + 1;
        if (g == 0) {
            printf("아무것도 하지 않습니다.\n");
            if (e > 0) e--;
            if (r <= 5 && b > 0) {
                b--;
                printf("집사와의 관계가 나빠집니다.\n");
            }
        } else if (g == 1) {
            printf("%s의 턱을 긁어주었습니다.\n", n);
            if (r >= 5 && b < 4) b++;
        } else if (g == 2 && hasM) {
            printf("장난감 쥐로 %s와 놀아 주었습니다.\n", n);
            if (e < 3) e++;
            if (r >= 4 && b < 4) b++;
        } else if (g == 3 && hasL) {
            printf("레이저 포인터로 %s와 놀아 주었습니다.\n", n);
            if (e <= 1) e += 2;
            else if (e == 2) e++;
            if (r >= 2 && b < 4) b++;
        } else {
            printf("입력이 잘못되었습니다.\n");
        }

        r = rand() % 6 + 1;
        if (r <= 6 - b && e > 0) {
            e--;
            printf("기분이 나빠졌습니다. 고양이니까? -> %d\n", e);
        }

        d = c;
        if (e == 0) {
            c = H;
            printf("기분이 나쁜 %s은(는) 집으로 갑니다.\n", n);
        } else if (e == 1) {
            if (hasS) c = 6;
            else if (hasT) c = 3;
            else {
                e = 0;
                printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
            }
        } else if (e == 2) {
            printf("%s은(는) 식빵을 굽습니다.\n", n);
        } else if (e == 3) {
            c = B;
            printf("%s은(는) 수프를 만들러 갑니다.\n", n);
        }

        if (c == B) {
            char* s[] = {"감자 수프", "양송이 수프", "브로콜리 수프"};
            int k = rand() % 3;
            printf("%s이(가) %s를 만들었습니다!\n", n, s[k]);
            a++;
        } else if (c == H && d == H) {
            if (e < 3) e++;
            printf("%s은(는) 집에서 쉬고 있습니다.\n", n);
        } else if (c == 6 && hasS) {
            if (e < 3) e++;
            printf("스크래처로 놀며 기분이 좋아졌습니다.\n");
        } else if (c == 3 && hasT) {
            if (e <= 1) e += 2;
            else if (e == 2) e++;
            printf("캣타워에서 기분이 제법 좋아졌습니다.\n");
        }

        int gain = (e > 0 ? e - 1 : 0) + b;
        f += gain;
        printf("CP +%d, 보유 CP: %d\n", gain, f);

        Sleep(2500);
        system("cls");
    }

    return 0;
}
