/*  ����: BOYWIN.H
    ��;: BOYWINDOWS 1.1 ϵͳ�⺯��ͷ�ļ�.
    ����: ����ռ���������Ⱥ ( Illusion Space Software Design ).
    ����: 1994 �� 1 ��.
    ��Ȩ: ����ռ���������Ⱥ. ( һ��Ȩ������! )
    ע��: ����ʹ�ô�����ģʽ���б���.
*/

#if !defined(__LARGE__) && !defined(__HUGE__)
   #error BoyWindows Library will run only in LARGE or HUGE memory model.
#endif

#if !defined(__BOY_WIN_H)
#define __BOY_WIN_H

/* �������ƶ���ı��Сʱ,�� BOY_ALL_TEST �������ظ��¼�ֵ*/
# define WindowsChange -9
# define WindowsMove  -8
# define WindowsClose -7

/* ������ı���󳤶� */
#define MaxInputTextLen 128

/* Ŀ¼���ı���󳤶� */
#define MaxPath        80

/* �ı���󳤶� */
#define MaxTextLen     81

/* ���ڸ߶���Сֵ */
extern int WINDOWS_Minh;
extern int WINDOWS_Minl;
extern int MAX_X,MAX_Y;
extern int ReDrawWindows;
extern char Serial[15];
/*
   �ر�ע��: �˱������ں������ʹ��У��.
   �����ڳ���ʼʱ, ���������óɺ���������к�.
   ��: strcpy(Serial,"018-2512950056");
   ���У�����, �����Զ��˳�.
 */

/* ϵͳ�¼��ṹ */
typedef struct {
	int key;    /* ������ֵ */
	int keys;   /* ��չ��ֵ */
	int mousex; /* �������� */
	int mousey; /* ��������� */
	int button; /* ��갴��״̬ (1:������� 2:�Ҽ����� 4:�м�����) */
       } TEST;

/* ���ڲ���˳��ṹ */
typedef struct {
	int type; /* �������ͺ� */
	int num;  /* ����˳��� */
       } TYPE;

/* �����뷨���ڱ�������, ��ֵΪһ. */
extern int _CHINESE;

/* ����ʼ���ɹ�, ��ֵΪһ, ����Ϊ��. */
extern char _MOUSE;

/* ��ǰ�������״��. */
extern int MOUSE_TYPE_TAB;

/* ϵͳ·���ṹ */
typedef struct _setup_boy{
	char ovl[MaxPath];        /* ȫƴ,��ƴ���, BGI */
	char font16[MaxPath];     /* 16�����ּ�Ӣ���ֿ� */
	char font24[MaxPath];     /* 24�����ֿ� */
	char boyswp[MaxPath];     /* ͼ����ʱ�����ļ� */
       }SETPATH;
extern SETPATH BOYPATH;

/**************************�����ṹ����************************************/

/* ��ά�����ṹ���� (����ֵΪ 1) */
typedef struct _key3d {
	int x1,y1;              /* �������Ͻ����� */
	int x2,y2;              /* �������½����� */
	char ico[MaxPath];      /* ������ͼ���ļ��� */
	int icox,icoy;          /* ͼ���ڰ����е����� */
	int enable;             /* �Ƿ��������� */
	int font;               /* ������ʹ�ú������� (0:�� 1:��) */
	int h;                  /* ������ά�߶� (0-8) */
	char text[MaxTextLen];  /* �����к������� */
	int hotkey;             /* �ȼ� */
	int fontchar;           /* ������άЧ�� (0:���� 1:͹ 2:��) */
	int bkcolor;            /* ��������ɫ */
        int style;              /* ��ťЧ�� 2.0+ */
	int index;              /* ����ֵ */
       }KEY3D;

