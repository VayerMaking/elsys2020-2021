#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void read(double arr[], const char * filename)
{
    ifstream info;
    info.open (filename);
    string num_string;
    double num;

    for (int i = 0; i < 3; i++)
    {
        getline(info, num_string, ' ');
        num = stod(num_string);
        arr[i] = num;
    }

}

int check_ball_size(int ball_d, int board_s)
{
    if(ball_d > board_s/10) return 0;
    return 1;
}

int verify(double x, double y)
{
    
    return 1;
}

double board_coordinates()
{
    int xb1, yb1;
    int xb2, yb2;
    int xb3, yb3;
    int xb4, yb4;

    double bigger;
    double smaller;

    int i = 0;

    do{ 
        if(i > 0)
        {
            cout << endl;
            cout << "Wrong coordinates! Board sides must be 1:2!" << endl;
        }
        if(i == 0) cout << "Board coordinates" << endl;
        cout << "down left X (int): ";
        cin >> xb1;
        cout << "down left Y (int): ";
        cin >> yb1;

        if(xb1 == yb1 && xb1 == 0)
        {
            cout << "up right X (int): ";
            cin >> xb3;
            cout << "up right Y (int): ";
            cin >> yb3;
            if(xb3/2 == yb3)
            {
                xb2 = 0;
                yb2 = yb3;
                xb4 = xb3;
                yb4 = 0;
                smaller = yb3;
                bigger = yb3*2;

                break;
            }
            else 
            {
                i++;
                continue;
            }
        }

        cout << "up left X (int): ";
        cin >> xb2;
        cout << "up left Y (int): ";
        cin >> yb2;

        cout << "up right X (int): ";
        cin >> xb3;
        cout << "up right Y (int): ";
        cin >> yb3;

        cout << "down right X (int): ";
        cin >> xb4;
        cout << "down right Y (int): ";
        cin >> yb4;

        int a1 = abs(xb1 - xb2);
        int b1 = abs(yb1 - yb2);
        int lenght_of_one_size = sqrt(abs(a1*a1 + b1*b1));

        int a2 = abs(xb3 - xb2);
        int b2 = abs(yb3 - yb2);
        int lenght_of_other_size = sqrt(abs(a2*a2 + b2*b2));

        if(lenght_of_other_size > lenght_of_one_size)
        {
            bigger = lenght_of_other_size;
            smaller = lenght_of_one_size;
        }else
        {
            smaller = lenght_of_other_size;
            bigger = lenght_of_one_size;
        }

        i++;

    }while (bigger != smaller/2);
    
    return smaller;
}


void choices(int* ball_d, int small_side)
{
    int choice;
    cout << endl;
    cout << "Choose ball diameter: " << endl;
    cout << "     optipon 1: Defalt (10)" << endl;
    cout << "     optipon 2: custom" << endl;

    cin >> choice;
    if (choice == 1) *ball_d = 10;
    if (choice == 2)
    {
        cout << endl;
        cout << "write int: ";
        cin >> *ball_d;
        while(!check_ball_size(*ball_d, small_side))
        {
            cout << "Wrong ball diameter" << endl;
            cout << "Max diameter is " << small_side/10 << endl;
            cout << "write int: ";
            cin >> *ball_d;
        }
    }
    
}

void start_p(int * xp, int * yp)
{
    cout << endl;
    cout << "Choose start point: " << endl;
    cout << "     X: ";
    cin >> *xp;
    cout << "     Y: " ;
    cin >> *yp;
    while (!verify(*xp, *yp))
    {
        cout << endl;
        cout << "Try again" << endl;

        cout << "Choose start point: " << endl;
        cout << "     X: ";
        cin >> *xp;
        cout << "     Y: " ;
        cin >> *yp;
    }
}

int check_power(double arr[])
{
    if(arr[0] >5 || arr[0] < 2) return 0;
    return 1;
}

int check_vect_lenght(int board_l, int x, int y, double arr[])
{
    int a = abs(x - arr[1]);
    int b = abs(y - arr[2]);
    int lenght = sqrt(abs(a*a + b*b));

    if(lenght < board_l/10 || lenght > (board_l*3)/10)
    {
        cout << endl;
        cout << "Vect lenght not correct!" << endl;
        cout << "Correct file or strat point" << endl;
        return 0;
    } 

    return 1;
}



void next_point(double arr[], int xp, int yp)
{
    int nextx = (arr[1]-xp)*arr[0] + xp;
    int nexty = (arr[2]-yp)*arr[0] + yp;

    if (nextx )
    {
        /* code */
    }
    

    cout << nextx << endl;
    cout << nexty << endl;



}

double* find_A_B(double arr[], int x1, int y1, int x2, int y2)
{
    double A = (y1 - y2) / (x1 + x2);
    double B = y1 - A*x1;
    arr[0] = A;
    arr[1] = B;
    

    return arr;                                                                                                                               
}

int main(int argc, char const *argv[])
{
    double arr[3]; 
    int ball_d;
    int x_start;
    int y_strat;
    double small_side;

    read(arr, argv[1]);
    small_side = board_coordinates();
    choices(&ball_d, small_side);
    if(!check_power(arr))
    {
        cout << "Fist num in file has to be in range 2 to 5!" << endl;
        cout << "Example: 3.7" << endl;
        return 0;
    
    }
    start_p(&x_start, &y_strat);

    // cout << small_side*2<< endl;
    // cout << x <<endl;
    // cout << y <<endl;
    // cout << arr[1] <<endl;
    // cout << arr[2] <<endl;


    if(check_vect_lenght(small_side*2, x_start, y_strat, arr) == 0) return 0;

    next_point(arr, x_start, y_strat);

    //while (1)
    {
    }
    





    // cout << arr[1];

    return 0;
}

