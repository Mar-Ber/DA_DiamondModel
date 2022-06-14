data {
    int<lower=0> n; // number of data items
    int<lower=0> k; // number of predictors
    matrix[n,k] X; // predictor matrix
    vector[n] Y; // outcome vector
}
parameters {
    real alpha; // intercept
    vector[k] beta; // coefficients for predictors
    real<lower=0> sigma; // error scale
}
model {
    Y ~ normal(alpha + X * beta, sigma); // likelihood
}
generated quantities {
    real price [n];
    for (i in 1:n) {
        price[i] = normal_rng(alpha + X[i] * beta, sigma);
    }
}