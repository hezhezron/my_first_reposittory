//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x =-10, y=-10;

int punktyCzerwony=0;
int punktyZolty =0;
int iloscOdbic =0;

int ktoZaczyna =0;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
pilka->Left +=x;
pilka->Top +=y;
//odbicie od dolnej siciany

if(pilka->Top+65 >= tlo->Height) y=-y;

//odbicie od gornej siciany

if(pilka->Top+5<=0) y=-y;

//skucha   czerwona

if(pilka->Left < paletka1->Left-5)
{
Timer1->Enabled = false;
pilka->Visible = false;
  punktyZolty++;
  Label2->Caption = IntToStr(punktyCzerwony) +" : " +IntToStr(punktyZolty);
  Label5->Visible=true;
  Label5->Caption = "ILOSC ODBIC: "  +IntToStr(iloscOdbic);
  Button2->Visible =true;
  Button3->Visible =true;
  ktoZaczyna = 1;
}

//skucha   zolta

else if
   (pilka->Left > paletka2->Left+5)
{
Timer1->Enabled = false;
pilka->Visible = false;
   punktyCzerwony++;
   Label2->Caption = IntToStr(punktyCzerwony) +" : " +IntToStr(punktyZolty);
   Label5->Visible=true;
  Label5->Caption = "ILOSC ODBIC: "  +IntToStr(iloscOdbic);
   Button2->Visible =true;
  Button3->Visible =true;
  ktoZaczyna = 0;
  
}


//odbicia czerowna paletka

else if ((pilka->Top+pilka->Height/2 >= paletka1->Top) &&
        (pilka->Top+pilka->Height/2  <= paletka1->Top+paletka1->Height ) &&
        (pilka->Left <= paletka1->Left+paletka1->Width)  )
        {
           if(x<0) x=-x;
           iloscOdbic++;
           x++;
           if((pilka->Top+pilka->Height/2  >= paletka1->Top+paletka1->Height/2-17) &&
               (pilka->Top+pilka->Height/2  <= paletka1->Top+paletka1->Height/2+17 ))
               {
                x=x+5;
                y=-y;
               }

        }
        //odbicia zolta paletka
         else if ((pilka->Top+pilka->Height/2 >= paletka2->Top) &&
        (pilka->Top+pilka->Height/2  <= paletka2->Top+paletka2->Height ) &&
        (pilka->Left+pilka->Width-5 >= paletka2->Left)  )
        {
           if(x>0) x=-x;
           iloscOdbic++;
           x--;

           if((pilka->Top+pilka->Height/2  >= paletka2->Top+paletka2->Height/2-17) &&
               (pilka->Top+pilka->Height/2  <= paletka2->Top+paletka2->Height/2+17 ))
               {
                x=x-5;
                y=-y;
               }

        }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled =true;
Button1->Visible=false;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::p1_upTimer(TObject *Sender)
{
if(paletka1->Top > 9)  paletka1->Top-=13;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p1_downTimer(TObject *Sender)
{
if(paletka1->Top<=tlo->Height-paletka1->Height-30)    paletka1->Top+=13;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p2_upTimer(TObject *Sender)
{
if(paletka2->Top > 9)paletka2->Top-=13;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p2_downTimer(TObject *Sender)
{
if(paletka2->Top<=tlo->Height-paletka2->Height-30) paletka2->Top+=13;         
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == 0x57) p1_up->Enabled = true;
if (Key == 0x53) p1_down->Enabled = true;
if (Key == 0x26) p2_up->Enabled = true;
if (Key == 0x28) p2_down->Enabled = true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == 0x57) p1_up->Enabled = false;
if (Key == 0x53) p1_down->Enabled = false;
if (Key == 0x26) p2_up->Enabled = false;
if (Key == 0x28) p2_down->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
       pilka->Top =    240;
       pilka->Left =   568;
       paletka1->Top =160;
       paletka2->Top =160;
       pilka->Visible = true;
       Button2->Visible =false;
       Button3->Visible =false;
        Timer1->Enabled =true;
        Label5->Visible=false;

       iloscOdbic =0;

       if (ktoZaczyna ==0)
       {
          x =-10; y=-10;
       }
         else
         {
         x =10, y=10;
         }

        Timer1->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if(Application->MessageBoxA(
         "Czy na pewno rozpocz¹æ od nowa ?","PotwierdŸ",
         MB_YESNO | MB_ICONQUESTION) == IDYES)
        {

 pilka->Top =    240;
       pilka->Left =   568;
       paletka1->Top =160;
       paletka2->Top =160;
       pilka->Visible = true;
       Button2->Visible =false;
       Button3->Visible =false;
       Timer1->Enabled =true;
       Label5->Visible=false;
       iloscOdbic =0;
       x =-10;
       y=-10;
       punktyCzerwony=0;
       punktyZolty =0;
       Label2->Caption = "0 : 0";

        Timer1->Enabled =true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Application->MessageBoxA(
         "Witaj w grze PingPong.\n "
         "Czerwony gracz steruje klawiszami W i S.\n"
         "Zó³ty gracz steruje strzalkami góra i dó³.\n\n"

         "Dodatkowo pi³eczka znacznie przyspiesza \n"
         "przy uderzeniu w œrodek paletki.\n"

         "Ka¿de odbicie równie¿ przyspiesza pi³eczkê."


         ,"PingPong", NULL);

      pilka->Top =    240;
       pilka->Left =   568;
       paletka1->Top =160;
       paletka2->Top =160;
       pilka->Visible = true;
       Button2->Visible =false;
       Button3->Visible =false;
       Label5->Visible=false;
       iloscOdbic =0;
       x =-10;
       y=-10;
       punktyCzerwony=0;
       punktyZolty =0;
       Label2->Caption = "0 : 0";

}
//---------------------------------------------------------------------------



