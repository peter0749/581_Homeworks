#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#define DEFAULTW 1024
#define DEFAULTH 1024
#define MAX 1000
using namespace std;

typedef struct
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}COLOR;

/* CLASS FOR IMAGE GENERATION */
class Draw
{
	protected:
		COLOR *pCLR;/*Pointer of image.*/
		unsigned int depth;/*Depth of color.*/
		unsigned int resX,resY;/*Resolution*/
	public:
		Draw(const unsigned int x, const unsigned int y, const unsigned int d, const COLOR BACKGROUND);/*Constructor of graph generator*/
		~Draw(void);
		inline void setCOL(const unsigned int x, const unsigned int y, COLOR c);/* Write the pixel */
		inline COLOR readCOL(const unsigned int x, const unsigned int y);/* Read the pixel */
		bool wTOPPM(const char *Filename);/*Write to file.*/
		inline unsigned int getX(void){return resX;}/*Return the resolution of x-axis.*/
		inline unsigned int getY(void){return resY;}/*Return the resolution of y-axis.*/
};

Draw::Draw(const unsigned int x, const unsigned int y, const unsigned int d, const COLOR BACKGROUND)
{
	pCLR=NULL;
	depth = d;
	resX = x;
	resY = y;
	pCLR = new COLOR[resX*resY];
	assert(pCLR);
	for(int i=resY*resX-1; i>=0; i--)
	{
		pCLR[i] = BACKGROUND;
	}
}

Draw::~Draw(void)
{
	if(pCLR==NULL)return;
	delete [] pCLR;
	pCLR = NULL;
}

inline void Draw::setCOL(const unsigned int x, const unsigned int y, COLOR c)
{
	assert(pCLR);
	pCLR[x+resX*y] = c;
}

inline COLOR Draw::readCOL(const unsigned int x, const unsigned int y)
{
	assert(pCLR);
	return pCLR[x+y*resX];
}

bool Draw::wTOPPM(const char *Filename)
{
	FILE *FP=NULL;
	FP = fopen(Filename,"wb");
	if(FP==NULL)return false;
	fprintf(FP,"P6 %d %d %d\n",(int)resX,(int)resY,(int)depth);
	fwrite(pCLR, 1, 3*resX*resY, FP);
	fclose(FP);FP=NULL;
	return true;
}
/*END OF THE CLASS*/

inline long double GUASS(const long double x)
{
	return ( 1.0L/(sqrt(M_PI*2.0L)) ) * exp(-x*x / 2.0L);
}

inline long double PDF(const long double x)
{
	return ( (1.0L/sqrt( M_PI*2.0L*10.0L )) * exp(-x*x / (2.0L*100.L))  );
}

inline long double absTAN(const long double x)
{
	return abs(tan(x));
}

inline long double TANabs(const long double x)
{
	return tan( abs(x) );
}

inline long double integral( long double(*f)(const long double), const long double from, const long double to, const long double t , Draw &image, const long double scale)
{
	long double i;
	long double total=0.0L;
	long double temp;
	int x, y;
	int c_x = DEFAULTW/2;
	int c_y = DEFAULTH/2;
	COLOR si;
	si.R=si.G=si.B=255;
	for(i=from; i<to; i+=t)
	{
		temp = f(i);
		total += temp*t;
		x = scale * i + c_x;
		y = scale * (-temp) + c_y;
		if(x>=0 && y>=0 && x<DEFAULTW && y<DEFAULTH)
			image.setCOL(x,y,si);/*Set the pixel*/
		//cout<<total<<endl;
	}
	return total;
}

int main( int argc, char *argv[]  )
{
	char temp[MAX];
	long double m,n,t,s;
	if(argc<6)
	{
		cout<<"Invalid Input!\n";
		cout<<"exec.exe f from to t scale\n";
		return -1;
	}
	COLOR clr;
	clr.R=clr.G=clr.B=0;
	Draw img(DEFAULTW,DEFAULTH,255,clr);/*Initialize a image.*/
	m = atof( argv[2] );
	n = atof( argv[3] );
	t = atof( argv[4] );
	s = atof( argv[5] );
	if(strcmp(argv[1],"sin")==0)
	{
		cout<<integral(sin, m, n, t, img, s)<<'\n';
	}
	else if(strcmp(argv[1],"cos")==0)
	{
		cout<<integral(cos, m, n, t, img, s)<<'\n';
	}
	else if(strcmp(argv[1],"tan")==0)
	{
		cout<<integral(tan, m, n, t, img, s)<<'\n';
	}
	else if(strcmp(argv[1],"abstan")==0)
	{
		cout<<integral(absTAN,m,n,t,img,s)<<'\n';
	}
	else if(strcmp(argv[1],"tanabs")==0)
	{
		cout<<integral(TANabs,m,n,t,img,s)<<'\n';
	}
	else if(strcmp(argv[1],"GUASS!")==0)
	{
		cout<<integral(GUASS, m, n, t, img, s)<<'\n';
	}
	else if(strcmp(argv[1],"PDF")==0)
	{
		cout<<integral(PDF,m,n,t,img,s)<<'\n';
	}
	else if(strcmp(argv[1],"Mandelbrot!")==0)
	{
		/*Generate a part of Mandelbrot SET*/
		cout<<";)\n";
		int i, j;
		int c_x = DEFAULTW/2;
		int c_y = DEFAULTH/2;
		for(i=0; i<DEFAULTW; i++)
		{
			for(j=0; j<DEFAULTH; j++)
			{
				long double R = (i-c_x)*s + m;
				long double I = (j-c_y)*s + n;
				long double temp=0.0L;
				long double cr, ci, nr, ni;
				float cl_t;
				cr = ci = nr = ni = 0.0;
				int step = 0;
				while(temp < 4.0L && step < t)
				{
					nr = cr*cr - ci*ci + R;
					ni = cr*ci;
					ni += ni;/*2.0*r*i a little boost*/
					ni += I;
					if(nr==cr && ni==ci)
					{
						step = t;break;/*A little boost, from wiki.*/
					}
					ci = ni; cr = nr;
					temp = ci*ci+cr*cr;
					step++;
				}
				if(t==step)
				{
					clr.B=clr.G=clr.B = 0;
				}
				else
				{
					cl_t = (float)step/(float)t;
					clr.R = 0; clr.G = cl_t/2.0L*255.0L; clr.B = cl_t*255.0L;
				}
				img.setCOL(i,j,clr);
			}
		}
	}
	else
		return -2;
	img.wTOPPM("GRAPH.ppm");
	return 0;
}
