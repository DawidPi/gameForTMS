///////////////////////////////////////
/////  Copyrights:                 ////
/////  iDSP 2009                   ////
/////  Zak�ad Techniki Sterownia   ////
/////     Instytut Automatyki      ////
/////     Politechnika ��dzka      ////
///////////////////////////////////////,
#define TMSLAB_WIN
class R_P_LCD_TMSLAB
{
public:
volatile long m_cntRefresh;                             // Etap auktualizacji
volatile int m_vsync;                                   // Flaga synchronizacji pionowej
void PartialRefresh();                                  // Procedura cyklicznego aktualizowania ekranu LCD
void Synchronize();										                  // Oczekuje zakonczenia aktualizacji wyswietlacza
void LCD_Command(unsigned int uiData);                  // Wys�anie polecenia do LCD
void LCD_Write_2Bytes(unsigned int uiData);             // Wys�anie s�owa danych do LCD
void LCD_Write_1Bytes(unsigned int uiData);             // Wys�anie bajtu danych do LCD
#ifdef TMSLAB_C2000
void LCD_Init(unsigned long *Map,unsigned char* TMap);  // Inicjalizacja wy�wietlacza LCD Map-adres pami�ci graficznejm TMap-adres pami�ci tekstowej
#endif
#ifdef TMSLAB_WIN
void LCD_Init(unsigned long **Map,unsigned short int** TMap);  // Inicjalizacja wy�wietlacza LCD Map-adres pami�ci graficznejm TMap-adres pami�ci tekstowej
#endif

private:
long *g1[2];
int g2[6];
};

