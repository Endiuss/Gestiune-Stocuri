#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>


char produse[500][500];
char cos[500][500];

int cantitate[1000];
int nrprod;
int nrcos=0;
int cantcos[1000];
void save(){FILE* file = fopen("save.in", "w");
for(int i=0;i<nrprod;i++){
    fprintf(file,"%s",produse[i]);
    fprintf(file,"%d\n",cantitate[i]);

}
fclose(file);

file = fopen("cos.in", "w");
for(int i=0;i<nrcos;i++){
    fprintf(file,"%s",cos[i]);
    fprintf(file,"%d\n",cantcos[i]);

}
fclose(file);




}
void comanda(){
    char chr;
for(int i =0;i<nrcos;i++){
for(int j=0;j<nrprod;j++){if(strcmp(cos[i],produse[j])==0){
    printf("%d\n",cantcos[i]);
        cantitate[j]= cantitate[j]-cantcos[i];}}}
memset(cos,'\0', sizeof cos);
memset(cantcos,0, sizeof cantcos);
nrcos=0;
printf("%s\n","Comanda a fost plasata cu succes!");
while((chr=getch())!=0x4B){}

}
void adaugacos(int k){
strcpy(cos[nrcos],produse[k]);
int x;
printf("%s\n",produse[k]);
printf("%s%d\n","Cantitatea valabila:",cantitate[k]);
label:
printf("%s","Introduceti noua cantitate:\n");

int n;

scanf("%d",&n);
if(n>=0&&n<=cantitate[k]){cantcos[nrcos]=n;}
else {printf("%s","Introduceti o cantitate valabila\n");
    goto label;}
nrcos++;







}

void init(){
    FILE* file = fopen("save.in", "r");
    char line[500];
    int i=0;
    int j=0;
    int k=0;
    while (fgets(line, sizeof(line), file)) {

            if(i%2==0){strcpy(produse[nrprod],line);

            nrprod++;

            }
            else {cantitate[k]=atoi(line);
            k++;
    }
    i++;



    }

    fclose(file);


file = fopen("cos.in", "r");

    i=0;
    j=0;
    k=0;
    while (fgets(line, sizeof(line), file)) {

            if(i%2==0){strcpy(cos[nrcos],line);

            nrcos++;

            }
            else {cantcos[k]=atoi(line);
            k++;
    }
    i++;



    }

    fclose(file);





    }

void stergere(int k){
    int i;
     for(i=nrprod-1;i>=k;i++){
    strcpy(produse[i-1],produse[i]);
    cantitate[i-1]=cantitate[i];

}
nrprod--;
}
void stergerecos(int k){
    int i;
     for(i=nrcos-1;i>=k;i++){
    strcpy(cos[i-1],cos[i]);
    cantcos[i-1]=cantcos[i];

}
nrcos--;
}
void modnume(int n){
    printf("%s","Introduceti noua denumire:\n");
    fgets(produse[n],120,stdin);


}
void modcantitate(int n){
printf("%s%d\n","Cantitatea actuala:",cantitate[n]);
printf("%s","Introduceti noua cantitate:\n");
int k;

scanf("%d",&k);
cantitate[n]=k;
}

typedef unsigned short int usint_t;

int menu(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);

