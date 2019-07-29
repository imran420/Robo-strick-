#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include<windows.h>
#include<MMSystem.h>
#include <gl/glut.h>
#include<GL/gl.h>
#define PI 3.14159






int enemyMovingspeed=5;
float _angle,_angle2 = 0.0;float _cameraAngle = 0.0;float _ang_tri = 0.0;GLint m_viewport[4];
bool paused = false;GLint CI=0;
int x,y;int i;int enemyPosition[100];
int pos_index;
int Score=0;int robot_life=100;int GameLvl= 1;
const int GAME_SCREEN= 0;			//background
const int MENU_SCREEN= 4;
const int Highest_enemy_val = 100;
const int enemy_types =5;
const int EnemyRotationSpeed =20;

float mouse_C_X ,mouse_C_Y ;				//Cursor coordinates;
float Fire_Angle=0 ,enemy_Angle =0,lineWidth = 1;float rob_posX=-250,rob_posY=-270;
float enemyX[Highest_enemy_val] ,enemyY[Highest_enemy_val];
float life_bar = 250;




GLint isEnemyAlive[Highest_enemy_val];
bool mPressed= false,startGame=false,gameOver=false;
bool screen_start = true ,next_screen=false,past_screen=false;
bool gameQuit = false, game_menu = false;
char best_score[100],ch;
float cloud_move =0.0f;float cloud_move1 =0.0f;float _trans=0;
void display();
void enemyCreate();
float speed = 0.0f;

float savedSpeed = 0.0f;
float skyclr1=.4;
float skyclr2= 0.7016;
float skyclr3=1;


float cloclr1=.86;
float cloclr2= 0.86;
float cloclr3=.86;

float sunclr1=1.00;
float sunclr2= 0.30;
float sunclr3=0.0;
float piramidclr1=0.78;
float piramidclr2=0.72;
float piramidclr3=0.13;

float piramidclr4=0.84;
float piramidclr5=0.79;
float piramidclr6=0.13;



void robot_bot(){
    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(15,15,0);
    glBegin(GL_POLYGON);


	for(int i=0;i<200;i++)
	{
	    float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=2;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-31,y-8 );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(15,15,20);
    glScalef(15,15,0);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
	    float pi=3.1416;
		float A=(i*2*pi)/400;
		float r=2.3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-31,y-8 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(200,0,100);
    glScalef(15,15,0);
    glBegin(GL_POLYGON);


	for(int i=0;i<200;i++)
	{
	    float pi=3.1416;
		float A=(i*2*pi)/400;
		float r=2.3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-31,y-12);
	}
	glEnd();
    glPopMatrix();

}



void circle(float x, float y, double r )
{
    float x1,y1;
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/25;
		float x1 = x+((r-.05) * cos(A) );
		float y1 = y+((r) * sin(A) );
		glVertex2f(x1,y1);
	}
	glEnd();
}


