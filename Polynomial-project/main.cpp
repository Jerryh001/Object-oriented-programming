#include"Polynomial.h"
using namespace std;
void printframe();//框架
int showlist(string,int,int);//顯示選單及選擇
void mainmenu();//主選單
void polyin(Polynomial&,int);//輸入介面
void ari_type_choose();//四則運算選擇介面
void devmenu();//微積分選單
void root_ans_choose();//求解介面
bool yes_no_choose();//選擇是否
void you_cant_do_this();//錯誤訊息顯示
Polynomial poly_current;
int main()
{
    mainmenu();
}

void printframe()
{
    gotoxy(0,0);
    cout<<" ╔═════════════════════════════════════╗"<<endl
        <<" ║                        第九組　多項式類別建置                            ║"<<endl
        <<" ╠═════════════════════════════════════╣"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ║                                                                          ║"<<endl
        <<" ╚═════════════════════════════════════╝"<<endl;
    gotoxy(20,22);
    cout<<"目前的多項式：";
    if(!poly_current.isempty())
    {
        cout<<poly_current;
    }else
    {
        cout<<"沒有";
    }
}
int showlist(string menu[],int item,int blank)
{
    switch(blank)//顯示"選項"
    {
    case 0:
        for(int i=0;i<item;i++)
        {
            gotoxy(39-menu[i].length()/2,6+i*3);
            cout<<menu[i];
        }
        break;
    default:
        for(int i=0;i<item;i++)
        {
            gotoxy(blank,6+i*3);
            cout<<menu[i];
        }
    }
    int choose=0;
    bool deside=false;
    while(!deside)//選擇
    {
        for(int i=0;i<item;i++)
        {
            gotoxy(18,6+i*3);
            if(i==choose)
            {
                cout<<'';
            }else
            {
                cout<<" ";
            }
        }
        switch(getch())
        {
        case VK_RETURN://enter
            deside=true;
            break;
        case 0x50://下
            choose++;
            break;
        case 0x48://上
            choose--;
            break;
        }
        if(choose<0)choose+=item;
        choose%=item;
    }
    return choose;
}
void mainmenu()
{
    printframe();
    string menu[]={"輸入多項式","四則運算","微積分","求出多項式的根/解","結束"};
    switch(showlist(menu,5,20))
    {
    case 0:
        polyin(poly_current,0);
        mainmenu();
        break;
    case 1:
        ari_type_choose();
        break;
    case 2:
        devmenu();
        break;
    case 3:
        root_ans_choose();
        break;
    case 4:
        return;
    }
}
void devmenu()
{
    printframe();
    if(poly_current.isempty())//尚未輸入多項式
    {
        you_cant_do_this();
        mainmenu();
        return;
    }
    show_hint_word("你想把這個多項式......",3);
    string menu[]={"微分","積分","上一頁"};
    int choose=showlist(menu,3,0);
    if(choose==2)
    {
        mainmenu();
        return;
    }
    Polynomial temp=poly_current;
    switch(choose)
    {
    case 0:
        temp.derivative();
        break;
    case 1:
        printframe();
        show_hint_word("請輸入積分常數項C(可為0)",3);
        gotoxy(25,4);
        int c;
        cin>>c;
        temp.integral(c);
        break;
    }
    printframe();
    show_hint_word("把這個多項式"+menu[choose]+"之後會變成",3);
    gotoxy(26,5);
    cout<<temp;
    show_hint_word("要將這個結果替換掉目前的多項式嗎?",7);
    if(yes_no_choose())
    {
        poly_current=temp;
    }
    mainmenu();
    return;
}
void root_ans_choose()
{
    printframe();
    if(poly_current.isempty())//尚未輸入多項式
    {
        you_cant_do_this();
        mainmenu();
        return;
    }
    show_hint_word("請輸入多項式 f(x)=y 的y值(可為零)",3);
    int y;
    gotoxy(24,5);
    cin>>y;
    printframe();
    show_hint_word("請輸入兩個數表示想搜尋的範圍",3);
    int a,b;
    gotoxy(24,5);
    cin>>a>>b;
    printframe();
    show_hint_word("請問你想尋找到小數點第幾位",3);
    int t;
    gotoxy(24,5);
    cin>>t;
    printframe();
    show_hint_word("當y=",3);
    cout<<y;
    show_hint_word("這個方程式的解有可能是",4);
    search_answer(poly_current,t,y,min(a,b),max(a,b));
    show_hint_word("要重新尋找嗎？",10);
    if(yes_no_choose())
    {
        root_ans_choose();
    }
    mainmenu();
}
void polyin(Polynomial& poly,int type)
{
    again:
    Polynomial polytemp;
    printframe();
    if(type==0)//判斷呼叫者而顯示不同說明
    {
        show_hint_word("請輸入以x為變數的多項式，如 3x^4-5x+1",3);
    }

    else
    {
        show_hint_word("請輸入要與當前多項式運算的式子",3);
    }
    gotoxy(21,5);
    cin>>polytemp;
    printframe();
    show_hint_word("請問你輸入的是這個多項式嗎?",3);
    gotoxy(26,5);
    cout<<polytemp;
    if(yes_no_choose())
    {
        poly=polytemp;
        return;
    }else
    {
        goto again;
    }
}
bool yes_no_choose()
{
    gotoxy(20,15);
    cout<<"是";
    gotoxy(20,17);
    cout<<"否";
    bool choose=true;
    bool deside=false;
    while(!deside)
    {
        for(int i=0;i<2;i++)
        {
            gotoxy(19,15+i*2);
            if(i!=choose)
            {
                cout<<'';
            }else
            {
                cout<<" ";
            }
        }
        switch(getch())
        {
        case VK_RETURN:
            deside=true;
            break;
        case 0x48://上
        case 0x50://下
            choose=!choose;
            break;
        }
    }
    return choose;

}
void you_cant_do_this()
{
    show_hint_word("還沒有輸入多項式，無法運算！",7);
    gotoxy(25,9);
    system("PAUSE");
}
void ari_type_choose()
{
    printframe();
    if(poly_current.isempty())
    {
        you_cant_do_this();
        mainmenu();
        return;
    }
    show_hint_word("請選擇要對當前多項式進行的運算",3);
    string menu[]={"加法","減法","乘法","除法","上一頁"};
    int arichoose=showlist(menu,5,0);
    if(arichoose==4)
    {
        mainmenu();
        return;
    }
    Polynomial poly2;
    polyin(poly2,1);
    printframe();
    show_hint_word("把這兩個式子進行"+menu[arichoose]+"運算之後得到的結果是",3);
    Polynomial tempans;
    switch(arichoose)
    {
    case 0:
        tempans=poly_current+poly2;
        break;
    case 1:
        tempans=poly_current-poly2;
        break;
    case 2:
        tempans=poly_current*poly2;
        break;
    case 3:
        tempans=poly_current/poly2;
        break;
    }
    gotoxy(20,5);
    cout<<tempans;
    if(arichoose==3)
    {
        gotoxy(20,6);
        Polynomial remain=poly_current%poly2;
        if(!remain.isempty())
        {
            cout<<"餘式是"<<remain;
        }
    }
    show_hint_word("要將這個結果替換掉目前的多項式嗎?",7);
    if(yes_no_choose())
    {
        poly_current=tempans;
    }
    mainmenu();
}