/* �������ṹ���� (����ֵΪ 2) */
typedef struct _scroll{
	int x1,y1;              /* �����������Ͻ����� */
	int x2,y2;              /* �����������½����� */
	int bkcolor;            /* ����������ɫ */
	int mx;                 /* �߼����ֵ */
	int mi;                 /* �߼���Сֵ */
	int bm;                 /* С�Ķ����� */
	int sm;                 /* ��Ķ����� */
	int v;                  /* ��ǰ�������߼�λ�� */
	int pd;                 /* �����ж�(0:�� 1:��) */
	int index;              /* ����ֵ */
	int enable;             /* �Ƿ��������� */
	int boxbkcolor;         /* ��������ɫ   */
       }SCROLL;

/* ��ǩ�ṹ���� (����ֵΪ 3) */
typedef struct _label{
	int x1,y1;              /* ��ʼ����                                 */
	int x2,y2;              /* ��������                                 */
	int alignment;          /* �ı����з�ʾ(0:�� 1:�� 2:��)             */
	int board;              /* �߿�����(0:�� 1:��)                      */
	int boardcolor;         /* �߿���ɫ(0-15)                           */
	int textfont;           /* ��������(0:16�������� 1:16������       */
				/* 2:24��������� 3:24�������� 4:24������ */
				/* 5:24������� 6:12��������� 7:12�������� */
				/* 8:12������ 9:12�������)               */
	int textcolor;          /* ����������ɫ(0-15)                       */
	int textstyle;          /* ��������(0:���� 1:�� 2:͹ 3:� 4:��͹) */
	int labelbkcolor;       /* ����ɫ(0-15)                             */
	int  hotkey;            /* �ȼ�                                     */
	int  index;             /* ����ֵ                                   */
	int  enable;            /* �Ƿ���������                             */
	char text[MaxTextLen];  /* ����                                     */
	int small;              /* (����)                                   */
	char smallfontname[MaxPath]; /* (����)                              */
       } LABEL;

/*��ܽṹ���� (����ֵΪ 4) */
typedef struct _frame{
	int x1,y1;              /* ��ʼ����                      */
	int x2,y2;              /* ��������                      */
	int type;               /* ����ֵ                        */
	char text[MaxTextLen];  /* �����ı�                      */
	int textcolor;          /* ���ֵ���ɫ                    */
	int font;               /* ��������                      */
	int bkcolor;            /* ������ɫ                      */
	int alignment;          /* �ı����з�ʾ(0:�� 1:�� 2:��)  */
	int enable;             /* �Ƿ���������                  */
       }FRAME;

/* �����ṹ���� (����ֵΪ 5) */
typedef struct _inputbox{
	int x1,y1;              /* ��ʼ����                           */
	int maxchar;            /* ������������ַ���                 */
	int password;           /* �Ƿ�����������                     */
	int maxl;               /* �����ַ�������󳤶�               */
	int board;              /* �߿�����(0:�� 1:��)                */
	int boardcolor;         /* �߿���ɫ(0-15)                     */
	int textfont;           /* ��������(0:16�������� 1:16������)*/
	int textcolor;          /* ����������ɫ(0-15)                 */
	int textbkcolor;        /* �������屳����ɫ(0-15)             */
	int inputboxbkcolor;    /* ����ɫ(0-15)                       */
	int  sels;              /* ѡ�е��ַ���ʼλ��                 */
	int  seln;              /* ѡ�е��ַ���                       */
	int  enable;            /* �Ƿ���������(0:�� 1:��)            */
	int  index;             /* ����ֵ                             */
	int  hotkey;            /* �ȼ�                               */
	char text[MaxInputTextLen];       /*����                      */
	char seltext[MaxInputTextLen];    /*��ѡ����                  */
	int  point;             /* (����)                             */
	int  startline;         /* (����)                             */
       } INPUTBOX;

/* ��ѡť�ṹ���� (����ֵΪ 6) */
typedef struct _option{
	int x1,y1;              /* ��ʼ����                       */
	char text[MaxTextLen];  /* ��ʾ����                       */
	int textcolor;          /* ������ɫ                       */
	int enable;             /* �Ƿ���������(0:�� 1:��)        */
	int hotkey;             /* �ȼ�                           */
	int font;               /* ��������                       */
	int bkcolor;            /* ��������ɫ                     */
	int YN;                 /* ��ǰ�Ƿ�ѡ��                 */
	int type;               /* ������ʽ (Ϊ 0 ��Ϊ��ťʽ)     */
	char bmpname1[MaxPath]; /* ͼ���ļ��� (������ʽΪ 0 ʱ)   */
	int index;
	int piclongx;
	int piclongy;
       }OPTION;

