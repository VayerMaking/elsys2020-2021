#include<bits/stdc++.h>
using namespace std;

#define N 3


int forwardElim(double eq[N][N+1]);
void backSub(double eq[N][N+1]);
void gaussianElimination(double eq[N][N+1]){
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(eq);

    /* if matrix is singular */

    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");

        // if the RHS of equation corresponding to
        //   zero row  is 0, * system has infinitely
        //   many solutions, else inconsistent
        if (eq[singular_flag][N])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return;
    }

    /* get solution to system and print it using
       backward substitution */
    backSub(eq);
}

// function for elementary operation of swapping two rows
void swap_row(double eq[N][N+1], int i, int j){
    //printf("Swapped rows %d and %d\n", i, j);

    for (int k=0; k<=N; k++){
        double temp = eq[i][k];
        eq[i][k] = eq[j][k];
        eq[j][k] = temp;
    }
}

// function to print matrix content at any stage
void print(double eq[N][N+1]){
    for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<=N; j++)
            printf("%lf ", eq[i][j]);

    printf("\n");
}

// function to reduce matrix to r.e.f.
int forwardElim(double eq[N][N+1]){
    for (int k=0; k<N; k++){
        // Initialize maximum value and index for pivot
        int i_max = k;
        int v_max = eq[i_max][k];

        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < N; i++){
            if (abs(eq[i][k]) > v_max)
                v_max = eq[i][k], i_max = i;
        }
        /* if a prinicipal diagonal element  is zero,
         * it denotes that matrix is singular, and
         * will lead to a division-by-zero later. */
        if (!eq[k][i_max]){
            return k; // Matrix is singular
        }
        /* Swap the greatest value row with current row */
        if (i_max != k){
            swap_row(eq, k, i_max);
        }

        for (int i=k+1; i<N; i++){
            /* factor f to set current row kth element to 0,
             * and subsequently remaining kth column to 0 */
            double f = eq[i][k]/eq[k][k];

            /* subtract fth multiple of corresponding kth
               row element*/
            for (int j=k+1; j<=N; j++){
                eq[i][j] -= eq[k][j]*f;
            }
            /* filling lower triangular matrix with zeros*/
            eq[i][k] = 0;
        }

        //print(mat);        //for matrix state
    }
    //print(mat);            //for matrix state
    return -1;
}

// function to calculate the values of the unknowns
void backSub(double eq[N][N+1]){
    double x[N];  // An array to store solution

    /* Start calculating from last equation up to the
       first */
    for (int i = N-1; i >= 0; i--){
        /* start with the RHS of the equation */
        x[i] = eq[i][N];

        /* Initialize j to i+1 since matrix is upper
           triangular*/
        for (int j=i+1; j<N; j++){
            /* subtract all the lhs values
             * except the coefficient of the variable
             * whose value is being calculated */
            x[i] -= eq[i][j]*x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i]/eq[i][i];
    }

    printf("\notg:\n");
    for (int i=0; i<N; i++){
        printf("%lf\n", x[i]);
    }
}

int main(){

    double eq1[N][N+1] = {{1.2, 4.0 * 135.0, 2.0 * 613.0, 31.18027},
                          {-3.0 * 851, -2.0 * 719.0, 16.0 * 712.0, -51.40619},
                          {2.0 * 314.0, 23.0 * 187.0, 5.0 * 617.0, -15.98744}
                         };
    double eq2[N][N+1] = {{2.0, 2.0, 1.0, 14.0},
                          {1.0, 1.0, 1.0, -11.0},
                          {4.0, 2.0, 3.0, 44.0}
                        };
    gaussianElimination(eq1);
    gaussianElimination(eq2);

    return 0;
}
