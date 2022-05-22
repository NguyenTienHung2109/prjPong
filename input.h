#include<iostream>
#include<SDL.h>
#include<SDL_mixer.h>
bool running,pause =true, play = true;
bool menu = true;
bool victory = false;
int pointer =1,pointer_pause = 1,pointer_win =1,demMenu = 0, demRunning = 0;
int win = 5,dem =0;
void inputMenu()
{
    running = true;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            menu = false;
            running = false;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                if (pointer > 1)pointer--;
                Mix_PlayChannel(-1, change_button, 0);
                break;
            case SDLK_DOWN:
                if (pointer < 3)pointer++;
                Mix_PlayChannel(-1, change_button, 0);
                break;
            case SDLK_w:
                if (pointer > 1)pointer--;
                Mix_PlayChannel(-1, change_button, 0);
                break;
            case SDLK_s:
                if (pointer < 3)pointer++;
                Mix_PlayChannel(-1, change_button, 0);
                break;
            case SDLK_SPACE:
                menu = false;
                pause = true;
                Mix_PlayChannel(-1, choose, 0);
                victory == false;
                demMenu = 0;
                if(pointer == 3)
                {
                    play == false;
                    running = false;
                }
                break;
            default:
                break;
            }
        }
    }
}
void input1()
{
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT) running=false;
    }
    /*if(keystates[SDL_SCANCODE_Q])
    {
        running=false;
        menu = false;
    }*/

    if(pause == true)
    {
        if(keystates[SDL_SCANCODE_W]) l_paddle.y-=SPEED;
        if(keystates[SDL_SCANCODE_S]) l_paddle.y+=SPEED;
    }

    if(keystates[SDL_SCANCODE_P])
    {
        pause = false;
        Mix_PlayChannel(-1, pausing, 0);
        demRunning =0;
    }
}

void input2()
{
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT) running=false;
    }

    if(pause == true)
    {
        if(keystates[SDL_SCANCODE_W]) l_paddle.y-=SPEED;
        if(keystates[SDL_SCANCODE_S]) l_paddle.y+=SPEED;
        if(keystates[SDL_SCANCODE_UP])r_paddle.y-=SPEED;
        if(keystates[SDL_SCANCODE_DOWN])r_paddle.y+=SPEED;
    }

    if(keystates[SDL_SCANCODE_P])
    {
        pause = false;
        victory = false;
        Mix_PlayChannel(-1, pausing, 0);
        demRunning =0;
    }
}

void Pause()
{
    if(pause == false && victory == false)
    {
        Mix_HaltMusic();
        SDL_Event P;
        while (SDL_PollEvent(&P))
        {
            switch (P.type)
            {
            case SDL_QUIT:
                menu = false;
                running = false;
            case SDL_KEYDOWN:
                switch (P.key.keysym.sym)
                {
                case SDLK_UP:
                    if (pointer_pause > 1)pointer_pause--;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_DOWN:
                    if (pointer_pause < 2)pointer_pause++;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_w:
                    if (pointer_pause > 1)pointer_pause--;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_s:
                    if (pointer_pause < 2)pointer_pause++;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_SPACE:
                    Mix_PlayChannel(-1, choose, 0);
                    if(pointer_pause == 2)
                    {
                        menu = true;
                        running = false;
                        serve();
                        l_s =0;
                        r_s =0;
                        demRunning = 0;
                        demMenu =0;
                    }
                    else
                        Mix_ResumeMusic();
                    pause = true;
                    pointer_pause =1;
                    demRunning = 0;
                    break;
                default:
                    break;
                }
            }
        }
    }
}
void Win()
{
    if(victory == true && pause == false)
    {
        Mix_HaltMusic();
        demRunning = 0;
        if(dem == 0)
        {
            if(l_s == win && pointer == 1)
                Mix_PlayChannel(-1, winning, 0);
            else if(r_s == win && pointer == 1)
                Mix_PlayChannel(-1, losing, 0);
            else if(pointer == 2)
                Mix_PlayChannel(-1, winning, 0);
            dem++;
        }
        SDL_Event P;
        while (SDL_PollEvent(&P))
        {
            switch (P.type)
            {
            case SDL_QUIT:
                menu = false;
                running = false;
            case SDL_KEYDOWN:
                switch (P.key.keysym.sym)
                {
                case SDLK_UP:
                    if (pointer_win > 1)pointer_win--;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_DOWN:
                    if (pointer_win < 2)pointer_win++;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_w:
                    if (pointer_win > 1)pointer_win--;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_s:
                    if (pointer_win < 2)pointer_win++;
                    Mix_PlayChannel(-1, change_button, 0);
                    break;
                case SDLK_SPACE:
                    Mix_PlayChannel(-1, choose, 0);
                    dem =0;
                    if(pointer_win == 2)
                    {
                        menu = true;
                        running = false;
                        l_s = 0;
                        r_s = 0;
                    }
                    else
                    {
                        serve();
                        l_s = 0;
                        r_s = 0;
                        running = true;
                        menu = false;
                    }
                    victory = false;
                    pause = true;
                    pointer_win =1;
                    demMenu = 0;
                    break;
                default:
                    break;
                }
            }
        }
    }
}