/* ��ѡť�ṹ���� (����ֵΪ 7) */
typedef struct boy_check{
	 int x1,y1;             /* ��ʼ����                      */
	 char text[MaxTextLen]; /* ��ʾ����                      */
	 int textcolor;         /* ������ɫ                      */
	 int enable;            /* ��ǰ�Ƿ񱻼���                */
	 int hotkey;            /* �ȼ�                          */
	 int font;              /* ��������                      */
	 int bkcolor;           /* ��������ɫ                    */
	 int YN;                /* ��ǰ�Ƿ�ѡ��                */
	 int type;              /* ������ʽ (Ϊ 0 ��Ϊ��ťʽ)    */
	 char filename[MaxPath];/* ͼ���ļ��� (������ʽΪ 0 ʱ)  */
	 int index;
	}CHECK;

/* ͼ��ṹ���� (����ֵΪ 8) */
typedef struct _icon{
	int x1,y1;              /* ��ʼ����    */
	int index;              /* ����ֵ      */
	char name[MaxPath];     /* ͼ���ļ���  */
       }ICON;

/* ͼ�νṹ���� (����ֵΪ 9) */
typedef struct _pic{
	int x1,y1;              /* ��ʼ����    */
	char name[MaxPath];     /* ͼ���ļ���  */
       }PICTURE;

/* ��άЧ���ṹ (����ֵΪ 10) */
typedef struct bar3d{
	int x1,y1;              /* ��ʼ����    */
	int x2,y2;              /* ����ʼ����  */
	int hight,space;        /* �߶������  */
	int type;               /* ������ʽ    */
	} BAR3D;

 /*�Ӽ����ṹ���� (����ֵΪ 11) */
 typedef struct _adddec{
	 int x,y;               /* �����Ӽ����ĺ������� */
	 int v;                 /* ��ǰֵ               */
	 int max;               /* ���ֵ               */
	 int min;               /* ��Сֵ               */
	 int bkcolor;           /* ��������ɫ           */
	 int index;             /* ����ֵ               */
	 int enable;            /* �Ƿ��������         */
	}ADDDEC;

/* �б���ṹ���� (����ֵΪ 12) */
typedef struct {
	int x1,y1;              /* ��ʼ����                           */
	int x2,y2;              /* (����)                             */
	int len,line;           /* �б���������ʾ�ַ����ĳ���, ������ */
	int to;                 /* ��ǰ�Ĺ�������λ��                 */
	int top,botton;         /* (����)                             */
	int enable;             /* �Ƿ���������                       */
	int textcolor;          /* ����ɫ��                           */
	int bkcolor;            /* ����ɫ��                           */
	int index;              /* ����ֵ                             */
	int sl,tl;              /* �б���������ÿ���               */
	char *text;             /* �б��ַ�������                     */
       }LISTED;

/* ��Ͽ�ṹ���� (����ֵΪ 13) */
typedef struct {
	int x1,y1;              /* ��Ͽ�ĺ�������                */
	int x2,y2;              /* (����)                          */
	int len;                /* ��Ͽ�����������ʾ�ַ����ĳ���  */
	int line;               /* ��Ͽ���������                  */
	int to;                 /* ��ǰ�Ĺ�������λ��              */
	int top,botton;         /* (����)                          */
	int enable;             /* �Ƿ���������                    */
	int type;               /* �Ƿ�Ϊ����                      */
	int input;              /* �Ƿ��������붨��                */
	int textcolor;          /* ����ɫ��                        */
	int bkcolor;            /* ����ɫ��                        */
	int sl,tl;              /* �б���������ÿ���            */
	int index;              /* ����ֵ                          */
	int index2;             /* (����)                          */
	char name[MaxTextLen];  /* ��������                        */
	char *text;             /* �б��ַ�������ָ��              */
       }COMBO;