void desert(){
/*SKY*/
glPushMatrix();

    glTranslatef(01.0, -200, 0.0);
    glScalef(1350.2, 350.8, 0.0);
    glColor3f(skyclr1,skyclr2,skyclr3);
    glBegin(GL_POLYGON);
    //glColor3f(.7333, 0.8666,1);
    glVertex3f(-2.8, 01.0, 0.0);
    glVertex3f(1.5, 01.0, 0.0);
    //glColor3f(.4, 0.7016,1);
    glVertex3f(1.5, 03.0, 0.0);
    glVertex3f(-2.8, 03.0, 0.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    //glBegin(GL_POLYGON);
    glColor3f(piramidclr1,piramidclr2,piramidclr3);

    glBegin(GL_POLYGON);
    glVertex3i(-1350, -325, 0);
    glVertex3i(1350, -325, 0);
    glVertex3i(1350, 150, 0);
    glVertex3i(-1350, 150, 0);
glEnd();
glPopMatrix();

}
void Cloud1()
{
    glPushMatrix();
    glTranslatef(-1400, 400.6, 0.0);
    glPushMatrix();
    glTranslatef(_angle,0,0);
    glScalef(700, 300, 0.0);
    glColor3f(cloclr1,cloclr2,cloclr3);                   ///left
    circle(-.90,0.57,0.15);
    glColor3f(cloclr1,cloclr2,cloclr3);

   circle(-0.79,0.50,0.15);
   glColor3f(cloclr1,cloclr2,cloclr3);
   circle(-0.70,0.50,0.15);
   glColor3f(cloclr1,cloclr2,cloclr3);
   circle(-0.75,0.57,0.15);

    glPopMatrix();
    glPopMatrix();
}
void Cloud2()
{

    glPushMatrix();
    glTranslatef(-1400, 400.6, 0.0);
    glPushMatrix();
   glTranslatef(_angle2,0,0);
    glScalef(700, 300, 0.0);
     glColor3f(cloclr1,cloclr2,cloclr3);
      circle(-0.85,0.57,0.15);
   circle(-0.79,0.50,0.15);
   circle(-0.70,0.50,0.15);
   circle(-0.75,0.57,0.15);
 glPopMatrix();
    glPopMatrix();
}

void sun()
{
    glPushMatrix();
    glTranslatef(1.0, 500.5, 0.0);
    glScalef(400, 300, 0.0);
    glColor3f(sunclr1, sunclr2, sunclr3);                ///sun
	circle(0.25,0.30,0.26);
	glPopMatrix();
}

void piramid()
{
    glColor3f(piramidclr4,piramidclr5,piramidclr6);
    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-700.0, -1.0, -1.0);
	glScalef(200.5,200.5,0); //Move to the center of the trapezoid
    glRotatef(-120 ,1.0, 1.0, 1.0); //Rotate about the z-axis
    glPushMatrix(); //Save the transformations performed thus far
   // glRotatef(_angle ,0.0, 0.0, 1.0); //Rotate about the z-axis
    glutSolidCone(1.5,2.5,10,10);
    glPopMatrix(); //Undo the move to the center of the trapezoid
    glPopMatrix();
    glEnd();

    glColor3f(piramidclr4,piramidclr5,piramidclr6);
    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1200.0, -1.0, 0.0);
	glScalef(270.5,180.5,0); //Move to the center of the trapezoid
    glRotatef(-120 ,1.0, 1.0, 1.0); //Rotate about the z-axis
    glPushMatrix(); //Save the transformations performed thus far
    //glRotatef(_angle ,0.0, 0.0, 1.0); //Rotate about the z-axis
    glutSolidCone(1.5,2.5,10,10);
    glPopMatrix(); //Undo the move to the center of the trapezoid
    glPopMatrix();
    glEnd();

    glColor3f(piramidclr4,piramidclr5,piramidclr6);
    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(1050.0, 100.0, 0.0);
	glScalef(200.5,100.5,0); //Move to the center of the trapezoid
    glRotatef(-120 ,1.0, 1.0, 1.0); //Rotate about the z-axis
    glPushMatrix(); //Save the transformations performed thus far
    //glRotatef(_angle ,0.0, 0.0, 1.0); //Rotate about the z-axis
    glutSolidCone(1.5,2.5,10,10);
    glPopMatrix(); //Undo the move to the center of the trapezoid
    glPopMatrix();
    glEnd();
}
void road(){


glColor3ub(50,50,50);//(R,G,B)
//draw a road
glBegin(GL_POLYGON);
    glVertex3i(-1350, -700, 0);
    glVertex3i(1350, -700, 0);
    glVertex3i(1350, -350, 0);
    glVertex3i(-1350, -350, 0);
glEnd();
// road line
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
    glVertex3i(-1350, -350, 0);
    glVertex3i(1350, -350, 0);
    glVertex3i(1350, -325, 0);
    glVertex3i(-1350, -325, 0);
glEnd();
//road line
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
    glVertex3i(-1350, -700, 0);
    glVertex3i(1350, -700, 0);
    glVertex3i(1350, -675, 0);
    glVertex3i(-1350, -675, 0);
glEnd();



glBegin(GL_POLYGON);
    glVertex3i(-1350, -500, 0);
    glVertex3i(-1000, -500, 0);
    glVertex3i(-1000, -525, 0);
    glVertex3i(-1350, -525, 0);
glEnd();


glBegin(GL_POLYGON);
    glVertex3i(-800, -500, 0);
    glVertex3i(-600, -500, 0);
    glVertex3i(-600, -525, 0);
    glVertex3i(-800, -525, 0);
glEnd();


glBegin(GL_POLYGON);
    glVertex3i(-400, -500, 0);
    glVertex3i(-200, -500, 0);
    glVertex3i(-200, -525, 0);
    glVertex3i(-400, -525, 0);
glEnd();



glBegin(GL_POLYGON);
    glVertex3i(0, -500, 0);
    glVertex3i(200, -500, 0);
    glVertex3i(200, -525, 0);
    glVertex3i(0, -525, 0);

glEnd();



glBegin(GL_POLYGON);
    glVertex3i(400, -500, 0);
    glVertex3i(600, -500, 0);
    glVertex3i(600, -525, 0);
    glVertex3i(400, -525, 0);

glEnd();

glBegin(GL_POLYGON);
    glVertex3i(800, -500, 0);
    glVertex3i(1000, -500, 0);
    glVertex3i(1000, -525, 0);
    glVertex3i(800, -525, 0);
glEnd();


glBegin(GL_POLYGON);
    glVertex3i(800, -500, 0);
    glVertex3i(1000, -500, 0);
    glVertex3i(1000, -525, 0);
    glVertex3i(800, -525, 0);
glEnd();




glBegin(GL_POLYGON);
    glVertex3i(1100, -500, 0);
    glVertex3i(1350, -500, 0);
    glVertex3i(1350, -525, 0);
    glVertex3i(1100, -525, 0);
glEnd();



}

