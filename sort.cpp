#define SDL_MAIN_HANDLED
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <thread>
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void myInsertionSort(vector<int> &num, SDL_Renderer *renderer)
{
    for (int i = 1; i < num.size(); i++)
    {
        if (num[i] < num[i - 1])
        {
            int j = i;
            while (num[j] < num[j - 1] && j > 0)
            {
                int holder = num[j];
                num[j] = num[j - 1];
                num[j - 1] = holder;
                j -= 1;
            }
        }
        SDL_Delay(40);
        for (auto sorted : num)
        {
            cout << sorted << " ";
        }
        cout << "\r" << flush;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);
        for (int boi = 0, j = 0; boi <= num.size(); boi += 1, j += 8)
        {
            int linedrawer = num[boi];

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 250);
            SDL_RenderDrawLineF(renderer, j, 600, j, 600 - linedrawer * 6);
            
            linedrawer = 0;
            
        }
        SDL_RenderPresent(renderer);
    };
};

class Window
{
public:
    SDL_Window *ptr;
    Window(int width, int height)
    {
        ptr = SDL_CreateWindow("Turtle lang by lazlo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    }
    ~Window()
    {
        SDL_DestroyWindow(ptr);
        cout << "Window Destroyed." << endl;
    }
};
class Render
{
public:
    SDL_Renderer *ptr2;
    Render(SDL_Window* window)
    {
        ptr2 = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    }
    ~Render()
    {
        SDL_DestroyRenderer(ptr2);
    }
};

int main(int argc, char **argv)
{
    int returnval = SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *ptr = SDL_CreateWindow("Insertion Sort", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *ptr2 = SDL_CreateRenderer(ptr, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    cout << returnval << endl;
    if (ptr2 == NULL)
    {
        return 1;
    }
    vector<int> listy = {12, 57, 84, 1, 93, 60, 59, 26, 74, 7, 2, 52, 10, 11, 20, 18, 97, 13, 79, 37, 45, 30, 32, 88, 14, 98, 70, 9, 36, 62, 61, 96, 24, 100, 33, 99, 21, 92, 81, 94, 40, 29, 90, 19, 58, 66, 56, 17, 28, 38, 46, 95, 55, 31, 85, 16, 73, 83, 49, 4, 44, 41, 78, 39, 23, 75, 86, 80, 87, 5, 72, 34, 3, 27, 25, 63, 64, 71, 6, 76, 8, 65, 22, 15, 50, 42, 43, 53, 51, 77, 67, 47, 35, 91, 89, 82, 68, 54, 69, 48};
    auto start = high_resolution_clock::now();
    myInsertionSort(listy, ptr2);
    auto stop = high_resolution_clock::now();
    // for(auto sorted : listy){
    // cout << sorted << " ";
    //}
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\r\n Duration of insertion sort alg: " << duration.count() << endl;
    cout << SDL_GetError() << endl;
    SDL_DestroyRenderer(ptr2);
    SDL_DestroyWindow(ptr);
    SDL_Quit();
    return 0;
}
// g++ sort.cpp -I sdl/SDL2-2.30.2/x86_64-w64-mingw32/include -L sdl/SDL2-2.30.2/x86_64-w64-mingw32/lib/ -l SDL2 -l SDL2main -O0 -g -Wall -Wextra -pedantic -std=c++17