/* ͼ���߽ṹ���� (����ֵΪ 14) */
typedef struct _line{
	int x1,y1;              /* ��ʼ����   */
	int x2,y2;              /* ��������   */
	int color;              /* ��ɫ       */
	int type;               /* ������ʽ   */
       }LINE;

/* �������б���ṹ���� (����ֵΪ 15) */
typedef struct {
	int x1,y1;              /* ��ʼ����                       */
	int x2,y2;              /* (����)                         */
	int len,line;           /* �������б���������ʾ�ַ������� */
	int to;                 /* ��ǰ�Ĺ�������λ��             */
	int top,botton;         /* (����)                         */
	int enable;             /* �Ƿ���������                   */
	int textcolor;          /* ����ɫ��                       */
	int bkcolor;            /* ����ɫ��                       */
	int index;              /* ����ֵ                         */
	char drive[3];          /* ����������                     */
       }DRIVELIST;

/* �ļ��б���ṹ���� (����ֵΪ 16)  */
typedef struct {
	int x1,y1;              /* ��ʼ����                               */
	int x2,y2;              /* (����)                                 */
	int len,line;           /* �ļ��б���������ʾ�ַ����ĳ���, ������ */
	int to;                 /* ��ǰ�Ĺ�������λ��                     */
	int top,botton;         /* (����)                                 */
	int enable;             /* �Ƿ���������                           */
	int textcolor;          /* ����ɫ��                               */
	int bkcolor;            /* ����ɫ��                               */
	int index;              /* ����ֵ                                 */
	int sl,tl;              /* �ļ��������������±�                   */
	char path[MaxPath];     /* �ļ�·����                             */
	char filetype[MaxTextLen];  /*�ļ�������                          */
	char *filename;         /* �ļ�������������ָ��,����Ϊ sl*tl ���ַ�*/
       }FILELIST;

/* Ŀ¼�б���ṹ���� (����ֵΪ 17) */
typedef struct {
	int x1,y1;              /* Ŀ¼�б���ĺ�������                   */
	int x2,y2;              /* (����)                                 */
	int len,line;           /* Ŀ¼�б���������ʾ�ַ����ĳ���, ������ */
	int to;                 /* ��ǰ�Ĺ�������λ��                     */
	int top,botton;         /* (����)                                 */
	int enable;             /* �Ƿ���������                           */
	int textcolor;          /* ����ɫ��                               */
	int bkcolor;            /* ����ɫ��                               */
	int index;              /* ����ֵ                                 */
	char path[MaxPath];     /* Ŀ¼·����                             */
       } DIRLIST;

/* ���ڲ˵��ṹ���� (����ֵΪ 18) */
typedef struct _menu{
	char name[MaxTextLen]; /* �˵�����          */
	int hotkey;            /* ����˵��ȼ�      */
	int pd;                /* ��ǰ�Ƿ���������  */
	int type;              /* �˵��Ĳ��        */
	int font;              /* �˵�����          */
	int index;             /* ���ڲ���          */
	int x,y;               /* (����)            */
        int active;            /* (����)            */
       }MENU;

