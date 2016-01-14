
#define TMSLAB_WIN

#include "main.h"
#include "stdlib.h"
#include "display/display.hpp"
#include "drawable/SpaceShip.hpp"
#include "drawable/Enemy.hpp"
#include "drawable/EnemyGroup.hpp"
#include "drawable/SimpleBullet.hpp"
#include "game/SpaceShooter.hpp"
#include <stdint.h>
#include <numeric>
#include <limits>
#include "Logger/Logger.h"

#ifdef TMSLAB_C2000
#include "2812_header.h"
#endif

#define PrintText(Pointer, String, Len, x, y)                                  \
  for (size_t a0 = 0; a0 < Len; a0++)                                          \
    Pointer[a0 + x + y * 40] = String[a0];

unsigned long *ekran; //[8*128*2]
#ifdef TMSLAB_C2000
unsigned char *textEkran; //[40*16/2]
#endif
#ifdef TMSLAB_WIN
unsigned short int *textEkran; //[40*16/2]
uint8_t *mySPtr = reinterpret_cast<uint8_t *>(ekran);
//extern int (*PartialRefresh)();
char credits[43] = " PILARSKI & STROKA : PID";
#endif

#ifdef TMSLAB_C2000
#pragma CODE_SECTION("prog")
#endif

void clearScreen(){
  size_t a;
  for (a = 0; a < (40 * 16); a++)
    textEkran[a] = ' ';
  for (a = 0; a < (128 * 8); a++)
    ekran[a] = 0;
}

int main() {
  using namespace Graphics;
  R_P_LCD_TMSLAB LCD;
  R_P_KEYBOARD_TMSLAB KEYBOARD;
  R_P_LEDBAR_TMSLAB LEDBAR;
  SetUpPeripherials();

#ifdef TMSLAB_C2000
  LCD.LCD_Init(ekran, textEkran);
#endif
#ifdef TMSLAB_WIN
  LCD.LCD_Init(&ekran, &textEkran);
#endif
  KEYBOARD.InitKB(100);
  LEDBAR.InitLedBar();

  EnableInterrupts();

  LOG_INFO("Program started");

  Display display(ekran, 115, 240);
  Game::SpaceShooter theGame(KEYBOARD, LCD, LEDBAR, display);

  LOG_INFO("starting the game");
  theGame.start();


}

#ifdef TMSLAB_C2000
#pragma CODE_SECTION("prog")
interrupt void Timer2Isr() {
  LCD.PartialRefresh();
  KEYBOARD.PartialRefresh();
}
#pragma CODE_SECTION("prog")
interrupt void NoIsr() {}
void EnableInterrupts() {

  EALLOW;
  volatile C28X_TIMER *Timer2 = (C28X_TIMER *)0xc10;
  Timer2->Control = 0x4020; // Generuj przerwanie od timera2 i przeladuj licznik
  IER = 0x2000; // Odblokuj przerwanie INT14
  PIECTRL = 1;
  EINT;
  EDIS;
}

void SetUpPeripherials() {
  EALLOW;
  DINT;
  DRTM;
  WDCR = Disable_WD;
  PLLCR = PLL_150MHz;
  uWait(10000);
  ekran = (unsigned long *)0x3f8000;     //[8*128*2]
  textEkran = (unsigned char *)0x3f8a00; //[40*16/2]
  volatile unsigned long *VECTBEG = (volatile unsigned long *)0x0D02;
  while (VECTBEG != (volatile unsigned long *)0x0E00)
    *VECTBEG++ = (long)NoIsr;
  INT14_VEC_014 = (ulong)Timer2Isr;
  PCLKCR = 0x000b;
  LOSPCP = 0;
  HISPCP = 0;
  volatile C28X_TIMER *Timer2 = (C28X_TIMER *)0xc10;
  Timer2->Timer = 0;
  Timer2->Period = 150 * 9;
  Timer2->Prescale = 0;
  Timer2->Control = 0;
  EDIS;
}
#endif

#ifdef TMSLAB_WIN
void EnableInterrupts() {}
void SetUpPeripherials() {}
#endif
