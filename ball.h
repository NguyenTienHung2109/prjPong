#include<iostream>
#include<SDL.h>

SDL_Rect l_paddle, r_paddle, ball, score_board;
bool turn;
float velX, velY;
SDL_Renderer* renderer;
void serve()
{
    l_paddle.y=r_paddle.y=(HEIGHT/2)-(l_paddle.h/2);
    if(turn)
    {
        ball.x=l_paddle.x+(l_paddle.w*4);
        velX=BALL_SPEED/2;
    }
    else
    {
        ball.x=r_paddle.x-(r_paddle.w*4);
        velX=-BALL_SPEED/2;
    }
    velY=0;
    ball.y=HEIGHT/2-(SIZE/2);
    turn=!turn;
}

void write(std::string text, int x, int y, TTF_Font *F,SDL_Color color)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    const char* t = text.c_str();
    surface = TTF_RenderText_Solid(F, t, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    score_board.w=surface->w;
    score_board.h=surface->h;
    score_board.x=x-score_board.w;
    score_board.y=y-score_board.h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &score_board);
    SDL_DestroyTexture(texture);
}
