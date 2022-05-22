#include<iostream>
#include<SDL.h>
Mix_Chunk *change_button,*choose,*losing, *winning, *pausing, *goal, *contact;
Mix_Music *bgm_menu, *bgm_game;
std::string score;
int l_s, r_s;
void update1()
{
    if(SDL_HasIntersection(&ball, &r_paddle))
    {
        double rel = (r_paddle.y+(r_paddle.h/2))-(ball.y+(SIZE/2));
        double norm = rel/(r_paddle.h/2);
        double bounce = norm * (5*PI/12);
        velX=-BALL_SPEED*cos(bounce);
        velY=BALL_SPEED*-sin(bounce);
        Mix_PlayChannel(-1, contact, 0);
    }
    if(SDL_HasIntersection(&ball, &l_paddle))
    {
        double rel = (l_paddle.y+(l_paddle.h/2))-(ball.y+(SIZE/2));
        double norm = rel/(l_paddle.h/2);
        double bounce = norm * (5*PI/12);
        velX=BALL_SPEED*cos(bounce);
        velY=BALL_SPEED*-sin(bounce);
        Mix_PlayChannel(-1, contact, 0);
    }
    if(ball.y > r_paddle.y+(r_paddle.h/2)) r_paddle.y+=SPEED;
    if(ball.y < r_paddle.y+(r_paddle.h/2)) r_paddle.y-=SPEED;
    if(ball.x<=0)
    {
        r_s++;
        serve();
        Mix_PlayChannel(-1, goal, 0);
    }
    if(ball.x+SIZE>=WIDTH)
    {
        l_s++;
        serve();
        Mix_PlayChannel(-1, goal, 0);
    }
    if(ball.y<=0 || ball.y+SIZE>=HEIGHT) velY=-velY;
    ball.x+=velX;
    ball.y+=velY;
    score=std::to_string(l_s) + "   " + std::to_string(r_s);
    if(l_paddle.y<0)l_paddle.y=0;
    if(l_paddle.y+l_paddle.h>HEIGHT)l_paddle.y=HEIGHT-l_paddle.h;
    if(r_paddle.y<0)r_paddle.y=0;
    if(r_paddle.y+r_paddle.h>HEIGHT)r_paddle.y=HEIGHT-r_paddle.h;
}

void update2()
{
    if(SDL_HasIntersection(&ball, &r_paddle))
    {
        double rel = (r_paddle.y+(r_paddle.h/2))-(ball.y+(SIZE/2));
        double norm = rel/(r_paddle.h/2);
        double bounce = norm * (5*PI/12);
        velX=-BALL_SPEED*cos(bounce);
        velY=BALL_SPEED*-sin(bounce);
        Mix_PlayChannel(-1, contact, 0);
    }
    if(SDL_HasIntersection(&ball, &l_paddle))
    {
        double rel = (l_paddle.y+(l_paddle.h/2))-(ball.y+(SIZE/2));
        double norm = rel/(l_paddle.h/2);
        double bounce = norm * (5*PI/12);
        velX=BALL_SPEED*cos(bounce);
        velY=BALL_SPEED*-sin(bounce);
        Mix_PlayChannel(-1, contact, 0);
    }
    if(ball.x<=0)
    {
        r_s++;
        serve();
        Mix_PlayChannel(-1, goal, 0);
    }
    if(ball.x+SIZE>=WIDTH)
    {
        l_s++;
        serve();
        Mix_PlayChannel(-1, goal, 0);
    }
    if(ball.y<=0 || ball.y+SIZE>=HEIGHT) velY=-velY;
    ball.x+=velX;
    ball.y+=velY;
    score=std::to_string(l_s) + "   " + std::to_string(r_s);
    if(l_paddle.y<0)l_paddle.y=0;
    if(l_paddle.y+l_paddle.h>HEIGHT)l_paddle.y=HEIGHT-l_paddle.h;
    if(r_paddle.y<0)r_paddle.y=0;
    if(r_paddle.y+r_paddle.h>HEIGHT)r_paddle.y=HEIGHT-r_paddle.h;
}
