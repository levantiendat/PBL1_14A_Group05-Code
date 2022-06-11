#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void Create();   // Nhap DS
void ViewPoint();  // Xem diem SV
void FixPoint(); // Sua diem SV
void PrList();  // In danh sach SV
void ArrList(); // Sap xep danh sach SV

int CheckID(long long x);  // Kiem tra ma sv
void ReadF();  // Doc file
void delay(int number_of_seconds);
void PrLine(); // Ngan dong

int n;

struct sv{
   long long msv;
   float l1,l2,p1,p2,ppt,final;
   float TB;
   char diemchu[3];
} ds[50];

FILE *ac,*ad;
char j[1001],k[1001],ap[1001];
void TitStart()
{
    printf("\t***********************************************************************************************************\n");
    printf("\t|                                PBL1: HE THONG QUAN LY DIEM CUA SINH VIEN                                |\n");
    printf("\t|                             Nguoi thuc hien: Le Van Tien Dat & La Dang Huy                              |\n");
    printf("\t|                                Giao vien huong dan: Tran Ho Thuy Tien                                   |\n");
    printf("\t***********************************************************************************************************\n");
}

void TitEnd()
{
    printf("\n\t***********************************************************************************************************\n");
    printf("\t|                        ^-^  Cam on moi nguoi da su dung he thong cua chung toi ^-^                      |\n");
    printf("\t*                                  Chuc moi nguoi mot ngay moi tot lanh !!!                               *\n");
    printf("\t|                                -.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-                             |\n");
    printf("\t***********************************************************************************************************\n");
}
int main(){
    SetConsoleTitle("Project");
    TitStart();
    int select,in;
    long long msv;
    printf("\t                                    Moi ban dang nhap vao he thong: "); scanf("%d", &in);
    //printf("\t");
    // delay of one second
    delay(2);
    while(in == 1){
    //PrLine();
    printf("\n\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\t|  1. Nhap diem\t\t\t\t\t\t\t\t\t\t                  |\n\t|  2. Xem diem\t\t\t\t\t\t\t\t\t\t                  |\n\t|  3. Sua diem\t\t\t\t\t\t\t\t\t\t                  |\n\t|  4. In danh sach\t\t\t\t\t\t\t\t\t                  |\n\t|  5. Sap xep\t\t\t\t\t\t\t\t\t\t                  |\n\t|  0. Thoat\t\t\t\t\t\t\t\t\t\t                  |");
    printf("\n\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\t                                    Chon chuc nang: ");
    scanf("%d",&select);
    switch (select){
        case 1:
            //ham tao file
            printf("\t                                    Nhap ten mon hoc: ");
            scanf("%s", &j);
            strcat(j,"_");
            printf("\t                                    Nhap ten lop ( nhom lop ): ");
            scanf("%s", &k);
            strcat(k,".txt");
            strcat(j,k);
            ac= fopen(j,"w");
            printf("\t                                    File %s da duoc tao\n ",j);
            if(ac == NULL){
            printf("\t                                    Error !!!");
            exit(1);
               }
            else
            {
                PrLine();
                Create();
            }
            fclose(ac);break;

         case 2:
            printf("\t                                    Nhap ten mon hoc: ");
            scanf("%s", &j);
            strcat(j,"_");
            printf("\t                                    Nhap ten lop ( nhom lop ): ");
            scanf("%s", &k);
            strcat(k,".txt");
            strcat(j,k);
            ac= fopen(j,"r");
            if(ac == NULL)
            {
                printf("\t                                    Error !");
                exit(1);
            }else{
                PrLine();
                ReadF();
                ViewPoint();
            }
            fclose(ac);break;

         case 3:
            printf("\t                                    Nhap ten mon hoc: ");
            scanf("%s", &j);
            strcat(j,"_");
            printf("\t                                    Nhap ten lop ( nhom lop ): ");
            scanf("%s", &k);
            strcat(k,".txt");
            strcat(j,k);
            ac= fopen(j,"r");
            if(ac == NULL)
            {
                printf("\t                                    Error !!!");
                exit(1);
            }else{
                PrLine();
                ReadF();
                FixPoint();
            }
            fclose(ac);break;

         case 4:
            printf("\t                                    Nhap ten mon hoc: ");
            scanf("%s", &j);
            strcpy(ap,j);
            strcat(j,"_");
            printf("\t                                    Nhap ten lop ( nhom lop ): ");
            scanf("%s", &k);
            strcat(ap,"    Nhom: ");
            strcat(ap,k);
            strcat(k,".txt");
            strcat(j,k);
            ac= fopen(j,"r");
            if(ac == NULL)
            {
                printf("\t                                    Error !!!");
                exit(1);
            }else{
                PrLine();
                ReadF();
                PrList();
            }
            fclose(ac);break;

         case 5:
            printf("\t                                    Nhap ten mon hoc: ");
            scanf("%s", &j);
            strcat(j,"_");
            printf("\t                                    Nhap ten lop ( nhom lop ): ");
            scanf("%s",&k);
            strcpy(ap,j);
            strcat(ap,k);
            strcat(k,".txt");
            strcat(j,k);
            strcpy(k,ap);
            //strcat(j,".txt");
            strcat(k,"_array.txt");
            ac= fopen(j,"r");
            ad= fopen(k,"w");
            if(ac == NULL||ad==NULL)
            {
                printf("\t                                    Error !!!");
                exit(1);
            }else{
                PrLine();
                ReadF();
                ArrList();
            }
            fclose(ac);
            fclose(ad);
            break;
        }
    if(select == 0) break;
    }
   //PrLine();



    PrLine();
    printf("\t                                    He thong da thoat !!!");
    TitEnd();
    return 0;
}

