#include <stdio.h>
#include <math.h>

int main() {
    // Variable Declarations
    double income, creditscore, DTI;
    
    // Predetermined Weights from Historical Data
    double Intercept = 5.0;
    double IW = -0.000080;
    double CSW = -0.012000;
    double DTIW = 6.5;

    // User Inputs
    printf("What's your Annual Income ($): ");
    scanf("%lf", &income);
    
    printf("What's your Credit Score (300-850): ");
    scanf("%lf", &creditscore);

    printf("What's your DTI (e.g. 0.25): ");
    scanf("%lf", &DTI);
    
    // Step 1: Compute Raw Score (z)
    double z = Intercept + (income * IW) + (creditscore * CSW) + (DTI * DTIW);
    
    // Step 2: Compute Probability (p) using Sigmoid Function
    double p = 1.0 / (1.0 + exp(-z));
    
    // Step 3: Set Decision Thresholds
    double ApprovedThreshold = 0.05; // 5% default risk
    double ReviewThreshold = 0.20;   // 20% default risk
    
    // Output Probability Percentage
    printf("\n--- Risk Evaluation ---\n");
    printf("Raw Score (z)       : %.4lf\n", z);
    printf("Default Probability : %.2lf%%\n", p * 100.0);
    
    // Step 4: Decision Logic
    if (p <= ApprovedThreshold) {
        printf("Decision: APPROVED\n");
    } 
    else if (p <= ReviewThreshold) {
        printf("Decision: MANUAL REVIEW (Needs Guarantor / Collateral)\n");
    } 
    else {
        printf("Decision: REJECTED\n");
    }

    return 0;
}
