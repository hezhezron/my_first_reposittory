//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *tlo;
        TImage *pilka;
        TImage *paletka1;
        TImage *paletka2;
        TTimer *Timer1;
        TTimer *p1_up;
        TTimer *p1_down;
        TTimer *p2_up;
        TTimer *p2_down;
        TLabel *Label1;
        TLabel *Label2;
        TShape *Shape2;
        TLabel *Label5;
        TButton *Button2;
        TButton *Button3;
        TButton *Button1;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall p1_upTimer(TObject *Sender);
        void __fastcall p1_downTimer(TObject *Sender);
        void __fastcall p2_upTimer(TObject *Sender);
        void __fastcall p2_downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