void Text_display(float x ,float y ,float z ,char *stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
		length = strlen(stringToDisplay);

	for(int i=0 ;i<length ;i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,stringToDisplay[i]);
	}
}
void SetDisplayMode(int modeToDisplay) {
		switch(modeToDisplay){
//		    glClear(GL_COLOR_BUFFER_BIT);
//		    glClearColor(0,0,0,1);
		    case GAME_SCREEN: glClearColor(0, 0, 0, 1);break;
		//case GAME_SCREEN: glClearColor(1, 1, 0, 1);break;
		case MENU_SCREEN : glClearColor(0.5, 1 , 1, 1);break;
	}
}
void set_enemy_possition() {


	for(int i = 0;i < Highest_enemy_val ;i++) {
		enemyPosition[i]=rand()%enemy_types;
		isEnemyAlive[i]=true;
	}

	enemyX[0] = -(200*Highest_enemy_val)-600;             //STARTING LINE

	for(int i = 0;i<Highest_enemy_val ;i++) {
		enemyY[i]=rand()%600;
		if(int(enemyY[i])%2)
			enemyY[i]*=-1;
		enemyX[i+1] = enemyX[i] + 200;
	}
}
void update(int value) {
	_angle += 3.50f;
	if (_angle > 3360) {
		_angle -= 3360;
	}
	_angle2 += 4.2f;
	if (_angle2 > 3360) {
		_angle2 -= 3360;
	}
/*	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}
	*/
_trans += 1.5f;
	if (_trans >7 ) {
		_trans = -6.0f;

	}

	glutPostRedisplay();

	glutTimerFunc(10, update, 0);
}



void Draw_Robo_car()
{

glPushMatrix();
glTranslated(-5.0,-5.0,0.0);
   ///big polygon
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);

    glVertex3i(-300, 100, 0);
    glVertex3i(-300, -50, 0);
    glVertex3i(-125,-50, 0);
    glVertex3i(-125,100, 0);
    glEnd();

   ///HEAD POLYGON
   glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glColor4f(0, 1, 1,0.5);
    glVertex3i(-265, 100, 0);
    glVertex3i(-160, 100, 0);
    glVertex3i(-160,150, 0);
    glVertex3i(-265,150, 0);
    glEnd();

      ///Front END POLYGON
glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);

    glVertex3i(-125, -50, 0);
    glVertex3i(20, -50, 0);
    glVertex3i(20,10, 0);
    glVertex3i(-125,10, 0);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(170, 100, 150);
    glVertex3i(20, 10, 0);
    glVertex3i(20, 140, 0);
    glEnd();
    ///wheels
glPushMatrix();
     glColor3ub(0,0,0);
     glTranslated(-1.46, -1.0, 0);
     glScalef(20,20,0);
     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-8,y-2.5 );
	}
	glEnd();
glPopMatrix();

glPushMatrix();
     glColor3ub(0,0,0);
    glTranslated(-1.46, -1.0, 0);
     glScalef(20,20,0);
     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-12,y-2.5 );
	}
	glEnd();
glPopMatrix();
///upper sphere
glPushMatrix();

glTranslatef(20.5, 120.0, 0.0);
glRotatef( 90,1.0, 0.0, 0.0);
glPushMatrix();

glColor3ub(255,0,0);

glRotatef( _angle,0.0, 0.0, 1.0);
glutWireSphere(20,10,10);
glPopMatrix();


glPopMatrix();

}

void Firing_point() {

	glColor3f(1, 1, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);           //Lazer stick
		glVertex2f(-55 ,10);
		glVertex2f(-55 ,30);
		glVertex2f(-50, 30);
		glVertex2f(-50 ,10);
	glEnd();

	float xMid =0,yMid =0;
	//Mid point of the lazer horizontal
	xMid = (55+50)/2.0;
	yMid = (25+35)/2.0;

	//Rotating about the point ,20
	glTranslated(-xMid, yMid, 0);
	glRotated(Fire_Angle, 0, 0 ,1);
	glTranslated(xMid , -yMid ,0);

	//find mid point of top of lazer stem
	float midPoint = -(55+50)/2.0;


	glPopMatrix();
}

void Firing_Path() {

	float xMid = -(55+50)/2.0;
	float yMid = (25+35)/2.0;

	float mouse_C_XEnd = -((- mouse_C_X) + rob_posX);
	float mouse_C_YEnd = -((- mouse_C_Y) + rob_posY);
	glLineWidth(5);   //----Laser beam width

	glColor3f(0, 0, 0);
	// LASER LIGHT..............................................
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(1, 0x1000);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(xMid ,yMid);
    glVertex2f(mouse_C_XEnd ,mouse_C_YEnd);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

	glColor3f(1, 0, 0);
	glTranslatef(mouse_C_XEnd ,mouse_C_YEnd,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*4*pi)/200;
		float r=10.0;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
	glLineWidth(5);
}

void enemy(void){

glPushMatrix();
glRotatef(-18,0,1,1);
glTranslatef(2,-1,0);
glScalef(2.0,2.0,0);
glPushMatrix();



glPushMatrix();

	//glTranslatef(1.0, 3.0, 0.0); //Move to the center of the triangle
	glScalef(0.5,0.5,0);
    glColor3ub(0,0,240);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*4*pi)/700;
		float r=2.0;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
glPopMatrix();

///////////WING //////////////
glPushMatrix();
glColor3ub(220,220,0);
//glRotatef(_angle,0.0,1.0,0.0);
glTranslatef(0.3, 0.0, 0.0);

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/550;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
glPopMatrix();


