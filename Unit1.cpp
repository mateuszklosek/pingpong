//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-8;
int y=-8;
int iloscOdbic = 0;
AnsiString wynik ="";
int punktyL = 0;
int punktyR = 0;
AnsiString punktyLstr, punktyRstr;
AnsiString iloscOdbicstr ="";


void koniecRundy(){
punktyLstr = IntToStr(punktyL);
punktyRstr = IntToStr(punktyR);
wynik = punktyLstr + " : " + punktyRstr;
Form1->tablicaWynikow->Visible = true;
Form1->tablicaWynikow->Caption = wynik;
Form1->Button2->Visible = true;
Form1->Button3->Visible = true;
Form1->liczbaOdbicLabel->Visible = true;
iloscOdbicstr = IntToStr(iloscOdbic);
Form1->liczbaOdbicLabel->Caption = "Liczba odbic: " + iloscOdbicstr;
}

void nowaRunda(){
Form1->tablicaWynikow->Visible = false;
Form1->Button2->Visible = false;
Form1->Button3->Visible = false;
Form1->TimerPilka->Enabled = true;
Form1->ball->Left = 550;
Form1->ball->Top = 350;
Form1->ball->Visible = true;
Form1->przegrana->Visible = false;
iloscOdbic = 0;
Form1->liczbaOdbicLabel->Visible = false;
}

void nowaGra(){
x=-8;
y=-8;
Form1->tablicaWynikow->Visible = false;
Form1->Button2->Visible = false;
Form1->Button3->Visible = false;
Form1->TimerPilka->Enabled = true;
Form1->ball->Left = 550;
Form1->ball->Top = 350;
Form1->ball->Visible = true;
Form1->przegrana->Visible = false;
punktyR = 0;
punktyL = 0;
iloscOdbic = 0;
Form1->liczbaOdbicLabel->Visible = false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
if(Application->MessageBox("Czy na pewno zakonczyc program?","PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
               Application->Terminate();
        }        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

Application->MessageBox(" Witaj w grze PingPong! \n Lewy gracz steruje wciskajac klawisze A oraz Z. \n Prawy gracz steruje wciskajac strza³ki góra / dó³.\n Uderzej¹c srodkiem paletki zwiekszysz predkosc i k¹t pi³ki!  \n \n Mi³ej zabawy!",
"Ping Pong ver. 1.0", NULL);
//ShowMessage("Please fill out your Time Sheet before leaving.", "Ping Pong ver. 1.0",  NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerDownLTimer(TObject *Sender)
{
if(p1->Top+p1->Height < Tlo ->Height-10) p1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerUpLTimer(TObject *Sender)
{
if(p1->Top > 10) p1->Top -= 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if ((Key == 'a' )|| (Key == 'A')) TimerUpL->Enabled = true;
if ((Key == 'z' )|| (Key == 'Z')) TimerDownL->Enabled = true;
if (Key == VK_UP) TimerUpR->Enabled = true;
if (Key == VK_DOWN) TimerDownR->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if ((Key == 'a' )|| (Key == 'A')) TimerUpL->Enabled = false;
if ((Key == 'z' )|| (Key == 'Z')) TimerDownL->Enabled = false;
if (Key == VK_UP) TimerUpR->Enabled = false;
if (Key == VK_DOWN) TimerDownR->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Button1->Visible = false;
TimerPilka->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerDownRTimer(TObject *Sender)
{
if(p2->Top+p2->Height < Tlo ->Height-10) p2->Top += 10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TimerUpRTimer(TObject *Sender)
{
if(p2->Top > 10) p2->Top -= 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TimerPilkaTimer(TObject *Sender)
{
ball->Top += y;
ball->Left += x;

//odbicie od gory
if(ball->Top-5 <= Tlo->Top) y = -y;

//odbicie od dolu
if(ball->Top+ball->Height+5 >= Tlo->Height) y = -y;

//skucha gracza po lewej
if(ball->Left <= p1->Left)
{
        TimerPilka->Enabled = false;
        ball->Visible = false;
        przegrana->Caption = "!Wygral gracz po prawej!";
        przegrana->Visible = true;
        punktyR++;
        x=-8;
        y=-8;
        koniecRundy();
}

//skucha gracza po prawej
if(ball->Left+ball->Width >= p2->Left+20)
{
        TimerPilka->Enabled = false;
        ball->Visible = false;
        przegrana->Caption = "!Wygral gracz po lewej!";
        przegrana->Visible = true;
        punktyL++;
        x=8;
        y=8;
        koniecRundy();
}
//odbicie od paletki lewej
if(ball->Top > p1->Top - 15 && ball->Top + ball->Height < p1->Top +p1->Height +15 && ball->Left <= p1->Left + p1->Width )
{
x = -x;
//sndPlaySound("snd/odbicie.wav", SND_ASYNC);
iloscOdbic++;
}
//odbicie od paletki prawej
if(ball->Top > p2->Top - 15 && ball->Top + ball->Height < p2->Top +p2->Height +15 && ball->Left+ball->Width >= p2->Left)
{
x = -x;
//sndPlaySound("snd/odbicie.wav", SND_ASYNC);
iloscOdbic++;
}

//odbicie od srodkowej czesci lewej paletki
if(ball->Top > p1->Top +9 && ball->Top + ball->Height < p1->Top +p1->Height -9 && ball->Left <= p1->Left + p1->Width )
{
if(x > 0) x+=2;
else x-=2;
if(y > 0) y+=1;
else y-=1;
}

//odbicie od srodkowej czesci prawej paletki
if(ball->Top > p2->Top +9 && ball->Top + ball->Height < p2->Top +p2->Height -9 && ball->Left+ball->Width >= p2->Left)
{
if(x > 0) x+=2;
else x-=2;
//if(y > 0) y+=1;
//else y-=1;
}


}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button2Click(TObject *Sender)
{
nowaRunda();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
nowaGra();
}
//---------------------------------------------------------------------------


