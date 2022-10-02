//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <fstream>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFC_v5 *FC_v5;
//---------------------------------------------------------------------------
__fastcall TFC_v5::TFC_v5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

  AnsiString X="",Y="",D="",X1="",pf,dgf,nd;
   float x=0,y=0,x1=0;
    int d=0,id;


////////////////////////////////////////////////////////////////////////////////
  int calculate_fame_before_daily_lost(AnsiString XX,AnsiString YY,AnsiString DD)
   {
        x=atof(XX.c_str())*1000;
        y=atof(YY.c_str())*1000;
        d=atoi(DD.c_str());

        FC_v5->Memo5->Lines->LoadFromFile("txt/history.txt");
        FC_v5->Memo2->Text=Now();
        FC_v5->Memo5->Lines->Append(FC_v5->Memo2->Text);
        FC_v5->Memo5->Lines->Append("Calculated fame before daily lost");
        FC_v5->Memo5->Lines->Append("Player's fame: ");
        FC_v5->Memo5->Lines->Append(x);
        FC_v5->Memo5->Lines->Append("Daily gained fame: ");
        FC_v5->Memo5->Lines->Append(y);
        FC_v5->Memo5->Lines->Append("Number of days: ");
        FC_v5->Memo5->Lines->Append(d);
        FC_v5->Memo5->Lines->Append("");


    d--;
    if(d>=1)
    {
        for (int i=0; d>i; i++)
        {

            x+=y;
            x=x-(x/50);
        }
        x+=y;
    }

    else if(d==0)
    {
        x+=y;
    }
     int xx=x;
    FC_v5->Memo5->Lines->Append("Amount of fame: ");
    FC_v5->Memo5->Lines->Append(xx);
    FC_v5->Memo5->Lines->Append("");
    FC_v5->Memo5->Lines->Append("");
    FC_v5->Memo5->Lines->SaveToFile("txt/history.txt");

                FC_v5->Edit1->Text="";
                FC_v5->Edit2->Text="";
                FC_v5->Edit3->Text="";

      return x;
     }
//------------------------------------------------------------------------------



     int calculate_fame_after_daily_lost(AnsiString XX,AnsiString YY,AnsiString DD)
     {
        x=atof(X.c_str())*1000;
        y=atof(Y.c_str())*1000;
        d=atoi(D.c_str());

        FC_v5->Memo5->Lines->LoadFromFile("txt/history.txt");
        FC_v5->Memo2->Text=Now();
        FC_v5->Memo5->Lines->Append(FC_v5->Memo2->Text);
        FC_v5->Memo5->Lines->Append("Calculated fame after daily lost");
        FC_v5->Memo5->Lines->Append("Player's fame: ");
        FC_v5->Memo5->Lines->Append(x);
        FC_v5->Memo5->Lines->Append("Daily gained fame: ");
        FC_v5->Memo5->Lines->Append(y);
        FC_v5->Memo5->Lines->Append("Number of days: ");
        FC_v5->Memo5->Lines->Append(d);
        FC_v5->Memo5->Lines->Append("");

    for (int i=0; d>i; i++)
    {
        x+=y;
        x=x-(x/50);
    }
    int xx=x;
    FC_v5->Memo5->Lines->Append("Amount of fame: ");
    FC_v5->Memo5->Lines->Append(xx);
    FC_v5->Memo5->Lines->Append("");
    FC_v5->Memo5->Lines->Append("");
    FC_v5->Memo5->Lines->SaveToFile("txt/history.txt");

                FC_v5->Edit1->Text="";
                FC_v5->Edit2->Text="";
                FC_v5->Edit3->Text="";

      return x;
     }