/* ���ڽṹ���� */
typedef struct _window{
	int x1,y1;             /* ���ڶ�������Ͻ����� */
	int x2,y2;             /* ���ڶ�������½����� */
	char text[MaxTextLen]; /* ���ڱ��������ַ����� */
	int winbkcolor;        /* ���ڱ���ɫ           */
	int bkcolor;           /* ���ڱ��ⱳ��ɫ       */
	int mouse;             /* ������������״     */
	int font;              /* ����16������������   */
	int enable;            /* �����Ƿ񱻼���       */
	int wintype;           /* ���ڱ߼�����         */
	int textcolor;         /* ���ڱ����ַ���ɫ     */
	int texttab;           /* �����־�             */
	int wincolor;          /* ����߿�ɫ           */
	int menusl;            /* ���ڲ˵�����         */
        int menubkcolor;       /* ���ڲ˵�������ɫ     */
        int menutextbkcolor;   /* ���ڲ˵�����ɫ       */
        int menutextcolor;     /* ���˵�������ɫ       */
        int menubktextcolor;   /* ���ڲ˵�����ǰ��ɫ   */
        int menudisablecolor;  /* ���ڲ˵��Ǽ�������ɫ */
        int menuframecolor;    /* ���ڲ˵��߿�ɫ       */
        int menushadow;        /* ���ڲ˵���Ӱ(0:�� 1:��)*/
       long bkpic;             /* (����)               */

	KEY3D *key;            /* (����)               */
	SCROLL *scl;           /* (����)               */
	LABEL *lab;            /* (����)               */
	FRAME *frm;            /* (����)               */
	INPUTBOX *inp;         /* (����)               */
	OPTION *opti;          /* (����)               */
	CHECK *chk;            /* (����)               */
	ICON *icn;             /* (����)               */
	PICTURE *pic;          /* (����)               */
	BAR3D *b3d;            /* (����)               */
	ADDDEC *ad;            /* (����)               */
	LISTED *lst;           /* (����)               */
	COMBO *cmb;            /* (����)               */
	LINE *line;            /* (����)               */
	DRIVELIST *drv;        /* (����)               */
	DIRLIST *dir;          /* (����)               */
	FILELIST *fil;         /* (����)               */
	MENU *menu;            /* (����)               */
      }WINDOWS;

/**********************************************************************/
/* ע:����ע��(����)�����Ϊϵͳ�ڲ�ʹ��, �û�����Ҫ������в���.     */
/**********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************��������***********************************/

/* 1. ��ά���� */
  void CREATE_BOY_KEY3D(KEY3D *);
  int  BOY_KEY3D_TEST(KEY3D *,TEST *);
  int  BOY_KEY3D_TESTm(KEY3D *keys,TEST *test);
  void BOY_KEY3D_DISABLE(KEY3D *);
  void BOY_KEY3D_ENABLE(KEY3D *);

/* 2. ������ */
  void CREATE_BOY_SCROLL(SCROLL *);
  int  BOY_SCROLL_TEST(SCROLL *scrolls, TEST *keys);
  int  BOY_SCROLL_TESTm(SCROLL *scrolls, TEST *keys);
  void BOY_SCROLL_DISABLE(SCROLL *);
  void BOY_SCROLL_ENABLE(SCROLL *);
  void REDRAW_BOY_SCROLL(SCROLL *scl,int newv);

/* 3. ��ǩ */
  void CREATE_BOY_LABEL(LABEL *);
  int  BOY_LABEL_TEST(LABEL *l, TEST *keys);

/* 4. ��� */
  void CREATE_BOY_FRAME(FRAME *);

/* 5. ����� */
  void CREATE_BOY_INPUTBOX(INPUTBOX *,int type);
  void BOY_INPUTBOX_ENABLE(INPUTBOX *);
  void BOY_INPUTBOX_DISABLE(INPUTBOX *);
  int  BOY_INPUTBOX_TEST(INPUTBOX *in, TEST *keys);
  int  BOY_INPUTBOX_TESTm(INPUTBOX *in, TEST *keys);

/* 6. ��ѡť */
  void CREATE_BOY_OPTION(OPTION *);
  int  BOY_OPTION_TEST(WINDOWS *ws,OPTION *opti,TYPE *tp,TEST *test,int total);
  int  BOY_OPTION_TESTm(WINDOWS *ws,OPTION *opti,TYPE *tp,TEST *test,int total);
  void BOY_OPTION_ENABLE(OPTION *opti);
  void BOY_OPTION_DISABLE(OPTION *opti);
  int  FRAME_OPTION(FRAME *f,OPTION *o); /*���ݴ��� */
  void BOY_OPTION_CLEAN (OPTION *opti); /*�����ǰ��ѡ����λ*/
  void BOY_OPTION_DRAW (OPTION *opti);  /*�����ǰ��ѡ����λ*/
  void BOY_OPTION_CLEANHELP(OPTION *opti);