/////////////EYE
glPushMatrix();
glColor3ub(255,255,255);
//glRotatef(_angle,0.0,1.0,0.0);
glTranslatef(-0.6, 0.2, 0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.17;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glPopMatrix();

	glPushMatrix();
glColor3ub(0,0,0);
glScalef(0.5,0.5,0);
//glRotatef(_angle,0.0,1.0,0.0);
glTranslatef(-1.1, 0.4, 0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.17;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glPopMatrix();
////////////HORNS/////////////////////
    glPushMatrix();
    glColor3ub(100,0,0);
     glTranslatef(-1.46, -0.1, 0.1);
     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/950;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

    glPopMatrix();



    glPushMatrix();
//glColor3ub(100,100,0);
     glTranslatef(-1.0, 0.6, 0.0);
     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/950;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

    glPopMatrix();

    glPushMatrix();
     glTranslatef(-0.3, 0.8, 0.0);
     glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/950;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

    glPopMatrix();

  glPopMatrix();

  glPopMatrix();
}

void enemy_display(int epos_index)
{
	glPushMatrix();
	glLoadIdentity();
	switch(epos_index)
	{
	case 0:

		glTranslated(-enemyX[pos_index] , enemyY[pos_index] ,0);
		//glRotatef(enemy_Angle ,0, 0, 1);
		glTranslated(0, 0, 0);
		glColor3f(0.4f, 0.0f, 0.0f);
		glScalef(15,20,1);
        enemy();
        glLoadIdentity();
	break;

	case 1:
		glColor3f(1.0f, 0.8f, 0.8f);
		glTranslated(-enemyX[pos_index] , enemyY[pos_index] ,0);
		glTranslated(0, 0, 0);
		glScalef(15,20,1);
		enemy();
		glLoadIdentity();
    break;

	case 2:
		glColor3f(0.2f, 0.2f, 0.0f);
		glTranslated(-enemyX[pos_index] , enemyY[pos_index] ,0);
		glTranslated(0, 0, 0);
		glScalef(15,20,1);
        enemy();
		glLoadIdentity();

		break;

	case 3:
		glColor3f(0.8f, 0.8f, 0.1f);
		glTranslated(-enemyX[pos_index] , enemyY[pos_index] ,0);
		glTranslated(0, 0, 0);
		glScalef(15,20,1);
		enemy();
		glLoadIdentity();
		break;
	case 4:
		glColor3f(0.26f, 0.26f, 0.26f);
		glTranslated(-enemyX[pos_index] , enemyY[pos_index] ,0);
		glTranslated(0, 0, 0);
		glScalef(15,20,1);
		enemy();
		glLoadIdentity();
		break;
	}
	glPopMatrix();
}
bool robo_collision() {
		for(int i =0 ;i<Highest_enemy_val ;i++) {
		if(isEnemyAlive[i]&((rob_posX >= (-enemyX[i]/2 -10 ) && rob_posX <= (-enemyX[i]/2 + 330) && rob_posY >= (enemyY[i]/2 -195 ) && rob_posY <= (enemyY[i]/2 + 50)) ))
		{
			isEnemyAlive[i]=0;
			return true;
		}
	}
	return false;
}
void robot_create(){
	glPushMatrix();
	glTranslated(rob_posX,rob_posY,0);
	if(robo_collision() && robot_life ){
		robot_life-=10;
		life_bar -= 170;
	}

	glPushMatrix();
	glTranslated(4,19,0);
	glPopMatrix();
	Draw_Robo_car();
	Firing_point();
	if(mPressed) {
		Firing_Path();
	}
	glEnd();
	glPopMatrix();
}

void Draw_life_bar() {
    glPushMatrix();
    glTranslatef(0.0,-1350.0,0.0);
	glColor3f(0 ,0 ,1);
	glBegin(GL_POLYGON);
		glVertex2f(-life_bar ,700);
		glVertex2f(1350 ,700);
		glVertex2f(1350 ,670);
		glVertex2f(-life_bar, 670);
	glEnd();
	glPopMatrix();

	char temp[40];
	glPushMatrix();
	glTranslatef(850,-1225,0);
	glColor3f(1 ,1 ,1);
	sprintf(temp,"SCORE = %d",Score);

	Text_display(-1100 ,600 ,0.4 ,temp);
    glPopMatrix();            //<variable score
	glColor3f(1 ,0 ,0);


}
void screen_startDisplay()
{

   glLineWidth(50);
   SetDisplayMode(MENU_SCREEN);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glColor4f(0,0,1,.5);
   glBegin(GL_POLYGON);
		glVertex3f(-1360 ,-700 ,0.5);
		glVertex3f(1370 ,-700 ,0.5);
		glVertex3f(1370 ,700 ,0.5);
		glVertex3f(-1360 ,700, 0.5);
	glEnd();

	glLineWidth(1);

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);				//PLAY GAME PLOYGON
		glVertex3f(-200 ,300 ,0.5);
		glVertex3f(-200 ,400 ,0.5);
		glVertex3f(200 ,400 ,0.5);
//		glVertex3f(200 ,300, 0.5);
	glEnd();
glBegin(GL_POLYGON);
glColor3f(.5,1,0);				//PlAY GAME PLOYGON
		glVertex3f(-200 ,300 ,0.5);
		//glVertex3f(-200 ,400 ,0.5);
		glVertex3f(200 ,300 ,0.5);
		glVertex3f(200 ,400, 0.5);
	glEnd();

	glBegin(GL_POLYGON);				//EXIT POLYGON
	glColor3f(0,1,0);
		glVertex3f(-200, 50 ,0.5);
		glVertex3f(-200 ,150 ,0.5);
		glVertex3f(200 ,150 ,0.5);
		//glVertex3f(200 ,50, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);				//EXIT POLYGON
		glVertex3f(-200, 50 ,0.5);
	//glColor3f(0,1,0);
		//glVertex3f(-200 ,150 ,0.5);
		glVertex3f(200 ,50 ,0.5);
	//glColor3f(0,0,1);
		glVertex3f(200 ,150, 0.5);
	glEnd();
	if(mouse_C_X>=-100 && mouse_C_X<=100 && mouse_C_Y>=150 && mouse_C_Y<=200){
		glColor3f(1 ,0 ,1) ;
		if(mPressed){
			startGame = true ;
			gameOver = false;
			mPressed = false;
		}
	} else
		glColor3f(0 , 0, 0);
	Text_display(-100 ,340 ,0.4 ,"Play Game");

	if(mouse_C_X>=-100 && mouse_C_X<=100 && mouse_C_Y>=30 && mouse_C_Y<=80) {
		glColor3f(0 ,0 ,1);
		if(mPressed){
			gameQuit = true ;
			mPressed = false;
		}
	} else
		glColor3f(0 , 0, 0);
	Text_display(-120 ,80 ,0.4 ,"     Exit");


    glColor3f(1,1, 0);
	Text_display(-200 ,-180 ,0.8 ,"How to Play ---  Left click of mouse to kill enemy and score!!!! *****");

	 glColor3f(1,1, 0);
	Text_display(-200 ,-300 ,0.8 ," ***** Press 'n' For Night Mode!!!! *****");

}
void GameScreenDisplay()
{

	SetDisplayMode(GAME_SCREEN);
    //glColor3f(1,0,1);

	road();

    desert();
	piramid();
	sun();
	Cloud2();
	Cloud1();
	Draw_life_bar();

	glScalef(2, 2 ,0);
	if(robot_life){
       robot_create();
	}
	else {
		gameOver=true;
		screen_start = false;
	}
	enemyCreate();
	 robot_bot();

}
void readFromFile() {

	FILE *fp = fopen("HighScoreFile.txt" ,"r");
	int i=0;
	if(fp!= NULL){
		while(fread(&ch,sizeof(char),1 ,fp)){
			best_score[i++] = ch;
		}
		best_score[i] = '\0';
	}
	fclose(fp);
}
void writeIntoFile() {
	FILE *fp = fopen("HighScoreFile.txt" ,"w");
	int i=0;
	char temp[40];
	if(fp!= NULL){
		int n= Score;
		while(n){
			ch = (n%10)+ '0';
			n/=10;
			temp[i++] = ch;
		}
		temp[i] = '\0';
		strrev(temp);
		puts(temp);
		if(temp[0] == '\0')
			temp[i++] = '0' ,temp[i++] = '\0';
		fwrite(temp ,sizeof(char)*i ,i ,fp);
	}
 fclose(fp);
}
void GameOverScreen()
{
	SetDisplayMode(MENU_SCREEN);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glColor3f(.5, 0, .8);
    glPushMatrix();
    glBegin(GL_POLYGON);

    glTranslated(0.0,9.0,0.0);
	for(int i=0;i<200;i++)
	{
	    float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=200;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+100 );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);

    glColor3f(1,0,0);
	for(int i=0;i<200;i++)
	{
	    float pi=3.1416;
		float A=(i*2*pi)/400;
		float r=200;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-1000,y+350 );
	}
	glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);

    glColor3f(1,0,1);
	for(int i=0;i<200;i++)
	{
	    float pi=3.1416;
		float A=(i*2*pi)/400;
		float r=200;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+1100,y+300 );
	}
	glEnd();
    glPopMatrix();

	glBegin(GL_POLYGON);				//QUIT POLYGON
		glVertex3f(-200 ,-200 ,0.5);
		glVertex3f(-200 ,-100 ,0.5);
		glVertex3f(200, -100 ,0.5);
		glVertex3f(200, -200 ,0.5);
	glEnd();

	glColor3f(0 , 0, 0);
	char temp[40];

	sprintf(temp,"Score : %d",Score);
	Text_display(1000 ,340 ,0.4 ,temp);
	readFromFile();
	char temp2[40];
	if(atoi(best_score) < Score){
		writeIntoFile();
		sprintf(temp2 ,"Highest Score :%d" ,Score);
	} else
		sprintf(temp2 ,"Highest Score :%s" ,best_score);

	Text_display(-1150 ,400 ,0.4 ,temp2);

	if(mouse_C_X>=-100 && mouse_C_X<=100 && mouse_C_Y>=25 && mouse_C_Y<=75){
		glColor3f(0 ,0 ,1);
		if(mPressed){                                                       //Reset game default values
			startGame = true ;
			gameOver=false;
			mPressed = false;
			set_enemy_possition();
			robot_life=100;
			life_bar=250;
			Score=0;
			GameLvl=1;
			GameScreenDisplay();
		}
	} else
		glColor3f(0 , 0, 0);
	Text_display(-70 ,80 ,0.4 ,"Restart");

	if(mouse_C_X>=-100 && mouse_C_X<=100 && mouse_C_Y>=-100 && mouse_C_Y<=-50){
		glColor3f(0 ,0 ,1);
		if(mPressed){
			exit(0);
			mPressed = false;
		}
	}
	else
		glColor3f(0 , 0, 0);
	Text_display(-100 ,-170 ,0.4 ,"    Quit");

}
void enemyCreate(){

		if(enemyX[0]>=-1200){

			Score+=50;
			set_enemy_possition();
			GameScreenDisplay();
		}

	for(int i=0; i<Highest_enemy_val ;i++){
		pos_index = i;

		if(mouse_C_X <= (-enemyX[i]/2+20) && mouse_C_X >=(-enemyX[i]/2-20) && mouse_C_Y >= (enemyY[i]/2-20) && mouse_C_Y <= (enemyY[i]/2+20) && mPressed){
			if(isEnemyAlive[i]){   // IF ALIVE KILL ENEMY
				isEnemyAlive[i]=0;
				Score=Score+10;
				if(Score%35==0) {

					enemyMovingspeed+=1;
				}
			}
		}
		enemyX[i] += enemyMovingspeed;
		if(isEnemyAlive[i] )             //Enemy alive
			enemy_display(enemyPosition[i]);
	}
	enemy_Angle+=EnemyRotationSpeed;
	if(enemy_Angle > 360) enemy_Angle = 0;
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,1350,700);
	if(startGame && !gameOver)
    {
		GameScreenDisplay();
    }

	else if(gameOver)
		GameOverScreen();

	else if(screen_start){
			screen_startDisplay();
			if(gameQuit || startGame || game_menu ){
				//screen_start = false;
				if(startGame){
					SetDisplayMode(GAME_SCREEN);
					screen_start = false;

				} else if(gameQuit)
					exit(0);

				}
		}

	//Reset Scaling values
	glScalef(1/2 ,1/2 ,0);
	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
}
void Fire_Angle_calculation() {

	float mouse_C_XForTan = (-50 - mouse_C_X) + rob_posX;
	float mouse_C_YForTan = (35 - mouse_C_Y) + rob_posY;
	float Fire_AngleInRadian = atan(mouse_C_YForTan/(mouse_C_XForTan));
	Fire_Angle = (180/PI) * Fire_AngleInRadian;
}
bool nightDay = true;
void keys(unsigned char key, int x, int y)
{
switch(key){
    case 'n' :

        if (nightDay)
        {
             skyclr1=0;
             skyclr2= 0.20;
             skyclr3=0.30;

             cloclr1=0.17;
             cloclr2=0.12;
             cloclr3=0.14;

             sunclr1=1.0;
             sunclr2=1.0;
             sunclr3=1.0;

             piramidclr1=0.39;
             piramidclr2=0.37;
             piramidclr3=0.09;


             piramidclr4=0.55;
             piramidclr5=0.51;
             piramidclr6=0.0;

            nightDay=false;
        }
        else{
             skyclr1=.4;
             skyclr2= 0.7016;
             skyclr3=1;

             cloclr1=.86;
             cloclr2=.86;
             cloclr3=.86;

             sunclr1=1.0;
             sunclr2=0.30;
             sunclr3=0.0;

             piramidclr1=0.78;
             piramidclr2=0.72;
             piramidclr3=0.13;

             piramidclr4=0.84;
             piramidclr5=0.79;
             piramidclr6=0.13;

            nightDay=true;

        }


         break;
         //display();
		//case MENU_SCREEN : glClearColor(0.5, 1 , 0, 1);break;
	}

}
void myinit()
{
	glClearColor(0.5,0.5,0.5,0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    gluOrtho2D(-1350,1350,-700,700);
//  gluOrtho2D(-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);
}
void passiveMotionFunc(int x,int y) {


	mouse_C_X = float(x)/(m_viewport[2]/1350.0)-675.0;
	mouse_C_Y = -(float(y)/(m_viewport[3]/700.0)-350.0);


	Fire_Angle_calculation();
	display();
}
 void mouseClick(int buttonPressed ,int state ,int x, int y) {

	if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mPressed = true;
		 paused = !paused;
              // Toggle state
      if (paused) {
         //savedSpeed = speed;  // Save parameters for restore later
       //  speed = 0;            // Stop movement
        Beep(950,50);
      } else {
        // speed = savedSpeed;  // Restore parameters
         Beep(950,50);
      }
	}
      else{
		mPressed = false;
        display();
      }
}


 void idleCallBack() {			//when no mouse or keybord pressed
	 display();
 }
 int main(int argc, char** argv) {

	 FILE *fp = fopen("HighScoreFile.txt" ,"r") ;      //check if best_scoreFile.txt exist if not create
	 if(fp!=NULL)
		fclose(fp);
	 else
		 writeIntoFile();

	glutInit(&argc, argv);
	glutInitWindowSize(1350,700);
	glutInitWindowPosition(90 ,0);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutCreateWindow("ROBOT STRIKE");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutPassiveMotionFunc(passiveMotionFunc);
	glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA);
	glutIdleFunc(idleCallBack);
	glutMouseFunc(mouseClick);
	glutTimerFunc(25, update, 0);
	glGetIntegerv(GL_VIEWPORT ,m_viewport);
	myinit();
	SetDisplayMode(GAME_SCREEN);
	set_enemy_possition();
	sndPlaySound("game_sound.wav",SND_ASYNC|SND_LOOP);
    ///glutFullScreen();
	glutMainLoop();
 }
