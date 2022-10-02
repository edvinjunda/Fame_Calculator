//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFC_v5 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Famecalculationafterdailylose1;
        TMenuItem *Historyoffamecalculations;
        TMenuItem *Informationaboutyieldsanddailygainedfame1;
        TMenuItem *Valuesofattributes1;
        TMenuItem *Famecalculation2;
        TMenuItem *Famecalculation1;
        TMenuItem *Famecalculation3;
        TMenuItem *Historyoffamecalculations1;
        TMenuItem *Historyoffamecalculations2;
        TMenuItem *Durationofelections1;
        TButton *Button1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TMenuItem *Exit1;
        TMemo *Memo5;
        TImage *a1;
        TImage *a2;
        TImage *a3;
        TImage *a5;
        TImage *a6;
        TImage *a4;
        TImage *a7;
        TImage *a8;
        TImage *a9;
        TImage *e2;
        TImage *e3;
        TImage *e4;
        TImage *e5;
        TImage *e6;
        TImage *e7;
        TImage *e8;
        TImage *e9;
        TImage *e10;
        TImage *e11;
        TImage *e12;
        TImage *percent;
        TImage *claim;
        TImage *gate;
        TImage *fame;
        TImage *sfame1;
        TImage *e1;
        TImage *Theme;
        TImage *excellent;
        TImage *very_good;
        TImage *good;
        TMemo *ecopper;
        TMemo *egold;
        TMemo *esilver;
        TLabel *de;
        TImage *sfame2;
        TImage *sfame3;
        TLabel *va1;
        TLabel *va2;
        TLabel *va3;
        TLabel *va4;
        TLabel *va5;
        TLabel *va6;
        TLabel *va8;
        TLabel *va9;
        TLabel *va10_1;
        TLabel *va;
        TTimer *Timer1;
        TLabel *ti;
        TLabel *ti1;
        TLabel *ti2;
        TLabel *ti3;
        TLabel *ti4;
        TLabel *ti5;
        TLabel *ti7;
        TLabel *ti6;
        TLabel *ti9;
        TLabel *ti13;
        TLabel *ti11;
        TLabel *ti12;
        TLabel *ti8;
        TLabel *ti10;
        TLabel *ti14;
        TLabel *ti15;
        TLabel *ti16;
        TMemo *Edit1;
        TMemo *Edit2;
        TMemo *Edit3;
        TMemo *Edit4;
        TMemo *Memo1;
        TMemo *Memo2;
        TLabel *va10_2;
        TLabel *va7;
        TImage *a10;
        void __fastcall Famecalculation2Click(TObject *Sender);
        void __fastcall Famecalculation3Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Informationaboutyieldsanddailygainedfame1Click(
          TObject *Sender);
        void __fastcall Valuesofattributes1Click(TObject *Sender);
        void __fastcall Durationofelections1Click(TObject *Sender);
        void __fastcall Historyoffamecalculations1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Famecalculation1Click(TObject *Sender);
        void __fastcall Historyoffamecalculations2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFC_v5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFC_v5 *FC_v5;
//---------------------------------------------------------------------------
#endif
