#include <stdio.h>
#include <SDL2/SDL.h>
#include <unistd.h>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        sleep(5);
        return 1;
    }

    // Load the music file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    if (SDL_LoadWAV("background_music.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
        printf("SDL_LoadWAV failed: %s\n", SDL_GetError());
        sleep(5);
        return 1;
    }

    // Open the audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        printf("SDL_OpenAudioDevice failed: %s\n", SDL_GetError());
        sleep(5);
        SDL_FreeWAV(wavBuffer);
        return 1;
    }

    // Queue the audio buffer for playback
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0); // Start playback

    // Wait for the music to finish
    SDL_Delay(10000); // Adjust the duration as needed

    // Clean up
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
    
    // Loop to prompt user to return to main menu
    while (1) {
        int choice;
        printf("\nEnter 0 to go to the main menu: ");
        scanf("%d", &choice);
        if (choice == 0) {
           break; // Exit the loop and return to main menu
        }
    }

    return 0;
}

