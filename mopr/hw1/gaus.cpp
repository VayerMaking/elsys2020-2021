#include<bits/stdc++.h>
using namespace std;

#define N 3

int forwardElim(double eq[N][N+1]);
void backSub(double eq[N][N+1]);
void gaussianElimination(double eq[N][N+1]){
    int singular_flag = forwardElim(eq);
    if (singular_flag != -1){
        printf("edenichna matritza.\n");
        if (eq[singular_flag][N])
            printf("nevalidna matritza.");
        else
            printf(" bezkraini resheniq");

        return;
    }
    backSub(eq);
}
void swap_row(double eq[N][N+1], int i, int j){
    for (int k=0; k<=N; k++){
        double temp = eq[i][k];
        eq[i][k] = eq[j][k];
        eq[j][k] = temp;
    }
}
void print(double eq[N][N+1]){
    for (int i=0; i<N; i++, printf("\n")){
        for (int j=0; j<=N; j++){
            printf("%lf ", eq[i][j]);
        }
    printf("\n");
    }
}
int forwardElim(double eq[N][N+1]){
    for (int k=0; k<N; k++){
        int i_max = k;
        int v_max = eq[i_max][k];
        for (int i = k+1; i < N; i++){
            if (abs(eq[i][k]) > v_max)
                v_max = eq[i][k], i_max = i;
        }
        if (!eq[k][i_max]){
            return k;
        }
        if (i_max != k){
            swap_row(eq, k, i_max);
        }
        for (int i=k+1; i<N; i++){
            double f = eq[i][k]/eq[k][k];

            for (int j=k+1; j<=N; j++){
                eq[i][j] -= eq[k][j]*f;
            }
            eq[i][k] = 0;
        }
    }
    return -1;
}
void backSub(double eq[N][N+1]){
    double x[N];

    for (int i = N-1; i >= 0; i--){
        x[i] = eq[i][N];

        for (int j=i+1; j<N; j++){
            x[i] -= eq[i][j]*x[j];
        }

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
