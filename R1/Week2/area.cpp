#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#define MAX 10000

using namespace std;

int abs(const int x)
{
    return x<0?-x:x;
}

class CORD
{
public:
    int x, y;
    CORD()
    {
        x = 0;
        y = 0;
    }
    int operator+(CORD foo)
    {
        return abs(this->x - foo.x)*abs(this->y - foo.y);
    }
    /*
    double operator++(void)
    {
        return sqrt(this->x*this->x + this->y*this->y);
    }
    */
};

int main(void)
{
    CORD data[MAX];
    int maxarea;
    int i, j;
    int foo;
    int term;
    int area;
    cin>>foo;
    while(foo--)
    {
        cin >> term;
        maxarea = 0;
        for(i=0;i<term;i++) cin >> data[i].x >> data[i].y;
        for(i=0;i<term;i++)
        {
            //cout<<++data[i]<<endl;
            for(j=i+1;j<term;j++)
            {
                area = data[i]+data[j];
                if(area>maxarea) maxarea = area;
            }
        }
        cout<<maxarea<<'\n';
    }
    return 0;
}
