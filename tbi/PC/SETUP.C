#include "jrtz.h"

// # include "c:\boy20\include\boywin.h" /* Ƕ��ͷ�ļ�, �йز����ṹ��Ϣ */
// # include "c:\boy20\include\key.h"    /* Ƕ��ͷ�ļ�, �йؼ���ɨ������Ϣ */


 void Setup(void)        /* һ�����û�����Ĵ��� */
 {
   extern char COM;
   extern char change;
   int FLAG = 0;               /* ѭ���ж� */
   int i,CASE;                   /* ����ֵ */
   static int  BOY_TOTAL = 7; /* �û������Ĳ������� */
   static TEST BOY_TEST;       /* �����ṹ */
   static int  BOY_TAB = 3;   /* ��ǰ�������ڴ˲����� */

   /* ����������:�μ��ֲ��98ҳ */
   static TYPE BOY_TYPE[7] = {
				 {99,0},{6,0},{6,1},{6,2},{6,3},
				 {1,0},{1,1},
				};

   /* ����Ϊ���ںʹ����в����ṹ�Ķ���
      �����޸�,������ֲ��һ���ݵڶ��� */
    static KEY3D BOY_KEY3D[2] = {
				   {214,284,274,306,"",0,0,1,0,2,"ȷ��",0,0,15,0,1},
				   {314,284,374,306,"",0,0,1,0,2,"ȡ��",27,0,15,0,2},
				  };
    static OPTION BOY_OPTION[4] = {
				    {284,184,"COM1",0,1,0,0,7,0,1,"",0},
				    {284,204,"COM2",0,1,0,0,7,1,1,"",0},
				    {284,224,"COM3",0,1,0,0,7,0,1,"",0},
				    {284,244,"COM4",0,1,0,0,7,0,1,"",0},
				   };
    static WINDOWS BOY_WINDOWS = { 154,144,434,315,"���ƽ��������",7,1,0,0,1,3,15,0,0,0,15,1,15,0,7,0,0};

    for(i=0;i<4;i++){
	if(COM==i)BOY_OPTION[i].YN=1;
	else BOY_OPTION[i].YN=0;
    }
    BOY_WINDOWS.key = BOY_KEY3D;
    BOY_WINDOWS.opti= BOY_OPTION;

    CREATE_WINDOWS_ALL(&BOY_WINDOWS,&BOY_TYPE[0],BOY_TOTAL,BOY_TAB);
    /* �������ڼ����� */

    while(!FLAG)
     { /* �õ�ϵͳ�¼� */
       BOY_GET_TEST(&BOY_TEST);
       CASE=BOY_ALL_TEST(&BOY_WINDOWS,&BOY_TEST,BOY_TOTAL,&BOY_TAB,BOY_TYPE);
       /* �õ�����ֵ */
       switch(CASE)
       {
	 /* ѡ�д�����˵�֮�رմ����� */
	 case 1:for(i=0;i<4;i++){
		if(BOY_OPTION[i].YN==1){
			if(COM!=i)change=1;
			COM=i;
			break;
		}
	 }

	 case 2:
	 case WindowsClose:FLAG=1;break;
	}
      }
     CLOSE_BOY_WINDOWS(&BOY_WINDOWS);    /* �رմ��� */
  }