void ReadF()
{
   rewind(ac);
   n=0;
   while(!feof(ac)){
      fscanf(ac,"%lld %f %f %f %f %f %f",&ds[n].msv,&ds[n].l1,&ds[n].l2,&ds[n].p1,&ds[n].p2,&ds[n].ppt,&ds[n].final);
      n++;
      }
   n--;
}

void PrLine()
{
    printf("\t");
    for(int i = 0; i < 107; i++)
    {
        printf("-");
    }
    printf("\n");
}
int CheckID( long long x)
{
    int db = -1;//db la vi tri co trong du lieu
    for(int j = 0; j <= n; j++){
        if(ds[j].msv == x) db = j;
    }
    return db;
}



void Create()
{
    int in;
    while(1){
       //PrLine();
       printf("\tNhap ma sinh vien ( nhap 0 de thoat chuc nang ): ");
       scanf("%lld", &ds[n].msv); if(ds[n].msv == 0) break;
       fprintf(ac, "%lld ", ds[n].msv);
       printf("\tLab1:            "); scanf("%f", &ds[n].l1); fprintf(ac, "%7.1f ", ds[n].l1);
       printf("\tLab2:            "); scanf("%f", &ds[n].l2); fprintf(ac, "%7.1f ", ds[n].l2);
       printf("\tProgress test 1: "); scanf("%f", &ds[n].p1); fprintf(ac, "%7.1f ", ds[n].p1);
       printf("\tProgress test 2: "); scanf("%f", &ds[n].p2); fprintf(ac, "%7.1f ", ds[n].p2);
       printf("\tPresentation:    "); scanf("%f", &ds[n].ppt); fprintf(ac, "%7.1f ", ds[n].ppt);
       printf("\tFinal Test:      "); scanf("%f", &ds[n].final); fprintf(ac, "%7.1f\n", ds[n].final);
    }
   // PrLine();
    printf("\tDa thoat chuc nang nhap diem !!\n");
}
void ViewPoint()
{
    long long msvc;
    int in;
    //printf("Nhap 1 de bat dau: ");
    //scanf("%d", &in);
    while(1){
        //PrLine();
        printf("\tNhap ma sinh vien can kiem tra ( nhap 0 de thoat chuc nang ): "); scanf("%lld", &msvc);
        if(msvc == 0) break;
        //ham check ma sinh vien
        int pos = CheckID(msvc);
        if( pos != -1){
            printf("\t*---------------------------------------------------------------------------------------------------------*\n");
            printf("        |  Bang diem cua SV co ma: %lld    \t\t\t\t\t\t                  |\n",msvc);
            printf("\t*---------------------------------------------------------------------------------------------------------*\n");
            printf("        | Lab1\t| Lab2\t|   Progress test 1\t |   Progress test 2\t | Presentation\t |     Final test         |\n");
            printf("\t*---------------------------------------------------------------------------------------------------------*\n");
            printf("        |  %.1f\t|  %.1f\t|         %.1f\t\t |        %.1f\t\t |      %.1f\t |       %.1f              |\n", ds[pos].l1, ds[pos].l2, ds[pos].p1, ds[pos].p2, ds[pos].ppt, ds[pos].final);
            printf("\t*---------------------------------------------------------------------------------------------------------*\n");
        } else printf("\tKhong tim thay !!\n");
        }
        PrLine();
        printf("\tDa thoat chuc nang xem diem !!\n");
}
void FixPoint()
{
    int select, in;//bien abc de chon cot diem can sua,bien k de khoi dong
    long long msvc;
    while(1){
        //PrLine();
        printf("\tNhap ma sinh vien can kiem tra ( nhap 0 de thoat chuc nang ): "); scanf("%lld", &msvc);
        if(msvc == 0) break;
        //ham check ma sinh vien
        int pos = CheckID(msvc);
        if(pos != -1){
            printf("\tChon cot diem can chinh sua:\n\t1. Lab1\n\t2. Lab2\n\t3. Progress test 1\n\t4. Progress test 2\n\t5. Presentation\n\t6. Final Test\n\tMoi ban chon: ");
            scanf("\t\t%d", &select);
            switch (select){
                case 1:
                    printf("\tNhap cot diem Lab1 moi: ");
                    scanf("%f",&ds[pos].l1);break;

                case 2:
                    printf("\tNhap cot diem Lab2 moi: ");
                    scanf("%f",&ds[pos].l2);break;

                case 3:
                    printf("\tNhap cot diem Progress Test 1 moi: ");
                    scanf("%f",&ds[pos].p1);break;

                case 4:
                    printf("\tNhap cot diem Progress Test 2 moi: ");
                    scanf("%f",&ds[pos].p2);break;

                case 5:
                    printf("\tNhap cot diem Presentation moi: ");
                    scanf("%f",&ds[pos].ppt);break;

                case 6:
                    printf("\tNhap cot diem Final moi: ");
                    scanf("%f",&ds[pos].final);break;
            }

        }else printf("\tKhong tim thay !!\n");
   }

   fclose(ac);
   ac = fopen(j, "w");
   for(int i = 0;i < n; i++){
       fprintf(ac, "%   lld ", ds[i].msv);
       fprintf(ac, "%7.1f ", ds[i].l1);
       fprintf(ac, "%7.1f ", ds[i].l2);
       fprintf(ac, "%7.1f ", ds[i].p1);
       fprintf(ac, "%7.1f ", ds[i].p2);
       fprintf(ac, "%7.1f ", ds[i].ppt);
       fprintf(ac, "%7.1f\n", ds[i].final);
   }
   PrLine();
   printf("\tDa thoat chuc nang sua diem !!\n");
}