//------------------------------------------------------------------------------


      int calculate_prefered_amount_of_fame(AnsiString XX,AnsiString YY,AnsiString X1)
     {  AnsiString A,B,C,D;
         float a,b;
         d=0;
        x=atof(X.c_str())*1000;
        y=atof(Y.c_str())*1000;
        x1=atof(X1.c_str())*1000;

        FC_v5->Memo5->Lines->LoadFromFile("txt/history.txt");
        FC_v5->Memo2->Text=Now();
        FC_v5->Memo5->Lines->Append(FC_v5->Memo2->Text);
        FC_v5->Memo5->Lines->Append("Calculated prefered amount of fame");
        FC_v5->Memo5->Lines->Append("Player's fame: ");
        FC_v5->Memo5->Lines->Append(x);
        FC_v5->Memo5->Lines->Append("Daily gained fame: ");
        FC_v5->Memo5->Lines->Append(y);
        FC_v5->Memo5->Lines->Append("Prefered amount of fame: ");
        FC_v5->Memo5->Lines->Append(x1);
        FC_v5->Memo5->Lines->Append("");


    if(y>0 && x>50000 && x1>0 && x1<50000)
    {
                ShowMessage("Incalculable number of days. Enter other numbers!");
                return 0;
    }

    else if((y*50>=x)&&(x1<x))
    {

    A="Prefered amount of fame has to be not less than ";

    y*=50;
    B=" or daily gained fame has to be not more than ";
    x1/=50;

    C=A+CurrToStr(y)+B+CurrToStr(x1);
    ShowMessage(C);
    return 0;

    }
    else if(y>=x1)
    {
        ShowMessage("Too low amount of prefered fame, it has to be not less than daily gained fame.");
        return 0;
    }
    else
    {
        if(x<x1)
        {
            while (x<x1)
            {
                x+=y;
                x=x-(x/50);
                if(a==x)
                {
                    d--;
                    x+=x1;
                }
                d++;
                a=x;
            }
        }
        else if((x>x1)&&(y*50!=x)&&(y*50<=x))
        {   b=x;
            while (x1<x)
                {
                x+=y;
                x=x-(x/50);
                d++;
                }
        }

        if(b>x1)
        {
            return d;
        }

        else if(x1>y*50)
        {
            x1=y*50;
            A="Max fame avaible to reach: ";
            B=" fame. It will take ";
            D=" days to reach it.";


            C=A+CurrToStr(x1)+B+CurrToStr(d)+D;
            ShowMessage(C);
            return 0;

        }
        else
        {
    FC_v5->Memo5->Lines->Append("Number of days: ");
    FC_v5->Memo5->Lines->Append(d);
    FC_v5->Memo5->Lines->Append("");
    FC_v5->Memo5->Lines->Append("");
    FC_v5->Memo5->Lines->SaveToFile("txt/history.txt");

                FC_v5->Edit1->Text="";
                FC_v5->Edit2->Text="";
                FC_v5->Edit3->Text="";

            return d;

        }
    }

}

//------------------------------------------------------------------------------
       void fameclose()
       {
              FC_v5->Famecalculation1->Checked=false;
              FC_v5->Famecalculation2->Checked=false;
              FC_v5->Famecalculation3->Checked=false;

               FC_v5->Label1 -> Visible=false;
                 FC_v5->Label2 -> Visible=false;
                 FC_v5->Label3 -> Visible=false;
                 FC_v5->Label5 -> Visible=false;
                 FC_v5->Label4 -> Visible=false;

                 FC_v5->Edit1 -> Visible=false;
                 FC_v5->Edit2 -> Visible=false;
                 FC_v5->Edit3 -> Visible=false;
                 FC_v5->Edit4->Visible=false;

                 FC_v5->Button1 ->  Visible=false;

                 FC_v5->fame->Visible=false;
                 FC_v5->sfame1->Visible=false;
                 FC_v5->sfame2->Visible=false;
                 FC_v5->sfame3->Visible=false;

       }
//------------------------------------------------------------------------------
        void memoclose()
        {
                 FC_v5->ti->Visible=false;
                 FC_v5->ti1->Visible=false;
                 FC_v5->ti2->Visible=false;
                 FC_v5->ti3->Visible=false;
                 FC_v5->ti4->Visible=false;
                 FC_v5->ti5->Visible=false;
                 FC_v5->ti6->Visible=false;
                 FC_v5->ti7->Visible=false;
                 FC_v5->ti8->Visible=false;
                 FC_v5->ti9->Visible=false;
                 FC_v5->ti10->Visible=false;
                 FC_v5->ti11->Visible=false;
                 FC_v5->ti12->Visible=false;
                 FC_v5->ti13->Visible=false;
                 FC_v5->ti14->Visible=false;
                 FC_v5->ti15->Visible=false;
                 FC_v5->ti16->Visible=false;

             FC_v5->ecopper->Visible=false;
             FC_v5->esilver->Visible=false;
             FC_v5->egold->Visible=false;

             FC_v5->de->Visible=false;

             FC_v5->e1->Visible=false;
             FC_v5->e2->Visible=false;
             FC_v5->e3->Visible=false;
             FC_v5->e4->Visible=false;
             FC_v5->e5->Visible=false;
             FC_v5->e6->Visible=false;
             FC_v5->e7->Visible=false;
             FC_v5->e8->Visible=false;
             FC_v5->e9->Visible=false;
             FC_v5->e10->Visible=false;
             FC_v5->e11->Visible=false;
             FC_v5->e12->Visible=false;

             FC_v5->excellent->Visible=false;
             FC_v5->very_good->Visible=false;
             FC_v5->good->Visible=false;

             FC_v5->Memo5->Visible=false;

             FC_v5->claim->Visible=false;
             FC_v5->gate->Visible=false;
             FC_v5->percent ->Visible=false;

             FC_v5->a1->Visible=false;
             FC_v5->a2->Visible=false;
             FC_v5->a3->Visible=false;
             FC_v5->a4->Visible=false;
             FC_v5->a5->Visible=false;
             FC_v5->a6->Visible=false;
             FC_v5->a7->Visible=false;
             FC_v5->a8->Visible=false;
             FC_v5->a9->Visible=false;
             FC_v5->a10->Visible=false;


             FC_v5->va->Visible=false;
            FC_v5->va1->Visible=false;
            FC_v5->va2->Visible=false;
            FC_v5->va3->Visible=false;
            FC_v5->va4->Visible=false;
            FC_v5->va5->Visible=false;
            FC_v5->va6->Visible=false;
            FC_v5->va7->Visible=false;
            FC_v5->va8->Visible=false;
            FC_v5->va9->Visible=false;
            FC_v5->va10_1->Visible=false;
            FC_v5->va10_2->Visible=false;


        }
