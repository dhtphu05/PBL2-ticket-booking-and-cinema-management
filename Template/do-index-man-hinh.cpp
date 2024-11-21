#include <iostream>
#include <stdio.h>
#include <windows.h>

// Khai bÃ¡o cÃ¡c biáº¿n toÃ n cá»¥c
HANDLE hStdin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

// Ghi lá»—i vÃ  thoÃ¡t ra
VOID WriteError(LPSTR lpszMessage)
{
    printf("%s\n", lpszMessage);
    ExitProcess(0);
}

// HÃ m nÃ y cho phÃ©p di chuyá»ƒn con trá» ghi cá»§a std lÃªn báº¥t cá»© vá»‹ trÃ­ x,y nÃ o trÃªn console
void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

// hÃ m nÃ y Ä‘á»ƒ láº¥y vá»‹ trÃ­ chuá»™t trÃªn std
void GetMousePosWin(MOUSE_EVENT_RECORD mer)
{
    // Khai bÃ¡o cÃ¡c biáº¿n mÃ  hÃ m cáº§n
    int x, y;
    INPUT_RECORD Inrec;
    DWORD eventRead;
    HANDLE hStdIn;
    DWORD dwMode;
    bool Captured = false;
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    // Kiá»ƒm tra xem console Ä‘Ã£ á»Ÿ cháº¿ Ä‘á»™ cháº¥p nháº­n input tá»« chuá»™t chÆ°a
    if (SetConsoleMode(hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)

        GetConsoleMode(hStdIn, &dwMode);
    SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

    // vÃ²ng láº·p nÃ y sáº½ láº¥y cÃ¡c event cá»§a trong bá»™ nhá»› ra Ä‘á»ƒ xá»­ lÃ½
    do
    {
        PeekConsoleInput(hStdIn, &Inrec, 1, &eventRead);
        if (eventRead)
        {
            ReadConsoleInput(hStdIn, &Inrec, 1, &eventRead);
            x = Inrec.Event.MouseEvent.dwMousePosition.X;
            y = Inrec.Event.MouseEvent.dwMousePosition.Y;
            switch (Inrec.EventType)
            {

            case MOUSE_EVENT:
            {
                Captured = true;
                gotoXY(0, 0);
                std::cout << "x location  " << x << " ";
                gotoXY(0, 1);
                std::cout << "y location  " << y << " ";
                break;
            }
            }
        }

    } while (!Captured);
}
void menu_InputData();
void menu_main();
void INTRO();
int main()
{
    SetConsoleCP(CP_UTF8);
    //INTRO();
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    int counter = 0;

    // Get the standard input handle.

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)
        WriteError("GetStdHandle");

    // Má»Ÿ cá»­a sá»• á»Ÿ cháº¿ Ä‘á»™ má»Ÿ
    fdwMode = ENABLE_EXTENDED_FLAGS;
    if (!SetConsoleMode(hStdin, fdwMode))
    {
        WriteError("SetConsoleMode");
    }

    // Má»Ÿ cá»­a sá»• á»Ÿ cháº¿ Ä‘á»™ cháº¥p nháº­n input

    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode))
    {
        WriteError("SetConsoleMode");
    }

    // VÃ²ng láº·p Ä‘á»ƒ quÃ©t qua cÃ¡c event
    while (!counter)
    {
        // Ä‘á»c event vÃ o
        if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
        {
            WriteError("ReadConsoleInput");
        }
        // xá»­ lÃ½ tá»«ng event má»™t
        for (i = 0; i < cNumRead; i++)
        {
            switch (irInBuf[i].EventType)
            {
            case MOUSE_EVENT: // khi cÃ³ event cá»§a chuá»™t
                GetMousePosWin(irInBuf[i].Event.MouseEvent);
                break;
            // ngoÃ i ra cÃ²n cÃ³ event cá»§a bÃ n phÃ­m, cá»§a chuá»™t
            default:
                break;
            }
        }
    }

    return 0;
}
void menu_main()
{
    int x = 30, y = 0;
    gotoXY(x, y);
    printf("               â”Œ---------------â”            \n");
    gotoXY(x, y + 1);
    printf("               |      MENU     |            \n");
    gotoXY(x, y + 2);
    printf("               â””---------------â”˜            \n");
    gotoXY(x, y + 3);

    printf("â”Œ---------------------------------------------â”\n");
    gotoXY(x, y + 4);
    printf("|                                             |\n");
    gotoXY(x, y + 5);
    printf("|               â”Œ--------------â”              |\n");
    gotoXY(x, y + 6);
    printf("|       1       | Nháº­p dá»¯ liá»‡u |              |\n");
    gotoXY(x, y + 7);
    printf("|               â””--------------â”˜              |\n");
    gotoXY(x, y + 8);
    printf("|          â”Œ------------------------â”         |\n");
    gotoXY(x, y + 9);
    printf("|       2  | Giáº£i phÆ°Æ¡ng trÃ¬nh báº±ng |         |\n");
    gotoXY(x, y + 10);
    printf("|          | phÆ°Æ¡ng phÃ¡p dÃ¢y cung   |         |\n");
    gotoXY(x, y + 11);
    printf("|          â””------------------------â”˜         |\n");
    gotoXY(x, y + 12);
    printf("|          â”Œ------------------------â”         |\n");
    gotoXY(x, y + 13);
    printf("|       3  | Giáº£i phÆ°Æ¡ng trÃ¬nh báº±ng |         |\n");
    gotoXY(x, y + 14);
    printf("|          | phÆ°Æ¡ng phÃ¡p chia Ä‘Ã´i   |         |\n");
    gotoXY(x, y + 15);
    printf("|          â””------------------------â”˜         |\n");
    gotoXY(x, y + 16);
    printf("|               â”Œ--------------â”              |\n");
    gotoXY(x, y + 17);
    printf("|       4       | Xuáº¥t dá»¯ liá»‡u |              |\n");
    gotoXY(x, y + 18);
    printf("|               â””--------------â”˜              |\n");
    gotoXY(x, y + 19);
    printf("|                                             |\n");
    gotoXY(x, y + 20);
    printf("â””---------------------------------------------â”˜\n");
}
void menu_InputData()
{
    int x = 30, y = 0;
    char message[] = "Má»i báº¡n chá»n phÆ°Æ¡ng thá»©c nháº­p dá»¯ liá»‡u.....";
    gotoXY(x, y);
    // loading_message(message);
    gotoXY(x, y + 3);
    printf("â”Œ------------------------------------------------â”\n");
    gotoXY(x, y + 4);
    printf("|                                                |\n");
    gotoXY(x, y + 5);
    printf("|               â”Œ-----------------â”              |\n");
    gotoXY(x, y + 6);
    printf("|         1     | Nháº­p dá»¯ liá»‡u tá»« |              |\n");
    gotoXY(x, y + 7);
    printf("|               |    bÃ n phÃ­m     |              |\n");
    gotoXY(x, y + 8);
    printf("|               â””-----------------â”˜              |\n");
    gotoXY(x, y + 9);
    printf("|               â”Œ-----------------â”              |\n");
    gotoXY(x, y + 10);
    printf("|         2     | Nháº­p dá»¯ liá»‡u tá»« |              |\n");
    gotoXY(x, y + 11);
    printf("|               |       file      |              |\n");
    gotoXY(x, y + 12);
    printf("|               â””-----------------â”˜              |\n");
    gotoXY(x, y + 13);
    printf("|               â”Œ-----------------â”              |\n");
    gotoXY(x, y + 14);
    printf("|         3     | Nháº­p dá»¯ liá»‡u tá»« |              |\n");
    gotoXY(x, y + 15);
    printf("|               |      random     |              |\n");
    gotoXY(x, y + 16);
    printf("|               â””-----------------â”˜              |\n");
    gotoXY(x, y + 17);
    printf("|                                                |\n");
    gotoXY(x, y + 18);
    printf("â””------------------------------------------------â”˜\n");
}
void INTRO()
{
    int x = 15, y = 6;
    gotoXY(x, 2);
    printf("â•”â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•—\n");
    gotoXY(x, 3);
    printf("â•‘                                  â•”â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•—                                     â•‘\n");
    gotoXY(x, 4);
    printf("â•‘                                  â•‘    NHÃ“M 8    â•‘                                     â•‘");
    gotoXY(x, 5);
    printf("â•‘                                  â•šâ•â•â•â•â•â•â•â•â•â•â•â•â•â•â•                                     â•‘");
    gotoXY(x, y);
    printf("â•‘          Äá» tÃ i: TÃ¬m nghiá»‡m cá»§a phÆ°Æ¡ng trÃ¬nh Ä‘a thá»©c báº­c n báº±ng phÆ°Æ¡ng                â•‘\n");
    gotoXY(x, y + 1);
    printf("â•‘                                                                                       â•‘\n");
    gotoXY(x, y + 2);
    printf("â•‘           phÃ¡p chia Ä‘Ã´i vÃ  phÆ°Æ¡ng phÃ¡p dÃ¢y cung                                       â•‘\n");
    gotoXY(x, y + 3);
    printf("â•‘---------------------------------------------------------------------------------------â•‘\n");
    gotoXY(x, y + 4);
    printf("â•‘            â•”-------------â•—         |             â•”-----------------â•—                  â•‘\n");
    gotoXY(x, y + 5);
    printf("â•‘            â•‘   MÃ´ táº£     â•‘         |             â•‘ NgÆ°á»i thá»±c hiá»‡n â•‘                  â•‘\n");
    gotoXY(x, y + 6);
    printf("â•‘            â•š-------------â•         |             â•š-----------------â•                  â•‘\n");
    gotoXY(x, y + 7);
    printf("â•‘------------------------------------|--------------------------------------------------â•‘\n");
    gotoXY(x, y + 8);
    printf("â•‘  - Äá»c Ä‘a thá»©c tá»« bÃ n phÃ­m         |     1.       ÄOÃ€N HOÃ€NG THIÃŠN PHÃš                â•‘\n");
    gotoXY(x, y + 9);
    printf("â•‘    hoáº·c tá»« file                    |                                                  â•‘\n");
    gotoXY(x, y + 10);
    printf("â•‘  - Nháº­p khoáº£ng nghiá»‡m Ä‘á»ƒ tÃ¬m nghiá»‡m|     Lá»›p: 23T_DT3            MSSV: 102230313      â•‘\n");
    gotoXY(x, y + 11);
    printf("â•‘  - Chá»n phÆ°Æ¡ng phÃ¡p Ä‘á»ƒ tÃ¬m         |--------------------------------------------------â•‘\n");
    gotoXY(x, y + 12);
    printf("â•‘  - Xuáº¥t káº¿t quáº£ ra mÃ n hÃ¬nh        |     2.       NGUYá»„N THá»Š THÃ™Y                     â•‘\n");
    gotoXY(x, y + 13);
    printf("â•‘    vÃ  file                         |                                                  â•‘\n");
    gotoXY(x, y + 14);
    printf("â•‘                                    |     Lá»›p: 23T_DT3            MSSV: 102230323      â•‘\n");
    gotoXY(x, y + 15);
    printf("â•‘                                    |                                                  â•‘\n");
    gotoXY(x, y + 16);
    printf("â•šâ•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•\n");
    gotoXY(x, y + 17);
    printf("                                                                  â•”----------------â•—      \n");
    gotoXY(x, y + 18);
    printf("                                                                  â•‘   Tiáº¿p tá»¥c...  â•‘      \n");
    gotoXY(x, y + 19);
    printf("                                                                  â•š----------------â•      \n");
}

int checkC(double x[], double y[],int n, double c)
{
    for (int i = 0; i < n; i++)
    {
        if (c == x[i])
        {
            printf("f(%lf) = %lf\n", c, y[i]);
            return 1;
        }
    }
    return 0;
}



void NoiSuyAnken(double x[],double y[],double anken[][100],int n,double c){
    double w=1,s=0;
    double d;

    for (int i = 0; i < n; i++)
    {
        if (c == x[i])
        {
            printf("f(%lf) = %lf\n", c, y[i]);
            return;
        }
    }

    for(int i=0;i<n;i++){
        w*=(c-x[i]);
        
        d=c-x[i];
        for(int j=0;j<n;j++){
            anken[i][j]=x[j]-x[i];
            if(j!=i){
                d*=(x[i]-x[j]);
                anken[i][j]=c-x[i];
            }
        }
        anken[i][n]=d;
        s+=y[i]/d;
    }
    printf("f(%lf)= %lf\n",c,w*s);
    

}