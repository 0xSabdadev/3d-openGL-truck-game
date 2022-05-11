#include "D:\Informatics\ProjectC\GKV_TRUK_Sementara\lib\car.h"
#include "D:\Informatics\ProjectC\GKV_TRUK_Sementara\lib\baseLib.h"

Mobil::Mobil(float x, float y, float z,float rotate){
    setX(x);
    setY(y);
    setZ(z);
    setHitValue(0);
    glPushMatrix();
        glTranslatef(getX(),getY(), getZ());
        glRotatef(rotate, 0, 1, 0);
        glPushMatrix();//body
            glColor3f(0.0,0.0,9.0);
            blok(1.25, 3, 2);
            glTranslatef(0, 1.125, 0);
            blok(1.25, 3, 2);
            glTranslatef(1.25, -1.25,0);
            blok(1.25, 5.5, 2);
            glRotatef(-35, 0, 0, 15);
            glTranslatef(0, 0.85,0);
            blok(1.25, 2, 2);
            glTranslatef(0.5, 0.6,-0.35); //atas-bawah,dalam,geser left right
            glColor3f(0.9,0.9,0.9);// warna kaca
            blok(0.075, 15, 28);
            glRotatef(180, 45, -45, 0);
        glPopMatrix();

        glPushMatrix();//roda (ganti semua ke-scale x)
            glColor3f(0.0,0.0,0.0); //kanan depan
            glTranslatef(2.5, -1,-0.625);
            cylinder(0.625, 0.625,0.085);
            glColor3f(0.0,0.0,0.0); //kanan belakang
            glTranslatef(-10, 4,3.5);
            glTranslatef(6, -4,-3.5); //ganti par1 aja
            cylinder(0.625, 0.625,0.085);
            glColor3f(0.0,0.0,0.0); //kiri blkg
            glTranslatef(2.5, 4,3.5);
            glRotatef(180,0,180,0);
            glTranslatef(0.75,-3.85,0.85); //,atas-bawah,kanan-kiri
            cylinder(0.625, 0.625,0.085);
            glColor3f(0.0,0.0,0.0);
            glTranslatef(-1.5,4,8);
            glTranslatef(-2.75,-3.85,-8);
            cylinder(0.625, 0.625,0.085);//,atas-bawah,kanan-kiri
            glColor3f(1.0,1.0,1.0);
            glRotatef(90,1,0,0); //kaca kaanan
            glTranslatef(2.5, 0.3,-1.35);//depan belakang,kaan-kiri
            blok(0.5, 1, 1.25); //ganti semua
            glRotatef(90,0,1,0); //kaca kanannn2
            glTranslatef(0.3,0.2,1);//depan belakang,kaan-kiri
            blok(1, 1.88, 3.5);
            glRotatef(0,0,0,0); //kaca kiri2
            glTranslatef(0,1.8,0);
            blok(1, 1.88,3.5);
            glRotatef(90,0,1,0);
            glTranslatef(1, 0.2,-0.35);//depan belakang,,kaan-kiri
            blok(0.5, 1, 1.25);
            // glColor3f(0.9,5.9,4.0);//lampu kiri
            // glRotatef(90,0,1,0);
            // glTranslatef(-0.35,-0.4,2);//bawah(+),kanan(-),depan(+)
            // cylinder(0.3, 0.3,0.55);
            //
            // glColor3f(0.9,5.9,4.0);//lampu kanan
            // glRotatef(0,0,0,0);
            // glTranslatef(0.03,-1.4,0.05);//atas(-),kaannkiri(-),depan-belakang(+)
            // cylinder(0.3, 0.3,0.55);

            // glColor3f(0.0,0.0,0.0);//knalpot
            // glRotatef(0,0,0,0);
            // glTranslatef(0.3,0.08,-6.25);//bawah(+),kiri(+),depan(+)
            // cylinder(0.2, 0.2,1);
            //
            // glColor3f(1.0,1.0,1.0); //kaca lakang
            // glRotatef(90,1,0,0);
            // glTranslatef(-0.4,0.68,-1.45);//,bawah(+),belakang(-)),kanan(+)
            // blok(0.8, 1.65, 3);
            //
            // glColor3f(9.0,0.0,0.0);//lampu atas
            // glRotatef(0,0,0,0);
            // glTranslatef(-1.85,3.2,-0.43);//,depanblkg,kanan-kiri
            // cylinder(0.2, 0.2,2.5);
        glPopMatrix();
    glPopMatrix();
}

void kerucut(float ngisor, float nduwur, float dowo)
{
    float i;
    glPushMatrix();
    glTranslatef(1.0,0.0,ngisor/24);
    glutSolidCone(ngisor,0,32,4);
    for(i=0;i<=dowo;i+=ngisor/24){
        glTranslatef(0.0,0.0,ngisor/24);
        glutSolidTorus(ngisor/4,ngisor-((i*(ngisor-nduwur))/dowo),16,16);
    }
    glTranslatef(0.0,0.0,ngisor/4);
    glutSolidCone(nduwur,0,20,1);
    glColor3f(0.,1.,1.);
    glPopMatrix();
}

void cylinder(float alas,float atas,float tinggi)
{
    float i;
    glPushMatrix();
        glTranslatef(1.0,0.0,-alas/8);
        glutSolidCone(alas,0,32,4);
        for(i=0;i<=tinggi;i+=alas/24){
            glTranslatef(0.0,0.0,alas/24);
            glutSolidTorus(alas/4,alas-((i*(alas-atas))/tinggi),16,16);
        }
        glTranslatef(0.0,0.0,alas/4);
        glutSolidCone(atas,0,20,1);
        glColor3f(1.,0.,0.);
    glPopMatrix();
}

void blok(float tebal,int ratiol,int ratiop)
{
    float i,j;
    glPushMatrix();
        for(i=0;i<ratiop;i++){
            glTranslatef(-(ratiol+1)*tebal/2,0.0,0.0);
            for(j=0;j<ratiol;j++){
                glTranslatef(tebal,0.0,0.0);
                glutSolidCube(tebal);
            }
            glTranslatef(-(ratiol-1)*tebal/2,0.0,tebal);
        }
    glPopMatrix();
}