//------------------------------------------------------------------------------
        void sfame()
        {

                 FC_v5->sfame1->Top=61;
                 FC_v5->sfame1->Left=530;
                 FC_v5->sfame1->Picture->LoadFromFile("icons/sfame.bmp");
                 FC_v5->sfame1->Visible=true;

                 FC_v5->sfame2->Top=111;
                 FC_v5->sfame2->Left=530;
                 FC_v5->sfame2->Picture->LoadFromFile("icons/sfame.bmp");
                 FC_v5->sfame2->Visible=true;

                 FC_v5->sfame3->Top=160;
                 FC_v5->sfame3->Left=530;
                 FC_v5->sfame3->Picture->LoadFromFile("icons/sfame.bmp");
                 FC_v5->sfame3->Visible=true;

                 FC_v5->fame->Top=260;
                 FC_v5->fame->Left=380;
                 FC_v5->fame->Picture->LoadFromFile("icons/fame.bmp");
                 FC_v5->fame->Visible=true;


        }

//------------------------------------------------------------------------------
        void memo2close()
        {
            FC_v5->claim->Visible=false;
            FC_v5->gate->Visible=false;
            FC_v5->percent->Visible=false;
            FC_v5->excellent->Visible=false;
            FC_v5->very_good->Visible=false;
            FC_v5->good->Visible=false;

                 FC_v5->ti->Visible=false;
                 FC_v5->ti1->Visible=false;
                 FC_v5->ti2->Visible=false;
                 FC_v5->ti3->Visible=false;
                 FC_v5->ti4->Visible=false;
                 FC_v5->ti5->Visible=false;
                 FC_v5->ti6->Visible=false;
                 FC_v5->ti7->Visible=false;
                 FC_v5->ti8->Visible=false;
                 FC_v5->ti9->Visible=false;
                 FC_v5->ti10->Visible=false;
                 FC_v5->ti11->Visible=false;
                 FC_v5->ti12->Visible=false;
                 FC_v5->ti13->Visible=false;
                 FC_v5->ti14->Visible=false;
                 FC_v5->ti15->Visible=false;
                 FC_v5->ti16->Visible=false;

        }
//------------------------------------------------------------------------------
        void memo3close()
        {

            FC_v5->va->Visible=false;
            FC_v5->va1->Visible=false;
            FC_v5->va2->Visible=false;
            FC_v5->va3->Visible=false;
            FC_v5->va4->Visible=false;
            FC_v5->va5->Visible=false;
            FC_v5->va6->Visible=false;
            FC_v5->va7->Visible=false;
            FC_v5->va8->Visible=false;
            FC_v5->va9->Visible=false;
            FC_v5->va10_1->Visible=false;
            FC_v5->va10_2->Visible=false;

           FC_v5->a1->Visible=false;
           FC_v5->a2->Visible=false;
           FC_v5->a3->Visible=false;
           FC_v5->a5->Visible=false;
           FC_v5->a4->Visible=false;
           FC_v5->a6->Visible=false;
           FC_v5->a7->Visible=false;
           FC_v5->a8->Visible=false;
           FC_v5->a9->Visible=false;
           FC_v5->a10->Visible=false;
        
        }
