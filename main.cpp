#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <math.h>
#include <SDL_mixer.h>
#define WIDTH 800
#define HEIGHT 600
#define FONT_SIZE 32
#define BALL_SPEED 16
#define SPEED 9
#define SIZE 16
#define PI 3.14159265358979323846
#include "ball.h"
#include "keyboard.h"
#include "input.h"
#include "print.h"
int main(int argc, char* args[])
{
    red.r = 222;
    red.g = 20;
    red.b = 20;
    red.a = 255;
    yellow.r = 255;
    yellow.g = 255;
    yellow.b = 0;
    yellow.a = 255;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
    SDL_Init(SDL_INIT_AUDIO);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Error" << Mix_GetError() << std::endl;
    }
    change_button = Mix_LoadWAV("assets/change button.wav");
    choose = Mix_LoadWAV("assets/choose.wav");
    losing = Mix_LoadWAV("assets/losing.wav");
    winning = Mix_LoadWAV("assets/winning.wav");
    pausing = Mix_LoadWAV("assets/pause.wav");
    goal = Mix_LoadWAV("assets/goal.wav");
    contact = Mix_LoadWAV("assets/contact.wav");
    bgm_menu = Mix_LoadMUS("assets/menuMusic.mp3");
    bgm_game = Mix_LoadMUS("assets/gameMusic.mp3");
    if(bgm_game == NULL || bgm_menu == NULL)
        std::cout << "ERROR OPEN MP3";
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer())" << std::endl;
    TTF_Init();
    font = TTF_OpenFont("assets/Peepo.ttf", FONT_SIZE);
    font_2 = TTF_OpenFont("assets/Peepo.ttf", FONT_SIZE*3);
    font_3 = TTF_OpenFont("assets/Peepo.ttf", FONT_SIZE*2);
    font_5 = TTF_OpenFont("assets/Peepo.ttf", FONT_SIZE*2 - 20);
    font_4 = TTF_OpenFont("assets/Peepo.ttf", FONT_SIZE*6);
    running=1;
    static int lastTime = 0;
    white.r=white.g=white.b=255;
    l_s=r_s=0;
    l_paddle.x=32;
    l_paddle.h=HEIGHT/4;
    l_paddle.y=(HEIGHT/2)-(l_paddle.h/2);
    l_paddle.w=20;
    r_paddle=l_paddle;
    r_paddle.x=WIDTH-r_paddle.w-32;
    ball.w=ball.h=SIZE;

    serve();
    while(play)
    {
        if(menu == false && running == false)
            play = false;
        while(menu)
        {
            inputMenu();
            Menu();
            if(demMenu == 0)
            {
                if(!Mix_PlayMusic(bgm_menu,-1))
                demMenu++;
            }
        }
        Mix_HaltMusic();
        while(running)
        {
            if(demRunning ==0)
            {
                Mix_PlayMusic(bgm_game,-1);
                demRunning++;
            }
            if(l_s == win -1)
            {
                r_paddle.h = HEIGHT/3;
            }
            else
                r_paddle.h = HEIGHT/4;
            if(r_s == win-1)
            {
                l_paddle.h = HEIGHT/3;
            }
            else
                l_paddle.h = HEIGHT/4;
            lastFrame=SDL_GetTicks();
            if(lastFrame>=(lastTime+1000))
            {
                lastTime=lastFrame;
                fps=frameCount;
                frameCount=0;
            }
            if(std::max(l_s,r_s) == win)
            {
                pause = false;
                victory = true;
            }
            if(pointer == 1)
            {
                Pause();
                Win();
                if(pause == true)
                {
                    input1();
                    update1();
                }
            }
            if(pointer == 2)
            {
                Pause();
                Win();
                if(pause == true)
                {
                    input2();
                    update2();
                }
            }
            render();
        }
    }
    bgm_game = nullptr;
    bgm_menu = nullptr;
    winning = nullptr;
    losing = nullptr;
    pausing = nullptr;
    choose = nullptr;
    change_button = nullptr;
    goal = nullptr;
    contact = nullptr;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}