/* 7. ��ѡť */
  void CREATE_BOY_CHECK(CHECK *);
  int  BOY_CHECK_TEST(CHECK *check,TEST *test);
  int  BOY_CHECK_TESTm(CHECK *check,TEST *test);
  void BOY_CHECK_ENABLE(CHECK *);
  void BOY_CHECK_DISABLE(CHECK *);
  void BOY_CHECK_DRAW(CHECK *check);
  void BOY_CHECK_CLEAN(CHECK *check);

/* 8. ͼ�� */
  void CREATE_BOY_ICON(ICON *icn);
  int  BOY_ICON_TEST(ICON *icn,TEST *test);

/* 9. ͼ�� */
  void CREATE_BOY_PICTURE(PICTURE *pic);

/* 10.��άЧ���ṹ */
  void CREATE_BOY_BAR3D(BAR3D *);

/* 11.�Ӽ��� */
  void CREATE_BOY_ADDDEC(ADDDEC *);
  int  BOY_ADDDEC_TEST(ADDDEC *,TEST *);
  void BOY_ADDDEC_ENABLE(ADDDEC *);
  void BOY_ADDDEC_DISABLE(ADDDEC *);
  void ins_adddec(ADDDEC *);

/* 12.�б��� */
  void CREATE_BOY_LISTED(LISTED *);
  int  BOY_LISTED_TEST(LISTED *,TEST *);
  void BOY_LISTED_DISABLE(LISTED *lst);
  void BOY_LISTED_ENABLE(LISTED *lst);

/* 13.��Ͽ� */
  void CREATE_BOY_COMBO(COMBO *);
   int BOY_COMBO_TEST(COMBO *, TEST *);
   int BOY_COMBO_TESTm(COMBO *, TEST *);
  void BOY_COMBO_DISABLE(COMBO *);
  void BOY_COMBO_ENABLE(COMBO *);

/* 14.ͼ���� */
  void CREATE_BOY_LINE(LINE *ln);

/* 15.�������б��� */
  void CREATE_BOY_DIRLIST(DIRLIST *);
   int BOY_DIRLIST_TEST(DIRLIST *, TEST *);
  void BOY_DIRLIST_ENABLE(DIRLIST *);
  void BOY_DIRLIST_DISABLE(DIRLIST *);

/* 16.�ļ��б��� */
  void CREATE_BOY_FILELIST(FILELIST *flst);
   int BOY_FILELIST_TEST(FILELIST *,TEST *);
  void BOY_FILELIST_DISABLE(FILELIST *flst);
  void BOY_FILELIST_ENABLE(FILELIST *flst);

/* 17.Ŀ¼�б��� */
  void CREATE_BOY_DRIVELIST(DRIVELIST *);
   int BOY_DRIVELIST_TEST(DRIVELIST *, TEST *);
   int BOY_DRIVELIST_TESTm(DRIVELIST *, TEST *);
  void BOY_DRIVELIST_ENABLE(DRIVELIST *);
  void BOY_DRIVELIST_DISABLE(DRIVELIST *);

/* 18.���ڲ˵� */
  void CREATE_BOY_MENU(MENU *menus,WINDOWS *wins);
  int  BOY_MENU_TEST(MENU *menus,WINDOWS *wins,TEST *test);
  void CLOSE_BOY_MENU(MENU *menus,WINDOWS *wins);
  void BOY_MENU_ENABLE(MENU *menus,WINDOWS *wins);
  void BOY_MENU_DISABLE(MENU *menus,WINDOWS *wins);