//------------------------------------------------------------------------------
        void declose()
        {
           FC_v5->de->Visible=false;
           FC_v5->ecopper->Visible=false;
           FC_v5->esilver->Visible=false;
           FC_v5->egold->Visible=false;
           FC_v5->e1->Visible=false;
           FC_v5->e2->Visible=false;
           FC_v5->e3->Visible=false;
           FC_v5->e4->Visible=false;
           FC_v5->e5->Visible=false;
           FC_v5->e6->Visible=false;
           FC_v5->e7->Visible=false;
           FC_v5->e8->Visible=false;
           FC_v5->e9->Visible=false;
           FC_v5->e10->Visible=false;
           FC_v5->e11 ->Visible=false;
           FC_v5->e12->Visible=false;

        }
//------------------------------------------------------------------------------
        void memo5close()
        {
        FC_v5->Memo5->Visible=false;

        }
//------------------------------------------------------------------------------
        void picture()
        {
            randomize();

        id=random(81)+1;

        switch(id)
        {  case 1:FC_v5->Theme->Picture->LoadFromFile("background/dv1.jpg");
           break;
           case 2: FC_v5->Theme->Picture->LoadFromFile("background/gf1.jpg");
           break;
           case 3: FC_v5->Theme->Picture->LoadFromFile("background/gf2.jpg");
           break;
           case 4: FC_v5->Theme->Picture->LoadFromFile("background/gf3.jpg");
           break;
           case 5: FC_v5->Theme->Picture->LoadFromFile("background/gf4.jpg");
           break;
           case 6: FC_v5->Theme->Picture->LoadFromFile("background/mw1.jpg");
           break;
           case 7: FC_v5->Theme->Picture->LoadFromFile("background/mw2.jpg");
           break;
           case 8: FC_v5->Theme->Picture->LoadFromFile("background/mw3.jpg");
           break;
           case 9: FC_v5->Theme->Picture->LoadFromFile("background/mw4.jpg");
           break;
           case 10: FC_v5->Theme->Picture->LoadFromFile("background/mw5.jpg");
           break;
           case 11: FC_v5->Theme->Picture->LoadFromFile("background/gv1.bmp");
           break;
           case 12: FC_v5->Theme->Picture->LoadFromFile("background/gv2.bmp");
           break;
           case 13: FC_v5->Theme->Picture->LoadFromFile("background/gv3.bmp");
           break;
           case 14: FC_v5->Theme->Picture->LoadFromFile("background/gv4.bmp");
           break;
           case 15: FC_v5->Theme->Picture->LoadFromFile("background/gv5.bmp");
           break;
           case 16: FC_v5->Theme->Picture->LoadFromFile("background/cc1.bmp");
           break;
           case 17: FC_v5->Theme->Picture->LoadFromFile("background/cc2.bmp");
           break;
           case 18: FC_v5->Theme->Picture->LoadFromFile("background/cc3.bmp");
           break;
           case 19: FC_v5->Theme->Picture->LoadFromFile("background/cc4.bmp");
           break;
           case 20: FC_v5->Theme->Picture->LoadFromFile("background/mm1.bmp");
           break;
           case 21: FC_v5->Theme->Picture->LoadFromFile("background/mm2.bmp");
           break;
           case 22: FC_v5->Theme->Picture->LoadFromFile("background/mm3.bmp");
           break;
           case 23: FC_v5->Theme->Picture->LoadFromFile("background/mm4.bmp");
           break;
           case 24: FC_v5->Theme->Picture->LoadFromFile("background/bgpros1.jpg");
           break;
           case 25: FC_v5->Theme->Picture->LoadFromFile("background/bgpros2.jpg");
           break;
           case 26: FC_v5->Theme->Picture->LoadFromFile("background/bgpros3.jpg");
           break;
           case 27: FC_v5->Theme->Picture->LoadFromFile("background/bgpros4.jpg");
           break;
           case 28: FC_v5->Theme->Picture->LoadFromFile("background/bgpros5.jpg");
           break;
           case 29: FC_v5->Theme->Picture->LoadFromFile("background/bgpros6.jpg");
           break;
           case 30: FC_v5->Theme->Picture->LoadFromFile("background/bgpros7.jpg");
           break;
           case 31: FC_v5->Theme->Picture->LoadFromFile("background/bgpros8.jpg");
           break;
           case 32: FC_v5->Theme->Picture->LoadFromFile("background/bgpros9.jpg");
           break;
           case 33: FC_v5->Theme->Picture->LoadFromFile("background/pvp1.jpg");
           break;
           case 34: FC_v5->Theme->Picture->LoadFromFile("background/bgarmor1.jpg");
           break;
           case 35: FC_v5->Theme->Picture->LoadFromFile("background/bgarmor2.jpg");
           break;
           case 37: FC_v5->Theme->Picture->LoadFromFile("background/bgarmor3.jpg");
           break;
           case 36: FC_v5->Theme->Picture->LoadFromFile("background/pvp2.jpg");
           break;
           case 38: FC_v5->Theme->Picture->LoadFromFile("background/pvp3.jpg");
           break;
           case 39: FC_v5->Theme->Picture->LoadFromFile("background/pvp4.jpg");
           break;
           case 40: FC_v5->Theme->Picture->LoadFromFile("background/pvp5.jpg");
           break;
           case 41: FC_v5->Theme->Picture->LoadFromFile("background/pvp6.jpg");
           break;
           case 42: FC_v5->Theme->Picture->LoadFromFile("background/pvp7.jpg");
           break;
           case 43: FC_v5->Theme->Picture->LoadFromFile("background/pvp8.jpg");
           break;
           case 44: FC_v5->Theme->Picture->LoadFromFile("background/bgpros10.jpg");
           break;
           case 45: FC_v5->Theme->Picture->LoadFromFile("background/pvp9.jpg");
           break;
           case 47: FC_v5->Theme->Picture->LoadFromFile("background/pvp10.jpg");
           break;
           case 46: FC_v5->Theme->Picture->LoadFromFile("background/pvp11.jpg");
           break;
           case 48: FC_v5->Theme->Picture->LoadFromFile("background/pvp12.jpg");
           break;
           case 49: FC_v5->Theme->Picture->LoadFromFile("background/pvp13.jpg");
           break;
           case 50: FC_v5->Theme->Picture->LoadFromFile("background/pvp14.jpg");
           break;
           case 51: FC_v5->Theme->Picture->LoadFromFile("background/pvp15.jpg");
           break;
           case 52: FC_v5->Theme->Picture->LoadFromFile("background/pvp16.jpg");
           break;
           case 53: FC_v5->Theme->Picture->LoadFromFile("background/pvp17.jpg");
           break;
           case 54: FC_v5->Theme->Picture->LoadFromFile("background/pvp18.jpg");
           break;
           case 55: FC_v5->Theme->Picture->LoadFromFile("background/pvp19.jpg");
           break;
           case 56: FC_v5->Theme->Picture->LoadFromFile("background/pvp20.jpg");
           break;
           case 57: FC_v5->Theme->Picture->LoadFromFile("background/pvp21.jpg");
           break;
           case 58: FC_v5->Theme->Picture->LoadFromFile("background/pvp22.jpg");
           break;
           case 59: FC_v5->Theme->Picture->LoadFromFile("background/pvp23.jpg");
           break;
           case 60: FC_v5->Theme->Picture->LoadFromFile("background/pvp24.jpg");
           break;
           case 61: FC_v5->Theme->Picture->LoadFromFile("background/pvp25.jpg");
           break;
           case 62: FC_v5->Theme->Picture->LoadFromFile("background/pvp26.jpg");
           break;
           case 63: FC_v5->Theme->Picture->LoadFromFile("background/pvp27.jpg");
           break;
           case 64: FC_v5->Theme->Picture->LoadFromFile("background/pvp28.jpg");
           break;
           case 65: FC_v5->Theme->Picture->LoadFromFile("background/dv2.jpg");
           break;
           case 66: FC_v5->Theme->Picture->LoadFromFile("background/rex1.bmp");
           break;
           case 67: FC_v5->Theme->Picture->LoadFromFile("background/pvp29.jpg");
           break;
           case 68: FC_v5->Theme->Picture->LoadFromFile("background/mm5.bmp");
           break;
           case 69: FC_v5->Theme->Picture->LoadFromFile("background/mm6.bmp");
           break;
           case 70: FC_v5->Theme->Picture->LoadFromFile("background/mm7.bmp");
           break;
           case 71: FC_v5->Theme->Picture->LoadFromFile("background/mm8.bmp");
           break;
           case 72: FC_v5->Theme->Picture->LoadFromFile("background/mm9.bmp");
           break;
           case 73: FC_v5->Theme->Picture->LoadFromFile("background/gf5.jpg");
           break;
           case 74: FC_v5->Theme->Picture->LoadFromFile("background/pvp30.jpg");
           break;
           case 75: FC_v5->Theme->Picture->LoadFromFile("background/pvp31.jpg");
           break;
           case 76: FC_v5->Theme->Picture->LoadFromFile("background/pvp32.jpg");
           break;
           case 77: FC_v5->Theme->Picture->LoadFromFile("background/pvp33.jpg");
           break;
           case 78: FC_v5->Theme->Picture->LoadFromFile("background/pvp34.jpg");
           break;
           case 79: FC_v5->Theme->Picture->LoadFromFile("background/pvp35.jpg");
           break;
           case 80: FC_v5->Theme->Picture->LoadFromFile("background/pvp36.jpg");
           break;
           case 81: FC_v5->Theme->Picture->LoadFromFile("background/pvp37.jpg");
           break;



        }

        }

