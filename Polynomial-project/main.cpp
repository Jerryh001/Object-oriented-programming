#include"Polynomial.h"
using namespace std;
void printframe();//�ج[
int showlist(string,int,int);//��ܿ��ο��
void mainmenu();//�D���
void polyin(Polynomial&,int);//��J����
void ari_type_choose();//�|�h�B���ܤ���
void devmenu();//�L�n�����
void root_ans_choose();//�D�Ѥ���
bool yes_no_choose();//��ܬO�_
void you_cant_do_this();//���~�T�����
Polynomial poly_current;
int main()
{
    mainmenu();
}

void printframe()
{
    gotoxy(0,0);
    cout<<" ������������������������������������������������������������������������������"<<endl
        <<" ��                        �ĤE�ա@�h�������O�ظm                            ��"<<endl
        <<" ������������������������������������������������������������������������������"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ��                                                                          ��"<<endl
        <<" ������������������������������������������������������������������������������"<<endl;
    gotoxy(20,22);
    cout<<"�ثe���h�����G";
    if(!poly_current.isempty())
    {
        cout<<poly_current;
    }else
    {
        cout<<"�S��";
    }
}
int showlist(string menu[],int item,int blank)
{
    switch(blank)//���"�ﶵ"
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
    while(!deside)//���
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
        case 0x50://�U
            choose++;
            break;
        case 0x48://�W
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
    string menu[]={"��J�h����","�|�h�B��","�L�n��","�D�X�h��������/��","����"};
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
    if(poly_current.isempty())//�|����J�h����
    {
        you_cant_do_this();
        mainmenu();
        return;
    }
    show_hint_word("�A�Q��o�Ӧh����......",3);
    string menu[]={"�L��","�n��","�W�@��"};
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
        show_hint_word("�п�J�n���`�ƶ�C(�i��0)",3);
        gotoxy(25,4);
        int c;
        cin>>c;
        temp.integral(c);
        break;
    }
    printframe();
    show_hint_word("��o�Ӧh����"+menu[choose]+"����|�ܦ�",3);
    gotoxy(26,5);
    cout<<temp;
    show_hint_word("�n�N�o�ӵ��G�������ثe���h������?",7);
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
    if(poly_current.isempty())//�|����J�h����
    {
        you_cant_do_this();
        mainmenu();
        return;
    }
    show_hint_word("�п�J�h���� f(x)=y ��y��(�i���s)",3);
    int y;
    gotoxy(24,5);
    cin>>y;
    printframe();
    show_hint_word("�п�J��Ӽƪ�ܷQ�j�M���d��",3);
    int a,b;
    gotoxy(24,5);
    cin>>a>>b;
    printframe();
    show_hint_word("�аݧA�Q�M���p���I�ĴX��",3);
    int t;
    gotoxy(24,5);
    cin>>t;
    printframe();
    show_hint_word("��y=",3);
    cout<<y;
    show_hint_word("�o�Ӥ�{�����Ѧ��i��O",4);
    search_answer(poly_current,t,y,min(a,b),max(a,b));
    show_hint_word("�n���s�M��ܡH",10);
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
    if(type==0)//�P�_�I�s�̦���ܤ��P����
    {
        show_hint_word("�п�J�Hx���ܼƪ��h�����A�p 3x^4-5x+1",3);
    }

    else
    {
        show_hint_word("�п�J�n�P��e�h�����B�⪺���l",3);
    }
    gotoxy(21,5);
    cin>>polytemp;
    printframe();
    show_hint_word("�аݧA��J���O�o�Ӧh������?",3);
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
    cout<<"�O";
    gotoxy(20,17);
    cout<<"�_";
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
        case 0x48://�W
        case 0x50://�U
            choose=!choose;
            break;
        }
    }
    return choose;

}
void you_cant_do_this()
{
    show_hint_word("�٨S����J�h�����A�L�k�B��I",7);
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
    show_hint_word("�п�ܭn���e�h�����i�檺�B��",3);
    string menu[]={"�[�k","��k","���k","���k","�W�@��"};
    int arichoose=showlist(menu,5,0);
    if(arichoose==4)
    {
        mainmenu();
        return;
    }
    Polynomial poly2;
    polyin(poly2,1);
    printframe();
    show_hint_word("��o��Ӧ��l�i��"+menu[arichoose]+"�B�⤧��o�쪺���G�O",3);
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
            cout<<"�l���O"<<remain;
        }
    }
    show_hint_word("�n�N�o�ӵ��G�������ثe���h������?",7);
    if(yes_no_choose())
    {
        poly_current=tempans;
    }
    mainmenu();
}
