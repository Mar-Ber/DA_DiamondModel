data {
    int N;
    real prices[N];
}

parameters {
    real <lower=0> mu;
    real <lower=0> sigma;
}

model {
    mu ~ normal(8000, 500);
    sigma ~ exponential(0.005);
    prices ~ normal(mu, sigma);
}

generated quantities {
    real price = normal_rng(mu, sigma);
}