/* 19.���� */
  void CREATE_BOY_WINDOWS(WINDOWS *);
  void CREATE_WINDOWS_ALL(WINDOWS *wnd,TYPE *type,int total, int tab);
  int  BOY_WINDOWS_TEST (WINDOWS *wins, TEST *test, int total, int tab, TYPE *type);
  int  BOY_ALL_TEST(WINDOWS *w, TEST *keys, int total, int *tab, TYPE *type);
  void REDRAW_WINDOWS_ALL(WINDOWS *wnd,TYPE *type,int total, int tab, int dx, int dy);
  void CLOSE_BOY_WINDOWS(WINDOWS *);
  void BOY_WINDOWS_DISABLE(WINDOWS *wins);
  void BOY_WINDOWS_ENABLE(WINDOWS *wins);
  void RestoreWindows(WINDOWS *wnd,TYPE *type,int total,int tab);
  void GetWindowsMax(WINDOWS *wnd,TYPE *type,int total,int tab);


/* 20.���ֵ���ʾ���������뷨 */
  void BOY_OUT_TEXTXY(int x, int y, char *str);
  void BOY_OUT_TEXT(char *str);
  void BOY_OUT_CHARXY(int x, int y, char ch);
  void BOY_OUT_CHAR(char ch);
  void BOY_OUT_HZXY(int x, int y, char *str);
  void BOY_OUT_HZ(char *str);
  void BOY_SETHZ_XY(int x, int y);
  void BOY_GETHZ_XY(int *x, int *y);
  void BOY_SETHZ_FONT(int font);
   int BOY_GETHZ_FONT(void);
  void BOY_SETHZ_COLOR(int color);
   int BOY_GETHZ_COLOR(void);

  void CREATE_BOY_CHINESE(void);
  void CLOSE_BOY_CHINESE(void);
   int BOY_CHINESE_TEST(TEST *keys);
  char BOY_HZ_GET(void);
   int BOY_CODE_GET(void);

/* 21.ͼ�δ��� */
  long BOY_GET_IMAGE(int x1, int y1, int x2, int y2);
   int BOY_PUT_IMAGE(int x, int y, long n, int op, int type);
   int BOY_GET_IMAGEF(int x1, int y1, int x2, int y2,char *fn);
   int BOY_PUT_IMAGEF(int x, int y, char *fn, int op);
   int BOY_IMAGE_SIZE(char *fn,int *x, int *y);
   int BOY_DRAW_PIC(int x1, int y1,char *fn);
   int BOY_DRAW_ICN(int x1, int y1,char *fn);
  void BOY_DEL_IMAGEBUF(long n);
  void BOY_DEL_IMAGEBUF_ALL(void);

/* 22.��� */
   int BOY_SET_MOUSE(void);
  void BOY_MOUSE_VIEW(void);
  void BOY_MOUSE_HIDE(void);
  void BOY_MOUSE_MOVE(int x,int y);
  void BOY_MOUSE_GET(int *x,int *y);
  void BOY_MOUSE_DGET(int *x,int *y);
   int BOY_MOUSE_INBOX(int x1,int y1, int x2, int y2);
   int BOY_MOUSE_BUTTON(void);
  void BOY_MOUSE_TYPE(int type);
  void BOY_MOUSE_GETALL(int *x, int *y, int *button);

/* ϵͳ */
   int BOY_SETUP_ALL(void);
  void BOY_CLOSE_ALL(void);
  void BOY_GET_TEST(TEST *BOY_TEST);
   int BOY_DESKTOP(int type, char *fn);
//   int MessageBox(char *name, char *text, int win);
   int CreateWarningWindows(char *name,char *text,int type);

int puthz16(int x,int y,int color,char p[256],int space,int font);
int puthz24(int x,int y,int z,int color,char *p,int PD);
void puthz163d(int x,int y,int g,char text[256],int type,int cl);
int puthz24_2(int x,int y,int z,int color,char *p,int PD);
int puthz24_small(int small,char name1[256],int x,int y,int z,int color,char *p,int PD);
int puthz24_2_small(int small,char name1[256],int x,int y,int z,int color,char *p,int PD);

#ifdef __cplusplus
}
#endif

#endif  /*__BOY_WIN_H */