//------------------------------------------------------------------------------
//calculates fame before daily lost
void __fastcall TFC_v5::Famecalculation1Click(TObject *Sender)
{
         Famecalculation2->Checked=false;
                Famecalculation3->Checked=false;

                memoclose();

                 Label5 -> Visible=false;
                 Label1 -> Visible=true;
                 Label2 -> Visible=true;
                 Label3 -> Visible=true;

                 Label4 -> Visible=true;
                 Edit1 -> Visible=true;
                 Edit1 -> Left=384;
                 Edit2 -> Visible=true;
                 Edit2 -> Left=384;
                 Edit3 -> Visible=true;
                 Edit3 -> Left=384;
                 Button1 ->  Visible=true;
                 Edit4->Visible=true;
                 Famecalculation1->Checked=true;
                 Label4->Caption="Amount of fame:";

                       sfame();
}
//---------------------------------------------------------------------------

//calculates fame after daily lost
void __fastcall TFC_v5::Famecalculation2Click(TObject *Sender)
{

                Famecalculation1->Checked=false;
                Famecalculation3->Checked=false;

                memoclose();

                 Label5 -> Visible=false;
                 Label1 -> Visible=true;
                 Label2 -> Visible=true;
                 Label3 -> Visible=true;
                 Label4 -> Visible=true;

                 Edit1 -> Visible=true;
                 Edit1 -> Left=384;
                 Edit2 -> Visible=true;
                 Edit2 -> Left=384;
                 Edit3 -> Visible=true;
                 Edit3 -> Left=384;
                 Button1 ->  Visible=true;
                 Edit4->Visible=true;
                 Famecalculation2->Checked=true;
                 Label4->Caption="Amount of fame:";

                        sfame();


}
//---------------------------------------------------------------------------
//calculates prefered amount of fame
void __fastcall TFC_v5::Famecalculation3Click(TObject *Sender)
{                 Famecalculation1->Checked=false;
                Famecalculation2->Checked=false;

                memoclose();

                  Label3->Visible=false;
                 Label1 -> Visible=true;
                 Label2 -> Visible=true;
                 Label5 -> Visible=true;
                 Label4 -> Visible=true;

                 Edit1 -> Left=475;
                 Edit1 -> Visible=true;
                 Edit2 -> Left=475;
                 Edit2 -> Visible=true;
                 Edit3 -> Left=475;
                 Edit3 -> Visible=true;
                 Button1 ->  Visible=true;
                 Edit4->Visible=true;
                 Famecalculation3->Checked=true;
                 Label4->Caption="Number of days:";

                 sfame();

                 sfame1->Left=621;
                 sfame2->Left=621;
                 sfame3->Left=621;
                 fame->Visible=false;

}
//---------------------------------------------------------------------------