int sterge(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int stergecos(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int almodifica(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int vizualizeaza(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int modnumestoc(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int user(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int magazin(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int vizualizeaza(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int usermeniu(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int almagazin(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);
int vizcos(char* name, char* prefix, char* cursor, usint_t orientation,
         usint_t padding, usint_t start_pos, usint_t delay,
         usint_t num_childs, ...);

void adauga(){
    int i;
     char str [120];
     printf("%s", "Introduceti denumirea obiectului ");
     fgets(str, 120, stdin);
     printf("%s", "Introduceti cantitatea ");
     scanf("%d",&i);
     strcpy(produse[nrprod],str);
     cantitate[nrprod]=i;
     nrprod++;


             }
int initin=0;
int main()
{if(initin==0){init();
initin++;}
int vall;
int userval;
userval = user("Gestiune Stocuri","[*]","->",1,3,3,0,2,
                      "Administrator","Client");
switch (userval){
case 1:{
    int response =menu("Gestiune Stocuri","[*]","->",1,3,3,0,5,
                      "Adauga Produse","Sterge produse","Editeaza produse","Vizualizeaza produse","Save");
    switch(response)
    {
        case 1:{
            system("cls");
            adauga();
            save();
            return main();}




        case 2:
            system("cls");
            vall=sterge("Sterge","[*]","->",1,3,3,0,nrprod);

            stergere(vall);
            save();
            return main();
        case 3:
             system("cls");
             vall=almodifica("Modifica Stocuri","[*]","->",1,3,3,0,nrprod);
             int modd=modnumestoc("Alece ce doresti sa modifici","[*]","->",1,3,3,0,2,
                      "Denumire","Cantitate");
                switch(modd){
            case 1:
                system("cls");
                modnume(vall-1);
           case 2:
                system("cls");
                modcantitate(vall-1);
              }
              save();
              main();




        case 4:
            system("cls");
            vall = vizualizeaza("Vizualizeaza Stocuri","[*]","->",1,3,3,0,nrprod);
        case 5:
            save();
            main();

    }}
    case 2:{int valuusermeniu;
    valuusermeniu=menu("Magazin sau Cos de cumparaturi","[*]","->",1,3,3,0,4,
                      "Magazin","Cos de cumparaturi","Elimina din cos","Plaseaza Comanda");
            switch(valuusermeniu){
            case 1:{
                int alegemagazin;
                system("cls");
                alegemagazin=almagazin("Alege din magazin","[*]","->",1,3,3,0,nrprod);
                system("cls");
                adaugacos(alegemagazin-1);
                save();
                main();

                }
            case 2:{
                system("cls");
             vizcos("Vizualizeaza Produse","[*]","->",1,3,3,0,nrcos);


            }
            case 3:{
                int ster;
                 system("cls");
            ster=stergecos("Sterge","[*]","->",1,3,3,0,nrcos);

            stergerecos(ster);
            save();
            return main();


            }
            case 4:{
                system("cls");
                comanda();
                save();
                return main();

            }


                                    }
            }

    }

    return main();
}


int menu
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...


)
{
    va_list args;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x48||chr==0x4B)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,va_arg(args,char*));}

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int almodifica
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,
    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...

)
{
    va_list args;
    args=produse;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x4B){main();}
        if(chr==0x48)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,produse[tmp-1]);
        }

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
int vizualizeaza
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...



)
{
    va_list args;
    args=produse;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x4B||chr==0x48||chr==0x50||chr==0x4D){main();}

        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        (orient)?strcat(format,"\n"):0;
        for (tmp=1;tmp<=childs;tmp++)
        {

            pos=padding;
            while((pos--)>0) strcat(format," ");
            produse[tmp-1][strlen(produse[tmp-1])-1]='\0';
            strcat(format,produse[tmp-1]);
            printf("%s\n",format);
            printf("%s\n",produse[tmp-1]);
            strcat(format," ---> ");
            char buff[32];
            itoa(cantitate[tmp-1],buff,10);
            strcat(format,buff);
            strcat(format," unitati");
            (orient)?strcat(format,"\n"):0;
        }

        Sleep(delay);
        system("cls");
        printf(format);
        format="";
        va_end(args);
    }while((chr=getch())!=0x4B);
    return main();
}

///////////////////////////////////////////////////////////////////////////
int sterge
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...



)
{
    va_list args;
    args=produse;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x4B){main();}
        if(chr==0x48)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,produse[tmp-1]);
        }

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}
//////////////////////
int modnumestoc
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...


)
{
    va_list args;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*15
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x48||chr==0x4B)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,va_arg(args,char*));}

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}

/////////////////////////////////////user
int user
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...


)
{

    va_list args;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x48||chr==0x4B)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,va_arg(args,char*));}

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}

/////////////////////////////
int almagazin
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,
    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...

)
{
    va_list args;
    args=produse;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x4B){main();}
        if(chr==0x48)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,produse[tmp-1]);
        }

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}

///////////////////////////
int vizcos
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...



)
{
    va_list args;
    args=cos;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x4B||chr==0x48||chr==0x50||chr==0x4D){main();}

        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        (orient)?strcat(format,"\n"):0;
        for (tmp=1;tmp<=childs;tmp++)
        {

            pos=padding;
            while((pos--)>0) strcat(format," ");
            cos[tmp-1][strlen(cos[tmp-1])-1]='\0';
            strcat(format,cos[tmp-1]);
            printf("%s\n",format);
            printf("%s\n",cos[tmp-1]);
            strcat(format," ---> ");
            char buff[32];
            itoa(cantcos[tmp-1],buff,10);
            strcat(format,buff);
            strcat(format," unitati");
            (orient)?strcat(format,"\n"):0;
        }

        Sleep(delay);
        system("cls");
        printf(format);
        format="";
        va_end(args);
    }while((chr=getch())!=0x4B);
    return main();
}
/////////////////////////////////////////////////////////////////////////
int stergecos
(
    char *name,
    char *prefix,
    char *cursor,
    usint_t orient,




    usint_t padding,
    usint_t start_pos,
    usint_t delay,
    usint_t childs,
    ...



)
{
    va_list args;
    args=cos;
    int tmp=0,pos;
    char chr;
    usint_t opt=start_pos;
    char* format=malloc
    (
        (
            strlen(name)+strlen(prefix)+strlen(cursor)+
            3+
            (2*childs)+
            (padding*childs)+
            childs*520
        )*sizeof(char)
    );
    do
    {
        if(tmp!=0)chr=getch();
        if(chr==0x4B){main();}
        if(chr==0x48)
            (opt>1&&opt!=1)?opt--:(opt=childs);
        else if(chr==0x50||chr==0x4D)
            (opt>=1&&opt!=childs)?opt++:(opt=1);
        else {}
        strcpy(format,"");
        strcat(format,prefix);
        strcat(format,name);
        strcat(format,":");
        va_start(args,childs);
        for (tmp=1;tmp<=childs;tmp++)
        {
            (orient)?strcat(format,"\n"):0;
            pos=padding;
            while((pos--)>0) strcat(format," ");
            if(tmp==opt)
            {
                strcat(format,"\b");
                strcat(format,cursor);
            }
            strcat(format,cos[tmp-1]);
        }

        Sleep(delay);
        system("cls");
        printf(format);
        va_end(args);
    }while((chr=getch())!=0x0D);
    return opt;
}
