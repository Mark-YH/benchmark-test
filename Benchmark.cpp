//
// Created by Mark Hsu on 2021/5/25.
//

#include "Benchmark.h"
#include <cmath>
#include <stdexcept>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989f

float Benchmark::absolute(vector<float> x) {
    /**
     * domain [-100, 100]
     */
    float fx = 0.0;
    for (int i = 0; i < x.size(); i++) {
        fx += abs(x[i]);
    }
    return fx;
}

float Benchmark::sphere(vector<float> x) {
    /**
     * domain [-100, 100]
     */
    float fx = 0.0;
    for (int i = 0; i < x.size(); i++) {
        fx += x[i] * x[i];
    }
    return fx;
}

float Benchmark::ackley(vector<float> x) {
    /**
     * domain [-32.768, 32.768]
     */
    float fx = 0.0, sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < x.size(); i++) {
        sum1 += x[i] * x[i];
        sum2 += cos(2.0f * PI * x[i]);
    }
    fx = 20.0f - 20.0f * exp(-0.2f * sqrt(sum1 / x.size())) - exp(sum2 / x.size()) + exp(1.0f);

    // using the following formula order causes IEEE 754 precision loss
    // fx = -20.0f * exp(-0.2f * sqrt(sum1 / x.size())) - exp(sum2 / x.size()) + 20.0f + exp(1.0f);
    return fx;
}

float Benchmark::rastrigin(vector<float> x) {
    /**
     * domain [-5.12, 5.12]
     */
    float fx = 0.0;
    for (int i = 0; i < x.size(); i++) {
        fx += x[i] * x[i] - 10.0f * cos(2.0f * PI * x[i]);
    }
    fx = 10.0f * x.size() + fx;
    return fx;
}

float Benchmark::rosenbrock(vector<float> x) {
    /**
     * domain [-5, 10]
     */
    if (x.size() < 2)
        throw std::invalid_argument("Dimension error. (d must >= 2)");

    float fx = 0.0;
    for (int i = 0; i < x.size() - 1; i++) {
        fx += 100.0f * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]) + (x[i] - 1.0f) * (x[i] - 1.0f);
    }
    return fx;
}

float Benchmark::griewank(vector<float> x) {
    /**
     * domain [-600, 600]
     */
    float fx = 0.0, product = 1.0;
    for (int i = 0; i < x.size(); i++) {
        fx += x[i] * x[i] / 4000.0f;
        product *= cos(x[i] / sqrt(i + 1));
    }
    return fx - product + 1.0f;
}


float Benchmark::booth(float x1, float x2) {
    /**
     * domain [-10, 10]
     */
    return (x1 + 2.0f * x2 - 7.0f) * (x1 + 2.0f * x2 - 7.0f) + (2.0f * x1 + x2 - 5.0f) * (2.0f * x1 + x2 - 5.0f);
}

float Benchmark::bohachevsky(float x1, float x2) {
    /**
     * domain [-100, 100]
     */
    float f1 = x1 * x1 + 2.0f * x2 * x2 - 0.3f * cos(3.0f * PI * x1) - 0.4f * cos(4.0f * PI * x2) + 0.7f;
    float f2 = x1 * x1 + 2.0f * x2 * x2 - 0.3f * cos(3.0f * PI * x1) * cos(4.0f * PI * x2) + 0.3f;
    float f3 = x1 * x1 + 2.0f * x2 * x2 - 0.3f * cos(3.0f * PI * x1 + 4.0f * PI * x2) + 0.3f;
    return f1;
}

float Benchmark::dropWave(float x1, float x2) {
    /**
     * domain [-5.12, 5.12]
     */
    return -(1.0f + cos(12.0f * sqrt(x1 * x1 + x2 * x2))) / (0.5f * (x1 * x1 + x2 * x2) + 2.0f);
}

float Benchmark::eggholder(float x1, float x2) {
    /**
     * domain [-512, 512]
     */
    return -(x2 + 47.0f) * sin(sqrt(abs(x2 + x1 / 2.0f + 47.0f))) - x1 * sin(sqrt(abs(x1 - (x2 + 47.0f))));
}