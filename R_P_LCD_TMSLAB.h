///////////////////////////////////////
/////  Copyrights:                 ////
/////  iDSP 2009                   ////
/////  Zak³ad Techniki Sterownia   ////
/////     Instytut Automatyki      ////
/////     Politechnika £ódzka      ////
///////////////////////////////////////,

#ifndef RADZIECKI_LCD
#define RADZIECKI_LCD

#define TMSLAB_WIN

class R_P_LCD_TMSLAB
{
public:
volatile long m_cntRefresh;                             // Etap auktualizacji
volatile int m_vsync;                                   // Flaga synchronizacji pionowej
void PartialRefresh();                                  // Procedura cyklicznego aktualizowania ekranu LCD
void Synchronize();										                  // Oczekuje zakonczenia aktualizacji wyswietlacza
void LCD_Command(unsigned int uiData);                  // Wys³anie polecenia do LCD
void LCD_Write_2Bytes(unsigned int uiData);             // Wys³anie s³owa danych do LCD
void LCD_Write_1Bytes(unsigned int uiData);             // Wys³anie bajtu danych do LCD
#ifdef TMSLAB_C2000
void LCD_Init(unsigned long *Map,unsigned char* TMap);  // Inicjalizacja wyœwietlacza LCD Map-adres pamiêci graficznejm TMap-adres pamiêci tekstowej
#endif
#ifdef TMSLAB_WIN
void LCD_Init(unsigned long **Map,unsigned short int** TMap);  // Inicjalizacja wyœwietlacza LCD Map-adres pamiêci graficznejm TMap-adres pamiêci tekstowej
#endif

private:
long *g1[2];
int g2[6];
};

#endif

