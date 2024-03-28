#include "header.h"

typedef struct
{
    SDL_Rect rect;           // Position et taille du bouton
    SDL_Texture* normalTexture; // Texture normale du bouton
    SDL_Texture* hoverTexture;  // Texture lorsqu'on survole le bouton
    bool isHovered;          // Indique si le bouton est survolé par la souris
} Button;


about(SDL_Renderer *renderer, SDL_Window *window, Button backButton){
printf("Run about\n");


    SDL_Surface* backgroundSurface = IMG_Load("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_047.png");
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





        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, backgroundTexture, 0, 0);

        SDL_Texture* backButtonTexture = backButton.isHovered ? backButton.hoverTexture : backButton.normalTexture;
        SDL_RenderCopy(renderer, backButtonTexture, NULL, &backButton.rect);






        SDL_RenderPresent(renderer);





    SDL_DestroyTexture(backgroundTexture);
}




