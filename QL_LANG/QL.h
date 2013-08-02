#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

#define true 1
#define false 0
#define bool int

typedef struct 
{
	bool F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12; // Handled
	bool ESC, lSHIFT, rSHIFT, lCTRL, rCTRL, lWIN, rWIN, lALT, rALT, CAPS, NUM; // Handled
	bool one, two, three, four, five, six, seven, eight, nine, zero; // Handled
	bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z; // Handled
	bool tab, insert, home, del, end, pgUp, pgDown, backspace; // Handled
	bool up, down, left, right; // Handled
	bool NUMone, NUMtwo, NUMthree, NUMfour, NUMfive, NUMsix, NUMseven, NUMeight, NUMnine, NUMzero; // Handled
} keyObj;

// SDL variables needed
SDL_Surface *screen;
SDL_Event event;

// Input
keyObj keyInput;

// Screen 
int scrWidth, scrHeight;
int scrTransX, scrTransY;
int scrScaleX, scrScaleY;
int scrColour;

// Framerate
int FPS, drawTime, timeDelta;
int timeOne, timeTwo;

// Shape displaying stuff
int colour;
int lineWidth;

// Function definitions:
bool initWindow(int height, int width, bool fullscreen, char *name); // Creates a window, this must be done before any graphics - related operations. Returns true if successful 
void clear();
void grabInput();
#ifdef EMSCRIPTEN
void update(int desFPS, void main)
#else
void update();
#endif
void capFrameRate(int desFPS); // Caps the frame rate, then updates FPS.

void pixel(int x, int y); // Blatantly copied from the SDL example

bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw); // Returns true if a collision is detected

void setColour(int r, int g, int b, int a);   // Sets the current colour to the r, g, b, a specified.
void setScrColour(int r, int g, int b, int a); // Sets the background of the window to the r, g, b, a specified;
void setLineWidth(int width); // Does nothing as there's no un-broken line drawing func yet :/

void line(int xi, int yi, int xii, int yii); // Does nothing as such, very broken :/
int rect(char *type, int x, int y, int w, int h); // Draws a rect. Returns false if an error has been encountered.
int circle(char *type, int x, int y, float radius); // Draws a circle with the middle at the x, y. Returns false if an error has been encountered.

float degreesToRadians(float deg); // Returns a float containing the radians.
float radiansToDegrees(float rad); // Returns a float containing the degrees.
int randomNum(int min, int max); // Returns a random number, is inclusive.
// bool noiseGen(double *noise, double width, double height); // Returns an array full of noise.
// double smoothNoise(double noise[][], double x, double y, double width, double height); // Smooths the noise. Don't use this, it's only for the noiseDraw() function.
// double turbulentNoise(double x, double y, double scale); // Applies turbulence to the noise. Don't use this, it's only for the noiseDraw() function.
// bool noiseDraw(char *type, double noise[][], double width, double height, double scale) // Draws noise created with noiseGen(). Supported args are "normal", "smooth" and "turbulence" (Don't use turbulence with a scale value of 0)

