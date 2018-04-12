#ifndef _DEBUGSERIAL_H_
#define _DEBUGSERIAL_H_

enum color
{
    color_black,
    color_red,
    color_green,
    color_yellow,
    color_blue,
    color_magenta,
    color_cyan,
    color_white,
    color_gray,
    color_default
};

enum cursorDir
{
    cursor_up,
    cursor_down,
    cursor_right,
    cursor_left
};

class DebugSerial : public Serial
{
public:
    DebugSerial(PinName tx, PinName rx) : Serial(tx, rx) {}
    DebugSerial(PinName tx, PinName rx, int baud) : Serial(tx, rx, baud) {}
    
    // cursor
    void clear() { printf("\033[2J"); }
    void setPos(int x, int y) { printf("\033[%d;%dH", x, y); }
    void clearToLineEnd() { printf("\033[K"); }
    void moveCursor(cursorDir dir, int distance)
    {
        for(int i = 0; i< distance; i++)
        {
            switch(dir)
            {
                case cursor_up:     printf("\033[1A"); break;
                case cursor_down:   printf("\033[1B"); break;
                case cursor_right:  printf("\033[1C"); break;
                case cursor_left:   printf("\033[1D"); break;
            }
        }
    }
    
    // letter attribute
    void letterDefault() { printf("\033[0m"); }
    void letterBrightBold()    { printf("\033[1m"); }
    void letterline()    { printf("\033[4m"); }
    void letterFlip()    { printf("\033[7m"); }
    
    // color
    void setLetterColor(color c) 
    {
        switch(c)
        {
            case color_black:   printf("\033[30m"); break;
            case color_red:     printf("\033[31m"); break;
            case color_green:   printf("\033[32m"); break;
            case color_yellow:  printf("\033[33m"); break;
            case color_blue:    printf("\033[34m"); break;
            case color_magenta: printf("\033[35m"); break;
            case color_cyan:    printf("\033[36m"); break;
            case color_white:   printf("\033[37m"); break;
            case color_default: printf("\033[39m"); break;
        }
    }
    
    void setBackColor(color c) 
    {
        switch(c)
        {
            case color_black:   printf("\033[40m"); break;
            case color_red:     printf("\033[41m"); break;
            case color_green:   printf("\033[42m"); break;
            case color_yellow:  printf("\033[43m"); break;
            case color_blue:    printf("\033[44m"); break;
            case color_magenta: printf("\033[45m"); break;
            case color_cyan:    printf("\033[46m"); break;
            case color_gray:    printf("\033[47m"); break;
            case color_default: printf("\033[49m"); break;
        }
    }
    
    void cls()
    {
        clear();
        setPos(0, 0);
    }

private:

};

#endif //_DEBUGSERIAL_H_
