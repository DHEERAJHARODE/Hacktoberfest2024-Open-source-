// Bresenham's Algorithm

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void draw_line(int x1, int y1, int x2, int y2, int dx, int dy, int decide) {
    int pk = 2 * dy - dx;
    for (int i = 0; i <= dx; i++) {
        printf("%d> (%d, %d)\n", i + 1, x1, y1);
        x1 < x2 ? x1++ : x1--;
        if (pk < 0) {
            if (decide == 0) {
                putpixel(x1, y1, WHITE);
                pk = pk + 2 * dy;
            } else {
                putpixel(y1, x1, WHITE);
                pk = pk + 2 * dy;
            }
        } else {
            y1 < y2 ? y1++ : y1--;
            if (decide == 0) {
                putpixel(x1, y1, WHITE);
            } else {
                putpixel(y1, x1, WHITE);
            }
            pk = pk + 2 * dy - 2 * dx;
        }
        delay(20);
    }
}

int main() {
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";  // static file
    initgraph(&gd, &gm, data);

    int x1, y1, x2, y2;
    printf("Enter coordinates of the first point: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter coordinates of the second point: ");
    scanf("%d%d", &x2, &y2);
    printf("Coordinates of the drawn points are:\n");
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (dx > dy) {
        draw_line(x1, y1, x2, y2, dx, dy, 0);
    } else {
        draw_line(y1, x1, y2, x2, dy, dx, 1);
 
    }

    getch();
    closegraph();
    return 0;
}

