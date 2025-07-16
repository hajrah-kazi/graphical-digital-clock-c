#include <stdio.h> 
#include <conio.h> 
#include <dos.h> 
#include <graphics.h> 
 
void drawClock(int hours, int minutes, int seconds) { 
    // Declare the time string at the beginning of the function 
    char timeString[9]; 
 
    // Set the background color 
    setbkcolor(BLACK); 
    cleardevice(); 
 
    // Draw a border for the clock 
    setcolor(WHITE); 
    rectangle(50, 50, 400, 200); 
 
    // Set text style and color 
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4); 
    setcolor(YELLOW); 
 
    // Format the time string 
    sprintf(timeString, "%02d:%02d:%02d", hours, minutes, seconds); 
 
    // Display the digital clock in the center 
    outtextxy(100, 100, timeString); 
 
    // Draw a label for the clock 
    setcolor(WHITE); 
    outtextxy(150, 160, "Digital Clock"); 
} 
 
void main() { 
    int gd = DETECT, gm; 
    int hours, minutes, seconds; // Declare time variables here 
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Initialize graphics mode 
 
    while (1) { 
        // Get the current time 
        seconds = time(NULL) % 60; // Get seconds 
        minutes = (time(NULL) / 60) % 60; // Get minutes 
        hours = (time(NULL) / 3600) % 24; // Get hours 
 
        // Draw the clock 
        drawClock(hours, minutes, seconds); 
 
        // Delay for 1 second 
        delay(1000); 
    } 
 
    closegraph(); // Close the graphics mode (not reached due to infinite loop) 
} 