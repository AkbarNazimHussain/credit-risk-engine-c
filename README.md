# Quantitative Credit Risk Engine (C)

An execution engine written in C that evaluates borrower loan default probabilities using a **Logistic Regression** framework and the **Sigmoid Activation Function**.

Designed to bridge the gap between financial risk theory and execution, this project demonstrates how statistical scorecard mechanics translate into high-performance, real-time decisioning systems.

---

## Technical Overview

The engine evaluates applicant financial profiles against historical logistic regression weights to produce a linear score ($z$). This score is then mapped through a Sigmoid activation function to output a bounded probability of default $P(\text{Default}) \in [0.0, 1.0]$.

### Key Features
* **Multi-Factor Input Processing:** Evaluates key risk metrics including **Annual Income**, **Credit Score**, and **Debt-to-Income (DTI)** ratio.
* **Logistic Activation:** Uses math library functions (`exp()`) to convert linear combinations into true probabilities.
* **Tiered Risk Governance:** Implements a multi-tier decision structure (**Auto-Approve**, **Manual Review**, **Auto-Reject**) based on risk tolerance cutoffs.
* **Interactive Terminal UI:** Built with ANSI escape codes for visual highlighting in command-line environments.

---

## Mathematical Formulation

### 1. Raw Score Calculation ($z$)
z = Intercept = (Income Weight * Income)+(Credit Score weight * Credit Score)+(DTI Weight * DTI)

Where predetermined weights derived from historical data are:
* **Intercept :** `+5.000000`
* **Income Weight :** `-0.000080`
* **Credit Score Weight :** `-0.012000`
* **DTI Weight :** `+6.500000`

### 2. Sigmoid Activation Function
Probability of Default P(D) = σ(z) = 1/(1+e^-z)

---

## Decision Governance Policy

| Default Probability ($P$) | Status | Operational Action |
| :--- | :--- | :--- |
| P <= 5.0% | **AUTO-APPROVED** | Instant approval; Prime interest rate tier. |
| 5.0 < P <= 20.0% | **MANUAL REVIEW** | Underwriter review required; Guarantor or collateral needed. |
| P > 20.0% | **AUTO-REJECTED** | Automatic denial based on risk tolerance limits. |

---

## Getting Started

### Prerequisites
A standard C compiler (e.g., `gcc` or `clang`).

### Compilation & Execution

1. **Clone the repository:**
   ```bash
   {https://github.com/AkbarNazimHussain/financial-risk-engine-suite.git}(https://github.com/AkbarNazimHussain/financial-risk-engine-suite.git)
   cd financial-risk-engine-suite
