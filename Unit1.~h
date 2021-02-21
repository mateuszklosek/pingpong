//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *p1;
        TTimer *TimerUpL;
        TTimer *TimerDownL;
        TShape *Tlo;
        TButton *Button1;
        TImage *p2;
        TTimer *TimerDownR;
        TTimer *TimerUpR;
        TImage *ball;
        TTimer *TimerPilka;
        TLabel *przegrana;
        TButton *Button2;
        TLabel *tablicaWynikow;
        TButton *Button3;
        TLabel *liczbaOdbicLabel;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TimerDownLTimer(TObject *Sender);
        void __fastcall TimerUpLTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall TimerDownRTimer(TObject *Sender);
        void __fastcall TimerUpRTimer(TObject *Sender);
        void __fastcall TimerPilkaTimer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