void PrList()
{
    printf("\t*---------------------------------------------------------------------------------------------------------*\n");
    printf("        |  Bang diem cua lop: %s    \t\t\t\t\t\t                  |\n",ap);
    printf("\t*---------------------------------------------------------------------------------------------------------*\n");
    printf("        | STT | Ma SV     | Lab1  | Lab2   | Progress test 1 | Progress test 2   | Presentation  | Final test     |\n");
    for( int i = 0; i < n; i++)
    {
        printf("\t*-----*-----------*-------*--------*-----------------*-------------------*---------------*----------------*\n");
        printf("        | %d   | %lld | %4.1f  |  %4.1f  |      %4.1f       |      %4.1f         |      %4.1f     |     %4.1f       |\n",
                            i+1, ds[i].msv, ds[i].l1, ds[i].l2, ds[i].p1, ds[i].p2, ds[i].ppt, ds[i].final);
    }
    printf("\t*---------------------------------------------------------------------------------------------------------*\n");

}
void ArrList()
{
   for(int i=0;i<n;i++){
      ds[i].TB=ds[i].l1*0.1+ds[i].l2*0.1+ds[i].p1*0.1+ds[i].p2*0.1+ds[i].ppt*0.2+ds[i].final*0.4;
      if(ds[i].TB>=9.5) strcpy(ds[i].diemchu,"A+");
      else if(ds[i].TB>=8.5) strcpy(ds[i].diemchu,"A");
      else if(ds[i].TB>=8.0) strcpy(ds[i].diemchu,"B+");
      else if(ds[i].TB>=7.0) strcpy(ds[i].diemchu,"B");
      else if(ds[i].TB>=6.5) strcpy(ds[i].diemchu,"C+");
      else if(ds[i].TB>=5.5) strcpy(ds[i].diemchu,"C");
      else if(ds[i].TB>=5.0) strcpy(ds[i].diemchu,"D+");
      else if(ds[i].TB>=4.0) strcpy(ds[i].diemchu,"D");
      else strcpy(ds[i].diemchu,"F");

   }
   for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
         if(ds[i].TB<ds[j].TB){
            char dc[3];
            strcpy(dc,ds[i].diemchu);strcpy(ds[i].diemchu,ds[j].diemchu);strcpy(ds[j].diemchu,dc);
            float t=ds[i].l1;ds[i].l1=ds[j].l1;ds[j].l1=t;
            t=ds[i].l2;ds[i].l2=ds[j].l2;ds[j].l2=t;
            t=ds[i].p1;ds[i].p1=ds[j].p1;ds[j].p1=t;
            t=ds[i].p2;ds[i].p2=ds[j].p2;ds[j].p2=t;
            t=ds[i].ppt;ds[i].ppt=ds[j].ppt;ds[j].ppt=t;
            t=ds[i].final;ds[i].final=ds[j].final;ds[j].final=t;
            t=ds[i].TB;ds[i].TB=ds[j].TB;ds[j].TB=t;
            long long kc=ds[i].msv;ds[i].msv=ds[j].msv;ds[j].msv=kc;
         }
      }
   }
   for(int i = 0;i < n;i++){
      fprintf(ad,"%9lld %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %6.2f %3s\n",ds[i].msv,ds[i].l1,ds[i].l2,ds[i].p1,ds[i].p2,ds[i].ppt,ds[i].final,ds[i].TB,ds[i].diemchu);
   }
   printf("\tDa sap xep xong hay xem tai file: %s\n",k);
   PrLine;
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