//ends the app
void __fastcall TFC_v5::Exit1Click(TObject *Sender)
{
        if(Application->MessageBox("Do you want to exit?","Accept",
        MB_YESNO|MB_ICONQUESTION)==IDYES)
        {

              Application->Terminate();

        }



}
//---------------------------------------------------------------------------
//end the app
void __fastcall TFC_v5::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application->MessageBox(
        "Do you want to exit?","Accept",
        MB_YESNO|MB_ICONQUESTION)==IDNO)
        {

        Action=caNone;

        }
}
//---------------------------------------------------------------------------


//shows info about yields and daily gained fame
void __fastcall TFC_v5::Informationaboutyieldsanddailygainedfame1Click(
      TObject *Sender)
{
                fameclose();
                memo3close();
                declose();
                memo5close();

                 claim->Picture->LoadFromFile("icons/claim icon.bmp");
                 claim->Visible=true;
                 claim->Top=170;
                 claim->Left=23;

                 gate->Picture->LoadFromFile("icons/gate icon.bmp");
                 gate->Visible=true;
                 gate->Top=10;
                 gate->Left=18;

                 percent->Picture->LoadFromFile("icons/% icon.bmp");
                 percent->Visible=true;
                 percent->Top=460;
                 percent->Left=22;

                 excellent->Picture->LoadFromFile("icons/yields/excellent.bmp");
                 excellent->Visible=true;
                 excellent->Top=386;
                 excellent->Left=88;

                 very_good->Picture->LoadFromFile("icons/yields/very good.bmp");
                 very_good->Visible=true;
                 very_good->Top=360;
                 very_good->Left=87;

                 good->Picture->LoadFromFile("icons/yields/good.bmp");
                 good->Visible=true;
                 good->Top=338;
                 good->Left=52;

                 ti->Visible=true;
                 ti1->Visible=true;
                 ti2->Visible=true;
                 ti3->Visible=true;
                 ti4->Visible=true;
                 ti5->Visible=true;
                 ti6->Visible=true;
                 ti7->Visible=true;
                 ti8->Visible=true;
                 ti9->Visible=true;
                 ti10->Visible=true;
                 ti11->Visible=true;
                 ti12->Visible=true;
                 ti13->Visible=true;
                 ti14->Visible=true;
                 ti15->Visible=true;
                 ti16->Visible=true;



}
//---------------------------------------------------------------------------


