//#include<string.h>

// # include "c:\boy20\include\boywin.h" /* Ƕ��ͷ�ļ�, �йز����ṹ��Ϣ */
// # include "c:\boy20\include\key.h"    /* Ƕ��ͷ�ļ�, �йؼ���ɨ������Ϣ */
 # include "jrtz.h"

 void del(void)        /* һ�����û�����Ĵ��� */
 {
   int FLAG = 0;               /* ѭ���ж� */
   int i;
   int CASE;                   /* ����ֵ */
   static int  BOY_TOTAL = 7; /* �û������Ĳ������� */
   static TEST BOY_TEST;       /* �����ṹ */
   static int  BOY_TAB = 3;   /* ��ǰ�������ڴ˲����� */

   /* ����������:�μ��ֲ��98ҳ */
   static TYPE BOY_TYPE[7] = {
				 {99,0},{1,0},{1,1},{12,0},{3,0},
				 {3,1},{3,2},
				};

   /* ����Ϊ���ںʹ����в����ṹ�Ķ���
      �����޸�,������ֲ��һ���ݵڶ��� */
    extern _station *station;

    static KEY3D BOY_KEY3D[2] = {
				   {450,180,510,202,"",0,0,1,0,2,"ɾ��",13,0,15,0,1},
				   {450,240,510,262,"",0,0,1,0,2,"ȡ��",27,0,15,0,2},
				  };
    static LABEL BOY_LABEL[3] = {
				    {110,130,150,150,0,0,0,0,0,0,7,0,0,1,"վ��",0,""},
				    {180,130,220,150,0,0,0,0,0,0,7,0,0,1,"˵��",0,""},
				    {320,130,400,150,0,0,0,0,0,0,7,0,0,1,"�绰����",0,""},
				   };
    static LISTED BOY_LISTED[1] = {
				    {110,155,412,337,sizeof(*station),10,1,9,0,1,0,255,0,10,sizeof(*station),""},
				   };
    static WINDOWS BOY_WINDOWS = { 100,100,540,350,"ɾ��վ��",7,1,0,0,1,3,15,0,0,0,15,1,15,0,7,0,0};

    extern int station_sum;
    extern char change;
    char *p;
    BOY_LISTED[0].sl=station_sum;
    p=(char *)station;
    for(i=0;i<station_sum;i++){
	station[i].NO[3]=station[i].phone[12]=station[i].comment[20]=' ';
    }
    for(i=0;i<sizeof(*station)*station_sum;i++)
	if(!p[i])p[i]=' ';
    BOY_LISTED[0].text=(char *)station;

    BOY_WINDOWS.key = BOY_KEY3D;
    BOY_WINDOWS.lab = BOY_LABEL;
    BOY_WINDOWS.lst = BOY_LISTED;

    CREATE_WINDOWS_ALL(&BOY_WINDOWS,&BOY_TYPE[0],BOY_TOTAL,BOY_TAB);
    /* �������ڼ����� */

    while(!FLAG)
     { /* �õ�ϵͳ�¼� */
       BOY_GET_TEST(&BOY_TEST);
       CASE=BOY_ALL_TEST(&BOY_WINDOWS,&BOY_TEST,BOY_TOTAL,&BOY_TAB,BOY_TYPE);
       /* �õ�����ֵ */
       switch(CASE)
       {

	 case 1:{
		i=CreateWarningWindows("ȷ��ɾ��","ȷ��ɾ����վ��?",1);
		if(i!=30)break;
		for(i=BOY_LISTED[0].to;i<station_sum;i++){
			strncpy(station[i].NO,station[i+1].NO,3);
			strncpy(station[i].phone,station[i+1].phone,12);
			strncpy(station[i].comment,station[i+1].comment,20);
		}
		station_sum--;
		change=1;
	 }
	 case 2:
	 case WindowsClose:FLAG=1;break;
	}
      }
     CLOSE_BOY_WINDOWS(&BOY_WINDOWS);    /* �رմ��� */
  }