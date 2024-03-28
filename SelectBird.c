#include "header.h"

typedef struct
{
    SDL_Rect rect;           // Position et taille du bouton
    SDL_Texture* normalTexture; // Texture normale du bouton
    SDL_Texture* hoverTexture;  // Texture lorsqu'on survole le bouton
    bool isHovered;          // Indique si le bouton est survolé par la souris
} Button;


 SelectBird(SDL_Renderer *renderer, SDL_Window *window, Button leftButton, Button rightButton, Button menuButton ,Button playButton, int frame ){


printf("Run SelectBird\n");



     SDL_Surface* backgroundSurface = IMG_Load("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_045.png");
    if (!backgroundSurface)
    {
        printf("Background image loading failed: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }


    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    if (!backgroundTexture)
    {
        printf("Background texture creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }




    SDL_Surface* birdSurface = IMG_Load("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_049.png");
    if (!birdSurface)
    {
        printf("Bird image loading failed: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }


    SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
    SDL_FreeSurface(birdSurface);
    if (!birdTexture)
    {
        printf("Bird texture creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }


    SDL_Rect bird1,bird2;
    bird1.x=193*frame;
    bird1.y=0;
    bird1.w=193;
    bird1.h=253;


    bird2.x=407;
    bird2.y=70;
    bird2.w=394;
    bird2.h=190;









        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, backgroundTexture, 0, 0);

        SDL_RenderCopy(renderer,birdTexture,&bird1,&bird2);


        SDL_Texture* leftButtonTexture = leftButton.isHovered ? leftButton.hoverTexture : leftButton.normalTexture;
        SDL_RenderCopy(renderer, leftButtonTexture, NULL, &leftButton.rect);

        SDL_Texture* rightButtonTexture = rightButton.isHovered ? rightButton.hoverTexture : rightButton.normalTexture;
        SDL_RenderCopy(renderer, rightButtonTexture, NULL, &rightButton.rect);

        SDL_Texture* menuButtonTexture = menuButton.isHovered ? menuButton.hoverTexture : menuButton.normalTexture;
        SDL_RenderCopy(renderer, menuButtonTexture, NULL, &menuButton.rect);

        SDL_Texture* playButtonTexture = playButton.isHovered ? playButton.hoverTexture : playButton.normalTexture;
        SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButton.rect);


        SDL_RenderPresent(renderer);





    SDL_DestroyTexture(backgroundTexture);
}