//shows info about of attribute values
void __fastcall TFC_v5::Valuesofattributes1Click(TObject *Sender)
{
        fameclose();
        memo2close();
        declose();
        memo5close();

                 va->Visible=true;
                 va1->Visible=true;
                 va2->Visible=true;
                 va3->Visible=true;
                 va4->Visible=true;
                 va5->Visible=true;
                 va6->Visible=true;
                 va7->Visible=true;
                 va8->Visible=true;
                 va9->Visible=true;
                 va10_1->Visible=true;
                 va10_2->Visible=true;

                 a1->Picture->LoadFromFile("icons/attributes/def.bmp");
                 a1->Visible=true;
                 a1->Left=10;
                 a1->Top=53;

                 a2->Picture->LoadFromFile("icons/attributes/strength.bmp");
                 a2->Visible=true;
                 a2->Left=11;
                 a2->Top=79;

                 a3->Picture->LoadFromFile("icons/attributes/dmg.bmp");
                 a3->Visible=true;
                 a3->Left=10;
                 a3->Top=104;

                 a4->Picture->LoadFromFile("icons/attributes/dmg.bmp");
                 a4->Visible=true;
                 a4->Left=10;
                 a4->Top=128;

                 a5->Picture->LoadFromFile("icons/attributes/vitality.bmp");
                 a5->Visible=true;
                 a5->Left=11;
                 a5->Top=151;

                 a6->Picture->LoadFromFile("icons/attributes/armor.bmp");
                 a6->Visible=true;
                 a6->Left=10;
                 a6->Top=177;

                 a7->Picture->LoadFromFile("icons/attributes/armor.bmp");
                 a7->Visible=true;
                 a7->Left=10;
                 a7->Top=202;

                 a8->Picture->LoadFromFile("icons/attributes/shield.bmp");
                 a8->Visible=true;
                 a8->Left=10;
                 a8->Top=228;

                 a9->Picture->LoadFromFile("icons/attributes/aim.bmp");
                 a9->Visible=true;
                 a9->Left=11;
                 a9->Top=252;

                 a10->Picture->LoadFromFile("icons/attributes/pene.bmp");
                 a10->Visible=true;
                 a10->Left=10;
                 a10->Top=277;

                 


}
//---------------------------------------------------------------------------
//shows info about duration of elections
void __fastcall TFC_v5::Durationofelections1Click(TObject *Sender)
{
                  fameclose();
                  memo2close();
                  memo3close();
                  memo5close();


                 de->Visible=true;

                 ecopper->Height=200;
                 ecopper->Width=300;
                 ecopper->Top=347;
                 ecopper->Left=108;
                 ecopper->Lines->LoadFromFile("txt/electxt/copper.txt");
                 ecopper->Visible=true;

                 e1->Left=70;
                 e1->Top=495;
                 e1->Picture->LoadFromFile("icons/elections/ranger.bmp");
                 e1->Visible=true;

                 e2->Left=70;
                 e2->Top=445;
                 e2->Picture->LoadFromFile("icons/elections/chief ranger.bmp");
                 e2->Visible=true;

                 e3->Left=70;
                 e3->Top=388;
                 e3->Picture->LoadFromFile("icons/elections/speaker.bmp");
                 e3->Visible=true;

                 e4->Left=70;
                 e4->Top=325;
                 e4->Picture->LoadFromFile("icons/elections/director.bmp");
                 e4->Visible=true;




                 esilver->Height=200;
                 esilver->Width=300;
                 esilver->Top=347;
                 esilver->Left=463;
                 esilver->Lines->LoadFromFile("txt/electxt/silver.txt");
                 esilver->Visible=true;

                 e5->Left=422;
                 e5->Top=493;
                 e5->Picture->LoadFromFile("icons/elections/board member.bmp");
                 e5->Visible=true;

                 e6->Left=417;
                 e6->Top=439;
                 e6->Picture->LoadFromFile("icons/elections/constable.bmp");
                 e6->Visible=true;

                 e7->Left=417;
                 e7->Top=387;
                 e7->Picture->LoadFromFile("icons/elections/councillor.bmp");
                 e7->Visible=true;

                 e8->Left=417;
                 e8->Top=325;
                 e8->Picture->LoadFromFile("icons/elections/governor.bmp");
                 e8->Visible=true;


                 egold->Height=230;
                 egold->Width=380;
                 egold->Top=50;
                 egold->Left=250;
                 egold->Lines->LoadFromFile("txt/electxt/gold.txt");
                 egold->Visible=true;

                 e9->Left=204;
                 e9->Top=220;
                 e9->Picture->LoadFromFile("icons/elections/assistant deputy.bmp");
                 e9->Visible=true;

                 e10->Left=199;
                 e10->Top=160;
                 e10->Picture->LoadFromFile("icons/elections/deputy.bmp");
                 e10->Visible=true;

                 e11->Left=199;
                 e11->Top=100;
                 e11->Picture->LoadFromFile("icons/elections/marshal.bmp");
                 e11->Visible=true;

                 e12->Left=203;
                 e12->Top=30;
                 e12->Picture->LoadFromFile("icons/elections/sheriff.bmp");
                 e12->Visible=true;





}
//---------------------------------------------------------------------------
//shows history of calculations
void __fastcall TFC_v5::Historyoffamecalculations1Click(TObject *Sender)
{
          fameclose();
          memo2close();
          memo3close();
          declose();



                 Memo5->Align=alClient;
                 Memo5->Lines->LoadFromFile("txt/history.txt");
                 Memo5->Visible=true;
}
//---------------------------------------------------------------------------



