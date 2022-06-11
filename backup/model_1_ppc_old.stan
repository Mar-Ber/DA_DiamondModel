generated quantities {
    real mu = normal_rng(8000, 500);
    real sigma = exponential_rng(0.1);
    real price = normal_rng(mu,sigma);
}