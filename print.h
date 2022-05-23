#include<iostream>
#include<SDL.h>
SDL_Color red;
SDL_Color yellow;

int frameCount, timerFPS, lastFrame, fps;
SDL_Window* window;
TTF_Font* font, *font_2, *font_3, *font_4, *font_5;
SDL_Color white;
void render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    frameCount++;
    timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60))
    {
        SDL_Delay((1000/60)-timerFPS);
    }


    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, 255);
    SDL_RenderDrawLine(renderer, WIDTH / 2, 0, WIDTH / 2, HEIGHT);
    SDL_RenderFillRect(renderer, &l_paddle);
    SDL_RenderFillRect(renderer, &r_paddle);
    SDL_RenderFillRect(renderer, &ball);
    if(l_s == win -1)
    {
        SDL_SetRenderDrawColor(renderer, yellow.r, yellow.g, yellow.b, 255);
        SDL_RenderFillRect(renderer, &r_paddle);
        SDL_SetRenderDrawColor(renderer, red.r, red.g, red.b, 255);
        SDL_RenderFillRect(renderer, &ball);
    }
    if(r_s == win -1)
    {
        SDL_SetRenderDrawColor(renderer, yellow.r, yellow.g, yellow.b, 255);
        SDL_RenderFillRect(renderer, &l_paddle);
        SDL_SetRenderDrawColor(renderer, red.r, red.g, red.b, 255);
        SDL_RenderFillRect(renderer, &ball);
    }
    write(score, WIDTH/2+FONT_SIZE, FONT_SIZE*2,font,white);
    if(pause == false)
    {
        if(victory == false)
        {
            write("PAUSE", WIDTH/2+FONT_SIZE+110, FONT_SIZE*7,font_2,yellow);
            if(pointer_pause == 1)
            {
                write("CONTINUE",WIDTH/2+FONT_SIZE+35, FONT_SIZE*9,font,red);
            }
            else
            {
                write("CONTINUE",WIDTH/2+FONT_SIZE+35, FONT_SIZE*9,font,white);
            }
            if(pointer_pause == 2)
            {
                write("MENU",WIDTH/2+FONT_SIZE + 5, FONT_SIZE*11,font,red);
            }
            else
            {
                write("MENU",WIDTH/2+FONT_SIZE + 5, FONT_SIZE*11,font,white);
            }

        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            if(l_s == win)
                write("PLAYER 1 WON!", WIDTH/2+FONT_SIZE+180, FONT_SIZE*7,font_3,yellow);
            else
                write("PLAYER 2 WON!", WIDTH/2+FONT_SIZE+180, FONT_SIZE*7,font_3,yellow);
            if(pointer_win == 1)
                write("REMATCH",WIDTH/2+FONT_SIZE+65, FONT_SIZE*10,font_5,red);
            else
                write("REMATCH",WIDTH/2+FONT_SIZE+65, FONT_SIZE*10,font_5,white);
            if(pointer_win == 2)
                write("MENU",WIDTH/2+FONT_SIZE+25, FONT_SIZE*12,font_5,red);
            else
                write("MENU",WIDTH/2+FONT_SIZE+25, FONT_SIZE*12,font_5,white);
            SDL_Event e;

        }
    }
    SDL_RenderPresent(renderer);
}

void Menu()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    frameCount++;
    timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60))
    {
        SDL_Delay((1000/60)-timerFPS);
    }

    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, 255);

    write("PONG", WIDTH/2+FONT_SIZE + 200, FONT_SIZE*8,font_4,yellow);
    if(pointer == 1)
        write("1 PLAYER", WIDTH/2+FONT_SIZE + 70, FONT_SIZE*10,font_5,red);
    else
        write("1 PLAYER", WIDTH/2+FONT_SIZE + 70, FONT_SIZE*10,font_5,white);
    if(pointer == 2)
    {
        write("2 PLAYER", WIDTH/2+FONT_SIZE + 75, FONT_SIZE*12,font_5,red);
    }
    else
        write("2 PLAYER", WIDTH/2+FONT_SIZE + 75, FONT_SIZE*12,font_5,white);
    if(pointer == 3)
        write("EXIT", WIDTH/2+FONT_SIZE + 23, FONT_SIZE*14,font_5,red);
    else
        write("EXIT", WIDTH/2+FONT_SIZE + 23, FONT_SIZE*14,font_5,white);
    SDL_RenderPresent(renderer);
}
