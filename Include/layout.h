#include "gotoXY.h"
#include <windows.h>
#include <iostream>
using namespace std;
#ifndef LAYOUT_H
#define LAYOUT_H


void lineWidth(int n, int x, int y, bool hasRadius, bool isTop)
{
    gotoXY(x, y);
    if (isTop)
    {
        if (hasRadius)
        {
            cout << "╭";
        }
        for (int i = 0; i < n; i++)
        {
            cout << "─";
        }
        if (hasRadius)
        {
            cout << "╮";
        }
    }
    else
    {
        if (hasRadius)
        {
            cout << "╰";
        }
        for (int i = 0; i < n; i++)
        {
            cout << "─";
        }
        if (hasRadius)
        {
            cout << "╯";
        }
    }
}
void lineHeight(int n, int x, int y, bool is3_l, bool is3_r, bool is4)
{
    if (is3_l)
    {
        for (int i = 0; i < n; i++)
        {
            gotoXY(x, y + i);
            cout << "├";
            y++;
        }
    }
    else if (is3_r)
    {
        for (int i = 0; i < n; i++)
        {
            gotoXY(x, y + i);
            cout << "┤";
            y++;
        }
    }
    else if (is4)
    {
        for (int i = 0; i < n; i++)
        {
            gotoXY(x, y + i);
            cout << "┼";
            y++;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            gotoXY(x, y + i);
            cout << "│" << endl;
            y++;
        }
    }
}
void lineHeight_main(int n, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        gotoXY(x, y + i);
        cout << "│" << endl;
    }
}
void showString(const string &str, int x, int y)
{
    gotoXY(x, y);
    cout << str;
}
#endif