void __fastcall TFC_v5::Button1Click(TObject *Sender)
{
      if(Famecalculation1->Checked==true)
      {
          if((Edit1->Text=="") || (Edit2->Text=="") || (Edit3->Text==""))
          ShowMessage("Enter numbers!");

            else
            {
                X=Edit1->Text;
                Y=Edit2->Text;
                D=Edit3->Text;
                Edit4->Text=calculate_fame_before_daily_lost(X,Y,D);
             }

      }

      if(Famecalculation2->Checked==true)
      {
              if((Edit1->Text=="") || (Edit2->Text=="") || (Edit3->Text==""))
          ShowMessage("Enter numbers!");


            else
            {
                X=Edit1->Text;
                Y=Edit2->Text;
                D=Edit3->Text;
                Edit4->Text=calculate_fame_after_daily_lost(X,Y,D);
            }
      }

      if(Famecalculation3->Checked==true)
      {         if((Edit1->Text=="") || (Edit2->Text=="") || (Edit3->Text==""))
          ShowMessage("Enter numbers!");

            else
            {
                X=Edit1->Text;
                Y=Edit2->Text;
                X1=Edit3->Text;

                Edit4->Text=calculate_prefered_amount_of_fame(X,Y,X1);
              }  

      }

}
//---------------------------------------------------------------------------




void __fastcall TFC_v5::FormCreate(TObject *Sender)
{

              FC_v5->Height=600;
              FC_v5->Width=900;
              Theme->Align=alClient;
                  picture();

                Edit1->Text="";
                Edit2->Text="";
                Edit3->Text="";

}
//---------------------------------------------------------------------------



void __fastcall TFC_v5::Timer1Timer(TObject *Sender)
{
picture();
}
//--------------------------------------------------------------------------


void __fastcall TFC_v5::Historyoffamecalculations2Click(TObject *Sender)
{
if(Application->MessageBox("Do you want to clear history?","Cleaning",
        MB_YESNO|MB_ICONQUESTION)==IDYES)
        {
         Memo1->Lines->SaveToFile("txt/history.txt");
        }
}
//---------------------------------------------------------------------------

